//
//  BasicLayer.cpp
//  MagicTouch
//
//  Created by SaiDong on 23/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "BasicLayer.h"

BasicLayer::BasicLayer()
{

}
BasicLayer::~BasicLayer()
{
    
}

bool BasicLayer::init()
{
    bool rRet = false;
    do {
        
        CC_BREAK_IF(!Layer::init());
        
        rRet = true;
    } while (0);
    
    return rRet;
}
/**
 *  获取屏幕的大小
 *
 *  @return CCSize
 */
Size BasicLayer::getWinSize()
{
    Size winSize = Director::getInstance()->getWinSize();
    return winSize;
}
/**
 *  获取屏幕矩形
 *
 *  @return CCRect
 */
Rect BasicLayer::getWinRect()
{
    Rect screenRect = Rect(0,0,getWinSize().width , getWinSize().height);

    return screenRect;
}
/**
 *  获取屏幕中心点
 *
 *  @return Point
 */
Point BasicLayer::getWinCenter()
{
    return Vec2(getWinSize().width/2,getWinSize().height/2);
}

/**
 *  设置当前层的初始化动作
 *
 *  @param style 动作
 */
void BasicLayer:: setInitAction(int style)
{
    
    this->setScale(0.5f);
    
    Sequence* seq = Sequence::create(ScaleBy::create(0.1f, 2.0f),ScaleBy::create(0.05f, 0.9f),
                                         ScaleBy::create(0.05f, 1.1f),ScaleBy::create(0.05f, 0.95f),
                                         NULL);
    
    this->runAction(seq);
}
/**
 *  设置当前层的初始化动作
 *
 *  @param style 动作
 */
void BasicLayer:: setInitAction(int style,float sd)
{
    this->setScale(0.5f + sd);
    
    Sequence* seq = Sequence::create(ScaleBy::create(0.1f, 2.0f),ScaleBy::create(0.05f, 0.9f),
                                         ScaleBy::create(0.05f, 1.1f),ScaleBy::create(0.05f, 0.95f),
                                         NULL);
    
    this->runAction(seq);
}
/**移除自己*/
void BasicLayer::removeSelf()
{
    //父结点
    Layer* layerParent = (Layer*)this->getParent();
    //找到遮罩层
    LayerColor* layerColor = (LayerColor*)layerParent->getChildByTag(66666);
    //如果存在则移除
    if(layerColor)
    {
        layerParent->removeChildByTag(66666);
    }
    this->removeFromParent();
}








