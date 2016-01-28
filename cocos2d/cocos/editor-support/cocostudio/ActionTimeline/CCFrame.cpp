/****************************************************************************
Copyright (c) 2013 cocos2d-x.org

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

#include "CCFrame.h"
#include "CCTimeLine.h"
#include "CCActionTimeline.h"
<<<<<<< HEAD
#include "2d/CCSpriteFrameCache.h"
#include "2d/CCSpriteFrame.h"
#include <exception>
#include <iostream>
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

USING_NS_CC;

NS_TIMELINE_BEGIN

// Frame
Frame::Frame()
    : _frameIndex(0)
    , _tween(true)
<<<<<<< HEAD
    , _tweenType(tweenfunc::TweenType::Linear)
    , _enterWhenPassed(false)
    , _timeline(nullptr)
    , _node(nullptr)
{
    _easingParam.clear();
=======
    , _timeline(nullptr)
    , _node(nullptr)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Frame::~Frame()
{
<<<<<<< HEAD
    _easingParam.clear();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Frame::emitEvent()
{
    if (_timeline)
    {
        _timeline->getActionTimeline()->emitFrameEvent(this);
    }
}

void Frame::cloneProperty(Frame* frame)
{
    _frameIndex = frame->getFrameIndex();
    _tween = frame->isTween();
<<<<<<< HEAD
    
    _tweenType = frame->getTweenType();
    setEasingParams(frame->getEasingParams());
}

void Frame::apply(float percent)
{
    if (!_tween)
        return;
    
    float tweenpercent = percent;
    if ( _tweenType != tweenfunc::TWEEN_EASING_MAX && _tweenType != tweenfunc::Linear)
    {
        tweenpercent = tweenPercent(tweenpercent);
    }
    onApply(tweenpercent);
}

float Frame::tweenPercent(float percent)
{
    return tweenfunc::tweenTo(percent, _tweenType, _easingParam.data());
}

void Frame::setEasingParams(const std::vector<float>& easingParams)
{
    _easingParam.assign(easingParams.begin(), easingParams.end());
}

const std::vector<float>& Frame::getEasingParams() const
{
    return _easingParam;
}
=======
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

// VisibleFrame
VisibleFrame* VisibleFrame::create()
{
<<<<<<< HEAD
    VisibleFrame* frame = new (std::nothrow) VisibleFrame();
=======
    VisibleFrame* frame = new VisibleFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

VisibleFrame::VisibleFrame()
    : _visible(true)
{
}

<<<<<<< HEAD
void VisibleFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node)
    {
        _node->setVisible(_visible);
    }
=======
void VisibleFrame::onEnter(Frame *nextFrame)
{
    _node->setVisible(_visible);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}


Frame* VisibleFrame::clone()
{
    VisibleFrame* frame = VisibleFrame::create();
    frame->setVisible(_visible);

    frame->cloneProperty(this);

    return frame;
}



// TextureFrame
TextureFrame* TextureFrame::create()
{
<<<<<<< HEAD
    TextureFrame* frame = new (std::nothrow) TextureFrame();
=======
    TextureFrame* frame = new TextureFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

TextureFrame::TextureFrame()
    : _textureName("")
{
}

void TextureFrame::setNode(Node* node)
{
    Frame::setNode(node);

    _sprite = dynamic_cast<Sprite*>(node);
}

<<<<<<< HEAD
void TextureFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if(_sprite)
    {
        auto spriteBlendFunc = _sprite->getBlendFunc();
=======
void TextureFrame::onEnter(Frame *nextFrame)
{
    if(_sprite)
    {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        SpriteFrame* spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(_textureName);

        if(spriteFrame != nullptr)
            _sprite->setSpriteFrame(spriteFrame);
        else
            _sprite->setTexture(_textureName);
<<<<<<< HEAD
        
        if(_sprite->getBlendFunc() != spriteBlendFunc)
            _sprite->setBlendFunc(spriteBlendFunc);
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
}


Frame* TextureFrame::clone()
{
    TextureFrame* frame = TextureFrame::create();
    frame->setTextureName(_textureName);

    frame->cloneProperty(this);

    return frame;
}



// RotationFrame
RotationFrame* RotationFrame::create()
{
<<<<<<< HEAD
    RotationFrame* frame = new (std::nothrow) RotationFrame();
=======
    RotationFrame* frame = new RotationFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

RotationFrame::RotationFrame()
    : _rotation(0)
{
}

<<<<<<< HEAD
void RotationFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
        return;
    }
	
    _node->setRotation(_rotation);

=======
void RotationFrame::onEnter(Frame *nextFrame)
{
    _node->setRotation(_rotation);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if(_tween)
    {
        _betwennRotation = static_cast<RotationFrame*>(nextFrame)->_rotation - _rotation;
    }
}

<<<<<<< HEAD
void RotationFrame::onApply(float percent)
{
    if (nullptr != _node && _betwennRotation != 0)
=======
void RotationFrame::apply(float percent)
{
    if (_tween && percent != 0 && _betwennRotation != 0)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        float rotation = _rotation + percent * _betwennRotation;
        _node->setRotation(rotation);
    }
}

Frame* RotationFrame::clone()
{
    RotationFrame* frame = RotationFrame::create();
    frame->setRotation(_rotation);

    frame->cloneProperty(this);

    return frame;
}



// SkewFrame
SkewFrame* SkewFrame::create()
{
<<<<<<< HEAD
    SkewFrame* frame = new (std::nothrow) SkewFrame();
=======
    SkewFrame* frame = new SkewFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

SkewFrame::SkewFrame()
    : _skewX(0)
    , _skewY(0)
{
}

<<<<<<< HEAD
void SkewFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

    _node->setSkewX(_skewX);
    _node->setSkewY(_skewY);

=======
void SkewFrame::onEnter(Frame *nextFrame)
{
    _node->setSkewX(_skewX);
    _node->setSkewY(_skewY);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if(_tween)
    {
        _betweenSkewX = static_cast<SkewFrame*>(nextFrame)->_skewX - _skewX;
        _betweenSkewY = static_cast<SkewFrame*>(nextFrame)->_skewY - _skewY;
    }
}

<<<<<<< HEAD
void SkewFrame::onApply(float percent)
{
    if (nullptr != _node && _betweenSkewX != 0 || _betweenSkewY != 0)
    {
        float skewx = _skewX + percent * _betweenSkewX;
        float skewy = _skewY + percent * _betweenSkewY;
        
=======
void SkewFrame::apply(float percent)
{
    if (_tween && percent != 0 && (_betweenSkewX != 0 || _betweenSkewY != 0))
    {
        float skewx = _skewX + percent * _betweenSkewX;
        float skewy = _skewY + percent * _betweenSkewY;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _node->setSkewX(skewx);
        _node->setSkewY(skewy);
    }
}

Frame* SkewFrame::clone()
{
    SkewFrame* frame = SkewFrame::create();
    frame->setSkewX(_skewX);
    frame->setSkewY(_skewY);

    frame->cloneProperty(this);

    return frame;
}




// RotationSkewFrame
RotationSkewFrame* RotationSkewFrame::create()
{
<<<<<<< HEAD
    RotationSkewFrame* frame = new (std::nothrow) RotationSkewFrame();
=======
    RotationSkewFrame* frame = new RotationSkewFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

RotationSkewFrame::RotationSkewFrame()
{
}

<<<<<<< HEAD
void RotationSkewFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

    _node->setRotationSkewX(_skewX);
    _node->setRotationSkewY(_skewY);

=======
void RotationSkewFrame::onEnter(Frame *nextFrame)
{
    _node->setRotationSkewX(_skewX);
    _node->setRotationSkewY(_skewY);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_tween)
    {
        _betweenSkewX = static_cast<RotationSkewFrame*>(nextFrame)->_skewX - _skewX;
        _betweenSkewY = static_cast<RotationSkewFrame*>(nextFrame)->_skewY - _skewY;
    }
}

<<<<<<< HEAD
void RotationSkewFrame::onApply(float percent)
{
    if (nullptr != _node && _betweenSkewX != 0 || _betweenSkewY != 0)
    {
        float skewx = _skewX + percent * _betweenSkewX;
        float skewy = _skewY + percent * _betweenSkewY;
        
=======
void RotationSkewFrame::apply(float percent)
{
    if (_tween && percent != 0 && (_betweenSkewX != 0 || _betweenSkewY != 0))
    {
        float skewx = _skewX + percent * _betweenSkewX;
        float skewy = _skewY + percent * _betweenSkewY;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _node->setRotationSkewX(skewx);
        _node->setRotationSkewY(skewy);
    }
}

Frame* RotationSkewFrame::clone()
{
    RotationSkewFrame* frame = RotationSkewFrame::create();
    frame->setSkewX(_skewX);
    frame->setSkewY(_skewY);

    frame->cloneProperty(this);

    return frame;
}


// PositionFrame
PositionFrame* PositionFrame::create()
{
<<<<<<< HEAD
    PositionFrame* frame = new (std::nothrow) PositionFrame();
=======
    PositionFrame* frame = new PositionFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

PositionFrame::PositionFrame()
    : _position(0,0)
{
}

<<<<<<< HEAD
void PositionFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

=======
void PositionFrame::onEnter(Frame *nextFrame)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _node->setPosition(_position);

    if(_tween)
    {
        _betweenX = static_cast<PositionFrame*>(nextFrame)->_position.x - _position.x;
        _betweenY = static_cast<PositionFrame*>(nextFrame)->_position.y - _position.y;
    }
}

<<<<<<< HEAD
void PositionFrame::onApply(float percent)
{
    if (nullptr != _node && (_betweenX != 0 || _betweenY != 0))
=======
void PositionFrame::apply(float percent)
{
    if (_tween && percent != 0 && (_betweenX != 0 || _betweenY != 0))
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        Point p;
        p.x = _position.x + _betweenX * percent;
        p.y = _position.y + _betweenY * percent;
<<<<<<< HEAD
        
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _node->setPosition(p);
    }
}

<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Frame* PositionFrame::clone()
{
    PositionFrame* frame = PositionFrame::create();
    frame->setPosition(_position);

    frame->cloneProperty(this);

    return frame;
}


// ScaleFrame
ScaleFrame* ScaleFrame::create()
{
<<<<<<< HEAD
    ScaleFrame* frame = new (std::nothrow) ScaleFrame();
=======
    ScaleFrame* frame = new ScaleFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

ScaleFrame::ScaleFrame()
    : _scaleX(1)
    , _scaleY(1)
{
}

<<<<<<< HEAD
void ScaleFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }
	
    _node->setScaleX(_scaleX);
    _node->setScaleY(_scaleY);

=======
void ScaleFrame::onEnter(Frame *nextFrame)
{
    _node->setScaleX(_scaleX);
    _node->setScaleY(_scaleY);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if(_tween)
    {
        _betweenScaleX = static_cast<ScaleFrame*>(nextFrame)->_scaleX - _scaleX;
        _betweenScaleY = static_cast<ScaleFrame*>(nextFrame)->_scaleY - _scaleY;
    }
}

<<<<<<< HEAD
void ScaleFrame::onApply(float percent)
{
    if (nullptr != _node && _betweenScaleX != 0 || _betweenScaleY != 0)
    {
        float scaleX = _scaleX + _betweenScaleX * percent;
        float scaleY = _scaleY + _betweenScaleY * percent;
        
=======
void ScaleFrame::apply(float percent)
{
    if (_tween && percent != 0 && (_betweenScaleX != 0 || _betweenScaleY != 0))
    {
        float scaleX = _scaleX + _betweenScaleX * percent;
        float scaleY = _scaleY + _betweenScaleY * percent;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _node->setScaleX(scaleX);
        _node->setScaleY(scaleY);
    }
}

Frame* ScaleFrame::clone()
{
    ScaleFrame* frame = ScaleFrame::create();
    frame->setScaleX(_scaleX);
    frame->setScaleY(_scaleY);  

    frame->cloneProperty(this);

    return frame;
}


// AnchorPointFrame
AnchorPointFrame* AnchorPointFrame::create()
{
<<<<<<< HEAD
    AnchorPointFrame* frame = new (std::nothrow) AnchorPointFrame();
=======
    AnchorPointFrame* frame = new AnchorPointFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

AnchorPointFrame::AnchorPointFrame()
    : _anchorPoint(0.5f,0.5f)
{
}

<<<<<<< HEAD
void AnchorPointFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

=======
void AnchorPointFrame::onEnter(Frame *nextFrame)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _node->setAnchorPoint(_anchorPoint);
}


Frame* AnchorPointFrame::clone()
{
    AnchorPointFrame* frame = AnchorPointFrame::create();
    frame->setAnchorPoint(_anchorPoint);

    frame->cloneProperty(this);

    return frame;
}



// InnerActionFrame
<<<<<<< HEAD
const std::string InnerActionFrame::AnimationAllName = "-- ALL --";

InnerActionFrame* InnerActionFrame::create()
{
    InnerActionFrame* frame = new (std::nothrow) InnerActionFrame();
=======
InnerActionFrame* InnerActionFrame::create()
{
    InnerActionFrame* frame = new InnerActionFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

InnerActionFrame::InnerActionFrame()
<<<<<<< HEAD
: _innerActionType(InnerActionType::SingleFrame)
, _startFrameIndex(0)
, _endFrameIndex(0)
, _singleFrameIndex(0)
, _animationName("")
, _enterWithName(false)
{

}

void InnerActionFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

    auto innerActiontimeline = static_cast<ActionTimeline*>(_node->getActionByTag(_node->getTag()));
    if( nullptr == innerActiontimeline)
        return;
    
    if (InnerActionType::SingleFrame == _innerActionType)
    {
        innerActiontimeline->gotoFrameAndPause(_singleFrameIndex);
        return;
    }
    
    int innerStart = _startFrameIndex;
    int innerEnd = _endFrameIndex;
    if (_enterWithName)
    {
        if (_animationName == AnimationAllName)
        {
            innerStart = 0;
            innerEnd = innerActiontimeline->getDuration();
        }
        else if(innerActiontimeline->IsAnimationInfoExists(_animationName))
        {
            AnimationInfo info = innerActiontimeline->getAnimationInfo(_animationName);
            innerStart = info.startIndex;
            innerEnd = info.endIndex;
        }
        else
        {
            CCLOG("Animation %s not exists!", _animationName.c_str());
        }
    }
    
    int duration = _timeline->getActionTimeline()->getDuration();
    int odddiff = duration - _frameIndex - innerEnd + innerStart;
    if (odddiff < 0)
    {
       innerEnd += odddiff;
    }
    
    if (InnerActionType::NoLoopAction == _innerActionType)
    {
        innerActiontimeline->gotoFrameAndPlay(innerStart, innerEnd, false);
    }
    else if (InnerActionType::LoopAction == _innerActionType)
    {
        innerActiontimeline->gotoFrameAndPlay(innerStart, innerEnd, true);
    }
}

void InnerActionFrame::setStartFrameIndex(int frameIndex)
{
    if(_enterWithName)
    {
        CCLOG(" cannot set start when enter frame with name. setEnterWithName false firstly!");
        throw std::exception();
    }
    _startFrameIndex = frameIndex;
}


void InnerActionFrame::setEndFrameIndex(int frameIndex)
{
    if(_enterWithName)
    {
         CCLOG(" cannot set end when enter frame with name. setEnterWithName false firstly!");
        throw std::exception();
    }
    _endFrameIndex = frameIndex;
}

void InnerActionFrame::setAnimationName(const std::string& animationName)
{
    if(!_enterWithName)
    {
         CCLOG(" cannot set aniamtioname when enter frame with index. setEnterWithName true firstly!");
        throw std::exception();
    }
    _animationName = animationName;
   
}

=======
    : _innerActionType(LoopAction)
    , _startFrameIndex(0)
{
}

void InnerActionFrame::onEnter(Frame *nextFrame)
{
}


>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Frame* InnerActionFrame::clone()
{
    InnerActionFrame* frame = InnerActionFrame::create();
    frame->setInnerActionType(_innerActionType);
<<<<<<< HEAD
    frame->setSingleFrameIndex(_singleFrameIndex);
    if(_enterWithName)
    {
        frame->setEnterWithName(true);
        frame->setAnimationName(_animationName);
    }
    else
    {
        frame->setStartFrameIndex(_startFrameIndex);
        frame->setEndFrameIndex(_endFrameIndex);
    }
=======
    frame->setStartFrameIndex(_startFrameIndex);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    frame->cloneProperty(this);

    return frame;
}


// ColorFrame
ColorFrame* ColorFrame::create()
{
<<<<<<< HEAD
    ColorFrame* frame = new (std::nothrow) ColorFrame();
=======
    ColorFrame* frame = new ColorFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

ColorFrame::ColorFrame()
<<<<<<< HEAD
: _color(Color3B(255, 255, 255))
{
}

void ColorFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }
    _node->setColor(_color);

    if(_tween)
    {
=======
    : _alpha(255)
    , _color(Color3B(255, 255, 255))
{
}

void ColorFrame::onEnter(Frame *nextFrame)
{
    _node->setOpacity(_alpha);
    _node->setColor(_color);
    
    if(_tween)
    {
        _betweenAlpha = static_cast<ColorFrame*>(nextFrame)->_alpha - _alpha;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        const Color3B& color = static_cast<ColorFrame*>(nextFrame)->_color;
        _betweenRed   = color.r - _color.r;
        _betweenGreen = color.g - _color.g;
        _betweenBlue  = color.b - _color.b;
    }
<<<<<<< HEAD
}

void ColorFrame::onApply(float percent)
{
    if (nullptr != _node && _betweenRed != 0 || _betweenGreen != 0 || _betweenBlue != 0)
    {
=======

    _node->setCascadeColorEnabled(true);
    _node->setCascadeOpacityEnabled(true);
}

void ColorFrame::apply(float percent)
{
    if (_tween && percent != 0 && (_betweenAlpha !=0 || _betweenRed != 0 || _betweenGreen != 0 || _betweenBlue != 0))
    {
        GLubyte alpha = _alpha + _betweenAlpha * percent;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        Color3B color;
        color.r = _color.r+ _betweenRed   * percent;
        color.g = _color.g+ _betweenGreen * percent;
        color.b = _color.b+ _betweenBlue  * percent;
<<<<<<< HEAD
        
=======

        _node->setOpacity(alpha);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _node->setColor(color);
    }
}

Frame* ColorFrame::clone()
{
    ColorFrame* frame = ColorFrame::create();
<<<<<<< HEAD
=======
    frame->setAlpha(_alpha);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    frame->setColor(_color);

    frame->cloneProperty(this);

    return frame;
}

<<<<<<< HEAD
// AlphaFrame
AlphaFrame* AlphaFrame::create()
{
    AlphaFrame* frame = new (std::nothrow) AlphaFrame();
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

AlphaFrame::AlphaFrame()
    : _alpha(255)
{
}

void AlphaFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (_node == nullptr)
    {
	    return;
    }

    _node->setOpacity(_alpha);

    if (_tween)
    {
        _betweenAlpha = static_cast<AlphaFrame*>(nextFrame)->_alpha - _alpha;
    }
}

void AlphaFrame::onApply(float percent)
{
    if (nullptr != _node)
    {
        GLubyte alpha = _alpha + _betweenAlpha * percent;
        _node->setOpacity(alpha);
    }
}

Frame* AlphaFrame::clone()
{
    AlphaFrame* frame = AlphaFrame::create();
    frame->setAlpha(_alpha);
    frame->cloneProperty(this);

    return frame;
}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

// EventFrame
EventFrame* EventFrame::create()
{
<<<<<<< HEAD
    EventFrame* frame = new (std::nothrow) EventFrame();
    if (frame)
    {
        frame->init();
=======
    EventFrame* frame = new EventFrame();
    if (frame)
    {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

<<<<<<< HEAD
void EventFrame::init()
{
    _enterWhenPassed = true;
}

EventFrame::EventFrame()
    : _event("")
    , _action(nullptr)
{
}

void EventFrame::setNode(cocos2d::Node* node)
{
    Frame::setNode(node);
    _action = _timeline->getActionTimeline();
}

void EventFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if (static_cast<int>(_frameIndex) < _action->getStartFrame() || static_cast<int>(_frameIndex) > _action->getEndFrame())
        return;

    if (currentFrameIndex >= static_cast<int>(_frameIndex))
        emitEvent();
=======
EventFrame::EventFrame()
    : _event("")
{
}

void EventFrame::onEnter(Frame *nextFrame)
{
    emitEvent();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}


Frame* EventFrame::clone()
{
    EventFrame* frame = EventFrame::create();
    frame->setEvent(_event);

    frame->cloneProperty(this);

    return frame;
}


// ZOrderFrame
ZOrderFrame* ZOrderFrame::create()
{
<<<<<<< HEAD
    ZOrderFrame* frame = new (std::nothrow) ZOrderFrame();
=======
    ZOrderFrame* frame = new ZOrderFrame();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

ZOrderFrame::ZOrderFrame()
    : _zorder(0)
{
}

<<<<<<< HEAD
void ZOrderFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
=======
void ZOrderFrame::onEnter(Frame *nextFrame)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    if(_node)
        _node->setLocalZOrder(_zorder);
}


Frame* ZOrderFrame::clone()
{
    ZOrderFrame* frame = ZOrderFrame::create();
    frame->setZOrder(_zorder);

    frame->cloneProperty(this);

    return frame;
}

<<<<<<< HEAD

// BlendFuncFrame
BlendFuncFrame* BlendFuncFrame::create()
{
    BlendFuncFrame* frame = new (std::nothrow) BlendFuncFrame();
    if (frame)
    {
        frame->autorelease();
        return frame;
    }
    CC_SAFE_DELETE(frame);
    return nullptr;
}

BlendFuncFrame::BlendFuncFrame()
: _blendFunc(BlendFunc::ALPHA_PREMULTIPLIED)
{
}

void BlendFuncFrame::onEnter(Frame *nextFrame, int currentFrameIndex)
{
    if(_node)
    {
        auto blendnode = dynamic_cast<BlendProtocol*>(_node);
        if(blendnode)
            blendnode->setBlendFunc(_blendFunc);
    }
}


Frame* BlendFuncFrame::clone()
{
    BlendFuncFrame* frame = BlendFuncFrame::create();
    frame->setBlendFunc(_blendFunc);
    frame->cloneProperty(this);
    
    return frame;
}


=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_TIMELINE_END
