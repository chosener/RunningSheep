/****************************************************************************
Copyright (c) 2008-2009 Jason Booth
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies Inc.

 http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

/*
 * Elastic, Back and Bounce actions based on code from:
 * http://github.com/NikhilK/silverlightfx/
 *
 * by http://github.com/NikhilK
 */

#include "2d/CCActionEase.h"
#include "2d/CCTweenFunction.h"

NS_CC_BEGIN

#ifndef M_PI_X_2
#define M_PI_X_2 (float)M_PI * 2.0f
#endif

//
// EaseAction
//

bool ActionEase::initWithAction(ActionInterval *action)
{
    CCASSERT(action != nullptr, "");

    if (ActionInterval::initWithDuration(action->getDuration()))
    {
        _inner = action;
        action->retain();

        return true;
    }

    return false;
}

ActionEase::~ActionEase(void)
{
    CC_SAFE_RELEASE(_inner);
}

void ActionEase::startWithTarget(Node *target)
{
    ActionInterval::startWithTarget(target);
    _inner->startWithTarget(_target);
}

void ActionEase::stop(void)
{
    _inner->stop();
    ActionInterval::stop();
}

void ActionEase::update(float time)
{
    _inner->update(time);
}

ActionInterval* ActionEase::getInnerAction()
{
    return _inner;
}

//
// EaseRateAction
//

bool EaseRateAction::initWithAction(ActionInterval *action, float rate)
{
    if (ActionEase::initWithAction(action))
    {
        _rate = rate;
        return true;
    }

    return false;
}

EaseRateAction::~EaseRateAction()
{
}

//
// EeseIn
//

EaseIn* EaseIn::create(ActionInterval *action, float rate)
{
<<<<<<< HEAD
    EaseIn *easeIn = new (std::nothrow) EaseIn();
=======
    EaseIn *easeIn = new EaseIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (easeIn)
    {
        if (easeIn->initWithAction(action, rate))
        {
            easeIn->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(easeIn);
        }
    }

    return easeIn;
}

EaseIn* EaseIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseIn();
    a->initWithAction(_inner->clone(), _rate);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseIn();
	a->initWithAction(_inner->clone(), _rate);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseIn::update(float time)
{
    _inner->update(tweenfunc::easeIn(time, _rate));
}

EaseIn* EaseIn::reverse() const
{
    return EaseIn::create(_inner->reverse(), 1 / _rate);
}

//
// EaseOut
//
EaseOut* EaseOut::create(ActionInterval *action, float rate)
{
<<<<<<< HEAD
    EaseOut *easeOut = new (std::nothrow) EaseOut();
=======
    EaseOut *easeOut = new EaseOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (easeOut)
    {
        if (easeOut->initWithAction(action, rate))
        {
            easeOut->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(easeOut);
        }
    }

    return easeOut;
}

EaseOut* EaseOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseOut();
    a->initWithAction(_inner->clone(), _rate);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseOut();
	a->initWithAction(_inner->clone(), _rate);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseOut::update(float time)
{
    _inner->update(tweenfunc::easeOut(time, _rate));
}

EaseOut* EaseOut::reverse() const
{
    return EaseOut::create(_inner->reverse(), 1 / _rate);
}

//
// EaseInOut
//
EaseInOut* EaseInOut::create(ActionInterval *action, float rate)
{
<<<<<<< HEAD
    EaseInOut *easeInOut = new (std::nothrow) EaseInOut();
=======
    EaseInOut *easeInOut = new EaseInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (easeInOut)
    {
        if (easeInOut->initWithAction(action, rate))
        {
            easeInOut->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(easeInOut);
        }
    }

    return easeInOut;
}

EaseInOut* EaseInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseInOut();
    a->initWithAction(_inner->clone(), _rate);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseInOut();
	a->initWithAction(_inner->clone(), _rate);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseInOut::update(float time)
{
    _inner->update(tweenfunc::easeInOut(time, _rate));
}

// InOut and OutIn are symmetrical
EaseInOut* EaseInOut::reverse() const
{
    return EaseInOut::create(_inner->reverse(), _rate);
}

//
// EaseExponentialIn
//
EaseExponentialIn* EaseExponentialIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseExponentialIn *ret = new (std::nothrow) EaseExponentialIn();
=======
    EaseExponentialIn *ret = new EaseExponentialIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseExponentialIn* EaseExponentialIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseExponentialIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseExponentialIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseExponentialIn::update(float time)
{
    _inner->update(tweenfunc::expoEaseIn(time));
}

