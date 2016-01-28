/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
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

#include "2d/CCParticleExamples.h"
<<<<<<< HEAD
=======
#include "platform/CCImage.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "base/CCDirector.h"
#include "base/firePngData.h"
#include "renderer/CCTextureCache.h"

NS_CC_BEGIN
//
// ParticleFire
//

static Texture2D* getDefaultTexture()
{
    Texture2D* texture = nullptr;
    Image* image = nullptr;
    do 
    {
        bool ret = false;
        const std::string key = "/__firePngData";
        texture = Director::getInstance()->getTextureCache()->getTextureForKey(key);
        CC_BREAK_IF(texture != nullptr);

<<<<<<< HEAD
        image = new (std::nothrow) Image();
=======
        image = new Image();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        CC_BREAK_IF(nullptr == image);
        ret = image->initWithImageData(__firePngData, sizeof(__firePngData));
        CC_BREAK_IF(!ret);

        texture = Director::getInstance()->getTextureCache()->addImage(image, key);
    } while (0);

    CC_SAFE_RELEASE(image);

    return texture;
}

ParticleFire* ParticleFire::create()
{
<<<<<<< HEAD
    ParticleFire* ret = new (std::nothrow) ParticleFire();
=======
    ParticleFire* ret = new ParticleFire();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleFire* ParticleFire::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleFire* ret = new (std::nothrow) ParticleFire();
=======
    ParticleFire* ret = new ParticleFire();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleFire::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        this->_emitterMode = Mode::GRAVITY;

        // Gravity Mode: gravity
<<<<<<< HEAD
        this->modeA.gravity.setZero();
=======
        this->modeA.gravity = Vec2(0,0);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

        // Gravity Mode: radial acceleration
        this->modeA.radialAccel = 0;
        this->modeA.radialAccelVar = 0;

        // Gravity Mode: speed of particles
        this->modeA.speed = 60;
        this->modeA.speedVar = 20;        

        // starting angle
        _angle = 90;
        _angleVar = 10;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2.0f, 60.0f);
        this->_posVar.set(40.0f, 20.0f);
=======
        this->setPosition(Vec2(winSize.width/2, 60));
        this->_posVar = Vec2(40, 20);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

        // life of particles
        _life = 3;
        _lifeVar = 0.25f;


        // size, in pixels
        _startSize = 54.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per frame
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.76f;
        _startColor.g = 0.25f;
        _startColor.b = 0.12f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }
        
        // additive
        this->setBlendAdditive(true);
        return true;
    }
    return false;
}
//
// ParticleFireworks
//

ParticleFireworks* ParticleFireworks::create()
{
<<<<<<< HEAD
    ParticleFireworks* ret = new (std::nothrow) ParticleFireworks();
=======
    ParticleFireworks* ret = new ParticleFireworks();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleFireworks* ParticleFireworks::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleFireworks* ret = new (std::nothrow) ParticleFireworks();
=======
    ParticleFireworks* ret = new ParticleFireworks();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleFireworks::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration= DURATION_INFINITY;

        // Gravity Mode
        this->_emitterMode = Mode::GRAVITY;

        // Gravity Mode: gravity
<<<<<<< HEAD
        this->modeA.gravity.set(0.0f, -90.0f);

        // Gravity Mode:  radial
        this->modeA.radialAccel = 0.0f;
        this->modeA.radialAccelVar = 0.0f;

        //  Gravity Mode: speed of particles
        this->modeA.speed = 180.0f;
        this->modeA.speedVar = 50.0f;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
        this->setPosition(winSize.width/2, winSize.height/2);

        // angle
        this->_angle= 90.0f;
        this->_angleVar = 20.0f;

        // life of particles
        this->_life = 3.5f;
        this->_lifeVar = 1.0f;
=======
        this->modeA.gravity = Vec2(0,-90);

        // Gravity Mode:  radial
        this->modeA.radialAccel = 0;
        this->modeA.radialAccelVar = 0;

        //  Gravity Mode: speed of particles
        this->modeA.speed = 180;
        this->modeA.speedVar = 50;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));

        // angle
        this->_angle= 90;
        this->_angleVar = 20;

        // life of particles
        this->_life = 3.5f;
        this->_lifeVar = 1;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

        // emits per frame
        this->_emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.5f;
        _startColor.g = 0.5f;
        _startColor.b = 0.5f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.5f;
        _startColorVar.g = 0.5f;
        _startColorVar.b = 0.5f;
        _startColorVar.a = 0.1f;
        _endColor.r = 0.1f;
        _endColor.g = 0.1f;
        _endColor.b = 0.1f;
        _endColor.a = 0.2f;
        _endColorVar.r = 0.1f;
        _endColorVar.g = 0.1f;
        _endColorVar.b = 0.1f;
        _endColorVar.a = 0.2f;

        // size, in pixels
        _startSize = 8.0f;
        _startSizeVar = 2.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }
        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}
