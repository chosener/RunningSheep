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

#include "ui/UIListView.h"
#include "ui/UIHelper.h"
<<<<<<< HEAD
=======
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

namespace ui {
    
IMPLEMENT_CLASS_GUI_INFO(ListView)

ListView::ListView():
_model(nullptr),
_gravity(Gravity::CENTER_VERTICAL),
_itemsMargin(0.0f),
<<<<<<< HEAD
_curSelectedIndex(0),
_refreshViewDirty(true),
_listViewEventListener(nullptr),
_listViewEventSelector(nullptr),
=======
_listViewEventListener(nullptr),
_listViewEventSelector(nullptr),
_curSelectedIndex(0),
_refreshViewDirty(true),
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
_eventCallback(nullptr)
{
    this->setTouchEnabled(true);
}

ListView::~ListView()
{
    _listViewEventListener = nullptr;
    _listViewEventSelector = nullptr;
    _items.clear();
    CC_SAFE_RELEASE(_model);
}

ListView* ListView::create()
{
<<<<<<< HEAD
    ListView* widget = new (std::nothrow) ListView();
=======
    ListView* widget = new ListView();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (widget && widget->init())
    {
        widget->autorelease();
        return widget;
    }
    CC_SAFE_DELETE(widget);
    return nullptr;
}

bool ListView::init()
{
    if (ScrollView::init())
    {
        setLayoutType(Type::VERTICAL);
        return true;
    }
    return false;
}

void ListView::setItemModel(Widget *model)
{
<<<<<<< HEAD
    if (nullptr == model)
    {
        CCLOG("Can't set a nullptr to item model!");
=======
    if (!model)
    {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return;
    }
    CC_SAFE_RELEASE_NULL(_model);
    _model = model;
    CC_SAFE_RETAIN(_model);
}

void ListView::updateInnerContainerSize()
{
    switch (_direction)
    {
        case Direction::VERTICAL:
        {
            size_t length = _items.size();
            float totalHeight = (length - 1) * _itemsMargin;
            for (auto& item : _items)
            {
                totalHeight += item->getContentSize().height;
            }
            float finalWidth = _contentSize.width;
            float finalHeight = totalHeight;
            setInnerContainerSize(Size(finalWidth, finalHeight));
            break;
        }
        case Direction::HORIZONTAL:
        {
            size_t length = _items.size();
            float totalWidth = (length - 1) * _itemsMargin;
            for (auto& item : _items)
            {
                totalWidth += item->getContentSize().width;
            }
            float finalWidth = totalWidth;
            float finalHeight = _contentSize.height;
            setInnerContainerSize(Size(finalWidth, finalHeight));
            break;
        }
        default:
            break;
    }
}
<<<<<<< HEAD
    
void ListView::remedyVerticalLayoutParameter(LinearLayoutParameter* layoutParameter, ssize_t itemIndex)
{
    CCASSERT(nullptr != layoutParameter, "Layout parameter can't be nullptr!");
    
    switch (_gravity)
    {
        case Gravity::LEFT:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
            break;
        case Gravity::RIGHT:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
            break;
        case Gravity::CENTER_HORIZONTAL:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
            break;
        default:
            break;
    }
    
    if (0 == itemIndex)
    {
        layoutParameter->setMargin(Margin::ZERO);
    }
    else
    {
        layoutParameter->setMargin(Margin(0.0f, _itemsMargin, 0.0f, 0.0f));
    }
}
    
void ListView::remedyHorizontalLayoutParameter(LinearLayoutParameter* layoutParameter, ssize_t itemIndex)
{
    CCASSERT(nullptr != layoutParameter, "Layout parameter can't be nullptr!");
    
    switch (_gravity)
    {
        case Gravity::TOP:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::TOP);
            break;
        case Gravity::BOTTOM:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::BOTTOM);
            break;
        case Gravity::CENTER_VERTICAL:
            layoutParameter->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
            break;
        default:
            break;
    }
    if (0 == itemIndex)
    {
        layoutParameter->setMargin(Margin::ZERO);
    }
    else
    {
        layoutParameter->setMargin(Margin(_itemsMargin, 0.0f, 0.0f, 0.0f));
    }
}

