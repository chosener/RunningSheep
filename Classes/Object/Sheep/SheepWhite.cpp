//
//  SheepWhite.cpp
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#include "SheepWhite.h"

SheepWhite::SheepWhite()
{
    this->setiCamp(En_Camp_None);
    this->setiType(En_SheepType_None);
    this->setiPower(0);
    this->setiSpeed(0);
    this->setiDirection(En_Direction_None);
}
SheepWhite::~SheepWhite()
{
    
}
bool SheepWhite::initWithIndex(int index)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    Sprite* icon = createFrameRectAnimForever("images/game/sheep/huge_rightSheep_run.png", 141, 150, 8, 0.1);
    this->addChild(icon);
    

    initView();
    
    return true;
}
bool SheepWhite::initWithFile(const char* name)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    Sprite* icon = Sprite::create(name);
    this->addChild(icon);
    
    initView();
    
    return true;
}

bool SheepWhite::initWithSpriteFrameName(const char* name)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    Sprite* icon = Sprite::createWithSpriteFrameName(name);
    this->addChild(icon);
    
    initView();
    
    return true;
}

///通过动画创建
bool SheepWhite::initWithFrameAnim(const char* name)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    Sprite* icon = createFrameRectAnimForever("images/game/sheep/huge_rightSheep_run.png", 141, 150, 8, 0.1);
    this->addChild(icon);
    
    initView();
    
    return true;
}

SheepWhite* SheepWhite::create(int index)
{
    SheepWhite* ret = new SheepWhite();
    if (ret->initWithIndex(index))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

SheepWhite* SheepWhite::create(const char* name)
{
    SheepWhite* ret = new SheepWhite();
    if (ret->initWithFile(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

SheepWhite* SheepWhite::createWithSpriteFrameName(const char* name)
{
    SheepWhite* ret = new SheepWhite();
    if (ret->initWithSpriteFrameName(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}
SheepWhite* SheepWhite::createWithFrameAnim(const char* name)
{
    SheepWhite* ret = new SheepWhite();
    if (ret->initWithFrameAnim(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}
void SheepWhite::initView()
{
    this->setrectCollide(Rect(0, 0, 141, 150));
}

string SheepWhite::getNamePng(int index,int camp)
{
    string pRet = "";
    
    switch (camp) {
        case En_Camp_Team:
        {
            string namePng[SHEEP_KIND] = {"sheepHR.png","sheepBR.png","sheepNR.png","sheepLR.png","sheepMR.png"};
            pRet = namePng[index];
        }
            break;
        case En_Camp_Enemy:
        {
            string namePng[SHEEP_KIND] = {"sheepHL.png","sheepBL.png","sheepNL.png","sheepLL.png","sheepML.png"};
            pRet = namePng[index];
        }
            break;
            
        default:
            break;
    }
    
    pRet = StringUtils::format("images/game/header/%s",pRet.c_str());
    
    return pRet;
}
