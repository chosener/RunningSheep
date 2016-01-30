
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
bool Header::initWithIndex(int index)
{
    if (this->GameTouchNode::init() == false) {
        return false;
    }
    string name = getNamePng(index, En_Camp_Team);
    
    Sprite* icon = Sprite::create(name);
    
    this->addChild(icon);
    
    return true;
}

Header* Header::create(int index)
{
    Header* ret = new Header();
    if (ret->initWithIndex(index))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
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