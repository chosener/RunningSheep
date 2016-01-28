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

#ifndef __cocos2d_libs__CCAccelerometerListener__
#define __cocos2d_libs__CCAccelerometerListener__

#include "base/CCEventListener.h"
#include "base/ccTypes.h"

<<<<<<< HEAD
/**
 * @addtogroup base
 * @{
 */

NS_CC_BEGIN

/** @class EventListenerAcceleration
 * @brief Acceleration event listener.
 * @js NA
 */
class CC_DLL EventListenerAcceleration : public EventListener
=======
NS_CC_BEGIN

class EventListenerAcceleration : public EventListener
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
public:
    static const std::string LISTENER_ID;
    
<<<<<<< HEAD
    /** Create a acceleration EventListener.
     *
     * @param callback The acceleration callback method.
     * @return An autoreleased EventListenerAcceleration object.
     */
    static EventListenerAcceleration* create(const std::function<void(Acceleration*, Event*)>& callback);
    
    /** Destructor.
     */
=======
    static EventListenerAcceleration* create(const std::function<void(Acceleration*, Event*)>& callback);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ~EventListenerAcceleration();
    
    /// Overrides
    virtual EventListenerAcceleration* clone() override;
    virtual bool checkAvailable() override;
<<<<<<< HEAD
    
CC_CONSTRUCTOR_ACCESS:
    EventListenerAcceleration();
    
    bool init(const std::function<void(Acceleration*, Event* event)>& callback);
    
private:
=======
private:
    EventListenerAcceleration();
    
    bool init(const std::function<void(Acceleration*, Event* event)>& callback);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    std::function<void(Acceleration*, Event*)> onAccelerationEvent;
    
    friend class LuaEventListenerAcceleration;
};

NS_CC_END

<<<<<<< HEAD
// end of base group
/// @}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif /* defined(__cocos2d_libs__CCAccelerometerListener__) */
