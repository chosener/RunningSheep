//
//  Sheep.cpp
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#include "Sheep.h"

Sheep::Sheep()
{
    this->setiCamp(En_Camp_None);
    this->setiType(En_SheepType_None);
    this->setiIndex(0);
    this->setfPower(0.0f);
    this->setfSpeed(0);
    this->setiDirection(En_Direction_None);
    
    this->setrectCollide(Rect::ZERO);
    
    this->setiLine(0);
    
    this->setbIsCollide(false);
    
    this->setbIsDead(false);
    
    this->setiAniState(En_Action_None);
    
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
    
    float speed = 0.0f;

    bool bIsCollide = this->getbIsCollide();
    if(bIsCollide)
    {
        speed = this->getfSpeed();
    }
    else
    {
        speed = this->getfPower();
    }
    
    setPositionX(pos.x + speed);
    
    if(!DISPLAY_RECT.intersectsRect(this->m_rectCollide))
    {
        this->setbIsDead(true);
        this->releaseSelf();
    }
    
}
void Sheep::updateCollide(float dt)
{
    Vec2 pos = this->getPosition();
    
    Rect rect = Rect(pos.x, pos.y, this->m_rectCollide.size.width, this->m_rectCollide.size.height);
    
    this->setrectCollide(rect);
}

void Sheep::setSheepPower()
{
    int index = this->getiIndex();
    float fPower = 0.0f;
    switch (index) {
        case 0:
        {
            fPower = 5.0f;
        }
            break;
        case 1:
        {
            fPower = 4.5f;
        }
            break;
        case 2:
        {
            fPower = 4.0f;
        }
            break;
        case 3:
        {
            fPower = 3.5f;
        }
            break;
        case 4:
        {
            fPower = 3.0f;
        }
            break;
            
        default:
            break;
    }
    
    int camp = this->getiCamp();
    switch (camp) {
        case En_Camp_Team:
        {
            fPower = -fPower;
        }
            break;
        case En_Camp_Enemy:
        {
            fPower = fPower;
        }
            break;
            
        default:
            break;
    }
    
    this->setfPower(fPower);
}

void Sheep::releaseSelf()
{
    this->removeFromParent();
}