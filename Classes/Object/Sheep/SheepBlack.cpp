//
//  SheepBlack.cpp
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#include "SheepBlack.h"

#include "../../Manager/Line/LineManager.h"

SheepBlack::SheepBlack()
{

}
SheepBlack::~SheepBlack()
{
    
}

bool SheepBlack::initWithIndex(int index,int camp)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    this->setiIndex(index);
    
    this->setiCamp(camp);

    this->setrectCollide(Rect(DISPLAY_LEFT, DISPLAY_BOTTOM, 10, 10));
    
    this->setSheepPower();
    
    this->playAction(En_Action_Run);
    
    initView();
    
    this->addShadow();

    return true;
}
bool SheepBlack::initWithFile(const char* name)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    Sprite* icon = Sprite::create(name);
    this->addChild(icon);
    
    initView();
    
    return true;
}

bool SheepBlack::initWithSpriteFrameName(const char* name)
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
bool SheepBlack::initWithFrameAnim(const char* name)
{
    if (this->Sheep::init() == false) {
        return false;
    }
    
    Sprite* icon = createFrameRectAnimForever("images/game/sheep/huge_rightSheep_run.png", 141, 150, 8, 0.1);
    this->addChild(icon);
    
    initView();
    
    return true;
}

SheepBlack* SheepBlack::create(int index,int camp)
{
    SheepBlack* ret = new SheepBlack();
    if (ret->initWithIndex(index,camp))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

SheepBlack* SheepBlack::create(const char* name)
{
    SheepBlack* ret = new SheepBlack();
    if (ret->initWithFile(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

SheepBlack* SheepBlack::createWithSpriteFrameName(const char* name)
{
    SheepBlack* ret = new SheepBlack();
    if (ret->initWithSpriteFrameName(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}
SheepBlack* SheepBlack::createWithFrameAnim(const char* name)
{
    SheepBlack* ret = new SheepBlack();
    if (ret->initWithFrameAnim(name)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}
void SheepBlack::initView()
{

    Size sizeCollide = this->getCollideSize(this->m_iIndex,this->m_iAniState);
    this->setrectCollide(Rect(0, 0, sizeCollide.width, sizeCollide.height));
}

void SheepBlack::playAction(int _indexAction)
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
            
            Size size = this->getAnimSize(this->m_iIndex,_indexAction);
            
            Sprite* icon = createFrameRectAnimForever(namePng.c_str(), size.width, size.height, 8, 0.1);
            
            icon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

            this->addChild(icon,1,1);
            Sprite* icon0 = (Sprite*)this->getChildByTag(2);
            if(icon0)
            {
                FadeOut* fadeOut = FadeOut::create(0.2f);
                
                CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(SheepBlack::callBackAni,this));
                
                Sequence* seq = Sequence::create(fadeOut,callFunc, NULL);
                
                icon0->runAction(seq);
                
            }
            this->removeDust();
            
        }
            break;
        case En_Action_Hit:
        {
            
            string namePng = this->getNamePngHit(this->m_iIndex, this->m_iCamp);
            
            Size size = this->getAnimSize(this->m_iIndex,_indexAction);
            
            Sprite* icon = createFrameRectAnimForever(namePng.c_str(), size.width, size.height, 8, 0.1);
            
            icon->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
            
            this->addChild(icon,1,2);
            Sprite* icon0 = (Sprite*)this->getChildByTag(1);
            if(icon0)
            {
                
                FadeOut* fadeOut = FadeOut::create(0.2f);
                
                CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(SheepBlack::callBackAni,this));
                
                Sequence* seq = Sequence::create(fadeOut,callFunc, NULL);
                
                icon0->runAction(seq);
            }
            
            this->addDust();
            
            this->addTears();
            
        }
            break;
            
        default:
            break;
    }
    Size sizeCollide = this->getCollideSize(this->m_iIndex,this->m_iAniState);
    this->setrectCollide(Rect(0, 0, sizeCollide.width, sizeCollide.height));
}
void SheepBlack::callBackAni(Node* node)
{
    node->removeFromParent();
}
void SheepBlack::releaseSelf()
{
    Sheep::releaseSelf();

    LineManager::getInstance()->eraseSheepIntoLine(this->m_iLine, this);
}

void SheepBlack::update(float dt)
{
    Sheep::update(dt);
    
    if(this->m_bIsDead)
    {
        this->releaseSelf();
    }
}

Size SheepBlack::getAnimSize(int index,int _indexAction)
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

Size SheepBlack::getCollideSize(int index,int _indexAction)
{
    Size size = Size::ZERO;
    
    float rate = 0.7f;
    
    switch (index) {
        case 0:
        {
            switch (_indexAction) {
                case En_Action_Run:
                    size = Size(141*rate, 150);
                    break;
                case En_Action_Hit:
                    size = Size(150*rate, 131);
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
                    size = Size(116*rate, 91);
                    break;
                case En_Action_Hit:
                    size = Size(128*rate, 88);
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
                    size = Size(108*rate, 68);
                    break;
                case En_Action_Hit:
                    size = Size(113*rate, 69);
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
                    size = Size(79*rate, 62);
                    break;
                case En_Action_Hit:
                    size = Size(76*rate, 58);
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
                    size = Size(54*rate, 53);
                    break;
                case En_Action_Hit:
                    size = Size(52*rate, 50);
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

string SheepBlack::getNamePng(int index,int camp)
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
string SheepBlack::getNamePngHit(int index,int camp)
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

