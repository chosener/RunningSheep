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

#ifndef __SPRITE_NODE_CCSPRITE_H__
#define __SPRITE_NODE_CCSPRITE_H__

<<<<<<< HEAD
#include <string>
#include "2d/CCNode.h"
#include "2d/CCDrawNode.h"
#include "base/CCProtocols.h"
#include "renderer/CCTextureAtlas.h"
=======
#include "2d/CCNode.h"
#include "base/CCProtocols.h"
#include "renderer/CCTextureAtlas.h"
#include "base/ccTypes.h"
#include <string>
#ifdef EMSCRIPTEN
#include "CCGLBufferedNode.h"
#endif // EMSCRIPTEN
#include "physics/CCPhysicsBody.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "renderer/CCQuadCommand.h"
#include "renderer/CCCustomCommand.h"

NS_CC_BEGIN

class SpriteBatchNode;
class SpriteFrame;
class Animation;
class Rect;
class Size;
class Texture2D;
struct transformValues_;

/**
<<<<<<< HEAD
 * @addtogroup _2d
=======
 * @addtogroup sprite_nodes
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 * @{
 */

/**
<<<<<<< HEAD
 * Sprite is a 2d image ( http://en.wikipedia.org/wiki/Sprite_(computer_graphics) ).
=======
 * Sprite is a 2d image ( http://en.wikipedia.org/wiki/Sprite_(computer_graphics) )
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 *
 * Sprite can be created with an image, or with a sub-rectangle of an image.
 *
 * To optimize the Sprite rendering, please follow the following best practices:
<<<<<<< HEAD
 *  - Put all your sprites in the same spritesheet (http://www.codeandweb.com/what-is-a-sprite-sheet).
 *  - Use the same blending function for all your sprites.
=======
 *
 *  - Put all your sprites in the same spritesheet (http://www.codeandweb.com/what-is-a-sprite-sheet)
 *  - Use the same blending function for all your sprites
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 *  - ...and the Renderer will automatically "batch" your sprites (will draw all of them in one OpenGL call).
 *
 *  To gain an additional 5% ~ 10% more in the rendering, you can parent your sprites into a `SpriteBatchNode`.
 *  But doing so carries the following limitations:
 *
 *  - The Alias/Antialias property belongs to `SpriteBatchNode`, so you can't individually set the aliased property.
 *  - The Blending function property belongs to `SpriteBatchNode`, so you can't individually set the blending function property.
 *  - `ParallaxNode` is not supported, but can be simulated with a "proxy" sprite.
 *  - Sprites can only have other Sprites (or subclasses of Sprite) as children.
 *
 * The default anchorPoint in Sprite is (0.5, 0.5).
 */
class CC_DLL Sprite : public Node, public TextureProtocol
{
public:
<<<<<<< HEAD
     /** Sprite invalid index on the SpriteBatchNode. */
    static const int INDEX_NOT_INITIALIZED = -1;

    /// @name Creators
    /// @{
=======

    static const int INDEX_NOT_INITIALIZED = -1; /// Sprite invalid index on the SpriteBatchNode

    /// @{
    /// @name Creators
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Creates an empty sprite without texture. You can call setTexture method subsequently.
     *
<<<<<<< HEAD
     * @memberof Sprite
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return An autoreleased sprite object.
     */
    static Sprite* create();

    /**
     * Creates a sprite with an image filename.
     *
     * After creation, the rect of sprite will be the size of the image,
     * and the offset will be (0,0).
     *
<<<<<<< HEAD
     * @param   filename A path to image file, e.g., "scene1/monster.png".
=======
     * @param   filename A path to image file, e.g., "scene1/monster.png"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return  An autoreleased sprite object.
     */
    static Sprite* create(const std::string& filename);

