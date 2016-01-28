/****************************************************************************
 Copyright (c) 2013 Chukong Technologies Inc.
 
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

#ifndef __CCPHYSICS_CONTACT_H__
#define __CCPHYSICS_CONTACT_H__

#include "base/ccConfig.h"
#if CC_USE_PHYSICS

#include "base/CCRef.h"
#include "math/CCGeometry.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEvent.h"
#include "base/CCEventCustom.h"

NS_CC_BEGIN

class PhysicsShape;
class PhysicsBody;
class PhysicsWorld;

<<<<<<< HEAD
typedef Vec2 Vect;

typedef struct CC_DLL PhysicsContactData
=======
class PhysicsContactInfo;

typedef Vec2 Vect;

typedef struct PhysicsContactData
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    static const int POINT_MAX = 4;
    Vec2 points[POINT_MAX];
    int   count;
    Vec2 normal;
    
    PhysicsContactData()
    : count(0)
    {}
}PhysicsContactData;

/**
<<<<<<< HEAD
 * @addtogroup core
 * @{
 */

/**
 * @brief Contact infomation. 
 
 * It will created automatically when two shape contact with each other. And it will destoried automatically when two shape separated.
 */
class CC_DLL PhysicsContact : public EventCustom
=======
 * @brief Contact infomation. it will created automatically when two shape contact with each other. and it will destoried automatically when two shape separated.
 */
class PhysicsContact : public EventCustom
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
public:
    
    enum class EventCode
    {
        NONE,
        BEGIN,
        PRESOLVE,
        POSTSOLVE,
        SEPERATE
    };
    
<<<<<<< HEAD
    /** Get contact shape A. */
    inline PhysicsShape* getShapeA() const { return _shapeA; }
    
    /** Get contact shape B. */
    inline PhysicsShape* getShapeB() const { return _shapeB; }
    
    /** Get contact data. */
    inline const PhysicsContactData* getContactData() const { return _contactData; }
    
    /** Get previous contact data */
    inline const PhysicsContactData* getPreContactData() const { return _preContactData; }
    
    /** 
     * Get data. 
     * @lua NA
     */
    inline void* getData() const { return _data; }
    
    /**
     * @brief Set data to contact. 
     
     * You must manage the memory yourself, Generally you can set data at contact begin, and distory it at contact seperate.
     *
     * @lua NA
     */
    inline void setData(void* data) { _data = data; }

    /** Get the event code */
=======
    /** get contact shape A. */
    inline PhysicsShape* getShapeA() const { return _shapeA; }
    /** get contact shape B. */
    inline PhysicsShape* getShapeB() const { return _shapeB; }
    /** get contact data */
    inline const PhysicsContactData* getContactData() const { return _contactData; }
    /** get previous contact data */
    inline const PhysicsContactData* getPreContactData() const { return _preContactData; }
    /** get data. */
    inline void* getData() const { return _data; }
    /**
     * @brief set data to contact. you must manage the memory yourself, Generally you can set data at contact begin, and distory it at contact seperate.
     */
    inline void setData(void* data) { _data = data; }
    /** get the event code */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    EventCode getEventCode() const { return _eventCode; };

private:
    static PhysicsContact* construct(PhysicsShape* a, PhysicsShape* b);
    bool init(PhysicsShape* a, PhysicsShape* b);
    
    void setEventCode(EventCode eventCode) { _eventCode = eventCode; };
    inline bool isNotificationEnabled() const { return _notificationEnable; }
    inline void setNotificationEnable(bool enable) { _notificationEnable = enable; }
    inline PhysicsWorld* getWorld() const { return _world; }
    inline void setWorld(PhysicsWorld* world) { _world = world; }
    inline void setResult(bool result) { _result = result; }
    inline bool resetResult() { bool ret = _result; _result = true; return ret; }
    
    void generateContactData();

private:
    PhysicsContact();
    ~PhysicsContact();
    
private:
    PhysicsWorld* _world;
    PhysicsShape* _shapeA;
    PhysicsShape* _shapeB;
    EventCode _eventCode;
<<<<<<< HEAD
=======
    PhysicsContactInfo* _info;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool _notificationEnable;
    bool _result;
    
    void* _data;
    void* _contactInfo;
    PhysicsContactData* _contactData;
    PhysicsContactData* _preContactData;
    
    friend class EventListenerPhysicsContact;
    friend class PhysicsWorldCallback;
    friend class PhysicsWorld;
};

