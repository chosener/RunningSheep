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

#include "physics/CCPhysicsShape.h"
#if CC_USE_PHYSICS

#include <climits>
<<<<<<< HEAD
#include <unordered_map>
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#include "chipmunk.h"
#include "chipmunk_unsafe.h"

<<<<<<< HEAD
#include "CCPhysicsBody.h"
#include "CCPhysicsWorld.h"
#include "CCPhysicsHelper.h"

NS_CC_BEGIN
extern const float PHYSICS_INFINITY;
std::unordered_map<cpShape*, PhysicsShape*> s_physicsShapeMap;
static cpBody* s_sharedBody = nullptr;

PhysicsShape::PhysicsShape()
: _body(nullptr)
=======
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsWorld.h"

#include "chipmunk/CCPhysicsBodyInfo_chipmunk.h"
#include "chipmunk/CCPhysicsShapeInfo_chipmunk.h"
#include "chipmunk/CCPhysicsHelper_chipmunk.h"

NS_CC_BEGIN
extern const float PHYSICS_INFINITY;

PhysicsShape::PhysicsShape()
: _body(nullptr)
, _info(nullptr)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
, _type(Type::UNKNOWN)
, _area(0.0f)
, _mass(0.0f)
, _moment(0.0f)
, _scaleX(1.0f)
, _scaleY(1.0f)
, _newScaleX(1.0f)
, _newScaleY(1.0f)
<<<<<<< HEAD
=======
, _dirty(false)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
, _tag(0)
, _categoryBitmask(UINT_MAX)
, _collisionBitmask(UINT_MAX)
, _contactTestBitmask(0)
, _group(0)
{
<<<<<<< HEAD
    if (s_sharedBody == nullptr)
    {
        s_sharedBody = cpBodyNewStatic();
    }
=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

PhysicsShape::~PhysicsShape()
{
<<<<<<< HEAD
    for (auto shape : _cpShapes)
    {
        s_physicsShapeMap.erase(shape);

        cpShapeFree(shape);
    }
=======
    CC_SAFE_DELETE(_info);
}

bool PhysicsShape::init(Type type)
{
    _info = new PhysicsShapeInfo(this);
    if (_info == nullptr) return false;
    
    _type = type;
    
    return true;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsShape::setMass(float mass)
{
    if (mass < 0)
    {
        return;
    }
    
    if (_body)
    {
        _body->addMass(-_mass);
        _body->addMass(mass);
    };
    
    _mass = mass;
}

void PhysicsShape::setMoment(float moment)
{
    if (moment < 0)
    {
        return;
    }
    
    if (_body)
    {
        _body->addMoment(-_moment);
        _body->addMoment(moment);
    };
    
    _moment = moment;
}

void PhysicsShape::setMaterial(const PhysicsMaterial& material)
{
    setDensity(material.density);
    setRestitution(material.restitution);
    setFriction(material.friction);
}

<<<<<<< HEAD
void PhysicsShape::setScale(float scaleX, float scaleY)
{
    if (_scaleX != scaleX || _scaleY != scaleY)
    {
        if (_type == Type::CIRCLE && scaleX != scaleY)
        {
            CCLOG("PhysicsShapeCircle WARNING: CANNOT support setScale with different x and y");
            return;
        }
        _newScaleX = scaleX;
        _newScaleY = scaleY;
        updateScale();
    }
}

void PhysicsShape::updateScale()
{
    _scaleX = _newScaleX;
    _scaleY = _newScaleY;
}

void PhysicsShape::addShape(cpShape* shape)
{
    if (shape)
    {
        cpShapeSetGroup(shape, _group);
        _cpShapes.push_back(shape);
        s_physicsShapeMap.insert(std::pair<cpShape*, PhysicsShape*>(shape, this));
=======
PhysicsBodyInfo* PhysicsShape::bodyInfo() const
{
    if (_body != nullptr)
    {
        return _body->_info;
    }else
    {
        return nullptr;
    }
}

void PhysicsShape::setScale(float scale)
{
    setScaleX(scale);
    setScaleY(scale);
}

void PhysicsShape::setScale(float scaleX, float scaleY)
{
    setScaleX(scaleX);
    setScaleY(scaleY);
}

void PhysicsShape::setScaleX(float scaleX)
{
    if (_scaleX == scaleX)
    {
        return;
    }
    
    _newScaleX = scaleX;
    _dirty = true;
}

void PhysicsShape::setScaleY(float scaleY)
{
    if (_scaleY == scaleY)
    {
        return;
    }
    
    _newScaleY = scaleY;
    _dirty = true;
}

void PhysicsShape::update(float delta)
{
    CC_UNUSED_PARAM(delta);
    
    if (_dirty)
    {
        _scaleX = _newScaleX;
        _scaleY = _newScaleY;
        _dirty = false;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
}

PhysicsShapeCircle::PhysicsShapeCircle()
{
    
}

PhysicsShapeCircle::~PhysicsShapeCircle()
{
    
}

PhysicsShapeBox::PhysicsShapeBox()
{
    
}

PhysicsShapeBox::~PhysicsShapeBox()
{
    
}

PhysicsShapePolygon::PhysicsShapePolygon()
{
    
}

PhysicsShapePolygon::~PhysicsShapePolygon()
{
    
}

PhysicsShapeEdgeBox::PhysicsShapeEdgeBox()
{
    
}

PhysicsShapeEdgeBox::~PhysicsShapeEdgeBox()
{
    
}

PhysicsShapeEdgeChain::PhysicsShapeEdgeChain()
{
    
}

PhysicsShapeEdgeChain::~PhysicsShapeEdgeChain()
{
    
}

PhysicsShapeEdgePolygon::PhysicsShapeEdgePolygon()
{
    
}

PhysicsShapeEdgePolygon::~PhysicsShapeEdgePolygon()
{
    
}

PhysicsShapeEdgeSegment::PhysicsShapeEdgeSegment()
{
    
}

PhysicsShapeEdgeSegment::~PhysicsShapeEdgeSegment()
{
    
}

void PhysicsShape::setDensity(float density)
{
    if (density < 0)
    {
        return;
    }
    
    _material.density = density;
    
    if (_material.density == PHYSICS_INFINITY)
    {
        setMass(PHYSICS_INFINITY);
    }else if (_area > 0)
    {
        setMass(PhysicsHelper::float2cpfloat(_material.density * _area));
    }
}

void PhysicsShape::setRestitution(float restitution)
{
    _material.restitution = restitution;
    
<<<<<<< HEAD
    for (cpShape* shape : _cpShapes)
=======
    for (cpShape* shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        cpShapeSetElasticity(shape, PhysicsHelper::float2cpfloat(restitution));
    }
}

void PhysicsShape::setFriction(float friction)
{
    _material.friction = friction;
    
<<<<<<< HEAD
    for (cpShape* shape : _cpShapes)
=======
    for (cpShape* shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        cpShapeSetFriction(shape, PhysicsHelper::float2cpfloat(friction));
    }
}


void PhysicsShape::recenterPoints(Vec2* points, int count, const Vec2& center)
{
    cpVect* cpvs = new cpVect[count];
    cpRecenterPoly(count, PhysicsHelper::points2cpvs(points, cpvs, count));
    PhysicsHelper::cpvs2points(cpvs, points, count);
    delete[] cpvs;
    
    if (center != Vec2::ZERO)
    {
        for (int i = 0; i < count; ++i)
        {
            points[i] += center;
        }
    }
}

Vec2 PhysicsShape::getPolyonCenter(const Vec2* points, int count)
{
    cpVect* cpvs = new cpVect[count];
    cpVect center = cpCentroidForPoly(count, PhysicsHelper::points2cpvs(points, cpvs, count));
    delete[] cpvs;
    
    return PhysicsHelper::cpv2point(center);
}

void PhysicsShape::setBody(PhysicsBody *body)
{
    // already added
<<<<<<< HEAD
    if (body && _body == body)
=======
    if (body != nullptr && _body == body)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }
    
<<<<<<< HEAD
    if (_body)
=======
    if (_body != nullptr)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        _body->removeShape(this);
    }
    
<<<<<<< HEAD
    for (auto shape : _cpShapes)
    {
        cpShapeSetBody(shape, body == nullptr ? s_sharedBody : body->_cpBody);
    }
    _body = body;
=======
    if (body == nullptr)
    {
        _info->setBody(nullptr);
        _body = nullptr;
    }else
    {
        _info->setBody(body->_info->getBody());
        _body = body;
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

// PhysicsShapeCircle
PhysicsShapeCircle* PhysicsShapeCircle::create(float radius, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset/* = Vec2(0, 0)*/)
{
<<<<<<< HEAD
    PhysicsShapeCircle* shape = new (std::nothrow) PhysicsShapeCircle();
=======
    PhysicsShapeCircle* shape = new PhysicsShapeCircle();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(radius, material, offset))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapeCircle::init(float radius, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset /*= Vec2(0, 0)*/)
{
    do
    {
<<<<<<< HEAD
        _type = Type::CIRCLE;
        
        auto shape = cpCircleShapeNew(s_sharedBody, radius, PhysicsHelper::point2cpv(offset));
        
        CC_BREAK_IF(shape == nullptr);
        
        addShape(shape);
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::CIRCLE));
        
        cpShape* shape = cpCircleShapeNew(_info->getSharedBody(), radius, PhysicsHelper::point2cpv(offset));
        
        CC_BREAK_IF(shape == nullptr);
        
        _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        _area = calculateArea();
        _mass = material.density == PHYSICS_INFINITY ? PHYSICS_INFINITY : material.density * _area;
        _moment = calculateDefaultMoment();
        
        setMaterial(material);
        return true;
    } while (false);
    
    return false;
}

float PhysicsShapeCircle::calculateArea(float radius)
{
    return PhysicsHelper::cpfloat2float(cpAreaForCircle(0, radius));
}

float PhysicsShapeCircle::calculateMoment(float mass, float radius, const Vec2& offset)
{
    return mass == PHYSICS_INFINITY ? PHYSICS_INFINITY
    : PhysicsHelper::cpfloat2float(cpMomentForCircle(PhysicsHelper::float2cpfloat(mass),
                                                     0,
                                                     PhysicsHelper::float2cpfloat(radius),
                                                     PhysicsHelper::point2cpv(offset)));
}

float PhysicsShapeCircle::calculateArea()
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpAreaForCircle(0, cpCircleShapeGetRadius(_cpShapes.front())));
=======
    return PhysicsHelper::cpfloat2float(cpAreaForCircle(0, cpCircleShapeGetRadius(_info->getShapes().front())));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

float PhysicsShapeCircle::calculateDefaultMoment()
{
<<<<<<< HEAD
    auto shape = _cpShapes.front();
=======
    cpShape* shape = _info->getShapes().front();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    return _mass == PHYSICS_INFINITY ? PHYSICS_INFINITY
    : PhysicsHelper::cpfloat2float(cpMomentForCircle(PhysicsHelper::float2cpfloat(_mass),
                                                     0,
                                                     cpCircleShapeGetRadius(shape),
                                                     cpCircleShapeGetOffset(shape)));
}

float PhysicsShapeCircle::getRadius() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpfloat2float(cpCircleShapeGetRadius(_cpShapes.front()));
=======
    return PhysicsHelper::cpfloat2float(cpCircleShapeGetRadius(_info->getShapes().front()));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsShapeCircle::getOffset()
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpCircleShapeGetOffset(_cpShapes.front()));
}

