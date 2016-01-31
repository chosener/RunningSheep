#ifndef __RunningSheep__Header__
#define __RunningSheep__Header__


#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"

///小羊的头像
class Header : public GameTouchNode
{

public:
	bool initWithFile(const char* name);
	bool initWithSpriteFrameName(const char* name);
    
    bool initWithIndex(int index,int camp);
    static Header* create(int index,int camp);
    
    void update(float dt);
    
public:
    
    void addChaZi();

private:
	static Header* create(const char* name);
	static Header* createWithSpriteFrameName(const char* name);
    
    void addBarTime();

    void callBackChaZie(Node* node);
    
private:
    string getNamePng(int index,int camp);
    void initVariables();
private:
    ///哪个索引
    CC_SYNTHESIZE(unsigned int, m_iIndex, iIndex);
    ///哪个位置
    CC_SYNTHESIZE(unsigned int, m_iNum, iNum);
    ///哪个阵营
    CC_SYNTHESIZE(unsigned int, m_iCamp, iCamp);
    ///CDTime
    CC_SYNTHESIZE(unsigned int, m_iCDTime, iCDTime);
    ///是不是可以用
    CC_SYNTHESIZE(bool, m_bIsUse, bIsUse);
    ///是不是锁定
    CC_SYNTHESIZE(bool, m_bIsLocked, bIsLocked);
};

#endif /* defined(__RunningSheep__Header__) */


