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

#ifndef __UIPAGEVIEW_H__
#define __UIPAGEVIEW_H__

#include "ui/UILayout.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

/**
 * @addtogroup ui
 * @{
 */
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_BEGIN

namespace ui {

<<<<<<< HEAD
/**
 *PageView page turn event type.
 *@deprecated Use `PageView::EventType` instead.
 */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
typedef enum
{
    PAGEVIEW_EVENT_TURNING,
}PageViewEventType;

<<<<<<< HEAD
/**
 *A callback which would be called when a PageView turning event is happening.
 *@deprecated Use `PageView::ccPageViewCallback` instead.
 */
typedef void (Ref::*SEL_PageViewEvent)(Ref*, PageViewEventType);
#define pagevieweventselector(_SELECTOR)(SEL_PageViewEvent)(&_SELECTOR)

/**
 *@brief Layout manager that allows the user to flip left and right through pages of data.
 *
 */
class CC_GUI_DLL PageView : public Layout
=======
typedef void (Ref::*SEL_PageViewEvent)(Ref*, PageViewEventType);
#define pagevieweventselector(_SELECTOR)(SEL_PageViewEvent)(&_SELECTOR)

class PageView : public Layout
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
<<<<<<< HEAD
    /**
     * Page turn event tpye.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class EventType
    {
        TURNING
    };
    
<<<<<<< HEAD
    /**
     * Touch direction type.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class TouchDirection
    {
        LEFT,
        RIGHT
    };
    
<<<<<<< HEAD
    /**
     *PageView page turn event callback.
     */
    typedef std::function<void(Ref*,EventType)> ccPageViewCallback;

    /**
     * Default constructor
     * @js ctor
     * @lua new
=======
    typedef std::function<void(Ref*,EventType)> ccPageViewCallback;
    /**
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    PageView();
    
    /**
     * Default destructor
<<<<<<< HEAD
     * @js NA
     * @lua NA
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~PageView();
    
    /**
<<<<<<< HEAD
     * Create an empty PageView.
     *@return A PageView instance.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static PageView* create();
    
    /**
<<<<<<< HEAD
     * Add a widget as a page of PageView in a given index.
     *
     * @param widget    Widget to be added to pageview.
     * @param pageIdx   A given index.
     * @param forceCreate   If `forceCreate` is true and `widget` isn't exists, pageview would create a default page and add it.
=======
     * Add a widget to a page of pageview.
     *
     * @param widget    widget to be added to pageview.
     *
     * @param pageIdx   index of page.
     *
     * @param forceCreate   if force create and there is no page exsit, pageview would create a default page for adding widget.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void addWidgetToPage(Widget* widget, ssize_t pageIdx, bool forceCreate);
    
    /**
<<<<<<< HEAD
     * Insert a page into the end of PageView.
     *
     * @param page Page to be inserted.
=======
     * Push back a page to pageview.
     *
     * @param page    page to be added to pageview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void addPage(Layout* page);
    
    /**
<<<<<<< HEAD
     * Insert a page into PageView at a given index.
     *
     * @param page  Page to be inserted.
     * @param idx   A given index.
=======
     * Insert a page to pageview.
     *
     * @param page    page to be added to pageview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void insertPage(Layout* page, int idx);
    
    /**
<<<<<<< HEAD
     * Remove a page of PageView.
     *
     * @param page  Page to be removed.
=======
     * Remove a page of pageview.
     *
     * @param page    page which will be removed.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void removePage(Layout* page);

    /**
<<<<<<< HEAD
     * Remove a page at a given index of PageView.
     *
     * @param index  A given index.
     */
    void removePageAtIndex(ssize_t index);
    
    
    /**
     * @brief Remove all pages of the PageView.
     */
    void removeAllPages();
    
    /**
     * Scroll to a page with a given index.
     *
     * @param idx   A given index in the PageView.
=======
     * Remove a page at index of pageview.
     *
     * @param index    index of page.
     */
    void removePageAtIndex(ssize_t index);
    
    void removeAllPages();
    
    /**
     * scroll pageview to index.
     *
     * @param idx    index of page.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void scrollToPage(ssize_t idx);
    
    /**
<<<<<<< HEAD
     * Gets current displayed page index.
=======
     * Gets current page index.
     *
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return current page index.
     */
    ssize_t getCurPageIndex() const;
    
<<<<<<< HEAD
     
    /**
     * @brief Get all the pages in the PageView.
     * @return A vector of Layout pionters.
     */
    Vector<Layout*>& getPages();
    
    
    /**
     * @brief Get a page at a given index
     *
     * @param index A given index.
     * @return A layout pointer in PageView container.
     */
    Layout* getPage(ssize_t index);
    