void PhysicsShapeCircle::updateScale()
{
    cpFloat factor = std::abs(PhysicsHelper::float2cpfloat(_newScaleX / _scaleX));

    cpShape* shape = _cpShapes.front();
    cpVect v = cpCircleShapeGetOffset(shape);
    v = cpvmult(v, PhysicsHelper::float2cpfloat(factor));
    ((cpCircleShape*)shape)->c = v;

    cpCircleShapeSetRadius(shape, cpCircleShapeGetRadius(shape) * factor);

    PhysicsShape::updateScale();
=======
    return PhysicsHelper::cpv2point(cpCircleShapeGetOffset(_info->getShapes().front()));
}

void PhysicsShapeCircle::setScale(float scale)
{
    if (_scaleX == scale)
    {
        return;
    }
    
    _newScaleX = _newScaleY = scale;
    _dirty = true;
}

void PhysicsShapeCircle::setScale(float scaleX, float scaleY)
{
    if (scaleX != scaleY)
    {
        CCLOG("PhysicsShapeCircle WARNING: CANNOT support setScale with different x and y");
    }
    
    if (_scaleX == scaleX)
    {
        return;
    }
    
    _newScaleX = _newScaleY = scaleX;
    _dirty = true;
}

void PhysicsShapeCircle::setScaleX(float scale)
{
    CCLOG("PhysicsShapeCircle WARNING: CANNOT support setScaleX");
    
    setScale(scale);
}