ActionEase * EaseExponentialIn::reverse() const
{
    return EaseExponentialOut::create(_inner->reverse());
}

//
// EaseExponentialOut
//
EaseExponentialOut* EaseExponentialOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseExponentialOut *ret = new (std::nothrow) EaseExponentialOut();
=======
    EaseExponentialOut *ret = new EaseExponentialOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseExponentialOut* EaseExponentialOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseExponentialOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseExponentialOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseExponentialOut::update(float time)
{
    _inner->update(tweenfunc::expoEaseOut(time));
}

ActionEase* EaseExponentialOut::reverse() const
{
    return EaseExponentialIn::create(_inner->reverse());
}

//
// EaseExponentialInOut
//

EaseExponentialInOut* EaseExponentialInOut::create(ActionInterval *action)
{
<<<<<<< HEAD
    EaseExponentialInOut *ret = new (std::nothrow) EaseExponentialInOut();
=======
    EaseExponentialInOut *ret = new EaseExponentialInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseExponentialInOut* EaseExponentialInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseExponentialInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseExponentialInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseExponentialInOut::update(float time)
{
    _inner->update(tweenfunc::expoEaseInOut(time));
}

EaseExponentialInOut* EaseExponentialInOut::reverse() const
{
    return EaseExponentialInOut::create(_inner->reverse());
}

//
// EaseSineIn
//

EaseSineIn* EaseSineIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseSineIn *ret = new (std::nothrow) EaseSineIn();
=======
    EaseSineIn *ret = new EaseSineIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseSineIn* EaseSineIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseSineIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseSineIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseSineIn::update(float time)
{
    _inner->update(tweenfunc::sineEaseIn(time));
}

ActionEase* EaseSineIn::reverse() const
{
    return EaseSineOut::create(_inner->reverse());
}

//
// EaseSineOut
//

EaseSineOut* EaseSineOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseSineOut *ret = new (std::nothrow) EaseSineOut();
=======
    EaseSineOut *ret = new EaseSineOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseSineOut* EaseSineOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseSineOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseSineOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseSineOut::update(float time)
{
    _inner->update(tweenfunc::sineEaseOut(time));
}

ActionEase* EaseSineOut::reverse(void) const
{
    return EaseSineIn::create(_inner->reverse());
}

//
// EaseSineInOut
//

EaseSineInOut* EaseSineInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseSineInOut *ret = new (std::nothrow) EaseSineInOut();
=======
    EaseSineInOut *ret = new EaseSineInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseSineInOut* EaseSineInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseSineInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseSineInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseSineInOut::update(float time)
{
    _inner->update(tweenfunc::sineEaseInOut(time));
}

EaseSineInOut* EaseSineInOut::reverse() const
{
    return EaseSineInOut::create(_inner->reverse());
}

//
// EaseElastic
//

bool EaseElastic::initWithAction(ActionInterval *action, float period/* = 0.3f*/)
{
    if (ActionEase::initWithAction(action))
    {
        _period = period;
        return true;
    }

    return false;
}

//
// EaseElasticIn
//

EaseElasticIn* EaseElasticIn::create(ActionInterval *action)
{
    return EaseElasticIn::create(action, 0.3f);
}

EaseElasticIn* EaseElasticIn::create(ActionInterval *action, float period/* = 0.3f*/)
{
<<<<<<< HEAD
    EaseElasticIn *ret = new (std::nothrow) EaseElasticIn();
=======
    EaseElasticIn *ret = new EaseElasticIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action, period))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseElasticIn* EaseElasticIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseElasticIn();
    a->initWithAction(_inner->clone(), _period);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseElasticIn();
	a->initWithAction(_inner->clone(), _period);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseElasticIn::update(float time)
{
    _inner->update(tweenfunc::elasticEaseIn(time, _period));
}

EaseElastic* EaseElasticIn::reverse() const
{
    return EaseElasticOut::create(_inner->reverse(), _period);
}

//
// EaseElasticOut
//

EaseElasticOut* EaseElasticOut::create(ActionInterval *action)
{
    return EaseElasticOut::create(action, 0.3f);
}

