/****************************************************************************
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

#include "ui/UISlider.h"
<<<<<<< HEAD
#include "ui/UIScale9Sprite.h"
#include "ui/UIHelper.h"
=======
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "2d/CCSprite.h"

NS_CC_BEGIN

namespace ui {
    
static const int BASEBAR_RENDERER_Z = (-2);
static const int PROGRESSBAR_RENDERER_Z = (-2);
static const int SLIDBALL_RENDERER_Z = (-1);
    
IMPLEMENT_CLASS_GUI_INFO(Slider)
    
Slider::Slider():
_barRenderer(nullptr),
_progressBarRenderer(nullptr),
<<<<<<< HEAD
_barTextureSize(Size::ZERO),
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_progressBarTextureSize(Size::ZERO),
_slidBallNormalRenderer(nullptr),
_slidBallPressedRenderer(nullptr),
_slidBallDisabledRenderer(nullptr),
_slidBallRenderer(nullptr),
_barLength(0.0),
_percent(0),
_scale9Enabled(false),
_prevIgnoreSize(true),
<<<<<<< HEAD
_zoomScale(0.1f),
_sliderBallNormalTextureScaleX(1.0),
_sliderBallNormalTextureScaleY(1.0),
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_textureFile(""),
_progressBarTextureFile(""),
_slidBallNormalTextureFile(""),
_slidBallPressedTextureFile(""),
_slidBallDisabledTextureFile(""),
_capInsetsBarRenderer(Rect::ZERO),
_capInsetsProgressBarRenderer(Rect::ZERO),
_sliderEventListener(nullptr),
_sliderEventSelector(nullptr),
<<<<<<< HEAD
_eventCallback(nullptr),
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_barTexType(TextureResType::LOCAL),
_progressBarTexType(TextureResType::LOCAL),
_ballNTexType(TextureResType::LOCAL),
_ballPTexType(TextureResType::LOCAL),
_ballDTexType(TextureResType::LOCAL),
_barRendererAdaptDirty(true),
<<<<<<< HEAD
_progressBarRendererDirty(true)
=======
_progressBarRendererDirty(true),
_eventCallback(nullptr)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    setTouchEnabled(true);
}

Slider::~Slider()
{
    _sliderEventListener = nullptr;
    _sliderEventSelector = nullptr;
}

Slider* Slider::create()
{
<<<<<<< HEAD
    Slider* widget = new (std::nothrow) Slider();
=======
    Slider* widget = new Slider();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}
<<<<<<< HEAD
    
Slider* Slider::create(const std::string& barTextureName,
                      const std::string& normalBallTextureName,
                      TextureResType resType)
{
    Slider* widget = new (std::nothrow) Slider();
    if (widget && widget->init())
    {
        widget->loadBarTexture(barTextureName);
        widget->loadSlidBallTextureNormal(normalBallTextureName);
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

bool Slider::init()
{
    if (Widget::init())
    {
        return true;
    }
    return false;
}

void Slider::initRenderer()
{
<<<<<<< HEAD
    _barRenderer = Scale9Sprite::create();
    _progressBarRenderer = Scale9Sprite::create();
    _barRenderer->setScale9Enabled(false);
    _progressBarRenderer->setScale9Enabled(false);
    
    _progressBarRenderer->setAnchorPoint(Vec2(0.0f, 0.5f));
    
    addProtectedChild(_barRenderer, BASEBAR_RENDERER_Z, -1);
    addProtectedChild(_progressBarRenderer, PROGRESSBAR_RENDERER_Z, -1);
    
=======
    _barRenderer = Sprite::create();
    _progressBarRenderer = Sprite::create();
    _progressBarRenderer->setAnchorPoint(Vec2(0.0f, 0.5f));
    addProtectedChild(_barRenderer, BASEBAR_RENDERER_Z, -1);
    addProtectedChild(_progressBarRenderer, PROGRESSBAR_RENDERER_Z, -1);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _slidBallNormalRenderer = Sprite::create();
    _slidBallPressedRenderer = Sprite::create();
    _slidBallPressedRenderer->setVisible(false);
    _slidBallDisabledRenderer = Sprite::create();
    _slidBallDisabledRenderer->setVisible(false);
<<<<<<< HEAD
    
    _slidBallRenderer = Node::create();
    
    _slidBallRenderer->addChild(_slidBallNormalRenderer);
    _slidBallRenderer->addChild(_slidBallPressedRenderer);
    _slidBallRenderer->addChild(_slidBallDisabledRenderer);
    _slidBallRenderer->setCascadeColorEnabled(true);
    _slidBallRenderer->setCascadeOpacityEnabled(true);
    
=======
    _slidBallRenderer = Node::create();
    _slidBallRenderer->addChild(_slidBallNormalRenderer);
    _slidBallRenderer->addChild(_slidBallPressedRenderer);
    _slidBallRenderer->addChild(_slidBallDisabledRenderer);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    addProtectedChild(_slidBallRenderer, SLIDBALL_RENDERER_Z, -1);
}

void Slider::loadBarTexture(const std::string& fileName, TextureResType texType)
{
    if (fileName.empty())
    {
        return;
    }
    _textureFile = fileName;
    _barTexType = texType;
    switch (_barTexType)
    {
        case TextureResType::LOCAL:
<<<<<<< HEAD
            _barRenderer->initWithFile(fileName);
            break;
        case TextureResType::PLIST:
            _barRenderer->initWithSpriteFrameName(fileName);
=======
            if (_scale9Enabled)
            {
                static_cast<extension::Scale9Sprite*>(_barRenderer)->initWithFile(fileName);
            }
            else
            {
                static_cast<Sprite*>(_barRenderer)->setTexture(fileName);
            }
            break;
        case TextureResType::PLIST:
            if (_scale9Enabled)
            {
                static_cast<extension::Scale9Sprite*>(_barRenderer)->initWithSpriteFrameName(fileName);
            }
            else
            {
                static_cast<Sprite*>(_barRenderer)->setSpriteFrame(fileName);
            }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        default:
            break;
    }
<<<<<<< HEAD
    this->updateChildrenDisplayedRGBA();
    _barRendererAdaptDirty = true;
    _progressBarRendererDirty = true;
    updateContentSizeWithTextureSize(_barRenderer->getContentSize());
    _barTextureSize = _barRenderer->getContentSize();
=======
    
    _barRendererAdaptDirty = true;
    _progressBarRendererDirty = true;
    updateContentSizeWithTextureSize(_barRenderer->getContentSize());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Slider::loadProgressBarTexture(const std::string& fileName, TextureResType texType)
{
    if (fileName.empty())
    {
        return;
    }
    _progressBarTextureFile = fileName;
    _progressBarTexType = texType;
    switch (_progressBarTexType)
    {
        case TextureResType::LOCAL:
<<<<<<< HEAD
            _progressBarRenderer->initWithFile(fileName);
            break;
        case TextureResType::PLIST:
            _progressBarRenderer->initWithSpriteFrameName(fileName);
=======
            if (_scale9Enabled)
            {
                static_cast<extension::Scale9Sprite*>(_progressBarRenderer)->initWithFile(fileName);
            }
            else
            {
                static_cast<Sprite*>(_progressBarRenderer)->setTexture(fileName);
            }
            break;
        case TextureResType::PLIST:
            if (_scale9Enabled)
            {
                static_cast<extension::Scale9Sprite*>(_progressBarRenderer)->initWithSpriteFrameName(fileName);
            }
            else
            {
                static_cast<Sprite*>(_progressBarRenderer)->setSpriteFrame(fileName);
            }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        default:
            break;
    }
<<<<<<< HEAD
    this->updateChildrenDisplayedRGBA();
=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _progressBarRenderer->setAnchorPoint(Vec2(0.0f, 0.5f));
    _progressBarTextureSize = _progressBarRenderer->getContentSize();
    _progressBarRendererDirty = true;
}

void Slider::setScale9Enabled(bool able)
{
    if (_scale9Enabled == able)
    {
        return;
    }
    
    _scale9Enabled = able;
<<<<<<< HEAD
    _barRenderer->setScale9Enabled(_scale9Enabled);
    _progressBarRenderer->setScale9Enabled(_scale9Enabled);
    
=======
    removeProtectedChild(_barRenderer);
    removeProtectedChild(_progressBarRenderer);
    _barRenderer = nullptr;
    _progressBarRenderer = nullptr;
    if (_scale9Enabled)
    {
        _barRenderer = extension::Scale9Sprite::create();
        _progressBarRenderer = extension::Scale9Sprite::create();
    }
    else
    {
        _barRenderer = Sprite::create();
        _progressBarRenderer = Sprite::create();
    }
    loadBarTexture(_textureFile, _barTexType);
    loadProgressBarTexture(_progressBarTextureFile, _progressBarTexType);
    addProtectedChild(_barRenderer, BASEBAR_RENDERER_Z, -1);
    addProtectedChild(_progressBarRenderer, PROGRESSBAR_RENDERER_Z, -1);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_scale9Enabled)
    {
        bool ignoreBefore = _ignoreSize;
        ignoreContentAdaptWithSize(false);
        _prevIgnoreSize = ignoreBefore;
    }
    else
    {
        ignoreContentAdaptWithSize(_prevIgnoreSize);
    }
    setCapInsetsBarRenderer(_capInsetsBarRenderer);
    setCapInsetProgressBarRebderer(_capInsetsProgressBarRenderer);
<<<<<<< HEAD
    _barRendererAdaptDirty = true;
    _progressBarRendererDirty = true;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}
    
bool Slider::isScale9Enabled()const
{
    return _scale9Enabled;
}

void Slider::ignoreContentAdaptWithSize(bool ignore)
{
    if (!_scale9Enabled || (_scale9Enabled && !ignore))
    {
        Widget::ignoreContentAdaptWithSize(ignore);
        _prevIgnoreSize = ignore;
    }
}

void Slider::setCapInsets(const Rect &capInsets)
{
    setCapInsetsBarRenderer(capInsets);
    setCapInsetProgressBarRebderer(capInsets);
}

void Slider::setCapInsetsBarRenderer(const Rect &capInsets)
{
<<<<<<< HEAD
    _capInsetsBarRenderer = ui::Helper::restrictCapInsetRect(capInsets, _barRenderer->getContentSize());
=======
    _capInsetsBarRenderer = capInsets;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (!_scale9Enabled)
    {
        return;
    }
<<<<<<< HEAD
    _barRenderer->setCapInsets(_capInsetsBarRenderer);
=======
    static_cast<extension::Scale9Sprite*>(_barRenderer)->setCapInsets(capInsets);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}
    
const Rect& Slider::getCapInsetsBarRenderer()const
{
    return _capInsetsBarRenderer;
}

void Slider::setCapInsetProgressBarRebderer(const Rect &capInsets)
{
<<<<<<< HEAD
    _capInsetsProgressBarRenderer = ui::Helper::restrictCapInsetRect(capInsets, _progressBarRenderer->getContentSize());
    
=======
    _capInsetsProgressBarRenderer = capInsets;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (!_scale9Enabled)
    {
        return;
    }
<<<<<<< HEAD
    _progressBarRenderer->setCapInsets(_capInsetsProgressBarRenderer);
=======
    static_cast<extension::Scale9Sprite*>(_progressBarRenderer)->setCapInsets(capInsets);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}
    
const Rect& Slider::getCapInsetsProgressBarRebderer()const
{
    return _capInsetsProgressBarRenderer;
}

<<<<<<< HEAD
void Slider::loadSlidBallTextures(const std::string& normal,
                                      const std::string& pressed,
                                      const std::string& disabled,
                                      TextureResType texType)
=======
    void Slider::loadSlidBallTextures(const std::string& normal,const std::string& pressed,const std::string& disabled,TextureResType texType)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    loadSlidBallTextureNormal(normal, texType);
    loadSlidBallTexturePressed(pressed,texType);
    loadSlidBallTextureDisabled(disabled,texType);
}

void Slider::loadSlidBallTextureNormal(const std::string& normal,TextureResType texType)
{
    if (normal.empty())
    {
        return;
    }
    _slidBallNormalTextureFile = normal;
    _ballNTexType = texType;
    switch (_ballNTexType)
    {
        case TextureResType::LOCAL:
            _slidBallNormalRenderer->setTexture(normal);
            break;
        case TextureResType::PLIST:
            _slidBallNormalRenderer->setSpriteFrame(normal);
            break;
        default:
            break;
    }
<<<<<<< HEAD
    this->updateChildrenDisplayedRGBA();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Slider::loadSlidBallTexturePressed(const std::string& pressed,TextureResType texType)
{
    if (pressed.empty())
    {
        return;
    }
    _slidBallPressedTextureFile = pressed;
    _ballPTexType = texType;
    switch (_ballPTexType)
    {
        case TextureResType::LOCAL:
            _slidBallPressedRenderer->setTexture(pressed);
            break;
        case TextureResType::PLIST:
            _slidBallPressedRenderer->setSpriteFrame(pressed);
            break;
        default:
            break;
    }
<<<<<<< HEAD
    this->updateChildrenDisplayedRGBA();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

    void Slider::loadSlidBallTextureDisabled(const std::string& disabled,TextureResType texType)
{
    if (disabled.empty())
    {
        return;
    }
    _slidBallDisabledTextureFile = disabled;
    _ballDTexType = texType;
    switch (_ballDTexType)
    {
        case TextureResType::LOCAL:
            _slidBallDisabledRenderer->setTexture(disabled);
            break;
        case TextureResType::PLIST:
            _slidBallDisabledRenderer->setSpriteFrame(disabled);
            break;
        default:
            break;
    }
<<<<<<< HEAD
    this->updateChildrenDisplayedRGBA();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Slider::setPercent(int percent)
{
    if (percent > 100)
    {
        percent = 100;
    }
    if (percent < 0)
    {
        percent = 0;
    }
    _percent = percent;
    float res = percent / 100.0f;
    float dis = _barLength * res;
<<<<<<< HEAD
    _slidBallRenderer->setPosition(dis, _contentSize.height / 2.0f);
    if (_scale9Enabled)
    {
        _progressBarRenderer->setPreferredSize(Size(dis,_contentSize.height));
    }
    else
    {
        Sprite* spriteRenderer = _progressBarRenderer->getSprite();
        
        if (nullptr != spriteRenderer) {
            Rect rect = spriteRenderer->getTextureRect();
            rect.size.width = _progressBarTextureSize.width * res;
            spriteRenderer->setTextureRect(rect, spriteRenderer->isTextureRectRotated(), rect.size);
        }
=======
    _slidBallRenderer->setPosition(Vec2(dis, _contentSize.height / 2.0f));
    if (_scale9Enabled)
    {
        static_cast<extension::Scale9Sprite*>(_progressBarRenderer)->setPreferredSize(Size(dis,_progressBarTextureSize.height));
    }
    else
    {
        Sprite* spriteRenderer = static_cast<Sprite*>(_progressBarRenderer);
        Rect rect = spriteRenderer->getTextureRect();
        rect.size.width = _progressBarTextureSize.width * res;
        spriteRenderer->setTextureRect(rect, spriteRenderer->isTextureRectRotated(), rect.size);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
}
    
bool Slider::hitTest(const cocos2d::Vec2 &pt)
{
    Vec2 nsp = this->_slidBallNormalRenderer->convertToNodeSpace(pt);
    Size ballSize = this->_slidBallNormalRenderer->getContentSize();
    Rect ballRect = Rect(0,0, ballSize.width, ballSize.height);
<<<<<<< HEAD
    if (ballRect.containsPoint(nsp))
    {
=======
    if (ballRect.containsPoint(nsp)) {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return true;
    }
    return false;
}

bool Slider::onTouchBegan(Touch *touch, Event *unusedEvent)
{
    bool pass = Widget::onTouchBegan(touch, unusedEvent);
    if (_hitted)
    {
        Vec2 nsp = convertToNodeSpace(_touchBeganPosition);
        setPercent(getPercentWithBallPos(nsp.x));
        percentChangedEvent();
    }
    return pass;
}

void Slider::onTouchMoved(Touch *touch, Event *unusedEvent)
{
    _touchMovePosition = touch->getLocation();
    Vec2 nsp = convertToNodeSpace(_touchMovePosition);
    setPercent(getPercentWithBallPos(nsp.x));
    percentChangedEvent();
}

void Slider::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    Widget::onTouchEnded(touch, unusedEvent);
}

void Slider::onTouchCancelled(Touch *touch, Event *unusedEvent)
{
    Widget::onTouchCancelled(touch, unusedEvent);
}

float Slider::getPercentWithBallPos(float px)const
{
    return ((px/_barLength)*100.0f);
}

void Slider::addEventListenerSlider(Ref *target, SEL_SlidPercentChangedEvent selector)
{
    _sliderEventListener = target;
    _sliderEventSelector = selector;
}
    
void Slider::addEventListener(const ccSliderCallback& callback)
{
    _eventCallback = callback;
}

void Slider::percentChangedEvent()
{
<<<<<<< HEAD
    this->retain();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_sliderEventListener && _sliderEventSelector)
    {
        (_sliderEventListener->*_sliderEventSelector)(this,SLIDER_PERCENTCHANGED);
    }
<<<<<<< HEAD
    if (_eventCallback)
    {
        _eventCallback(this, EventType::ON_PERCENTAGE_CHANGED);
    }
    if (_ccEventCallback)
    {
        _ccEventCallback(this, static_cast<int>(EventType::ON_PERCENTAGE_CHANGED));
    }
    this->release();
=======
    if (_eventCallback) {
        _eventCallback(this, EventType::ON_PERCENTAGE_CHANGED);
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

int Slider::getPercent()const
{
    return _percent;
}

void Slider::onSizeChanged()
{
    Widget::onSizeChanged();
    _barRendererAdaptDirty = true;
    _progressBarRendererDirty = true;
}
    
void Slider::adaptRenderers()
{
    if (_barRendererAdaptDirty)
    {
        barRendererScaleChangedWithSize();
        _barRendererAdaptDirty = false;
    }
    if (_progressBarRendererDirty)
    {
        progressBarRendererScaleChangedWithSize();
        _progressBarRendererDirty = false;
    }
}

<<<<<<< HEAD
Size Slider::getVirtualRendererSize() const
=======
const Size& Slider::getVirtualRendererSize() const
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    return _barRenderer->getContentSize();
}

Node* Slider::getVirtualRenderer()
{
    return _barRenderer;
}

void Slider::barRendererScaleChangedWithSize()
{
<<<<<<< HEAD
    if (_unifySize)
    {
        _barLength = _contentSize.width;
        _barRenderer->setPreferredSize(_contentSize);
    }
    else if (_ignoreSize)
=======
    if (_ignoreSize)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        
        _barRenderer->setScale(1.0f);
        _barLength = _contentSize.width;
    }
    else
    {
        _barLength = _contentSize.width;
        if (_scale9Enabled)
        {
<<<<<<< HEAD
            _barRenderer->setPreferredSize(_contentSize);
            _barRenderer->setScale(1.0f);
        }
        else
        {
            Size btextureSize = _barTextureSize;
=======
            static_cast<extension::Scale9Sprite*>(_barRenderer)->setPreferredSize(_contentSize);
        }
        else
        {
            Size btextureSize = _barRenderer->getContentSize();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            if (btextureSize.width <= 0.0f || btextureSize.height <= 0.0f)
            {
                _barRenderer->setScale(1.0f);
                return;
            }
            float bscaleX = _contentSize.width / btextureSize.width;
            float bscaleY = _contentSize.height / btextureSize.height;
            _barRenderer->setScaleX(bscaleX);
            _barRenderer->setScaleY(bscaleY);
        }
    }
    _barRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
    setPercent(_percent);
}

void Slider::progressBarRendererScaleChangedWithSize()
{
<<<<<<< HEAD
    if (_unifySize)
    {
        _progressBarRenderer->setPreferredSize(_contentSize);
    }
    else if (_ignoreSize)
=======
    if (_ignoreSize)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        if (!_scale9Enabled)
        {
            Size ptextureSize = _progressBarTextureSize;
            float pscaleX = _contentSize.width / ptextureSize.width;
            float pscaleY = _contentSize.height / ptextureSize.height;
            _progressBarRenderer->setScaleX(pscaleX);
            _progressBarRenderer->setScaleY(pscaleY);
        }
    }
    else
    {
        if (_scale9Enabled)
        {
<<<<<<< HEAD
            _progressBarRenderer->setPreferredSize(_contentSize);
            _progressBarRenderer->setScale(1.0);
=======
            static_cast<extension::Scale9Sprite*>(_progressBarRenderer)->setPreferredSize(_contentSize);
            _progressBarTextureSize = _progressBarRenderer->getContentSize();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        else
        {
            Size ptextureSize = _progressBarTextureSize;
            if (ptextureSize.width <= 0.0f || ptextureSize.height <= 0.0f)
            {
                _progressBarRenderer->setScale(1.0f);
                return;
            }
            float pscaleX = _contentSize.width / ptextureSize.width;
            float pscaleY = _contentSize.height / ptextureSize.height;
            _progressBarRenderer->setScaleX(pscaleX);
            _progressBarRenderer->setScaleY(pscaleY);
        }
    }
    _progressBarRenderer->setPosition(0.0f, _contentSize.height / 2.0f);
    setPercent(_percent);
}

void Slider::onPressStateChangedToNormal()
{
    _slidBallNormalRenderer->setVisible(true);
    _slidBallPressedRenderer->setVisible(false);
    _slidBallDisabledRenderer->setVisible(false);
<<<<<<< HEAD
    
    _slidBallNormalRenderer->setGLProgramState(this->getNormalGLProgramState());
    _slidBallNormalRenderer->setScale(_sliderBallNormalTextureScaleX, _sliderBallNormalTextureScaleY);
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Slider::onPressStateChangedToPressed()
{
<<<<<<< HEAD
    _slidBallNormalRenderer->setGLProgramState(this->getNormalGLProgramState());

    
    if (_slidBallPressedTextureFile.empty())
    {
        _slidBallNormalRenderer->setScale(_sliderBallNormalTextureScaleX + _zoomScale,
                                          _sliderBallNormalTextureScaleY + _zoomScale);
    }
    else
    {
        _slidBallNormalRenderer->setVisible(false);
        _slidBallPressedRenderer->setVisible(true);
        _slidBallDisabledRenderer->setVisible(false);
    }
=======
    _slidBallNormalRenderer->setVisible(false);
    _slidBallPressedRenderer->setVisible(true);
    _slidBallDisabledRenderer->setVisible(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Slider::onPressStateChangedToDisabled()
{
<<<<<<< HEAD
    if (_slidBallDisabledTextureFile.empty())
    {
        _slidBallNormalRenderer->setGLProgramState(this->getGrayGLProgramState());
    }
    else
    {
        _slidBallNormalRenderer->setVisible(false);
        _slidBallDisabledRenderer->setVisible(true);
    }
    
    _slidBallNormalRenderer->setScale(_sliderBallNormalTextureScaleX, _sliderBallNormalTextureScaleY);
    
    _slidBallPressedRenderer->setVisible(false);
}
    
    
void Slider::setZoomScale(float scale)
{
    _zoomScale = scale;
}

float Slider::getZoomScale()const
{
    return _zoomScale;
}

=======
    _slidBallNormalRenderer->setVisible(false);
    _slidBallPressedRenderer->setVisible(false);
    _slidBallDisabledRenderer->setVisible(true);
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

std::string Slider::getDescription() const
{
    return "Slider";
}

Widget* Slider::createCloneInstance()
{
    return Slider::create();
}

void Slider::copySpecialProperties(Widget *widget)
{
    Slider* slider = dynamic_cast<Slider*>(widget);
    if (slider)
    {
        _prevIgnoreSize = slider->_prevIgnoreSize;
        setScale9Enabled(slider->_scale9Enabled);
        loadBarTexture(slider->_textureFile, slider->_barTexType);
        loadProgressBarTexture(slider->_progressBarTextureFile, slider->_progressBarTexType);
        loadSlidBallTextureNormal(slider->_slidBallNormalTextureFile, slider->_ballNTexType);
        loadSlidBallTexturePressed(slider->_slidBallPressedTextureFile, slider->_ballPTexType);
        loadSlidBallTextureDisabled(slider->_slidBallDisabledTextureFile, slider->_ballDTexType);
        setPercent(slider->getPercent());
        _sliderEventListener = slider->_sliderEventListener;
        _sliderEventSelector = slider->_sliderEventSelector;
        _eventCallback = slider->_eventCallback;
<<<<<<< HEAD
        _ccEventCallback = slider->_ccEventCallback;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
}

}

NS_CC_END
