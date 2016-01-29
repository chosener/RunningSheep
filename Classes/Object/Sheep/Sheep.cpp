//
//  Sheep.cpp
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#include "../../Framework/GameHeader.h"

Sheep::Sheep()
{
    this->setiCamp(En_Camp_None);
    this->setiType(En_SheepType_None);
    this->setiPower(0);
    this->setiSpeed(0);
    this->setiDirection(En_Direction_None);
    
    this->setrectCollide(Rect::ZERO);
    
    this->scheduleUpdate();
}
Sheep::~Sheep()
{
    
}

bool Sheep::init()
{
    if (this->GameTouchNode::init() == false) {
        return false;
    }

        
    return true;
}

void Sheep::update(float dt)
{
    this->updateCollide(dt);
    
    Vec2 pos = this->getPosition();
    
    setPositionX(pos.x + 3.0f);
    
    if(!DISPLAY_RECT.intersectsRect(this->m_rectCollide));
    {
        this->release();
    }
    
}
void Sheep::updateCollide(float dt)
{
    Vec2 pos = this->getPosition();
    
    Rect rect = Rect(pos.x, pos.y, this->m_rectCollide.size.width, this->m_rectCollide.size.height);
    
    this->setrectCollide(rect);
}

void Sheep::release()
{
    this->removeFromParent();
}