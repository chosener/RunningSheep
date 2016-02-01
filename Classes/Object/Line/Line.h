#ifndef __RunningSheep_Line_H__
#define __RunningSheep_Line_H__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"
#include "../../Object/Sheep/SheepWhite.h"
#include "../../Object/Sheep/SheepBlack.h"

///小羊的线路
class Line : public GameTouchNode
{

public:
    bool initWithNothing();
	bool initWithFile(const char* name);
	bool initWithSpriteFrameName(const char* name);
    
    void update(float dt);

public:
    static Line* create();
	static Line* create(const char* name);
	static Line* createWithSpriteFrameName(const char* name);
    
    void pushDequeWhite(SheepWhite* white);
    void pushDequeBlack(SheepBlack* black);
    
    void eraseDequeWhite(SheepWhite* white);
    void eraseDequeBlack(SheepBlack* black);
    
    Vector<SheepWhite*> m_vecSheepWhite;
    Vector<SheepBlack*> m_vecSheepBlack;
    
    
    Vector<Sheep*> m_vecSheepCollide;

private:
    
    ///这条线的速度
    CC_SYNTHESIZE(float, m_fSpeed, fSpeed);
    
    ///有一次碰撞
    CC_SYNTHESIZE(bool, m_bIsOnceCollide, bIsOnceCollide);
};

#endif

