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
    
    bool initWithIndex(int index);
    static Header* create(int index);

private:
	static Header* create(const char* name);
	static Header* createWithSpriteFrameName(const char* name);
    
private:
    string getNamePng(int index,int camp);
    
private:
    ///哪个阵营
    CC_SYNTHESIZE(unsigned int, m_iCamp, iCamp);
};

#endif /* defined(__RunningSheep__Header__) */


