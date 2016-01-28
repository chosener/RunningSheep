/****************************************************************************
Copyright (c) 2009-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
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

#ifndef __CCTRANSITION_H__
#define __CCTRANSITION_H__

#include "2d/CCScene.h"
<<<<<<< HEAD
=======
#include "base/ccTypes.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

/**
<<<<<<< HEAD
 * @addtogroup _2d
=======
 * @addtogroup transition
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 * @{
 */

//static creation function macro
//c/c++ don't support object creation of using class name
//so, all classes need creation method.

class ActionInterval;
class Node;
class NodeGrid;

<<<<<<< HEAD
/** @class TransitionEaseScene
 * @brief TransitionEaseScene can ease the actions of the scene protocol.
@since v0.8.2
@js NA
=======
/** @brief TransitionEaseScene can ease the actions of the scene protocol.
@since v0.8.2
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
*/
class CC_DLL TransitionEaseScene// : public Ref
{
public:
<<<<<<< HEAD
    /** Constructor.
     */
    virtual ~TransitionEaseScene() {}

    /** Returns the Ease action that will be performed on a linear action.
    @since v0.8.2
     *
     * @param action A given interval action.
     * @return The Ease action that will be performed on a linear action.
     */
    virtual ActionInterval * easeActionWithAction(ActionInterval * action) = 0;
};

/** @class TransitionScene
 * @brief Base class for Transition scenes.
=======
    virtual ~TransitionEaseScene() {}

    /** returns the Ease action that will be performed on a linear action.
    @since v0.8.2
    */
    virtual ActionInterval * easeActionWithAction(ActionInterval * action) = 0;
};

/** @brief Base class for Transition scenes
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
*/
class CC_DLL TransitionScene : public Scene
{
public:
<<<<<<< HEAD
    /** Orientation Type used by some transitions.
=======
    /** Orientation Type used by some transitions
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    enum class Orientation
    {
        /// An horizontal orientation where the Left is nearer
        LEFT_OVER = 0,
        /// An horizontal orientation where the Right is nearer
        RIGHT_OVER = 1,
        /// A vertical orientation where the Up is nearer
        UP_OVER = 0,
        /// A vertical orientation where the Bottom is nearer
        DOWN_OVER = 1,
    };
    
<<<<<<< HEAD
    /** Creates a base transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionScene object.
     */
    static TransitionScene * create(float t, Scene *scene);

    /** Called after the transition finishes.
     */
    void finish(void);

    /** Used by some transitions to hide the outer scene.
     */
    void hideOutShowIn(void);

    Scene* getInScene() const{ return _inScene; }
    float getDuration() const { return _duration; }
=======
    /** creates a base transition with duration and incoming scene */
    static TransitionScene * create(float t, Scene *scene);

    /** called after the transition finishes */
    void finish(void);

    /** used by some transitions to hide the outer scene */
    void hideOutShowIn(void);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    //
    // Overrides
    //
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void cleanup() override;
    
CC_CONSTRUCTOR_ACCESS:
    TransitionScene();
    virtual ~TransitionScene();

    /** initializes a transition with duration and incoming scene */
    bool initWithDuration(float t,Scene* scene);
    
protected:
    virtual void sceneOrder();
    void setNewScene(float dt);

    Scene *_inScene;
    Scene *_outScene;
    float _duration;
    bool _isInSceneOnTop;
    bool _isSendCleanupToScene;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionScene);
};

<<<<<<< HEAD
/** @class TransitionSceneOriented
 * @brief A Transition that supports orientation like.
 * Possible orientation: LeftOver, RightOver, UpOver, DownOver
 */