<<<<<<< HEAD
/**
 * @brief Presolve value generated when onContactPreSolve called.
 */
class CC_DLL PhysicsContactPreSolve
{
public:
    /** Get restitution between two bodies.*/
    float getRestitution() const;
    /** Get friction between two bodies.*/
    float getFriction() const;
    /** Get surface velocity between two bodies.*/
    Vec2 getSurfaceVelocity() const;
    /** Set the restitution.*/
    void setRestitution(float restitution);
    /** Set the friction.*/
    void setFriction(float friction);
    /** Set the surface velocity.*/
    void setSurfaceVelocity(const Vect& velocity);
    /** Ignore the rest of the contact presolve and postsolve callbacks. */
=======
/*
 * @brief presolve value generated when onContactPreSolve called.
 */
class PhysicsContactPreSolve
{
public:
    /** get restitution between two bodies*/
    float getRestitution() const;
    /** get friction between two bodies*/
    float getFriction() const;
    /** get surface velocity between two bodies*/
    Vec2 getSurfaceVelocity() const;
    /** set the restitution*/
    void setRestitution(float restitution);
    /** set the friction*/
    void setFriction(float friction);
    /** set the surface velocity*/
    void setSurfaceVelocity(const Vect& velocity);
    /** ignore the rest of the contact presolve and postsolve callbacks */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void ignore();
    
private:
    PhysicsContactPreSolve(void* contactInfo);
    ~PhysicsContactPreSolve();
    
private:
    void* _contactInfo;
    
    friend class EventListenerPhysicsContact;
};

<<<<<<< HEAD
/**
 * @brief Postsolve value generated when onContactPostSolve called.
 */
class CC_DLL PhysicsContactPostSolve
{
public:
    /** Get restitution between two bodies.*/
    float getRestitution() const;
    /** Get friction between two bodies.*/
    float getFriction() const;
    /** Get surface velocity between two bodies.*/
=======
/*
 * @brief postsolve value generated when onContactPostSolve called.
 */
class PhysicsContactPostSolve
{
public:
    /** get restitution between two bodies*/
    float getRestitution() const;
    /** get friction between two bodies*/
    float getFriction() const;
    /** get surface velocity between two bodies*/
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Vec2 getSurfaceVelocity() const;
    
private:
    PhysicsContactPostSolve(void* contactInfo);
    ~PhysicsContactPostSolve();
    
private:
    void* _contactInfo;
    
    friend class EventListenerPhysicsContact;
};

<<<<<<< HEAD
/** Contact listener. It will recive all the contact callbacks. */
class CC_DLL EventListenerPhysicsContact : public EventListenerCustom
{
public:
    /** Create the listener. */
    static EventListenerPhysicsContact* create();
    
    /** Check the listener is available.

     *@return Ture if there's one available callback function at least, false if there's no one.
     */
    virtual bool checkAvailable() override;
    
    /** Clone an object from this listener.*/
=======
/* contact listener. it will recive all the contact callbacks. */
class EventListenerPhysicsContact : public EventListenerCustom
{
public:
    /** create the listener */
    static EventListenerPhysicsContact* create();
    virtual bool checkAvailable() override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual EventListenerPhysicsContact* clone() override;
    
protected:
    /**
<<<<<<< HEAD
     * It will be call when two body have contact.
     * if return false, it will not invoke callbacks.
=======
     * it will be call when two body have contact.
     * if return false, it will not invoke callbacks
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual bool hitTest(PhysicsShape* shapeA, PhysicsShape* shapeB);
    
public:
<<<<<<< HEAD
    /**
     * @brief It will called at two shapes start to contact, and only call it once.
     */
    std::function<bool(PhysicsContact& contact)> onContactBegin;
    /**
     * @brief Two shapes are touching during this step. Return false from the callback to make world ignore the collision this step or true to process it normally. Additionally, you may override collision values, restitution, or surface velocity values.
     */
    std::function<bool(PhysicsContact& contact, PhysicsContactPreSolve& solve)> onContactPreSolve;
    /**
     * @brief Two shapes are touching and their collision response has been processed. You can retrieve the collision impulse or kinetic energy at this time if you want to use it to calculate sound volumes or damage amounts. See cpArbiter for more info
     */
    std::function<void(PhysicsContact& contact, const PhysicsContactPostSolve& solve)> onContactPostSolve;
    /**
     * @brief It will called at two shapes separated, and only call it once.
=======
    /*
     * @brief it will called at two shapes start to contact, and only call it once.
     */
    std::function<bool(PhysicsContact& contact)> onContactBegin;
    /*
     * @brief Two shapes are touching during this step. Return false from the callback to make world ignore the collision this step or true to process it normally. Additionally, you may override collision values, restitution, or surface velocity values.
     */
    std::function<bool(PhysicsContact& contact, PhysicsContactPreSolve& solve)> onContactPreSolve;
    /*
     * @brief Two shapes are touching and their collision response has been processed. You can retrieve the collision impulse or kinetic energy at this time if you want to use it to calculate sound volumes or damage amounts. See cpArbiter for more info
     */
    std::function<void(PhysicsContact& contact, const PhysicsContactPostSolve& solve)> onContactPostSolve;
    /*
     * @brief it will called at two shapes separated, and only call it once.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * onContactBegin and onContactSeperate will called in pairs.
     */
    std::function<void(PhysicsContact& contact)> onContactSeperate;
    
protected:
    bool init();
    void onEvent(EventCustom* event);
    
protected:
    EventListenerPhysicsContact();
    virtual ~EventListenerPhysicsContact();
    
