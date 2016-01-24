#include "common.h"
#include "ImageButton.h"


bool ImageButton::initWithFile(const char* normal, const char* pressed, const char* invalid)
{
	if (normal == NULL || pressed == NULL) {
		return false;
	}

	if (this->init() == false) {
		return false;
	}
	
	this->nomalSprite = NULL;
	this->pressedSprite = NULL;
	this->invalidSprite = NULL;

	Sprite* nomalSprite = Sprite::create(normal);
	this->addChild(nomalSprite);
	this->nomalSprite = nomalSprite;
	this->nomalSprite->setVisible(true);

	Sprite* pressedSprite = Sprite::create(pressed);
	this->addChild(pressedSprite);
	this->pressedSprite = pressedSprite;
	this->pressedSprite->setVisible(false);

	if (invalid != NULL) {
		Sprite* invalidSprite = Sprite::create(invalid);
		if (invalidSprite) {
			this->addChild(invalidSprite);
			this->invalidSprite = invalidSprite;
			this->invalidSprite->setVisible(false);
		}
	}

	return true;
}

ImageButton* ImageButton::create(const char* normal, const char* pressed, const char* invalid)
{
	ImageButton* bt = new ImageButton();
	if (bt->initWithFile(normal, pressed, invalid)) {
		bt->autorelease();
		return bt;
	}
	CC_SAFE_DELETE(bt);
	return NULL;
}

bool ImageButton::initWithSpriteFrameName(const char* normal, const char* pressed, const char* invalid)
{
	if (normal == NULL || pressed == NULL) {
		return false;
	}

	if (this->init() == false) {
		return false;
	}

	this->nomalSprite = NULL;
	this->pressedSprite = NULL;
	this->invalidSprite = NULL;

	Sprite* nomalSprite = Sprite::createWithSpriteFrameName(normal);
	this->addChild(nomalSprite);
	this->nomalSprite = nomalSprite;
	this->nomalSprite->setVisible(true);

	Sprite* pressedSprite = Sprite::createWithSpriteFrameName(pressed);
	this->addChild(pressedSprite);
	this->pressedSprite = pressedSprite;
	this->pressedSprite->setVisible(false);

	if (invalid != NULL) {
		Sprite* invalidSprite = Sprite::createWithSpriteFrameName(invalid);
		if (invalidSprite) {
			this->addChild(invalidSprite);
			this->invalidSprite = invalidSprite;
			this->invalidSprite->setVisible(false);
		}
	}

	return true;
}

ImageButton* ImageButton::createWithSpriteFrameName(const char* normal, const char* pressed, const char* invalid)
{
	ImageButton* bt = new ImageButton();
	if (bt->initWithSpriteFrameName(normal, pressed, invalid)) {
		bt->autorelease();
		return bt;
	}
	CC_SAFE_DELETE(bt);
	return NULL;
}

bool ImageButton::onTouchBegin(Touch* touch, Event* event)
{
	bool ret = this->GameTouchNode::onTouchBegin(touch, event);
	if (ret) {
		this->pressedSprite->setVisible(true);
		this->nomalSprite->setVisible(false);
	}
	return ret;
}

void ImageButton::onTouchEnded(Touch* touch, Event* event)
{
	this->GameTouchNode::onTouchEnded(touch, event);
	this->pressedSprite->setVisible(false);
	this->nomalSprite->setVisible(true);
}

void ImageButton::setToucheEnable(bool enable)
{
	this->GameTouchNode::setToucheEnable(enable);
	if (enable == false) {
		if (this->invalidSprite) {
			this->invalidSprite->setVisible(true);
			this->pressedSprite->setVisible(false);
			this->nomalSprite->setVisible(false);
		}
	}
	else {
		if (this->invalidSprite) {
			this->invalidSprite->setVisible(false);
			this->pressedSprite->setVisible(false);
			this->nomalSprite->setVisible(true);
		}
	}
}