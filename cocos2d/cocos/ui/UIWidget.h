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

#ifndef __UIWIDGET_H__
#define __UIWIDGET_H__

<<<<<<< HEAD
#include "2d/CCProtectedNode.h"
#include "ui/UILayoutParameter.h"
#include "ui/GUIDefine.h"
#include "ui/GUIExport.h"
#include "base/CCMap.h"

/**
 * @addtogroup ui
 * @{
 */
=======
#include "ui/CCProtectedNode.h"
#include "ui/UILayoutParameter.h"
#include "ui/GUIDefine.h"
#include "base/CCMap.h"

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_BEGIN

class EventListenerTouchOneByOne;


namespace ui {
<<<<<<< HEAD
    class LayoutComponent;

/**
 * Touch event type.
 *@deprecated use `Widget::TouchEventType` instead
 */
=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
typedef enum
{
    TOUCH_EVENT_BEGAN,
    TOUCH_EVENT_MOVED,
    TOUCH_EVENT_ENDED,
    TOUCH_EVENT_CANCELED
}TouchEventType;
    
<<<<<<< HEAD
/**
 * Touch event callback.
 *@deprecated use `Widget::ccWidgetTouchCallback` instead
 */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
typedef void (Ref::*SEL_TouchEvent)(Ref*,TouchEventType);
#define toucheventselector(_SELECTOR) (SEL_TouchEvent)(&_SELECTOR)


<<<<<<< HEAD
=======
/**
*   @js NA
*   @lua NA
*/

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#ifdef ABSOLUTE
#undef ABSOLUTE
#endif
#endif

<<<<<<< HEAD
/**
 *@brief Base class for all ui widgets.
 * This class inherent from `ProtectedNode` and `LayoutParameterProtocol`.
 * If you want to implements your own ui widget, you should subclass it.
 */
class CC_GUI_DLL Widget : public ProtectedNode, public LayoutParameterProtocol
{
public:
    /**
     * Widget focus direction.
     */
=======

class Widget : public ProtectedNode, public LayoutParameterProtocol
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class FocusDirection
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    
<<<<<<< HEAD
    /**
     * Widget position type for layout.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class PositionType
    {
        ABSOLUTE,
        PERCENT
    };
    
<<<<<<< HEAD
    /**
     * Widget size type for layout.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class SizeType
    {
        ABSOLUTE,
        PERCENT
    };
    
<<<<<<< HEAD
    /**
     * Touch event type.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class TouchEventType
    {
        BEGAN,
        MOVED,
        ENDED,
        CANCELED
    };
    
<<<<<<< HEAD
    /**
     * Texture resource type.
     * - LOCAL:  It means the texture is loaded from image.
     * - PLIST: It means the texture is loaded from texture atlas.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class TextureResType
    {
        LOCAL = 0,
        PLIST = 1
    };
    
<<<<<<< HEAD
    /**
     * Widget bright style.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class BrightStyle
    {
        NONE = -1,
        NORMAL,
        HIGHLIGHT
    };

    
<<<<<<< HEAD
    /**
     * Widget touch event callback.
     */
    typedef std::function<void(Ref*,Widget::TouchEventType)> ccWidgetTouchCallback;
    /**
     * Widget click event callback.
     */
    typedef std::function<void(Ref*)> ccWidgetClickCallback;
    /**
     * Widget custom event callback.
     * It is mainly used together with Cocos Studio.
     */
    typedef std::function<void(Ref*, int)> ccWidgetEventCallback;
    /**
     * Default constructor
     * @js ctor
     * @lua new
=======
    typedef std::function<void(Ref*,Widget::TouchEventType)> ccWidgetTouchCallback;
    /**
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    Widget(void);
    
    /**
     * Default destructor
<<<<<<< HEAD
     * @js NA
     * @lua NA
     */
    virtual ~Widget();
    /**
     * Create and return a empty Widget instance pointer.
=======
     */
    virtual ~Widget();
    /**
     * Allocates and initializes a widget.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static Widget* create();

    /**
     * Sets whether the widget is enabled
     * 
     * true if the widget is enabled, widget may be touched , false if the widget is disabled, widget cannot be touched.
     *
<<<<<<< HEAD
     * Note: If you want to change the widget's appearance  to disabled state, you should also call  `setBright(false)`.
     *
     * The default value is true, a widget is default to enable touch.
     *
     * @param enabled Set to true to enable touch, false otherwise.
=======
     * The default value is true, a widget is default to enabled
     *
     * @param enabled
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setEnabled(bool enabled);

    /**
<<<<<<< HEAD
     * Determines if the widget is enabled or not.
=======
     * Determines if the widget is enabled
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @return true if the widget is enabled, false if the widget is disabled.
     */
    bool isEnabled() const;

