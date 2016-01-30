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
     
}
void HeaderManager::addStartHeader()
{
    for(int i = 0; i< 4;i++ )
    {
        addHeader(En_Camp_Team, i);
        addHeader(En_Camp_Enemy, i);
    }
}
void HeaderManager::addHeader(int camp,int num)
{
    int index = this->getHeaderIndex();
    
    Header* header = Header::create(index);
    
    m_dequeHeaderLeft.push_back(header);
    
    DLog::d("size",(int)m_dequeHeaderLeft.size());
    
    header->setPosition(this->getPosHeader(camp, num));
    
    this->m_Layer->addChild(header,1001);
    
    //m_dequeHeaderLeft.pop_front();
    
    //DLog::d("size",(int)m_dequeHeaderLeft.size());
}

int HeaderManager::getHeaderIndex()
{
    int pRet = -1;
    
    int random = CCRANDOM_0_1()*100.0f;
    
    DLog::d("rand",random);
    
    pRet = 3;
    
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

    int yPos = DISPLAY_TOP - 50;

    switch (camp) {
        case En_Camp_Team:
        {
            Vec2 originRight[4] = {Vec2(1120, yPos),Vec2(1002, yPos),Vec2(884, yPos),Vec2(766, yPos)};
            pos = originRight[num];
        }
            break;
        case En_Camp_Enemy:
        {
            Vec2 originLeft[4] = {Vec2(168, yPos),Vec2(282, yPos),Vec2(394, yPos),Vec2(514, yPos)};
            pos = originLeft[num];
        }
            break;
            
        default:
            break;
    }
    
    
    return pos;
}

