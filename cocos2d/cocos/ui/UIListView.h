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


#ifndef __UILISTVIEW_H__
#define __UILISTVIEW_H__

#include "ui/UIScrollView.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

/**
 * @addtogroup ui
 * @{
 */
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_BEGIN

namespace ui{
    
<<<<<<< HEAD
/**
 * ListView click item event type.
 */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
typedef enum
{
    LISTVIEW_ONSELECTEDITEM_START,
    LISTVIEW_ONSELECTEDITEM_END
}ListViewEventType;

<<<<<<< HEAD
/**
 * A callback which would be called when a ListView item is clicked.
 *@deprecated Use `ccListViewCallback` instead.
 */
typedef void (Ref::*SEL_ListViewEvent)(Ref*,ListViewEventType);
#define listvieweventselector(_SELECTOR) (SEL_ListViewEvent)(&_SELECTOR)

/**
 *@brief ListView is a view group that displays a list of scrollable items.
 *The list items are inserted to the list by using `addChild` or  `insertDefaultItem`.
 * @warning The list item in ListView doesn't support cell reuse at the moment, if you have a large amount of data need to be displayed, use  `TableView` instead.
 * ListView is a subclass of  `ScrollView`, so it shares many features of ScrollView.
 */
class CC_GUI_DLL ListView : public ScrollView
{
 
    DECLARE_CLASS_GUI_INFO
public:
    /**
     * Gravity for docking elements in ListView.
     */
=======
typedef void (Ref::*SEL_ListViewEvent)(Ref*,ListViewEventType);
#define listvieweventselector(_SELECTOR) (SEL_ListViewEvent)(&_SELECTOR)

class ListView : public ScrollView
{
 
    DECLARE_CLASS_GUI_INFO
    
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class Gravity
    {
        LEFT,
        RIGHT,
        CENTER_HORIZONTAL,
        TOP,
        BOTTOM,
        CENTER_VERTICAL
    };
    
<<<<<<< HEAD
    /**
     * ListView element item click event.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class EventType
    {
        ON_SELECTED_ITEM_START,
        ON_SELECTED_ITEM_END
    };
    
<<<<<<< HEAD
    /**
     * ListView item click callback.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    typedef std::function<void(Ref*, EventType)> ccListViewCallback;
    
    /**
     * Default constructor
<<<<<<< HEAD
     * @js ctor
     * @lua new
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    ListView();
    
    /**
     * Default destructor
<<<<<<< HEAD
     * @js NA
     * @lua NA
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~ListView();
    
    /**
<<<<<<< HEAD
     * Create an empty ListView.
     *@return A ListView instance.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static ListView* create();
    
    /**
<<<<<<< HEAD
     * Set a item model for listview.
     *
     * When calling `pushBackDefaultItem`, the model will be used as a blueprint and new model copy will be inserted into ListView.
     * @param model  Model in `Widget*`.
=======
     * Sets a item model for listview
     *
     * A model will be cloned for adding default item.
     *
     * @param model  item model for listview
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setItemModel(Widget* model);
    
    /**
<<<<<<< HEAD
     * Insert a  a default item(create by a cloned model) at the end of the listview.
=======
     * Push back a default item(create by a cloned model) into listview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void pushBackDefaultItem();
    
    /**
<<<<<<< HEAD
     * Insert a default item(create by cloning model) into listview at a give index.
     *@param index  A index in ssize_t.
=======
     * Insert a default item(create by a cloned model) into listview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void insertDefaultItem(ssize_t index);
    
    /**
<<<<<<< HEAD
     * Insert a  custom item into the end of ListView.
     *@param item A item in `Widget*`.
     */
    void pushBackCustomItem(Widget* item);
    
    
    /**
     * @brief Insert a custom widget into ListView at a given index.
     *
     * @param item A widget pointer to be inserted.
     * @param index A given index in ssize_t.
=======
     * Push back custom item into listview.
     */
    void pushBackCustomItem(Widget* item);
    
    /**
     * Insert custom item into listview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void insertCustomItem(Widget* item, ssize_t index);
    
    /**
<<<<<<< HEAD
     *  Removes the last item of ListView.
=======
     *  Removes the last item of listview.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void removeLastItem();
    
    /**
<<<<<<< HEAD
     * Remove a item at given index.
     *
     * @param index A given index in ssize_t.
     */
    void removeItem(ssize_t index);
    
    
    /**
     * @brief Remove all items in current ListView.
     *
     
     */
    void removeAllItems();
    
    /**
     * Return a item at a given index.
     *
     * @param index A given index in ssize_t.
     * @return A widget instance.
=======
     * Removes a item whose index is same as the parameter.
     *
     * @param index of item.
     */
    void removeItem(ssize_t index);
    
    void removeAllItems();
    