void PhysicsShapeCircle::setScaleY(float scale)
{
    CCLOG("PhysicsShapeCircle WARNING: CANNOT support setScaleY");
    
    setScale(scale);
}

void PhysicsShapeCircle::update(float delta)
{
    
    if (_dirty)
    {
        cpFloat factor = std::abs(PhysicsHelper::float2cpfloat( _newScaleX / _scaleX ));
        
        cpShape* shape = _info->getShapes().front();
        cpVect v = cpCircleShapeGetOffset(shape);
        v = cpvmult(v, PhysicsHelper::float2cpfloat(factor));
        ((cpCircleShape*)shape)->c = v;
        
        cpCircleShapeSetRadius(shape, cpCircleShapeGetRadius(shape) * factor);
    }
    
    PhysicsShape::update(delta);
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

// PhysicsShapeEdgeSegment
PhysicsShapeEdgeSegment* PhysicsShapeEdgeSegment::create(const Vec2& a, const Vec2& b, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
<<<<<<< HEAD
    PhysicsShapeEdgeSegment* shape = new (std::nothrow) PhysicsShapeEdgeSegment();
=======
    PhysicsShapeEdgeSegment* shape = new PhysicsShapeEdgeSegment();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(a, b, material, border))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapeEdgeSegment::init(const Vec2& a, const Vec2& b, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
    do
    {
<<<<<<< HEAD
        _type = Type::EDGESEGMENT;
        
        auto shape = cpSegmentShapeNew(s_sharedBody,
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::EDGESEGMENT));
        
        cpShape* shape = cpSegmentShapeNew(_info->getSharedBody(),
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
                                           PhysicsHelper::point2cpv(a),
                                           PhysicsHelper::point2cpv(b),
                                           PhysicsHelper::float2cpfloat(border));
        
        CC_BREAK_IF(shape == nullptr);
        
<<<<<<< HEAD
        addShape(shape);
=======
        _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        _mass = PHYSICS_INFINITY;
        _moment = PHYSICS_INFINITY;
        
<<<<<<< HEAD
=======
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setMaterial(material);
        
        return true;
    } while (false);
    
    return false;
}

