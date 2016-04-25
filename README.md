# quick2d - The best of Game Engine for 2D Games


It is based on [cocos2d-x](https://github.com/cocos2d/cocos2d-x)[version 3.9], but remove 3D and other features. It works on iOS,OS X,Android and Windows. 

------------------------------------------------

The major change:

- Only support iOS,OS X,Android and Windows.
- Remove 3D features
- Remove support for JS script (It's permanent)
- Remove deprecated classes and functions
- Remove Camera
- Remove Physics integration
- Remove C++ implementations of Component
- Remove C++ implementations of CocoStudio parser
- Remove C++ implementations of CocosBuilder parser
- Remove AssetsManager, AssetsManagerEX
- Remove Allocator
- Remove AutoPolygon
- Remove support for WebP,S3TC,ATITC
- Remove support for game controller
- Improved robustness and many bugs have been fixed
- Using FastTileMap instead of TileMap
- Replace Luabinding with [Sol2](https://github.com/ThePhD/sol2)


## Git user attention

1. Clone the repo from GitHub.

        $ git clone https://github.com/dualface/quick2d-engine.git

2. After cloning the repo, please execute `download-deps.py` to download and install dependencies.

        $ cd quick2d-engine
        $ python download-deps.py

3. After running `download-deps.py`.

        $ git submodule update --init


## Contributing to the Project

quick2d-engine is licensed under the [MIT License](https://opensource.org/licenses/MIT). We welcome participation!

