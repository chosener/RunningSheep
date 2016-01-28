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

#include "ui/UIWidget.h"
#include "ui/UILayout.h"
#include "ui/UIHelper.h"
#include "base/CCEventListenerTouch.h"
#include "base/CCEventListenerKeyboard.h"
#include "base/CCDirector.h"
#include "base/CCEventFocus.h"
<<<<<<< HEAD
#include "base/CCEventDispatcher.h"
#include "ui/UILayoutComponent.h"
#include "renderer/CCGLProgram.h"
#include "renderer/CCGLProgramState.h"
#include "renderer/ccShaders.h"
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

namespace ui {
<<<<<<< HEAD

class Widget::FocusNavigationController
{
    void enableFocusNavigation(bool flag);

=======
    
class Widget::FocusNavigationController
{
    void enableFocusNavigation(bool flag);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    FocusNavigationController():
    _keyboardListener(nullptr),
    _firstFocusedWidget(nullptr),
    _enableFocusNavigation(false),
    _keyboardEventPriority(1)
    {
        //no-op
    }
    ~FocusNavigationController();
protected:
    void setFirstFocsuedWidget(Widget* widget);
<<<<<<< HEAD

    void onKeypadKeyPressed(EventKeyboard::KeyCode, Event*);

    void addKeyboardEventListener();
    void removeKeyboardEventListener();

=======
    
    void onKeypadKeyPressed(EventKeyboard::KeyCode, Event*);
    
    void addKeyboardEventListener();
    void removeKeyboardEventListener();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    friend class Widget;
private:
    EventListenerKeyboard* _keyboardListener ;
    Widget* _firstFocusedWidget ;
    bool _enableFocusNavigation ;
    const int _keyboardEventPriority;
};
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Widget::FocusNavigationController::~FocusNavigationController()
{
    this->removeKeyboardEventListener();
}

void Widget::FocusNavigationController::onKeypadKeyPressed(EventKeyboard::KeyCode  keyCode, Event *event)
{
    if (_enableFocusNavigation && _firstFocusedWidget)
    {
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_DOWN)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::DOWN, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_UP)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::UP, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_LEFT)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::LEFT, _firstFocusedWidget);
        }
        if (keyCode == EventKeyboard::KeyCode::KEY_DPAD_RIGHT)
        {
            _firstFocusedWidget = _firstFocusedWidget->findNextFocusedWidget(Widget::FocusDirection::RIGHT, _firstFocusedWidget);
        }
    }
}

void Widget::FocusNavigationController::enableFocusNavigation(bool flag)
{
    if (_enableFocusNavigation == flag)
        return;
<<<<<<< HEAD

    _enableFocusNavigation = flag;

=======
    
    _enableFocusNavigation = flag;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (flag)
        this->addKeyboardEventListener();
    else
        this->removeKeyboardEventListener();
}

void Widget::FocusNavigationController::setFirstFocsuedWidget(Widget* widget)
{
    _firstFocusedWidget = widget;
}

void Widget::FocusNavigationController::addKeyboardEventListener()
{
    if (nullptr == _keyboardListener)
    {
        _keyboardListener = EventListenerKeyboard::create();
        _keyboardListener->onKeyReleased = CC_CALLBACK_2(Widget::FocusNavigationController::onKeypadKeyPressed, this);
        EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithFixedPriority(_keyboardListener, _keyboardEventPriority);
    }
}

void Widget::FocusNavigationController::removeKeyboardEventListener()
{
    if (nullptr != _keyboardListener)
    {
        EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
        dispatcher->removeEventListener(_keyboardListener);
        _keyboardListener = nullptr;
    }
}

Widget* Widget::_focusedWidget = nullptr;
Widget::FocusNavigationController* Widget::_focusNavigationController = nullptr;
<<<<<<< HEAD

Widget::Widget():
_usingLayoutComponent(false),
_unifySize(false),
=======
    
