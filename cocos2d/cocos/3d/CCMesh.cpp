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

<<<<<<< HEAD
#include "3d/CCMesh.h"
#include "3d/CCMeshSkin.h"
#include "3d/CCSkeleton3D.h"
#include "3d/CCMeshVertexIndexData.h"
#include "base/CCEventDispatcher.h"
#include "base/CCDirector.h"
#include "renderer/CCTextureCache.h"
#include "renderer/CCGLProgramState.h"

using namespace std;

NS_CC_BEGIN

Mesh::Mesh()
: _texture(nullptr)
, _skin(nullptr)
, _visible(true)
, _isTransparent(false)
, _meshIndexData(nullptr)
, _glProgramState(nullptr)
, _blend(BlendFunc::ALPHA_NON_PREMULTIPLIED)
, _visibleChanged(nullptr)
{
    
}
Mesh::~Mesh()
{
    CC_SAFE_RELEASE(_texture);
    CC_SAFE_RELEASE(_skin);
    CC_SAFE_RELEASE(_meshIndexData);
    CC_SAFE_RELEASE(_glProgramState);
}

GLuint Mesh::getVertexBuffer() const
{
    return _meshIndexData->getVertexBuffer()->getVBO();
}

bool Mesh::hasVertexAttrib(int attrib) const
{
    return _meshIndexData->getMeshVertexData()->hasVertexAttrib(attrib);
}

ssize_t Mesh::getMeshVertexAttribCount() const
{
    return _meshIndexData->getMeshVertexData()->getMeshVertexAttribCount();
}

const MeshVertexAttrib& Mesh::getMeshVertexAttribute(int idx)
{
    return _meshIndexData->getMeshVertexData()->getMeshVertexAttrib(idx);
}

int Mesh::getVertexSizeInBytes() const
{
    return _meshIndexData->getVertexBuffer()->getSizePerVertex();
}

Mesh* Mesh::create(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const IndexArray& indices)
{
    int perVertexSizeInFloat = 0;
    std::vector<float> vertices;
    std::vector<MeshVertexAttrib> attribs;
    MeshVertexAttrib att;
    att.size = 3;
    att.type = GL_FLOAT;
    att.attribSizeBytes = att.size * sizeof(float);
    
    if (positions.size())
    {
        perVertexSizeInFloat += 3;
        att.vertexAttrib = GLProgram::VERTEX_ATTRIB_POSITION;
        attribs.push_back(att);
    }
    if (normals.size())
    {
        perVertexSizeInFloat += 3;
        att.vertexAttrib = GLProgram::VERTEX_ATTRIB_NORMAL;
        attribs.push_back(att);
    }
    if (texs.size())
    {
        perVertexSizeInFloat += 2;
        att.vertexAttrib = GLProgram::VERTEX_ATTRIB_TEX_COORD;
        att.size = 2;
        att.attribSizeBytes = att.size * sizeof(float);
        attribs.push_back(att);
    }
    
    bool hasNormal = (normals.size() != 0);
    bool hasTexCoord = (texs.size() != 0);
    //position, normal, texCoordinate into _vertexs
    size_t vertexNum = positions.size() / 3;
    for(size_t i = 0; i < vertexNum; i++)
    {
        vertices.push_back(positions[i * 3]);
        vertices.push_back(positions[i * 3 + 1]);
        vertices.push_back(positions[i * 3 + 2]);

        if (hasNormal)
        {
            vertices.push_back(normals[i * 3]);
            vertices.push_back(normals[i * 3 + 1]);
            vertices.push_back(normals[i * 3 + 2]);
        }
    
        if (hasTexCoord)
        {
            vertices.push_back(texs[i * 2]);
            vertices.push_back(texs[i * 2 + 1]);
        }
    }
    return create(vertices, perVertexSizeInFloat, indices, attribs);
}

Mesh* Mesh::create(const std::vector<float>& vertices, int perVertexSizeInFloat, const IndexArray& indices, const std::vector<MeshVertexAttrib>& attribs)
{
    MeshData meshdata;
    meshdata.attribs = attribs;
    meshdata.vertex = vertices;
    meshdata.subMeshIndices.push_back(indices);
    meshdata.subMeshIds.push_back("");
    auto meshvertexdata = MeshVertexData::create(meshdata);
    auto indexData = meshvertexdata->getMeshIndexDataByIndex(0);
    
    return create("", indexData);
}