    /**
     * Creates a sprite with an image filename and a rect.
     *
<<<<<<< HEAD
     * @param   filename A path to image file, e.g., "scene1/monster.png".
     * @param   rect     A subrect of the image file.
     * @return  An autoreleased sprite object.
=======
     * @param   filename A path to image file, e.g., "scene1/monster.png"
     * @param   rect     A subrect of the image file
     * @return  An autoreleased sprite object
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static Sprite* create(const std::string& filename, const Rect& rect);

    /**
     * Creates a sprite with a Texture2D object.
     *
     * After creation, the rect will be the size of the texture, and the offset will be (0,0).
     *
     * @param   texture    A pointer to a Texture2D object.
<<<<<<< HEAD
     * @return  An autoreleased sprite object.
=======
     * @return  An autoreleased sprite object
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static Sprite* createWithTexture(Texture2D *texture);

    /**
     * Creates a sprite with a texture and a rect.
     *
     * After creation, the offset will be (0,0).
     *
<<<<<<< HEAD
     * @param   texture     A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
     * @param   rotated     Whether or not the rect is rotated.
     * @return  An autoreleased sprite object.
=======
     * @param   texture    A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside the rect of this texture will be applied for this sprite.
     * @param   rotated     Whether or not the rect is rotated
     * @return  An autoreleased sprite object
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static Sprite* createWithTexture(Texture2D *texture, const Rect& rect, bool rotated=false);

    /**
     * Creates a sprite with an sprite frame.
     *
<<<<<<< HEAD
     * @param   spriteFrame    A sprite frame which involves a texture and a rect.
     * @return  An autoreleased sprite object.
=======
     * @param   spriteFrame    A sprite frame which involves a texture and a rect
     * @return  An autoreleased sprite object
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static Sprite* createWithSpriteFrame(SpriteFrame *spriteFrame);

    /**
     * Creates a sprite with an sprite frame name.
     *
     * A SpriteFrame will be fetched from the SpriteFrameCache by spriteFrameName param.
     * If the SpriteFrame doesn't exist it will raise an exception.
     *
     * @param   spriteFrameName A null terminated string which indicates the sprite frame name.
<<<<<<< HEAD
     * @return  An autoreleased sprite object.
     */
    static Sprite* createWithSpriteFrameName(const std::string& spriteFrameName);

    //  end of creators group
    /// @}
=======
     * @return  An autoreleased sprite object
     */
    static Sprite* createWithSpriteFrameName(const std::string& spriteFrameName);

    /// @}  end of creators group
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


    /// @{
    /// @name BatchNode methods

    /**
     * Updates the quad according the rotation, position, scale values.
     */
<<<<<<< HEAD
    virtual void updateTransform() override;

    /**
     * Returns the batch node object if this sprite is rendered by SpriteBatchNode.
=======
    virtual void updateTransform(void);

    /**
     * Returns the batch node object if this sprite is rendered by SpriteBatchNode
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @return The SpriteBatchNode object if this sprite is rendered by SpriteBatchNode,
     *         nullptr if the sprite isn't used batch node.
     */
<<<<<<< HEAD
    virtual SpriteBatchNode* getBatchNode() const;
    /**
     * Sets the batch node to sprite.
=======
    virtual SpriteBatchNode* getBatchNode(void);
    /**
     * Sets the batch node to sprite
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @warning This method is not recommended for game developers. Sample code for using batch node
     * @code
     * SpriteBatchNode *batch = SpriteBatchNode::create("Images/grossini_dance_atlas.png", 15);
     * Sprite *sprite = Sprite::createWithTexture(batch->getTexture(), Rect(0, 0, 57, 57));
     * batch->addChild(sprite);
     * layer->addChild(batch);
     * @endcode
     */
    virtual void setBatchNode(SpriteBatchNode *spriteBatchNode);

    /// @} end of BatchNode methods


<<<<<<< HEAD
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /// @{
    /// @name Texture / Frame methods

    /** Sets a new texture (from a filename) to the sprite.
<<<<<<< HEAD
     *
     *  @memberof Sprite
     *  It will call `setTextureRect()` with the texture's content size.
     */
    virtual void setTexture(const std::string &filename );

    /** @overload
     *
     *  The Texture's rect is not changed.
     */
    virtual void setTexture(Texture2D *texture) override;

    /** Returns the Texture2D object used by the sprite. */
=======
     It will call `setTextureRect()` with the texture's content size.
     TODO: The whole Sprite API needs to be reviewed.
     */
    virtual void setTexture(const std::string &filename );

    /** Sets a new texture to the sprite.
     The Texture's rect is not changed.
     */
    virtual void setTexture(Texture2D *texture) override;

    /** returns the Texture2D object used by the sprite */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual Texture2D* getTexture() const override;

    /**
     * Updates the texture rect of the Sprite in points.
<<<<<<< HEAD
     *
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * It will call setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize) with \p rotated = false, and \p utrimmedSize = rect.size.
     */
    virtual void setTextureRect(const Rect& rect);

<<<<<<< HEAD
    /** @overload
     *
=======
    /**
     * Sets the texture rect, rectRotated and untrimmed size of the Sprite in points.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * It will update the texture coordinates and the vertex rectangle.
     */
    virtual void setTextureRect(const Rect& rect, bool rotated, const Size& untrimmedSize);

