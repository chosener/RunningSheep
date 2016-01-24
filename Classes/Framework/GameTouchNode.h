#ifndef __GAME_TOUCHE_NODE_H__
#define __GAME_TOUCHE_NODE_H__

#include "CocosHead.h"

typedef void (Ref::*PressEvent_CallFunc)(Node* sender, Touch* touch, Event* e);
#define CALL_PRESS_FUNC_SELECTOR(_SELECTOR) static_cast<PressEvent_CallFunc>(&_SELECTOR)

enum {
	T_INVALID,
	T_BEGAN,
	T_MOVED,
	T_CANCELD,
	T_ENDED,
};
typedef void (Ref::*CaptureEvent_CallFunc)(int type, Touch* touch, Event* e);
#define CALL_CAPTURE_FUNC_SELECTOR(_SELECTOR) static_cast<CaptureEvent_CallFunc>(&_SELECTOR)

class GameTouchNode : public Node {
public:
	GameTouchNode();
	~GameTouchNode();

public:
	virtual bool onTouchBegin(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchCancelled(Touch* touch, Event* event);

public:
	virtual void onEnter();
	virtual void onExit();
	virtual bool init();

private:
	PressEvent_CallFunc _function;
	Ref* target;

	CaptureEvent_CallFunc _captureFunc;
	Ref* captureTarget;


	bool m_touchEnable;

public:
	bool isContainTouchPoint(Touch* touch);
	bool isContainTouchPoint(Vec2& worldPos);
	
	void addTouchEventListener(PressEvent_CallFunc func, Ref* target);
	void addCaptureEventListener(CaptureEvent_CallFunc func, Ref* target);

	void setToucheEnable(bool enable) { this->m_touchEnable = enable; };
	bool getTouchEnable() { return this->m_touchEnable; };

public:
	CREATE_FUNC(GameTouchNode);
};

#endif