class CC_DLL TransitionSceneOriented : public TransitionScene
{
public:
    /** Creates a transition with duration, incoming scene and orientation.
     * 
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @param orientation A given orientation: LeftOver, RightOver, UpOver, DownOver.
     * @return A autoreleased TransitionSceneOriented object.
     */
=======
/** @brief A Transition that supports orientation like.
* Possible orientation: LeftOver, RightOver, UpOver, DownOver
*/
class CC_DLL TransitionSceneOriented : public TransitionScene
{
public:
    /** creates a base transition with duration and incoming scene */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionSceneOriented * create(float t,Scene* scene, Orientation orientation);
    
CC_CONSTRUCTOR_ACCESS:
    TransitionSceneOriented();
    virtual ~TransitionSceneOriented();

    /** initializes a transition with duration and incoming scene */
    bool initWithDuration(float t,Scene* scene,Orientation orientation);

protected:
    Orientation _orientation;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSceneOriented);
};

<<<<<<< HEAD
/** @class TransitionRotoZoom
 * @brief TransitionRotoZoom:
=======
/** @brief TransitionRotoZoom:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Rotate and zoom out the outgoing scene, and then rotate and zoom in the incoming 
*/
class CC_DLL TransitionRotoZoom : public TransitionScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionRotoZoom object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionRotoZoom* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionRotoZoom();
    virtual ~TransitionRotoZoom();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionRotoZoom);

};

<<<<<<< HEAD
/** @class TransitionJumpZoom
 * @brief TransitionJumpZoom:
=======
/** @brief TransitionJumpZoom:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Zoom out and jump the outgoing scene, and then jump and zoom in the incoming 
*/
class CC_DLL TransitionJumpZoom : public TransitionScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionJumpZoom object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionJumpZoom* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionJumpZoom();
    virtual ~TransitionJumpZoom();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionJumpZoom);
};

<<<<<<< HEAD
/** @class TransitionMoveInL
 * @brief TransitionMoveInL:
=======
/** @brief TransitionMoveInL:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Move in from to the left the incoming scene.
*/
class CC_DLL TransitionMoveInL : public TransitionScene, public TransitionEaseScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionMoveInL object.
     */
    static TransitionMoveInL* create(float t, Scene* scene);

    /** Returns the action that will be performed. 
     * 
     * @return The action that will be performed.
     */
    virtual ActionInterval* action(void);

    virtual ActionInterval* easeActionWithAction(ActionInterval * action) override;
=======
    static TransitionMoveInL* create(float t, Scene* scene);

    /** returns the action that will be performed */
    virtual ActionInterval* action(void);

    virtual ActionInterval* easeActionWithAction(ActionInterval * action);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    //
    // Overrides
    //
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionMoveInL();
    virtual ~TransitionMoveInL();

protected:
    /** initializes the scenes */
    virtual void initScenes();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionMoveInL);
};

<<<<<<< HEAD
/** @class TransitionMoveInR
 * @brief TransitionMoveInR:
=======
/** @brief TransitionMoveInR:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Move in from to the right the incoming scene.
*/
class CC_DLL TransitionMoveInR : public TransitionMoveInL
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionMoveInR object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionMoveInR* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    TransitionMoveInR();
    virtual ~TransitionMoveInR();

protected:
    virtual void initScenes();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionMoveInR);
};

<<<<<<< HEAD
/** @class TransitionMoveInT
 * @brief TransitionMoveInT:
=======
/** @brief TransitionMoveInT:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Move in from to the top the incoming scene.
*/
class CC_DLL TransitionMoveInT : public TransitionMoveInL 
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionMoveInT object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionMoveInT* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    TransitionMoveInT();
    virtual ~TransitionMoveInT();

protected:
    virtual void initScenes();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionMoveInT);
};

<<<<<<< HEAD
/** @class TransitionMoveInB
 * @brief TransitionMoveInB:
=======
/** @brief TransitionMoveInB:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Move in from to the bottom the incoming scene.
*/
class CC_DLL TransitionMoveInB : public TransitionMoveInL
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionMoveInB object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionMoveInB* create(float t, Scene* scene);