    /**
     * Sets whether the widget is bright
     *
     * The default value is true, a widget is default to bright
     *
<<<<<<< HEAD
     * @param bright   true if the widget is bright, false if the widget is dark.
=======
     * @param visible   true if the widget is bright, false if the widget is dark.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setBright(bool bright);

    /**
     * Determines if the widget is bright
     *
     * @return true if the widget is bright, false if the widget is dark.
     */
    bool isBright() const;

    /**
<<<<<<< HEAD
     * Sets whether the widget is touch enabled.
     *
     * The default value is false, a widget is default to touch disabled.
     *
     * @param enabled   True if the widget is touch enabled, false if the widget is touch disabled.
=======
     * Sets whether the widget is touch enabled
     *
     * The default value is false, a widget is default to touch disabled
     *
     * @param visible   true if the widget is touch enabled, false if the widget is touch disabled.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setTouchEnabled(bool enabled);

    /**
     * To set the bright style of widget.
     *
     * @see BrightStyle
     *
     * @param style   BrightStyle::NORMAL means the widget is in normal state, BrightStyle::HIGHLIGHT means the widget is in highlight state.
     */
    void setBrightStyle(BrightStyle style);

    /**
     * Determines if the widget is touch enabled
     *
     * @return true if the widget is touch enabled, false if the widget is touch disabled.
     */
    bool isTouchEnabled() const;

    /**
     * Determines if the widget is highlighted
     *
     * @return true if the widget is highlighted, false if the widget is not hignlighted .
     */
    bool isHighlighted() const;

    /**
     * Sets whether the widget is hilighted
     *
     * The default value is false, a widget is default to not hilighted
     *
     * @param hilight   true if the widget is hilighted, false if the widget is not hilighted.
     */
    void setHighlighted(bool hilight);

