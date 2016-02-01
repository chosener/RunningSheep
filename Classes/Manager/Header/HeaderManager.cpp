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
            //放一个出去
            int line = CCRANDOM_0_1()*5.0f;
            this->letEnemyGo(line);
            
            //this->removeHeaderFront(headerFront->getiCamp());
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
            //添加一个
            this->addHeader(camp, 3);
            
            //移动头像
            this->moveRightHeader();
            
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
    int sizeLeft = (int)this->m_dequeHeaderRight.size();
    if(sizeLeft > 0)
    {
        for (int i = 0; i < sizeLeft; i++)
        {
            Header* header = this->m_dequeHeaderRight.at(i);
            
            int num = header->getiNum();//哪一个位置
            
            num -= 1;
            
            num = (num <= 0) ? 0 : num;
            
            header->setiNum(num);//设置新的位置
            
            bool isVisible = (num < 3) ? true : false;
            
            header->setVisible(isVisible);
            
            Vec2 aimPos = this->getPosHeader(En_Camp_Team, num);
            
            MoveTo* moveTo = MoveTo::create(0.2f, aimPos);
            
            CallFuncN* callFunc = CallFuncN::create(CC_CALLBACK_1(HeaderManager::callBackMove,this));
            
            Sequence* seq = Sequence::create(moveTo,callFunc, NULL);
            
            header->runAction(seq);
        }
    }
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
void HeaderManager::letTeamGo(int line)
{
    
    Header* headerRight = this->m_dequeHeaderRight.front();
    
    bool isUse = headerRight->getbIsUse();
    if(isUse)
    {
        DLog::d("放出一只白羊,line",line);
        int index = headerRight->getiIndex();
        int camp = headerRight->getiCamp();
        
        SheepWhite* sheepWhite = SheepWhite::create(index, camp);
        
        sheepWhite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
        
        sheepWhite->setPosition(DISPLAY_RIGHT - 100,DISPLAY_BOTTOM + 120*line + 20);
        
        this->getLayer()->addChild(sheepWhite,5);
        
        sheepWhite->setiLine(line);
        
        LineManager::getInstance()->pushSheepIntoLine(line, sheepWhite);
        
        
        int sizeLeft = (int)this->m_dequeHeaderRight.size();
        if(sizeLeft > 0)
        {
            Header* headerFront = this->m_dequeHeaderRight.front();
            if(headerFront->getbIsUse())
            {
                this->removeHeaderFront(headerFront->getiCamp());
            }
        }
    }
    else{
        //显示大叉子
        DLog::d("第1只羊还处于冷却状态.请等待...");
        headerRight->addChaZi();
    }
    
}

void HeaderManager::letEnemyGo(int line)
{
    DLog::d("放出一只黑羊,line",line);
    Header* headerRight = this->m_dequeHeaderLeft.front();
    int index = headerRight->getiIndex();
    int camp = headerRight->getiCamp();
    
    ///创建一个敌人羊
    
    SheepBlack* sheepBlack = SheepBlack::create(index, camp);
    
    sheepBlack->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    
    sheepBlack->setPosition(DISPLAY_LEFT + 100,DISPLAY_BOTTOM + 120*line + 20);
    
    this->getLayer()->addChild(sheepBlack,5);
    
    sheepBlack->setiLine(line);
    
    LineManager::getInstance()->pushSheepIntoLine(line, sheepBlack);
    
    //-------------------------------
    //移除一个头像
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

    int yPos = DISPLAY_TOP - 50;

    switch (camp) {
        case En_Camp_Team:
        {
            Vec2 originRight[4] = {Vec2(1114, yPos),Vec2(994, yPos),Vec2(888, yPos),Vec2(770, yPos)};
            pos = originRight[num];
        }
            break;
        case En_Camp_Enemy:
        {
            Vec2 originLeft[4] = {Vec2(168, yPos),Vec2(285, yPos),Vec2(392, yPos),Vec2(511, yPos)};
            pos = originLeft[num];
        }
            break;
            
        default:
            break;
    }
    
    
    return pos;
}

