/****************************************************************************
Copyright (c) 2009      On-Core
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
#ifndef __ACTION_CCGRID_ACTION_H__
#define __ACTION_CCGRID_ACTION_H__

#include "2d/CCActionInterval.h"
#include "2d/CCActionInstant.h"

NS_CC_BEGIN

class GridBase;
class NodeGrid;

/**
 * @addtogroup actions
 * @{
 */

<<<<<<< HEAD
/** 
@class GridAction
@brief Base class for Grid actions.
@details Grid actions are the actions take effect on GridBase.
*/
=======
/** @brief Base class for Grid actions */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
class CC_DLL GridAction : public ActionInterval
{
public:

<<<<<<< HEAD
    /** 
    @brief Get the pointer of GridBase.
    @return The pointer of GridBase.
    */
    virtual GridBase* getGrid();

    // overrides
    virtual GridAction * clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
    virtual GridAction* reverse() const override;
    virtual void startWithTarget(Node *target) override;

CC_CONSTRUCTOR_ACCESS:
    GridAction() {}
    virtual ~GridAction() {}
    /** 
     * @brief Initializes the action with size and duration.
     * @param duration The duration of the GridAction. It's a value in seconds.
     * @param gridSize The size of the GridAction should be.
     * @return Return true when the initialization success, otherwise return false.
     */
    bool initWithDuration(float duration, const Size& gridSize);

protected:
=======
    /** returns the grid */
    virtual GridBase* getGrid();

    // overrides
	virtual GridAction * clone() const override = 0;
    virtual GridAction* reverse() const override;
    virtual void startWithTarget(Node *target) override;

protected:
    GridAction() {}
    virtual ~GridAction() {}
    /** initializes the action with size and duration */
    bool initWithDuration(float duration, const Size& gridSize);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Size _gridSize;
    
    NodeGrid* _gridNodeTarget;
    
    void cacheTargetAsGridNode();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(GridAction);
};

/** 
 @brief Base class for Grid3D actions.
<<<<<<< HEAD
 @details Grid3D actions can modify a non-tiled grid.
=======
 Grid3D actions can modify a non-tiled grid.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
class CC_DLL Grid3DAction : public GridAction
{
public:

<<<<<<< HEAD

    virtual GridBase* getGrid() override;
    /**
     * @brief Get the vertex that belongs to certain position in the grid.
     * @param position The position of the grid.
     * @return Return a pointer of vertex.
     * @js vertex
=======
    /** returns the grid */
    virtual GridBase* getGrid();
    /** returns the vertex than belongs to certain position in the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    Vec3 getVertex(const Vec2& position) const;

    /** @deprecated Use getVertex() instead 
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE inline Vec3 vertex(const Vec2& position) { return getVertex(position); }

<<<<<<< HEAD
    /** 
     * @brief Get the non-transformed vertex that belongs to certain position in the grid.
     * @param position The position of the grid.
     * @return Return a pointer of vertex.
     * @js originalVertex
=======
    /** returns the non-transformed vertex than belongs to certain position in the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    Vec3 getOriginalVertex(const Vec2& position) const;

    /** @deprecated Use getOriginalVertex() instead 
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE inline Vec3 originalVertex(const Vec2& position) { return getOriginalVertex(position); }

<<<<<<< HEAD
    /** 
     * @brief Set a new vertex to a certain position of the grid.
     * @param position The position of the grid.
     * @param vertex The vertex will be used on the certain position of grid.
     * @js setVertex
=======
    /** sets a new vertex to a certain position of the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    void setVertex(const Vec2& position, const Vec3& vertex);

    // Overrides
<<<<<<< HEAD
    virtual Grid3DAction * clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
};

/**
@brief Base class for TiledGrid3D actions.
*/
class CC_DLL TiledGrid3DAction : public GridAction
{
public:
    /** 
     * @brief Create the action with size and duration.
     * @param duration The duration of the action. It's a value in seconds.
     * @param gridSize Specify the grid size of the action.
     * @return A pointer of TiledGrid3DAction. If creation failed, return nil.
=======
	virtual Grid3DAction * clone() const override = 0;
};

/** @brief Base class for TiledGrid3D actions */
class CC_DLL TiledGrid3DAction : public GridAction
{
public:
    /** creates the action with size and duration 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    static TiledGrid3DAction* create(float duration, const Size& gridSize);

<<<<<<< HEAD
    /** 
     * @brief Get the tile that belongs to a certain position of the grid.
     * @param position The position of the tile want to get.
     * @return A quadrilateral of the tile. 
     * @js tile
=======
    /** returns the tile that belongs to a certain position of the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    Quad3 getTile(const Vec2& position) const;

    /** @deprecated Use getTile() instead 
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE Quad3 tile(const Vec2& position) { return getTile(position); }

<<<<<<< HEAD
    /** 
     * @brief Get the non-transformed tile that belongs to a certain position of the grid.
     * @param position The position of the tile want to get.
     * @return A quadrilateral of the tile. 
     * @js originalTile
=======
    /** returns the non-transformed tile that belongs to a certain position of the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    Quad3 getOriginalTile(const Vec2& position) const;

<<<<<<< HEAD
    /** @deprecated Use getOriginalTile() instead.
=======
    /** @deprecated Use getOriginalTile() instead 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE Quad3 originalTile(const Vec2& position) { return getOriginalTile(position); }

<<<<<<< HEAD
    /** 
     * @brief Set a new tile to a certain position of the grid.
     * @param position The position of the tile.
     * @param coords The quadrilateral of the new tile.
=======
    /** sets a new tile to a certain position of the grid 
     * @js NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua NA
     */
    void setTile(const Vec2& position, const Quad3& coords);

