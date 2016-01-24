#include <stdio.h>
#include <string.h>
using namespace std;

#include "common.h"
#include "TouchSprite.h"

bool TouchSprite::initWithFile(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::create(name);
	this->addChild(icon);
	return true;
}

bool TouchSprite::initWithSpriteFrameName(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::createWithSpriteFrameName(name);
	this->addChild(icon);
	return true;
}

TouchSprite* TouchSprite::create(const char* name)
{
	TouchSprite* ret = new TouchSprite();
	if (ret->initWithFile(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

TouchSprite* TouchSprite::createWithSpriteFrameName(const char* name)
{
	TouchSprite* ret = new TouchSprite();
	if (ret->initWithSpriteFrameName(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}
