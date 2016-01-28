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

#include "ui/UIButton.h"
<<<<<<< HEAD
#include "ui/UIScale9Sprite.h"
=======
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "2d/CCLabel.h"
#include "2d/CCSprite.h"
#include "2d/CCActionInterval.h"
#include "platform/CCFileUtils.h"
<<<<<<< HEAD
#include "ui/UIHelper.h"
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

namespace ui {

static const int NORMAL_RENDERER_Z = (-2);
static const int PRESSED_RENDERER_Z = (-2);
static const int DISABLED_RENDERER_Z = (-2);
static const int TITLE_RENDERER_Z = (-1);
<<<<<<< HEAD
static const float ZOOM_ACTION_TIME_STEP = 0.05f;

IMPLEMENT_CLASS_GUI_INFO(Button)

=======
    
IMPLEMENT_CLASS_GUI_INFO(Button)
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Button::Button():
_buttonNormalRenderer(nullptr),
_buttonClickedRenderer(nullptr),
_buttonDisableRenderer(nullptr),
_titleRenderer(nullptr),
<<<<<<< HEAD
_zoomScale(0.1f),
_prevIgnoreSize(true),
_scale9Enabled(false),
_pressedActionEnabled(false),
_capInsetsNormal(Rect::ZERO),
_capInsetsPressed(Rect::ZERO),
_capInsetsDisabled(Rect::ZERO),
_normalTextureSize(_contentSize),
_pressedTextureSize(_contentSize),
_disabledTextureSize(_contentSize),
=======
_normalFileName(""),
_clickedFileName(""),
_disabledFileName(""),
_prevIgnoreSize(true),
_scale9Enabled(false),
_capInsetsNormal(Rect::ZERO),
_capInsetsPressed(Rect::ZERO),
_capInsetsDisabled(Rect::ZERO),
_normalTexType(TextureResType::LOCAL),
_pressedTexType(TextureResType::LOCAL),
_disabledTexType(TextureResType::LOCAL),
_normalTextureSize(_contentSize),
_pressedTextureSize(_contentSize),
_disabledTextureSize(_contentSize),
_pressedActionEnabled(false),
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_normalTextureScaleXInSize(1.0f),
_normalTextureScaleYInSize(1.0f),
_pressedTextureScaleXInSize(1.0f),
_pressedTextureScaleYInSize(1.0f),
_normalTextureLoaded(false),
_pressedTextureLoaded(false),
_disabledTextureLoaded(false),
_normalTextureAdaptDirty(true),
_pressedTextureAdaptDirty(true),
_disabledTextureAdaptDirty(true),
<<<<<<< HEAD
=======
_fontName("Thonburi"),
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_fontSize(10),
_type(FontType::SYSTEM)
{
    setTouchEnabled(true);
}

Button::~Button()
{
}

Button* Button::create()
{
<<<<<<< HEAD
    Button* widget = new (std::nothrow) Button();
=======
    Button* widget = new Button();
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

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Button* Button::create(const std::string &normalImage,
                       const std::string& selectedImage ,
                       const std::string& disableImage,
                       TextureResType texType)
{
<<<<<<< HEAD
    Button *btn = new (std::nothrow) Button;
    if (btn && btn->init(normalImage,selectedImage,disableImage,texType))
    {
=======
    Button *btn = new Button;
    if (btn && btn->init(normalImage,selectedImage,disableImage,texType)) {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        btn->autorelease();
        return btn;
    }
    CC_SAFE_DELETE(btn);
    return nullptr;
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool Button::init(const std::string &normalImage,
                  const std::string& selectedImage ,
                  const std::string& disableImage,
                  TextureResType texType)
{
    bool ret = true;
<<<<<<< HEAD
    do
    {
        if (!Widget::init())
        {
            ret = false;
            break;
        }

=======
    do {
        if (!Widget::init()) {
            ret = false;
            break;
        }
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        this->loadTextures(normalImage, selectedImage, disableImage,texType);
    } while (0);
    return ret;
}

bool Button::init()
{
    if (Widget::init())
    {
        return true;
    }
    return false;
}

void Button::initRenderer()
{
<<<<<<< HEAD
    _buttonNormalRenderer = Scale9Sprite::create();
    _buttonClickedRenderer = Scale9Sprite::create();
    _buttonDisableRenderer = Scale9Sprite::create();
    _buttonClickedRenderer->setScale9Enabled(false);
    _buttonNormalRenderer->setScale9Enabled(false);
    _buttonDisableRenderer->setScale9Enabled(false);
=======
    _buttonNormalRenderer = Sprite::create();
    _buttonClickedRenderer = Sprite::create();
    _buttonDisableRenderer = Sprite::create();
    _titleRenderer = Label::create();
    _titleRenderer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    addProtectedChild(_buttonNormalRenderer, NORMAL_RENDERER_Z, -1);
    addProtectedChild(_buttonClickedRenderer, PRESSED_RENDERER_Z, -1);
    addProtectedChild(_buttonDisableRenderer, DISABLED_RENDERER_Z, -1);
<<<<<<< HEAD
}

void Button::createTitleRenderer()
{
    _titleRenderer = Label::create();
    _titleRenderer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    addProtectedChild(_titleRenderer, TITLE_RENDERER_Z, -1);
}

void Button::setScale9Enabled(bool able)
{
    if (_scale9Enabled == able)
    {
        return;
    }
<<<<<<< HEAD

    _scale9Enabled = able;

    _buttonNormalRenderer->setScale9Enabled(_scale9Enabled);
    _buttonClickedRenderer->setScale9Enabled(_scale9Enabled);
    _buttonDisableRenderer->setScale9Enabled(_scale9Enabled);

=======
    _brightStyle = BrightStyle::NONE;
    _scale9Enabled = able;
    removeProtectedChild(_buttonNormalRenderer);
    removeProtectedChild(_buttonClickedRenderer);
    removeProtectedChild(_buttonDisableRenderer);
    _buttonNormalRenderer = nullptr;
    _buttonClickedRenderer = nullptr;
    _buttonDisableRenderer = nullptr;
    if (_scale9Enabled)
    {
        _buttonNormalRenderer = extension::Scale9Sprite::create();
        _buttonClickedRenderer = extension::Scale9Sprite::create();
        _buttonDisableRenderer = extension::Scale9Sprite::create();
    }
    else
    {
        _buttonNormalRenderer = Sprite::create();
        _buttonClickedRenderer = Sprite::create();
        _buttonDisableRenderer = Sprite::create();
    }

    loadTextureNormal(_normalFileName, _normalTexType);
    loadTexturePressed(_clickedFileName, _pressedTexType);
    loadTextureDisabled(_disabledFileName, _disabledTexType);
    addProtectedChild(_buttonNormalRenderer, NORMAL_RENDERER_Z, -1);
    addProtectedChild(_buttonClickedRenderer, PRESSED_RENDERER_Z, -1);
    addProtectedChild(_buttonDisableRenderer, DISABLED_RENDERER_Z, -1);
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
<<<<<<< HEAD

    setCapInsetsNormalRenderer(_capInsetsNormal);
    setCapInsetsPressedRenderer(_capInsetsPressed);
    setCapInsetsDisabledRenderer(_capInsetsDisabled);

    _brightStyle = BrightStyle::NONE;
    setBright(_bright);

    _normalTextureAdaptDirty = true;
    _pressedTextureAdaptDirty = true;
    _disabledTextureAdaptDirty = true;
=======
    setCapInsetsNormalRenderer(_capInsetsNormal);
    setCapInsetsPressedRenderer(_capInsetsPressed);
    setCapInsetsDisabledRenderer(_capInsetsDisabled);
    setBright(_bright);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool Button::isScale9Enabled()const
{
    return _scale9Enabled;
}

void Button::ignoreContentAdaptWithSize(bool ignore)
{
<<<<<<< HEAD
    if (_unifySize)
    {
        this->updateContentSize();
        return;
    }

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (!_scale9Enabled || (_scale9Enabled && !ignore))
    {
        Widget::ignoreContentAdaptWithSize(ignore);
        _prevIgnoreSize = ignore;
    }
}

void Button::loadTextures(const std::string& normal,
                          const std::string& selected,
                          const std::string& disabled,
                          TextureResType texType)
{
    loadTextureNormal(normal,texType);
    loadTexturePressed(selected,texType);
    loadTextureDisabled(disabled,texType);
}

void Button::loadTextureNormal(const std::string& normal,TextureResType texType)
{
<<<<<<< HEAD
    if(normal.empty())
    {
        return;
    }
    switch (texType)
    {
        case TextureResType::LOCAL:
            _buttonNormalRenderer->initWithFile(normal);
            break;
        case TextureResType::PLIST:
            _buttonNormalRenderer->initWithSpriteFrameName(normal);
            break;
        default:
            break;
    }
    this->setupNormalTexture();

}

void Button::setupNormalTexture()
{
    _normalTextureSize = _buttonNormalRenderer->getContentSize();

    this->updateChildrenDisplayedRGBA();

    if (_unifySize )
    {
        if (!_scale9Enabled)
        {
            updateContentSizeWithTextureSize(this->getNormalSize());
        }
    }
    else
    {
        updateContentSizeWithTextureSize(_normalTextureSize);
    }
=======
    if (normal.empty())
    {
        return;
    }
    _normalFileName = normal;
    _normalTexType = texType;
    if (_scale9Enabled)
    {
        extension::Scale9Sprite* normalRendererScale9 = static_cast<extension::Scale9Sprite*>(_buttonNormalRenderer);
        switch (_normalTexType)
        {
            case TextureResType::LOCAL:
                normalRendererScale9->initWithFile(normal);
                break;
            case TextureResType::PLIST:
                normalRendererScale9->initWithSpriteFrameName(normal);
                break;
            default:
                break;
        }
        normalRendererScale9->setCapInsets(_capInsetsNormal);
    }
    else
    {
        Sprite* normalRenderer = static_cast<Sprite*>(_buttonNormalRenderer);
        switch (_normalTexType)
        {
            case TextureResType::LOCAL:
                normalRenderer->setTexture(normal);
                break;
            case TextureResType::PLIST:
                normalRenderer->setSpriteFrame(normal);
                break;
            default:
                break;
        }
    }
    _normalTextureSize = _buttonNormalRenderer->getContentSize();
    updateFlippedX();
    updateFlippedY();
    
    updateContentSizeWithTextureSize(_normalTextureSize);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _normalTextureLoaded = true;
    _normalTextureAdaptDirty = true;
}

<<<<<<< HEAD
void Button::loadTextureNormal(SpriteFrame* normalSpriteFrame)
{
    _buttonNormalRenderer->initWithSpriteFrame(normalSpriteFrame);
    this->setupNormalTexture();
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Button::loadTexturePressed(const std::string& selected,TextureResType texType)
{
    if (selected.empty())
    {
        return;
    }
<<<<<<< HEAD

    switch (texType)
    {
        case TextureResType::LOCAL:
            _buttonClickedRenderer->initWithFile(selected);
            break;
        case TextureResType::PLIST:
            _buttonClickedRenderer->initWithSpriteFrameName(selected);
            break;
        default:
            break;
    }

    this->setupPressedTexture();
}

void Button::setupPressedTexture()
{
    _pressedTextureSize = _buttonClickedRenderer->getContentSize();

    this->updateChildrenDisplayedRGBA();

=======
    _clickedFileName = selected;
    _pressedTexType = texType;
    if (_scale9Enabled)
    {
        extension::Scale9Sprite* clickedRendererScale9 = static_cast<extension::Scale9Sprite*>(_buttonClickedRenderer);
        switch (_pressedTexType)
        {
            case TextureResType::LOCAL:
                clickedRendererScale9->initWithFile(selected);
                break;
            case TextureResType::PLIST:
                clickedRendererScale9->initWithSpriteFrameName(selected);
                break;
            default:
                break;
        }
        clickedRendererScale9->setCapInsets(_capInsetsPressed);
    }
    else
    {
        Sprite* clickedRenderer = static_cast<Sprite*>(_buttonClickedRenderer);
        switch (_pressedTexType)
        {
            case TextureResType::LOCAL:
                clickedRenderer->setTexture(selected);
                break;
            case TextureResType::PLIST:
                clickedRenderer->setSpriteFrame(selected);
                break;
            default:
                break;
        }
    }
    _pressedTextureSize = _buttonClickedRenderer->getContentSize();
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _pressedTextureLoaded = true;
    _pressedTextureAdaptDirty = true;
}

<<<<<<< HEAD
void Button::loadTexturePressed(SpriteFrame* pressedSpriteFrame)
{
    _buttonClickedRenderer->initWithSpriteFrame(pressedSpriteFrame);
    this->setupPressedTexture();
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Button::loadTextureDisabled(const std::string& disabled,TextureResType texType)
{
    if (disabled.empty())
    {
        return;
    }
<<<<<<< HEAD

    switch (texType)
    {
        case TextureResType::LOCAL:
            _buttonDisableRenderer->initWithFile(disabled);
            break;
        case TextureResType::PLIST:
            _buttonDisableRenderer->initWithSpriteFrameName(disabled);
            break;
        default:
            break;
    }
    this->setupDisabledTexture();
}

void Button::setupDisabledTexture()
{
    _disabledTextureSize = _buttonDisableRenderer->getContentSize();

    this->updateChildrenDisplayedRGBA();

=======
    _disabledFileName = disabled;
    _disabledTexType = texType;
    if (_scale9Enabled)
    {
        extension::Scale9Sprite* disabledScale9 = static_cast<extension::Scale9Sprite*>(_buttonDisableRenderer);
        switch (_disabledTexType)
        {
            case TextureResType::LOCAL:
                disabledScale9->initWithFile(disabled);
                break;
            case TextureResType::PLIST:
                disabledScale9->initWithSpriteFrameName(disabled);
                break;
            default:
                break;
        }
        disabledScale9->setCapInsets(_capInsetsDisabled);
    }
    else
    {
        Sprite* disabledRenderer = static_cast<Sprite*>(_buttonDisableRenderer);
        switch (_disabledTexType)
        {
            case TextureResType::LOCAL:
                disabledRenderer->setTexture(disabled);
                break;
            case TextureResType::PLIST:
                disabledRenderer->setSpriteFrame(disabled);
                break;
            default:
                break;
        }
    }
    _disabledTextureSize = _buttonDisableRenderer->getContentSize();
    updateFlippedX();
    updateFlippedY();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _disabledTextureLoaded = true;
    _disabledTextureAdaptDirty = true;
}

<<<<<<< HEAD
void Button::loadTextureDisabled(SpriteFrame* disabledSpriteFrame)
{
    _buttonDisableRenderer->initWithSpriteFrame(disabledSpriteFrame);
    this->setupDisabledTexture();
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Button::setCapInsets(const Rect &capInsets)
{
    setCapInsetsNormalRenderer(capInsets);
    setCapInsetsPressedRenderer(capInsets);
    setCapInsetsDisabledRenderer(capInsets);
}

<<<<<<< HEAD

void Button::setCapInsetsNormalRenderer(const Rect &capInsets)
{
    _capInsetsNormal = Helper::restrictCapInsetRect(capInsets, this->_normalTextureSize);

    //for performance issue
=======
void Button::setCapInsetsNormalRenderer(const Rect &capInsets)
{
    _capInsetsNormal = capInsets;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (!_scale9Enabled)
    {
        return;
    }
<<<<<<< HEAD
    _buttonNormalRenderer->setCapInsets(_capInsetsNormal);
}

void Button::setCapInsetsPressedRenderer(const Rect &capInsets)
{
    _capInsetsPressed = Helper::restrictCapInsetRect(capInsets, this->_pressedTextureSize);

    //for performance issue
    if (!_scale9Enabled)
    {
        return;
    }
    _buttonClickedRenderer->setCapInsets(_capInsetsPressed);
}

void Button::setCapInsetsDisabledRenderer(const Rect &capInsets)
{
    _capInsetsDisabled = Helper::restrictCapInsetRect(capInsets, this->_disabledTextureSize);

    //for performance issue
=======
    static_cast<extension::Scale9Sprite*>(_buttonNormalRenderer)->setCapInsets(capInsets);
}

const Rect& Button::getCapInsetsNormalRenderer()const
{
    return _capInsetsNormal;
}

void Button::setCapInsetsPressedRenderer(const Rect &capInsets)
{
    _capInsetsPressed = capInsets;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (!_scale9Enabled)
    {
        return;
    }
<<<<<<< HEAD
    _buttonDisableRenderer->setCapInsets(_capInsetsDisabled);
}

const Rect& Button::getCapInsetsNormalRenderer()const
{
    return _capInsetsNormal;
}

const Rect& Button::getCapInsetsPressedRenderer()const
{
    return _capInsetsPressed;
=======
    static_cast<extension::Scale9Sprite*>(_buttonClickedRenderer)->setCapInsets(capInsets);
}

const Rect& Button::getCapInsetsPressedRenderer()const
{
    return _capInsetsPressed;
}

void Button::setCapInsetsDisabledRenderer(const Rect &capInsets)
{
    _capInsetsDisabled = capInsets;
    if (!_scale9Enabled)
    {
        return;
    }
    static_cast<extension::Scale9Sprite*>(_buttonDisableRenderer)->setCapInsets(capInsets);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

const Rect& Button::getCapInsetsDisabledRenderer()const
{
    return _capInsetsDisabled;
}

void Button::onPressStateChangedToNormal()
{
    _buttonNormalRenderer->setVisible(true);
    _buttonClickedRenderer->setVisible(false);
    _buttonDisableRenderer->setVisible(false);
<<<<<<< HEAD
    _buttonNormalRenderer->setState(Scale9Sprite::State::NORMAL);

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_pressedTextureLoaded)
    {
        if (_pressedActionEnabled)
        {
            _buttonNormalRenderer->stopAllActions();
            _buttonClickedRenderer->stopAllActions();
<<<<<<< HEAD

//            Action *zoomAction = ScaleTo::create(ZOOM_ACTION_TIME_STEP, _normalTextureScaleXInSize, _normalTextureScaleYInSize);
            //fixme: the zoomAction will run in the next frame which will cause the _buttonNormalRenderer to a wrong scale
            _buttonNormalRenderer->setScale(_normalTextureScaleXInSize, _normalTextureScaleYInSize);
            _buttonClickedRenderer->setScale(_pressedTextureScaleXInSize, _pressedTextureScaleYInSize);

            if(nullptr != _titleRenderer)
            {
                _titleRenderer->stopAllActions();
                if (_unifySize)
                {
                    Action *zoomTitleAction = ScaleTo::create(ZOOM_ACTION_TIME_STEP, 1.0f, 1.0f);
                    _titleRenderer->runAction(zoomTitleAction);
                }
                else
                {
                    _titleRenderer->setScaleX(1.0f);
                    _titleRenderer->setScaleY(1.0f);
                }
            }
=======
            Action *zoomAction = ScaleTo::create(0.05f, _normalTextureScaleXInSize, _normalTextureScaleYInSize);
            _buttonNormalRenderer->runAction(zoomAction);
            _buttonClickedRenderer->setScale(_pressedTextureScaleXInSize, _pressedTextureScaleYInSize);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
    }
    else
    {
<<<<<<< HEAD
        _buttonNormalRenderer->stopAllActions();
        _buttonNormalRenderer->setScale(_normalTextureScaleXInSize, _normalTextureScaleYInSize);

        if(nullptr != _titleRenderer)
        {
            _titleRenderer->stopAllActions();
            _titleRenderer->setScaleX(1.0f);
            _titleRenderer->setScaleY(1.0f);
        }

    }
}

void Button::onPressStateChangedToPressed()
{
    _buttonNormalRenderer->setState(Scale9Sprite::State::NORMAL);

=======
        if (_scale9Enabled)
        {
            updateTexturesRGBA();
        }
        else
        {
            _buttonNormalRenderer->stopAllActions();
            _buttonNormalRenderer->setScale(_normalTextureScaleXInSize, _normalTextureScaleYInSize);
        }
    }
}
    
void Button::updateTexturesRGBA()
{
    _buttonNormalRenderer->setColor(this->getColor());
    _buttonClickedRenderer->setColor(this->getColor());
    _buttonDisableRenderer->setColor(this->getColor());

    _buttonNormalRenderer->setOpacity(this->getOpacity());
    _buttonClickedRenderer->setOpacity(this->getOpacity());
    _buttonDisableRenderer->setOpacity(this->getOpacity());
}

void Button::onPressStateChangedToPressed()
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_pressedTextureLoaded)
    {
        _buttonNormalRenderer->setVisible(false);
        _buttonClickedRenderer->setVisible(true);
        _buttonDisableRenderer->setVisible(false);
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        if (_pressedActionEnabled)
        {
            _buttonNormalRenderer->stopAllActions();
            _buttonClickedRenderer->stopAllActions();
<<<<<<< HEAD

            Action *zoomAction = ScaleTo::create(ZOOM_ACTION_TIME_STEP,
                                                 _pressedTextureScaleXInSize + _zoomScale,
                                                 _pressedTextureScaleYInSize + _zoomScale);
            _buttonClickedRenderer->runAction(zoomAction);

            _buttonNormalRenderer->setScale(_pressedTextureScaleXInSize + _zoomScale,
                                            _pressedTextureScaleYInSize + _zoomScale);

            if(nullptr != _titleRenderer)
            {
                _titleRenderer->stopAllActions();
                Action *zoomTitleAction = ScaleTo::create(ZOOM_ACTION_TIME_STEP,
                                                          1.0f + _zoomScale, 1.0f + _zoomScale);
                _titleRenderer->runAction(zoomTitleAction);
            }
=======
            Action *zoomAction = ScaleTo::create(0.05f, _pressedTextureScaleXInSize + 0.1f, _pressedTextureScaleYInSize + 0.1f);
            _buttonClickedRenderer->runAction(zoomAction);
            _buttonNormalRenderer->setScale(_pressedTextureScaleXInSize + 0.1f, _pressedTextureScaleYInSize + 0.1f);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
    }
    else
    {
        _buttonNormalRenderer->setVisible(true);
        _buttonClickedRenderer->setVisible(true);
        _buttonDisableRenderer->setVisible(false);
<<<<<<< HEAD

        _buttonNormalRenderer->stopAllActions();
        _buttonNormalRenderer->setScale(_normalTextureScaleXInSize +_zoomScale, _normalTextureScaleYInSize + _zoomScale);

        if(nullptr != _titleRenderer)
        {
            _titleRenderer->stopAllActions();
            _titleRenderer->setScaleX(1.0f + _zoomScale);
            _titleRenderer->setScaleY(1.0f + _zoomScale);
=======
        if (_scale9Enabled)
        {
            _buttonNormalRenderer->setColor(Color3B::GRAY);
        }
        else
        {
            _buttonNormalRenderer->stopAllActions();
            _buttonNormalRenderer->setScale(_normalTextureScaleXInSize + 0.1f, _normalTextureScaleYInSize + 0.1f);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
    }
}

void Button::onPressStateChangedToDisabled()
{
<<<<<<< HEAD
    //if disable resource is null
    if (!_disabledTextureLoaded)
    {
        if (_normalTextureLoaded)
        {
            _buttonNormalRenderer->setState(Scale9Sprite::State::GRAY);
        }
    }
    else
    {
        _buttonNormalRenderer->setVisible(false);
        _buttonDisableRenderer->setVisible(true);
    }

    _buttonClickedRenderer->setVisible(false);
=======
    _buttonNormalRenderer->setVisible(false);
    _buttonClickedRenderer->setVisible(false);
    _buttonDisableRenderer->setVisible(true);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _buttonNormalRenderer->setScale(_normalTextureScaleXInSize, _normalTextureScaleYInSize);
    _buttonClickedRenderer->setScale(_pressedTextureScaleXInSize, _pressedTextureScaleYInSize);
}

<<<<<<< HEAD
void Button::updateTitleLocation()
{
    _titleRenderer->setPosition(_contentSize.width * 0.5f, _contentSize.height * 0.5f);
}

void Button::updateContentSize()
{
    if (_unifySize)
    {
        if (_scale9Enabled)
        {
            ProtectedNode::setContentSize(_customSize);
        }
        else
        {
            Size s = getNormalSize();
            ProtectedNode::setContentSize(s);
        }
        onSizeChanged();
        return;
    }

    if (_ignoreSize)
    {
        this->setContentSize(getVirtualRendererSize());
    }
}
=======
void Button::updateFlippedX()
{
    float flip = _flippedX ? -1.0f : 1.0f;
    _titleRenderer->setScaleX(flip);
    if (_scale9Enabled)
    {
        _buttonNormalRenderer->setScaleX(flip);
        _buttonClickedRenderer->setScaleX(flip);
        _buttonDisableRenderer->setScaleX(flip);
    }
    else
    {
        static_cast<Sprite*>(_buttonNormalRenderer)->setFlippedX(_flippedX);
        static_cast<Sprite*>(_buttonClickedRenderer)->setFlippedX(_flippedX);
        static_cast<Sprite*>(_buttonDisableRenderer)->setFlippedX(_flippedX);
    }
}
    
void Button::updateFlippedY()
{
    float flip = _flippedY ? -1.0f : 1.0f;
    _titleRenderer->setScaleY(flip);
    if (_scale9Enabled)
    {
        _buttonNormalRenderer->setScaleY(flip);
        _buttonClickedRenderer->setScaleY(flip);
        _buttonDisableRenderer->setScaleY(flip);
    }
    else
    {
        static_cast<Sprite*>(_buttonNormalRenderer)->setFlippedY(_flippedY);
        static_cast<Sprite*>(_buttonClickedRenderer)->setFlippedY(_flippedY);
        static_cast<Sprite*>(_buttonDisableRenderer)->setFlippedY(_flippedY);
    }
}
    
void Button::updateTitleLocation()
{
    _titleRenderer->setPosition(Vec2(_contentSize.width * 0.5f, _contentSize.height * 0.5f));
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

void Button::onSizeChanged()
{
    Widget::onSizeChanged();
<<<<<<< HEAD
    if(nullptr != _titleRenderer)
    {
        updateTitleLocation();
    }
=======
    updateTitleLocation();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _normalTextureAdaptDirty = true;
    _pressedTextureAdaptDirty = true;
    _disabledTextureAdaptDirty = true;
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Button::adaptRenderers()
{
    if (_normalTextureAdaptDirty)
    {
        normalTextureScaleChangedWithSize();
        _normalTextureAdaptDirty = false;
    }
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_pressedTextureAdaptDirty)
    {
        pressedTextureScaleChangedWithSize();
        _pressedTextureAdaptDirty = false;
    }
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_disabledTextureAdaptDirty)
    {
        disabledTextureScaleChangedWithSize();
        _disabledTextureAdaptDirty = false;
    }
}

<<<<<<< HEAD
Size Button::getVirtualRendererSize() const
{
    if (_unifySize)
    {
        return this->getNormalSize();
    }

    if(nullptr != _titleRenderer)
    {
        Size titleSize = _titleRenderer->getContentSize();
        if (!_normalTextureLoaded && _titleRenderer->getString().size() > 0)
        {
            return titleSize;
        }
    }
=======
const Size& Button::getVirtualRendererSize() const
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return _normalTextureSize;
}

Node* Button::getVirtualRenderer()
{
    if (_bright)
    {
        switch (_brightStyle)
        {
            case BrightStyle::NORMAL:
                return _buttonNormalRenderer;
            case BrightStyle::HIGHLIGHT:
                return _buttonClickedRenderer;
            default:
                return nullptr;
        }
    }
    else
    {
        return _buttonDisableRenderer;
    }
}

void Button::normalTextureScaleChangedWithSize()
{
<<<<<<< HEAD

    if (_ignoreSize && !_unifySize)
=======
    if (_ignoreSize)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        if (!_scale9Enabled)
        {
            _buttonNormalRenderer->setScale(1.0f);
            _normalTextureScaleXInSize = _normalTextureScaleYInSize = 1.0f;
        }
    }
    else
    {
        if (_scale9Enabled)
        {
<<<<<<< HEAD
            _buttonNormalRenderer->setPreferredSize(_contentSize);
            _normalTextureScaleXInSize = _normalTextureScaleYInSize = 1.0f;
            _buttonNormalRenderer->setScale(_normalTextureScaleXInSize,_normalTextureScaleYInSize);
=======
            static_cast<extension::Scale9Sprite*>(_buttonNormalRenderer)->setPreferredSize(_contentSize);
            _normalTextureScaleXInSize = _normalTextureScaleYInSize = 1.0f;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        else
        {
            Size textureSize = _normalTextureSize;
            if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
            {
                _buttonNormalRenderer->setScale(1.0f);
                return;
            }
            float scaleX = _contentSize.width / textureSize.width;
            float scaleY = _contentSize.height / textureSize.height;
            _buttonNormalRenderer->setScaleX(scaleX);
            _buttonNormalRenderer->setScaleY(scaleY);
            _normalTextureScaleXInSize = scaleX;
            _normalTextureScaleYInSize = scaleY;
        }
    }
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _buttonNormalRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

void Button::pressedTextureScaleChangedWithSize()
{
<<<<<<< HEAD

    if (_ignoreSize && !_unifySize)
=======
    if (_ignoreSize)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        if (!_scale9Enabled)
        {
            _buttonClickedRenderer->setScale(1.0f);
            _pressedTextureScaleXInSize = _pressedTextureScaleYInSize = 1.0f;
        }
    }
    else
    {
        if (_scale9Enabled)
        {
<<<<<<< HEAD
            _buttonClickedRenderer->setPreferredSize(_contentSize);
            _pressedTextureScaleXInSize = _pressedTextureScaleYInSize = 1.0f;
            _buttonClickedRenderer->setScale(_pressedTextureScaleXInSize,_pressedTextureScaleYInSize);
=======
            static_cast<extension::Scale9Sprite*>(_buttonClickedRenderer)->setPreferredSize(_contentSize);
            _pressedTextureScaleXInSize = _pressedTextureScaleYInSize = 1.0f;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        else
        {
            Size textureSize = _pressedTextureSize;
            if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
            {
                _buttonClickedRenderer->setScale(1.0f);
                return;
            }
            float scaleX = _contentSize.width / _pressedTextureSize.width;
            float scaleY = _contentSize.height / _pressedTextureSize.height;
            _buttonClickedRenderer->setScaleX(scaleX);
            _buttonClickedRenderer->setScaleY(scaleY);
            _pressedTextureScaleXInSize = scaleX;
            _pressedTextureScaleYInSize = scaleY;
        }
    }
    _buttonClickedRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

void Button::disabledTextureScaleChangedWithSize()
{
<<<<<<< HEAD

    if (_ignoreSize && !_unifySize)
=======
    if (_ignoreSize)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        if (!_scale9Enabled)
        {
            _buttonDisableRenderer->setScale(1.0f);
        }
    }
    else
    {
        if (_scale9Enabled)
        {
<<<<<<< HEAD
            _buttonDisableRenderer->setScale(1.0);
            _buttonDisableRenderer->setPreferredSize(_contentSize);
=======
            static_cast<extension::Scale9Sprite*>(_buttonDisableRenderer)->setPreferredSize(_contentSize);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        else
        {
            Size textureSize = _disabledTextureSize;
            if (textureSize.width <= 0.0f || textureSize.height <= 0.0f)
            {
                _buttonDisableRenderer->setScale(1.0f);
                return;
            }
            float scaleX = _contentSize.width / _disabledTextureSize.width;
            float scaleY = _contentSize.height / _disabledTextureSize.height;
            _buttonDisableRenderer->setScaleX(scaleX);
            _buttonDisableRenderer->setScaleY(scaleY);
        }
    }
    _buttonDisableRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

void Button::setPressedActionEnabled(bool enabled)
{
    _pressedActionEnabled = enabled;
}

void Button::setTitleText(const std::string& text)
{
<<<<<<< HEAD
    if (text == getTitleText())
    {
        return;
    }
    if(nullptr == _titleRenderer)
    {
        this->createTitleRenderer();
    }
    _titleRenderer->setString(text);
    updateContentSize();
}

const std::string Button::getTitleText() const
{
    if(nullptr == _titleRenderer)
    {
        return "";
    }
=======
    _titleRenderer->setString(text);
}

const std::string& Button::getTitleText() const
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return _titleRenderer->getString();
}

void Button::setTitleColor(const Color3B& color)
{
<<<<<<< HEAD
    if(nullptr == _titleRenderer)
    {
        this->createTitleRenderer();
    }
    _titleRenderer->setTextColor(Color4B(color));
}

Color3B Button::getTitleColor() const
{
    if(nullptr == _titleRenderer)
    {
        return Color3B::WHITE;
    }
    return Color3B(_titleRenderer->getTextColor());
=======
    _titleRenderer->setColor(color);
}

const Color3B& Button::getTitleColor() const
{
    return _titleRenderer->getColor();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Button::setTitleFontSize(float size)
{
<<<<<<< HEAD
    if(nullptr == _titleRenderer)
    {
        this->createTitleRenderer();
    }
    if (_type == FontType::SYSTEM)
    {
        _titleRenderer->setSystemFontSize(size);
    }
    else
    {
=======
    if (_type == FontType::SYSTEM) {
        _titleRenderer->setSystemFontSize(size);
    }
    else{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        TTFConfig config = _titleRenderer->getTTFConfig();
        config.fontSize = size;
        _titleRenderer->setTTFConfig(config);
    }
<<<<<<< HEAD
    updateContentSize();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _fontSize = size;
}

float Button::getTitleFontSize() const
{
    return _fontSize;
}

<<<<<<< HEAD
void Button::setZoomScale(float scale)
{
    _zoomScale = scale;
}

float Button::getZoomScale()const
{
    return _zoomScale;
}

void Button::setTitleFontName(const std::string& fontName)
{
    if(nullptr == _titleRenderer)
    {
        this->createTitleRenderer();
    }
=======
void Button::setTitleFontName(const std::string& fontName)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if(FileUtils::getInstance()->isFileExist(fontName))
    {
        TTFConfig config = _titleRenderer->getTTFConfig();
        config.fontFilePath = fontName;
        config.fontSize = _fontSize;
        _titleRenderer->setTTFConfig(config);
        _type = FontType::TTF;
<<<<<<< HEAD
    }
    else
    {
        _titleRenderer->setSystemFontName(fontName);
        if (_type == FontType::TTF)
        {
            _titleRenderer->requestSystemFontRefresh();
        }
        _titleRenderer->setSystemFontSize(_fontSize);
        _type = FontType::SYSTEM;
    }
    this->updateContentSize();
}

Label* Button::getTitleRenderer()const
{
    return _titleRenderer;
}

const std::string Button::getTitleFontName() const
{
    if (nullptr != _titleRenderer)
    {
        if(this->_type == FontType::SYSTEM)
        {
            return _titleRenderer->getSystemFontName();
        }
        else
        {
            return  _titleRenderer->getTTFConfig().fontFilePath;
        }
    }
    else
    {
        return "";
    }
}

=======
    } else{
        _titleRenderer->setSystemFontName(fontName);
        _type = FontType::SYSTEM;
    }
    _fontName = fontName;
}

const std::string& Button::getTitleFontName() const
{
    return _fontName;
}
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
std::string Button::getDescription() const
{
    return "Button";
}

Widget* Button::createCloneInstance()
{
    return Button::create();
}

void Button::copySpecialProperties(Widget *widget)
{
    Button* button = dynamic_cast<Button*>(widget);
    if (button)
    {
        _prevIgnoreSize = button->_prevIgnoreSize;
        setScale9Enabled(button->_scale9Enabled);
<<<<<<< HEAD
        auto normalSprite = button->_buttonNormalRenderer->getSprite();
        if (nullptr != normalSprite)
        {
            loadTextureNormal(normalSprite->getSpriteFrame());
        }
        auto clickedSprite = button->_buttonClickedRenderer->getSprite();
        if (nullptr != clickedSprite)
        {
            loadTexturePressed(clickedSprite->getSpriteFrame());
        }
        auto disabledSprite = button->_buttonDisableRenderer->getSprite();
        if (nullptr != disabledSprite)
        {
            loadTextureDisabled(disabledSprite->getSpriteFrame());
        }
        setCapInsetsNormalRenderer(button->_capInsetsNormal);
        setCapInsetsPressedRenderer(button->_capInsetsPressed);
        setCapInsetsDisabledRenderer(button->_capInsetsDisabled);
        if(nullptr != button->getTitleRenderer())
        {
            setTitleText(button->getTitleText());
            setTitleFontName(button->getTitleFontName());
            setTitleFontSize(button->getTitleFontSize());
            setTitleColor(button->getTitleColor());
        }
        setPressedActionEnabled(button->_pressedActionEnabled);
        setZoomScale(button->_zoomScale);
    }

}
Size Button::getNormalSize() const
{
    Size titleSize;
    if (_titleRenderer != nullptr)
    {
        titleSize = _titleRenderer->getContentSize();
    }
    Size imageSize;
    if (_buttonNormalRenderer != nullptr)
    {
        imageSize = _buttonNormalRenderer->getContentSize();
    }
    float width = titleSize.width > imageSize.width ? titleSize.width : imageSize.width;
    float height = titleSize.height > imageSize.height ? titleSize.height : imageSize.height;

    return Size(width,height);
}

Size Button::getNormalTextureSize() const
{
    return _normalTextureSize;
}
=======
        loadTextureNormal(button->_normalFileName, button->_normalTexType);
        loadTexturePressed(button->_clickedFileName, button->_pressedTexType);
        loadTextureDisabled(button->_disabledFileName, button->_disabledTexType);
        setCapInsetsNormalRenderer(button->_capInsetsNormal);
        setCapInsetsPressedRenderer(button->_capInsetsPressed);
        setCapInsetsDisabledRenderer(button->_capInsetsDisabled);
        setTitleText(button->getTitleText());
        setTitleFontName(button->getTitleFontName());
        setTitleFontSize(button->getTitleFontSize());
        setTitleColor(button->getTitleColor());
        setPressedActionEnabled(button->_pressedActionEnabled);
    }
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

NS_CC_END