Vec2 PhysicsShapeEdgeSegment::getPointA() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(((cpSegmentShape*)(_cpShapes.front()))->ta);
=======
    return PhysicsHelper::cpv2point(((cpSegmentShape*)(_info->getShapes().front()))->ta);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsShapeEdgeSegment::getPointB() const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(((cpSegmentShape*)(_cpShapes.front()))->tb);
=======
    return PhysicsHelper::cpv2point(((cpSegmentShape*)(_info->getShapes().front()))->tb);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsShapeEdgeSegment::getCenter()
{
<<<<<<< HEAD
    auto a = PhysicsHelper::cpv2point(cpSegmentShapeGetA(_cpShapes.front()));
    auto b = PhysicsHelper::cpv2point(cpSegmentShapeGetB(_cpShapes.front()));
    return ( a + b ) / 2;
}

void PhysicsShapeEdgeSegment::updateScale()
{
    cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
    cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);

    cpShape* shape = _cpShapes.front();
    cpVect a = cpSegmentShapeGetA(shape);
    a.x *= factorX;
    a.y *= factorY;
    cpVect b = cpSegmentShapeGetB(shape);
    b.x *= factorX;
    b.y *= factorY;
    cpSegmentShapeSetEndpoints(shape, a, b);

    PhysicsShape::updateScale();
=======
    Vec2 a = PhysicsHelper::cpv2point(cpSegmentShapeGetA(_info->getShapes().front()));
    Vec2 b = PhysicsHelper::cpv2point(cpSegmentShapeGetB(_info->getShapes().front()));
    return ( a + b ) / 2;
}

void PhysicsShapeEdgeSegment::update(float delta)
{
    if (_dirty)
    {
        cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
        cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);
        
        cpShape* shape = _info->getShapes().front();
        cpVect a = cpSegmentShapeGetA(shape);
        a.x *= factorX;
        a.y *= factorY;
        cpVect b = cpSegmentShapeGetB(shape);
        b.x *= factorX;
        b.y *= factorY;
        cpSegmentShapeSetEndpoints(shape, a, b);
    }
    
    PhysicsShape::update(delta);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

// PhysicsShapeBox
PhysicsShapeBox* PhysicsShapeBox::create(const Size& size, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset/* = Vec2(0, 0)*/)
{
<<<<<<< HEAD
    PhysicsShapeBox* shape = new (std::nothrow) PhysicsShapeBox();
=======
    PhysicsShapeBox* shape = new PhysicsShapeBox();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(size, material, offset))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapeBox::init(const Size& size, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset /*= Vec2(0, 0)*/)
{
    do
    {
<<<<<<< HEAD
        _type = Type::BOX;
        
        auto wh = PhysicsHelper::size2cpv(size);
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::BOX));
        
        cpVect wh = PhysicsHelper::size2cpv(size);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        cpVect vec[4] =
        {
            {-wh.x/2.0f, -wh.y/2.0f}, {-wh.x/2.0f, wh.y/2.0f}, {wh.x/2.0f, wh.y/2.0f}, {wh.x/2.0f, -wh.y/2.0f}
        };
        
<<<<<<< HEAD
        auto shape = cpPolyShapeNew(s_sharedBody, 4, vec, PhysicsHelper::point2cpv(offset));
        
        CC_BREAK_IF(shape == nullptr);
        
        addShape(shape);
=======
        cpShape* shape = cpPolyShapeNew(_info->getSharedBody(), 4, vec, PhysicsHelper::point2cpv(offset));
        
        CC_BREAK_IF(shape == nullptr);
        
        _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        _area = calculateArea();
        _mass = material.density == PHYSICS_INFINITY ? PHYSICS_INFINITY : material.density * _area;
        _moment = calculateDefaultMoment();
        
        setMaterial(material);
        
        return true;
    } while (false);
    
    return false;
}

