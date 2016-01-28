//
//  LayerMainMenu.cpp
//  MagicTouch
//
//  Created by SaiDong on 29/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "LayerMainMenu.h"

//创建场景
Scene* LayerMainMenu::createScene()
{
    
    auto scene = Scene::create();
    
    auto layer = LayerMainMenu::create();
    
    scene->addChild(layer);
    
    return scene;
}

//初始化
bool LayerMainMenu::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("LayerMainMenu Test!", "", 25);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    label->setColor(Color3B(255, 0, 0));
    
    this->addChild(label, 1);
    
<<<<<<< HEAD
    return true;
}
=======
    this->initView();
    
    return true;
}
void LayerMainMenu::initView()
{
    this->initBackGround();
    this->initButton();
}
void LayerMainMenu::initBackGround()
{
    Sprite* spBg0 = Sprite::create("images/mainmenu/activity.png");
    spBg0->setPosition(DISPLAY_CX,DISPLAY_CY);
    this->addChild(spBg0,-1);
    
    Sprite* spBg = Sprite::create("images/mainmenu/backgroundTop.png");
    spBg->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    spBg->setPosition(DISPLAY_WIDTH/2,DISPLAY_BOTTOM);
    this->addChild(spBg,-1);

}
void LayerMainMenu::initButton()
{
    ImageButton* imgBtnStart = ImageButton::create("images/mainmenu/btnPlay.png", "images/mainmenu/btnPlay.png");
    imgBtnStart->setPosition(DISPLAY_WIDTH * 0.7f,DISPLAY_HEIGHT * 0.1f);
    this->addChild(imgBtnStart);
    imgBtnStart->addTouchEventListener(CALL_PRESS_FUNC_SELECTOR(LayerMainMenu::onGameStart), this);
    

}

void LayerMainMenu::onGameStart(Node* sender, Touch* touch, Event* e)
{
    DLog::d("game start !");
    SceneManager::getInstance()->changeScene(SceneManager::en_GameScene);
}



>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