void ListView::remedyLayoutParameter(Widget *item)
{
    CCASSERT(nullptr != item, "ListView Item can't be nullptr!");
    
    LinearLayoutParameter* linearLayoutParameter = (LinearLayoutParameter*)(item->getLayoutParameter());
    bool isLayoutParameterExists = true;
    if (!linearLayoutParameter)
    {
        linearLayoutParameter = LinearLayoutParameter::create();
        isLayoutParameterExists = false;
    }
    ssize_t itemIndex = getIndex(item);
    
    switch (_direction)
    {
        case Direction::VERTICAL:
        {
            this->remedyVerticalLayoutParameter(linearLayoutParameter, itemIndex);
=======

void ListView::remedyLayoutParameter(Widget *item)
{
    if (!item)
    {
        return;
    }
    switch (_direction) {
        case Direction::VERTICAL:
        {
            LinearLayoutParameter* llp = (LinearLayoutParameter*)(item->getLayoutParameter());
            if (!llp)
            {
                LinearLayoutParameter* defaultLp = LinearLayoutParameter::create();
                switch (_gravity) {
                    case Gravity::LEFT:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
                        break;
                    case Gravity::RIGHT:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
                        break;
                    case Gravity::CENTER_HORIZONTAL:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
                        break;
                    default:
                        break;
                }
                if (getIndex(item) == 0)
                {
                    defaultLp->setMargin(Margin::ZERO);
                }
                else
                {
                    defaultLp->setMargin(Margin(0.0f, _itemsMargin, 0.0f, 0.0f));
                }
                item->setLayoutParameter(defaultLp);
            }
            else
            {
                if (getIndex(item) == 0)
                {
                    llp->setMargin(Margin::ZERO);
                }
                else
                {
                    llp->setMargin(Margin(0.0f, _itemsMargin, 0.0f, 0.0f));
                }
                switch (_gravity) {
                    case Gravity::LEFT:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::LEFT);
                        break;
                    case Gravity::RIGHT:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::RIGHT);
                        break;
                    case Gravity::CENTER_HORIZONTAL:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_HORIZONTAL);
                        break;
                    default:
                        break;
                }
            }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        }
        case Direction::HORIZONTAL:
        {
<<<<<<< HEAD
            this->remedyHorizontalLayoutParameter(linearLayoutParameter, itemIndex);
=======
            LinearLayoutParameter* llp = (LinearLayoutParameter*)(item->getLayoutParameter());
            if (!llp)
            {
                LinearLayoutParameter* defaultLp = LinearLayoutParameter::create();
                switch (_gravity) {
                    case Gravity::TOP:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::TOP);
                        break;
                    case Gravity::BOTTOM:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::BOTTOM);
                        break;
                    case Gravity::CENTER_VERTICAL:
                        defaultLp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
                        break;
                    default:
                        break;
                }
                if (getIndex(item) == 0)
                {
                    defaultLp->setMargin(Margin::ZERO);
                }
                else
                {
                    defaultLp->setMargin(Margin(_itemsMargin, 0.0f, 0.0f, 0.0f));
                }
                item->setLayoutParameter(defaultLp);
            }
            else
            {
                if (getIndex(item) == 0)
                {
                    llp->setMargin(Margin::ZERO);
                }
                else
                {
                    llp->setMargin(Margin(_itemsMargin, 0.0f, 0.0f, 0.0f));
                }
                switch (_gravity) {
                    case Gravity::TOP:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::TOP);
                        break;
                    case Gravity::BOTTOM:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::BOTTOM);
                        break;
                    case Gravity::CENTER_VERTICAL:
                        llp->setGravity(LinearLayoutParameter::LinearGravity::CENTER_VERTICAL);
                        break;
                    default:
                        break;
                }
            }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            break;
        }
        default:
            break;
    }
<<<<<<< HEAD
    if (!isLayoutParameterExists)
    {
        item->setLayoutParameter(linearLayoutParameter);
    }
=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void ListView::pushBackDefaultItem()
{
<<<<<<< HEAD
    if (nullptr == _model)
=======
    if (!_model)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    Widget* newItem = _model->clone();
    remedyLayoutParameter(newItem);
    addChild(newItem);
    _refreshViewDirty = true;
}