Size PhysicsShapeBox::getSize() const
{
<<<<<<< HEAD
    cpShape* shape = _cpShapes.front();
=======
    cpShape* shape = _info->getShapes().front();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return PhysicsHelper::cpv2size(cpv(cpvdist(cpPolyShapeGetVert(shape, 1), cpPolyShapeGetVert(shape, 2)),
                                       cpvdist(cpPolyShapeGetVert(shape, 0), cpPolyShapeGetVert(shape, 1))));
}

// PhysicsShapePolygon
PhysicsShapePolygon* PhysicsShapePolygon::create(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset/* = Vec2(0, 0)*/)
{
<<<<<<< HEAD
    PhysicsShapePolygon* shape = new (std::nothrow) PhysicsShapePolygon();
=======
    PhysicsShapePolygon* shape = new PhysicsShapePolygon();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(points, count, material, offset))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapePolygon::init(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, const Vec2& offset/* = Vec2(0, 0)*/)
{
    do
    {
<<<<<<< HEAD
        _type = Type::POLYGEN;
        
        auto vecs = new cpVect[count];
        PhysicsHelper::points2cpvs(points, vecs, count);
        auto shape = cpPolyShapeNew(s_sharedBody, count, vecs, PhysicsHelper::point2cpv(offset));
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::POLYGEN));
        
        cpVect* vecs = new cpVect[count];
        PhysicsHelper::points2cpvs(points, vecs, count);
        cpShape* shape = cpPolyShapeNew(_info->getSharedBody(), count, vecs, PhysicsHelper::point2cpv(offset));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        CC_SAFE_DELETE_ARRAY(vecs);
        
        CC_BREAK_IF(shape == nullptr);
        
<<<<<<< HEAD
        addShape(shape);
=======
        _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        _area = calculateArea();
        _mass = material.density == PHYSICS_INFINITY ? PHYSICS_INFINITY : material.density * _area;
        _moment = calculateDefaultMoment();
        
        setMaterial(material);
        
        return true;
    } while (false);
    
    return false;
}

float PhysicsShapePolygon::calculateArea(const Vec2* points, int count)
{
    cpVect* vecs = new cpVect[count];
    PhysicsHelper::points2cpvs(points, vecs, count);
    float area = PhysicsHelper::cpfloat2float(cpAreaForPoly(count, vecs));
    CC_SAFE_DELETE_ARRAY(vecs);
    
    return area;
}

float PhysicsShapePolygon::calculateMoment(float mass, const Vec2* points, int count, const Vec2& offset)
{
    cpVect* vecs = new cpVect[count];
    PhysicsHelper::points2cpvs(points, vecs, count);
    float moment = mass == PHYSICS_INFINITY ? PHYSICS_INFINITY
    : PhysicsHelper::cpfloat2float(cpMomentForPoly(mass, count, vecs, PhysicsHelper::point2cpv(offset)));
    CC_SAFE_DELETE_ARRAY(vecs);
    
    return moment;
}

float PhysicsShapePolygon::calculateArea()
{
<<<<<<< HEAD
    auto shape = _cpShapes.front();
=======
    cpShape* shape = _info->getShapes().front();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return PhysicsHelper::cpfloat2float(cpAreaForPoly(((cpPolyShape*)shape)->numVerts, ((cpPolyShape*)shape)->verts));
}

float PhysicsShapePolygon::calculateDefaultMoment()
{
<<<<<<< HEAD
    auto shape = _cpShapes.front();
=======
    cpShape* shape = _info->getShapes().front();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return _mass == PHYSICS_INFINITY ? PHYSICS_INFINITY
    : PhysicsHelper::cpfloat2float(cpMomentForPoly(_mass, ((cpPolyShape*)shape)->numVerts, ((cpPolyShape*)shape)->verts, cpvzero));
}

Vec2 PhysicsShapePolygon::getPoint(int i) const
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpPolyShapeGetVert(_cpShapes.front(), i));
=======
    return PhysicsHelper::cpv2point(cpPolyShapeGetVert(_info->getShapes().front(), i));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsShapePolygon::getPoints(Vec2* outPoints) const
{
<<<<<<< HEAD
    auto shape = _cpShapes.front();
=======
    cpShape* shape = _info->getShapes().front();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    PhysicsHelper::cpvs2points(((cpPolyShape*)shape)->verts, outPoints, ((cpPolyShape*)shape)->numVerts);
}

