#include <stdio.h>
#include <string.h>
using namespace std;

#include "../common.h"
#include "../TouchSprite.h"

#include "GameJoyStick.h"
// [0, pi / 8) R
// [pi / 8, 3 * pi / 8) RU
// [3 * pi / 8, 5*pi / 8) U
// [5*pi, 7*pi/8) LU
// [7*pi/8, 9*pi/8) L
// [9*pi/8, 11*pi/8) LD
// [11*pi/8, 13*pi/8) D
// [13*pi/8, 15*pi/8) RD
// [15*pi/8, 0] R

int GameJoyStick::getDirection(float r)
{
	if (r >= 0 && r < M_PI / 8) {
		return R_DIR;
	}
	else if (r >= M_PI * 1 / 8 && r < M_PI * 3 / 8) {
		return RU_DIR;
	}
	else if (r >= M_PI * 3 / 8 && r < M_PI * 5 / 8) {
		return U_DIR;
	}
	else if (r >= M_PI * 5 / 8 && r < M_PI * 7 / 8) {
		return LU_DIR;
	}
	else if (r >= M_PI * 7 / 8 && r < M_PI * 9 / 8) {
		return L_DIR;
	}
	else if (r >= M_PI * 9 / 8 && r < M_PI * 11 / 8) {
		return LD_DIR;
	}
	else if (r >= M_PI * 11 / 8 && r < M_PI * 13 / 8) {
		return D_DIR;
	}
	else if (r >= M_PI * 13 / 8 && r < M_PI * 15 / 8) {
		return RD_DIR;
	}
	else if (r >= M_PI * 15 / 8 && r <= M_PI * 2) {
		return R_DIR;
	}
	return INVALID_DIR;
}

void GameJoyStick::onCaptureEventHandler(int type, Touch* touch, Event* e)
{
	switch (type) {
	case T_MOVED:
	{
		Vec2 pos = this->convertTouchToNodeSpace(touch);
		float len = pos.length(); // ´óÈý½ÇÐÐµÄÐ±±ß
		if (len <= this->minRadis) {
			EVENT_DISPATCHER->dispatchCustomEvent(JOY_STICK_EVENT, (void*)INVALID_DIR);
			return ;
		}

		if (len > maxRadis) {
			// x1 / pos.x = maxRadis / len  x1 = maxRadis * pos.x / len
			pos.x = pos.x * maxRadis / len;
			pos.y = pos.y * maxRadis / len;
		}
		this->beadsSprite->setPosition(pos);
		float r = getRadianByVec(pos);
		int dir = this->getDirection(r);
		EVENT_DISPATCHER->dispatchCustomEvent(JOY_STICK_EVENT, (void*)dir);
	}
	break;
	case T_ENDED:
	case T_CANCELD:
	{
		this->beadsSprite->setPosition(0, 0);
		EVENT_DISPATCHER->dispatchCustomEvent(JOY_STICK_EVENT, (void*)INVALID_DIR);
	}
	break;
	}
}

bool GameJoyStick::initWithFile(const char*bkName,
	const char* beads, float maxRadis, float minRadis)
{
	if (this->Node::init() == false) {
		return false;
	}
	
	Sprite* bk = Sprite::create(bkName);
	if (bk == NULL) {
		return false;
	}

	this->addChild(bk);

	TouchSprite* beadsSprite = TouchSprite::create(beads);
	if (beadsSprite == NULL) {
		return false;
	}
	this->addChild(beadsSprite);
	beadsSprite->addCaptureEventListener(CALL_CAPTURE_FUNC_SELECTOR(GameJoyStick::onCaptureEventHandler), this);
	this->beadsSprite = beadsSprite;

	this->maxRadis = maxRadis;
	this->minRadis = minRadis;
	return true;
}

bool GameJoyStick::initWithSpriteFrameName(const char*bkName,
	const char* beads, float maxRadis, float minRadis)
{
	if (this->Node::init() == false) {
		return false;
	}

	Sprite* bk = Sprite::createWithSpriteFrameName(bkName);
	if (bk == NULL) {
		return false;
	}

	this->addChild(bk);

	TouchSprite* beadsSprite = TouchSprite::createWithSpriteFrameName(beads);
	if (beadsSprite == NULL) {
		return false;
	}
	
	this->addChild(beadsSprite);
	beadsSprite->addCaptureEventListener(CALL_CAPTURE_FUNC_SELECTOR(GameJoyStick::onCaptureEventHandler), this);
	this->beadsSprite = beadsSprite;
	this->maxRadis = maxRadis;
	this->minRadis = minRadis;

	return true;
}

GameJoyStick* GameJoyStick::create(const char* bkName,
	const char* beads, float maxRadis, float minRadis)
{
	GameJoyStick* ret = new GameJoyStick();
	if (ret->initWithFile(bkName, beads, maxRadis, minRadis)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);

	return NULL;
}

GameJoyStick* GameJoyStick::createWithSpriteFrameName(const char* bkName,
	const char* beads, float maxRadis, float minRadis)
{
	GameJoyStick* ret = new GameJoyStick();
	if (ret->initWithSpriteFrameName(bkName, beads, maxRadis, minRadis)) {
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);

	return NULL;
	return NULL;
}