void ListView::insertDefaultItem(ssize_t index)
{
<<<<<<< HEAD
    if (nullptr == _model)
=======
    if (!_model)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    Widget* newItem = _model->clone();
    
    _items.insert(index, newItem);
    ScrollView::addChild(newItem);

    remedyLayoutParameter(newItem);
    
    _refreshViewDirty = true;
}


void ListView::pushBackCustomItem(Widget* item)
{
    remedyLayoutParameter(item);
    addChild(item);
    _refreshViewDirty = true;
}
    
void ListView::addChild(cocos2d::Node *child, int zOrder, int tag)
{
    ScrollView::addChild(child, zOrder, tag);

    Widget* widget = dynamic_cast<Widget*>(child);
<<<<<<< HEAD
    if (nullptr != widget)
=======
    if (widget)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        _items.pushBack(widget);
    }
}
    
void ListView::addChild(cocos2d::Node *child)
{
    ListView::addChild(child, child->getLocalZOrder(), child->getName());
}

void ListView::addChild(cocos2d::Node *child, int zOrder)
{
    ListView::addChild(child, zOrder, child->getName());
}
 
void ListView::addChild(Node* child, int zOrder, const std::string &name)
{
    ScrollView::addChild(child, zOrder, name);
    
    Widget* widget = dynamic_cast<Widget*>(child);
<<<<<<< HEAD
    if (nullptr != widget)
=======
    if (widget)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        _items.pushBack(widget);
    }
}
    
void ListView::removeChild(cocos2d::Node *child, bool cleaup)
{
    Widget* widget = dynamic_cast<Widget*>(child);
<<<<<<< HEAD
    if (nullptr != widget)
    {
=======
    if (widget) {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        _items.eraseObject(widget);
    }
   
    ScrollView::removeChild(child, cleaup);
}
    
void ListView::removeAllChildren()
{
    this->removeAllChildrenWithCleanup(true);
}
    
void ListView::removeAllChildrenWithCleanup(bool cleanup)
{
    ScrollView::removeAllChildrenWithCleanup(cleanup);
    _items.clear();
}

void ListView::insertCustomItem(Widget* item, ssize_t index)
{
    _items.insert(index, item);
    ScrollView::addChild(item);

    remedyLayoutParameter(item);
    _refreshViewDirty = true;
}

void ListView::removeItem(ssize_t index)
{
    Widget* item = getItem(index);
<<<<<<< HEAD
    if (nullptr == item)
=======
    if (!item)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    removeChild(item, true);
    
    _refreshViewDirty = true;
}

void ListView::removeLastItem()
{
    removeItem(_items.size() -1);
}
    
void ListView::removeAllItems()
{
    removeAllChildren();
}

Widget* ListView::getItem(ssize_t index)const
{
    if (index < 0 || index >= _items.size())
    {
        return nullptr;
    }
    return _items.at(index);
}

Vector<Widget*>& ListView::getItems()
{
    return _items;
}

ssize_t ListView::getIndex(Widget *item) const
{
<<<<<<< HEAD
    if (nullptr == item)
=======
    if (!item)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return -1;
    }
    return _items.getIndex(item);
}

void ListView::setGravity(Gravity gravity)
{
    if (_gravity == gravity)
    {
        return;
    }
    _gravity = gravity;
    _refreshViewDirty = true;
}

void ListView::setItemsMargin(float margin)
{
    if (_itemsMargin == margin)
    {
        return;
    }
    _itemsMargin = margin;
    _refreshViewDirty = true;
}
    
float ListView::getItemsMargin()const
{
    return _itemsMargin;
}

void ListView::setDirection(Direction dir)
{
    switch (dir)
    {
<<<<<<< HEAD
        case Direction::NONE:
        case Direction::BOTH:
            break;
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        case Direction::VERTICAL:
            setLayoutType(Type::VERTICAL);
            break;
        case Direction::HORIZONTAL:
            setLayoutType(Type::HORIZONTAL);
            break;
<<<<<<< HEAD
=======
        case Direction::BOTH:
            return;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        default:
            return;
            break;
    }
    ScrollView::setDirection(dir);
}
    