CC_CONSTRUCTOR_ACCESS:
    TransitionMoveInB();
    virtual ~TransitionMoveInB();

protected:
    virtual void initScenes();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionMoveInB);
};

<<<<<<< HEAD
/** @class TransitionSlideInL
 * @brief TransitionSlideInL:
=======
/** @brief TransitionSlideInL:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Slide in the incoming scene from the left border.
*/
class CC_DLL TransitionSlideInL : public TransitionScene, public TransitionEaseScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSlideInL object.
     */
    static TransitionSlideInL* create(float t, Scene* scene);

    virtual ActionInterval* easeActionWithAction(ActionInterval * action) override;

    /** Returns the action that will be performed by the incoming and outgoing scene.
     *
     * @return The action that will be performed by the incoming and outgoing scene.
     */
=======
    static TransitionSlideInL* create(float t, Scene* scene);

    virtual ActionInterval* easeActionWithAction(ActionInterval * action);

    /** returns the action that will be performed by the incoming and outgoing scene */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ActionInterval* action(void);

    //
    // Overrides
    //
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionSlideInL();
    virtual ~TransitionSlideInL();

protected:
    /** initializes the scenes */
    virtual void initScenes(void);

    virtual void sceneOrder() override;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSlideInL);
};

<<<<<<< HEAD
/** @class TransitionSlideInR
 *@brief TransitionSlideInR:
=======
/** @brief TransitionSlideInR:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Slide in the incoming scene from the right border.
*/
class CC_DLL TransitionSlideInR : public TransitionSlideInL 
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSlideInR object.
     */
    static TransitionSlideInR* create(float t, Scene* scene);

    /** Returns the action that will be performed by the incoming and outgoing scene. */
    virtual ActionInterval* action(void) override;
=======
    static TransitionSlideInR* create(float t, Scene* scene);

    /** returns the action that will be performed by the incoming and outgoing scene */
    virtual ActionInterval* action(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    TransitionSlideInR();
    virtual ~TransitionSlideInR();

protected:
    /** initializes the scenes */
<<<<<<< HEAD
    virtual void initScenes(void) override;
=======
    virtual void initScenes(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    virtual void sceneOrder() override;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSlideInR);
};

<<<<<<< HEAD
/** @class TransitionSlideInB
 * @brief TransitionSlideInB:
=======
/** @brief TransitionSlideInB:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Slide in the incoming scene from the bottom border.
*/
class CC_DLL TransitionSlideInB : public TransitionSlideInL
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSlideInB object.
     */
    static TransitionSlideInB* create(float t, Scene* scene);

    /** returns the action that will be performed by the incoming and outgoing scene */
    virtual ActionInterval* action(void) override;
=======
    static TransitionSlideInB* create(float t, Scene* scene);

    /** returns the action that will be performed by the incoming and outgoing scene */
    virtual ActionInterval* action(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    TransitionSlideInB();
    virtual ~TransitionSlideInB();

protected:
    /** initializes the scenes */
<<<<<<< HEAD
    virtual void initScenes() override;
=======
    virtual void initScenes();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    virtual void sceneOrder() override;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSlideInB);
};

<<<<<<< HEAD
/** @class TransitionSlideInT
 * @brief TransitionSlideInT:
=======
/** @brief TransitionSlideInT:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Slide in the incoming scene from the top border.
*/
class CC_DLL TransitionSlideInT : public TransitionSlideInL
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSlideInT object.
     */
    static TransitionSlideInT* create(float t, Scene* scene);

    /** returns the action that will be performed by the incoming and outgoing scene */
    virtual ActionInterval* action(void) override;
=======
    static TransitionSlideInT* create(float t, Scene* scene);

    /** returns the action that will be performed by the incoming and outgoing scene */
    virtual ActionInterval* action(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    TransitionSlideInT();
    virtual ~TransitionSlideInT();

protected:
    /** initializes the scenes */
<<<<<<< HEAD
    virtual void initScenes(void) override;
=======
    virtual void initScenes(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    virtual void sceneOrder() override;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSlideInT);
};