    /**
     * Returns a item whose index is same as the parameter.
     *
     * @param index of item.
     *
     * @return the item widget.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    Widget* getItem(ssize_t index)const;
    
    /**
<<<<<<< HEAD
     * Return all items in a ListView.
     *@returns A vector of widget pointers.
=======
     * Returns the item container.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    Vector<Widget*>& getItems();
    
    /**
<<<<<<< HEAD
     * Return the index of specified widget.
     *
     * @param item  A widget pointer.
     * @return The index of a given widget in ListView.
=======
     * Returns the index of item.
     *
     * @param item  the item which need to be checked.
     *
     * @return the index of item.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    ssize_t getIndex(Widget* item) const;
    
    /**
<<<<<<< HEAD
     * Set the gravity of ListView.
     * @see `ListViewGravity`
=======
     * Changes the gravity of listview.
     * @see ListViewGravity
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setGravity(Gravity gravity);
    
    /**
<<<<<<< HEAD
     * Set the margin between each item in ListView.
=======
     * Changes the margin between each item.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @param margin
     */
    void setItemsMargin(float margin);
    
<<<<<<< HEAD
    
    /**
     * @brief Query margin between each item in ListView.
     *
     
     * @return A margin in float.
     */
    float getItemsMargin()const;
    
    //override methods
    virtual void forceDoLayout()override;
    virtual void doLayout() override;
=======
    float getItemsMargin()const;
    
    virtual void doLayout() override;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void addChild(Node* child)override;
    virtual void addChild(Node * child, int localZOrder)override;
    virtual void addChild(Node* child, int zOrder, int tag) override;
    virtual void addChild(Node* child, int zOrder, const std::string &name) override;
    virtual void removeAllChildren() override;
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;
<<<<<<< HEAD
    virtual void removeChild(Node* child, bool cleaup = true) override;
    
        
    /**
     * @brief Query current selected widget's idnex.
     *
     
     * @return A index of a selected item.
     */
    ssize_t getCurSelectedIndex() const;
    
    /**
     * Add a event click callback to ListView, then one item of Listview is clicked, the callback will be called.
     *@deprecated Use  `addEventListener` instead.
     *@param target A pointer of `Ref*` type.
     *@param selector A member function pointer with type of `SEL_ListViewEvent`.
     */
    CC_DEPRECATED_ATTRIBUTE void addEventListenerListView(Ref* target, SEL_ListViewEvent selector);

    /**
     * Add a event click callback to ListView, then one item of Listview is clicked, the callback will be called.
     *@param callback A callback function with type of `ccListViewCallback`.
     */
=======
	virtual void removeChild(Node* child, bool cleaup = true) override;
    
    ssize_t getCurSelectedIndex() const;
    
    CC_DEPRECATED_ATTRIBUTE void addEventListenerListView(Ref* target, SEL_ListViewEvent selector);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void addEventListener(const ccListViewCallback& callback);
    using ScrollView::addEventListener;

    /**
     * Changes scroll direction of scrollview.
     *
<<<<<<< HEAD
     *  Direction Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll.
     * @param dir Set the list view's scroll direction.
=======
     * @see Direction Direction::VERTICAL means vertical scroll, Direction::HORIZONTAL means horizontal scroll
     *
     * @param dir, set the list view's scroll direction
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setDirection(Direction dir) override;
    
    virtual std::string getDescription() const override;
    
<<<<<<< HEAD
    /**
     * @brief Refresh view and layout of ListView manually.
     * This method will mark ListView content as dirty and the content view will be refershed in the next frame.
     */
    void requestRefreshView();

    
    /**
     * @brief Refresh content view of ListView.
     */
=======
    void requestRefreshView();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void refreshView();

CC_CONSTRUCTOR_ACCESS:
    virtual bool init() override;
    
protected:
    
    void updateInnerContainerSize();
    void remedyLayoutParameter(Widget* item);
<<<<<<< HEAD
    void remedyVerticalLayoutParameter(LinearLayoutParameter* layoutParameter, ssize_t itemIndex);
    void remedyHorizontalLayoutParameter(LinearLayoutParameter* layoutParameter,ssize_t itemIndex);
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void onSizeChanged() override;
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
    virtual void copyClonedWidgetChildren(Widget* model) override;
    void selectedItemEvent(TouchEventType event);
    virtual void interceptTouchEvent(Widget::TouchEventType event,Widget* sender,Touch* touch) override;
protected:
    Widget* _model;
    
    Vector<Widget*> _items;
    
    Gravity _gravity;
    
    float _itemsMargin;
    
    ssize_t _curSelectedIndex;
    bool _refreshViewDirty;
    
    Ref*       _listViewEventListener;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (push)
#pragma warning (disable: 4996)
#endif
    SEL_ListViewEvent    _listViewEventSelector;
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#pragma GCC diagnostic warning "-Wdeprecated-declarations"
#elif _MSC_VER >= 1400 //vs 2005 or higher
#pragma warning (pop)
#endif
    ccListViewCallback _eventCallback;
};

}
NS_CC_END
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__ListView__) */