    friend class PhysicsWorld;
};

<<<<<<< HEAD
/** This event listener only be called when bodyA and bodyB have contacts. */
class CC_DLL EventListenerPhysicsContactWithBodies : public EventListenerPhysicsContact
{
public:
    /** Create the listener. */
    static EventListenerPhysicsContactWithBodies* create(PhysicsBody* bodyA, PhysicsBody* bodyB);
    
    virtual bool hitTest(PhysicsShape* shapeA, PhysicsShape* shapeB) override;

=======
/** this event listener only be called when bodyA and bodyB have contacts */
class EventListenerPhysicsContactWithBodies : public EventListenerPhysicsContact
{
public:
    static EventListenerPhysicsContactWithBodies* create(PhysicsBody* bodyA, PhysicsBody* bodyB);
    
    virtual bool hitTest(PhysicsShape* shapeA, PhysicsShape* shapeB) override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual EventListenerPhysicsContactWithBodies* clone() override;
    
protected:
    PhysicsBody* _a;
    PhysicsBody* _b;
    
protected:
    EventListenerPhysicsContactWithBodies();
    virtual ~EventListenerPhysicsContactWithBodies();
};

<<<<<<< HEAD
/** This event listener only be called when shapeA and shapeB have contacts. */
class CC_DLL EventListenerPhysicsContactWithShapes : public EventListenerPhysicsContact
{
public:
    /** Create the listener. */
=======
/** this event listener only be called when shapeA and shapeB have contacts */
class EventListenerPhysicsContactWithShapes : public EventListenerPhysicsContact
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EventListenerPhysicsContactWithShapes* create(PhysicsShape* shapeA, PhysicsShape* shapeB);
    
    virtual bool hitTest(PhysicsShape* shapeA, PhysicsShape* shapeB) override;
    virtual EventListenerPhysicsContactWithShapes* clone() override;
    
protected:
    PhysicsShape* _a;
    PhysicsShape* _b;
    
protected:
    EventListenerPhysicsContactWithShapes();
    virtual ~EventListenerPhysicsContactWithShapes();
};

<<<<<<< HEAD
/** This event listener only be called when shapeA or shapeB is in the group your specified */
class CC_DLL EventListenerPhysicsContactWithGroup : public EventListenerPhysicsContact
{
public:
    /** Create the listener. */
=======
/** this event listener only be called when shapeA or shapeB is in the group your specified */
class EventListenerPhysicsContactWithGroup : public EventListenerPhysicsContact
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EventListenerPhysicsContactWithGroup* create(int group);
    
    virtual bool hitTest(PhysicsShape* shapeA, PhysicsShape* shapeB) override;
    virtual EventListenerPhysicsContactWithGroup* clone() override;
    
protected:
    int _group;
    
protected:
    EventListenerPhysicsContactWithGroup();
    virtual ~EventListenerPhysicsContactWithGroup();
};

<<<<<<< HEAD
/** @} */

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END

#endif // CC_USE_PHYSICS
#endif //__CCPHYSICS_CONTACT_H__
