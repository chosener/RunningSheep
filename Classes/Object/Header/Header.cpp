
#include "Header.h"

bool Header::initWithFile(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::create(name);
	this->addChild(icon);
	return true;
}

bool Header::initWithSpriteFrameName(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::createWithSpriteFrameName(name);
	this->addChild(icon);
	return true;
}

Header* Header::create(const char* name)
{
	Header* ret = new Header();
	if (ret->initWithFile(name))
    {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

Header* Header::createWithSpriteFrameName(const char* name)
{
	Header* ret = new Header();
	if (ret->initWithSpriteFrameName(name))
    {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}
bool Header::initWithIndex(int index,int camp)
{
    if (this->GameTouchNode::init() == false) {
        return false;
    }
    
    this->scheduleUpdate();
    
    this->setiIndex(index);
    
    this->setiCamp(camp);
    
    string name = getNamePng(index, camp);
    
    Sprite* icon = Sprite::create(name);
    
    this->addChild(icon,5);
    
    this->addBarTime();

    this->initVariables();
    return true;
}

Header* Header::create(int index,int camp)
{
    Header* ret = new Header();
    if (ret->initWithIndex(index,camp))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}
void Header::initVariables()
{
    this->setiNum(0);
    this->setiCDTime(100);
    this->setbIsUse(false);
    this->setbIsLocked(true);
    bool isVisible = (this->m_iNum < 3) ? true : false;
    this->setVisible(isVisible);
}
void Header::update(float dt)
{
    if(!this->m_bIsLocked)
    {
        this->setiCDTime(--this->m_iCDTime);
        bool isZero = (this->m_iCDTime <= 0) ? true : false;
        
        if(isZero)
        {
            this->setbIsLocked(true);
            
            switch (this->m_iCamp)
            {
                case En_Camp_Team:
                {
                    //敌方自动出兵
                    this->setiCDTime(100);
                }
                    break;
                case En_Camp_Enemy:
                {
                    //敌方自动出兵
                    this->setiCDTime(100);

                }
                    break;
                    
                default:
                    break;
            }
        }
        else
        {
            int div = 100/5;
            
            int chushu = this->m_iCDTime/div;
            
            int yushu = this->m_iCDTime % div;
            
            if(yushu == 0)
            {
                string nameBar = StringUtils::format("images/game/bar/cd_%d.png",(chushu -1));
                Sprite* spBg = (Sprite*)this->getChildByTag(10);
                spBg->setTexture(nameBar.c_str());
                
                if(chushu == 1)
                {
                    this->setbIsUse(true);
                }

            }


        }
    }
    

}
void Header::addBarTime()
{
    //底
    Sprite* spBg = Sprite::create("images/game/bar/cd_4.png");
    this->addChild(spBg,4,10);

}
void Header::addChaZi()
{
    Sprite* spChaZi = Sprite::create("images/game/bar/wrong.png");
    this->addChild(spChaZi,6);
    
    FadeOut* fadeOut = FadeOut::create(0.2);
    
    CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(Header::callBackChaZie,this));
    
    Sequence* seq = Sequence::create(fadeOut,callFunc, NULL);
    
    spChaZi->runAction(seq);
}
void Header::callBackChaZie(Node* node)
{
    node->removeFromParent();
}
string Header::getNamePng(int index,int camp)
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