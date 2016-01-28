<<<<<<< HEAD
# cocos2d-x v3.6 Release Notes #
<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Misc Information](#misc-information)
- [Requirements](#requirements)
  - [Runtime Requirements](#runtime-requirements)
  - [Compiler Requirements](#compiler-requirements)
  - [How to run tests](#how-to-run-tests)
    - [Mac OSX & iOS](#mac-osx-&-ios)
    - [Android](#android)
    - [Windows](#windows)
    - [Linux](#linux)
  - [How to start a new game](#how-to-start-a-new-game)
- [v3.6](#v36)
  - [Highlights of v3.6](#highlights-of-v36)
  - [Features in detail](#features-in-detail-1)
    - [3D TextureCube](#3d-texturecube)
    - [3D Skybox](#3d-skybox)
    - [3D Terrain](#3d-terrain)
    - [Animate3D Quality Control](#animate3d-quality-control)
    - [Un-bottleneck your fill-rate with SpritePolygon](#un-bottleneck-your-fill-rate-with-spritepolygon)
    - [LuaJit ARM64](#luajit-arm64)
    - [Button memory usage optimization](#button-memory-usage-optimization)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Misc Information

* [Full Changelog](https://github.com/cocos2d/cocos2d-x/blob/v3/CHANGELOG)
=======
# cocos2d-x v3.2 Release Notes #

**Table of Contents**  *generated with [DocToc](http://doctoc.herokuapp.com/)*

- [cocos2d-x v3.2 Release Notes](#user-content-cocos2d-x-v32-release-notes)
- [Misc Information](#user-content-misc-information)
- [Requirements](#user-content-requirements)
	- [Runtime Requirements](#user-content-runtime-requirements)
	- [Compiler Requirements](#user-content-compiler-requirements)
	- [How to run tests](#user-content-how-to-run-tests)
		- [Mac OSX & iOS](#user-content-mac-osx--ios)
		- [Android](#user-content-android)
		- [Windows](#user-content-windows)
		- [Linux](#user-content-linux)
	- [How to start a new game](#user-content-how-to-start-a-new-game)
- [Highlights of v3.2](#user-content-highlights-of-v32)
- [Documents](#user-content-documents)
- [Toolchain requirement changed](#user-content-toolchain-requirement-changed)
- [atof issue on Android](#user-content-atof-issue-on-android)
- [Features in detail](#user-content-features-in-detail)
	- [Sprite3D & Animation3D](#user-content-sprite3d--animation3d)
		- [fbx-conv usage](#user-content-fbx-conv-usage)
	- [Game controller](#user-content-game-controller)
	- [Fast tilemap](#user-content-fast-tilemap)
	- [Node::enumerateChildren](#user-content-nodeenumeratechildren)
	- [utils::findChildren](#user-content-utilsfindchildren)
	- [Node::setNormalizedPosition](#user-content-nodesetnormalizedposition)

# Misc Information

* Download: http://cdn.cocos2d-x.org/cocos2d-x-3.2.zip
* Full Changelog: https://github.com/cocos2d/cocos2d-x/blob/cocos2d-x-3.2/CHANGELOG
* API Reference: http://www.cocos2d-x.org/reference/native-cpp/V3.2/index.html
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
* v3.0 Release Notes can be found here: [v3.0 Release Notes](https://github.com/cocos2d/cocos2d-x/blob/cocos2d-x-3.0/docs/RELEASE_NOTES.md)

# Requirements

## Runtime Requirements

* Android 2.3 or newer
* iOS 5.0 or newer
* OS X 10.7 or newer
* Windows 7 or newer
<<<<<<< HEAD
* Windows Phone 8.1
* Linux Ubuntu 14.04 or newer
=======
* Windows Phone 8 or newer
* Linux Ubuntu 14.04 or newer
* ~~Browsers via Emscripten~~ N/A for the moment
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

## Compiler Requirements

* Xcode 5.1 or newer for iOS or Mac
* gcc 4.9 or newer for Linux
<<<<<<< HEAD
* ndk-r10c for Android
=======
* ndk-r9d or newer for Android
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
* Visual Studio 2012  or newer for Windows (win32)
* Visual Studio 2012  or newer for Windows Phone 8

## How to run tests

### Mac OSX & iOS

* Enter `cocos2d-x/build` folder, open `cocos2d_test.xcodeproj`
* Select `iOS` or `OS X` target in scheme toolbar
* Click `run` button

### Android

You can run the samples...

**Using command line:**

    $ cd cocos2d-x
    $ ./setup.py
    $ cd build
    $ ./android-build.py cpp-empty-test -p 10
    $ adb install cocos2d-x/tests/cpp-empty-test/proj.android/bin/CppEmptyTest-debug.apk
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Then click item on Android device to run tests. Available value of `-p` is the API level, cocos2d-x supports from level 10.

**Using Eclipse:**

    $ cd cocos2d-x
    $ ./setup.py
    $ cd build
    $ ./android-build.py cpp-empty-test -p 10
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Then

* Import cocos2d-x Android project into Eclipse, the path used to import is `cocos/2d/platform/android`
* Import `cpp-empty-test` Android project into Eclipse, the path used to import is `tests/cpp-empty-test/proj.android`
* Build `cpp-empty-test` Android project and run

### Windows

* Enter `cocos2d-x/build`, and open `cocos2d-win32.vs2012.sln`
* Select `cpp-empty-test` as running target
* Click run button


### Linux

    $ cd cocos2d-x/build
    $ ./install-deps-linux.sh
    $ cd ../..
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Then

    $ mkdir build
    $ cd build
    $ cmake ../cocos2d-x
    $ make -j4
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Run

    $ cd bin/cpp-empty-test
    $ ./cpp-empty-test
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
## How to start a new game

Please refer to this document: [ReadMe](../README.md)

<<<<<<< HEAD
# v3.6

## Highlights of v3.6

* 3D: added skybox support
* 3D: added terrain support
* added `SpritePolygon` to fix overdraw issue
* used luajit v2.1-20150331 on 64-bit iOS devices
* removed WP8 support
* memory usage optimization of `ui::Button`
* 3rd: updated Spine runtime to v2.1.25
* 3rd: updated libcurl to v7.4 on all supported platforms except WP8.1 universal
* 3rd: updated chipmunk to v6.2.2
* 3rd: updated openssl to v1.0.11
* 3rd: updated freetype to v2.5.5
* 3rd: updated png to v1.6.16

Because Angle doesn't support WP8 any more, and WP8's market share is around 20% worldwide with variations across countries, so we removed WP8 support suggested by MS OPEN TECK guys since v3.6.


## Features in detail

### 3D TextureCube

TextureCube is useful for skybox and environment mapping. It uses 6 faces of a cube as map shape, and 6 pictures are projected onto the sides of a cube and stored as six square textures.

**TexturesCube usage**

```c++
auto texturecube = TextureCube::create("left.jpg", "right.jpg", "top.jpg", "bottom.jpg","front.jpg", "back.jpg");
//set texture parameters
Texture2D::TexParams tRepeatParams;
tRepeatParams.magFilter = GL_NEAREST;
tRepeatParams.minFilter = GL_NEAREST;
tRepeatParams.wrapS = GL_MIRRORED_REPEAT;
tRepeatParams.wrapT = GL_MIRRORED_REPEAT;
texturecube->setTexParameters(tRepeatParams);

//create a GLProgramState using custom shader
auto shader = GLProgram::createWithFilenames("cube_map.vert", "cube_map.frag");
auto state = GLProgramState::create(shader);
// pass the texture sampler to our custom shader, state is a pointer of GLProgramState, u_cubeTex is a uniform in shader
state->setUniformTexture("u_cubeTex", texturecube);
```

Then the shader cube_map.frag can be something like this,

```c++
varying vec3        v_reflect; //reflect direction
uniform samplerCube u_cubeTex;

void main(void)
{
    gl_FragColor = textureCube(u_cubeTex, v_reflect); //sample the color of reflection direction
}
```

For more information please refer to cpp-tests/Sprite3DTest/Sprite3DCubeMapTest.

### 3D Skybox

Skybox is a common component in 3D game. It is based on TextureCube.

Usage of skybox

```c++
// create a texture cube
auto textureCube = TextureCube::create("left.jpg", "right.jpg","top.jpg", "bottom.jpg","front.jpg", "back.jpg");
//create a skybox
auto skyBox = Skybox::create();
skyBox->retain();
//set cube texture to the skybox
skyBox->setTexture(textureCube);
addChild(_skyBox);
```

For more information please refer to cpp-tests/Sprite3DTest/Sprite3DCubeMapTest.

![tecturecube-and-skybox](https://raw.githubusercontent.com/minggo/Pictures/master/texturecube-skybox.gif)

### 3D Terrain

Terrain is an important component in 3D game. A texture is used to stand for the height map. And up to 4 textures can be used to blend the details of the terrain, grass, road, and so on.

Usage of terrain

```c++
//blended layers
Terrain::DetailMap dirt("TerrainTest/dirt.jpg"), grass("TerrainTest/Grass2.jpg"), road("TerrainTest/road.jpg"), green("TerrainTest/GreenSkin.jpg");

//height map, alpha map (blend weight), and blended layers
Terrain::TerrainData data("TerrainTest/heightmap16.jpg", "TerrainTest/alphamap.png", dirt, grass, road, green);

//create terrain here
_terrain = Terrain::create(data,Terrain::CrackFixedType::SKIRT);
//set lod distance
_terrain->setLODDistance(3.2,6.4,9.6);
//it must be less than 5
_terrain->setMaxDetailMapAmount(4);
addChild(_terrain);
```

For more information please refer to cpp-tests/Sprite3DTest/TerrainTest.

![terrian](https://raw.githubusercontent.com/minggo/Pictures/master/terrian.png)

### Animate3D Quality Control

In order to make Animate3D run fast, you can use low quality animation. There are three types of animation quality：

* Animate3DQuality::QUALITY_NONE
* Animate3DQuality::QUALITY_LOW
* Animate3DQuality::QUALITY_HIGH

`Animate3DQuality::QUALITY_NONE` means the animation will not be updated. You can use this type on the animation that you are sure it is not visible. `Animate3DQuality::QUALITY_LOW` will use the nearest keyframe to display current frame; `Animate3DQuality::QUALITY_HIGH` will will interpolate between keyframes.


```c++
std::string fileName = "Sprite3DTest/orc.c3b";
auto sprite = Sprite3D::create(fileName);
addChild(sprite);
    
auto animation = Animation3D::create(fileName);
if (animation)
{
   auto animate = Animate3D::create(animation);
   //use low quality animation
   animate->setQuality(Animate3DQuality::QUALITY_LOW);
   sprite->runAction(RepeatForever::create(animate));
}
```

The animation quality is also configurable in config.plist, the key is cocos2d.x.3d.animate_high_quality. All created Animate3D base on this key if exist. You can modify it using the above method.

### Un-bottleneck your fill-rate with SpritePolygon

SpritePolygon is a 2d Node, like Sprites, it displays a 2d Image.
But the difference is where Sprites is made of 2 triangles to form a quad, SpritePolygon is made of N number of triangles. `It is an experimental feature.`

![sprite-polygon](https://raw.githubusercontent.com/minggo/Pictures/master/sprite-polygon.jpg)

This allows the GPU to draw the same graphics with much lower pixels.

Because 2d games tends to not use much vertices compared to 3d games, but almost of all sprites are `none rectangular`, GPU wastes precious bandwidth drawing area that is totally transparent. Fill-rate is often the bottleneck in a graphic intense 2d game. SpritePolygon is the perfect cure for "Over-Draw".

Following picture is the result of performance comparing, corresponding performance test cases are in `tests/cpp-tests/Classes/SpritePolygonTest`:

![spritepolygon-performance](http://discuss.cocos2d-x.org/uploads/default/_optimized/336/215/1423528cff_690x149.png)

For more detail description of SpritePolygon please refer to [this thread](http://discuss.cocos2d-x.org/t/new-feature-meshsprite-polygonsprite/21153)

### luajit arm64 

The version of the luajit is [v2.1-20150331](https://github.com/openresty/luajit2/releases). We have consulted the author of luajit, he said it was stability enough to be used. We will update to v2.1 when it is released.

Using luajit arm64 version is that because it can improve the performance. In previous versions of cocos2d-x, it uses lua on iOS 64-bit devices. 

Bytecode of luajit and luajit arm64 are not compatible, which means you can not use one version of bytecode on iOS 32-bit devices and iOS 64-bit devices.

As there is not mandatory requirement of having arm64 bit bin on Android, so we don't use luajit arm64 on Android as its bytecode is not compatible with luajit arm32.

### Button memory usage optimization
Now the title label of Button is created on demand. A Button without title won't
create an extra empty label.

And we have also removed some redundant string variables in Button's header file.

We use Cpp-Empty-Test to verify this optimization.

Here is the test code:

```
auto visibleSize = Director::getInstance()->getVisibleSize();
auto origin = Director::getInstance()->getVisibleOrigin();

int num = 100;
for (int i=0; i < num; ++i)
{
auto button = ui::Button::create("ClosedNormal.png",
"ClosedSelected.png");
button->setPosition(origin + visibleSize/2);
this->addChild(button);
}
```

And here is the result:

#### On iOS platform

|Num of buttons|100 | 200 | 500| 1000|
|-----|-----|-----|-----|-----|
|Before optimization | 61M | 61.9M | 67.1M | 72.2M|
|After optimization |60.7M| 61.1M | 66M | 67.9M|

#### On Mac platform

|Num of buttons|100 | 200 | 500| 1000|
|-----|-----|-----|-----|-----|
|Before optimization |26.8M | 27.1M| 33.2M| 35.4M|
|After optimization |25.1M|25.9M|28M|32.4M|
=======
# Highlights of v3.2

* `Animation3D`/`Animate3D`, new nodes for 3d animation
* `fbx-conv` supports generating binary format which is supported by `Sprite3D`
* Game controller support
* Fast tilemap support
* Added `utils::cpatureScreen` to take screenshot
* Physics body supports scale and rotation
* Added `Node::enumerateChildren` and `utils::findChildren`, and support c++ 11 regular expression
* Added `Node::setNormalizedPosition`, `Node`'s position in pixel will be calculated according its parent's content size

# Documents

* [Sprite3D & Animation3D](http://cocos2d-x.org/wiki/Sprite3D)
* [Game controller](http://www.cocos2d-x.org/wiki/Game_Controller)
* [How to compile shader on WP8](http://cocos2d-x.org/wiki/How_to_update_wp8_shader)

# Toolchain requirement changed

`Node::enumerateChildren()` uses `std::regex` which will cause crash using gcc v4.8 or lower version. 
Because `OTHER_LDFLAGS` can not work in Xcode6 beta3. So we used fat library(including 64-bit libaries) on iOS. But Xcode 5.0 or lower version has building problem by this way.

So

* NDK r9d or newer version is required for Android building
* gcc 4.9 is required for linux building
* Xcode 5.1 or newer is required on iOS

# atof issue on Android

We found a bug of `atof` on Android when using libc++. The bug is that, the return value of `atof` may be `-inf` when passing some valid digit string.

For example

```c++
atof("90.099998474121094"); // -> return value is -inf
```

We have reported it to google guys, and they confirmed that it is a bug. In order to work around this issue, we added `utils::atof()`.

The corresponding pull request for this issue is [here](https://github.com/cocos2d/cocos2d-x/pull/7440). You can refer to this pull request for demail information.

# Features in detail

## Sprite3D & Animation3D

Sample code to use binary version
```c++
auto sprite3d = Sprite3D::create("filename.c3b");
addChild(sprite3d);

auto animation3d = Animation3D("filename.c3b");
auto animate3d = Animate3D::create(animation3d);
sprite3d->runAction(RepeatForEver::create(animate));
```

Detail information please refer to [Sprite3D & Animation3D](http://cocos2d-x.org/wiki/Sprite3D).

### `fbx-conv` usage

* Mac OS X

```
$ cd COCOS2DX_ROOT/tools/fbx-conv/mac
$ ./fbx-conv [-a|-b|-t] FBXFile
```

* Windows

```
cd COCOS2DX_ROOT/tools/fbx-conv/windows
fbx-conv [-a|-b|-t] FBXFile
```

Options:

* -a: export both text and binary format
* -b: export binary format
* -t: export text format

## Game controller

Supported controller type:

* Android standard controllers
* Amazon tv
* OUYA
* Moga
* Nibiru
* iOS standard controllers

Sample codes
```c++
// register event listener
auto listener = EventListenerController::create();
listner->onKeyDown = ...
...
eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

// start connecting controller
Controller::startDiscoveryController();

// handler key down/ key up event
void GameControllerTest::onKeyDown(Controller *controller, int keyCode, Event *event)
{
    switch (keyCode)
    {
        case Controller::Key::BUTTON_A:
        ...
        break;
        
        ...
    }
}
```

Detail information please refer to [Game controller](http://www.cocos2d-x.org/wiki/Game_Controller).

## Fast tilemap

Fast tilemap has the same API as `TMXTiledMap` without deprecated functions.

Sample code
```c++
auto tilemap = cocos2d::experimental::TMXTiledMap::create("MyFile.tmx");
addChild(tilemap);
```

Full demo please refer to `COCOS2DX_ROOT/tests/cpp-tests/Classes/TileMapTest/TileMapTest2.cpp`.

## Node::enumerateChildren

This functions is used to enumerate children of a `Node`. It supports c++ 11 regular expression.

```c++
// Find nodes whose name is 'nameToFind' and end with digits.
node->enumerateChildren("nameToFind[[:digit:]]+", [](Node* node) -> bool {
    ...
    return false; // return true to stop at first match
});

// Find nodes whose name is 'nameToFind' and end with digits recursively.
node->enumerateChildren("nameToFind[[:digit:]]+", [](Node* node) -> bool {
    ...
    return false; // return true to stop at first match
});
```

Full test please refer to `NodeNameTest` in `COCOS2DX_ROOT/tests/cpp-tests/NodeTest/NodeTest.cpp`.

Because this function uses `std::regex` which is not supported well in gcc 4.8 or lower version. So we use `clang` and `stdc++` instead for Android building. This lead to the result that `NDK r9d` or newer is required. And `gcc 4.9` is required on linux.

## utils::findChildren

This is a helper function to find children of a `Node` share a name. The implementation of this function bases on `Node::enumerateChildren`.

```c++
auto children = utils::findChildren(node, "nameToFind");

...
```

## Node::setNormalizedPosition

Can use this function to set Node's position(x,y) using value between 0 and 1. `Can use this function when it has a parent node.` The positions in pixels is calculated like the following:

```c++
// pseudo code
void setNormalizedPosition(Vec2 pos)
{
    Size s = getParent()->getContentSize();
    _position = pos * s;
}
```

Full test please refer to `NodeNormalizedPositionTest1/2` in `tests/cpp-tests/Classes/NodeTest/NodeTest.cpp`.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
