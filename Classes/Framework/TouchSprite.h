#ifndef __TOUCH_SPRITE_H__
#define __TOUCH_SPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

#include "GameTouchNode.h"

class TouchSprite : public GameTouchNode {

public:
	bool initWithFile(const char* name);
	bool initWithSpriteFrameName(const char* name);

public:
	static TouchSprite* create(const char* name);
	static TouchSprite* createWithSpriteFrameName(const char* name);
};

#endif

