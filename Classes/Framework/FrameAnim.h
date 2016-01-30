#ifndef __FRAME_ANIM_H__
#define __FRAME_ANIM_H__

#include "cocos2d.h"
USING_NS_CC;

/*
int start_index[] = {1, 3, ...} start_index[U_DIR]
*/
Sprite* createFrameAnimForever(const char* plist, const char*png,
                            const char*name_format,
							int index, int count, float time);

Sprite* createFrameAnimOnce(const char* plist, const char*png,
                         const char*name_format, int index,
						 int count, float time, CallFunc* func = NULL);

Sprite* createFrameRectAnimForever(const char*png,int widthCell,int heightCell, int count, float time);
#endif