Widget::Widget():
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_enabled(true),
_bright(true),
_touchEnabled(false),
_highlight(false),
<<<<<<< HEAD
_affectByClipping(false),
_ignoreSize(false),
_propagateTouchEvents(true),
_brightStyle(BrightStyle::NONE),
_sizeType(SizeType::ABSOLUTE),
_positionType(PositionType::ABSOLUTE),
_actionTag(0),
_customSize(Size::ZERO),
=======
_brightStyle(BrightStyle::NONE),
_touchBeganPosition(Vec2::ZERO),
_touchMovePosition(Vec2::ZERO),
_touchEndPosition(Vec2::ZERO),
_touchEventListener(nullptr),
_touchEventSelector(nullptr),
_actionTag(0),
_customSize(Size::ZERO),
_ignoreSize(false),
_affectByClipping(false),
_sizeType(SizeType::ABSOLUTE),
_sizePercent(Vec2::ZERO),
_positionType(PositionType::ABSOLUTE),
_positionPercent(Vec2::ZERO),
_reorderWidgetChildDirty(true),
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_hitted(false),
_touchListener(nullptr),
_flippedX(false),
_flippedY(false),
<<<<<<< HEAD
_layoutParameterType(LayoutParameter::Type::NONE),
_focused(false),
_focusEnabled(true),
_touchEventListener(nullptr),
_touchEventSelector(nullptr),
_ccEventCallback(nullptr),
_callbackType(""),
_callbackName("")
{

=======
_focused(false),
_focusEnabled(true),
_layoutParameterType(LayoutParameter::Type::NONE)
{
  
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Widget::~Widget()
{
    this->cleanupWidget();
}

void Widget::cleanupWidget()
{
    //clean up _touchListener
    _eventDispatcher->removeEventListener(_touchListener);
    CC_SAFE_RELEASE_NULL(_touchListener);
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    //cleanup focused widget and focus navigation controller
    if (_focusedWidget == this)
    {
        //delete
        CC_SAFE_DELETE(_focusNavigationController);
        _focusedWidget = nullptr;
    }

}

Widget* Widget::create()
{
<<<<<<< HEAD
    Widget* widget = new (std::nothrow) Widget();
=======
    Widget* widget = new Widget();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool Widget::init()
{
    if (ProtectedNode::init())
    {
        initRenderer();
        setBright(true);
        onFocusChanged = CC_CALLBACK_2(Widget::onFocusChange,this);
        onNextFocusedWidget = nullptr;
        this->setAnchorPoint(Vec2(0.5f, 0.5f));

        ignoreContentAdaptWithSize(true);

<<<<<<< HEAD
=======
        this->setCascadeColorEnabled(true);
        this->setCascadeOpacityEnabled(true);
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return true;
    }
    return false;
}

void Widget::onEnter()
{
<<<<<<< HEAD
    if (!_usingLayoutComponent)
        updateSizeAndPosition();
=======
    updateSizeAndPosition();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    ProtectedNode::onEnter();
}

void Widget::onExit()
{
    unscheduleUpdate();
    ProtectedNode::onExit();
}

void Widget::visit(Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
<<<<<<< HEAD
    if (_visible || !isVisitableByVisitingCamera())
=======
    if (_visible)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        adaptRenderers();
        ProtectedNode::visit(renderer, parentTransform, parentFlags);
    }
}

Widget* Widget::getWidgetParent()
{
    return dynamic_cast<Widget*>(getParent());
}

void Widget::setEnabled(bool enabled)
{
    _enabled = enabled;
}
<<<<<<< HEAD

void Widget::initRenderer()
{
}

LayoutComponent* Widget::getOrCreateLayoutComponent()
{
    auto layoutComponent = this->getComponent(__LAYOUT_COMPONENT_NAME);
    if (nullptr == layoutComponent)
    {
        LayoutComponent *component = LayoutComponent::create();
        this->addComponent(component);
        layoutComponent = component;
    }

    return (LayoutComponent*)layoutComponent;
}

void Widget::setContentSize(const cocos2d::Size &contentSize)
{
    ProtectedNode::setContentSize(contentSize);

    _customSize = contentSize;
    if (_unifySize)
    {
        //unify Size logic
    }
    else if (_ignoreSize)
    {
        _contentSize = getVirtualRendererSize();
    }
    if (!_usingLayoutComponent && _running)
=======
    
void Widget::initRenderer()
{
}
    
void Widget::setContentSize(const cocos2d::Size &contentSize)
{
    ProtectedNode::setContentSize(contentSize);
    
    _customSize = contentSize;
    if (_ignoreSize)
    {
        _contentSize = getVirtualRendererSize();
    }
    else
    {
        _contentSize = contentSize;
    }
    if (_running)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        Widget* widgetParent = getWidgetParent();
        Size pSize;
        if (widgetParent)
        {
            pSize = widgetParent->getContentSize();
        }
        else
        {
            pSize = _parent->getContentSize();
        }
        float spx = 0.0f;
        float spy = 0.0f;
        if (pSize.width > 0.0f)
        {
            spx = _customSize.width / pSize.width;
        }
        if (pSize.height > 0.0f)
        {
            spy = _customSize.height / pSize.height;
        }
<<<<<<< HEAD
        _sizePercent.set(spx, spy);
=======
        _sizePercent = Vec2(spx, spy);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
    onSizeChanged();
}

void Widget::setSize(const Size &size)
{
    this->setContentSize(size);
}

void Widget::setSizePercent(const Vec2 &percent)
{
<<<<<<< HEAD
    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();
        component->setUsingPercentContentSize(true);
        component->setPercentContentSize(percent);
        component->refreshLayout();
    }
    else
    {
        _sizePercent = percent;
        Size cSize = _customSize;
        if (_running)
        {
            Widget* widgetParent = getWidgetParent();
            if (widgetParent)
            {
                cSize = Size(widgetParent->getContentSize().width * percent.x, widgetParent->getContentSize().height * percent.y);
            }
            else
            {
                cSize = Size(_parent->getContentSize().width * percent.x, _parent->getContentSize().height * percent.y);
            }
        }
        if (_ignoreSize)
        {
            this->setContentSize(getVirtualRendererSize());
        }
        else
        {
            this->setContentSize(cSize);
        }
        _customSize = cSize;
    }
=======
    _sizePercent = percent;
    Size cSize = _customSize;
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        if (widgetParent)
        {
            cSize = Size(widgetParent->getContentSize().width * percent.x , widgetParent->getContentSize().height * percent.y);
        }
        else
        {
            cSize = Size(_parent->getContentSize().width * percent.x , _parent->getContentSize().height * percent.y);
        }
    }
    if (_ignoreSize)
    {
        this->setContentSize(getVirtualRendererSize());
    }
    else
    {
        this->setContentSize(cSize);
    }
    _customSize = cSize;
    onSizeChanged();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::updateSizeAndPosition()
{
    Size pSize = _parent->getContentSize();
<<<<<<< HEAD

    updateSizeAndPosition(pSize);
}

=======
    
    updateSizeAndPosition(pSize);
}
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Widget::updateSizeAndPosition(const cocos2d::Size &parentSize)
{
    switch (_sizeType)
    {
        case SizeType::ABSOLUTE:
        {
            if (_ignoreSize)
            {
                this->setContentSize(getVirtualRendererSize());
            }
            else
            {
                this->setContentSize(_customSize);
            }
            float spx = 0.0f;
            float spy = 0.0f;
            if (parentSize.width > 0.0f)
            {
                spx = _customSize.width / parentSize.width;
            }
            if (parentSize.height > 0.0f)
            {
                spy = _customSize.height / parentSize.height;
            }
<<<<<<< HEAD
            _sizePercent.set(spx, spy);
=======
            _sizePercent = Vec2(spx, spy);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        }
        case SizeType::PERCENT:
        {
            Size cSize = Size(parentSize.width * _sizePercent.x , parentSize.height * _sizePercent.y);
            if (_ignoreSize)
            {
                this->setContentSize(getVirtualRendererSize());
            }
            else
            {
                this->setContentSize(cSize);
            }
            _customSize = cSize;
            break;
        }
        default:
            break;
    }
<<<<<<< HEAD

    //update position & position percent
=======
    onSizeChanged();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Vec2 absPos = getPosition();
    switch (_positionType)
    {
        case PositionType::ABSOLUTE:
        {
            if (parentSize.width <= 0.0f || parentSize.height <= 0.0f)
            {
<<<<<<< HEAD
                _positionPercent.setZero();
            }
            else
            {
                _positionPercent.set(absPos.x / parentSize.width, absPos.y / parentSize.height);
=======
                _positionPercent = Vec2::ZERO;
            }
            else
            {
                _positionPercent = Vec2(absPos.x / parentSize.width, absPos.y / parentSize.height);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
            break;
        }
        case PositionType::PERCENT:
        {
<<<<<<< HEAD
            absPos.set(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
=======
            absPos = Vec2(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        }
        default:
            break;
    }
    setPosition(absPos);
}

void Widget::setSizeType(SizeType type)
{
    _sizeType = type;
<<<<<<< HEAD

    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();

        if (_sizeType == Widget::SizeType::PERCENT)
        {
            component->setUsingPercentContentSize(true);
        }
        else
        {
            component->setUsingPercentContentSize(false);
        }
    }
}
=======
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Widget::SizeType Widget::getSizeType() const
{
    return _sizeType;
}

void Widget::ignoreContentAdaptWithSize(bool ignore)
{
<<<<<<< HEAD
    if (_unifySize)
    {
        this->setContentSize(_customSize);
        return;
    }
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_ignoreSize == ignore)
    {
        return;
    }
    _ignoreSize = ignore;
    if (_ignoreSize)
    {
        Size s = getVirtualRendererSize();
        this->setContentSize(s);
    }
    else
    {
        this->setContentSize(_customSize);
    }
<<<<<<< HEAD
=======
    onSizeChanged();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool Widget::isIgnoreContentAdaptWithSize() const
{
    return _ignoreSize;
}

const Size& Widget::getSize() const
{
    return this->getContentSize();
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
const Size& Widget::getCustomSize() const
{
    return _customSize;
}

<<<<<<< HEAD
const Vec2& Widget::getSizePercent()
{
    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();
        _sizePercent = component->getPercentContentSize();
    }

=======
const Vec2& Widget::getSizePercent() const
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return _sizePercent;
}

Vec2 Widget::getWorldPosition()const
{
    return convertToWorldSpace(Vec2(_anchorPoint.x * _contentSize.width, _anchorPoint.y * _contentSize.height));
}

Node* Widget::getVirtualRenderer()
{
    return this;
}

void Widget::onSizeChanged()
{
<<<<<<< HEAD
    if (!_usingLayoutComponent)
    {
        for (auto& child : getChildren())
        {
            Widget* widgetChild = dynamic_cast<Widget*>(child);
            if (widgetChild)
            {
                widgetChild->updateSizeAndPosition();
            }
=======
    for (auto& child : getChildren())
    {
        Widget* widgetChild = dynamic_cast<Widget*>(child);
        if (widgetChild)
        {
            widgetChild->updateSizeAndPosition();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
    }
}

<<<<<<< HEAD
Size Widget::getVirtualRendererSize() const
{
    return _contentSize;
}

void Widget::updateContentSizeWithTextureSize(const cocos2d::Size &size)
{
    if (_unifySize)
    {
        this->setContentSize(size);
        return;
    }
=======
const Size& Widget::getVirtualRendererSize() const
{
    return _contentSize;
}
    
void Widget::updateContentSizeWithTextureSize(const cocos2d::Size &size)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_ignoreSize)
    {
        this->setContentSize(size);
    }
    else
    {
        this->setContentSize(_customSize);
    }
<<<<<<< HEAD
=======
    onSizeChanged();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::setTouchEnabled(bool enable)
{
    if (enable == _touchEnabled)
    {
        return;
    }
    _touchEnabled = enable;
    if (_touchEnabled)
    {
        _touchListener = EventListenerTouchOneByOne::create();
        CC_SAFE_RETAIN(_touchListener);
        _touchListener->setSwallowTouches(true);
        _touchListener->onTouchBegan = CC_CALLBACK_2(Widget::onTouchBegan, this);
        _touchListener->onTouchMoved = CC_CALLBACK_2(Widget::onTouchMoved, this);
        _touchListener->onTouchEnded = CC_CALLBACK_2(Widget::onTouchEnded, this);
        _touchListener->onTouchCancelled = CC_CALLBACK_2(Widget::onTouchCancelled, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);
    }
    else
    {
        _eventDispatcher->removeEventListener(_touchListener);
        CC_SAFE_RELEASE_NULL(_touchListener);
    }
}

bool Widget::isTouchEnabled() const
{
    return _touchEnabled;
}

bool Widget::isHighlighted() const
{
    return _highlight;
}

void Widget::setHighlighted(bool hilight)
{
    if (hilight == _highlight)
    {
        return;
    }
    _highlight = hilight;
    if (_bright)
    {
        if (_highlight)
        {
            setBrightStyle(BrightStyle::HIGHLIGHT);
        }
        else
        {
            setBrightStyle(BrightStyle::NORMAL);
        }
    }
    else
    {
        onPressStateChangedToDisabled();
    }
}

void Widget::setBright(bool bright)
{
    _bright = bright;
    if (_bright)
    {
        _brightStyle = BrightStyle::NONE;
        setBrightStyle(BrightStyle::NORMAL);
    }
    else
    {
        onPressStateChangedToDisabled();
    }
}

void Widget::setBrightStyle(BrightStyle style)
{
    if (_brightStyle == style)
    {
        return;
    }
    _brightStyle = style;
    switch (_brightStyle)
    {
        case BrightStyle::NORMAL:
            onPressStateChangedToNormal();
            break;
        case BrightStyle::HIGHLIGHT:
            onPressStateChangedToPressed();
            break;
        default:
            break;
    }
}

void Widget::onPressStateChangedToNormal()
{

}

void Widget::onPressStateChangedToPressed()
{

}

void Widget::onPressStateChangedToDisabled()
{

}

<<<<<<< HEAD
void Widget::updateChildrenDisplayedRGBA()
{
    this->setColor(this->getColor());
    this->setOpacity(this->getOpacity());
}


=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Widget* Widget::getAncensterWidget(Node* node)
{
    if (nullptr == node)
    {
        return nullptr;
    }
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Node* parent = node->getParent();
    if (nullptr == parent)
    {
        return nullptr;
    }
    Widget* parentWidget = dynamic_cast<Widget*>(parent);
    if (parentWidget)
    {
        return parentWidget;
    }
    else
    {
        return this->getAncensterWidget(parent->getParent());
    }
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool Widget::isAncestorsVisible(Node* node)
{
    if (nullptr == node)
    {
        return true;
    }
    Node* parent = node->getParent();
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (parent && !parent->isVisible())
    {
        return false;
    }
    return this->isAncestorsVisible(parent);
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool Widget::isAncestorsEnabled()
{
    Widget* parentWidget = this->getAncensterWidget(this);
    if (parentWidget == nullptr)
    {
        return true;
    }
    if (parentWidget && !parentWidget->isEnabled())
    {
        return false;
    }
<<<<<<< HEAD

    return parentWidget->isAncestorsEnabled();
}

void Widget::setPropagateTouchEvents(bool isPropagate)
{
    _propagateTouchEvents = isPropagate;
}

bool Widget::isPropagateTouchEvents()const
{
    return _propagateTouchEvents;
}

void Widget::setSwallowTouches(bool swallow)
{
    if (_touchListener)
    {
        _touchListener->setSwallowTouches(swallow);
    }
}

bool Widget::isSwallowTouches()const
{
    if (_touchListener)
    {
        return _touchListener->isSwallowTouches();
    }
    return false;
}

=======
    
    return parentWidget->isAncestorsEnabled();
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool Widget::onTouchBegan(Touch *touch, Event *unusedEvent)
{
    _hitted = false;
    if (isVisible() && isEnabled() && isAncestorsEnabled() && isAncestorsVisible(this) )
    {
        _touchBeganPosition = touch->getLocation();
        if(hitTest(_touchBeganPosition) && isClippingParentContainsPoint(_touchBeganPosition))
        {
            _hitted = true;
        }
    }
    if (!_hitted)
    {
        return false;
    }
    setHighlighted(true);
<<<<<<< HEAD

    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::BEGAN, this, touch);
    }

    pushDownEvent();
    return true;
}

void Widget::propagateTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, cocos2d::Touch *touch)
{
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(event, sender, touch);
    }
=======
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(TouchEventType::BEGAN, this, touch);
    }
    pushDownEvent();
    return true;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::onTouchMoved(Touch *touch, Event *unusedEvent)
{
    _touchMovePosition = touch->getLocation();
<<<<<<< HEAD

    setHighlighted(hitTest(_touchMovePosition));

    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::MOVED, this, touch);
    }

=======
    setHighlighted(hitTest(_touchMovePosition));
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(TouchEventType::MOVED, this, touch);
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    moveEvent();
}

void Widget::onTouchEnded(Touch *touch, Event *unusedEvent)
{
    _touchEndPosition = touch->getLocation();
<<<<<<< HEAD

    /*
     * Propagate touch events to its parents
     */
    if (_propagateTouchEvents)
    {
        this->propagateTouchEvent(TouchEventType::ENDED, this, touch);
    }

    bool highlight = _highlight;
    setHighlighted(false);

=======
    
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(TouchEventType::ENDED, this, touch);
    }
    
    bool highlight = _highlight;
    setHighlighted(false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (highlight)
    {
        releaseUpEvent();
    }
    else
    {
        cancelUpEvent();
    }
}

void Widget::onTouchCancelled(Touch *touch, Event *unusedEvent)
{
    setHighlighted(false);
    cancelUpEvent();
}

void Widget::pushDownEvent()
{
<<<<<<< HEAD
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::BEGAN);
    }

=======
    if (_touchEventCallback) {
        _touchEventCallback(this, TouchEventType::BEGAN);
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_BEGAN);
    }