Mesh* Mesh::create(const std::string& name, MeshIndexData* indexData, MeshSkin* skin)
{
    auto state = new (std::nothrow) Mesh();
    state->autorelease();
    state->bindMeshCommand();
    state->_name = name;
    state->setMeshIndexData(indexData);
    state->setSkin(skin);
    
    return state;
}

void Mesh::setVisible(bool visible)
{
    if (_visible != visible)
    {
        _visible = visible;
        if (_visibleChanged)
            _visibleChanged();
    }
}

void Mesh::setTexture(const std::string& texPath)
{
    auto tex = Director::getInstance()->getTextureCache()->addImage(texPath);
    setTexture(tex);
}

void Mesh::setTexture(Texture2D* tex)
{
    if (tex != _texture)
    {
        CC_SAFE_RETAIN(tex);
        CC_SAFE_RELEASE(_texture);
        _texture = tex;
        bindMeshCommand();
    }
}

void Mesh::setSkin(MeshSkin* skin)
{
    if (_skin != skin)
    {
        CC_SAFE_RETAIN(skin);
        CC_SAFE_RELEASE(_skin);
        _skin = skin;
        calculateAABB();
    }
}

void Mesh::setMeshIndexData(MeshIndexData* subMesh)
{
    if (_meshIndexData != subMesh)
    {
        CC_SAFE_RETAIN(subMesh);
        CC_SAFE_RELEASE(_meshIndexData);
        _meshIndexData = subMesh;
        calculateAABB();
        bindMeshCommand();
    }
}

void Mesh::setGLProgramState(GLProgramState* glProgramState)
{
    if (_glProgramState != glProgramState)
    {
        CC_SAFE_RETAIN(glProgramState);
        CC_SAFE_RELEASE(_glProgramState);
        _glProgramState = glProgramState;
        bindMeshCommand();
    }
}

void Mesh::calculateAABB()
{
    if (_meshIndexData)
    {
        _aabb = _meshIndexData->getAABB();
        if (_skin)
        {
            //get skin root
            Bone3D* root = nullptr;
            Mat4 invBindPose;
            if (_skin->_skinBones.size())
            {
                root = _skin->_skinBones.at(0);
                while (root) {
                    auto parent = root->getParentBone();
                    bool parentInSkinBone = false;
                    for (const auto& bone : _skin->_skinBones) {
                        if (bone == parent)
                        {
                            parentInSkinBone = true;
                            break;
                        }
                    }
                    if (!parentInSkinBone)
                        break;
                    root = parent;
                }
            }
            
            if (root)
            {
                _aabb.transform(root->getWorldMat() * _skin->getInvBindPose(root));
            }
        }
    }
}

void Mesh::bindMeshCommand()
{
    if (_glProgramState && _meshIndexData && _texture)
    {
        GLuint texID = _texture ? _texture->getName() : 0;
        _meshCommand.genMaterialID(texID, _glProgramState, _meshIndexData->getVertexBuffer()->getVBO(), _meshIndexData->getIndexBuffer()->getVBO(), _blend);
        _meshCommand.setCullFaceEnabled(true);
        _meshCommand.setDepthTestEnabled(true);
    }
}

void Mesh::setBlendFunc(const BlendFunc &blendFunc)
{
    if(_blend.src != blendFunc.src || _blend.dst != blendFunc.dst)
    {
        _blend = blendFunc;
        bindMeshCommand();
    }
}
const BlendFunc &Mesh::getBlendFunc() const
{
    return _blend;
}

GLenum Mesh::getPrimitiveType() const
{
    return _meshIndexData->getPrimitiveType();
}

ssize_t Mesh::getIndexCount() const
{
    return _meshIndexData->getIndexBuffer()->getIndexNumber();
}

GLenum Mesh::getIndexFormat() const
{
    return GL_UNSIGNED_SHORT;
}

GLuint Mesh::getIndexBuffer() const
{
    return _meshIndexData->getIndexBuffer()->getVBO();
}
=======
#include "CCMesh.h"

#include <list>
#include <fstream>
#include <iostream>
#include <sstream>

#include "3d/CCObjLoader.h"
#include "3d/CCSprite3DMaterial.h"

#include "base/ccMacros.h"
#include "base/CCEventCustom.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventType.h"
#include "base/CCDirector.h"
#include "renderer/ccGLStateCache.h"


using namespace std;