<<<<<<< HEAD
/** @class TransitionShrinkGrow
* @brief Shrink the outgoing scene while grow the incoming scene
=======
/**
@brief Shrink the outgoing scene while grow the incoming scene
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
*/
class CC_DLL TransitionShrinkGrow : public TransitionScene , public TransitionEaseScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionShrinkGrow object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionShrinkGrow* create(float t, Scene* scene);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;
    virtual ActionInterval* easeActionWithAction(ActionInterval * action) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionShrinkGrow();
    virtual ~TransitionShrinkGrow();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionShrinkGrow);
};

<<<<<<< HEAD
/** @class TransitionFlipX
 * @brief TransitionFlipX:
=======
/** @brief TransitionFlipX:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen horizontally.
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionFlipX : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionFlipX object.
     */
    static TransitionFlipX* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionFlipX object.
     */
=======
    static TransitionFlipX* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFlipX* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFlipX();
    virtual ~TransitionFlipX();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFlipX);
};

<<<<<<< HEAD
/** @class TransitionFlipY
 * @brief TransitionFlipY:
=======
/** @brief TransitionFlipY:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen vertically.
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionFlipY : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionFlipY object.
     */
    static TransitionFlipY* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionFlipY object.
     */
=======
    static TransitionFlipY* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFlipY* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFlipY();
    virtual ~TransitionFlipY();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFlipY);
};

<<<<<<< HEAD
/** @class TransitionFlipAngular
 * @brief TransitionFlipAngular:
=======
/** @brief TransitionFlipAngular:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen half horizontally and half vertically.
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionFlipAngular : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionFlipAngular object.
     */
    static TransitionFlipAngular* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionFlipAngular object.
     */
=======
    static TransitionFlipAngular* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFlipAngular* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFlipAngular();
    virtual ~TransitionFlipAngular();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFlipAngular);
};

<<<<<<< HEAD
/** @class TransitionZoomFlipX
 * @brief TransitionZoomFlipX:
=======
/** @brief TransitionZoomFlipX:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen horizontally doing a zoom out/in
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionZoomFlipX : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionZoomFlipX object.
     */
    static TransitionZoomFlipX* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionZoomFlipX object.
     */
=======
    static TransitionZoomFlipX* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionZoomFlipX* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionZoomFlipX();
    virtual ~TransitionZoomFlipX();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionZoomFlipX);
};

<<<<<<< HEAD
/** @class TransitionZoomFlipY
 * @brief TransitionZoomFlipY:
=======
/** @brief TransitionZoomFlipY:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen vertically doing a little zooming out/in
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionZoomFlipY : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionZoomFlipY object.
     */
    static TransitionZoomFlipY* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionZoomFlipY object.
     */
=======
    static TransitionZoomFlipY* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionZoomFlipY* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionZoomFlipY();
    virtual ~TransitionZoomFlipY();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionZoomFlipY);
};

<<<<<<< HEAD
/** @class TransitionZoomFlipAngular
 * @brief TransitionZoomFlipAngular:
=======
/** @brief TransitionZoomFlipAngular:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Flips the screen half horizontally and half vertically doing a little zooming out/in.
The front face is the outgoing scene and the back face is the incoming scene.
*/
class CC_DLL TransitionZoomFlipAngular : public TransitionSceneOriented
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration, incoming scene and orientation.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @param o A given orientation.
     * @return A autoreleased TransitionZoomFlipAngular object.
     */
    static TransitionZoomFlipAngular* create(float t, Scene* s, Orientation o);
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param s A given scene.
     * @return A autoreleased TransitionZoomFlipAngular object.
     */
