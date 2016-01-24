//
//  LayerMainMenu.h
//  MagicTouch
//
//  Created by SaiDong on 29/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#ifndef __MagicTouch__LayerMainMenu__
#define __MagicTouch__LayerMainMenu__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/BasicLayer.h"

//这是测试层Test
class LayerMainMenu : public BasicLayer
{
public:
    //创建场景
    static cocos2d::Scene* createScene();
    //初始化
    virtual bool init();
    
    CREATE_FUNC(LayerMainMenu);
};

#endif /* defined(__MagicTouch__LayerMainMenu__) */
