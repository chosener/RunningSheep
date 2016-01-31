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


void LineManager::update(float dt)
{
     
}