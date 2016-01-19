//
//  BasicLayer.h
//  MagicTouch
//
//  Created by SaiDong on 23/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

//游戏中的所有层的基类，此类继承自Layer

#ifndef __MagicTouch__BasicLayer__
#define __MagicTouch__BasicLayer__

#include "CocosHead.h"
//#include "GlobalEnum.h"

/**
 *  层初始类型
 */
enum ActionInitLayer {
    kActionScale = 0,
    kActionDown
    };
/****************************************************************************/
/****************************************************************************/
//层的基类
/****************************************************************************/
/****************************************************************************/
class BasicLayer : public Layer
{
public:
    BasicLayer();
    ~BasicLayer();
    
    virtual bool init();
    
    Size getWinSize();
    
    Rect getWinRect();
    
    Point getWinCenter();

    CREATE_FUNC(BasicLayer);

    /**
     *  设置当前层的初始化动作
     *
     *  @param style 动作
     */
    void setInitAction(int style);
    /**
     *  设置当前层的初始化动作
     *
     *  @param style 动作
     */
    void setInitAction(int style,float sd);
    /**移除自己*/
    void removeSelf();

};

#endif