    /**
     * Add a page turn callback to PageView, then when one page is turning, the callback will be called.
     *@deprecated Use `PageView::addEventListener` instead.
     *@param target A pointer of `Ref*` type.
     *@param selector A member function pointer with signature of `SEL_PageViewEvent`.
     */
    CC_DEPRECATED_ATTRIBUTE void addEventListenerPageView(Ref *target, SEL_PageViewEvent selector);

    
    /**
     * @brief Add a page turn callback to PageView, then when one page is turning, the callback will be called.
     *
     * @param callback A page turning callback.
     */
    void addEventListener(const ccPageViewCallback& callback);
    
    //override methods
=======
    
    Vector<Layout*>& getPages();
    
    Layout* getPage(ssize_t index);
    
    // event
    CC_DEPRECATED_ATTRIBUTE void addEventListenerPageView(Ref *target, SEL_PageViewEvent selector);
    void addEventListener(const ccPageViewCallback& callback);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual bool onTouchBegan(Touch *touch, Event *unusedEvent) override;
    virtual void onTouchMoved(Touch *touch, Event *unusedEvent) override;
    virtual void onTouchEnded(Touch *touch, Event *unusedEvent) override;
    virtual void onTouchCancelled(Touch *touch, Event *unusedEvent) override;
<<<<<<< HEAD
    virtual void update(float dt) override;
    virtual void setLayoutType(Type type) override{};
    virtual Type getLayoutType() const override{return Type::ABSOLUTE;};
    virtual std::string getDescription() const override;
    /**
     * @lua NA
     */
    virtual void onEnter() override;

    /**   
     *@brief If you don't specify the value, the pageView will turn page when scrolling at the half width of a page.
     *@param threshold  A threshold in float.
     */
    void setCustomScrollThreshold(float threshold);

    /**
     *@brief Query the custom scroll threshold of the PageView.
     *@return Custom scroll threshold in float.
     */
    float getCustomScrollThreshold()const;

    /**
     *@brief Set using user defined scroll page threshold or not.
     * If you set it to false, then the default scroll threshold is pageView.width / 2
     *@param flag True if using custom scroll threshold, false otherwise.
     */
    void setUsingCustomScrollThreshold(bool flag);

    /**
     *@brief Query whether use user defined scroll page threshold or not.
     *@return True if using custom scroll threshold, false otherwise.
     */
    bool isUsingCustomScrollThreshold()const;
=======
    
    //override "update" method of widget.
    virtual void update(float dt) override;
    /**
     * Sets LayoutType.
     *
     * @see LayoutType
     *
     * @param type LayoutType
     */
    virtual void setLayoutType(Type type) override{};
    
    /**
     * Gets LayoutType.
     *
     * @see LayoutType
     *
     * @return LayoutType
     */
    virtual Type getLayoutType() const override{return Type::ABSOLUTE;};
    
    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;

    virtual void onEnter() override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;

protected:

    Layout* createPage();
    float getPositionXByIndex(ssize_t idx)const;
    ssize_t getPageCount()const;

    void updateBoundaryPages();
    virtual bool scrollPages(float touchOffset);
    void movePages(float offset);
    void pageTurningEvent();
    void updateAllPagesSize();
    void updateAllPagesPosition();
    void autoScroll(float dt);

    virtual void handleMoveLogic(Touch *touch) ;
    virtual void handleReleaseLogic(Touch *touch) ;
<<<<<<< HEAD
    virtual void interceptTouchEvent(TouchEventType event, Widget* sender,Touch *touch) override;
=======
    virtual void interceptTouchEvent(TouchEventType event, Widget* sender,Touch *touch) ;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    
    virtual void onSizeChanged() override;
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
    virtual void copyClonedWidgetChildren(Widget* model) override;

    virtual void doLayout() override;

protected:
    enum class AutoScrollDirection
    {
        LEFT,
        RIGHT
    };
    bool _isAutoScrolling;
    float _autoScrollDistance;
    float _autoScrollSpeed;
    AutoScrollDirection _autoScrollDirection;
    
    ssize_t _curPageIdx;
    Vector<Layout*> _pages;

    TouchDirection _touchMoveDirection;
   
    Widget* _leftBoundaryChild;
    Widget* _rightBoundaryChild;
    
    float _leftBoundary;
    float _rightBoundary;
<<<<<<< HEAD
    float _customScrollThreshold;
    bool _usingCustomScrollThreshold;

=======
   
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    float _childFocusCancelOffset;

    Ref* _pageViewEventListener;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif
    SEL_PageViewEvent _pageViewEventSelector;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif
    ccPageViewCallback _eventCallback;
};

}
NS_CC_END
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__PageView__) */