//
// ParticleSun
//
ParticleSun* ParticleSun::create()
{
<<<<<<< HEAD
    ParticleSun* ret = new (std::nothrow) ParticleSun();
=======
    ParticleSun* ret = new ParticleSun();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleSun* ParticleSun::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleSun* ret = new (std::nothrow) ParticleSun();
=======
    ParticleSun* ret = new ParticleSun();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleSun::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // additive
        this->setBlendAdditive(true);

        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity mode: speed of particles
        setSpeed(20);
        setSpeedVar(5);


        // angle
        _angle = 90;
        _angleVar = 360;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 1;
        _lifeVar = 0.5f;

        // size, in pixels
        _startSize = 30.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per seconds
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.76f;
        _startColor.g = 0.25f;
        _startColor.b = 0.12f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        return true;
    }
    return false;
}

//
// ParticleGalaxy
//

ParticleGalaxy* ParticleGalaxy::create()
{
<<<<<<< HEAD
    ParticleGalaxy* ret = new (std::nothrow) ParticleGalaxy();
=======
    ParticleGalaxy* ret = new ParticleGalaxy();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleGalaxy* ParticleGalaxy::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleGalaxy* ret = new (std::nothrow) ParticleGalaxy();
=======
    ParticleGalaxy* ret = new ParticleGalaxy();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleGalaxy::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity Mode: speed of particles
        setSpeed(60);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-80);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(80);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 37.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.12f;
        _startColor.g = 0.25f;
        _startColor.b = 0.76f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(true);
        return true;
    }
    return false;
}

//
// ParticleFlower
//

ParticleFlower* ParticleFlower::create()
{
<<<<<<< HEAD
    ParticleFlower* ret = new (std::nothrow) ParticleFlower();
=======
    ParticleFlower* ret = new ParticleFlower();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleFlower* ParticleFlower::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleFlower* ret = new (std::nothrow) ParticleFlower();
=======
    ParticleFlower* ret = new ParticleFlower();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleFlower::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity Mode: speed of particles
        setSpeed(80);
        setSpeedVar(10);

        // Gravity Mode: radial
        setRadialAccel(-60);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(15);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 30.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.50f;
        _startColor.g = 0.50f;
        _startColor.b = 0.50f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.5f;
        _startColorVar.g = 0.5f;
        _startColorVar.b = 0.5f;
        _startColorVar.a = 0.5f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(true);
        return true;
    }
    return false;
}
//
// ParticleMeteor
//

ParticleMeteor * ParticleMeteor::create()
{
<<<<<<< HEAD
    ParticleMeteor *ret = new (std::nothrow) ParticleMeteor();
=======
    ParticleMeteor *ret = new ParticleMeteor();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleMeteor* ParticleMeteor::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleMeteor* ret = new (std::nothrow) ParticleMeteor();
=======
    ParticleMeteor* ret = new ParticleMeteor();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleMeteor::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(-200,200));

        // Gravity Mode: speed of particles
        setSpeed(15);
        setSpeedVar(5);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 2;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 60.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.2f;
        _startColor.g = 0.4f;
        _startColor.b = 0.7f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.2f;
        _startColorVar.a = 0.1f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(true);
        return true;
    }
    return false;
}

