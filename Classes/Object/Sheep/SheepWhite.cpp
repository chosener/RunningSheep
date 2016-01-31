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
    
    this->scheduleUpdate();
    
    this->setiIndex(index);
    
    this->setiCamp(camp);
    
    this->setSheepPower();

    this->playAction(En_Action_Run);
    
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
    Size sizeCollide = this->getCollideSize(this->m_iIndex,this->m_iAniState);
    this->setrectCollide(Rect(0, 0, sizeCollide.width, sizeCollide.height));
}



void SheepWhite::playAction(int _indexAction)
{

    bool isSame = (this->m_iAniState == _indexAction) ? true : false;
    
    if(isSame)
        return;
    
    this->setiAniState(_indexAction);
    
    switch (_indexAction)
    {
        case En_Action_Run:
        {

            string namePng = this->getNamePng(this->m_iIndex, this->m_iCamp);
            
            Size size = this->getAnimSize(this->m_iIndex);
            
            Sprite* icon = createFrameRectAnimForever(namePng.c_str(), size.width, size.height, 8, 0.1);
            
            icon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
            
            icon->setFlippedX(true);
            
            this->addChild(icon,1,1);
            Sprite* icon0 = (Sprite*)this->getChildByTag(2);
            if(icon0)
            {
                FadeOut* fadeOut = FadeOut::create(0.2f);
                
                CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(SheepWhite::callBackAni,this));
                
                Sequence* seq = Sequence::create(fadeOut,callFunc, NULL);
                
                icon0->runAction(seq);
                
            }

        }
            break;
        case En_Action_Hit:
        {

            string namePng = this->getNamePngHit(this->m_iIndex, this->m_iCamp);
            
            Size size = this->getAnimSize(this->m_iIndex,En_Action_Hit);
            
            Sprite* icon = createFrameRectAnimForever(namePng.c_str(), size.width, size.height, 8, 0.1);
            
            icon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
            
            icon->setFlippedX(true);
            
            this->addChild(icon,1,2);
            Sprite* icon0 = (Sprite*)this->getChildByTag(1);
            if(icon0)
            {

                FadeOut* fadeOut = FadeOut::create(0.2f);
                
                CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(SheepWhite::callBackAni,this));
                
                Sequence* seq = Sequence::create(fadeOut,callFunc, NULL);
                
                icon0->runAction(seq);
            }

        }
            break;
            
        default:
            break;
    }
}
void SheepWhite::callBackAni(Node* node)
{
    node->removeFromParent();
}
Size SheepWhite::getAnimSize(int index,int _indexAction)
{
    Size size = Size::ZERO;
    
    switch (index) {
        case 0:
        {
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(141, 150);
                    break;
                case En_Action_Hit:
                    size = Size(150, 131);
                    break;
                    
                default:
                    break;
            }
            
        }
            break;
        case 1:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(116, 91);
                    break;
                case En_Action_Hit:
                    size = Size(128, 88);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 2:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(108, 68);
                    break;
                case En_Action_Hit:
                    size = Size(113, 69);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 3:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(79, 62);
                    break;
                case En_Action_Hit:
                    size = Size(76, 58);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 4:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(54, 53);
                    break;
                case En_Action_Hit:
                    size = Size(52, 50);
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        default:
            break;
    }
    
    return size;
}

Size SheepWhite::getCollideSize(int index,int _indexAction)
{
    Size size = Size::ZERO;
    
    switch (index) {
        case 0:
        {
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(141, 150);
                    break;
                case En_Action_Hit:
                    size = Size(150, 131);
                    break;
                    
                default:
                    break;
            }
            
        }
            break;
        case 1:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(116, 91);
                    break;
                case En_Action_Hit:
                    size = Size(128, 88);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 2:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(108, 68);
                    break;
                case En_Action_Hit:
                    size = Size(113, 69);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 3:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(79, 62);
                    break;
                case En_Action_Hit:
                    size = Size(76, 58);
                    break;
                    
                default:
                    break;
            }
        }
            break;
        case 4:
        {
            
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(54, 53);
                    break;
                case En_Action_Hit:
                    size = Size(52, 50);
                    break;
                    
                default:
                    break;
            }
        }
            break;
            
        default:
            break;
    }
    
#if 0
    
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
#endif
    
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
string SheepWhite::getNamePngHit(int index,int camp)
{
    string pRet = "";
    string strDir = "";
    switch (camp) {
        case En_Camp_Team:
        {
            string namePng[SHEEP_KIND] = {"huge_rightSheep_hit.png","big_rightSheep_hit.png","normal_rightSheep_hit.png","little_rightSheep_hit.png","mini_rightSheep_hit.png"};
            pRet = namePng[index];
            strDir = "Sheep_Right";
        }
            break;
        case En_Camp_Enemy:
        {
            string namePng[SHEEP_KIND] = {"huge_leftSheep_hit.png","big_leftSheep_hit.png","normal_leftSheep_hit.png","little_leftSheep_hit.png","mini_leftSheep_hit.png"};
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
