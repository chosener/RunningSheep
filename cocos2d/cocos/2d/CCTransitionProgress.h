/****************************************************************************
Copyright (c) 2009      Lam Pham
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2012      Ricardo Quesada
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

#ifndef __CCTRANSITIONPROGRESS_H__
#define __CCTRANSITIONPROGRESS_H__

#include "2d/CCTransition.h"

NS_CC_BEGIN

class ProgressTimer;
class RenderTexture;

/**
<<<<<<< HEAD
 * @addtogroup _2d
 * @{
 */
/** @class TransitionProgress
 * @brief A base class of progress transition.
 */
class CC_DLL TransitionProgress : public TransitionScene
{
public:
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgress object.
     */
=======
 * @addtogroup transition
 * @{
 */
class CC_DLL TransitionProgress : public TransitionScene
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgress* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual void onEnter() override;
    virtual void onExit() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionProgress();
    virtual ~TransitionProgress(){}

protected:
    virtual void sceneOrder() override;

protected:
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture);
    virtual void setupTransition();

protected:
    float _to;
    float _from;
    Scene* _sceneToBeModified;
};


<<<<<<< HEAD
/** @class TransitionProgressRadialCCW
 * @brief TransitionRadialCCW transition.
=======
/** TransitionRadialCCW transition.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 A counter clock-wise radial transition to the next scene
 */
class CC_DLL TransitionProgressRadialCCW : public TransitionProgress
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressRadialCCW object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressRadialCCW* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressRadialCCW(){}
    virtual ~TransitionProgressRadialCCW(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;
  
};


<<<<<<< HEAD
/** @class TransitionProgressRadialCW
 * @brief TransitionRadialCW transition.
 A counter clock-wise radial transition to the next scene.
=======
/** TransitionRadialCW transition.
 A counter clock-wise radial transition to the next scene
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
*/
class CC_DLL TransitionProgressRadialCW : public TransitionProgress
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressRadialCW object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressRadialCW* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressRadialCW(){}
    virtual ~TransitionProgressRadialCW(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;

};

<<<<<<< HEAD
/** @class TransitionProgressHorizontal
  * @brief TransitionProgressHorizontal transition.
=======
/** TransitionProgressHorizontal transition.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 A  clock-wise radial transition to the next scene
 */
class CC_DLL TransitionProgressHorizontal : public TransitionProgress
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressHorizontal object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressHorizontal* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressHorizontal(){}
    virtual ~TransitionProgressHorizontal(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;
};

<<<<<<< HEAD
/** @class TransitionProgressVertical
 * @brief TransitionProgressVertical transition.
 */
class CC_DLL TransitionProgressVertical : public TransitionProgress
{
public:
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressVertical object.
     */
=======
class CC_DLL TransitionProgressVertical : public TransitionProgress
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressVertical* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressVertical(){}
    virtual ~TransitionProgressVertical(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;
};

<<<<<<< HEAD
/** @class TransitionProgressInOut
 * @brief TransitionProgressInOut transition.
 */
class CC_DLL TransitionProgressInOut : public TransitionProgress
{
public:
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressInOut object.
     */
=======
class CC_DLL TransitionProgressInOut : public TransitionProgress
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressInOut* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressInOut(){}
    virtual ~TransitionProgressInOut(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;
    virtual void sceneOrder() override;
    virtual void setupTransition() override;
};

<<<<<<< HEAD
/** @class TransitionProgressOutIn
 * @brief TransitionProgressOutIn transition.
 */
class CC_DLL TransitionProgressOutIn : public TransitionProgress
{
public:
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return An autoreleased TransitionProgressOutIn object.
     */
=======
class CC_DLL TransitionProgressOutIn : public TransitionProgress
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionProgressOutIn* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    TransitionProgressOutIn(){}
    virtual ~TransitionProgressOutIn(){}

protected:
    //
    // Overrides
    //
    virtual ProgressTimer* progressTimerNodeWithRenderTexture(RenderTexture* texture) override;

};

<<<<<<< HEAD
// end of _2d group
=======
// end of transition group
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
/// @}

NS_CC_END

#endif /* __CCTRANSITIONPROGRESS_H__ */