//
// ParticleSpiral
//

ParticleSpiral* ParticleSpiral::create()
{
<<<<<<< HEAD
    ParticleSpiral* ret = new (std::nothrow) ParticleSpiral();
=======
    ParticleSpiral* ret = new ParticleSpiral();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleSpiral* ParticleSpiral::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleSpiral* ret = new (std::nothrow) ParticleSpiral();
=======
    ParticleSpiral* ret = new ParticleSpiral();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleSpiral::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        _duration = DURATION_INFINITY;

        // Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity Mode: speed of particles
        setSpeed(150);
        setSpeedVar(0);

        // Gravity Mode: radial
        setRadialAccel(-380);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(45);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 0;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 12;
        _lifeVar = 0;

        // size, in pixels
        _startSize = 20.0f;
        _startSizeVar = 0.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.5f;
        _startColor.g = 0.5f;
        _startColor.b = 0.5f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.5f;
        _startColorVar.g = 0.5f;
        _startColorVar.b = 0.5f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.5f;
        _endColor.g = 0.5f;
        _endColor.b = 0.5f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.5f;
        _endColorVar.g = 0.5f;
        _endColorVar.b = 0.5f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}

//
// ParticleExplosion
//

ParticleExplosion* ParticleExplosion::create()
{
<<<<<<< HEAD
    ParticleExplosion* ret = new (std::nothrow) ParticleExplosion();
=======
    ParticleExplosion* ret = new ParticleExplosion();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleExplosion* ParticleExplosion::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleExplosion* ret = new (std::nothrow) ParticleExplosion();
=======
    ParticleExplosion* ret = new ParticleExplosion();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleExplosion::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        _duration = 0.1f;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity Mode: speed of particles
        setSpeed(70);
        setSpeedVar(40);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(0);

        // angle
        _angle = 90;
        _angleVar = 360;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height/2);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height/2));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2::ZERO);

        // life of particles
        _life = 5.0f;
        _lifeVar = 2;

        // size, in pixels
        _startSize = 15.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = _totalParticles/_duration;

        // color of particles
        _startColor.r = 0.7f;
        _startColor.g = 0.1f;
        _startColor.b = 0.2f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.5f;
        _startColorVar.g = 0.5f;
        _startColorVar.b = 0.5f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.5f;
        _endColor.g = 0.5f;
        _endColor.b = 0.5f;
        _endColor.a = 0.0f;
        _endColorVar.r = 0.5f;
        _endColorVar.g = 0.5f;
        _endColorVar.b = 0.5f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}

//
// ParticleSmoke
//

ParticleSmoke* ParticleSmoke::create()
{
<<<<<<< HEAD
    ParticleSmoke* ret = new (std::nothrow) ParticleSmoke();
=======
    ParticleSmoke* ret = new ParticleSmoke();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleSmoke* ParticleSmoke::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleSmoke* ret = new (std::nothrow) ParticleSmoke();
=======
    ParticleSmoke* ret = new ParticleSmoke();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleSmoke::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        // Emitter mode: Gravity Mode
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,0));

        // Gravity Mode: radial acceleration
        setRadialAccel(0);
        setRadialAccelVar(0);

        // Gravity Mode: speed of particles
        setSpeed(25);
        setSpeedVar(10);

        // angle
        _angle = 90;
        _angleVar = 5;

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, 0);
=======
        this->setPosition(Vec2(winSize.width/2, 0));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2(20, 0));

        // life of particles
        _life = 4;
        _lifeVar = 1;

        // size, in pixels
        _startSize = 60.0f;
        _startSizeVar = 10.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per frame
        _emissionRate = _totalParticles/_life;

        // color of particles
        _startColor.r = 0.8f;
        _startColor.g = 0.8f;
        _startColor.b = 0.8f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.02f;
        _startColorVar.g = 0.02f;
        _startColorVar.b = 0.02f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.0f;
        _endColor.g = 0.0f;
        _endColor.b = 0.0f;
        _endColor.a = 1.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}

