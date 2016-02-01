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

}
Sheep::~Sheep()
{
    
}

bool Sheep::init()
{
    if (this->GameTouchNode::init() == false) {
        return false;
    }

    this->setiCamp(En_Camp_None);
    this->setiType(En_SheepType_None);
    this->setiIndex(0);
    this->setfPower(0.0f);
    this->setfSpeed(0);
    this->setiDirection(En_Direction_None);
    
    this->setiLine(0);
    
    this->setbIsCollide(false);
    
    this->setbIsDead(false);
    
    this->setiAniState(En_Action_None);
    
    this->scheduleUpdate();
    
    return true;
}

void Sheep::addShadow()
{
    string name = StringUtils::format("images/game/Effects/shadow%d.png",5 - this->m_iIndex);
    Sprite* spShadow = Sprite::create(name.c_str());
    Rect rect = this->getrectCollide();
    //spShadow->setPosition(0,-rect.size.height/4);
    this->addChild(spShadow,10);
    bool isFlipX = false;
    switch (this->m_iCamp) {
        case En_Camp_Team:
            isFlipX = true;
            break;
        case En_Camp_Enemy:
            isFlipX = false;
            break;
            
        default:
            break;
    }
    spShadow->setFlippedX(isFlipX);
}
void Sheep::addDust()
{
    Sprite* spDust = createFrameRectAnimForever("images/game/Effects/Dust.png", 91, 22, 4, 0.2);

    spDust->setFlippedX(true);
    
    this->addChild(spDust,10,5);
    
    bool isFlipX = false;
    switch (this->m_iCamp) {
        case En_Camp_Team:
            isFlipX = true;
            break;
        case En_Camp_Enemy:
            isFlipX = false;
            break;
            
        default:
            break;
    }
    spDust->setFlippedX(isFlipX);
}

void Sheep::removeDust()
{
    Sprite* spDust = (Sprite*)this->getChildByTag(5);
    if(spDust)
    {
        spDust->removeFromParent();
    }
}

void Sheep::addTears()
{

    string name = "";

    Sprite* spTear = nullptr;
    
    switch (this->m_iCamp) {
        case En_Camp_Enemy:
        {
            name = "tearsSecond";
            spTear = createFrameAnimForever("images/game/Effects/tears/tearsSecond.plist","images/game/Effects/tears/tearsSecond.png","tearsSecond0",1,4,0.2f);
            
            Rect rest = this->getrectCollide();
            
            spTear->setPosition(rest.size.width/3.5,rest.size.height/3);
        }

            break;
        case En_Camp_Team:
        {
            name = "tearsFirst";
            spTear = createFrameAnimForever("images/game/Effects/tears/tears_First.plist","images/game/Effects/tears/tears_First.png","tearsFirst0",1,4,0.2f);
            
            Rect rest = this->getrectCollide();
            
            spTear->setPosition(-rest.size.width/3.5,rest.size.height/3);
        }
            break;
            
        default:
            break;
    }

    this->addChild(spTear,12,8);

    spTear->setScale(1.5f);
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
    
    Rect rectBattle = Rect(150, 0, DISPLAY_WIDTH - 150, DISPLAY_HEIGHT);
    
    if(!rectBattle.intersectsRect(this->m_rectCollide))
    {
        this->setbIsDead(true);
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
            fPower = 4.0f;
        }
            break;
        case 2:
        {
            fPower = 3.0f;
        }
            break;
        case 3:
        {
            fPower = 2.5f;
        }
            break;
        case 4:
        {
            fPower = 2.0f;
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