=======
    static TransitionZoomFlipAngular* create(float t, Scene* s, Orientation o);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionZoomFlipAngular* create(float t, Scene* s);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionZoomFlipAngular();
    virtual ~TransitionZoomFlipAngular();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionZoomFlipAngular);
};

<<<<<<< HEAD
/** @class TransitionFade
 * @brief TransitionFade:
=======
/** @brief TransitionFade:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Fade out the outgoing scene and then fade in the incoming scene.'''
*/
class CC_DLL TransitionFade : public TransitionScene
{
public:
<<<<<<< HEAD
    /** Creates the transition with a duration and with an RGB color
     * Example: FadeTransition::create(2, scene, Color3B(255,0,0); // red color
     *
     * @param duration Duration time, in seconds.
     * @param scene A given scene.
     * @param color A given transition color.
     * @return A autoreleased TransitionFade object.
     */
    static TransitionFade* create(float duration, Scene* scene, const Color3B& color);
    /** Creates the transition with a duration.
     *
     * @param duration Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionFade object.
     */
    static TransitionFade* create(float duration, Scene* scene);

    /**
=======
    /** creates the transition with a duration and with an RGB color
    * Example: FadeTransition::create(2, scene, Color3B(255,0,0); // red color
    */
    static TransitionFade* create(float duration, Scene* scene, const Color3B& color);
    static TransitionFade* create(float duration, Scene* scene);

    /**
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onExit() override;
    
CC_CONSTRUCTOR_ACCESS:
    TransitionFade();
    virtual ~TransitionFade();

    /** initializes the transition with a duration and with an RGB color */
    bool initWithDuration(float t, Scene*scene, const Color3B& color);
    bool initWithDuration(float t, Scene* scene);

protected:
    Color4B _color;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFade);

};

class RenderTexture;
<<<<<<< HEAD
/** @class TransitionCrossFade
=======
/**
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
@brief TransitionCrossFade:
Cross fades two scenes using the RenderTexture object.
*/
class CC_DLL TransitionCrossFade : public TransitionScene
{
public :
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionCrossFade object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionCrossFade* create(float t, Scene* scene);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onExit() override;

CC_CONSTRUCTOR_ACCESS:
    TransitionCrossFade();
    virtual ~TransitionCrossFade();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionCrossFade);
};

<<<<<<< HEAD
/** @class TransitionTurnOffTiles
 * @brief TransitionTurnOffTiles:
=======
/** @brief TransitionTurnOffTiles:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Turn off the tiles of the outgoing scene in random order
*/
class CC_DLL TransitionTurnOffTiles : public TransitionScene ,public TransitionEaseScene
{
public :
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionTurnOffTiles object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionTurnOffTiles* create(float t, Scene* scene);

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
     * @lua NA
     */
    virtual void onEnter() override;
    /**
     * @js NA
     */
    virtual void onExit() override;
	virtual ActionInterval * easeActionWithAction(ActionInterval * action) override;
	/**
	* @js NA
	*/
=======
     * @js NA
     * @lua NA
     */
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual ActionInterval * easeActionWithAction(ActionInterval * action) override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionTurnOffTiles();
    virtual ~TransitionTurnOffTiles();

protected:
    virtual void sceneOrder() override;
    NodeGrid* _outSceneProxy;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionTurnOffTiles);
};

<<<<<<< HEAD
/** @class TransitionSplitCols
 * @brief TransitionSplitCols:
=======
/** @brief TransitionSplitCols:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
The odd columns goes upwards while the even columns goes downwards.
*/
class CC_DLL TransitionSplitCols : public TransitionScene , public TransitionEaseScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSplitCols object.
     */
    static TransitionSplitCols* create(float t, Scene* scene);

    /** Returns the action that will be performed.
     *
     * @return The action that will be performed.
     */