NS_CC_BEGIN

bool RenderMeshData::hasVertexAttrib(int attrib)
{
    for (auto itr = _vertexAttribs.begin(); itr != _vertexAttribs.end(); itr++)
    {
        if ((*itr).vertexAttrib == attrib)
            return true; //already has
    }
    return false;
}

bool RenderMeshData::init(const std::vector<float>& positions,
                              const std::vector<float>& normals,
                              const std::vector<float>& texs,
                              const std::vector<unsigned short>& indices)
{
    CC_ASSERT(positions.size()<65536 * 3 && "index may out of bound");
    
    _vertexAttribs.clear();
    
    _vertexNum = positions.size() / 3; //number of vertex
    if (_vertexNum == 0)
        return false;
    
    if ((normals.size() != 0 && _vertexNum * 3 != normals.size()) || (texs.size() != 0 && _vertexNum * 2 != texs.size()))
        return false;
    
    MeshVertexAttrib meshvertexattrib;
    meshvertexattrib.size = 3;
    meshvertexattrib.type = GL_FLOAT;
    meshvertexattrib.attribSizeBytes = meshvertexattrib.size * sizeof(float);
    meshvertexattrib.vertexAttrib = GLProgram::VERTEX_ATTRIB_POSITION;
    _vertexAttribs.push_back(meshvertexattrib);
    
    //normal
    if (normals.size())
    {
        //add normal flag
        meshvertexattrib.vertexAttrib = GLProgram::VERTEX_ATTRIB_NORMAL;
        _vertexAttribs.push_back(meshvertexattrib);
    }
    //
    if (texs.size())
    {
        meshvertexattrib.size = 2;
        meshvertexattrib.vertexAttrib = GLProgram::VERTEX_ATTRIB_TEX_COORD;
        meshvertexattrib.attribSizeBytes = meshvertexattrib.size * sizeof(float);
        _vertexAttribs.push_back(meshvertexattrib);
    }
    
    _vertexs.clear();
    _vertexsizeBytes = calVertexSizeBytes();
    _vertexs.reserve(_vertexNum * _vertexsizeBytes / sizeof(float));
    
    bool hasNormal = hasVertexAttrib(GLProgram::VERTEX_ATTRIB_NORMAL);
    bool hasTexCoord = hasVertexAttrib(GLProgram::VERTEX_ATTRIB_TEX_COORD);
    //position, normal, texCoordinate into _vertexs
    for(int i = 0; i < _vertexNum; i++)
    {
        _vertexs.push_back(positions[i * 3]);
        _vertexs.push_back(positions[i * 3 + 1]);
        _vertexs.push_back(positions[i * 3 + 2]);
        
        if (hasNormal)
        {
            _vertexs.push_back(normals[i * 3]);
            _vertexs.push_back(normals[i * 3 + 1]);
            _vertexs.push_back(normals[i * 3 + 2]);
        }
        
        if (hasTexCoord)
        {
            _vertexs.push_back(texs[i * 2]);
            _vertexs.push_back(texs[i * 2 + 1]);
        }
    }
    _indices = indices;
    
    return true;
}

bool RenderMeshData::init(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs)
{
    _vertexs = vertices;
    _indices = indices;
    _vertexAttribs = attribs;
    
    _vertexsizeBytes = calVertexSizeBytes();
    
    return true;
}

int RenderMeshData::calVertexSizeBytes()
{
    int sizeBytes = 0;
    for (auto it = _vertexAttribs.begin(); it != _vertexAttribs.end(); it++) {
        sizeBytes += (*it).size;
        CCASSERT((*it).type == GL_FLOAT, "use float");
    }
    sizeBytes *= sizeof(float);
    
    return sizeBytes;
}

Mesh::Mesh()
:_vertexBuffer(0)
, _indexBuffer(0)
, _primitiveType(PrimitiveType::TRIANGLES)
, _indexFormat(IndexFormat::INDEX16)
, _indexCount(0)
{
}

Mesh::~Mesh()
{
    cleanAndFreeBuffers();
}

Mesh* Mesh::create(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const std::vector<unsigned short>& indices)
{
    auto mesh = new Mesh();
    if(mesh && mesh->init(positions, normals, texs, indices))
    {
        mesh->autorelease();
        return mesh;
    }
    CC_SAFE_DELETE(mesh);
    return nullptr;
}