<<<<<<< HEAD
    this->release();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::moveEvent()
{
<<<<<<< HEAD
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::MOVED);
    }

=======
    if (_touchEventCallback) {
        _touchEventCallback(this, TouchEventType::MOVED);
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_MOVED);
    }
<<<<<<< HEAD
    this->release();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::releaseUpEvent()
{
<<<<<<< HEAD
    this->retain();
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::ENDED);
    }

=======
    
    if (_touchEventCallback) {
        _touchEventCallback(this, TouchEventType::ENDED);
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_ENDED);
    }
<<<<<<< HEAD

    if (_clickEventListener) {
        _clickEventListener(this);
    }
    this->release();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::cancelUpEvent()
{
<<<<<<< HEAD
    this->retain();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_touchEventCallback)
    {
        _touchEventCallback(this, TouchEventType::CANCELED);
    }
<<<<<<< HEAD

=======
   
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (_touchEventListener && _touchEventSelector)
    {
        (_touchEventListener->*_touchEventSelector)(this,TOUCH_EVENT_CANCELED);
    }
<<<<<<< HEAD
    this->release();
=======
   
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::addTouchEventListener(Ref *target, SEL_TouchEvent selector)
{
    _touchEventListener = target;
    _touchEventSelector = selector;
}
<<<<<<< HEAD

