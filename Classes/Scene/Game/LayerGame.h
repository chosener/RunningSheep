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

//游戏主菜单
class LayerGame : public BasicLayer
{
public:
    //创建场景
    static cocos2d::Scene* createScene();
    //初始化
    virtual bool init();
    
    CREATE_FUNC(LayerGame);
    
private:
    void initView();
    ///背景
    void initBackGround();
    void initUI();
    ///按钮
    void initButton();
    
    void initTest();
    
    void onSheepGo(Node* sender, Touch* touch, Event* e);
};

#endif /* defined(__MagicTouch__LayerGame__) */