//
// ParticleSnow
//

ParticleSnow* ParticleSnow::create()
{
<<<<<<< HEAD
    ParticleSnow* ret = new (std::nothrow) ParticleSnow();
=======
    ParticleSnow* ret = new ParticleSnow();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleSnow* ParticleSnow::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleSnow* ret = new (std::nothrow) ParticleSnow();
=======
    ParticleSnow* ret = new ParticleSnow();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleSnow::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) ) 
    {
        // duration
        _duration = DURATION_INFINITY;

        // set gravity mode.
        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(0,-1));

        // Gravity Mode: speed of particles
        setSpeed(5);
        setSpeedVar(1);

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height + 10);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height + 10));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2(winSize.width/2, 0));

        // angle
        _angle = -90;
        _angleVar = 5;

        // life of particles
        _life = 45;
        _lifeVar = 15;

        // size, in pixels
        _startSize = 10.0f;
        _startSizeVar = 5.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = 10;

        // color of particles
        _startColor.r = 1.0f;
        _startColor.g = 1.0f;
        _startColor.b = 1.0f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 1.0f;
        _endColor.g = 1.0f;
        _endColor.b = 1.0f;
        _endColor.a = 0.0f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}
//
// ParticleRain
//

ParticleRain* ParticleRain::create()
{
<<<<<<< HEAD
    ParticleRain* ret = new (std::nothrow) ParticleRain();
=======
    ParticleRain* ret = new ParticleRain();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

ParticleRain* ParticleRain::createWithTotalParticles(int numberOfParticles)
{
<<<<<<< HEAD
    ParticleRain* ret = new (std::nothrow) ParticleRain();
=======
    ParticleRain* ret = new ParticleRain();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    if (ret && ret->initWithTotalParticles(numberOfParticles))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

bool ParticleRain::initWithTotalParticles(int numberOfParticles)
{
    if( ParticleSystemQuad::initWithTotalParticles(numberOfParticles) )
    {
        // duration
        _duration = DURATION_INFINITY;

        setEmitterMode(Mode::GRAVITY);

        // Gravity Mode: gravity
        setGravity(Vec2(10,-10));

        // Gravity Mode: radial
        setRadialAccel(0);
        setRadialAccelVar(1);

        // Gravity Mode: tangential
        setTangentialAccel(0);
        setTangentialAccelVar(1);

        // Gravity Mode: speed of particles
        setSpeed(130);
        setSpeedVar(30);

        // angle
        _angle = -90;
        _angleVar = 5;


        // emitter position
        Size winSize = Director::getInstance()->getWinSize();
<<<<<<< HEAD
        this->setPosition(winSize.width/2, winSize.height);
=======
        this->setPosition(Vec2(winSize.width/2, winSize.height));
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        setPosVar(Vec2(winSize.width/2, 0));

        // life of particles
        _life = 4.5f;
        _lifeVar = 0;

        // size, in pixels
        _startSize = 4.0f;
        _startSizeVar = 2.0f;
        _endSize = START_SIZE_EQUAL_TO_END_SIZE;

        // emits per second
        _emissionRate = 20;

        // color of particles
        _startColor.r = 0.7f;
        _startColor.g = 0.8f;
        _startColor.b = 1.0f;
        _startColor.a = 1.0f;
        _startColorVar.r = 0.0f;
        _startColorVar.g = 0.0f;
        _startColorVar.b = 0.0f;
        _startColorVar.a = 0.0f;
        _endColor.r = 0.7f;
        _endColor.g = 0.8f;
        _endColor.b = 1.0f;
        _endColor.a = 0.5f;
        _endColorVar.r = 0.0f;
        _endColorVar.g = 0.0f;
        _endColorVar.b = 0.0f;
        _endColorVar.a = 0.0f;

        Texture2D* texture = getDefaultTexture();
        if (texture != nullptr)
        {
            setTexture(texture);
        }

        // additive
        this->setBlendAdditive(false);
        return true;
    }
    return false;
}

NS_CC_END