    /** returns the grid */
<<<<<<< HEAD
    virtual GridBase* getGrid() override;

    // Override
    virtual TiledGrid3DAction * clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
};

/**
@brief AccelDeccelAmplitude action.
@js NA
*/
class CC_DLL AccelDeccelAmplitude : public ActionInterval
{
public:
    /**
    @brief Create the action with an inner action that has the amplitude property, and a duration time.
    @param action A pointer of the inner action.
    @param duration Specify the duration of the AccelDeccelAmplitude action.
    @return Return a pointer of AccelDeccelAmplitude action. When the creation failed, return nil.
    */
    static AccelDeccelAmplitude* create(Action *action, float duration);

    /** 
    @brief Get the value of amplitude rate.
    @return the value of amplitude rate.
    */
    inline float getRate(void) const { return _rate; }
    /**
    @brief Set the value of amplitude rate.
    @param rate Specify the value of amplitude rate.
    */
=======
    virtual GridBase* getGrid();

    // Override
    virtual TiledGrid3DAction * clone() const override = 0;
};

/** @brief AccelDeccelAmplitude action */
class CC_DLL AccelDeccelAmplitude : public ActionInterval
{
public:
    /** creates the action with an inner action that has the amplitude property, and a duration time */
    static AccelDeccelAmplitude* create(Action *action, float duration);

    /** get amplitude rate */
    inline float getRate(void) const { return _rate; }
    /** set amplitude rate */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setRate(float rate) { _rate = rate; }

    // Overrides
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual AccelDeccelAmplitude* clone() const override;
    virtual AccelDeccelAmplitude* reverse() const override;
=======
	virtual AccelDeccelAmplitude* clone() const override;
	virtual AccelDeccelAmplitude* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
CC_CONSTRUCTOR_ACCESS:
    AccelDeccelAmplitude() {}
    virtual ~AccelDeccelAmplitude();
    
<<<<<<< HEAD
    /** 
    @brief Initializes the action with an inner action that has the amplitude property, and a duration time.
    @param action A pointer of the inner action.
    @param duration Specify the duration of the AccelDeccelAmplitude action.
    @return If the initialization success, return true; otherwise, return false.
    */
=======
    /** initializes the action with an inner action that has the amplitude property, and a duration time */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithAction(Action *action, float duration);

protected:
    float _rate;
    ActionInterval *_other;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(AccelDeccelAmplitude);
};

<<<<<<< HEAD
/**
@brief AccelAmplitude action.
@js NA
*/
class CC_DLL AccelAmplitude : public ActionInterval
{
public:
    /** 
    @brief Create the action with an inner action that has the amplitude property, and a duration time.
    @param action A pointer of the inner action.
    @param duration Specify the duration of the AccelAmplitude action.
    @return Return a pointer of AccelAmplitude action. When the creation failed, return nil.
     */
    static AccelAmplitude* create(Action *action, float duration);

    /** 
    @brief Get the value of amplitude rate.
    @return The value of amplitude rate.
    */
    inline float getRate() const { return _rate; }
    /**
    @brief Set the value of amplitude rate.
    @param rate Specify the value of amplitude rate.
    */
=======
/** @brief AccelAmplitude action */
class CC_DLL AccelAmplitude : public ActionInterval
{
public:
    /** creates the action with an inner action that has the amplitude property, and a duration time */
    static AccelAmplitude* create(Action *action, float duration);

    /** get amplitude rate */
    inline float getRate() const { return _rate; }
    /** set amplitude rate */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setRate(float rate) { _rate = rate; }

    // Overrides
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual AccelAmplitude* clone() const override;
    virtual AccelAmplitude* reverse() const override;
=======
	virtual AccelAmplitude* clone() const override;
	virtual AccelAmplitude* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
CC_CONSTRUCTOR_ACCESS:
    AccelAmplitude() {}
    virtual ~AccelAmplitude();

