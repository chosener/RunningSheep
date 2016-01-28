//
//  LayerStart.cpp
//  MagicTouch
//
//  Created by SaiDong on 29/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "LayerStart.h"

//创建场景
Scene* LayerStart::createScene()
{
    
    auto scene = Scene::create();
    
    auto layer = LayerStart::create();
    
    scene->addChild(layer);
    
    return scene;
}

//初始化
bool LayerStart::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("LayerStart Test!", "", 25);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    label->setColor(Color3B(255, 0, 0));
    
    this->addChild(label, 1);
    
    this->initView();
    
    return true;
}
void LayerStart::initView()
{
    this->initBackGround();
    this->initButton();
}
void LayerStart::initBackGround()
{
    Sprite* spBg = Sprite::create("images/start/FirstLayerBack.png");
    spBg->setPosition(DISPLAY_CX,DISPLAY_CY);
    this->addChild(spBg,-1);
    
    Sprite* spTitle = Sprite::create("images/start/gameTitle.png");
    spTitle->setPosition(DISPLAY_CX,DISPLAY_CY + 150.0f);
    this->addChild(spTitle);
}
void LayerStart::initButton()
{
    ImageButton* imgBtnStart = ImageButton::create("images/start/start.png", "images/start/start.png");
    imgBtnStart->setPosition(DISPLAY_CX,DISPLAY_CY - 150.0f);
    this->addChild(imgBtnStart);
    imgBtnStart->addTouchEventListener(CALL_PRESS_FUNC_SELECTOR(LayerStart::onGameStart), this);
    

}

void LayerStart::onGameStart(Node* sender, Touch* touch, Event* e)
{
    DLog::d("game start !");
    SceneManager::getInstance()->changeScene(SceneManager::en_GameMainMenu);
}



