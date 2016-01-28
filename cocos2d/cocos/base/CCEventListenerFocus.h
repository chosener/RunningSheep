/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 Copyright (c) 2014 Chukong Technologies Inc.
 
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

#ifndef __cocos2d_libs__CCEventListenerFocus__
#define __cocos2d_libs__CCEventListenerFocus__

<<<<<<< HEAD
#include "base/CCEventListener.h"

/**
 * @addtogroup base
 * @{
 */
=======
#include "CCEventListener.h"

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

namespace ui {
    class Widget;
}

<<<<<<< HEAD
/** @class EventListenerFocus
 * @brief Focus event listener.
 */
class CC_DLL EventListenerFocus : public EventListener
{
public:
    static const std::string LISTENER_ID;
    
    /** Create a focus event listener.
     *
     * @return An autoreleased EventListenerFocus object.
     */
    static EventListenerFocus* create();
    
    /** Destructor.
     * @js NA
     */
=======
class EventListenerFocus : public EventListener
{
public:
    static const std::string LISTENER_ID;
    static EventListenerFocus* create();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ~EventListenerFocus();
    
    /// Overrides
    virtual EventListenerFocus* clone() override;
    virtual bool checkAvailable() override;
    //
    
public:
    std::function<void(ui::Widget*, ui::Widget*)> onFocusChanged;
    
<<<<<<< HEAD
CC_CONSTRUCTOR_ACCESS:
=======
private:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    EventListenerFocus();
    bool init();
    
    friend class EventDispatcher;
};

<<<<<<< HEAD
NS_CC_END

// end of base group
/// @}
=======


NS_CC_END
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__cocos2d_libs__CCEventListenerFocus__) */
