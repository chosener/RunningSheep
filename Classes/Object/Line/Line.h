#ifndef __TOUCH_SPRITE_H__
#define __TOUCH_SPRITE_H__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"


///小羊的线路
class Line : public GameTouchNode
{

public:
	bool initWithFile(const char* name);
	bool initWithSpriteFrameName(const char* name);

public:
	static Line* create(const char* name);
	static Line* createWithSpriteFrameName(const char* name);
};

#endif

