#include "common.h"
#include "GameTouchNode.h"

using namespace cocos2d::ui;
//#include "ui/UIScale9Sprite.h"


GameTouchNode::GameTouchNode()
{
	this->target = NULL;
	this->_function = NULL;
	this->captureTarget = NULL;
	this->_captureFunc = NULL;
}

GameTouchNode::~GameTouchNode()
{
	CC_SAFE_RELEASE(this->target);
	CC_SAFE_RELEASE(this->captureTarget);
}

void GameTouchNode::addTouchEventListener(PressEvent_CallFunc func, Ref* target)
{
	CC_SAFE_RELEASE(this->target);
	this->_function = func;
	this->target = target;
	CC_SAFE_RETAIN(this->target);
}

void GameTouchNode::addCaptureEventListener(CaptureEvent_CallFunc func, Ref* target)
{
	CC_SAFE_RELEASE(this->captureTarget);
	this->_captureFunc = func;
	this->captureTarget = target;
	CC_SAFE_RETAIN(this->captureTarget);
}

// static bool containtPoint(Touch* touch, Node* root)
static bool containtPoint(Vec2 w_pos, Node* root)
{
	Rect r = root->getBoundingBox();
	r.containsPoint(w_pos);

	Vec2 pos = root->getParent()->convertToNodeSpace(w_pos);
	if (r.containsPoint(pos)) {
		return true;
	}
	
	//遍历所有的孩子
	Vector<Node*> children = root->getChildren();
	for (int i = 0; i < children.size(); i++) {
		Node* elem = children.at(i);
		if (elem->isVisible() == false) {
			continue;
		}

		if (containtPoint(w_pos, elem) == true) {
			return true;
		}
	}
	// 如果所有的没有找到 
	return false;
}

bool GameTouchNode::isContainTouchPoint(Vec2& worldPos)
{
	return containtPoint(worldPos, this);
}

bool GameTouchNode::isContainTouchPoint(Touch* touch)
{
	return containtPoint(touch->getLocation(), this);
}

bool GameTouchNode::onTouchBegin(Touch* touch, Event* event)
{
	if (this->m_touchEnable == false) {
		return false;
	}

	if (containtPoint(touch->getLocation(), this) == false) {
		return false;
	}

	if (this->captureTarget && this->_captureFunc) {
		(captureTarget->*_captureFunc)(T_BEGAN, touch, event);
	}
	return true;
}

void GameTouchNode::onTouchEnded(Touch* touch, Event* event)
{
	if (containtPoint(touch->getLocation(), this) == true &&
	    this->_function && this->target) {
		(target->*_function)(this, touch, event);
	}

	if (this->captureTarget && this->_captureFunc) {
		(captureTarget->*_captureFunc)(T_ENDED, touch, event);
	}
}

void GameTouchNode::onTouchMoved(Touch* touch, Event* event)
{
	if (this->captureTarget && this->_captureFunc) {
		(captureTarget->*_captureFunc)(T_MOVED, touch, event);
	}
}

void GameTouchNode::onTouchCancelled(Touch* touch, Event* event)
{
	if (this->captureTarget && this->_captureFunc) {
		(captureTarget->*_captureFunc)(T_CANCELD, touch, event);
	}
}

bool GameTouchNode::init()
{
	if (this->Node::init() == false) {
		return false;
	}
	this->setCascadeOpacityEnabled(true);
    
    this->setToucheEnable(true);
    
	return true;
}

void GameTouchNode::onEnter()
{
	this->Node::onEnter();
	// 注册touch事件
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameTouchNode::onTouchBegin, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameTouchNode::onTouchEnded, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameTouchNode::onTouchMoved, this);
	listener->onTouchCancelled = CC_CALLBACK_2(GameTouchNode::onTouchCancelled, this);

	// 监听我们的事件
	EVENT_DISPATCHER->addEventListenerWithSceneGraphPriority(listener, this);
	//

}

void GameTouchNode::onExit()
{
	// 注销touch事件
	EVENT_DISPATCHER->removeEventListenersForTarget(this);
	// end

	this->Node::onExit();
}