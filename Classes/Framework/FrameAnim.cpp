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
    string strName = "";
	Vector<SpriteFrame*> animFrames;
	for (i = index; i < index + count; i++)
    {
        sprintf(name, "%d.png", i);
        
        strName = StringUtils::format("%s%s",name_format,name);
        
		SpriteFrame* frame = frameCache->getSpriteFrameByName(strName);
		animFrames.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
	Animate* anim = Animate::create(animation);

	Sprite* it = Sprite::create();

	//sprintf(name, name_format, index);
	SpriteFrame* frame = frameCache->getSpriteFrameByName(strName);
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
    //char name[128];
    
    if (count <= 0  || png == NULL) {
        return NULL;
    }
    
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(png);

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
Sprite* createFrameAnimSingle(const char* path,const char* name,int count,int delay)
{
    
#if 1
    Vector<SpriteFrame*> animFrames;
    
    for (int i = 1; i<=count;i++)
    {
        char szName[100] = {0};
        
        sprintf(szName, "0%d.png", i);
        
        string strName = StringUtils::format("%s%s%s",path,name,szName);
        
        SpriteFrame* frame = SpriteFrame::create(strName, Rect(0, 0, 21, 30));
        
        animFrames.pushBack(frame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(animFrames, delay);
    
    Animate* anim = Animate::create(animation);
#endif
    
#if 0
    auto animation = Animation::create();
    for( int i=1;i<count;i++)
    {
        char szName[100] = {0};
        sprintf(szName, "0%d.png", i);
        
        string strName = StringUtils::format("%s%s%s",path,name,szName);
        
        animation->addSpriteFrameWithFile(strName);

    }

    // should last 2.8 seconds. And there are 14 frames.
    animation->setDelayPerUnit(delay);
    animation->setRestoreOriginalFrame(true);
    Animate* anim = Animate::create(animation);

#endif
    
    Sprite* it = Sprite::create();
    
    it->runAction(RepeatForever::create(anim));

    return it;
}
