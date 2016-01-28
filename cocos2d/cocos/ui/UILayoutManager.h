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

#ifndef __cocos2d_libs__CCLayoutManager__
#define __cocos2d_libs__CCLayoutManager__

#include "base/CCRef.h"
#include "base/CCVector.h"
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
    
class LayoutProtocol;
class Widget;
class RelativeLayoutParameter;

<<<<<<< HEAD
/**
 *@brief Base class for managing layout.
 * All the concret layout manager should inherit from this class.
 */
class CC_GUI_DLL LayoutManager : public Ref
=======
class LayoutManager : public Ref
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
public:
    virtual ~LayoutManager(){};
    LayoutManager(){};
    
<<<<<<< HEAD
    /**
     * The interface does the actual layouting work.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void doLayout(LayoutProtocol *layout) = 0;
    
    friend class Layout;
};

<<<<<<< HEAD
/**
 *@brief Linear vertical layouting class.
 * Note: This class is used only by @see `Layout` class.
 * @lua NA
 * @js NA
 */
class CC_GUI_DLL LinearVerticalLayoutManager : public LayoutManager
=======
class LinearVerticalLayoutManager : public LayoutManager
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
private:
    LinearVerticalLayoutManager(){};
    virtual ~LinearVerticalLayoutManager(){};
    static LinearVerticalLayoutManager* create();
    virtual void doLayout(LayoutProtocol *layout) override;
    
    friend class Layout;
};

<<<<<<< HEAD
/**
 *@brief Linear horizontal layouting class.
 *Note: This class is used only by @see `Layout` class.
 * @lua NA
 * @js NA
 */
class CC_GUI_DLL LinearHorizontalLayoutManager : public LayoutManager
=======
class LinearHorizontalLayoutManager : public LayoutManager
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
private:
    LinearHorizontalLayoutManager(){};
    virtual ~LinearHorizontalLayoutManager(){};
    static LinearHorizontalLayoutManager* create();
    virtual void doLayout(LayoutProtocol *layout) override;
    
    friend class Layout;
};

<<<<<<< HEAD
/**
 *@brief Relative layouting class.
 *Note: This class is used only by `Layout` class.
 * @lua NA
 * @js NA
 */
class CC_GUI_DLL RelativeLayoutManager : public LayoutManager
=======
class RelativeLayoutManager : public LayoutManager
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
private:
    RelativeLayoutManager()
    :_unlayoutChildCount(0),
    _widget(nullptr),
    _finalPositionX(0.0f),
    _finalPositionY(0.0f),
    _relativeWidgetLP(nullptr)
    {}
    virtual ~RelativeLayoutManager(){};
    static RelativeLayoutManager* create();
    virtual void doLayout(LayoutProtocol *layout) override;
    
    Vector<Widget*> getAllWidgets(LayoutProtocol *layout);
    Widget* getRelativeWidget(Widget* widget);
    bool caculateFinalPositionWithRelativeWidget(LayoutProtocol *layout);
    void caculateFinalPositionWithRelativeAlign();
    
    ssize_t _unlayoutChildCount;
    Vector<Widget*> _widgetChildren;
    Widget* _widget;
    float _finalPositionX;
    float _finalPositionY;
    
    RelativeLayoutParameter* _relativeWidgetLP;
    
    friend class Layout;
};

}

NS_CC_END
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif /* defined(__cocos2d_libs__CCLayoutManager__) */
