/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.

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

#ifndef __CCMESH_H__
#define __CCMESH_H__

#include <string>
<<<<<<< HEAD

#include "3d/CCBundle3DData.h"
#include "3d/CCAABB.h"

#include "base/CCRef.h"
#include "math/CCMath.h"
#include "renderer/CCMeshCommand.h"

NS_CC_BEGIN

/**
 * @addtogroup _3d
 * @{
 */

class Texture2D;
class MeshSkin;
class MeshIndexData;
class GLProgramState;
class GLProgram;
/** 
 * @brief Mesh: contains ref to index buffer, GLProgramState, texture, skin, blend function, aabb and so on
 */
class CC_DLL Mesh : public Ref
{
    friend class Sprite3D;
public:
    typedef std::vector<unsigned short> IndexArray;
    /**create mesh from positions, normals, and so on, sigle SubMesh*/
    static Mesh* create(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const IndexArray& indices);
    /**create mesh with vertex attributes*/
    CC_DEPRECATED_ATTRIBUTE static Mesh* create(const std::vector<float>& vertices, int perVertexSizeInFloat, const IndexArray& indices, int numIndex, const std::vector<MeshVertexAttrib>& attribs, int attribCount){ return create(vertices, perVertexSizeInFloat, indices, attribs); }
    
    /**
     * @lua NA
     */
    static Mesh* create(const std::vector<float>& vertices, int perVertexSizeInFloat, const IndexArray& indices, const std::vector<MeshVertexAttrib>& attribs);
    
    /** 
     * create mesh
     * @lua NA
     */
    static Mesh* create(const std::string& name, MeshIndexData* indexData, MeshSkin* skin = nullptr);
    
    /**
     * get vertex buffer
     * 
     * @lua NA
     */
    GLuint getVertexBuffer() const;
    /**
     * has vertex attribute?
     *
     * @lua NA
     */
    bool hasVertexAttrib(int attrib) const;
    /**get mesh vertex attribute count*/
    ssize_t getMeshVertexAttribCount() const;
    /**get MeshVertexAttribute by index*/
    const MeshVertexAttrib& getMeshVertexAttribute(int idx);
    /**get per vertex size in bytes*/
    int getVertexSizeInBytes() const;

    /**texture getter and setter*/
    void setTexture(const std::string& texPath);
    void setTexture(Texture2D* tex);
    Texture2D* getTexture() const { return _texture; }
    
    /**visible getter and setter*/
    void setVisible(bool visible);
    bool isVisible() const { return _visible; }
    
    /**
     * skin getter
     *
     * @lua NA
     */
    MeshSkin* getSkin() const { return _skin; }
    
    /**
     * mesh index data getter
     *
     * @lua NA
     */
    MeshIndexData* getMeshIndexData() const { return _meshIndexData; }
    
    /**
     * get GLProgramState
     * 
     * @lua NA
     */
    GLProgramState* getGLProgramState() const { return _glProgramState; }
    
    /**name getter */
    const std::string& getName() const { return _name; }
    
    void setBlendFunc(const BlendFunc &blendFunc);
    const BlendFunc &getBlendFunc() const;
    
    /** 
     * get primitive type
     *
     * @lua NA
     */
    GLenum getPrimitiveType() const;
    /**
     * get index count
     *
     * @lua NA
     */
    ssize_t getIndexCount() const;
    /**
     * get index format
     *
     * @lua NA
     */
    GLenum getIndexFormat() const;
    /**
     * get index buffer
     *
     * @lua NA
     */
    GLuint getIndexBuffer() const;
    
    /**get AABB*/
    const AABB& getAABB() const { return _aabb; }
=======
#include <vector>

#include "3d/CCBundle3DData.h"

#include "base/CCRef.h"
#include "base/ccTypes.h"
#include "math/CCMath.h"
#include "renderer/CCGLProgram.h"

NS_CC_BEGIN

class EventListenerCustom;
class EventCustom;

class RenderMeshData
{
    friend class Mesh;
public:
    RenderMeshData(): _vertexsizeBytes(0)
    {
    }
    bool hasVertexAttrib(int attrib);
    bool init(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const std::vector<unsigned short>& indices);
    bool init(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs);
    
protected:
    
    int calVertexSizeBytes();
    
    int _vertexsizeBytes;
    ssize_t _vertexNum;
    std::vector<float> _vertexs;
    std::vector<unsigned short> _indices;
    std::vector<MeshVertexAttrib> _vertexAttribs;
};

/** 
 * Mesh: Geometry with a collection of vertex. 
 * Supporting various vertex formats.
 */
class Mesh : public Ref
{
public:
    /** Defines supported index formats. */
    enum class IndexFormat
    {
        INDEX8 = GL_UNSIGNED_BYTE,
        INDEX16 = GL_UNSIGNED_SHORT,
    };

