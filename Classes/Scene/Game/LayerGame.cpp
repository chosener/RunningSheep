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
    
    this->scheduleUpdate();
    
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

void LayerGame::onEnter()
{
    Layer::onEnter();

}

void LayerGame::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    this->initManager();
}

void LayerGame::onExit()
{
    Layer::onExit();
}

void LayerGame::initView()
{
    this->initVariables();
    
    this->initBackGround();
    this->initButton();
    
    this->initUI();
    
    this->initTest();
}
void LayerGame::initVariables()
{
    
}
void LayerGame::initManager()
{
    this->m_HeaderMng = HeaderManager::getInstance();
    this->m_HeaderMng->setLayer(this);
    this->m_HeaderMng->addStartHeader();
    
    this->m_LineMng = LineManager::getInstance();
    this->m_LineMng->setLayer(this);
    this->m_LineMng->addLineToLayer();
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
    Sprite* spLeft = Sprite::create("images/game/eave.png");
    spLeft->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    spLeft->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM);
    this->addChild(spLeft,100);
    
    Sprite* spRight = Sprite::create("images/game/right.png");
    spRight->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
    spRight->setPosition(DISPLAY_RIGHT,DISPLAY_BOTTOM);
    this->addChild(spRight,100);

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
    this->addChild(spTitleBg1,1002);
    
    //关卡字
    Sprite* spTxtGuanKa = Sprite::create("images/game/txt_guanka.png");
    spTxtGuanKa->setPosition(DISPLAY_LEFT + 55,DISPLAY_TOP - 30.0f);
    this->addChild(spTxtGuanKa,1100);
    
    //金币icon背景
    Sprite* spBgIconGold = Sprite::create("images/game/img_bg_gold.png");
    spBgIconGold->setPosition(DISPLAY_LEFT + 55,DISPLAY_TOP - 200.0f);
    this->addChild(spBgIconGold,100);
    
    //金币icon
    Sprite* spIconGold = Sprite::create("images/game/goldBig.png");
    spIconGold->setPosition(DISPLAY_LEFT + 55,DISPLAY_TOP - 200.0f);
    this->addChild(spIconGold,100);
    
    ///暂停按钮
    ImageButton* imgBtnPause = ImageButton::create("images/game/btn_pause.png", "images/game/btn_pause_s.png");
    imgBtnPause->setPosition(DISPLAY_RIGHT - 50,DISPLAY_TOP - 40.0f);
    this->addChild(imgBtnPause,1100);
}
void LayerGame::initButton()
{
    //右侧
    //go按钮
    for (int i = 0; i < 5; i++)
    {
        ImageButton* imgBtnGo = ImageButton::create("images/game/btnGoBig_1.png", "images/game/btnGoBig_2.png");
        imgBtnGo->setPosition(DISPLAY_RIGHT - 80,DISPLAY_BOTTOM + 120 * i + 60);
        this->addChild(imgBtnGo,100,10 + i);
        
        imgBtnGo->addTouchEventListener(CALL_PRESS_FUNC_SELECTOR(LayerGame::onSheepGo), this);
    }

}
void LayerGame::initTest()
{
#if 0
    SheepWhite* sheepWhite = SheepWhite::createWithFrameAnim("images/game/goldBig.png");
    sheepWhite->setPosition(DISPLAY_LEFT,DISPLAY_CY);
    this->addChild(sheepWhite,5);
#endif
}
void LayerGame::addSheep(int line)
{
#if 0
    SheepWhite* sheepWhite = SheepWhite::createWithFrameAnim("images/game/goldBig.png");
    sheepWhite->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM + 120*line + 60);
    this->addChild(sheepWhite,5);
#endif
#if 0
    this->m_HeaderMng->addHeader();
#endif
#if 1
    this->m_HeaderMng->letTeamGo(line);
#endif
}
void LayerGame::onSheepGo(Node* sender, Touch* touch, Event* e)
{
    DLog::d("sheep running");
    //SceneManager::getInstance()->changeScene(SceneManager::en_GameScene);
    ImageButton* imgBtnGo = (ImageButton*)sender;
    int tag = imgBtnGo->getTag();
    int line = tag - 10;
    switch (tag) {
        case 10:
        {
            DLog::d("run",line);
            addSheep(line);
        }
            break;
        case 11:
        {
            DLog::d("run",line);
            addSheep(line);
        }
            break;
        case 12:
        {
            DLog::d("run",line);
            addSheep(line);
        }
            break;
        case 13:
        {
            DLog::d("run",line);
            addSheep(line);
        }
            break;
        case 14:
        {
            
            DLog::d("run",line);
            addSheep(line);
        }
            break;
        
            
        default:
            break;
    }
}

void LayerGame::update(float dt)
{
    this->updateManagerHeader(dt);
    this->updateManagerLine(dt);
}

///头像管理器更新
void LayerGame::updateManagerHeader(float dt)
{
    
    this->m_HeaderMng->update(dt);
}

///更新线路
void LayerGame::updateManagerLine(float dt)
{
    this->m_LineMng->update(dt);
}