int PhysicsShapePolygon::getPointsCount() const
{
<<<<<<< HEAD
    return ((cpPolyShape*)_cpShapes.front())->numVerts;
=======
    return ((cpPolyShape*)_info->getShapes().front())->numVerts;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Vec2 PhysicsShapePolygon::getCenter()
{
<<<<<<< HEAD
    return PhysicsHelper::cpv2point(cpCentroidForPoly(((cpPolyShape*)_cpShapes.front())->numVerts, ((cpPolyShape*)_cpShapes.front())->verts));
}

void PhysicsShapePolygon::updateScale()
{
    cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
    cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);

    auto shape = _cpShapes.front();
    int count = cpPolyShapeGetNumVerts(shape);
    cpVect* vects = ((cpPolyShape*)shape)->verts;
    cpSplittingPlane* planes = ((cpPolyShape*)shape)->planes;

    for (int i = 0; i < count; ++i)
    {
        vects[i].x *= factorX;
        vects[i].y *= factorY;
    }

    // convert hole to clockwise
    if (factorX * factorY < 0)
    {
        for (int i = 0; i < count / 2; ++i)
        {
            cpVect v = vects[i];
            vects[i] = vects[count - i - 1];
            vects[count - i - 1] = v;
        }
    }

    for (int i = 0; i < count; ++i)
    {
        cpVect n = cpvnormalize(cpvperp(cpvsub(vects[i], vects[(i + 1) % count])));

        planes[i].n = n;
        planes[i].d = cpvdot(n, vects[i]);
    }
    
    PhysicsShape::updateScale();
=======
    return PhysicsHelper::cpv2point(cpCentroidForPoly(((cpPolyShape*)_info->getShapes().front())->numVerts, ((cpPolyShape*)_info->getShapes().front())->verts));
}