    /**
     * Sets the vertex rect.
<<<<<<< HEAD
     *
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * It will be called internally by setTextureRect.
     * Useful if you want to create 2x images from SD images in Retina Display.
     * Do not call it manually. Use setTextureRect instead.
     */
    virtual void setVertexRect(const Rect& rect);

<<<<<<< HEAD
    /** @{
=======
    /**
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * Sets a new SpriteFrame to the Sprite.
     */
    virtual void setSpriteFrame(const std::string &spriteFrameName);
    virtual void setSpriteFrame(SpriteFrame* newFrame);
<<<<<<< HEAD
    /** @} */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /** @deprecated Use `setSpriteFrame()` instead. */
    CC_DEPRECATED_ATTRIBUTE virtual void setDisplayFrame(SpriteFrame *newFrame) { setSpriteFrame(newFrame); }

    /**
<<<<<<< HEAD
     * Returns whether or not a SpriteFrame is being displayed.
     */
    virtual bool isFrameDisplayed(SpriteFrame *frame) const;
=======
     * Returns whether or not a SpriteFrame is being displayed
     */
    virtual bool isFrameDisplayed(SpriteFrame *pFrame) const;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Returns the current displayed frame.
     */
    virtual SpriteFrame* getSpriteFrame() const;
<<<<<<< HEAD
    /** @deprecated Use `getSpriteFrame()` instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE virtual SpriteFrame* getDisplayFrame() const { return getSpriteFrame(); }
    /** @deprecated Use `getSpriteFrame()` instead. */
=======
    /** @deprecated Use `getSpriteFrame()` instead */
    CC_DEPRECATED_ATTRIBUTE virtual SpriteFrame* getDisplayFrame() const { return getSpriteFrame(); }
    /** @deprecated Use `getSpriteFrame()` instead */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE virtual SpriteFrame* displayFrame() const { return getSpriteFrame(); };

    /// @} End of frames methods


    /// @{
    /// @name Animation methods
    /**
     * Changes the display frame with animation name and index.
<<<<<<< HEAD
     * The animation name will be get from the AnimationCache.
=======
     * The animation name will be get from the AnimationCache
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual void setDisplayFrameWithAnimationName(const std::string& animationName, ssize_t frameIndex);
    /// @}


    /// @{
<<<<<<< HEAD
    /// @name Sprite Properties' setter/getters.
=======
    /// @name Sprite Properties' setter/getters
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Whether or not the Sprite needs to be updated in the Atlas.
     *
<<<<<<< HEAD
     * @return True if the sprite needs to be updated in the Atlas, false otherwise.
     */
    virtual bool isDirty() const { return _dirty; }
=======
     * @return true if the sprite needs to be updated in the Atlas, false otherwise.
     */
    virtual bool isDirty(void) const { return _dirty; }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Makes the Sprite to be updated in the Atlas.
     */
    virtual void setDirty(bool dirty) { _dirty = dirty; }

    /**
     * Returns the quad (tex coords, vertex coords and color) information.
     * @js  NA
     * @lua NA
     */
<<<<<<< HEAD
    inline V3F_C4B_T2F_Quad getQuad() const { return _quad; }
=======
    inline V3F_C4B_T2F_Quad getQuad(void) const { return _quad; }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Returns whether or not the texture rectangle is rotated.
     */
<<<<<<< HEAD
    inline bool isTextureRectRotated() const { return _rectRotated; }
=======
    inline bool isTextureRectRotated(void) const { return _rectRotated; }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Returns the index used on the TextureAtlas.
     */
<<<<<<< HEAD
    inline ssize_t getAtlasIndex() const { return _atlasIndex; }

    /**
     * Sets the index used on the TextureAtlas.
     *
     * @warning Don't modify this value unless you know what you are doing.
=======
    inline ssize_t getAtlasIndex(void) const { return _atlasIndex; }

    /**
     * Sets the index used on the TextureAtlas.
     * @warning Don't modify this value unless you know what you are doing
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setAtlasIndex(ssize_t atlasIndex) { _atlasIndex = atlasIndex; }

    /**
<<<<<<< HEAD
     * Returns the rect of the Sprite in points.
     */
    inline const Rect& getTextureRect() const { return _rect; }

