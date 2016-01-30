//
//  TestManager.cpp
//  MagicTouch
//
//  Created by DongSai on 4/9/15.
//
//

#include "TestManager.h"


static TestManager* m_HeaderMng = nullptr;

TestManager::TestManager()
{
    
}

TestManager::~TestManager()
{
    
}

TestManager* TestManager::getInstance()
{
    if(m_HeaderMng == nullptr)
    {
        m_HeaderMng = new TestManager();
        //初始化
        if (m_HeaderMng && m_HeaderMng->init()) {
            m_HeaderMng->autorelease();
            m_HeaderMng->retain();
        }
    }
    return m_HeaderMng;
}

bool TestManager::init()
{

    return true;
}


void TestManager::update(float dt)
{
     
}