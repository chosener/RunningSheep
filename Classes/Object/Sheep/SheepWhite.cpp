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

}
SheepWhite::~SheepWhite()
{
    
}
bool SheepWhite::initWithIndex(int index,int camp)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    this->setiIndex(index);
    
    this->setiCamp(camp);
    
    this->setSheepPower();
    
    string namePng = this->getNamePng(index, camp);
    
    Size size = this->getAnimSize(index);
    
    Sprite* icon = createFrameRectAnimForever(namePng.c_str(), size.width, size.height, 8, 0.1);
    
    icon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    
    icon->setFlippedX(true);
    
    this->addChild(icon);
    
    //icon->setTexture("images/game/sheep/Sheep_Right/huge_rightSheep_hit.png");
    

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

SheepWhite* SheepWhite::create(int index,int camp)
{
    SheepWhite* ret = new SheepWhite();
    if (ret->initWithIndex(index,camp))
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
    Size sizeCollide = this->getCollideSize(this->m_iIndex);
    this->setrectCollide(Rect(0, 0, sizeCollide.width, sizeCollide.height));
}

Size SheepWhite::getAnimSize(int index)
{
    Size size = Size::ZERO;
    
    switch (index) {
        case 0:
        {
            size = Size(141, 150);
        }
            break;
        case 1:
        {
            size = Size(116, 91);
        }
            break;
        case 2:
        {
            size = Size(108, 68);
        }
            break;
        case 3:
        {
            size = Size(79, 62);
        }
            break;
        case 4:
        {
            size = Size(54, 53);
        }
            break;
            
        default:
            break;
    }
    
    return size;
}

Size SheepWhite::getCollideSize(int index)
{
    Size size = Size::ZERO;
    
    switch (index) {
        case 0:
        {
            size = Size(98.7f, 150);
        }
            break;
        case 1:
        {
            size = Size(81.2f, 91);
        }
            break;
        case 2:
        {
            size = Size(75.6f, 68);
        }
            break;
        case 3:
        {
            size = Size(55.3f, 62);
        }
            break;
        case 4:
        {
            size = Size(37.8f, 53);
        }
            break;
        default:
            break;
    }
    
    return size;
}

string SheepWhite::getNamePng(int index,int camp)
{
    string pRet = "";
    string strDir = "";
    switch (camp) {
        case En_Camp_Team:
        {
            string namePng[SHEEP_KIND] = {"huge_rightSheep_run.png","big_rightSheep_run.png","normal_rightSheep_run.png","little_rightSheep_run.png","mini_rightSheep_run.png"};
            pRet = namePng[index];
            strDir = "Sheep_Right";
        }
            break;
        case En_Camp_Enemy:
        {
            string namePng[SHEEP_KIND] = {"huge_leftSheep_run.png","big_leftSheep_run.png","normal_leftSheep_run.png","little_leftSheep_run.png","mini_leftSheep_run.png"};
            pRet = namePng[index];
            strDir = "Sheep_Left";
        }
            break;
            
        default:
            break;
    }
    
    pRet = StringUtils::format("images/game/sheep/%s/%s",strDir.c_str(),pRet.c_str());
    
    return pRet;
}
