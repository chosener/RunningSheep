
#include "Line.h"

bool Line::initWithNothing()
{
    if (this->GameTouchNode::init() == false) {
        return false;
    }
    this->scheduleUpdate();
    this->setfSpeed(0.0f);
    this->setbIsOnceCollide(false);

    return true;
}

bool Line::initWithFile(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::create(name);
	this->addChild(icon);
	return true;
}

bool Line::initWithSpriteFrameName(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::createWithSpriteFrameName(name);
	this->addChild(icon);
	return true;
}

Line* Line::create()
{
    Line* ret = new Line();
    if (ret->initWithNothing()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

Line* Line::create(const char* name)
{
	Line* ret = new Line();
	if (ret->initWithFile(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

Line* Line::createWithSpriteFrameName(const char* name)
{
	Line* ret = new Line();
	if (ret->initWithSpriteFrameName(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

void Line::update(float dt)
{
    int sizeWhite = (int)this->m_vecSheepWhite.size();
    int sizeBlack = (int)this->m_vecSheepBlack.size();
    
    float fSpeed = 0.0f;
    
    if(!this->m_bIsOnceCollide)
    {
        for (int i = 0; i<sizeWhite; i++)
        {
            SheepWhite* white = this->m_vecSheepWhite.at(i);
            Rect rectWhite = white->getrectCollide();
            for (int j = 0; j<sizeBlack; j++)
            {
                SheepBlack* black = this->m_vecSheepBlack.at(j);
                Rect rectBlack = black->getrectCollide();
                if(rectWhite.intersectsRect(rectBlack))
                {
                    //碰撞了
                    //fSpeed = white->getfPower() + black->getfPower();
                    this->setbIsOnceCollide(true);
                    break;
                }
            }
        }
    }
    else
    {
        float fPowerWhite = 0.0f;
        float fPowerBlack = 0.0f;
        for (int i = 0; i<sizeWhite; i++)
        {
            SheepWhite* white = this->m_vecSheepWhite.at(i);
            Rect rectWhite = white->getrectCollide();
            for (int j = 0; j<sizeBlack; j++)
            {
                SheepBlack* black = this->m_vecSheepBlack.at(j);
                Rect rectBlack = black->getrectCollide();
                if(rectWhite.intersectsRect(rectBlack))
                {

                    bool isContainW = m_vecSheepCollide.contains(white);
                    bool isContainB = m_vecSheepCollide.contains(black);
                    
                    white->playAction(En_Action_Hit);
                    black->playAction(En_Action_Hit);
                    
                    if(!isContainW)
                    {
                        m_vecSheepCollide.pushBack(white);
                    }
                    if(!isContainB)
                    {
                        m_vecSheepCollide.pushBack(black);
                    }

                }
            }
        }

        
        int sizeSheep = (int)this->m_vecSheepCollide.size();
        if(sizeSheep > 0)
        {
            for (int i = 0; i<sizeSheep; i++)
            {
                Sheep* sheep = this->m_vecSheepCollide.at(i);
                
                if(!sheep->getbIsDead())
                {
                   fSpeed += sheep->getfPower();
                }

                
            }
            
            for(const auto &sheep : m_vecSheepCollide)
            {
                //Sheep* sheep = this->m_vecSheepCollide.at(i);
                
                sheep->setbIsCollide(true);
                
                sheep->setfSpeed(fSpeed);
                
                if(sheep->getbIsDead())
                {
                    //this->m_vecSheepCollide.eraseObject(sheep);
                    //sheep->releaseSelf();
                }
            }

        }


    }

    //DLog::d("fSpeed", fSpeed);
}


void Line::pushDequeWhite(SheepWhite* white)
{
    this->m_vecSheepWhite.pushBack(white);
}
void Line::pushDequeBlack(SheepBlack* black)
{
    this->m_vecSheepBlack.pushBack(black);
}

void Line::eraseDequeWhite(SheepWhite* white)
{
    this->m_vecSheepWhite.eraseObject(white);
}
void Line::eraseDequeBlack(SheepBlack* black)
{
    this->m_vecSheepBlack.eraseObject(black);
}

