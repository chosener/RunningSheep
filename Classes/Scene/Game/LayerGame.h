//
//  LayerGame.h
//  MagicTouch
//
//  Created by SaiDong on 29/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#ifndef __MagicTouch__LayerGame__
#define __MagicTouch__LayerGame__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"
#include "../../Framework/BasicLayer.h"

#include "../../Object/Sheep/SheepWhite.h"
#include "../../Manager/Header/HeaderManager.h"

//游戏主菜单
class LayerGame : public BasicLayer
{
public:
    //创建场景
    static cocos2d::Scene* createScene();
    //初始化
    virtual bool init();
    
    void onEnter();

    void onEnterTransitionDidFinish();

    void onExit();

    
    CREATE_FUNC(LayerGame);
    
    void update(float dt);
    
private:
    void initView();
    void initVariables();
    void initManager();
    ///背景
    void initBackGround();
    void initUI();
    ///按钮
    void initButton();
    
    void initTest();
    
    void onSheepGo(Node* sender, Touch* touch, Event* e);
    
    void addSheep(int line);
    
private:
    ///头像管理器更新
    void updateManagerHeader(float dt);
    
private:
    HeaderManager* m_HeaderMng;
};

#endif /* defined(__MagicTouch__LayerGame__) */