    /**
     * Gets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
     */
    inline TextureAtlas* getTextureAtlas() const { return _textureAtlas; }

    /**
     * Sets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode.
     */
    inline void setTextureAtlas(TextureAtlas *textureAtlas) { _textureAtlas = textureAtlas; }
=======
     * Returns the rect of the Sprite in points
     */
    inline const Rect& getTextureRect(void) { return _rect; }

    /**
     * Gets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode
     */
    inline TextureAtlas* getTextureAtlas(void) { return _textureAtlas; }

    /**
     * Sets the weak reference of the TextureAtlas when the sprite is rendered using via SpriteBatchNode
     */
    inline void setTextureAtlas(TextureAtlas *pobTextureAtlas) { _textureAtlas = pobTextureAtlas; }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Gets the offset position of the sprite. Calculated automatically by editors like Zwoptex.
     */
<<<<<<< HEAD
    inline const Vec2& getOffsetPosition() const { return _offsetPosition; }
=======
    inline const Vec2& getOffsetPosition(void) const { return _offsetPosition; }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


    /**
     * Returns the flag which indicates whether the sprite is flipped horizontally or not.
     *
     * It only flips the texture of the sprite, and not the texture of the sprite's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * sprite->setScaleX(sprite->getScaleX() * -1);
     *
     * @return true if the sprite is flipped horizontally, false otherwise.
     */
<<<<<<< HEAD
    bool isFlippedX() const;
=======
    bool isFlippedX(void) const;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /**
     * Sets whether the sprite should be flipped horizontally or not.
     *
     * @param flippedX true if the sprite should be flipped horizontally, false otherwise.
     */
    void setFlippedX(bool flippedX);

<<<<<<< HEAD
    /** @deprecated Use isFlippedX() instead.
=======
    /** @deprecated Use isFlippedX() instead
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    * @js NA
    * @lua NA
    */
    CC_DEPRECATED_ATTRIBUTE bool isFlipX() { return isFlippedX(); };
<<<<<<< HEAD
    /** @deprecated Use setFlippedX() instead
     * @js NA
     */
=======
    /** @deprecated Use setFlippedX() instead */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE void setFlipX(bool flippedX) { setFlippedX(flippedX); };

    /**
     * Return the flag which indicates whether the sprite is flipped vertically or not.
     *
     * It only flips the texture of the sprite, and not the texture of the sprite's children.
     * Also, flipping the texture doesn't alter the anchorPoint.
     * If you want to flip the anchorPoint too, and/or to flip the children too use:
     * sprite->setScaleY(sprite->getScaleY() * -1);
     *
     * @return true if the sprite is flipped vertically, false otherwise.
     */
<<<<<<< HEAD
    bool isFlippedY() const;
=======
    bool isFlippedY(void) const;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /**
     * Sets whether the sprite should be flipped vertically or not.
     *
     * @param flippedY true if the sprite should be flipped vertically, false otherwise.
     */
    void setFlippedY(bool flippedY);

    /// @} End of Sprite properties getter/setters

<<<<<<< HEAD
    /** @deprecated Use isFlippedY() instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE bool isFlipY() { return isFlippedY(); };
    /** @deprecated Use setFlippedY() instead.
     * @js NA
     */
=======
    /** @deprecated Use isFlippedY() instead */
    CC_DEPRECATED_ATTRIBUTE bool isFlipY() { return isFlippedY(); };
    /** @deprecated Use setFlippedY() instead */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE void setFlipY(bool flippedY) { setFlippedY(flippedY); };

    //
    // Overrides
    //
    /// @{
<<<<<<< HEAD
    /// @name Functions inherited from TextureProtocol.
    /**
    *@code
    *When this function bound into js or lua,the parameter will be changed.
    *In js: var setBlendFunc(var src, var dst).
    *In lua: local setBlendFunc(local src, local dst).
=======
    /// @name Functions inherited from TextureProtocol
    /**
    *@code
    *When this function bound into js or lua,the parameter will be changed
    *In js: var setBlendFunc(var src, var dst)
    *In lua: local setBlendFunc(local src, local dst)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    *@endcode
    */
    inline void setBlendFunc(const BlendFunc &blendFunc) override { _blendFunc = blendFunc; }
    /**
    * @js  NA
    * @lua NA
    */
    inline const BlendFunc& getBlendFunc() const override { return _blendFunc; }
    /// @}

<<<<<<< HEAD
    /**
     * @js NA
     */
    virtual std::string getDescription() const override;

