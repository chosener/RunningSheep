#ifndef __IMAGE_BUTTON_H__
#define __IMAGE_BUTTON_H__

#include "GameTouchNode.h"

class ImageButton : public GameTouchNode {
	Sprite* nomalSprite;
	Sprite* pressedSprite;
	Sprite* invalidSprite;

private:
	bool initWithSpriteFrameName(const char* normal, const char* pressed, const char* invalid = NULL);
	bool initWithFile(const char* normal, const char* pressed, const char* invalid = NULL);

public:
	static ImageButton* createWithSpriteFrameName(const char* normal, const char* pressed, const char* invalid = NULL);
	static ImageButton* create(const char* normal, const char* pressed, const char* invalid = NULL);
	
	virtual bool onTouchBegin(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
	void setToucheEnable(bool enable);
};


#endif
