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
    
    return true;
}