    bool initWithAction(Action *action, float duration);

protected:
    float _rate;
    ActionInterval *_other;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(AccelAmplitude);
};

<<<<<<< HEAD
/**
@brief DeccelAmplitude action.
@js NA
*/
class CC_DLL DeccelAmplitude : public ActionInterval
{
public:
    /** 
    @brief Creates the action with an inner action that has the amplitude property, and a duration time.
    @param action A pointer of the inner action.
    @param duration Specify the duration of the DeccelAmplitude action.
    @return Return a pointer of DeccelAmplitude. When the creation failed, return nil.
    */
    static DeccelAmplitude* create(Action *action, float duration);

    /** 
    @brief Get the value of amplitude rate.
    @return The value of amplitude rate.
    */
    inline float getRate() const { return _rate; }
    /**
    @brief Set the value of amplitude rate.
    @param rate Specify the value.
    */
=======
/** @brief DeccelAmplitude action */
class CC_DLL DeccelAmplitude : public ActionInterval
{
public:
    /** creates the action with an inner action that has the amplitude property, and a duration time */
    static DeccelAmplitude* create(Action *action, float duration);

    /** get amplitude rate */
    inline float getRate() const { return _rate; }
    /** set amplitude rate */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setRate(float rate) { _rate = rate; }

    // overrides
    virtual void startWithTarget(Node *target) override;
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual DeccelAmplitude* clone() const override;
    virtual DeccelAmplitude* reverse() const override;
=======
	virtual DeccelAmplitude* clone() const override;
	virtual DeccelAmplitude* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
CC_CONSTRUCTOR_ACCESS:
    DeccelAmplitude() {}
    virtual ~DeccelAmplitude();

<<<<<<< HEAD
    /** 
    @brief Initializes the action with an inner action that has the amplitude property, and a duration time.
    @param action The pointer of inner action.
    @param duration The duration of the DeccelAmplitude action.
    @return If the initilization sucess, return true; otherwise, return false.
    */
=======
    /** initializes the action with an inner action that has the amplitude property, and a duration time */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithAction(Action *action, float duration);

protected:
    float _rate;
    ActionInterval *_other;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(DeccelAmplitude);
};

<<<<<<< HEAD
/**
 @brief StopGrid action.
=======
/** @brief StopGrid action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @warning Don't call this action if another grid action is active.
 Call if you want to remove the the grid effect. Example:
 Sequence::actions(Lens::action(...), StopGrid::action(...), nullptr);
 */
class CC_DLL StopGrid : public ActionInstant
{
public:
<<<<<<< HEAD
    /** 
    @brief Create a StopGrid Action.
    @return Return a pointer of StopGrid. When the creation failed, return nil.
    */
=======
    /** Allocates and initializes the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static StopGrid* create();

    // Overrides
    virtual void startWithTarget(Node *target) override;
<<<<<<< HEAD
    virtual StopGrid* clone() const override;
    virtual StopGrid* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    StopGrid() {}
    virtual ~StopGrid() {}
    
protected:
=======
	virtual StopGrid* clone() const override;
	virtual StopGrid* reverse() const override;

protected:
    StopGrid() {}
    virtual ~StopGrid() {}
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    NodeGrid* _gridNodeTarget;
    
    void cacheTargetAsGridNode();

private:
    CC_DISALLOW_COPY_AND_ASSIGN(StopGrid);
};

<<<<<<< HEAD
/** 
@brief ReuseGrid action.
*/
class CC_DLL ReuseGrid : public ActionInstant
{
public:
    /** 
    @brief Create an action with the number of times that the current grid will be reused.
    @param times Specify times the grid will be reused.
    @return Return a pointer of ReuseGrid. When the creation failed, return nil.
    */
=======
/** @brief ReuseGrid action */
class CC_DLL ReuseGrid : public ActionInstant
{
public:
    /** creates an action with the number of times that the current grid will be reused */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static ReuseGrid* create(int times);

    // Override
    virtual void startWithTarget(Node *target) override;
<<<<<<< HEAD
    virtual ReuseGrid* clone() const override;
    virtual ReuseGrid* reverse() const override;
=======
	virtual ReuseGrid* clone() const override;
	virtual ReuseGrid* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
CC_CONSTRUCTOR_ACCESS:
    ReuseGrid() {}
    virtual ~ReuseGrid() {}
    
<<<<<<< HEAD
    /** 
    @brief Initializes an action with the number of times that the current grid will be reused.
    @param times Specify times the grid will be reused.
    @return If the initialization sucess, return true; otherwise, return false.
    */
=======
    /** initializes an action with the number of times that the current grid will be reused */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithTimes(int times);

protected:
    NodeGrid* _gridNodeTarget;
    
    void cacheTargetAsGridNode();
    
    int _times;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(ReuseGrid);
};

// end of actions group
/// @}

NS_CC_END

#endif // __ACTION_CCGRID_ACTION_H__
