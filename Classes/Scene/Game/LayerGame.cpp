//
//  LayerGame.cpp
//  MagicTouch
//
//  Created by SaiDong on 29/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "LayerGame.h"

//创建场景
Scene* LayerGame::createScene()
{
    
    auto scene = Scene::create();
    
    auto layer = LayerGame::create();
    
    scene->addChild(layer);
    
    return scene;
}

//初始化
bool LayerGame::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("LayerGame Test!", "", 25);
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    label->setColor(Color3B(255, 0, 0));
    
    this->addChild(label, 1);
    
    this->initView();
    
    return true;
}
void LayerGame::initView()
{
    this->initBackGround();
    this->initButton();
    
    this->initUI();
}
void LayerGame::initBackGround()
{
    //--------------------------------------------------
    Sprite* spBg0 = Sprite::create("images/game/back.png");
    spBg0->setPosition(DISPLAY_CX,DISPLAY_CY);
    this->addChild(spBg0,-3);
    
    Sprite* spBg1 = Sprite::create("images/game/background1.png");
    spBg1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    spBg1->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM);
    this->addChild(spBg1,-1);
    
    Sprite* spBg2 = Sprite::create("images/game/backgroundTop1.png");
    spBg2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    spBg2->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM);
    this->addChild(spBg2,-1);
    
    //--------------------------------------------------
    //路
#if 0
    int orginY = 68;
    int disY = 136;
    for (int i = 1 ; i < 6; i++)
    {
        Sprite* spRoad0 = Sprite::create("images/game/witheredGrass.png");
        spRoad0->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        spRoad0->setPosition(DISPLAY_WIDTH/2,DISPLAY_BOTTOM + orginY + disY * i);
        this->addChild(spRoad0,1);
    }
#endif
    
    //--------------------------------------------------
    Sprite* spLeft = Sprite::create("images/game/left.png");
    spLeft->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    spLeft->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM);
    this->addChild(spLeft,1);
    
    Sprite* spRight = Sprite::create("images/game/eave.png");
    spRight->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
    spRight->setPosition(DISPLAY_RIGHT,DISPLAY_BOTTOM);
    this->addChild(spRight,1);

}
void LayerGame::initUI()
{
    Sprite* spTitleBg0 = Sprite::create("images/game/top_1.png");
    spTitleBg0->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    spTitleBg0->setPosition(DISPLAY_WIDTH/2,DISPLAY_TOP + 10.0f);
    this->addChild(spTitleBg0,1000);
    
    Sprite* spTitleBg1 = Sprite::create("images/game/top.png");
    spTitleBg1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
    spTitleBg1->setPosition(DISPLAY_WIDTH/2,DISPLAY_TOP + 10.0f);
    this->addChild(spTitleBg1,1000);
}
void LayerGame::initButton()
{
    
}

void LayerGame::onGameStart(Node* sender, Touch* touch, Event* e)
{
    DLog::d("game start !");
    SceneManager::getInstance()->changeScene(SceneManager::en_GameScene);
}



