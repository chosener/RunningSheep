#ifndef __COMMON_H__
#define __COMMON_H__

#include "CocosHead.h"

#define DISPLAY_SIZE (Director::getInstance()->getWinSize())

#define DISPLAY_WIDTH (DISPLAY_SIZE.width)
#define DISPLAY_HEIGHT (DISPLAY_SIZE.height)

#define DISPLAY_CX (DISPLAY_WIDTH / 2.0f)
#define DISPLAY_CY (DISPLAY_HEIGHT / 2.0f)

#define DISPLAY_LEFT (0)
#define DISPLAY_RIGHT (DISPLAY_WIDTH)
#define DISPLAY_TOP (DISPLAY_HEIGHT)
#define DISPLAY_BOTTOM (0)

#define ADD_SPRITE_FRAMES(plist, png) (SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plist, png))

#define EVENT_DISPATCHER (Director::getInstance()->getEventDispatcher())

float getDegreeByVec(const Vec2& pos);
float getRadianByVec(const Vec2& pos);


void callLater(Node* target, float delay, const std::function<void()> &func);
#define performWithDelay callLater 

#if 0
template<class T>
void randomVector(Vector<T>& set, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int index0 = random() % count;
		int index1 = random() % count;
		set.swap(index0, index1);

	}
}

template<class T>
void random_vector(std::vector<T>& set, int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int index0 = random() % count;
		int index1 = random() % count;

		T t = set.at(index0);
		set.at(index0) = set.at(index1);
		set.at(index1) = t;
	}
}
#endif

#endif