EaseElasticOut* EaseElasticOut::create(ActionInterval *action, float period/* = 0.3f*/)
{
<<<<<<< HEAD
    EaseElasticOut *ret = new (std::nothrow) EaseElasticOut();
=======
    EaseElasticOut *ret = new EaseElasticOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action, period))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseElasticOut* EaseElasticOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseElasticOut();
    a->initWithAction(_inner->clone(), _period);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseElasticOut();
	a->initWithAction(_inner->clone(), _period);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseElasticOut::update(float time)
{
    _inner->update(tweenfunc::elasticEaseOut(time, _period));
}

EaseElastic* EaseElasticOut::reverse() const
{
    return EaseElasticIn::create(_inner->reverse(), _period);
}

//
// EaseElasticInOut
//

EaseElasticInOut* EaseElasticInOut::create(ActionInterval *action)
{
    return EaseElasticInOut::create(action, 0.3f);
}

EaseElasticInOut* EaseElasticInOut::create(ActionInterval *action, float period/* = 0.3f*/)
{
<<<<<<< HEAD
    EaseElasticInOut *ret = new (std::nothrow) EaseElasticInOut();
=======
    EaseElasticInOut *ret = new EaseElasticInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action, period))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseElasticInOut* EaseElasticInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseElasticInOut();
    a->initWithAction(_inner->clone(), _period);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseElasticInOut();
	a->initWithAction(_inner->clone(), _period);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseElasticInOut::update(float time)
{
    _inner->update(tweenfunc::elasticEaseInOut(time, _period));
}

EaseElasticInOut* EaseElasticInOut::reverse() const
{
    return EaseElasticInOut::create(_inner->reverse(), _period);
}

//
// EaseBounce
//

//
// EaseBounceIn
//

EaseBounceIn* EaseBounceIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseBounceIn *ret = new (std::nothrow) EaseBounceIn();
=======
    EaseBounceIn *ret = new EaseBounceIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBounceIn* EaseBounceIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseBounceIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseBounceIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseBounceIn::update(float time)
{
    _inner->update(tweenfunc::bounceEaseIn(time));
}

EaseBounce* EaseBounceIn::reverse() const
{
    return EaseBounceOut::create(_inner->reverse());
}

//
// EaseBounceOut
//

EaseBounceOut* EaseBounceOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseBounceOut *ret = new (std::nothrow) EaseBounceOut();
=======
    EaseBounceOut *ret = new EaseBounceOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBounceOut* EaseBounceOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseBounceOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseBounceOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseBounceOut::update(float time)
{
    _inner->update(tweenfunc::bounceEaseOut(time));
}

EaseBounce* EaseBounceOut::reverse() const
{
    return EaseBounceIn::create(_inner->reverse());
}

//
// EaseBounceInOut
//

EaseBounceInOut* EaseBounceInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseBounceInOut *ret = new (std::nothrow) EaseBounceInOut();
=======
    EaseBounceInOut *ret = new EaseBounceInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBounceInOut* EaseBounceInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseBounceInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseBounceInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseBounceInOut::update(float time)
{
    _inner->update(tweenfunc::bounceEaseInOut(time));
}

EaseBounceInOut* EaseBounceInOut::reverse() const
{
    return EaseBounceInOut::create(_inner->reverse());
}

//
// EaseBackIn
//

EaseBackIn* EaseBackIn::create(ActionInterval *action)
{
<<<<<<< HEAD
    EaseBackIn *ret = new (std::nothrow) EaseBackIn();
=======
    EaseBackIn *ret = new EaseBackIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBackIn* EaseBackIn::clone() const
{
	// no copy constructor	
<<<<<<< HEAD
	auto a = new (std::nothrow) EaseBackIn();
=======
	auto a = new EaseBackIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
}

void EaseBackIn::update(float time)
{
    _inner->update(tweenfunc::backEaseIn(time));
}

ActionEase* EaseBackIn::reverse() const
{
    return EaseBackOut::create(_inner->reverse());
}

//
// EaseBackOut
//

EaseBackOut* EaseBackOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseBackOut *ret = new (std::nothrow) EaseBackOut();
=======
    EaseBackOut *ret = new EaseBackOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBackOut* EaseBackOut::clone() const
{
	// no copy constructor	
<<<<<<< HEAD
	auto a = new (std::nothrow) EaseBackOut();
=======
	auto a = new EaseBackOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
}

void EaseBackOut::update(float time)
{
    _inner->update(tweenfunc::backEaseOut(time));
}

ActionEase* EaseBackOut::reverse() const
{
    return EaseBackIn::create(_inner->reverse());
}

//
// EaseBackInOut
//

EaseBackInOut* EaseBackInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseBackInOut *ret = new (std::nothrow) EaseBackInOut();
=======
    EaseBackInOut *ret = new EaseBackInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
}