void ListView::requestRefreshView()
{
    _refreshViewDirty = true;
}

void ListView::refreshView()
{
    ssize_t length = _items.size();
    for (int i=0; i<length; i++)
    {
        Widget* item = _items.at(i);
        item->setLocalZOrder(i);
        remedyLayoutParameter(item);
    }
    updateInnerContainerSize();
}
    
<<<<<<< HEAD
void ListView::forceDoLayout()
{
    if (_refreshViewDirty)
    {
        refreshView();
        _refreshViewDirty = false;
    }

    this->_innerContainer->forceDoLayout();
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void ListView::doLayout()
{
    Layout::doLayout();
    
    if (_refreshViewDirty)
    {
        refreshView();
        _refreshViewDirty = false;
    }
}
    
void ListView::addEventListenerListView(Ref *target, SEL_ListViewEvent selector)
{
    _listViewEventListener = target;
    _listViewEventSelector = selector;
}

    
void ListView::addEventListener(const ccListViewCallback& callback)
{
    _eventCallback = callback;
}
    
void ListView::selectedItemEvent(TouchEventType event)
{
<<<<<<< HEAD
    this->retain();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    switch (event)
    {
        case TouchEventType::BEGAN:
        {
            if (_listViewEventListener && _listViewEventSelector)
            {
                (_listViewEventListener->*_listViewEventSelector)(this, LISTVIEW_ONSELECTEDITEM_START);
            }
            if (_eventCallback) {
                _eventCallback(this,EventType::ON_SELECTED_ITEM_START);
            }
<<<<<<< HEAD
            if (_ccEventCallback)
            {
                _ccEventCallback(this, static_cast<int>(EventType::ON_SELECTED_ITEM_START));
            }
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        break;
        default:
        {
            if (_listViewEventListener && _listViewEventSelector)
            {
                (_listViewEventListener->*_listViewEventSelector)(this, LISTVIEW_ONSELECTEDITEM_END);
            }
            if (_eventCallback) {
                _eventCallback(this, EventType::ON_SELECTED_ITEM_END);
            }
<<<<<<< HEAD
            if (_ccEventCallback)
            {
                _ccEventCallback(this, static_cast<int>(EventType::ON_SELECTED_ITEM_END));
            }
        }
        break;
    }
    this->release();
=======
        }
        break;
    }

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}
    
void ListView::interceptTouchEvent(TouchEventType event, Widget *sender, Touch* touch)
{
    ScrollView::interceptTouchEvent(event, sender, touch);
    if (event != TouchEventType::MOVED)
    {
        Widget* parent = sender;
        while (parent)
        {
            if (parent && parent->getParent() == _innerContainer)
            {
                _curSelectedIndex = getIndex(parent);
                break;
            }
            parent = dynamic_cast<Widget*>(parent->getParent());
        }
        if (sender->isHighlighted()) {
            selectedItemEvent(event);
        }
    }
}
    
ssize_t ListView::getCurSelectedIndex() const
{
    return _curSelectedIndex;
}

void ListView::onSizeChanged()
{
    ScrollView::onSizeChanged();
    _refreshViewDirty = true;
}

std::string ListView::getDescription() const
{
    return "ListView";
}

Widget* ListView::createCloneInstance()
{
    return ListView::create();
}

void ListView::copyClonedWidgetChildren(Widget* model)
{
    auto& arrayItems = static_cast<ListView*>(model)->getItems();
    for (auto& item : arrayItems)
    {
        pushBackCustomItem(item->clone());
    }
}

void ListView::copySpecialProperties(Widget *widget)
{
    ListView* listViewEx = dynamic_cast<ListView*>(widget);
    if (listViewEx)
    {
        ScrollView::copySpecialProperties(widget);
        setItemModel(listViewEx->_model);
        setItemsMargin(listViewEx->_itemsMargin);
        setGravity(listViewEx->_gravity);
        _listViewEventListener = listViewEx->_listViewEventListener;
        _listViewEventSelector = listViewEx->_listViewEventSelector;
        _eventCallback = listViewEx->_eventCallback;
    }
}

}
NS_CC_END
