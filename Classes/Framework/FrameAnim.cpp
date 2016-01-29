#include <stdio.h>
#include <string.h>

#include "FrameAnim.h"

Sprite* createFrameAnimForever(const char* plist, const char*png,
                            const char*name_format, 
							int index, int count, float time)
{
	char name[128];

	if (count <= 0 || plist == NULL || png == NULL || name_format == NULL) {
		return NULL;
	}

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(plist, png);

	int i = 0;
	Vector<SpriteFrame*> animFrames;
	for (i = index; i < index + count; i++) {
		sprintf(name, name_format, i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
		animFrames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
	Animate* anim = Animate::create(animation);

	Sprite* it = Sprite::create();

	sprintf(name, name_format, index);
	SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
	it->setSpriteFrame(frame);

	it->runAction(RepeatForever::create(anim));

	return it;
}

Sprite* createFrameAnimOnce(const char* plist, const char*png,
                         const char*name_format, int index, 
						 int count, float time, CallFunc* func)
{
	char name[128];

	if (count <= 0 || plist == NULL || png == NULL) {
		return NULL;
	}

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile(plist, png);

	int i = 0;
	Vector<SpriteFrame*> animFrames;
	for (i = index; i < index + count; i++) {
		sprintf(name, name_format, i);
		SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
		animFrames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
	Animate* anim = Animate::create(animation);

	Sprite* it = Sprite::create();

	sprintf(name, name_format, index);
	SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
	it->setSpriteFrame(frame);

	// it->runAction(anim);
	if (func != NULL) {
		Sequence* seq = Sequence::create(anim, func, NULL);
		it->runAction((seq));
	}
	else {
		Sequence* seq = Sequence::create(anim, NULL);
		it->runAction((seq));
	}

	return it;
}

Sprite* createFrameRectAnimForever(const char*png,int widthCell,int heightCell, int count, float time)
{
    char name[128];
    
    if (count <= 0  || png == NULL) {
        return NULL;
    }
    
    Texture2D *texture = TextureCache::getInstance()->addImage(png);

    int i = 0;
    Vector<SpriteFrame*> animFrames;
    
    for (i = 0; i < count; i++)
    {
        SpriteFrame* frame = SpriteFrame::createWithTexture(texture, Rect(widthCell * i,0,widthCell,heightCell));
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
    Animate* anim = Animate::create(animation);
    
    Sprite* it = Sprite::create();
    
    it->runAction(RepeatForever::create(anim));
    
    return it;
}