EaseBackInOut* EaseBackInOut::clone() const
{
	// no copy constructor
<<<<<<< HEAD
	auto a = new (std::nothrow) EaseBackInOut();
=======
	auto a = new EaseBackInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
}

void EaseBackInOut::update(float time)
{
    _inner->update(tweenfunc::backEaseInOut(time));
}

EaseBackInOut* EaseBackInOut::reverse() const
{
    return EaseBackInOut::create(_inner->reverse());
}




EaseBezierAction* EaseBezierAction::create(cocos2d::ActionInterval* action)
{
<<<<<<< HEAD
	EaseBezierAction *ret = new (std::nothrow) EaseBezierAction();
=======
	EaseBezierAction *ret = new EaseBezierAction();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	if (ret)
	{  
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
}

void EaseBezierAction::setBezierParamer( float p0, float p1, float p2, float p3)
{
<<<<<<< HEAD
    _p0 = p0;
    _p1 = p1;
    _p2 = p2;
    _p3 = p3;
=======
	_p0 = p0;
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseBezierAction* EaseBezierAction::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseBezierAction();
    a->initWithAction(_inner->clone());
    a->setBezierParamer(_p0,_p1,_p2,_p3);
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseBezierAction();
	a->initWithAction(_inner->clone());
	a->setBezierParamer(_p0,_p1,_p2,_p3);
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseBezierAction::update(float time)
{
	_inner->update(tweenfunc::bezieratFunction(_p0,_p1,_p2,_p3,time));
}

EaseBezierAction* EaseBezierAction::reverse() const
{
<<<<<<< HEAD
    EaseBezierAction* reverseAction = EaseBezierAction::create(_inner->reverse());
    reverseAction->setBezierParamer(_p3,_p2,_p1,_p0);
    return reverseAction;
=======
	EaseBezierAction* reverseAction = EaseBezierAction::create(_inner->reverse());
	reverseAction->setBezierParamer(_p3,_p2,_p1,_p0);
	return reverseAction;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuadraticActionIn
//

EaseQuadraticActionIn* EaseQuadraticActionIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuadraticActionIn *ret = new (std::nothrow) EaseQuadraticActionIn();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuadraticActionIn *ret = new EaseQuadraticActionIn();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuadraticActionIn* EaseQuadraticActionIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuadraticActionIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuadraticActionIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuadraticActionIn::update(float time)
{
	_inner->update(tweenfunc::quadraticIn(time));
}

EaseQuadraticActionIn* EaseQuadraticActionIn::reverse() const
{
<<<<<<< HEAD
    return EaseQuadraticActionIn::create(_inner->reverse());
=======
	return EaseQuadraticActionIn::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuadraticActionOut
//

EaseQuadraticActionOut* EaseQuadraticActionOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuadraticActionOut *ret = new (std::nothrow) EaseQuadraticActionOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuadraticActionOut *ret = new EaseQuadraticActionOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuadraticActionOut* EaseQuadraticActionOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuadraticActionOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuadraticActionOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuadraticActionOut::update(float time)
{	
<<<<<<< HEAD
    _inner->update(tweenfunc::quadraticOut(time));
=======
	_inner->update(tweenfunc::quadraticOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuadraticActionOut* EaseQuadraticActionOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuadraticActionOut::create(_inner->reverse());
=======
	return EaseQuadraticActionOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuadraticActionInOut
//

EaseQuadraticActionInOut* EaseQuadraticActionInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuadraticActionInOut *ret = new (std::nothrow) EaseQuadraticActionInOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuadraticActionInOut *ret = new EaseQuadraticActionInOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuadraticActionInOut* EaseQuadraticActionInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuadraticActionInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuadraticActionInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuadraticActionInOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quadraticInOut(time));
=======
	_inner->update(tweenfunc::quadraticInOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuadraticActionInOut* EaseQuadraticActionInOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuadraticActionInOut::create(_inner->reverse());
=======
	return EaseQuadraticActionInOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuarticActionIn
//

EaseQuarticActionIn* EaseQuarticActionIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuarticActionIn *ret = new (std::nothrow) EaseQuarticActionIn();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
    	}
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuarticActionIn *ret = new EaseQuarticActionIn();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuarticActionIn* EaseQuarticActionIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuarticActionIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuarticActionIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuarticActionIn::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quartEaseIn(time));
=======
	_inner->update(tweenfunc::quartEaseIn(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuarticActionIn* EaseQuarticActionIn::reverse() const
{
<<<<<<< HEAD
    return EaseQuarticActionIn::create(_inner->reverse());
=======
	return EaseQuarticActionIn::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuarticActionOut
//

EaseQuarticActionOut* EaseQuarticActionOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuarticActionOut *ret = new (std::nothrow) EaseQuarticActionOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
    	}
    }

    return ret;
=======
	EaseQuarticActionOut *ret = new EaseQuarticActionOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuarticActionOut* EaseQuarticActionOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuarticActionOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuarticActionOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuarticActionOut::update(float time)
{
    _inner->update(tweenfunc::quartEaseOut(time));
}

EaseQuarticActionOut* EaseQuarticActionOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuarticActionOut::create(_inner->reverse());
=======
	return EaseQuarticActionOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuarticActionInOut
//

EaseQuarticActionInOut* EaseQuarticActionInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuarticActionInOut *ret = new (std::nothrow) EaseQuarticActionInOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuarticActionInOut *ret = new EaseQuarticActionInOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuarticActionInOut* EaseQuarticActionInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuarticActionInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuarticActionInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuarticActionInOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quartEaseInOut(time));
=======
	_inner->update(tweenfunc::quartEaseInOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuarticActionInOut* EaseQuarticActionInOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuarticActionInOut::create(_inner->reverse());
=======
	return EaseQuarticActionInOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuinticActionIn
//

EaseQuinticActionIn* EaseQuinticActionIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuinticActionIn *ret = new (std::nothrow) EaseQuinticActionIn();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuinticActionIn *ret = new EaseQuinticActionIn();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionIn* EaseQuinticActionIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuinticActionIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuinticActionIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuinticActionIn::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quintEaseIn(time));
=======
	_inner->update(tweenfunc::quintEaseIn(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionIn* EaseQuinticActionIn::reverse() const
{
<<<<<<< HEAD
    return EaseQuinticActionIn::create(_inner->reverse());
=======
	return EaseQuinticActionIn::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuinticActionOut
//

EaseQuinticActionOut* EaseQuinticActionOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuinticActionOut *ret = new (std::nothrow) EaseQuinticActionOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuinticActionOut *ret = new EaseQuinticActionOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionOut* EaseQuinticActionOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuinticActionOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuinticActionOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuinticActionOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quintEaseOut(time));
=======
	_inner->update(tweenfunc::quintEaseOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionOut* EaseQuinticActionOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuinticActionOut::create(_inner->reverse());
=======
	return EaseQuinticActionOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseQuinticActionInOut
//

EaseQuinticActionInOut* EaseQuinticActionInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseQuinticActionInOut *ret = new (std::nothrow) EaseQuinticActionInOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseQuinticActionInOut *ret = new EaseQuinticActionInOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionInOut* EaseQuinticActionInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseQuinticActionInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseQuinticActionInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseQuinticActionInOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::quintEaseInOut(time));
=======
	_inner->update(tweenfunc::quintEaseInOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseQuinticActionInOut* EaseQuinticActionInOut::reverse() const
{
<<<<<<< HEAD
    return EaseQuinticActionInOut::create(_inner->reverse());
=======
	return EaseQuinticActionInOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCircleActionIn
//

EaseCircleActionIn* EaseCircleActionIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseCircleActionIn *ret = new (std::nothrow) EaseCircleActionIn();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret; 
=======
	EaseCircleActionIn *ret = new EaseCircleActionIn();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCircleActionIn* EaseCircleActionIn::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseCircleActionIn();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseCircleActionIn();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseCircleActionIn::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::circEaseIn(time));
=======
	_inner->update(tweenfunc::circEaseIn(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCircleActionIn* EaseCircleActionIn::reverse() const
{
<<<<<<< HEAD
    return EaseCircleActionIn::create(_inner->reverse());
=======
	return EaseCircleActionIn::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCircleActionOut
//

EaseCircleActionOut* EaseCircleActionOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseCircleActionOut *ret = new (std::nothrow) EaseCircleActionOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

	return ret;
=======
	EaseCircleActionOut *ret = new EaseCircleActionOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCircleActionOut* EaseCircleActionOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseCircleActionOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseCircleActionOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseCircleActionOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::circEaseOut(time));
=======
	_inner->update(tweenfunc::circEaseOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCircleActionOut* EaseCircleActionOut::reverse() const
{
<<<<<<< HEAD
    return EaseCircleActionOut::create(_inner->reverse());
=======
	return EaseCircleActionOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCircleActionInOut
//

EaseCircleActionInOut* EaseCircleActionInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
	EaseCircleActionInOut *ret = new (std::nothrow) EaseCircleActionInOut();
=======
	EaseCircleActionInOut *ret = new EaseCircleActionInOut();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
}

EaseCircleActionInOut* EaseCircleActionInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseCircleActionInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseCircleActionInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseCircleActionInOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::circEaseInOut(time));
=======
	_inner->update(tweenfunc::circEaseInOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCircleActionInOut* EaseCircleActionInOut::reverse() const
{
<<<<<<< HEAD
    return EaseCircleActionInOut::create(_inner->reverse());
=======
	return EaseCircleActionInOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCubicActionIn
//

EaseCubicActionIn* EaseCubicActionIn::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseCubicActionIn *ret = new (std::nothrow) EaseCubicActionIn();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseCubicActionIn *ret = new EaseCubicActionIn();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionIn* EaseCubicActionIn::clone() const
{
	// no copy constructor
<<<<<<< HEAD
	auto a = new (std::nothrow) EaseCubicActionIn();
=======
	auto a = new EaseCubicActionIn();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
}

void EaseCubicActionIn::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::cubicEaseIn(time));
=======
	_inner->update(tweenfunc::cubicEaseIn(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionIn* EaseCubicActionIn::reverse() const
{
<<<<<<< HEAD
    return EaseCubicActionIn::create(_inner->reverse());
=======
	return EaseCubicActionIn::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCubicActionOut
//

EaseCubicActionOut* EaseCubicActionOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseCubicActionOut *ret = new (std::nothrow) EaseCubicActionOut();
    if (ret)
    {
        if (ret->initWithAction(action))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_RELEASE_NULL(ret);
        }
    }

    return ret;
=======
	EaseCubicActionOut *ret = new EaseCubicActionOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionOut* EaseCubicActionOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseCubicActionOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseCubicActionOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseCubicActionOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::cubicEaseOut(time));
=======
	_inner->update(tweenfunc::cubicEaseOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionOut* EaseCubicActionOut::reverse() const
{
<<<<<<< HEAD
    return EaseCubicActionOut::create(_inner->reverse());
=======
	return EaseCubicActionOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
// EaseCubicActionInOut
//

EaseCubicActionInOut* EaseCubicActionInOut::create(ActionInterval* action)
{
<<<<<<< HEAD
    EaseCubicActionInOut *ret = new (std::nothrow) EaseCubicActionInOut();
    if (ret)
    {
    	if (ret->initWithAction(action))
    	{
    		ret->autorelease();
    	}
    	else
    	{
    		CC_SAFE_RELEASE_NULL(ret);
    	}
    }

    return ret;
=======
	EaseCubicActionInOut *ret = new EaseCubicActionInOut();
	if (ret)
	{
		if (ret->initWithAction(action))
		{
			ret->autorelease();
		}
		else
		{
			CC_SAFE_RELEASE_NULL(ret);
		}
	}

	return ret; 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionInOut* EaseCubicActionInOut::clone() const
{
<<<<<<< HEAD
    // no copy constructor
    auto a = new (std::nothrow) EaseCubicActionInOut();
    a->initWithAction(_inner->clone());
    a->autorelease();
    return a;
=======
	// no copy constructor
	auto a = new EaseCubicActionInOut();
	a->initWithAction(_inner->clone());
	a->autorelease();
	return a;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void EaseCubicActionInOut::update(float time)
{
<<<<<<< HEAD
    _inner->update(tweenfunc::cubicEaseInOut(time));
=======
	_inner->update(tweenfunc::cubicEaseInOut(time));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

EaseCubicActionInOut* EaseCubicActionInOut::reverse() const
{
<<<<<<< HEAD
    return EaseCubicActionInOut::create(_inner->reverse());
=======
	return EaseCubicActionInOut::create(_inner->reverse());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

NS_CC_END
