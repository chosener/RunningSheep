#ifndef __RunningSheep_Test_H__
#define __RunningSheep_Test_H__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"


///小羊的头像
class Test : public GameTouchNode
{

public:
	bool initWithFile(const char* name);
	bool initWithSpriteFrameName(const char* name);

public:
	static Test* create(const char* name);
	static Test* createWithSpriteFrameName(const char* name);
};

#endif