    /** Defines supported primitive types. */
    enum class PrimitiveType
    {
        TRIANGLES = GL_TRIANGLES,
        TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
        LINES = GL_LINES,
        LINE_STRIP = GL_LINE_STRIP,
        POINTS = GL_POINTS
    };

    /**create mesh from positions, normals, and so on*/
    static Mesh* create(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const std::vector<unsigned short>& indices);
    
    /**create mesh with vertex attributes*/
    CC_DEPRECATED_ATTRIBUTE static Mesh* create(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, int numIndex, const std::vector<MeshVertexAttrib>& attribs, int attribCount) { return create(vertices, vertexSizeInFloat, indices, attribs); }
    
    /**create mesh with vertex attributes*/
    static Mesh* create(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs);

    /**get vertex buffer*/
    inline GLuint getVertexBuffer() const { return _vertexBuffer; }
    
    /**get mesh vertex attribute count*/
    ssize_t getMeshVertexAttribCount() const { return _renderdata._vertexAttribs.size(); }
    /**get MeshVertexAttribute by index*/
    const MeshVertexAttrib& getMeshVertexAttribute(int idx) const { return _renderdata._vertexAttribs[idx]; }
    /**has vertex attribute?*/
    bool hasVertexAttrib(int attrib) { return _renderdata.hasVertexAttrib(attrib); }
    /**get per vertex size in bytes*/
    int getVertexSizeInBytes() const { return _renderdata._vertexsizeBytes; }
    
    /** get primitive type*/
    PrimitiveType getPrimitiveType() const { return _primitiveType; }
    /**get index count*/
    ssize_t getIndexCount() const { return _indexCount; }
    /**get index format*/
    IndexFormat getIndexFormat() const { return _indexFormat; }
    /**get index buffer*/
    GLuint getIndexBuffer() const {return _indexBuffer; }
    
    /**build vertex buffer from renderdata*/
    void restore();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    
    Mesh();
    virtual ~Mesh();
<<<<<<< HEAD

    /** 
     * Get the default GL program.
     */
    GLProgram* getDefaultGLProgram(bool textured);
    
    /** 
     * Set the default GL program.
     */
    void setGLProgramState(GLProgramState* glProgramState);
    
    /** 
     * Get the MeshCommand.
     */
    MeshCommand& getMeshCommand() { return _meshCommand; }

    /**skin setter*/
    void setSkin(MeshSkin* skin);
    /**Mesh index data setter*/
    void setMeshIndexData(MeshIndexData* indexdata);
    /**name setter*/
    void setName(const std::string& name) { _name = name; }
 
    /** 
     * calculate the AABB of the mesh
     * @note the AABB is in the local space, not the world space
     */
    void calculateAABB();
    
    /** 
     * Bind to the MeshCommand
     */
    void bindMeshCommand();
protected:
    Texture2D* _texture;  //texture that submesh is using
    MeshSkin*  _skin;     //skin
    bool       _visible; // is the submesh visible
    bool       _isTransparent; // is this mesh transparent, it is a property of material in fact
    
    std::string  _name;
    MeshIndexData*     _meshIndexData;
    GLProgramState* _glProgramState;
    MeshCommand     _meshCommand;
    BlendFunc       _blend;
    AABB         _aabb;
    std::function<void()> _visibleChanged;
};

// end of 3d group
/// @}


NS_CC_END

#endif // __CCMESH_H__
=======
    /**init mesh*/
    bool init(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const std::vector<unsigned short>& indices);
    
    /**init mesh*/
    bool init(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs);

    /**build buffer*/
    void buildBuffer();
    /**free buffer*/
    void cleanAndFreeBuffers();

protected:
    PrimitiveType _primitiveType;
    IndexFormat _indexFormat;
    GLuint _vertexBuffer;
    GLuint _indexBuffer;
    ssize_t _indexCount;

    RenderMeshData _renderdata;
};

/**
 * Mesh Cache
 */
class MeshCache
{
public:
    /**get & destroy*/
    static MeshCache* getInstance();
    static void destroyInstance();
    
    /**get mesh from cache*/
    Mesh* getMesh(const std::string& key) const;
    
    /**add mesh to cache*/
    bool addMesh(const std::string& key, Mesh* mesh);
    
    /**remove all meshes*/
    void removeAllMeshes();

    /**remove unused meshes*/
    void removeUnusedMesh();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    void listenRendererRecreated(EventCustom* event);
#endif
    
CC_CONSTRUCTOR_ACCESS:
    
    MeshCache();
    ~MeshCache();
    
protected:
    
    static MeshCache* _cacheInstance;//instance
    
    std::unordered_map<std::string, Mesh*> _meshes; //cached meshes
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    EventListenerCustom* _rendererRecreatedListener;
#endif
};

NS_CC_END

#endif // __CCMESH_H_
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
