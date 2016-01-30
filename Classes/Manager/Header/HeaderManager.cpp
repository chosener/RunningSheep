//
//  HeaderManager.cpp
//  MagicTouch
//
//  Created by DongSai on 4/9/15.
//
//

#include "HeaderManager.h"


static HeaderManager* m_HeaderMng = nullptr;

HeaderManager::HeaderManager()
{
    
}

HeaderManager::~HeaderManager()
{
    
}

HeaderManager* HeaderManager::getInstance()
{
    if(m_HeaderMng == nullptr)
    {
        m_HeaderMng = new HeaderManager();
        //初始化
        if (m_HeaderMng && m_HeaderMng->init()) {
            m_HeaderMng->autorelease();
            m_HeaderMng->retain();
        }
    }
    return m_HeaderMng;
}

bool HeaderManager::init()
{

    this->initVariables();
    
    return true;
}

void HeaderManager::initVariables()
{
    this->setHeadLeftLocked(false);
    this->setHeadRightLocked(false);
    
    this->setbIsStart(false);

    //this->addHeader();

}

void HeaderManager::update(float dt)
{
    int sizeLeft = (int)this->m_dequeHeaderLeft.size();
    if(sizeLeft > 0)
    {
        Header* headerFront = this->m_dequeHeaderLeft.front();
        if(headerFront->getbIsUse())
        {
            this->removeHeaderFront(headerFront->getiCamp());
        }
    }
}
void HeaderManager::addStartHeader()
{
    for(int i = 0; i< 3;i++ )
    {
        addHeader(En_Camp_Team, i);
        addHeader(En_Camp_Enemy, i);
    }
    
    this->setHeaderFrontOpen();
}
///设置两边的头一个位置都为开放状态
void HeaderManager::setHeaderFrontOpen()
{
    Header* headerLeftFront = this->m_dequeHeaderLeft.front();
    headerLeftFront->setbIsLocked(false);
    
    Header* headerLeftRight = this->m_dequeHeaderRight.front();
    headerLeftRight->setbIsLocked(false);
}
void HeaderManager::addHeader(int camp,int num)
{
    //生成哪一个羊
    int index = this->getHeaderIndex();
    
    Header* header = Header::create(index,camp);
    
    switch (camp) {
        case En_Camp_Team:
        {
            //队友
            m_dequeHeaderRight.push_back(header);
            
            
            DLog::d("size",(int)m_dequeHeaderRight.size());
        }
            break;
        case En_Camp_Enemy:
        {
            //敌人
            m_dequeHeaderLeft.push_back(header);
            
            
            DLog::d("size",(int)m_dequeHeaderLeft.size());
        }
            break;
            
        default:
            break;
    }

    
    header->setPosition(this->getPosHeader(camp, num));
    
    header->setiIndex(index);
    
    header->setiNum(num);
    
    this->m_Layer->addChild(header,1001);

}
void HeaderManager::removeHeaderFront(int camp)
{
    switch (camp) {
        case En_Camp_Team:
        {
            Header* header = this->m_dequeHeaderRight.front();
            this->m_Layer->removeChild(header);
            this->m_dequeHeaderRight.pop_front();
        }
            break;
        case En_Camp_Enemy:
        {
            
            //添加一个
            this->addHeader(camp, 3);
            
            
            //移动头像
            this->moveLeftHeader();
            
            //移除一个
            Header* header = this->m_dequeHeaderLeft.front();
            this->m_Layer->removeChild(header);
            this->m_dequeHeaderLeft.pop_front();


        }
            break;
            
        default:
            break;
    }
}
void HeaderManager::moveLeftHeader()
{
    int sizeLeft = (int)this->m_dequeHeaderLeft.size();
    if(sizeLeft > 0)
    {
        for (int i = 0; i < sizeLeft; i++)
        {
            Header* header = this->m_dequeHeaderLeft.at(i);
            
            int num = header->getiNum();//哪一个位置
            
            num -= 1;
            
            num = (num <= 0) ? 0 : num;
            
            header->setiNum(num);//设置新的位置
            
            bool isVisible = (num < 3) ? true : false;
            
            header->setVisible(isVisible);
            
            Vec2 aimPos = this->getPosHeader(En_Camp_Enemy, num);
            
            MoveTo* moveTo = MoveTo::create(0.2f, aimPos);
            
            CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(HeaderManager::callBackMove,this));
            
            Sequence* seq = Sequence::create(moveTo,callFunc, NULL);
            
            header->runAction(seq);
        }
    }
}
void HeaderManager::moveRightHeader()
{
    
}

void HeaderManager::callBackMove(Node* node)
{
    Header* header = (Header*)node;
    int camp = header->getiCamp();
    switch (camp) {
        case En_Camp_Team:
        {
            Header* headerLeftRight = this->m_dequeHeaderRight.front();
            headerLeftRight->setbIsLocked(false);
        }
            break;
        case En_Camp_Enemy:
        {
            Header* headerLeftFront = this->m_dequeHeaderLeft.front();
            headerLeftFront->setbIsLocked(false);
        }
            break;
            
        default:
            break;
    }

}
void HeaderManager::letGo(int line)
{
    Header* headerRight = this->m_dequeHeaderRight.front();
    int index = headerRight->getiIndex();
    
    SheepWhite* sheepWhite = SheepWhite::createWithFrameAnim("images/game/goldBig.png");
    sheepWhite->setPosition(DISPLAY_LEFT,DISPLAY_BOTTOM + 120*line + 60);
    this->getLayer()->addChild(sheepWhite,5);
}

int HeaderManager::getHeaderIndex()
{
    int pRet = -1;
    
    int random = CCRANDOM_0_1()*5.0f;
    
    DLog::d("rand",random);
    
    pRet = random;
    
    return pRet;
}
int HeaderManager::getHeaderRate()
{
    int pRet = -1;
    
    pRet = 50;
    
    return pRet;
}

///头像位置
Vec2 HeaderManager::getPosHeader(int camp,int num)
{
    Vec2 pos = Vec2::ZERO;

    int yPos = DISPLAY_TOP - 48;

    switch (camp) {
        case En_Camp_Team:
        {
            Vec2 originRight[4] = {Vec2(1116, yPos),Vec2(996, yPos),Vec2(890, yPos),Vec2(770, yPos)};
            pos = originRight[num];
        }
            break;
        case En_Camp_Enemy:
        {
            Vec2 originLeft[4] = {Vec2(170, yPos),Vec2(285, yPos),Vec2(392, yPos),Vec2(511, yPos)};
            pos = originLeft[num];
        }
            break;
            
        default:
            break;
    }
    
    
    return pos;
}

