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

#include "physics/CCPhysicsJoint.h"
#if CC_USE_PHYSICS
#include "chipmunk.h"

<<<<<<< HEAD
#include "CCPhysicsBody.h"
#include "CCPhysicsWorld.h"
#include "CCPhysicsHelper.h"
=======
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"

#include "chipmunk/CCPhysicsJointInfo_chipmunk.h"
#include "chipmunk/CCPhysicsBodyInfo_chipmunk.h"
#include "chipmunk/CCPhysicsShapeInfo_chipmunk.h"
#include "chipmunk/CCPhysicsHelper_chipmunk.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "2d/CCNode.h"

NS_CC_BEGIN

PhysicsJoint::PhysicsJoint()
: _bodyA(nullptr)
, _bodyB(nullptr)
, _world(nullptr)
<<<<<<< HEAD
=======
, _info(nullptr)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
, _enable(false)
, _collisionEnable(true)
, _destoryMark(false)
, _tag(0)
<<<<<<< HEAD
, _maxForce(PHYSICS_INFINITY)
, _initDirty(true)
{

=======
{
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJoint::~PhysicsJoint()
{
    // reset the shapes collision group
    setCollisionEnable(true);
<<<<<<< HEAD

    for (cpConstraint* joint : _cpConstraints)
    {
        cpConstraintFree(joint);
    }
    _cpConstraints.clear();
=======
    
    CC_SAFE_DELETE(_info);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool PhysicsJoint::init(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b)
{
    do
    {
        CCASSERT(a != nullptr && b != nullptr, "the body passed in is nil");
        CCASSERT(a != b, "the two bodies are equal");
<<<<<<< HEAD

        _bodyA = a;
        _bodyB = b;
        _bodyA->_joints.push_back(this);
        _bodyB->_joints.push_back(this);

        return true;
    } while (false);

    return false;
}

bool PhysicsJoint::initJoint()
{
    bool ret = !_initDirty;
    while (_initDirty)
    {
        ret = createConstraints();
        CC_BREAK_IF(!ret);

        for (auto subjoint : _cpConstraints)
        {
            subjoint->maxForce = _maxForce;
            subjoint->errorBias = cpfpow(1.0f - 0.15f, 60.0f);
            cpSpaceAddConstraint(_world->_cpSpace, subjoint);
        }
        _initDirty = false;
        ret = true;
    }

    return ret;
}

=======
        
        CC_BREAK_IF(!(_info = new PhysicsJointInfo(this)));
        
        _bodyA = a;
        _bodyA->_joints.push_back(this);
        _bodyB = b;
        _bodyB->_joints.push_back(this);
        
        return true;
    } while (false);
    
    return false;
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void PhysicsJoint::setEnable(bool enable)
{
    if (_enable != enable)
    {
        _enable = enable;
<<<<<<< HEAD

        if (_world)
        {
            if (enable)
            {
                _world->addJoint(this);
            }
            else
            {
                _world->removeJoint(this, false);
=======
        
        if (_world != nullptr)
        {
            if (enable)
            {
                _world->addJointOrDelay(this);
            }else
            {
                _world->removeJointOrDelay(this);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
        }
    }
}

<<<<<<< HEAD
=======
PhysicsBodyInfo* PhysicsJoint::getBodyInfo(PhysicsBody* body) const
{
    return body->_info;
}

Node* PhysicsJoint::getBodyNode(PhysicsBody* body) const
{
    return body->_node;
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void PhysicsJoint::setCollisionEnable(bool enable)
{
    if (_collisionEnable != enable)
    {
        _collisionEnable = enable;
    }
}

void PhysicsJoint::removeFormWorld()
{
    if (_world)
    {
        _world->removeJoint(this, false);
    }
}

<<<<<<< HEAD
void PhysicsJoint::setMaxForce(float force)
{
    _maxForce = force;
    for (auto joint : _cpConstraints)
=======
void PhysicsJoint::destroy(PhysicsJoint* joint)
{
    if (joint!= nullptr)
    {
        // remove the joint and delete it.
        if (joint->_world != nullptr)
        {
            joint->_world->removeJoint(joint, true);
        }
        else
        {
            if (joint->_bodyA != nullptr)
            {
                joint->_bodyA->removeJoint(joint);
            }
            
            if (joint->_bodyB != nullptr)
            {
                joint->_bodyB->removeJoint(joint);
            }
            
            delete joint;
        }
    }
}

void PhysicsJoint::setMaxForce(float force)
{
    for (cpConstraint* joint : _info->getJoints())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        joint->maxForce = PhysicsHelper::float2cpfloat(force);
    }
}

<<<<<<< HEAD
PhysicsJointFixed* PhysicsJointFixed::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr)
{
    auto joint = new (std::nothrow) PhysicsJointFixed();

    if (joint && joint->init(a, b))
    {
        joint->_anchr = anchr;
        return joint;
    }

=======
float PhysicsJoint::getMaxForce() const
{
    return PhysicsHelper::cpfloat2float(_info->getJoints().front()->maxForce);
}

PhysicsJointFixed* PhysicsJointFixed::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr)
{
    PhysicsJointFixed* joint = new PhysicsJointFixed();
    
    if (joint && joint->init(a, b, anchr))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointFixed::createConstraints()
{
    do
    {
        _bodyA->getNode()->setPosition(_anchr);
        _bodyB->getNode()->setPosition(_anchr);

        // add a pivot joint to fixed two body together
        auto joint = cpPivotJointNew(_bodyA->getCPBody(), _bodyB->getCPBody(),
            PhysicsHelper::point2cpv(_anchr));
        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        // add a gear joint to make two body have the same rotation.
        joint = cpGearJointNew(_bodyA->getCPBody(), _bodyB->getCPBody(), 0, 1);
        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        _collisionEnable = false;

        return true;
    } while (false);

    return false;
}

PhysicsJointPin* PhysicsJointPin::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& pivot)
{
    auto joint = new (std::nothrow) PhysicsJointPin();

    if (joint && joint->init(a, b))
    {
        joint->_anchr1 = pivot;
        joint->_useSpecificAnchr = false;
        return joint;
    }

=======
bool PhysicsJointFixed::init(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        getBodyNode(a)->setPosition(anchr);
        getBodyNode(b)->setPosition(anchr);
        
        // add a pivot joint to fixed two body together
        cpConstraint* joint = cpPivotJointNew(getBodyInfo(a)->getBody(), getBodyInfo(b)->getBody(),
                                        PhysicsHelper::point2cpv(anchr));
        CC_BREAK_IF(joint == nullptr);
        _info->add(joint);
        
        // add a gear joint to make two body have the same rotation.
        joint = cpGearJointNew(getBodyInfo(a)->getBody(), getBodyInfo(b)->getBody(), 0, 1);
        CC_BREAK_IF(joint == nullptr);
        _info->add(joint);
        
        setCollisionEnable(false);
        
        return true;
    } while (false);
    
    return false;
}

PhysicsJointPin* PhysicsJointPin::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr)
{
    PhysicsJointPin* joint = new PhysicsJointPin();
    
    if (joint && joint->init(a, b, anchr))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
PhysicsJointPin* PhysicsJointPin::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
{
    auto joint = new (std::nothrow) PhysicsJointPin();

    if (joint && joint->init(a, b))
    {
        joint->_anchr1 = anchr1;
        joint->_anchr2 = anchr2;
        joint->_useSpecificAnchr = true;

        return joint;
    }

    CC_SAFE_DELETE(joint);
    return nullptr;
}

bool PhysicsJointPin::createConstraints()
{
    do
    {
        cpConstraint* joint = nullptr;
        if (_useSpecificAnchr)
        {
            joint = cpPivotJointNew2(_bodyA->getCPBody(), _bodyB->getCPBody(),
                PhysicsHelper::point2cpv(_anchr1), PhysicsHelper::point2cpv(_anchr2));
        }
        else
        {
            joint = cpPivotJointNew(_bodyA->getCPBody(), _bodyB->getCPBody(),
                PhysicsHelper::point2cpv(_anchr1));
        }

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointPin::init(PhysicsBody *a, PhysicsBody *b, const Vec2& anchr)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        cpConstraint* joint = cpPivotJointNew(getBodyInfo(a)->getBody(), getBodyInfo(b)->getBody(),
                                       PhysicsHelper::point2cpv(anchr));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

PhysicsJointLimit* PhysicsJointLimit::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float min, float max)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointLimit();

    if (joint && joint->init(a, b))
    {
        joint->_anchr1 = anchr1;
        joint->_anchr2 = anchr2;
        joint->_min = min;
        joint->_max = max;

        return joint;
    }

=======
    PhysicsJointLimit* joint = new PhysicsJointLimit();
    
    if (joint && joint->init(a, b, anchr1, anchr2, min, max))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

PhysicsJointLimit* PhysicsJointLimit::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
{
    return construct(a, b, anchr1, anchr2, 0, b->local2World(anchr1).getDistance(a->local2World(anchr2)));
}

<<<<<<< HEAD
bool PhysicsJointLimit::createConstraints()
{
    do
    {
        auto joint = cpSlideJointNew(_bodyA->getCPBody(), _bodyB->getCPBody(),
            PhysicsHelper::point2cpv(_anchr1),
            PhysicsHelper::point2cpv(_anchr2),
            PhysicsHelper::float2cpfloat(_min),
            PhysicsHelper::float2cpfloat(_max));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointLimit::init(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float min, float max)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpSlideJointNew(getBodyInfo(a)->getBody(), getBodyInfo(b)->getBody(),
                                       PhysicsHelper::point2cpv(anchr1),
                                       PhysicsHelper::point2cpv(anchr2),
                                       PhysicsHelper::float2cpfloat(min),
                                       PhysicsHelper::float2cpfloat(max));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointLimit::getMin() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpSlideJointGetMin(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpSlideJointGetMin(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointLimit::setMin(float min)
{
<<<<<<< HEAD
    cpSlideJointSetMin(_cpConstraints.front(), PhysicsHelper::float2cpfloat(min));
=======
    cpSlideJointSetMin(_info->getJoints().front(), PhysicsHelper::float2cpfloat(min));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointLimit::getMax() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpSlideJointGetMax(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpSlideJointGetMax(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointLimit::setMax(float max)
{
<<<<<<< HEAD
    cpSlideJointSetMax(_cpConstraints.front(), PhysicsHelper::float2cpfloat(max));
=======
    cpSlideJointSetMax(_info->getJoints().front(), PhysicsHelper::float2cpfloat(max));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsJointLimit::getAnchr1() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpSlideJointGetAnchr1(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpSlideJointGetAnchr1(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointLimit::setAnchr1(const Vec2& anchr)
{
<<<<<<< HEAD
    cpSlideJointSetAnchr1(_cpConstraints.front(), PhysicsHelper::point2cpv(anchr));
=======
    cpSlideJointSetAnchr1(_info->getJoints().front(), PhysicsHelper::point2cpv(anchr));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsJointLimit::getAnchr2() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpSlideJointGetAnchr2(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpSlideJointGetAnchr2(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointLimit::setAnchr2(const Vec2& anchr)
{
<<<<<<< HEAD
    cpSlideJointSetAnchr1(_cpConstraints.front(), PhysicsHelper::point2cpv(anchr));
=======
    cpSlideJointSetAnchr1(_info->getJoints().front(), PhysicsHelper::point2cpv(anchr));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointDistance* PhysicsJointDistance::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointDistance();

    if (joint && joint->init(a, b))
    {
        joint->_anchr1 = anchr1;
        joint->_anchr2 = anchr2;

        return joint;
    }

=======
    PhysicsJointDistance* joint = new PhysicsJointDistance();
    
    if (joint && joint->init(a, b, anchr1, anchr2))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointDistance::createConstraints()
{
    do
    {
        auto joint = cpPinJointNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::point2cpv(_anchr1),
            PhysicsHelper::point2cpv(_anchr2));
        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointDistance::init(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpPinJointNew(getBodyInfo(a)->getBody(),
                                            getBodyInfo(b)->getBody(),
                                            PhysicsHelper::point2cpv(anchr1),
                                            PhysicsHelper::point2cpv(anchr2));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointDistance::getDistance() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpPinJointGetDist(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpPinJointGetDist(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointDistance::setDistance(float distance)
{
<<<<<<< HEAD
    cpPinJointSetDist(_cpConstraints.front(), PhysicsHelper::float2cpfloat(distance));
=======
    cpPinJointSetDist(_info->getJoints().front(), PhysicsHelper::float2cpfloat(distance));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointSpring* PhysicsJointSpring::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float stiffness, float damping)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointSpring();

    if (joint && joint->init(a, b))
    {
        joint->_anchr1 = anchr1;
        joint->_anchr2 = anchr2;
        joint->_stiffness = stiffness;
        joint->_damping = damping;

        return joint;
    }

=======
    PhysicsJointSpring* joint = new PhysicsJointSpring();
    
    if (joint && joint->init(a, b, anchr1, anchr2, stiffness, damping))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointSpring::createConstraints()
{
    do {
        auto joint = cpDampedSpringNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::point2cpv(_anchr1),
            PhysicsHelper::point2cpv(_anchr2),
            PhysicsHelper::float2cpfloat(_bodyB->local2World(_anchr1).getDistance(_bodyA->local2World(_anchr2))),
            PhysicsHelper::float2cpfloat(_stiffness),
            PhysicsHelper::float2cpfloat(_damping));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointSpring::init(PhysicsBody* a, PhysicsBody* b, const Vec2& anchr1, const Vec2& anchr2, float stiffness, float damping)
{
    do {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpDampedSpringNew(getBodyInfo(a)->getBody(),
                                                getBodyInfo(b)->getBody(),
                                                PhysicsHelper::point2cpv(anchr1),
                                                PhysicsHelper::point2cpv(anchr2),
                                                PhysicsHelper::float2cpfloat(_bodyB->local2World(anchr1).getDistance(_bodyA->local2World(anchr2))),
                                                PhysicsHelper::float2cpfloat(stiffness),
                                                PhysicsHelper::float2cpfloat(damping));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

Vec2 PhysicsJointSpring::getAnchr1() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpDampedSpringGetAnchr1(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpDampedSpringGetAnchr1(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointSpring::setAnchr1(const Vec2& anchr)
{
<<<<<<< HEAD
    cpDampedSpringSetAnchr1(_cpConstraints.front(), PhysicsHelper::point2cpv(anchr));
=======
    cpDampedSpringSetAnchr1(_info->getJoints().front(), PhysicsHelper::point2cpv(anchr));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsJointSpring::getAnchr2() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpDampedSpringGetAnchr2(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpDampedSpringGetAnchr2(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointSpring::setAnchr2(const Vec2& anchr)
{
<<<<<<< HEAD
    cpDampedSpringSetAnchr1(_cpConstraints.front(), PhysicsHelper::point2cpv(anchr));
=======
    cpDampedSpringSetAnchr1(_info->getJoints().front(), PhysicsHelper::point2cpv(anchr));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointSpring::getRestLength() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetRestLength(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetRestLength(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointSpring::setRestLength(float restLength)
{
<<<<<<< HEAD
    cpDampedSpringSetRestLength(_cpConstraints.front(), PhysicsHelper::float2cpfloat(restLength));
=======
    cpDampedSpringSetRestLength(_info->getJoints().front(), PhysicsHelper::float2cpfloat(restLength));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointSpring::getStiffness() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetStiffness(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetStiffness(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointSpring::setStiffness(float stiffness)
{
<<<<<<< HEAD
    cpDampedSpringSetStiffness(_cpConstraints.front(), PhysicsHelper::float2cpfloat(stiffness));
=======
    cpDampedSpringSetStiffness(_info->getJoints().front(), PhysicsHelper::float2cpfloat(stiffness));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointSpring::getDamping() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetDamping(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedSpringGetDamping(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointSpring::setDamping(float damping)
{
<<<<<<< HEAD
    cpDampedSpringSetDamping(_cpConstraints.front(), PhysicsHelper::float2cpfloat(damping));
=======
    cpDampedSpringSetDamping(_info->getJoints().front(), PhysicsHelper::float2cpfloat(damping));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointGroove* PhysicsJointGroove::construct(PhysicsBody* a, PhysicsBody* b, const Vec2& grooveA, const Vec2& grooveB, const Vec2& anchr2)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointGroove();

    if (joint && joint->init(a, b))
    {
        joint->_grooveA = grooveA;
        joint->_grooveB = grooveB;
        joint->_anchr2 = anchr2;

        return joint;
    }

=======
    PhysicsJointGroove* joint = new PhysicsJointGroove();
    
    if (joint && joint->init(a, b, grooveA, grooveB, anchr2))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointGroove::createConstraints()
{
    do {
        auto joint = cpGrooveJointNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::point2cpv(_grooveA),
            PhysicsHelper::point2cpv(_grooveB),
            PhysicsHelper::point2cpv(_anchr2));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointGroove::init(PhysicsBody* a, PhysicsBody* b, const Vec2& grooveA, const Vec2& grooveB, const Vec2& anchr2)
{
    do {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpGrooveJointNew(getBodyInfo(a)->getBody(),
                                               getBodyInfo(b)->getBody(),
                                               PhysicsHelper::point2cpv(grooveA),
                                               PhysicsHelper::point2cpv(grooveB),
                                               PhysicsHelper::point2cpv(anchr2));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

Vec2 PhysicsJointGroove::getGrooveA() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpGrooveJointGetGrooveA(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpGrooveJointGetGrooveA(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointGroove::setGrooveA(const Vec2& grooveA)
{
<<<<<<< HEAD
    cpGrooveJointSetGrooveA(_cpConstraints.front(), PhysicsHelper::point2cpv(grooveA));
=======
    cpGrooveJointSetGrooveA(_info->getJoints().front(), PhysicsHelper::point2cpv(grooveA));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsJointGroove::getGrooveB() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpGrooveJointGetGrooveB(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpGrooveJointGetGrooveB(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointGroove::setGrooveB(const Vec2& grooveB)
{
<<<<<<< HEAD
    cpGrooveJointSetGrooveB(_cpConstraints.front(), PhysicsHelper::point2cpv(grooveB));
=======
    cpGrooveJointSetGrooveB(_info->getJoints().front(), PhysicsHelper::point2cpv(grooveB));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsJointGroove::getAnchr2() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpGrooveJointGetAnchr2(_cpConstraints.front()));
=======
    return PhysicsHelper::cpv2point(cpGrooveJointGetAnchr2(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointGroove::setAnchr2(const Vec2& anchr2)
{
<<<<<<< HEAD
    cpGrooveJointSetAnchr2(_cpConstraints.front(), PhysicsHelper::point2cpv(anchr2));
=======
    cpGrooveJointSetAnchr2(_info->getJoints().front(), PhysicsHelper::point2cpv(anchr2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointRotarySpring* PhysicsJointRotarySpring::construct(PhysicsBody* a, PhysicsBody* b, float stiffness, float damping)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointRotarySpring();

    if (joint && joint->init(a, b))
    {
        joint->_stiffness = stiffness;
        joint->_damping = damping;

        return joint;
    }

=======
    PhysicsJointRotarySpring* joint = new PhysicsJointRotarySpring();
    
    if (joint && joint->init(a, b, stiffness, damping))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointRotarySpring::createConstraints()
{
    do {
        auto joint = cpDampedRotarySpringNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::float2cpfloat(_bodyB->getRotation() - _bodyA->getRotation()),
            PhysicsHelper::float2cpfloat(_stiffness),
            PhysicsHelper::float2cpfloat(_damping));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointRotarySpring::init(PhysicsBody* a, PhysicsBody* b, float stiffness, float damping)
{
    do {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpDampedRotarySpringNew(getBodyInfo(a)->getBody(),
                                                      getBodyInfo(b)->getBody(),
                                                      PhysicsHelper::float2cpfloat(_bodyB->getRotation() - _bodyA->getRotation()),
                                                      PhysicsHelper::float2cpfloat(stiffness),
                                                      PhysicsHelper::float2cpfloat(damping));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointRotarySpring::getRestAngle() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetRestAngle(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetRestAngle(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRotarySpring::setRestAngle(float restAngle)
{
<<<<<<< HEAD
    cpDampedRotarySpringSetRestAngle(_cpConstraints.front(), PhysicsHelper::float2cpfloat(restAngle));
=======
    cpDampedRotarySpringSetRestAngle(_info->getJoints().front(), PhysicsHelper::float2cpfloat(restAngle));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointRotarySpring::getStiffness() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetStiffness(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetStiffness(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRotarySpring::setStiffness(float stiffness)
{
<<<<<<< HEAD
    cpDampedRotarySpringSetStiffness(_cpConstraints.front(), PhysicsHelper::float2cpfloat(stiffness));
=======
    cpDampedRotarySpringSetStiffness(_info->getJoints().front(), PhysicsHelper::float2cpfloat(stiffness));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointRotarySpring::getDamping() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetDamping(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpDampedRotarySpringGetDamping(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRotarySpring::setDamping(float damping)
{
<<<<<<< HEAD
    cpDampedRotarySpringSetDamping(_cpConstraints.front(), PhysicsHelper::float2cpfloat(damping));
=======
    cpDampedRotarySpringSetDamping(_info->getJoints().front(), PhysicsHelper::float2cpfloat(damping));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointRotaryLimit* PhysicsJointRotaryLimit::construct(PhysicsBody* a, PhysicsBody* b, float min, float max)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointRotaryLimit();

    if (joint && joint->init(a, b))
    {
        joint->_min = min;
        joint->_max = max;

        return joint;
    }

=======
    PhysicsJointRotaryLimit* joint = new PhysicsJointRotaryLimit();
    
    if (joint && joint->init(a, b, min, max))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

PhysicsJointRotaryLimit* PhysicsJointRotaryLimit::construct(PhysicsBody* a, PhysicsBody* b)
{
    return construct(a, b, 0.0f, 0.0f);
}

<<<<<<< HEAD
bool PhysicsJointRotaryLimit::createConstraints()
{
    do
    {
        auto joint = cpRotaryLimitJointNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::float2cpfloat(_min),
            PhysicsHelper::float2cpfloat(_max));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointRotaryLimit::init(PhysicsBody* a, PhysicsBody* b, float min, float max)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpRotaryLimitJointNew(getBodyInfo(a)->getBody(),
                                                    getBodyInfo(b)->getBody(),
                                                    PhysicsHelper::float2cpfloat(min),
                                                    PhysicsHelper::float2cpfloat(max));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointRotaryLimit::getMin() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpRotaryLimitJointGetMin(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpRotaryLimitJointGetMin(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRotaryLimit::setMin(float min)
{
<<<<<<< HEAD
    cpRotaryLimitJointSetMin(_cpConstraints.front(), PhysicsHelper::float2cpfloat(min));
=======
    cpRotaryLimitJointSetMin(_info->getJoints().front(), PhysicsHelper::float2cpfloat(min));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointRotaryLimit::getMax() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpRotaryLimitJointGetMax(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpRotaryLimitJointGetMax(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRotaryLimit::setMax(float max)
{
<<<<<<< HEAD
    cpRotaryLimitJointSetMax(_cpConstraints.front(), PhysicsHelper::float2cpfloat(max));
=======
    cpRotaryLimitJointSetMax(_info->getJoints().front(), PhysicsHelper::float2cpfloat(max));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointRatchet* PhysicsJointRatchet::construct(PhysicsBody* a, PhysicsBody* b, float phase, float ratchet)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointRatchet();

    if (joint && joint->init(a, b))
    {
        joint->_phase = phase;
        joint->_ratchet = ratchet;

        return joint;
    }

=======
    PhysicsJointRatchet* joint = new PhysicsJointRatchet();
    
    if (joint && joint->init(a, b, phase, ratchet))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointRatchet::createConstraints()
{
    do
    {
        auto joint = cpRatchetJointNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::float2cpfloat(_phase),
            PhysicsHelper::cpfloat2float(_ratchet));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointRatchet::init(PhysicsBody* a, PhysicsBody* b, float phase, float ratchet)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpRatchetJointNew(getBodyInfo(a)->getBody(),
                                                getBodyInfo(b)->getBody(),
                                                PhysicsHelper::float2cpfloat(phase),
                                                PhysicsHelper::cpfloat2float(ratchet));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointRatchet::getAngle() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetAngle(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetAngle(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRatchet::setAngle(float angle)
{
<<<<<<< HEAD
    cpRatchetJointSetAngle(_cpConstraints.front(), PhysicsHelper::float2cpfloat(angle));
=======
    cpRatchetJointSetAngle(_info->getJoints().front(), PhysicsHelper::float2cpfloat(angle));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointRatchet::getPhase() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetPhase(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetPhase(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRatchet::setPhase(float phase)
{
<<<<<<< HEAD
    cpRatchetJointSetPhase(_cpConstraints.front(), PhysicsHelper::float2cpfloat(phase));
=======
    cpRatchetJointSetPhase(_info->getJoints().front(), PhysicsHelper::float2cpfloat(phase));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointRatchet::getRatchet() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetRatchet(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpRatchetJointGetRatchet(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointRatchet::setRatchet(float ratchet)
{
<<<<<<< HEAD
    cpRatchetJointSetRatchet(_cpConstraints.front(), PhysicsHelper::float2cpfloat(ratchet));
}

PhysicsJointGear* PhysicsJointGear::construct(PhysicsBody* a, PhysicsBody* b, float phase, float ratio)
{
    auto joint = new (std::nothrow) PhysicsJointGear();

    if (joint && joint->init(a, b))
    {
        joint->_phase = phase;
        joint->_ratio = ratio;

        return joint;
    }

=======
    cpRatchetJointSetRatchet(_info->getJoints().front(), PhysicsHelper::float2cpfloat(ratchet));
}

PhysicsJointGear* PhysicsJointGear::construct(PhysicsBody* a, PhysicsBody* b, float phase, float ratchet)
{
    PhysicsJointGear* joint = new PhysicsJointGear();
    
    if (joint && joint->init(a, b, phase, ratchet))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointGear::createConstraints()
{
    do
    {
        auto joint = cpGearJointNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::float2cpfloat(_phase),
            PhysicsHelper::float2cpfloat(_ratio));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointGear::init(PhysicsBody* a, PhysicsBody* b, float phase, float ratio)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpGearJointNew(getBodyInfo(a)->getBody(),
                                             getBodyInfo(b)->getBody(),
                                             PhysicsHelper::float2cpfloat(phase),
                                             PhysicsHelper::float2cpfloat(ratio));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointGear::getPhase() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpGearJointGetPhase(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpGearJointGetPhase(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointGear::setPhase(float phase)
{
<<<<<<< HEAD
    cpGearJointSetPhase(_cpConstraints.front(), PhysicsHelper::float2cpfloat(phase));
=======
    cpGearJointSetPhase(_info->getJoints().front(), PhysicsHelper::float2cpfloat(phase));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsJointGear::getRatio() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpGearJointGetRatio(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpGearJointGetRatio(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointGear::setRatio(float ratio)
{
<<<<<<< HEAD
    cpGearJointSetRatio(_cpConstraints.front(), PhysicsHelper::float2cpfloat(ratio));
=======
    cpGearJointSetRatio(_info->getJoints().front(), PhysicsHelper::float2cpfloat(ratio));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsJointMotor* PhysicsJointMotor::construct(PhysicsBody* a, PhysicsBody* b, float rate)
{
<<<<<<< HEAD
    auto joint = new (std::nothrow) PhysicsJointMotor();

    if (joint && joint->init(a, b))
    {
        joint->_rate = rate;

        return joint;
    }

=======
    PhysicsJointMotor* joint = new PhysicsJointMotor();
    
    if (joint && joint->init(a, b, rate))
    {
        return joint;
    }
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_SAFE_DELETE(joint);
    return nullptr;
}

<<<<<<< HEAD
bool PhysicsJointMotor::createConstraints()
{
    do
    {
        auto joint = cpSimpleMotorNew(_bodyA->getCPBody(),
            _bodyB->getCPBody(),
            PhysicsHelper::float2cpfloat(_rate));

        CC_BREAK_IF(joint == nullptr);
        _cpConstraints.push_back(joint);

        return true;
    } while (false);

=======
bool PhysicsJointMotor::init(PhysicsBody* a, PhysicsBody* b, float rate)
{
    do
    {
        CC_BREAK_IF(!PhysicsJoint::init(a, b));
        
        cpConstraint* joint = cpSimpleMotorNew(getBodyInfo(a)->getBody(),
                                             getBodyInfo(b)->getBody(),
                                             PhysicsHelper::float2cpfloat(rate));
        
        CC_BREAK_IF(joint == nullptr);
        
        _info->add(joint);
        
        return true;
    } while (false);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return false;
}

float PhysicsJointMotor::getRate() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpSimpleMotorGetRate(_cpConstraints.front()));
=======
    return PhysicsHelper::cpfloat2float(cpSimpleMotorGetRate(_info->getJoints().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsJointMotor::setRate(float rate)
{
<<<<<<< HEAD
    cpSimpleMotorSetRate(_cpConstraints.front(), PhysicsHelper::float2cpfloat(rate));
=======
    cpSimpleMotorSetRate(_info->getJoints().front(), PhysicsHelper::float2cpfloat(rate));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

NS_CC_END
#endif // CC_USE_PHYSICS