void Widget::addTouchEventListener(const ccWidgetTouchCallback& callback)
=======
    
void Widget::addTouchEventListener(Widget::ccWidgetTouchCallback callback)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    this->_touchEventCallback = callback;
}

<<<<<<< HEAD
void Widget::addClickEventListener(const ccWidgetClickCallback &callback)
{
    this->_clickEventListener = callback;
}

void Widget::addCCSEventListener(const ccWidgetEventCallback &callback)
{
    this->_ccEventCallback = callback;
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
bool Widget::hitTest(const Vec2 &pt)
{
    Vec2 nsp = convertToNodeSpace(pt);
    Rect bb;
    bb.size = _contentSize;
    if (bb.containsPoint(nsp))
    {
        return true;
    }
    return false;
}

bool Widget::isClippingParentContainsPoint(const Vec2 &pt)
{
    _affectByClipping = false;
    Widget* parent = getWidgetParent();
    Widget* clippingParent = nullptr;
    while (parent)
    {
        Layout* layoutParent = dynamic_cast<Layout*>(parent);
        if (layoutParent)
        {
            if (layoutParent->isClippingEnabled())
            {
                _affectByClipping = true;
                clippingParent = layoutParent;
                break;
            }
        }
        parent = parent->getWidgetParent();
    }

    if (!_affectByClipping)
    {
        return true;
    }


    if (clippingParent)
    {
        bool bRet = false;
        if (clippingParent->hitTest(pt))
        {
            bRet = true;
        }
        if (bRet)
        {
            return clippingParent->isClippingParentContainsPoint(pt);
        }
        return false;
    }
    return true;
}

void Widget::interceptTouchEvent(cocos2d::ui::Widget::TouchEventType event, cocos2d::ui::Widget *sender, Touch *touch)
{
    Widget* widgetParent = getWidgetParent();
    if (widgetParent)
    {
        widgetParent->interceptTouchEvent(event,sender,touch);
    }

}

void Widget::setPosition(const Vec2 &pos)
{
<<<<<<< HEAD
    if (!_usingLayoutComponent && _running)
=======
    if (_running)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        Widget* widgetParent = getWidgetParent();
        if (widgetParent)
        {
            Size pSize = widgetParent->getContentSize();
            if (pSize.width <= 0.0f || pSize.height <= 0.0f)
            {
<<<<<<< HEAD
                _positionPercent.setZero();
            }
            else
            {
                _positionPercent.set(pos.x / pSize.width, pos.y / pSize.height);
=======
                _positionPercent = Vec2::ZERO;
            }
            else
            {
                _positionPercent = Vec2(pos.x / pSize.width, pos.y / pSize.height);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
        }
    }
    ProtectedNode::setPosition(pos);
}

void Widget::setPositionPercent(const Vec2 &percent)
{
<<<<<<< HEAD
    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();
        component->setPositionPercentX(percent.x);
        component->setPositionPercentY(percent.y);
        component->refreshLayout();
    }
    else
    {
        _positionPercent = percent;
        if (_running)
        {
            Widget* widgetParent = getWidgetParent();
            if (widgetParent)
            {
                Size parentSize = widgetParent->getContentSize();
                Vec2 absPos(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
                setPosition(absPos);
            }
=======
    _positionPercent = percent;
    if (_running)
    {
        Widget* widgetParent = getWidgetParent();
        if (widgetParent)
        {
            Size parentSize = widgetParent->getContentSize();
            Vec2 absPos = Vec2(parentSize.width * _positionPercent.x, parentSize.height * _positionPercent.y);
            setPosition(absPos);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
    }
}

<<<<<<< HEAD
const Vec2& Widget::getPositionPercent(){

    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();
        float percentX = component->getPositionPercentX();
        float percentY = component->getPositionPercentY();

        _positionPercent.set(percentX, percentY);
    }
=======
const Vec2& Widget::getPositionPercent()const{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return _positionPercent;
}

void Widget::setPositionType(PositionType type)
{
    _positionType = type;
<<<<<<< HEAD

    if (_usingLayoutComponent)
    {
        auto component = this->getOrCreateLayoutComponent();
        if (type == Widget::PositionType::ABSOLUTE)
        {
            component->setPositionPercentXEnabled(false);
            component->setPositionPercentYEnabled(false);
        }
        else
        {
            component->setPositionPercentXEnabled(true);
            component->setPositionPercentYEnabled(true);
        }
    }
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Widget::PositionType Widget::getPositionType() const
{
    return _positionType;
}

bool Widget::isBright() const
{
    return _bright;
}

bool Widget::isEnabled() const
{
    return _enabled;
}

float Widget::getLeftBoundary() const
{
    return getPosition().x - getAnchorPoint().x * _contentSize.width;
}

float Widget::getBottomBoundary() const
{
    return getPosition().y - getAnchorPoint().y * _contentSize.height;
}

float Widget::getRightBoundary() const
{
    return getLeftBoundary() + _contentSize.width;
}

float Widget::getTopBoundary() const
{
    return getBottomBoundary() + _contentSize.height;
}

const Vec2& Widget::getTouchBeganPosition()const
{
    return _touchBeganPosition;
}

const Vec2& Widget::getTouchMovePosition()const
{
    return _touchMovePosition;
}

const Vec2& Widget::getTouchEndPosition()const
{
    return _touchEndPosition;
}

void Widget::setLayoutParameter(LayoutParameter *parameter)
{
    if (!parameter)
    {
        return;
    }
    _layoutParameterDictionary.insert((int)parameter->getLayoutType(), parameter);
    _layoutParameterType = parameter->getLayoutType();
}

LayoutParameter* Widget::getLayoutParameter()const
{
    return dynamic_cast<LayoutParameter*>(_layoutParameterDictionary.at((int)_layoutParameterType));
}
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
LayoutParameter* Widget::getLayoutParameter(LayoutParameter::Type type)
{
    return dynamic_cast<LayoutParameter*>(_layoutParameterDictionary.at((int)type));
}

std::string Widget::getDescription() const
{
    return "Widget";
}

Widget* Widget::clone()
{
    Widget* clonedWidget = createCloneInstance();
    clonedWidget->copyProperties(this);
    clonedWidget->copyClonedWidgetChildren(this);
    return clonedWidget;
}

Widget* Widget::createCloneInstance()
{
    return Widget::create();
}

void Widget::copyClonedWidgetChildren(Widget* model)
{
    auto& modelChildren = model->getChildren();

    for (auto& subWidget : modelChildren)
    {
        Widget* child = dynamic_cast<Widget*>(subWidget);
        if (child)
        {
            addChild(child->clone());
        }
    }
}

<<<<<<< HEAD
GLProgramState* Widget::getNormalGLProgramState()const
{
    GLProgramState *glState = nullptr;
    glState = GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP);
    return glState;
}

GLProgramState* Widget::getGrayGLProgramState()const
{
    GLProgramState *glState = nullptr;
    glState = GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_GRAYSCALE);
    return glState;
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Widget::copySpecialProperties(Widget* model)
{

}

void Widget::copyProperties(Widget *widget)
{
    setEnabled(widget->isEnabled());
    setVisible(widget->isVisible());
    setBright(widget->isBright());
    setTouchEnabled(widget->isTouchEnabled());
    setLocalZOrder(widget->getLocalZOrder());
    setTag(widget->getTag());
    setName(widget->getName());
    setActionTag(widget->getActionTag());
    _ignoreSize = widget->_ignoreSize;
    this->setContentSize(widget->_contentSize);
    _customSize = widget->_customSize;
    _sizeType = widget->getSizeType();
    _sizePercent = widget->_sizePercent;
    _positionType = widget->_positionType;
    _positionPercent = widget->_positionPercent;
    setPosition(widget->getPosition());
    setAnchorPoint(widget->getAnchorPoint());
    setScaleX(widget->getScaleX());
    setScaleY(widget->getScaleY());
    setRotation(widget->getRotation());
    setRotationSkewX(widget->getRotationSkewX());
    setRotationSkewY(widget->getRotationSkewY());
    setFlippedX(widget->isFlippedX());
    setFlippedY(widget->isFlippedY());
    setColor(widget->getColor());
    setOpacity(widget->getOpacity());
    _touchEventCallback = widget->_touchEventCallback;
    _touchEventListener = widget->_touchEventListener;
    _touchEventSelector = widget->_touchEventSelector;
<<<<<<< HEAD
    _clickEventListener = widget->_clickEventListener;
    _focused = widget->_focused;
    _focusEnabled = widget->_focusEnabled;
    _propagateTouchEvents = widget->_propagateTouchEvents;

=======
    _focused = widget->_focused;
    _focusEnabled = widget->_focusEnabled;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    copySpecialProperties(widget);

    Map<int, LayoutParameter*>& layoutParameterDic = widget->_layoutParameterDictionary;
    for (auto iter = layoutParameterDic.begin(); iter != layoutParameterDic.end(); ++iter)
    {
        setLayoutParameter(iter->second->clone());
    }
<<<<<<< HEAD
}

    void Widget::setFlippedX(bool flippedX)
    {

        float realScale = this->getScaleX();
        _flippedX = flippedX;
        this->setScaleX(realScale);
    }

    void Widget::setFlippedY(bool flippedY)
    {
        float realScale = this->getScaleY();
        _flippedY = flippedY;
        this->setScaleY(realScale);
    }



    void Widget::setScaleX(float scaleX)
    {
        if (_flippedX) {
            scaleX = scaleX * -1;
        }
        Node::setScaleX(scaleX);
    }

    void Widget::setScaleY(float scaleY)
    {
        if (_flippedY) {
            scaleY = scaleY * -1;
        }
        Node::setScaleY(scaleY);
    }

    void Widget::setScale(float scale)
    {
        this->setScaleX(scale);
        this->setScaleY(scale);
        this->setScaleZ(scale);
    }

    void Widget::setScale(float scaleX, float scaleY)
    {
        this->setScaleX(scaleX);
        this->setScaleY(scaleY);
    }

    float Widget::getScaleX()const
    {
        float originalScale = Node::getScaleX();
        if (_flippedX)
        {
            originalScale = originalScale * -1.0;
        }
        return originalScale;
    }

    float Widget::getScaleY()const
    {
        float originalScale = Node::getScaleY();
        if (_flippedY)
        {
            originalScale = originalScale * -1.0;
        }
        return originalScale;
    }

    float Widget::getScale()const
    {
        CCASSERT(this->getScaleX() == this->getScaleY(), "");
        return this->getScaleX();
    }
=======
    onSizeChanged();
}
    
void Widget::setFlippedX(bool flippedX)
{
    _flippedX = flippedX;
    updateFlippedX();
}

void Widget::setFlippedY(bool flippedY)
{
    _flippedY = flippedY;
    updateFlippedY();
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


/*temp action*/
void Widget::setActionTag(int tag)
{
	_actionTag = tag;
}

int Widget::getActionTag()const
{
	return _actionTag;
}
<<<<<<< HEAD

void Widget::setFocused(bool focus)
{
    _focused = focus;

=======
    
void Widget::setFocused(bool focus)
{
    _focused = focus;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    //make sure there is only one focusedWidget
    if (focus) {
        _focusedWidget = this;
        if (_focusNavigationController) {
            _focusNavigationController->setFirstFocsuedWidget(this);
        }
    }
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool Widget::isFocused()const
{
    return _focused;
}

void Widget::setFocusEnabled(bool enable)
{
    _focusEnabled = enable;
}

bool Widget::isFocusEnabled()const
{
    return _focusEnabled;
}

Widget* Widget::findNextFocusedWidget(FocusDirection direction,  Widget* current)
{
    if (nullptr == onNextFocusedWidget || nullptr == onNextFocusedWidget(direction) ) {
        if (this->isFocused() || dynamic_cast<Layout*>(current))
        {
            Node* parent = this->getParent();
<<<<<<< HEAD

=======
            
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            Layout* layout = dynamic_cast<Layout*>(parent);
            if (nullptr == layout)
            {
                //the outer layout's default behaviour is : loop focus
                if (dynamic_cast<Layout*>(current))
                {
                    return current->findNextFocusedWidget(direction, current);
                }
                return current;
            }
            else
            {
                Widget *nextWidget = layout->findNextFocusedWidget(direction, current);
                return nextWidget;
            }
        }
        else
        {
            return current;
        }
    }
    else
    {
        Widget *getFocusWidget = onNextFocusedWidget(direction);
        this->dispatchFocusEvent(this, getFocusWidget);
        return getFocusWidget;
    }
}

void Widget::dispatchFocusEvent(cocos2d::ui::Widget *widgetLoseFocus, cocos2d::ui::Widget *widgetGetFocus)
{
    //if the widgetLoseFocus doesn't get focus, it will use the previous focused widget instead
    if (widgetLoseFocus && !widgetLoseFocus->isFocused())
    {
        widgetLoseFocus = _focusedWidget;
    }
<<<<<<< HEAD

    if (widgetGetFocus != widgetLoseFocus)
    {

=======
    
    if (widgetGetFocus != widgetLoseFocus)
    {
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        if (widgetGetFocus)
        {
            widgetGetFocus->onFocusChanged(widgetLoseFocus, widgetGetFocus);
        }
<<<<<<< HEAD

=======
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        if (widgetLoseFocus)
        {
            widgetLoseFocus->onFocusChanged(widgetLoseFocus, widgetGetFocus);
        }
<<<<<<< HEAD

=======
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        EventFocus event(widgetLoseFocus, widgetGetFocus);
        auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->dispatchEvent(&event);
    }
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Widget::requestFocus()
{
    if (this == _focusedWidget)
    {
        return;
    }
<<<<<<< HEAD

    this->dispatchFocusEvent(_focusedWidget, this);
}

=======
    
    this->dispatchFocusEvent(_focusedWidget, this);
}
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Widget::onFocusChange(Widget* widgetLostFocus, Widget* widgetGetFocus)
{
    //only change focus when there is indeed a get&lose happens
    if (widgetLostFocus)
    {
        widgetLostFocus->setFocused(false);
    }
<<<<<<< HEAD

=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (widgetGetFocus)
    {
        widgetGetFocus->setFocused(true);
    }
}

Widget* Widget::getCurrentFocusedWidget()const
{
    return _focusedWidget;
}

void Widget::enableDpadNavigation(bool enable)
{
    if (enable)
    {
        if (nullptr == _focusNavigationController)
        {
<<<<<<< HEAD
            _focusNavigationController = new (std::nothrow) FocusNavigationController;
            if (_focusedWidget)
            {
=======
            _focusNavigationController = new FocusNavigationController;
            if (_focusedWidget) {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
                _focusNavigationController->setFirstFocsuedWidget(_focusedWidget);
            }
        }
    }
    else
    {
        CC_SAFE_DELETE(_focusNavigationController);
    }
<<<<<<< HEAD

    if (nullptr != _focusNavigationController)
    {
        _focusNavigationController->enableFocusNavigation(enable);
    }
}


bool Widget::isUnifySizeEnabled()const
{
    return _unifySize;
}

void Widget::setUnifySizeEnabled(bool enable)
{
    _unifySize = enable;
}


void Widget::setLayoutComponentEnabled(bool enable)
{
    _usingLayoutComponent = enable;
}

bool Widget::isLayoutComponentEnabled()const
{
    return _usingLayoutComponent;
}



}
=======
    _focusNavigationController->enableFocusNavigation(enable);
}


}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END
