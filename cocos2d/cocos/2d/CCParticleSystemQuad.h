/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2009      Leonardo Kasperavičius
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
#ifndef __CC_PARTICLE_SYSTEM_QUAD_H__
#define __CC_PARTICLE_SYSTEM_QUAD_H__

<<<<<<< HEAD
#include "2d/CCParticleSystem.h"
=======
#include  "CCParticleSystem.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "renderer/CCQuadCommand.h"

NS_CC_BEGIN

class SpriteFrame;
class EventCustom;

/**
<<<<<<< HEAD
 * @addtogroup _2d
 * @{
 */

/** @class ParticleSystemQuad
 * @brief ParticleSystemQuad is a subclass of ParticleSystem.
=======
 * @addtogroup particle_nodes
 * @{
 */

/** @brief ParticleSystemQuad is a subclass of ParticleSystem
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

It includes all the features of ParticleSystem.

Special features and Limitations:    
- Particle size can be any float number.
<<<<<<< HEAD
- The system can be scaled.
- The particles can be rotated.
- It supports subrects.
- It supports batched rendering since 1.1.
@since v0.8
@js NA
=======
- The system can be scaled
- The particles can be rotated
- It supports subrects
- It supports batched rendering since 1.1
@since v0.8
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
*/
class CC_DLL ParticleSystemQuad : public ParticleSystem
{
public:

<<<<<<< HEAD
    /** Creates a Particle Emitter.
     *
     * @return An autoreleased ParticleSystemQuad object.
     */
    static ParticleSystemQuad * create();
    /** Creates a Particle Emitter with a number of particles.
     *
     * @param numberOfParticles A given number of particles.
     * @return An autoreleased ParticleSystemQuad object.
     */
    static ParticleSystemQuad * createWithTotalParticles(int numberOfParticles);
    /** Creates an initializes a ParticleSystemQuad from a plist file.
     This plist files can be created manually or with Particle Designer.
     *
     * @param filename Particle plist file name.
     * @return An autoreleased ParticleSystemQuad object.
     */
    static ParticleSystemQuad * create(const std::string& filename);
    /** Creates a Particle Emitter with a dictionary.
     * 
     * @param dictionary Particle dictionary.
     * @return An autoreleased ParticleSystemQuad object.
     */
=======
    /** creates a Particle Emitter */
    static ParticleSystemQuad * create();
    /** creates a Particle Emitter with a number of particles */
    static ParticleSystemQuad * createWithTotalParticles(int numberOfParticles);
    /** creates an initializes a ParticleSystemQuad from a plist file.
     This plist files can be created manually or with Particle Designer:
     */
    static ParticleSystemQuad * create(const std::string& filename);
    /** creates a Particle Emitter with a dictionary */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static ParticleSystemQuad * create(ValueMap &dictionary);

    /** Sets a new SpriteFrame as particle.
    WARNING: this method is experimental. Use setTextureWithRect instead.
<<<<<<< HEAD
     *
     * @param spriteFrame A given sprite frame as particle texture.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    @since v0.99.4
    */
    void setDisplayFrame(SpriteFrame *spriteFrame);

    /** Sets a new texture with a rect. The rect is in Points.
     @since v0.99.4
     * @js NA
     * @lua NA
<<<<<<< HEAD
     *
     * @param texture A given texture.
     8 @param rect A given rect, in points.
     */
    void setTextureWithRect(Texture2D *texture, const Rect& rect);

    /** Listen the event that renderer was recreated on Android/WP8.
     * @js NA
     * @lua NA
     *
     * @param event the event that renderer was recreated on Android/WP8.
=======
     */
    void setTextureWithRect(Texture2D *texture, const Rect& rect);

    /** listen the event that renderer was recreated on Android/WP8
     * @js NA
     * @lua NA
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void listenRendererRecreated(EventCustom* event);

    /**
     * @js NA
     * @lua NA
     */
    virtual void setTexture(Texture2D* texture) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void updateQuadWithParticle(tParticle* particle, const Vec2& newPosition) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void postStep() override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    /**
     * @js NA
     * @lua NA
     */
    virtual void setBatchNode(ParticleBatchNode* batchNode) override;
    /**
     * @js NA
     * @lua NA
     */
    virtual void setTotalParticles(int tp) override;

    virtual std::string getDescription() const override;
    
CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    ParticleSystemQuad();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~ParticleSystemQuad();
    
    // Overrides
    /**
     * @js NA
     * @lua NA
     */
    virtual bool initWithTotalParticles(int numberOfParticles) override;

protected:
    /** initializes the indices for the vertices*/
    void initIndices();
    
    /** initializes the texture with a rectangle measured Points */
    void initTexCoordsWithRect(const Rect& rect);
    
    /** Updates texture coords */
    void updateTexCoords();

    void setupVBOandVAO();
    void setupVBO();
    bool allocMemory();

    V3F_C4B_T2F_Quad    *_quads;        // quads to be rendered
    GLushort            *_indices;      // indices
    GLuint              _VAOname;
    GLuint              _buffersVBO[2]; //0: vertex  1: indices

    QuadCommand _quadCommand;           // quad command

private:
    CC_DISALLOW_COPY_AND_ASSIGN(ParticleSystemQuad);
};

<<<<<<< HEAD
// end of _2d group
=======
// end of particle_nodes group
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
/// @}

NS_CC_END

#endif //__CC_PARTICLE_SYSTEM_QUAD_H__