=======
    static TransitionSplitCols* create(float t, Scene* scene);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ActionInterval* action();

    //
    // Overrides
    //
    /**
<<<<<<< HEAD
=======
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    virtual void onEnter() override;
    virtual ActionInterval * easeActionWithAction(ActionInterval * action) override;
    virtual void onExit() override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionSplitCols();
    virtual ~TransitionSplitCols();

protected:
    void switchTargetToInscene();
    NodeGrid* _gridProxy;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSplitCols);
};

<<<<<<< HEAD
/** @class TransitionSplitRows
 * @brief TransitionSplitRows:
=======
/** @brief TransitionSplitRows:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
The odd rows goes to the left while the even rows goes to the right.
*/
class CC_DLL TransitionSplitRows : public TransitionSplitCols
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionSplitRows object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionSplitRows* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual ActionInterval* action(void) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionSplitRows();
    virtual ~TransitionSplitRows();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionSplitRows);
};

<<<<<<< HEAD
/** @class TransitionFadeTR
 * @brief TransitionFadeTR:
=======
/** @brief TransitionFadeTR:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Fade the tiles of the outgoing scene from the left-bottom corner the to top-right corner.
*/
class CC_DLL TransitionFadeTR : public TransitionScene , public TransitionEaseScene
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionFadeTR object.
     */
    static TransitionFadeTR* create(float t, Scene* scene);

    /** Returns the action that will be performed with size.
     *
     * @param size A given size.
     * @return The action that will be performed.
     */
=======
    static TransitionFadeTR* create(float t, Scene* scene);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ActionInterval* actionWithSize(const Size& size);

    //
    // Overrides
    //
    /**
     * @js NA
     * @lua NA
     */
    virtual void onEnter() override;
    virtual ActionInterval* easeActionWithAction(ActionInterval * action) override;
    virtual void onExit() override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFadeTR();
    virtual ~TransitionFadeTR();

protected:
<<<<<<< HEAD
    virtual void sceneOrder() override;
=======
    virtual void sceneOrder();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    NodeGrid* _outSceneProxy;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFadeTR);
};

<<<<<<< HEAD
/** @class TransitionFadeBL
 * @brief TransitionFadeBL:
=======
/** @brief TransitionFadeBL:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
Fade the tiles of the outgoing scene from the top-right corner to the bottom-left corner.
*/
class CC_DLL TransitionFadeBL : public TransitionFadeTR
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionFadeBL object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFadeBL* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual ActionInterval* actionWithSize(const Size& size) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFadeBL();
    virtual ~TransitionFadeBL();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFadeBL);
};

<<<<<<< HEAD
/** @class TransitionFadeUp
 * @brief TransitionFadeUp:
=======
/** @brief TransitionFadeUp:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
* Fade the tiles of the outgoing scene from the bottom to the top.
*/
class CC_DLL TransitionFadeUp : public TransitionFadeTR
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionFadeUp object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFadeUp* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual ActionInterval* actionWithSize(const Size& size) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFadeUp();
    virtual ~TransitionFadeUp();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFadeUp);
};

<<<<<<< HEAD
/** @class TransitionFadeDown
 * @brief TransitionFadeDown:
=======
/** @brief TransitionFadeDown:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
* Fade the tiles of the outgoing scene from the top to the bottom.
*/
class CC_DLL TransitionFadeDown : public TransitionFadeTR
{
public:
<<<<<<< HEAD
    /** Creates a transition with duration and incoming scene.
     *
     * @param t Duration time, in seconds.
     * @param scene A given scene.
     * @return A autoreleased TransitionFadeDown object.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static TransitionFadeDown* create(float t, Scene* scene);

    //
    // Overrides
    //
    virtual ActionInterval* actionWithSize(const Size& size) override;

CC_CONSTRUCTOR_ACCESS:
    TransitionFadeDown();
    virtual ~TransitionFadeDown();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(TransitionFadeDown);

};

<<<<<<< HEAD
// end of _2d group
=======
// end of transition group
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
/// @}

NS_CC_END

#endif // __CCTRANSITION_H__

