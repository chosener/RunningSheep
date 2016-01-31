//
//  Sheep.h
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#ifndef Sheep_h
#define Sheep_h

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"

#include "../../Framework/GameTouchNode.h"

///羊的基类
class Sheep : public GameTouchNode
{
public:
    Sheep();
    ~Sheep();
    virtual bool init();
    
    void update(float dt);
public:
    void setSheepPower();
private:
    void updateCollide(float dt);
    void release();
    
private:
    ///阵营
    CC_SYNTHESIZE(unsigned int, m_iCamp, iCamp);
    ///类型
    CC_SYNTHESIZE(unsigned int, m_iType, iType);
    ///索引
    CC_SYNTHESIZE(unsigned int, m_iIndex, iIndex);
    ///力量
    CC_SYNTHESIZE(float, m_fPower, fPower);
    ///速度
    CC_SYNTHESIZE(unsigned int, m_iSpeed, iSpeed);
    ///方向
    CC_SYNTHESIZE(unsigned int, m_iDirection, iDirection);
    ///碰撞块的大小
    CC_SYNTHESIZE(Rect, m_rectCollide, rectCollide);
    ///属于哪一路
    CC_SYNTHESIZE(unsigned int, m_iLine, iLine);
};

#endif /* Sheep_h */
