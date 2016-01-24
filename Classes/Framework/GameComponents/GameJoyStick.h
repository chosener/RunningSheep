#ifndef __GAME_JOY_STICK_H__
#define __GAME_JOY_STICK_H__

#include "CocosHead.h"

enum {
	U_DIR = 0,
	D_DIR,
	L_DIR,
	R_DIR,
	RU_DIR,
	LU_DIR,
	LD_DIR,
	RD_DIR,
	INVALID_DIR,
};

#define JOY_STICK_EVENT "joy_stick_event"

class TouchSprite;
class GameJoyStick : public Node {
private:
	TouchSprite* beadsSprite;
	float maxRadis;
	float minRadis = 0;
	
private:
	int getDirection(float r);

public:
	bool initWithFile(const char*bkName, 
	                 const char* beads, float maxRadis, float minRadis = 0.0f);

	bool initWithSpriteFrameName(const char*bkName,
		const char* beads, float maxRadis, float minRadis = 0.0f);

	void onCaptureEventHandler(int type, Touch* touch, Event* e);
public:
	static GameJoyStick* create(const char* bkName, 
		const char* beads, float maxRadis, float minRadis = 0.0f);

	static GameJoyStick* createWithSpriteFrameName(const char* bkName,
		const char* beads, float maxRadis, float minRadis = 0.0f);
};

#endif