    /**
     * Gets the left boundary position of this widget in parent's coordination system.
<<<<<<< HEAD
     * @deprecated use `getLeftBoundary` instead.
     * @return The left boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getLeftInParent(){return this->getLeftBoundary();}

    /**
     * Gets the left boundary position of this widget in parent's coordination system.
     * @return The left boundary position of this widget.
     */
=======
     *
     * @return The left boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getLeftInParent(){return this->getLeftBoundary();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    float getLeftBoundary() const;

    /**
     * Gets the bottom boundary position of this widget in parent's coordination system.
<<<<<<< HEAD
     * @deprecated use `getBottomBoundary` instead.
     * @return The bottom boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getBottomInParent(){return this->getBottomBoundary();}
    /**
     * Gets the bottom boundary position of this widget in parent's coordination system.
     * @return The bottom boundary position of this widget.
     */
=======
     *
     * @return The bottom boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getBottomInParent(){return this->getBottomBoundary();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    float getBottomBoundary() const;

    /**
     * Gets the right boundary position of this widget in parent's coordination system.
<<<<<<< HEAD
     * @deprecated use `getRightBoundary` instead.
     * @return The right boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getRightInParent(){return this->getRightBoundary();}
    /**
     * Gets the right boundary position of this widget in parent's coordination system.
     * @return The right boundary position of this widget.
     */
=======
     *
     * @return The right boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getRightInParent(){return this->getRightBoundary();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    float getRightBoundary() const;

    /**
     * Gets the top boundary position of this widget in parent's coordination system.
<<<<<<< HEAD
     * @deprecated use `getTopBoundary` instead.
     * @return The top boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getTopInParent(){return this->getTopBoundary();}
    /**
     * Gets the top boundary position of this widget in parent's coordination system.
     * @return The top boundary position of this widget.
     */
    float getTopBoundary() const;

    /**
     * @js NA
     */
    virtual void visit(cocos2d::Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;

    /**
     * Sets the touch event target/selector to the widget
     */
    CC_DEPRECATED_ATTRIBUTE void addTouchEventListener(Ref* target,SEL_TouchEvent selector);
    /**
     * Set a callback to touch vent listener.
     *@param callback  The callback in `ccWidgetEventCallback.`
     */
    void addTouchEventListener(const ccWidgetTouchCallback& callback);
    
    /**
     * Set a click event handler to the widget.
     * @param callback The callback in `ccWidgetClickCallback`.
     */
    void addClickEventListener(const ccWidgetClickCallback& callback);
    /**
     * Set a event handler to the widget in order to use cocostudio editor and framework
     * @param callback The callback in `ccWidgetEventCallback`.
     * @lua NA
     */
    virtual void addCCSEventListener(const ccWidgetEventCallback& callback);
    /**/
=======
     *
     * @return The top boundary position of this widget.
     */
    CC_DEPRECATED_ATTRIBUTE float getTopInParent(){return this->getTopBoundary();}
    float getTopBoundary() const;

    virtual void visit(cocos2d::Renderer *renderer, const Mat4 &parentTransform, uint32_t parentFlags) override;

    /**
     * Sets the touch event target/selector of the menu item
     */
    CC_DEPRECATED_ATTRIBUTE void addTouchEventListener(Ref* target,SEL_TouchEvent selector);
    void addTouchEventListener(ccWidgetTouchCallback callback);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Changes the position (x,y) of the widget in OpenGL coordinates
     *
<<<<<<< HEAD
     * Usually we use p(x,y) to compose a Vec2 object.
     * The original point (0,0) is at the left-bottom corner of screen.
     *
     * @param pos  The position (x,y) of the widget in OpenGL coordinates
=======
     * Usually we use p(x,y) to compose Vec2 object.
     * The original point (0,0) is at the left-bottom corner of screen.
     *
     * @param position  The position (x,y) of the widget in OpenGL coordinates
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setPosition(const Vec2 &pos) override;

    /**
     * Set the percent(x,y) of the widget in OpenGL coordinates
     *
     * @param percent  The percent (x,y) of the widget in OpenGL coordinates
     */
    void setPositionPercent(const Vec2 &percent);

    /**
     * Gets the percent (x,y) of the widget in OpenGL coordinates
     *
     * @see setPosition(const Vec2&)
     *
     * @return The percent (x,y) of the widget in OpenGL coordinates
     */
<<<<<<< HEAD
    const Vec2& getPositionPercent();
=======
    const Vec2& getPositionPercent()const;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Changes the position type of the widget
     *
<<<<<<< HEAD
     * @see `PositionType`
=======
     * @see PositionType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @param type  the position type of widget
     */
    void setPositionType(PositionType type);

    /**
     * Gets the position type of the widget
     *
<<<<<<< HEAD
     * @see `PositionType`
=======
     * @see PositionType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @return type  the position type of widget
     */
    PositionType getPositionType() const;

    /**
     * Sets whether the widget should be flipped horizontally or not.
     *
<<<<<<< HEAD
     * @param flippedX true if the widget should be flipped horizaontally, false otherwise.
=======
     * @param bFlippedX true if the widget should be flipped horizaontally, false otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setFlippedX(bool flippedX);

    /**
     * Returns the flag which indicates whether the widget is flipped horizontally or not.
     *
<<<<<<< HEAD
     * It not only flips the texture of the widget, but also the texture of the widget's children.
     * Also, flipping relies on widget's anchor point.
     * Internally, it just use setScaleX(-1) to flip the widget.
=======
     * It only flips the texture of the widget, and not the texture of the widget's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * widget->setScaleX(sprite->getScaleX() * -1);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @return true if the widget is flipped horizaontally, false otherwise.
     */
    virtual bool isFlippedX()const{return _flippedX;};

    /**
     * Sets whether the widget should be flipped vertically or not.
     *
<<<<<<< HEAD
     * @param flippedY true if the widget should be flipped vertically, flase otherwise.
=======
     * @param bFlippedY true if the widget should be flipped vertically, flase otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setFlippedY(bool flippedY);

    /**
     * Return the flag which indicates whether the widget is flipped vertically or not.
     *
<<<<<<< HEAD
     * It not only flips the texture of the widget, but also the texture of the widget's children.
     * Also, flipping relies on widget's anchor point.
     * Internally, it just use setScaleY(-1) to flip the widget.
=======
     * It only flips the texture of the widget, and not the texture of the widget's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * widget->setScaleY(widget->getScaleY() * -1);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @return true if the widget is flipped vertically, flase otherwise.
     */
    virtual bool isFlippedY()const{return _flippedY;};

    /** @deprecated Use isFlippedX() instead */
    CC_DEPRECATED_ATTRIBUTE bool isFlipX() { return isFlippedX(); };
    /** @deprecated Use setFlippedX() instead */
    CC_DEPRECATED_ATTRIBUTE void setFlipX(bool flipX) { setFlippedX(flipX); };
    /** @deprecated Use isFlippedY() instead */
    CC_DEPRECATED_ATTRIBUTE bool isFlipY() { return isFlippedY(); };
    /** @deprecated Use setFlippedY() instead */
    CC_DEPRECATED_ATTRIBUTE void setFlipY(bool flipY) { setFlippedY(flipY); };

<<<<<<< HEAD
    //override the setScale function of Node
    virtual void setScaleX(float scaleX) override;
    virtual void setScaleY(float scaleY) override;
    virtual void setScale(float scale) override;
    virtual void setScale(float scalex, float scaley) override;
    using Node::setScaleZ;
    virtual float getScaleX() const override;
    virtual float getScaleY() const override;
    virtual float getScale() const override;
    using Node::getScaleZ;
    
    /**
     * Checks a point if in parent's area.
     *
     * @param pt A point in `Vec2`.
     * @deprecated  use `isClippingParentContainsPoint` instead.
     * @return true if the point is in parent's area, flase otherwise.
     */
    CC_DEPRECATED_ATTRIBUTE bool clippingParentAreaContainPoint(const Vec2 &pt){return this->isClippingParentContainsPoint(pt);}

    /**
     * Checks a point if in parent's area.
     *
     * @param pt A point in `Vec2`.
     * @return true if the point is in parent's area, flase otherwise.
     */
    bool isClippingParentContainsPoint(const Vec2& pt);

    /**
     * Gets the touch began point of widget when widget is selected.
     * @deprecated use `getTouchBeganPosition` instead.
     * @return the touch began point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchStartPos()const{return this->getTouchBeganPosition();}
    /**
     * Gets the touch began point of widget when widget is selected.
     * @return the touch began point.
     */
=======
    /*
     * Checks a point if in parent's area.
     *
     * @param point
     *
     * @return true if the point is in parent's area, flase otherwise.
     */
    CC_DEPRECATED_ATTRIBUTE bool clippingParentAreaContainPoint(const Vec2 &pt){return this->isClippingParentContainsPoint(pt);}
    bool isClippingParentContainsPoint(const Vec2& pt);

    /*
     * Gets the touch began point of widget when widget is selected.
     *
     * @return the touch began point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchStartPos()const{return this->getTouchBeganPosition();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    const Vec2& getTouchBeganPosition()const;

    /*
     * Gets the touch move point of widget when widget is selected.
<<<<<<< HEAD
     * @deprecated use `getTouchMovePosition` instead.
     * @return the touch move point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchMovePos()const{ return this->getTouchMovePosition();}
    /*
     * Gets the touch move point of widget when widget is selected.
     * @return the touch move point.
     */
=======
     *
     * @return the touch move point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchMovePos()const{ return this->getTouchMovePosition();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    const Vec2& getTouchMovePosition()const;

    /*
     * Gets the touch end point of widget when widget is selected.
<<<<<<< HEAD
     * @deprecated use `getTouchEndPosition` instead.
     * @return the touch end point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchEndPos()const{return this->getTouchEndPosition();}
    /*
     * Gets the touch end point of widget when widget is selected.
     * @return the touch end point.
     */
=======
     *
     * @return the touch end point.
     */
    CC_DEPRECATED_ATTRIBUTE const Vec2& getTouchEndPos()const{return this->getTouchEndPosition();}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    const Vec2& getTouchEndPosition()const;

    /**
     * Changes the size that is widget's size
<<<<<<< HEAD
     * @deprecated use `setContentSize` instead.
     * @param size that is widget's size
     */
    CC_DEPRECATED_ATTRIBUTE virtual void setSize(const Size &size);
    /**
     * Changes the size that is widget's size
     * @param contentSize A content size in `Size`.
     */
=======
     *
     * @param size that is widget's size
     */
    CC_DEPRECATED_ATTRIBUTE virtual void setSize(const Size &size);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void setContentSize(const Size& contentSize) override;

    /**
     * Changes the percent that is widget's percent size
     *
     * @param percent that is widget's percent size
     */
    virtual void setSizePercent(const Vec2 &percent);

    /**
     * Changes the size type of widget.
     *
<<<<<<< HEAD
     * @see `SizeType`
=======
     * @see SizeType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @param type that is widget's size type
     */
    void setSizeType(SizeType type);

    /**
     * Gets the size type of widget.
     *
<<<<<<< HEAD
     * @see `SizeType`
=======
     * @see SizeType
     *
     * @param type that is widget's size type
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    SizeType getSizeType() const;

    /**
<<<<<<< HEAD
     * Get the size of widget
     *
     * @return Widget content size.
     */
    CC_DEPRECATED_ATTRIBUTE const Size& getSize() const;
    
    /**
     * Get the user defined widget size.
     *@return User defined size.
     */
    const Size& getCustomSize() const;
    
    /**
     * Get the content size of widget.
     * @warning This API exists mainly for keeping back compatibility.
     * @return 
     */
    virtual const Size& getLayoutSize() {return _contentSize;};

    /**
     * Get size percent of widget.
     *
     * @return Percent size.
     */
    const Vec2& getSizePercent();

    /**
     * Checks a point is in widget's content space.
     * This function is used for determining touch area of widget.
     *
     * @param pt The point in `Vec2`.
     * @return true if the point is in widget's content space, flase otherwise.
     */
    virtual bool hitTest(const Vec2 &pt);

    /**
     * A callback which will be called when touch began event is issued.
     *@param touch The touch info.
     *@param unusedEvent The touch event info.
     *@return True if user want to handle touches, false otherwise.
     */
    virtual bool onTouchBegan(Touch *touch, Event *unusedEvent);

    /**
     * A callback which will be called when touch moved event is issued.
     *@param touch The touch info.
     *@param unusedEvent The touch event info.
     */
    virtual void onTouchMoved(Touch *touch, Event *unusedEvent);

    /**
     * A callback which will be called when touch ended event is issued.
     *@param touch The touch info.
     *@param unusedEvent The touch event info.
     */
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent);

    /**
     * A callback which will be called when touch cancelled event is issued.
     *@param touch The touch info.
     *@param unusedEvent The touch event info.
     */
=======
     * Returns size of widget
     *
     * @return size
     */
    CC_DEPRECATED_ATTRIBUTE const Size& getSize() const;
    
    const Size& getCustomSize() const;
    
    virtual const Size& getLayoutSize() {return _contentSize;};

    /**
     * Returns size percent of widget
     *
     * @return size percent
     */
    const Vec2& getSizePercent() const;

    /**
     * Checks a point if is in widget's space
     *
     * @param point
     *
     * @return true if the point is in widget's space, flase otherwise.
     */
    virtual bool hitTest(const Vec2 &pt);

    virtual bool onTouchBegan(Touch *touch, Event *unusedEvent);
    virtual void onTouchMoved(Touch *touch, Event *unusedEvent);
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void onTouchCancelled(Touch *touch, Event *unusedEvent);

    /**
     * Sets a LayoutParameter to widget.
     *
     * @see LayoutParameter
<<<<<<< HEAD
     * @param parameter LayoutParameter pointer
=======
     *
     * @param LayoutParameter pointer
     *
     * @param type  Relative or Linear
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setLayoutParameter(LayoutParameter* parameter);

    /**
     * Gets LayoutParameter of widget.
     *
     * @see LayoutParameter
<<<<<<< HEAD
     * @return LayoutParameter
     */
    LayoutParameter* getLayoutParameter()const override;
    /**
     * Gets LayoutParameter of widget.
     *
     * @see LayoutParameter
     * @deprecated use `getLayoutParameter()` instead.
     * @param type  Relative or Linear
     * @return LayoutParameter
     */
=======
     *
     * @param type  Relative or Linear
     *
     * @return LayoutParameter
     */
    LayoutParameter* getLayoutParameter()const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE LayoutParameter* getLayoutParameter(LayoutParameter::Type type);


    /**
<<<<<<< HEAD
     * Toggle whether ignore user defined content size for widget.
     * Set true will ignore user defined content size which means 
     * the widget size is always equal to the return value of `getVirtualRendererSize`.
     *
     * @param ignore set member variabl _ignoreSize to ignore
=======
     *
     * Note: when you set _ignoreSize to true, no matther you call setContentSize or not, 
     * the widget size is always equal to the return value of the member function getVirtualRendererSize.
     *
     * @param ignore, set member variabl _ignoreSize to ignore
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void ignoreContentAdaptWithSize(bool ignore);

    /**
     * Query whether the widget ignores user deinfed content size or not
     *
<<<<<<< HEAD
     * @return True means ignore user defined content size, false otherwise.
=======
     * @return bool
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    bool isIgnoreContentAdaptWithSize() const;

    /**
<<<<<<< HEAD
     * Gets position of widget in world space.
     *
     * @return Position of widget in world space.
=======
     * Gets world position of widget.
     *
     * @return world position of widget.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    Vec2 getWorldPosition()const;

    /**
<<<<<<< HEAD
     * Gets the inner Renderer node of widget.
=======
     * Gets the Virtual Renderer of widget.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * For example, a button's Virtual Renderer is it's texture renderer.
     *
     * @return Node pointer.
     */
    virtual Node* getVirtualRenderer();


<<<<<<< HEAD
    /**
     *  Get the virtual renderer's size
     *@return Widget virtual renderer size.
     */
    virtual Size getVirtualRendererSize() const;
    

    /**
     * Returns the string representation of widget class name
     * @return get the class description.
     */
    virtual std::string getDescription() const override;

    /**
     * Create a new widget copy of the original one.
     * @return A cloned widget copy of original.
     */
    Widget* clone();
    /**
     * @lua NA
     */
    virtual void onEnter() override;
    
    /**
     * @lua NA
     */
    virtual void onExit() override;

    /**
     * Update all children's contents size and position recursively.
     * @see `updateSizeAndPosition(const Size&)`
     */
    void updateSizeAndPosition();

    /**
     * Update all children's contents size and position recursively.
     */
    void updateSizeAndPosition(const Size& parentSize);
    
    /**
     * Set the tag of action.
     *@param tag  A integer tag value.
     */
    void setActionTag(int tag);

    /**
     * Get the action tag.
     *@return Action tag.
     */
    int getActionTag()const;
    
    /**
     * @brief Allow widget touch events to propagate to its parents. Set false will disable propagation
     * @param isPropagate  True to allow propagation, false otherwise.
     * @since v3.3
     */
    void setPropagateTouchEvents(bool isPropagate);
    
    /**
     * Return whether the widget is propagate touch events to its parents or not
     * @return whether touch event propagation is allowed or not.
     * @since v3.3
     */
     
    bool isPropagateTouchEvents()const;
    
    /**
     * Toggle widget swallow touch option.
     * @brief Specify widget to swallow touches or not
     * @param swallow True to swallow touch, false otherwise.
     * @since v3.3
     */
    void setSwallowTouches(bool swallow);
    
    /**
     * Return whether the widget is swallowing touch or not
     * @return Whether touch is swallowed.
     * @since v3.3
     */
    bool isSwallowTouches()const;
    
    /**
     * Query whether widget is focused or not.
=======
    virtual const Size& getVirtualRendererSize() const;
    

    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;

    Widget* clone();

    virtual void onEnter() override;
    virtual void onExit() override;

    void updateSizeAndPosition();

    void updateSizeAndPosition(const Size& parentSize);
    
    /*temp action*/
    void setActionTag(int tag);
	int getActionTag()const;
    
    /**
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@return  whether the widget is focused or not
     */
    bool isFocused()const;
    
    /**
<<<<<<< HEAD
     * Toggle widget focus status.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@param focus  pass true to let the widget get focus or pass false to let the widget lose focus
     *@return void
     */
    void setFocused(bool focus);
    
    /**
<<<<<<< HEAD
     * Query widget's focus enable state.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@return true represent the widget could accept focus, false represent the widget couldn't accept focus
     */
    bool isFocusEnabled()const;
    
    /**
<<<<<<< HEAD
     * Allow widget to accept focus.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@param enable pass true/false to enable/disable the focus ability of a widget
     *@return void
     */
    void setFocusEnabled(bool enable);
    
    /**
     *  When a widget is in a layout, you could call this method to get the next focused widget within a specified direction. 
     *  If the widget is not in a layout, it will return itself
<<<<<<< HEAD
     *@param direction the direction to look for the next focused widget in a layout
=======
     *@param dir the direction to look for the next focused widget in a layout
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@param current  the current focused widget
     *@return the next focused widget in a layout
     */
    virtual Widget* findNextFocusedWidget(FocusDirection direction, Widget* current);
    
    /**
     * when a widget calls this method, it will get focus immediately.
     */
    void requestFocus();

    /**
<<<<<<< HEAD
     * Return a current focused widget in your UI scene.
     * No matter what widget object you call this method on , it will return you the exact one focused widget.
     * @param isWidget  if your set isWidget to true, it will return the _realFocusedWidget which is always a widget
     *                  otherwise, it will return a widget or a layout.
     * @deprecated use `getCurrentFocusedWidget` instead.
=======
     * no matter what widget object you call this method on , it will return you the exact one focused widget
     * @param isWidget  if your set isWidget to true, it will return the _realFocusedWidget which is always a widget
     *                  otherwise, it will return a widget or a layout
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    CC_DEPRECATED_ATTRIBUTE Widget* getCurrentFocusedWidget(bool isWidget){
        CC_UNUSED_PARAM(isWidget);
        return getCurrentFocusedWidget();
    }

<<<<<<< HEAD
    /**
     * Return a current focused widget in your UI scene.
     * No matter what widget object you call this method on , it will return you the exact one focused widget.
     */
    Widget* getCurrentFocusedWidget()const;

    /*
     *  Call this method with parameter true to enable the Android Dpad focus navigation feature
=======
    Widget* getCurrentFocusedWidget()const;
    /*
     *  call this method with parameter true to enable the Android Dpad focus navigation feature
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *@param enable  set true to enable dpad focus navigation, otherwise disenable dpad focus navigation
     */
    static void enableDpadNavigation(bool enable);

    /**
     * When a widget lose/get focus, this method will be called. Be Caution when you provide your own version, 
     * you must call widget->setFocused(true/false) to change the focus state of the current focused widget;
     */
    std::function<void(Widget*,Widget*)> onFocusChanged;
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /**
     * use this function to manually specify the next focused widget regards to each direction
     */
    std::function<Widget*(FocusDirection)> onNextFocusedWidget;
<<<<<<< HEAD
    
    /**
     *Toggle use unify size.
     *@param enable True to use unify size, false otherwise.
     *@return void
     */
    void setUnifySizeEnabled(bool enable);

    /**
     * Query whether unify size enable state. 
     *@return true represent the widget use Unify Size, false represent the widget couldn't use Unify Size
     */
    bool isUnifySizeEnabled()const;

    /**
     * Set callback name.
     *@param callbackName A string representation of callback name.
     */
    void setCallbackName(const std::string& callbackName) { _callbackName = callbackName; }


    /**
     * Query callback name.
     *@return The callback name.
     */
    const std::string& getCallbackName() const{ return _callbackName; }
    
    /**
     * Set callback type.
     * @param callbackType A string representation of callback type.
     */
    void setCallbackType(const std::string& callbackType) { _callbackType = callbackType; }

    /**
     * Query callback type.
     *@return Callback type string.
     */
    const std::string& getCallbackType() const{ return _callbackType; }

    /**
     * Toggle layout component enable.
     *@param enable Layout Component of a widget
     *@return void
     */
    void setLayoutComponentEnabled(bool enable);

    /**
     * Query whether layout component is enabled or not. 
     *@return true represent the widget use Layout Component, false represent the widget couldn't use Layout Component.
     */
    bool isLayoutComponentEnabled()const;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:

    //initializes state of widget.
    virtual bool init() override;

    /*
<<<<<<< HEAD
     * @brief Sends the touch event to widget's parent, if a widget wants to handle touch event under another widget, 
     *        it must overide this function.
=======
     * Sends the touch event to widget's parent
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @param  event  the touch event type, it could be BEGAN/MOVED/CANCELED/ENDED
     * @param parent
     * @param point
     */
    virtual void interceptTouchEvent(TouchEventType event, Widget* sender, Touch *touch);
<<<<<<< HEAD
    
    /**
     *@brief Propagate touch events to its parents
     */
    void propagateTouchEvent(TouchEventType event, Widget* sender, Touch *touch);
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    friend class PageView;
    /**
     * This method is called when a focus change event happens
     *@param widgetLostFocus  The widget which lose its focus
     *@param widgetGetFocus  The widget whihc get its focus
     *@return void
     */
    void onFocusChange(Widget* widgetLostFocus, Widget* widgetGetFocus);
    
    /**
     * Dispatch a EventFocus through a EventDispatcher
     *@param widgetLoseFocus  The widget which lose its focus
     *@param widgetGetFocus he widget whihc get its focus
     *@return void
     */
    void  dispatchFocusEvent(Widget* widgetLoseFocus, Widget* widgetGetFocus);
    
protected:
<<<<<<< HEAD
    /**
     * Get a normal state GLProgramState
     *@since v3.4
     */
    
    GLProgramState* getNormalGLProgramState()const;
    
    /**
     * Get a disabled state GLProgramState
     *@since v3.4
     */
    GLProgramState* getGrayGLProgramState()const;
     
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    //call back function called when size changed.
    virtual void onSizeChanged();

    //initializes renderer of widget.
    virtual void initRenderer();

    //call back function called widget's state changed to normal.
    virtual void onPressStateChangedToNormal();
    //call back function called widget's state changed to selected.
    virtual void onPressStateChangedToPressed();
    //call back function called widget's state changed to dark.
    virtual void onPressStateChangedToDisabled();

    void pushDownEvent();
    void moveEvent();

    virtual void releaseUpEvent();
    virtual void cancelUpEvent();

<<<<<<< HEAD
    
    virtual void adaptRenderers(){};
    void updateChildrenDisplayedRGBA();
=======
    virtual void updateFlippedX(){};
    virtual void updateFlippedY(){};
    virtual void adaptRenderers(){};
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    void copyProperties(Widget* model);
    virtual Widget* createCloneInstance();
    virtual void copySpecialProperties(Widget* model);
    virtual void copyClonedWidgetChildren(Widget* model);
    
    Widget* getWidgetParent();
    void updateContentSizeWithTextureSize(const Size& size);
    
    bool isAncestorsEnabled();
    Widget* getAncensterWidget(Node* node);
    bool isAncestorsVisible(Node* node);

    void cleanupWidget();
<<<<<<< HEAD
    LayoutComponent* getOrCreateLayoutComponent();

protected:
    bool _usingLayoutComponent;
    bool _unifySize;
=======

protected:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool _enabled;
    bool _bright;
    bool _touchEnabled;
    bool _highlight;
<<<<<<< HEAD
    bool _affectByClipping;
    bool _ignoreSize;
    bool _propagateTouchEvents;
=======
    bool _reorderWidgetChildDirty;
    bool _affectByClipping;
    bool _ignoreSize;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    BrightStyle _brightStyle;
    SizeType _sizeType;
    PositionType _positionType;

    //used for search widget by action tag in UIHelper class
    int _actionTag;

    Size _customSize;

    Vec2 _sizePercent;
    Vec2 _positionPercent;

    bool _hitted;
    EventListenerTouchOneByOne* _touchListener;
    Vec2 _touchBeganPosition;
    Vec2 _touchMovePosition;
    Vec2 _touchEndPosition;

    bool _flippedX;
    bool _flippedY;

    //use map to enble switch back and forth for user layout parameters
    Map<int,LayoutParameter*> _layoutParameterDictionary;
    LayoutParameter::Type _layoutParameterType;

    bool _focused;
    bool _focusEnabled;
    /**
     * store the only one focued widget
     */
    static Widget *_focusedWidget;  //both layout & widget will be stored in this variable

    Ref*       _touchEventListener;
    #if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    #elif _MSC_VER >= 1400 //vs 2005 or higher
    #pragma warning (push)
    #pragma warning (disable: 4996)
    #endif
    SEL_TouchEvent    _touchEventSelector;
    #if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
    #pragma GCC diagnostic warning "-Wdeprecated-declarations"
    #elif _MSC_VER >= 1400 //vs 2005 or higher
    #pragma warning (pop)
    #endif
    ccWidgetTouchCallback _touchEventCallback;
<<<<<<< HEAD
    ccWidgetClickCallback _clickEventListener;
    ccWidgetEventCallback _ccEventCallback;
    
    std::string _callbackType;
    std::string _callbackName;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
private:
    class FocusNavigationController;
    static FocusNavigationController* _focusNavigationController;
};
}

NS_CC_END
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__Widget__) */
