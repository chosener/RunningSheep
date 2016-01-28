/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
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
#ifndef __AUTORELEASEPOOL_H__
#define __AUTORELEASEPOOL_H__

<<<<<<< HEAD
=======
#include <stack>
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include <vector>
#include <string>
#include "base/CCRef.h"

<<<<<<< HEAD
/**
 * @addtogroup base
 * @{
 */
NS_CC_BEGIN


/**
 * A pool for managing autorlease objects.
 * @js NA
 */
=======
NS_CC_BEGIN

/**
 * @addtogroup base_nodes
 * @{
 */

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
class CC_DLL AutoreleasePool
{
public:
    /**
<<<<<<< HEAD
     * @warning Don't create an autorelease pool in heap, create it in stack.
=======
     * @warn Don't create an auto release pool in heap, create it in stack.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    AutoreleasePool();
    
    /**
     * Create an autorelease pool with specific name. This name is useful for debugging.
<<<<<<< HEAD
     * @warning Don't create an autorelease pool in heap, create it in stack.
     * @js NA
     * @lua NA
     *
     * @param name The name of created autorelease pool.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    AutoreleasePool(const std::string &name);
    
    /**
     * @js NA
     * @lua NA
     */
    ~AutoreleasePool();

    /**
<<<<<<< HEAD
     * Add a given object to this autorelease pool.
     *
     * The same object may be added several times to an autorelease pool. When the
     * pool is destructed, the object's `Ref::release()` method will be called
     * the same times as it was added.
     *
     * @param object    The object to be added into the autorelease pool.
=======
     * Add a given object to this pool.
     *
     * The same object may be added several times to the same pool; When the
     * pool is destructed, the object's Ref::release() method will be called
     * for each time it was added.
     *
     * @param object    The object to add to the pool.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    void addObject(Ref *object);

    /**
     * Clear the autorelease pool.
     *
<<<<<<< HEAD
     * It will invoke each element's `release()` function.
     *
=======
     * Ref::release() will be called for each time the managed object is
     * added to the pool.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    void clear();
    
#if defined(COCOS2D_DEBUG) && (COCOS2D_DEBUG > 0)
    /**
<<<<<<< HEAD
     * Whether the autorelease pool is doing `clear` operation.
     *
     * @return True if autorelase pool is clearning, false if not.
     *
     * @js NA
     * @lua NA
=======
     * Whether the pool is doing `clear` operation.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    bool isClearing() const { return _isClearing; };
#endif
    
    /**
<<<<<<< HEAD
     * Checks whether the autorelease pool contains the specified object.
     *
     * @param object The object to be checked.
     * @return True if the autorelease pool contains the object, false if not
     * @js NA
     * @lua NA
=======
     * Checks whether the pool contains the specified object.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    bool contains(Ref* object) const;

    /**
<<<<<<< HEAD
     * Dump the objects that are put into the autorelease pool. It is used for debugging.
=======
     * Dump the objects that are put into autorelease pool. It is used for debugging.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * The result will look like:
     * Object pointer address     object id     reference count
     *
<<<<<<< HEAD
     * @js NA
     * @lua NA
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void dump();
    
private:
    /**
     * The underlying array of object managed by the pool.
     *
     * Although Array retains the object once when an object is added, proper
     * Ref::release() is called outside the array to make sure that the pool
     * does not affect the managed object's reference count. So an object can
     * be destructed properly by calling Ref::release() even if the object
     * is in the pool.
     */
    std::vector<Ref*> _managedObjectArray;
    std::string _name;
    
#if defined(COCOS2D_DEBUG) && (COCOS2D_DEBUG > 0)
    /**
     *  The flag for checking whether the pool is doing `clear` operation.
     */
    bool _isClearing;
#endif
};

<<<<<<< HEAD
// end of base group
/** @} */

/**
 * @cond
 */
class CC_DLL PoolManager
{
public:

    CC_DEPRECATED_ATTRIBUTE static PoolManager* sharedPoolManager() { return getInstance(); }
    static PoolManager* getInstance();
    
=======
class CC_DLL PoolManager
{
public:
    /**
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE static PoolManager* sharedPoolManager() { return getInstance(); }
    static PoolManager* getInstance();
    
    /**
     * @js NA
     * @lua NA
     */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE static void purgePoolManager() { destroyInstance(); }
    static void destroyInstance();
    
    /**
     * Get current auto release pool, there is at least one auto release pool that created by engine.
     * You can create your own auto release pool at demand, which will be put into auto releae pool stack.
     */
    AutoreleasePool *getCurrentPool() const;

    bool isObjectInPools(Ref* obj) const;

<<<<<<< HEAD

=======
    /**
     * @js NA
     * @lua NA
     */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    friend class AutoreleasePool;
    
private:
    PoolManager();
    ~PoolManager();
    
    void push(AutoreleasePool *pool);
    void pop();
    
    static PoolManager* s_singleInstance;
    
    std::vector<AutoreleasePool*> _releasePoolStack;
};
<<<<<<< HEAD
/**
 * @endcond
 */
=======

// end of base_nodes group
/// @}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_END

#endif //__AUTORELEASEPOOL_H__