Mesh* Mesh::create(const std::vector<float> &vertices, int vertexSizeInFloat, const std::vector<unsigned short> &indices, const std::vector<MeshVertexAttrib> &attribs)
{
    auto mesh = new Mesh();
    if (mesh && mesh->init(vertices, vertexSizeInFloat, indices, attribs))
    {
        mesh->autorelease();
        return mesh;
    }
    CC_SAFE_DELETE(mesh);
    return nullptr;
}

bool Mesh::init(const std::vector<float>& positions, const std::vector<float>& normals, const std::vector<float>& texs, const std::vector<unsigned short>& indices)
{
    bool bRet = _renderdata.init(positions, normals, texs, indices);
    if (!bRet)
        return false;
    
    buildBuffer();
    return true;
}

bool Mesh::init(const std::vector<float>& vertices, int vertexSizeInFloat, const std::vector<unsigned short>& indices, const std::vector<MeshVertexAttrib>& attribs)
{
    bool bRet = _renderdata.init(vertices, vertexSizeInFloat, indices, attribs);
    if (!bRet)
        return false;
    
    buildBuffer();
    return true;
}

void Mesh::cleanAndFreeBuffers()
{
    if(glIsBuffer(_vertexBuffer))
    {
        glDeleteBuffers(1, &_vertexBuffer);
        _vertexBuffer = 0;
    }
    
    if(glIsBuffer(_indexBuffer))
    {
        glDeleteBuffers(1, &_indexBuffer);
        _indexBuffer = 0;
    }
    _primitiveType = PrimitiveType::TRIANGLES;
    _indexFormat = IndexFormat::INDEX16;
    _indexCount = 0;
}

void Mesh::buildBuffer()
{
    cleanAndFreeBuffers();

    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    
    glBufferData(GL_ARRAY_BUFFER,
                 _renderdata._vertexs.size() * sizeof(_renderdata._vertexs[0]),
                 &_renderdata._vertexs[0],
                 GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &_indexBuffer);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
    
    unsigned int indexSize = 2;
    
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize * _renderdata._indices.size(), &_renderdata._indices[0], GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    _primitiveType = PrimitiveType::TRIANGLES;
    _indexFormat = IndexFormat::INDEX16;
    _indexCount = _renderdata._indices.size();
}

void Mesh::restore()
{
    _vertexBuffer = 0;
    _indexBuffer = 0;
    buildBuffer();
}

/**
 * MeshCache
 */
MeshCache* MeshCache::_cacheInstance = nullptr;

MeshCache* MeshCache::getInstance()
{
    if (_cacheInstance == nullptr)
        _cacheInstance = new MeshCache();
    
    return _cacheInstance;
}
void MeshCache::destroyInstance()
{
    if (_cacheInstance)
        CC_SAFE_DELETE(_cacheInstance);
}

Mesh* MeshCache::getMesh(const std::string& key) const
{
    auto it = _meshes.find(key);
    if (it != _meshes.end())
        return it->second;
    
    return nullptr;
}

bool MeshCache::addMesh(const std::string& key, Mesh* mesh)
{
    auto it = _meshes.find(key);
    if (it == _meshes.end())
    {
        mesh->retain();
        _meshes[key] = mesh;
        
        return true;
    }
    return false;
}

void MeshCache::removeAllMeshes()
{
    for (auto it : _meshes) {
        CC_SAFE_RELEASE(it.second);
    }
    _meshes.clear();
}

void MeshCache::removeUnusedMesh()
{
    for( auto it=_meshes.cbegin(); it!=_meshes.cend(); /* nothing */) {
        if(it->second->getReferenceCount() == 1)
        {
            it->second->release();
            _meshes.erase(it++);
        }
        else
            ++it;
    }
}

MeshCache::MeshCache()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    // listen the event that renderer was recreated on Android/WP8
    _rendererRecreatedListener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, CC_CALLBACK_1(MeshCache::listenRendererRecreated, this));
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_rendererRecreatedListener, -1);
#endif
}
MeshCache::~MeshCache()
{
    removeAllMeshes();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    Director::getInstance()->getEventDispatcher()->removeEventListener(_rendererRecreatedListener);
#endif
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
void MeshCache::listenRendererRecreated(EventCustom* event)
{
    for (auto iter = _meshes.begin(); iter != _meshes.end(); ++iter)
    {
        auto mesh = iter->second;
        mesh->restore();
    }
}
#endif
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_END
