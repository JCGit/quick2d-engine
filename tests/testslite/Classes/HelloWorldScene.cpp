
#include "HelloWorldScene.h"
#include "sol.hpp"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init()) {
        return false;
    }

    Size size = Director::getInstance()->getOpenGLView()->getFrameSize();

    auto label = Label::createWithSystemFont("Hello World", "sans", 24);
    label->setAlignment(TextHAlignment::CENTER);
    label->setVerticalAlignment(TextVAlignment::CENTER);

    // position the label on the center of the screen
    label->setPosition(Vec2(size.width / 2, size.height / 2));

    // add the label as a child to this layer
    this->addChild(label, 1);

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::math);

    lua.new_usertype<HelloWorld>("HelloWorld",
                                 "addChild", sol::resolve<void(Node*)>(&Layer::addChild)
                                 );

    // Node
    {
        lua.new_usertype<Node>("Node");
    }

    // Sprite
    {
        auto create = sol::overload(sol::resolve<Sprite*()>(&Sprite::create),
                                    sol::resolve<Sprite*(const std::string&)>(&Sprite::create));

        auto setPosition = sol::overload(sol::resolve<void(const Vec2&)>(&Sprite::setPosition),
                                         sol::resolve<void(float, float)>(&Sprite::setPosition));

        lua.new_usertype<Sprite>("Sprite",
                                 "create", create,
                                 "createWithFilename", sol::resolve<Sprite*(const std::string&)>(&Sprite::create),
                                 "setPosition", setPosition,
                                 sol::base_classes, sol::bases<Node>()
                                 );
    }

    // Vec2
    {
        sol::constructors<sol::types<>, sol::types<float, float>> ctor;
        lua.new_usertype<Vec2>("Vec2",
                               ctor,
                               "x", &Vec2::x,
                               "y", &Vec2::y);
    }

    lua["layer"] = this;
    lua.script("local s2 = Sprite.create(); local sprite = Sprite.createWithFilename('HelloWorld.png'); local pos = Vec2.new(480, 320); sprite:setPosition(pos); layer:addChild(sprite); sprite:setPosition(100, 100);");

    return true;
}
