#include "AppDelegate.h"
#include "HelloWorldScene.h"

#include "Manager/Scene/SceneManager.h"
#include "Scene/MainMenu/LayerMainMenu.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
<<<<<<< HEAD
=======
/*
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}
<<<<<<< HEAD
=======
 */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

<<<<<<< HEAD
bool AppDelegate::applicationDidFinishLaunching() {
=======
bool AppDelegate::applicationDidFinishLaunching()
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
<<<<<<< HEAD
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }

=======
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    glview->setDesignResolutionSize(1280,720,ResolutionPolicy::SHOW_ALL);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    register_all_packages();

    // create a scene. it's an autorelease object
<<<<<<< HEAD
    auto scene = LayerMainMenu::createScene();

    // run
    director->runWithScene(scene);
=======
    //auto scene = LayerMainMenu::createScene();

    // run
    //director->runWithScene(scene);
    SceneManager::getInstance()->changeScene(SceneManager::en_GameScene);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
