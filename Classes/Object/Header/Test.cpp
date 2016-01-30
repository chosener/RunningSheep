
#include "Test.h"

bool Test::initWithFile(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::create(name);
	this->addChild(icon);
	return true;
}

bool Test::initWithSpriteFrameName(const char* name)
{
	if (this->GameTouchNode::init() == false) {
		return false;
	}

	Sprite* icon = Sprite::createWithSpriteFrameName(name);
	this->addChild(icon);
	return true;
}

Test* Test::create(const char* name)
{
	Test* ret = new Test();
	if (ret->initWithFile(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

Test* Test::createWithSpriteFrameName(const char* name)
{
	Test* ret = new Test();
	if (ret->initWithSpriteFrameName(name)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}
