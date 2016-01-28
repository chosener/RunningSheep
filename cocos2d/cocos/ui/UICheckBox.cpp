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

#include "ui/UICheckBox.h"
#include "2d/CCSprite.h"

NS_CC_BEGIN

namespace ui {
    
static const int BACKGROUNDBOX_RENDERER_Z = (-1);
static const int BACKGROUNDSELECTEDBOX_RENDERER_Z = (-1);
static const int FRONTCROSS_RENDERER_Z = (-1);
static const int BACKGROUNDBOXDISABLED_RENDERER_Z = (-1);
static const int FRONTCROSSDISABLED_RENDERER_Z = (-1);
    
IMPLEMENT_CLASS_GUI_INFO(CheckBox)

CheckBox::CheckBox():
_backGroundBoxRenderer(nullptr),
_backGroundSelectedBoxRenderer(nullptr),
_frontCrossRenderer(nullptr),
_backGroundBoxDisabledRenderer(nullptr),
_frontCrossDisabledRenderer(nullptr),
_isSelected(true),
_checkBoxEventListener(nullptr),
_checkBoxEventSelector(nullptr),
_backGroundTexType(TextureResType::LOCAL),
_backGroundSelectedTexType(TextureResType::LOCAL),
_frontCrossTexType(TextureResType::LOCAL),
_backGroundDisabledTexType(TextureResType::LOCAL),
_frontCrossDisabledTexType(TextureResType::LOCAL),
<<<<<<< HEAD
_zoomScale(0.1f),
_backgroundTextureScaleX(1.0),
_backgroundTextureScaleY(1.0),
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_backGroundFileName(""),
_backGroundSelectedFileName(""),
_frontCrossFileName(""),
_backGroundDisabledFileName(""),
_frontCrossDisabledFileName(""),
_backGroundBoxRendererAdaptDirty(true),
_backGroundSelectedBoxRendererAdaptDirty(true),
_frontCrossRendererAdaptDirty(true),
_backGroundBoxDisabledRendererAdaptDirty(true),
_frontCrossDisabledRendererAdaptDirty(true)
{
    setTouchEnabled(true);
}

CheckBox::~CheckBox()
{
    _checkBoxEventSelector = nullptr;
}

CheckBox* CheckBox::create()
{
<<<<<<< HEAD
    CheckBox* widget = new (std::nothrow) CheckBox();
=======
    CheckBox* widget = new CheckBox();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}
    
CheckBox* CheckBox::create(const std::string& backGround,
                           const std::string& backGroundSeleted,
                           const std::string& cross,
                           const std::string& backGroundDisabled,
                           const std::string& frontCrossDisabled,
                           TextureResType texType)
{
<<<<<<< HEAD
    CheckBox *pWidget = new (std::nothrow) CheckBox;
=======
    CheckBox *pWidget = new CheckBox;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (pWidget && pWidget->init(backGround,
                                 backGroundSeleted,
                                 cross,
                                 backGroundDisabled,
                                 frontCrossDisabled,
                                 texType))
    {
        pWidget->autorelease();
        return pWidget;
    }
    CC_SAFE_DELETE(pWidget);
    return nullptr;
}
    
<<<<<<< HEAD
CheckBox* CheckBox::create(const std::string& backGround,
                           const std::string& cross,
                           TextureResType texType)
{
    CheckBox *pWidget = new (std::nothrow) CheckBox;
    if (pWidget && pWidget->init(backGround,
                                 "",
                                 cross,
                                 "",
                                 "",
                                 texType))
    {
        pWidget->autorelease();
        return pWidget;
    }
    CC_SAFE_DELETE(pWidget);
    return nullptr;
}
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool CheckBox::init(const std::string& backGround,
                    const std::string& backGroundSeleted,
                    const std::string& cross,
                    const std::string& backGroundDisabled,
                    const std::string& frontCrossDisabled,
                    TextureResType texType)
{
    bool ret = true;
<<<<<<< HEAD
    do
    {
        if (!Widget::init())
        {
=======
    do {
        if (!Widget::init()) {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            ret = false;
            break;
        }
        
<<<<<<< HEAD
        setSelected(false);
=======
        setSelectedState(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        loadTextures(backGround, backGroundSeleted, cross, backGroundDisabled, frontCrossDisabled,texType);
    } while (0);
    return ret;
}

bool CheckBox::init()
{
    if (Widget::init())
    {
<<<<<<< HEAD
        setSelected(false);
=======
        setSelectedState(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return true;
    }
    return false;
}

void CheckBox::initRenderer()
{
    _backGroundBoxRenderer = Sprite::create();
    _backGroundSelectedBoxRenderer = Sprite::create();
    _frontCrossRenderer = Sprite::create();
    _backGroundBoxDisabledRenderer = Sprite::create();
    _frontCrossDisabledRenderer = Sprite::create();
        
    addProtectedChild(_backGroundBoxRenderer, BACKGROUNDBOX_RENDERER_Z, -1);
    addProtectedChild(_backGroundSelectedBoxRenderer, BACKGROUNDSELECTEDBOX_RENDERER_Z, -1);
    addProtectedChild(_frontCrossRenderer, FRONTCROSS_RENDERER_Z, -1);
    addProtectedChild(_backGroundBoxDisabledRenderer, BACKGROUNDBOXDISABLED_RENDERER_Z, -1);
    addProtectedChild(_frontCrossDisabledRenderer, FRONTCROSSDISABLED_RENDERER_Z, -1);
}

void CheckBox::loadTextures(const std::string& backGround,
                            const std::string& backGroundSelected,
                            const std::string& cross,
                            const std::string& backGroundDisabled,
                            const std::string& frontCrossDisabled,
                            TextureResType texType)
{
    loadTextureBackGround(backGround,texType);
    loadTextureBackGroundSelected(backGroundSelected,texType);
    loadTextureFrontCross(cross,texType);
    loadTextureBackGroundDisabled(backGroundDisabled,texType);
    loadTextureFrontCrossDisabled(frontCrossDisabled,texType);
}

void CheckBox::loadTextureBackGround(const std::string& backGround,TextureResType texType)
{
<<<<<<< HEAD
    if (backGround.empty() || (_backGroundFileName == backGround && _backGroundTexType == texType))
=======
    if (backGround.empty())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    _backGroundFileName = backGround;
    _backGroundTexType = texType;
    switch (_backGroundTexType)
    {
        case TextureResType::LOCAL:
            _backGroundBoxRenderer->setTexture(backGround);
            break;
        case TextureResType::PLIST:
            _backGroundBoxRenderer->setSpriteFrame(backGround);
            break;
        default:
            break;
    }
<<<<<<< HEAD
   
    this->updateChildrenDisplayedRGBA();

=======
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    updateContentSizeWithTextureSize(_backGroundBoxRenderer->getContentSize());
    _backGroundBoxRendererAdaptDirty = true;
}

void CheckBox::loadTextureBackGroundSelected(const std::string& backGroundSelected,TextureResType texType)
{
<<<<<<< HEAD
    if (backGroundSelected.empty() ||
        (_backGroundSelectedFileName == backGroundSelected && _backGroundSelectedTexType == texType))
    {
        return;
    }
    
=======
    if (backGroundSelected.empty())
    {
        return;
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _backGroundSelectedFileName = backGroundSelected;
    _backGroundSelectedTexType = texType;
    switch (_backGroundSelectedTexType)
    {
        case TextureResType::LOCAL:
            _backGroundSelectedBoxRenderer->setTexture(backGroundSelected);
            break;
        case TextureResType::PLIST:
            _backGroundSelectedBoxRenderer->setSpriteFrame(backGroundSelected);
            break;
        default:
            break;
    }
<<<<<<< HEAD
  
    this->updateChildrenDisplayedRGBA();

=======
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _backGroundSelectedBoxRendererAdaptDirty = true;
}

void CheckBox::loadTextureFrontCross(const std::string& cross,TextureResType texType)
{
<<<<<<< HEAD
    if (cross.empty() || (_frontCrossFileName == cross && _frontCrossTexType == texType))
=======
    if (cross.empty())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    _frontCrossFileName = cross;
    _frontCrossTexType = texType;
    switch (_frontCrossTexType)
    {
        case TextureResType::LOCAL:
            _frontCrossRenderer->setTexture(cross);
            break;
        case TextureResType::PLIST:
            _frontCrossRenderer->setSpriteFrame(cross);
            break;
        default:
            break;
    }
<<<<<<< HEAD
   
    this->updateChildrenDisplayedRGBA();

=======
    updateFlippedX();
    updateFlippedY();
   
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _frontCrossRendererAdaptDirty = true;
}

void CheckBox::loadTextureBackGroundDisabled(const std::string& backGroundDisabled,TextureResType texType)
{
<<<<<<< HEAD
    if (backGroundDisabled.empty() ||
        (_backGroundDisabledFileName == backGroundDisabled && _backGroundDisabledTexType == texType))
=======
    if (backGroundDisabled.empty())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    _backGroundDisabledFileName = backGroundDisabled;
    _backGroundDisabledTexType = texType;
    switch (_backGroundDisabledTexType)
    {
        case TextureResType::LOCAL:
            _backGroundBoxDisabledRenderer->setTexture(backGroundDisabled);
            break;
        case TextureResType::PLIST:
            _backGroundBoxDisabledRenderer->setSpriteFrame(backGroundDisabled);
            break;
        default:
            break;
    }
<<<<<<< HEAD
   
    this->updateChildrenDisplayedRGBA();

=======
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _backGroundBoxDisabledRendererAdaptDirty = true;
}

void CheckBox::loadTextureFrontCrossDisabled(const std::string& frontCrossDisabled,TextureResType texType)
{
<<<<<<< HEAD
    if (frontCrossDisabled.empty() ||
        (_frontCrossDisabledFileName == frontCrossDisabled && _frontCrossDisabledTexType == texType))
=======
    if (frontCrossDisabled.empty())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    _frontCrossDisabledFileName = frontCrossDisabled;
    _frontCrossDisabledTexType = texType;
    switch (_frontCrossDisabledTexType)
    {
        case TextureResType::LOCAL:
            _frontCrossDisabledRenderer->setTexture(frontCrossDisabled);
            break;
        case TextureResType::PLIST:
            _frontCrossDisabledRenderer->setSpriteFrame(frontCrossDisabled);
            break;
        default:
            break;
    }
<<<<<<< HEAD
  
    this->updateChildrenDisplayedRGBA();

=======
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _frontCrossDisabledRendererAdaptDirty = true;
}


void CheckBox::releaseUpEvent()
{
    Widget::releaseUpEvent();
    
<<<<<<< HEAD
    if (_isSelected)
    {
        setSelected(false);
=======
    if (_isSelected){
        setSelectedState(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        unSelectedEvent();
    }
    else
    {
<<<<<<< HEAD
        setSelected(true);
=======
        setSelectedState(true);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        selectedEvent();
    }
}


void CheckBox::onPressStateChangedToNormal()
{
    _backGroundBoxRenderer->setVisible(true);
    _backGroundSelectedBoxRenderer->setVisible(false);
    _backGroundBoxDisabledRenderer->setVisible(false);
    _frontCrossDisabledRenderer->setVisible(false);
<<<<<<< HEAD
    
    _backGroundBoxRenderer->setGLProgramState(this->getNormalGLProgramState());
    _frontCrossRenderer->setGLProgramState(this->getNormalGLProgramState());
    
    
    _backGroundBoxRenderer->setScale(_backgroundTextureScaleX, _backgroundTextureScaleY);
    _frontCrossRenderer->setScale(_backgroundTextureScaleX, _backgroundTextureScaleY);

    
    if (_isSelected)
    {
        _frontCrossRenderer->setVisible(true);
    }
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::onPressStateChangedToPressed()
{
<<<<<<< HEAD
    _backGroundBoxRenderer->setGLProgramState(this->getNormalGLProgramState());
    _frontCrossRenderer->setGLProgramState(this->getNormalGLProgramState());
    
    if (_backGroundSelectedFileName.empty())
    {
        _backGroundBoxRenderer->setScale(_backgroundTextureScaleX + _zoomScale,
                                         _backgroundTextureScaleY + _zoomScale);
        _frontCrossRenderer->setScale(_backgroundTextureScaleX + _zoomScale,
                                      _backgroundTextureScaleY + _zoomScale);
    }
    else
    {
        _backGroundBoxRenderer->setVisible(false);
        _backGroundSelectedBoxRenderer->setVisible(true);
        _backGroundBoxDisabledRenderer->setVisible(false);
        _frontCrossDisabledRenderer->setVisible(false);
    }
=======
    _backGroundBoxRenderer->setVisible(false);
    _backGroundSelectedBoxRenderer->setVisible(true);
    _backGroundBoxDisabledRenderer->setVisible(false);
    _frontCrossDisabledRenderer->setVisible(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::onPressStateChangedToDisabled()
{
<<<<<<< HEAD
    if (_backGroundDisabledFileName.empty() || _frontCrossDisabledFileName.empty())
    {
        _backGroundBoxRenderer->setGLProgramState(this->getGrayGLProgramState());
        _frontCrossRenderer->setGLProgramState(this->getGrayGLProgramState());
    }
    else
    {
        _backGroundBoxRenderer->setVisible(false);
        _backGroundBoxDisabledRenderer->setVisible(true);
        
    }
    
    _backGroundSelectedBoxRenderer->setVisible(false);
    _frontCrossRenderer->setVisible(false);
    _backGroundBoxRenderer->setScale(_backgroundTextureScaleX, _backgroundTextureScaleY);
    _frontCrossRenderer->setScale(_backgroundTextureScaleX, _backgroundTextureScaleY);
    
=======
    _backGroundBoxRenderer->setVisible(false);
    _backGroundSelectedBoxRenderer->setVisible(false);
    _backGroundBoxDisabledRenderer->setVisible(true);
    _frontCrossRenderer->setVisible(false);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_isSelected)
    {
        _frontCrossDisabledRenderer->setVisible(true);
    }
}
<<<<<<< HEAD
    
void CheckBox::setZoomScale(float scale)
{
    _zoomScale = scale;
}

float CheckBox::getZoomScale()const
{
    return _zoomScale;
}

void CheckBox::setSelected(bool selected)
=======

void CheckBox::setSelectedState(bool selected)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    if (selected == _isSelected)
    {
        return;
    }
    _isSelected = selected;
    _frontCrossRenderer->setVisible(_isSelected);
}
<<<<<<< HEAD
    
bool CheckBox::isSelected()const
=======

bool CheckBox::getSelectedState()const
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    return _isSelected;
}

void CheckBox::selectedEvent()
{
<<<<<<< HEAD
    this->retain();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_checkBoxEventCallback)
    {
        _checkBoxEventCallback(this, EventType::SELECTED);
    }
<<<<<<< HEAD
    if (_ccEventCallback)
    {
        _ccEventCallback(this, static_cast<int>(EventType::SELECTED));
    }
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    if (_checkBoxEventListener && _checkBoxEventSelector)
    {
        (_checkBoxEventListener->*_checkBoxEventSelector)(this,CHECKBOX_STATE_EVENT_SELECTED);
    }
<<<<<<< HEAD
    this->release();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::unSelectedEvent()
{
<<<<<<< HEAD
    this->retain();
    if (_checkBoxEventCallback)
    {
        _checkBoxEventCallback(this, EventType::UNSELECTED);
    }
    if (_ccEventCallback)
    {
        _ccEventCallback(this, static_cast<int>(EventType::UNSELECTED));
    }
=======
    if (_checkBoxEventCallback) {
        _checkBoxEventCallback(this, EventType::UNSELECTED);
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_checkBoxEventListener && _checkBoxEventSelector)
    {
        (_checkBoxEventListener->*_checkBoxEventSelector)(this,CHECKBOX_STATE_EVENT_UNSELECTED);
    }
<<<<<<< HEAD
    this->release();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::addEventListenerCheckBox(Ref *target, SEL_SelectedStateEvent selector)
{
    _checkBoxEventListener = target;
    _checkBoxEventSelector = selector;
}

void CheckBox::addEventListener(const ccCheckBoxCallback& callback)
{
    _checkBoxEventCallback = callback;
}
    
<<<<<<< HEAD
=======
void CheckBox::updateFlippedX()
{
    _backGroundBoxRenderer->setFlippedX(_flippedX);
    _backGroundSelectedBoxRenderer->setFlippedX(_flippedX);
    _frontCrossRenderer->setFlippedX(_flippedX);
    _backGroundBoxDisabledRenderer->setFlippedX(_flippedX);
    _frontCrossDisabledRenderer->setFlippedX(_flippedX);
}
    
void CheckBox::updateFlippedY()
{
    _backGroundBoxRenderer->setFlippedY(_flippedY);
    _backGroundSelectedBoxRenderer->setFlippedY(_flippedY);
    _frontCrossRenderer->setFlippedY(_flippedY);
    _backGroundBoxDisabledRenderer->setFlippedY(_flippedY);
    _frontCrossDisabledRenderer->setFlippedY(_flippedY);
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void CheckBox::onSizeChanged()
{
    Widget::onSizeChanged();
    _backGroundBoxRendererAdaptDirty = true;
    _backGroundSelectedBoxRendererAdaptDirty = true;
    _frontCrossRendererAdaptDirty = true;
    _backGroundBoxDisabledRendererAdaptDirty = true;
    _frontCrossDisabledRendererAdaptDirty = true;
}
    
void CheckBox::adaptRenderers()
{
    if (_backGroundBoxRendererAdaptDirty)
    {
        backGroundTextureScaleChangedWithSize();
        _backGroundBoxRendererAdaptDirty = false;
    }
    if (_backGroundSelectedBoxRendererAdaptDirty)
    {
        backGroundSelectedTextureScaleChangedWithSize();
        _backGroundSelectedBoxRendererAdaptDirty = false;
    }
    if (_frontCrossRendererAdaptDirty)
    {
        frontCrossTextureScaleChangedWithSize();
        _frontCrossRendererAdaptDirty = false;
    }
    if (_backGroundBoxDisabledRendererAdaptDirty)
    {
        backGroundDisabledTextureScaleChangedWithSize();
        _backGroundBoxDisabledRendererAdaptDirty = false;
    }
    if (_frontCrossDisabledRendererAdaptDirty)
    {
        frontCrossDisabledTextureScaleChangedWithSize();
        _frontCrossDisabledRendererAdaptDirty = false;
    }
}

<<<<<<< HEAD
Size CheckBox::getVirtualRendererSize() const
=======
const Size& CheckBox::getVirtualRendererSize() const
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    return _backGroundBoxRenderer->getContentSize();
}

Node* CheckBox::getVirtualRenderer()
{
    return _backGroundBoxRenderer;
}

void CheckBox::backGroundTextureScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _backGroundBoxRenderer->setScale(1.0f);
<<<<<<< HEAD
        _backgroundTextureScaleX = _backgroundTextureScaleY = 1.0f;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
    else
    {
        Size textureSize = _backGroundBoxRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _backGroundBoxRenderer->setScale(1.0f);
<<<<<<< HEAD
            _backgroundTextureScaleX = _backgroundTextureScaleY = 1.0f;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            return;
        }
        float scaleX = _contentSize.width / textureSize.width;
        float scaleY = _contentSize.height / textureSize.height;
<<<<<<< HEAD
        _backgroundTextureScaleX = scaleX;
        _backgroundTextureScaleY = scaleY;
        _backGroundBoxRenderer->setScaleX(scaleX);
        _backGroundBoxRenderer->setScaleY(scaleY);
    }
    _backGroundBoxRenderer->setPosition(_contentSize.width / 2, _contentSize.height / 2);
=======
        _backGroundBoxRenderer->setScaleX(scaleX);
        _backGroundBoxRenderer->setScaleY(scaleY);
    }
    _backGroundBoxRenderer->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::backGroundSelectedTextureScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _backGroundSelectedBoxRenderer->setScale(1.0f);
    }
    else
    {
        Size textureSize = _backGroundSelectedBoxRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _backGroundSelectedBoxRenderer->setScale(1.0f);
            return;
        }
        float scaleX = _contentSize.width / textureSize.width;
        float scaleY = _contentSize.height / textureSize.height;
        _backGroundSelectedBoxRenderer->setScaleX(scaleX);
        _backGroundSelectedBoxRenderer->setScaleY(scaleY);
    }
<<<<<<< HEAD
    _backGroundSelectedBoxRenderer->setPosition(_contentSize.width / 2, _contentSize.height / 2);
=======
    _backGroundSelectedBoxRenderer->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::frontCrossTextureScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _frontCrossRenderer->setScale(1.0f);
    }
    else
    {
        Size textureSize = _frontCrossRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _frontCrossRenderer->setScale(1.0f);
            return;
        }
        float scaleX = _contentSize.width / textureSize.width;
        float scaleY = _contentSize.height / textureSize.height;
        _frontCrossRenderer->setScaleX(scaleX);
        _frontCrossRenderer->setScaleY(scaleY);
    }
<<<<<<< HEAD
    _frontCrossRenderer->setPosition(_contentSize.width / 2, _contentSize.height / 2);
=======
    _frontCrossRenderer->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::backGroundDisabledTextureScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _backGroundBoxDisabledRenderer->setScale(1.0f);
    }
    else
    {
        Size textureSize = _backGroundBoxDisabledRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _backGroundBoxDisabledRenderer->setScale(1.0f);
            return;
        }
        float scaleX = _contentSize.width / textureSize.width;
        float scaleY = _contentSize.height / textureSize.height;
        _backGroundBoxDisabledRenderer->setScaleX(scaleX);
        _backGroundBoxDisabledRenderer->setScaleY(scaleY);
    }
<<<<<<< HEAD
    _backGroundBoxDisabledRenderer->setPosition(_contentSize.width / 2, _contentSize.height / 2);
=======
    _backGroundBoxDisabledRenderer->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void CheckBox::frontCrossDisabledTextureScaleChangedWithSize()
{
    if (_ignoreSize)
    {
        _frontCrossDisabledRenderer->setScale(1.0f);
    }
    else
    {
        Size textureSize = _frontCrossDisabledRenderer->getContentSize();
        if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
        {
            _frontCrossDisabledRenderer->setScale(1.0f);
            return;
        }
        float scaleX = _contentSize.width / textureSize.width;
        float scaleY = _contentSize.height / textureSize.height;
        _frontCrossDisabledRenderer->setScaleX(scaleX);
        _frontCrossDisabledRenderer->setScaleY(scaleY);
    }
<<<<<<< HEAD
    _frontCrossDisabledRenderer->setPosition(_contentSize.width / 2, _contentSize.height / 2);
=======
    _frontCrossDisabledRenderer->setPosition(Vec2(_contentSize.width / 2, _contentSize.height / 2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

std::string CheckBox::getDescription() const
{
    return "CheckBox";
}

Widget* CheckBox::createCloneInstance()
{
    return CheckBox::create();
}

void CheckBox::copySpecialProperties(Widget *widget)
{
    CheckBox* checkBox = dynamic_cast<CheckBox*>(widget);
    if (checkBox)
    {
        loadTextureBackGround(checkBox->_backGroundFileName, checkBox->_backGroundTexType);
        loadTextureBackGroundSelected(checkBox->_backGroundSelectedFileName, checkBox->_backGroundSelectedTexType);
        loadTextureFrontCross(checkBox->_frontCrossFileName, checkBox->_frontCrossTexType);
        loadTextureBackGroundDisabled(checkBox->_backGroundDisabledFileName, checkBox->_backGroundDisabledTexType);
        loadTextureFrontCrossDisabled(checkBox->_frontCrossDisabledFileName, checkBox->_frontCrossDisabledTexType);
<<<<<<< HEAD
        setSelected(checkBox->_isSelected);
        _checkBoxEventListener = checkBox->_checkBoxEventListener;
        _checkBoxEventSelector = checkBox->_checkBoxEventSelector;
        _checkBoxEventCallback = checkBox->_checkBoxEventCallback;
        _ccEventCallback = checkBox->_ccEventCallback;
        _zoomScale = checkBox->_zoomScale;
        _backgroundTextureScaleX = checkBox->_backgroundTextureScaleX;
        _backgroundTextureScaleY = checkBox->_backgroundTextureScaleY;
=======
        setSelectedState(checkBox->_isSelected);
        _checkBoxEventListener = checkBox->_checkBoxEventListener;
        _checkBoxEventSelector = checkBox->_checkBoxEventSelector;
        _checkBoxEventCallback = checkBox->_checkBoxEventCallback;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
}

}

NS_CC_END