    /// @{
    /// @name Functions inherited from Node.
=======
    virtual std::string getDescription() const override;

    /// @{
    /// @name Functions inherited from Node
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void setScaleX(float scaleX) override;
    virtual void setScaleY(float scaleY) override;
    virtual void setScale(float scaleX, float scaleY) override;
    /**
    * @js  NA
    * @lua NA
    */
    virtual void setPosition(const Vec2& pos) override;
    virtual void setPosition(float x, float y) override;
    virtual void setRotation(float rotation) override;
    virtual void setRotationSkewX(float rotationX) override;
    virtual void setRotationSkewY(float rotationY) override;
    virtual void setSkewX(float sx) override;
    virtual void setSkewY(float sy) override;
    virtual void removeChild(Node* child, bool cleanup) override;
    virtual void removeAllChildrenWithCleanup(bool cleanup) override;
    virtual void reorderChild(Node *child, int zOrder) override;
    using Node::addChild;
    virtual void addChild(Node *child, int zOrder, int tag) override;
    virtual void addChild(Node *child, int zOrder, const std::string &name) override;
    virtual void sortAllChildren() override;
    virtual void setScale(float scale) override;
    virtual void setPositionZ(float positionZ) override;
    virtual void setAnchorPoint(const Vec2& anchor) override;
    virtual void ignoreAnchorPointForPosition(bool value) override;
    virtual void setVisible(bool bVisible) override;
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    virtual void setOpacityModifyRGB(bool modify) override;
<<<<<<< HEAD
    virtual bool isOpacityModifyRGB() const override;
    /// @}

CC_CONSTRUCTOR_ACCESS:
	/**
     * @js ctor
     */
    Sprite();
    virtual ~Sprite();

    /* Initializes an empty sprite with nothing init. */
    virtual bool init() override;
=======
    virtual bool isOpacityModifyRGB(void) const override;
    /// @}

CC_CONSTRUCTOR_ACCESS:

    Sprite(void);
    virtual ~Sprite(void);

    /* Initializes an empty sprite with nothing init. */
    virtual bool init(void);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Initializes a sprite with a texture.
     *
     * After initialization, the rect used will be the size of the texture, and the offset will be (0,0).
     *
     * @param   texture    A pointer to an existing Texture2D object.
     *                      You can use a Texture2D object for many sprites.
<<<<<<< HEAD
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @return  true if the sprite is initialized properly, false otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual bool initWithTexture(Texture2D *texture);

    /**
     * Initializes a sprite with a texture and a rect.
     *
     * After initialization, the offset will be (0,0).
     *
     * @param   texture    A pointer to an exisiting Texture2D object.
     *                      You can use a Texture2D object for many sprites.
     * @param   rect        Only the contents inside rect of this texture will be applied for this sprite.
<<<<<<< HEAD
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @return  true if the sprite is initialized properly, false otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual bool initWithTexture(Texture2D *texture, const Rect& rect);

    /**
     * Initializes a sprite with a texture and a rect in points, optionally rotated.
     *
     * After initialization, the offset will be (0,0).
     * @note    This is the designated initializer.
     *
     * @param   texture    A Texture2D object whose texture will be applied to this sprite.
     * @param   rect        A rectangle assigned the contents of texture.
     * @param   rotated     Whether or not the texture rectangle is rotated.
<<<<<<< HEAD
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @return  true if the sprite is initialized properly, false otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual bool initWithTexture(Texture2D *texture, const Rect& rect, bool rotated);

    /**
<<<<<<< HEAD
     * Initializes a sprite with an SpriteFrame. The texture and rect in SpriteFrame will be applied on this sprite.
     *
     * @param   spriteFrame  A SpriteFrame object. It should includes a valid texture and a rect.
     * @return  True if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithSpriteFrame(SpriteFrame *spriteFrame);
=======
     * Initializes a sprite with an SpriteFrame. The texture and rect in SpriteFrame will be applied on this sprite
     *
     * @param   pSpriteFrame  A SpriteFrame object. It should includes a valid texture and a rect
     * @return  true if the sprite is initialized properly, false otherwise.
     */
    virtual bool initWithSpriteFrame(SpriteFrame *pSpriteFrame);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * Initializes a sprite with an sprite frame name.
     *
     * A SpriteFrame will be fetched from the SpriteFrameCache by name.
     * If the SpriteFrame doesn't exist it will raise an exception.
     *
<<<<<<< HEAD
     * @param   spriteFrameName  A key string that can fected a volid SpriteFrame from SpriteFrameCache.
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @param   spriteFrameName  A key string that can fected a volid SpriteFrame from SpriteFrameCache
     * @return  true if the sprite is initialized properly, false otherwise.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual bool initWithSpriteFrameName(const std::string& spriteFrameName);