void PhysicsShapePolygon::update(float delta)
{
    if (_dirty)
    {
        cpFloat factorX = PhysicsHelper::float2cpfloat( _newScaleX / _scaleX );
        cpFloat factorY = PhysicsHelper::float2cpfloat( _newScaleY / _scaleY );
        
        cpShape* shape = _info->getShapes().front();
        int count = cpPolyShapeGetNumVerts(shape);
        cpVect* vects = ((cpPolyShape*)shape)->verts;
        cpSplittingPlane* planes = ((cpPolyShape*)shape)->planes;

        for (int i = 0; i < count ; ++i)
        {
            vects[i].x *= factorX;
            vects[i].y *= factorY;
        }
        
        // convert hole to clockwise
        if ( factorX * factorY < 0 )
        {
            for (int i = 0; i < count / 2; ++i)
            {
                cpVect v = vects[i];
                vects[i] = vects[count - i - 1];
                vects[count - i - 1] = v;
            }
        }
        
        for (int i = 0; i < count; ++i)
        {
            cpVect n = cpvnormalize(cpvperp(cpvsub(vects[i], vects[(i + 1) % count])));
            
            planes[i].n = n;
            planes[i].d = cpvdot(n, vects[i]);
        }
    }
    
    PhysicsShape::update(delta);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

// PhysicsShapeEdgeBox
PhysicsShapeEdgeBox* PhysicsShapeEdgeBox::create(const Size& size, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/, const Vec2& offset/* = Vec2(0, 0)*/)
{
<<<<<<< HEAD
    PhysicsShapeEdgeBox* shape = new (std::nothrow) PhysicsShapeEdgeBox();
=======
    PhysicsShapeEdgeBox* shape = new PhysicsShapeEdgeBox();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(size, material, border, offset))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapeEdgeBox::init(const Size& size, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/, const Vec2& offset/*= Vec2(0, 0)*/)
{
    do
    {
<<<<<<< HEAD
        _type = Type::EDGEBOX;
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::EDGEBOX));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        cpVect vec[4] = {};
        vec[0] = PhysicsHelper::point2cpv(Vec2(-size.width/2+offset.x, -size.height/2+offset.y));
        vec[1] = PhysicsHelper::point2cpv(Vec2(+size.width/2+offset.x, -size.height/2+offset.y));
        vec[2] = PhysicsHelper::point2cpv(Vec2(+size.width/2+offset.x, +size.height/2+offset.y));
        vec[3] = PhysicsHelper::point2cpv(Vec2(-size.width/2+offset.x, +size.height/2+offset.y));
        
        int i = 0;
        for (; i < 4; ++i)
        {
<<<<<<< HEAD
            auto shape = cpSegmentShapeNew(s_sharedBody, vec[i], vec[(i + 1) % 4],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
            addShape(shape);
=======
            cpShape* shape = cpSegmentShapeNew(_info->getSharedBody(), vec[i], vec[(i+1)%4],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
            _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        CC_BREAK_IF(i < 4);
        
        _mass = PHYSICS_INFINITY;
        _moment = PHYSICS_INFINITY;
        
        setMaterial(material);
        
        return true;
    } while (false);
    
    return false;
}

// PhysicsShapeEdgeBox
PhysicsShapeEdgePolygon* PhysicsShapeEdgePolygon::create(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
<<<<<<< HEAD
    PhysicsShapeEdgePolygon* shape = new (std::nothrow) PhysicsShapeEdgePolygon();
=======
    PhysicsShapeEdgePolygon* shape = new PhysicsShapeEdgePolygon();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(points, count, material, border))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

bool PhysicsShapeEdgePolygon::init(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
    cpVect* vec = nullptr;
    do
    {
<<<<<<< HEAD
        _type = Type::EDGEPOLYGEN;
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::EDGEPOLYGEN));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        vec = new cpVect[count];
        PhysicsHelper::points2cpvs(points, vec, count);
        
        int i = 0;
        for (; i < count; ++i)
        {
<<<<<<< HEAD
            auto shape = cpSegmentShapeNew(s_sharedBody, vec[i], vec[(i + 1) % count],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
            cpShapeSetElasticity(shape, 1.0f);
            cpShapeSetFriction(shape, 1.0f);
            addShape(shape);
=======
            cpShape* shape = cpSegmentShapeNew(_info->getSharedBody(), vec[i], vec[(i+1)%count],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
			cpShapeSetElasticity(shape, 1.0f);
			cpShapeSetFriction(shape, 1.0f);
            _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        CC_SAFE_DELETE_ARRAY(vec);
        
        CC_BREAK_IF(i < count);
        
        _mass = PHYSICS_INFINITY;
        _moment = PHYSICS_INFINITY;
        
        setMaterial(material);
        
        return true;
    } while (false);
    
    CC_SAFE_DELETE_ARRAY(vec);
    
    return false;
}

Vec2 PhysicsShapeEdgePolygon::getCenter()
{
<<<<<<< HEAD
    int count = (int)_cpShapes.size();
    cpVect* points = new cpVect[count];
    int i = 0;
    for(auto shape : _cpShapes)
=======
    int count = (int)_info->getShapes().size();
    cpVect* points = new cpVect[count];
    int i = 0;
    for(auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        points[i++] = ((cpSegmentShape*)shape)->a;
    }
    
    Vec2 center = PhysicsHelper::cpv2point(cpCentroidForPoly(count, points));
    delete[] points;
    
    return center;
}

void PhysicsShapeEdgePolygon::getPoints(cocos2d::Vec2 *outPoints) const
{
    int i = 0;
<<<<<<< HEAD
    for(auto shape : _cpShapes)
=======
    for(auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        outPoints[i++] = PhysicsHelper::cpv2point(((cpSegmentShape*)shape)->a);
    }
}

int PhysicsShapeEdgePolygon::getPointsCount() const
{
<<<<<<< HEAD
    return static_cast<int>(_cpShapes.size());
=======
    return static_cast<int>(_info->getShapes().size());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

// PhysicsShapeEdgeChain
PhysicsShapeEdgeChain* PhysicsShapeEdgeChain::create(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
<<<<<<< HEAD
    PhysicsShapeEdgeChain* shape = new (std::nothrow) PhysicsShapeEdgeChain();
=======
    PhysicsShapeEdgeChain* shape = new PhysicsShapeEdgeChain();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (shape && shape->init(points, count, material, border))
    {
        shape->autorelease();
        return shape;
    }
    
    CC_SAFE_DELETE(shape);
    return nullptr;
}

<<<<<<< HEAD
void PhysicsShapeEdgePolygon::updateScale()
{
    cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
    cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);

    for (auto shape : _cpShapes)
    {
        cpVect a = cpSegmentShapeGetA(shape);
        a.x *= factorX;
        a.y *= factorY;
        cpVect b = cpSegmentShapeGetB(shape);
        b.x *= factorX;
        b.y *= factorY;
        cpSegmentShapeSetEndpoints(shape, a, b);
    }
    
    PhysicsShape::updateScale();
=======
void PhysicsShapeEdgePolygon::update(float delta)
{
    if (_dirty)
    {
        cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
        cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);
        
        for(auto shape : _info->getShapes())
        {
            cpVect a = cpSegmentShapeGetA(shape);
            a.x *= factorX;
            a.y *= factorY;
            cpVect b = cpSegmentShapeGetB(shape);
            b.x *= factorX;
            b.y *= factorY;
            cpSegmentShapeSetEndpoints(shape, a, b);
        }
    }
    
    PhysicsShape::update(delta);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool PhysicsShapeEdgeChain::init(const Vec2* points, int count, const PhysicsMaterial& material/* = MaterialDefault*/, float border/* = 1*/)
{
    cpVect* vec = nullptr;
    do
    {
<<<<<<< HEAD
        _type = Type::EDGECHAIN;
=======
        CC_BREAK_IF(!PhysicsShape::init(Type::EDGECHAIN));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        
        vec = new cpVect[count];
        PhysicsHelper::points2cpvs(points, vec, count);
        
        int i = 0;
        for (; i < count - 1; ++i)
        {
<<<<<<< HEAD
            auto shape = cpSegmentShapeNew(s_sharedBody, vec[i], vec[i + 1],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
            cpShapeSetElasticity(shape, 1.0f);
            cpShapeSetFriction(shape, 1.0f);
            addShape(shape);
=======
            cpShape* shape = cpSegmentShapeNew(_info->getSharedBody(), vec[i], vec[i+1],
                                               PhysicsHelper::float2cpfloat(border));
            CC_BREAK_IF(shape == nullptr);
			cpShapeSetElasticity(shape, 1.0f);
			cpShapeSetFriction(shape, 1.0f);
            _info->add(shape);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        }
        CC_SAFE_DELETE_ARRAY(vec);
        CC_BREAK_IF(i < count - 1);
        
        _mass = PHYSICS_INFINITY;
        _moment = PHYSICS_INFINITY;
        
        setMaterial(material);
        
        return true;
    } while (false);
    
    CC_SAFE_DELETE_ARRAY(vec);
    
    return false;
}

Vec2 PhysicsShapeEdgeChain::getCenter()
{
<<<<<<< HEAD
    int count = (int)_cpShapes.size() + 1;
    cpVect* points = new cpVect[count];
    int i = 0;
    for(auto shape : _cpShapes)
=======
    int count = (int)_info->getShapes().size() + 1;
    cpVect* points = new cpVect[count];
    int i = 0;
    for(auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        points[i++] = ((cpSegmentShape*)shape)->a;
    }
    
<<<<<<< HEAD
    points[i++] = ((cpSegmentShape*)_cpShapes.back())->b;
=======
    points[i++] = ((cpSegmentShape*)_info->getShapes().back())->b;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    Vec2 center = PhysicsHelper::cpv2point(cpCentroidForPoly(count, points));
    delete[] points;
    
    return center;
}

void PhysicsShapeEdgeChain::getPoints(Vec2* outPoints) const
{
    int i = 0;
<<<<<<< HEAD
    for(auto shape : _cpShapes)
=======
    for(auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        outPoints[i++] = PhysicsHelper::cpv2point(((cpSegmentShape*)shape)->a);
    }
    
<<<<<<< HEAD
    outPoints[i++] = PhysicsHelper::cpv2point(((cpSegmentShape*)_cpShapes.back())->b);
=======
    outPoints[i++] = PhysicsHelper::cpv2point(((cpSegmentShape*)_info->getShapes().back())->b);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

int PhysicsShapeEdgeChain::getPointsCount() const
{
<<<<<<< HEAD
    return static_cast<int>(_cpShapes.size() + 1);
}

void PhysicsShapeEdgeChain::updateScale()
{
    cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
    cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);

    for (auto shape : _cpShapes)
    {
        cpVect a = cpSegmentShapeGetA(shape);
        a.x *= factorX;
        a.y *= factorY;
        cpVect b = cpSegmentShapeGetB(shape);
        b.x *= factorX;
        b.y *= factorY;
        cpSegmentShapeSetEndpoints(shape, a, b);
    }
    
    PhysicsShape::updateScale();
=======
    return static_cast<int>(_info->getShapes().size() + 1);
}

void PhysicsShapeEdgeChain::update(float delta)
{
    if (_dirty)
    {
        cpFloat factorX = PhysicsHelper::float2cpfloat(_newScaleX / _scaleX);
        cpFloat factorY = PhysicsHelper::float2cpfloat(_newScaleY / _scaleY);
        
        for(auto shape : _info->getShapes())
        {
            cpVect a = cpSegmentShapeGetA(shape);
            a.x *= factorX;
            a.y *= factorY;
            cpVect b = cpSegmentShapeGetB(shape);
            b.x *= factorX;
            b.y *= factorY;
            cpSegmentShapeSetEndpoints(shape, a, b);
        }
    }
    
    PhysicsShape::update(delta);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void PhysicsShape::setGroup(int group)
{
    if (group < 0)
    {
<<<<<<< HEAD
        for (auto shape : _cpShapes)
=======
        for (auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        {
            cpShapeSetGroup(shape, (cpGroup)group);
        }
    }
    
    _group = group;
}

bool PhysicsShape::containsPoint(const Vec2& point) const
{
<<<<<<< HEAD
    for (auto shape : _cpShapes)
=======
    for (auto shape : _info->getShapes())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        if (cpShapePointQuery(shape, PhysicsHelper::point2cpv(point)))
        {
            return true;
        }
    }
    
    return false;
}

NS_CC_END

#endif // CC_USE_PHYSICS
