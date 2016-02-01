//
//  LineManager.cpp
//  MagicTouch
//
//  Created by DongSai on 4/9/15.
//
//

#include "LineManager.h"


static LineManager* m_HeaderMng = nullptr;

LineManager::LineManager()
{
    
}

LineManager::~LineManager()
{
    
}

LineManager* LineManager::getInstance()
{
    if(m_HeaderMng == nullptr)
    {
        m_HeaderMng = new LineManager();
        //初始化
        if (m_HeaderMng && m_HeaderMng->init()) {
            m_HeaderMng->autorelease();
            m_HeaderMng->retain();
        }
    }
    return m_HeaderMng;
}

bool LineManager::init()
{

    return true;
}

void LineManager::addLineToLayer()
{
    
    for(int i = 0 ; i < LINE_COUNT; i++)
    {
        Line* line = Line::create();
        this->getLayer()->addChild(line);
        this->m_vecLine.pushBack(line);
    }
}

void LineManager::update(float dt)
{
#if 0
    for (int i = 0; i < LINE_COUNT; i++)
    {
        Line* line = this->getLine(i);
        
        for(const auto &white : line->m_vecSheepWhite)
        {
            //SheepWhite* white = line->m_vecSheepWhite.at(i);
            if(white->getbIsDead())
            {

                this->eraseSheepIntoLine(i, white);

                if(!white->getbIsCollide())
                {
                    white->releaseSelf();
                }
                
            }
            
        }
        int sizeBlack = (int)line->m_vecSheepBlack.size();
        //for(const auto &black : line->m_vecSheepBlack)
        for (int i = 0; i<sizeBlack; i++)
        {
            SheepBlack* black = line->m_vecSheepBlack.at(i);
            bool isDead = black->getbIsDead();
            if(isDead)
            {

                //this->eraseSheepIntoLine(i, black);
                line->m_vecSheepBlack.eraseObject(black);
                
                if(!black->getbIsCollide())
                {
                    black->releaseSelf();
                }

            }
            
        }
        
        for(const auto &sheep : line->m_vecSheepCollide)
        {
            //Sheep* sheep = this->m_vecSheepCollide.at(i);
            
            if(sheep->getbIsDead())
            {
                line->m_vecSheepCollide.eraseObject(sheep);
                sheep->releaseSelf();
            }
        }
        
    }
#endif
}
void LineManager::pushSheepIntoLine(int _line,SheepWhite* _sheep)
{
    Line* line = this->getLine(_line);
    
    line->pushDequeWhite(_sheep);
}
void LineManager::pushSheepIntoLine(int _line,SheepBlack* _sheep)
{
    Line* line = this->getLine(_line);
    
    line->pushDequeBlack(_sheep);
}

void LineManager::eraseSheepIntoLine(int _line,SheepWhite* _sheep)
{
    Line* line = this->getLine(_line);
    line->eraseDequeWhite(_sheep);
}
void LineManager::eraseSheepIntoLine(int _line,SheepBlack* _sheep)
{
    Line* line = this->getLine(_line);
    line->eraseDequeBlack(_sheep);
}

Line* LineManager::getLine(int index)
{
    Line* line = this->m_vecLine.at(index);
    return line;
}