    /**
     * Initializes a sprite with an image filename.
     *
     * This method will find filename from local file system, load its content to Texture2D,
     * then use Texture2D to create a sprite.
     * After initialization, the rect used will be the size of the image. The offset will be (0,0).
     *
<<<<<<< HEAD
     * @param   filename The path to an image file in local file system.
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @param   filename The path to an image file in local file system
     * @return  true if the sprite is initialized properly, false otherwise.
     * @js      init
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua     init
     */
    virtual bool initWithFile(const std::string& filename);

    /**
     * Initializes a sprite with an image filename, and a rect.
     *
     * This method will find filename from local file system, load its content to Texture2D,
     * then use Texture2D to create a sprite.
     * After initialization, the offset will be (0,0).
     *
     * @param   filename The path to an image file in local file system.
     * @param   rect        The rectangle assigned the content area from texture.
<<<<<<< HEAD
     * @return  True if the sprite is initialized properly, false otherwise.
=======
     * @return  true if the sprite is initialized properly, false otherwise.
     * @js      init
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @lua     init
     */
    virtual bool initWithFile(const std::string& filename, const Rect& rect);

protected:

<<<<<<< HEAD
    void updateColor() override;
    virtual void setTextureCoords(Rect rect);
    virtual void updateBlendFunc();
    virtual void setReorderChildDirtyRecursively();
    virtual void setDirtyRecursively(bool value);
=======
    void updateColor(void);
    virtual void setTextureCoords(Rect rect);
    virtual void updateBlendFunc(void);
    virtual void setReorderChildDirtyRecursively(void);
    virtual void setDirtyRecursively(bool bValue);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    //
    // Data used when the sprite is rendered using a SpriteSheet
    //
    TextureAtlas*       _textureAtlas;      /// SpriteBatchNode texture atlas (weak reference)
    ssize_t             _atlasIndex;        /// Absolute (real) Index on the SpriteSheet
    SpriteBatchNode*    _batchNode;         /// Used batch node (weak reference)

    bool                _dirty;             /// Whether the sprite needs to be updated
    bool                _recursiveDirty;    /// Whether all of the sprite's children needs to be updated
    bool                _shouldBeHidden;    /// should not be drawn because one of the ancestors is not visible
    Mat4              _transformToBatch;

    //
    // Data used when the sprite is self-rendered
    //
    BlendFunc        _blendFunc;            /// It's required for TextureProtocol inheritance
    Texture2D*       _texture;              /// Texture2D object that is used to render the sprite
<<<<<<< HEAD
    SpriteFrame*     _spriteFrame;
    QuadCommand      _quadCommand;          /// quad command
#if CC_SPRITE_DEBUG_DRAW
    DrawNode *_debugDrawNode;
=======
    QuadCommand      _quadCommand;          /// quad command
#if CC_SPRITE_DEBUG_DRAW
    CustomCommand   _customDebugDrawCommand;
    void drawDebugData();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif //CC_SPRITE_DEBUG_DRAW
    //
    // Shared data
    //

    // texture
    Rect _rect;                             /// Retangle of Texture2D
    bool   _rectRotated;                    /// Whether the texture is rotated

    // Offset Position (used by Zwoptex)
    Vec2 _offsetPosition;
    Vec2 _unflippedOffsetPositionFromCenter;

    // vertex coords, texture coords and color info
    V3F_C4B_T2F_Quad _quad;

    // opacity and RGB protocol
    bool _opacityModifyRGB;

    // image is flipped
    bool _flippedX;                         /// Whether the sprite is flipped horizontally or not
    bool _flippedY;                         /// Whether the sprite is flipped vertically or not

    bool _insideBounds;                     /// whether or not the sprite was inside bounds the previous frame
private:
    CC_DISALLOW_COPY_AND_ASSIGN(Sprite);
};


// end of sprite_nodes group
/// @}

NS_CC_END

#endif // __SPRITE_NODE_CCSPRITE_H__
