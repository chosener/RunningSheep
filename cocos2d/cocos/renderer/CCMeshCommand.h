/****************************************************************************
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

#ifndef _CC_MESHCOMMAND_H_
#define _CC_MESHCOMMAND_H_

#include <unordered_map>
<<<<<<< HEAD
#include "renderer/CCRenderCommand.h"
#include "renderer/CCGLProgram.h"
#include "math/CCMath.h"
=======
#include "CCRenderCommand.h"
#include "renderer/CCGLProgram.h"
#include "math/CCMath.h"
#include "CCRenderCommandPool.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

class GLProgramState;
class GLProgram;
struct Uniform;
class EventListenerCustom;
class EventCustom;

//it is a common mesh
<<<<<<< HEAD
class CC_DLL MeshCommand : public RenderCommand
=======
class MeshCommand : public RenderCommand
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
public:

    MeshCommand();
    ~MeshCommand();
<<<<<<< HEAD
    
    void init(float globalZOrder, GLuint textureID, GLProgramState* glProgramState, BlendFunc blendType, GLuint vertexBuffer, GLuint indexBuffer, GLenum primitive, GLenum indexFormat, ssize_t indexCount, const Mat4 &mv, uint32_t flags);
    
    CC_DEPRECATED_ATTRIBUTE void init(float globalZOrder, GLuint textureID, GLProgramState* glProgramState, BlendFunc blendType, GLuint vertexBuffer, GLuint indexBuffer, GLenum primitive, GLenum indexType, ssize_t indexCount, const Mat4 &mv);
=======

    void init(float globalOrder, GLuint textureID, GLProgramState* glProgramState, BlendFunc blendType, GLuint vertexBuffer, GLuint indexBuffer, GLenum primitive, GLenum indexType, ssize_t indexCount, const Mat4 &mv);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    void setCullFaceEnabled(bool enable);
    
    void setCullFace(GLenum cullFace);
    
    void setDepthTestEnabled(bool enable);
    
    void setDepthWriteEnabled(bool enable);
    
    void setDisplayColor(const Vec4& color);
    
    void setMatrixPalette(const Vec4* matrixPalette) { _matrixPalette = matrixPalette; }
    
    void setMatrixPaletteSize(int size) { _matrixPaletteSize = size; }
<<<<<<< HEAD

    void setLightMask(unsigned int lightmask) { _lightMask = lightmask; }
    
    void setTransparent(bool value);
    
    void execute();
    
    //used for batch
=======
    
    void execute();
    
    //used for bath
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void preBatchDraw();
    void batchDraw();
    void postBatchDraw();
    
<<<<<<< HEAD
    void genMaterialID(GLuint texID, void* glProgramState, GLuint vertexBuffer, GLuint indexBuffer, const BlendFunc& blend);
    
    uint32_t getMaterialID() const { return _materialID; }
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
=======
    void genMaterialID(GLuint texID, void* glProgramState, void* mesh, const BlendFunc& blend);
    
    uint32_t getMaterialID() const { return _materialID; }
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void listenRendererRecreated(EventCustom* event);
#endif

protected:
    //build & release vao
    void buildVAO();
    void releaseVAO();
    
    // apply renderstate
    void applyRenderState();
<<<<<<< HEAD

    void setLightUniforms();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    //restore to all false
    void restoreRenderState();
    
    void MatrixPalleteCallBack( GLProgram* glProgram, Uniform* uniform);

<<<<<<< HEAD
    void resetLightUniformValues();

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    GLuint _textureID;
    GLProgramState* _glProgramState;
    BlendFunc _blendType;

    GLuint _textrueID;
    
    Vec4 _displayColor; // in order to support tint and fade in fade out
    
    // used for skin
    const Vec4* _matrixPalette;
    int   _matrixPaletteSize;
    
    uint32_t _materialID; //material ID
    
    GLuint   _vao; //use vao if possible
    
    GLuint _vertexBuffer;
    GLuint _indexBuffer;
    GLenum _primitive;
    GLenum _indexFormat;
    ssize_t _indexCount;
    
    // States, default value all false
    bool _cullFaceEnabled;
    GLenum _cullFace;
    bool _depthTestEnabled;
    bool _depthWriteEnabled;
<<<<<<< HEAD
    bool _forceDepthWrite;
    
    bool _renderStateCullFaceEnabled;
    bool _renderStateDepthTest;
    GLboolean _renderStateDepthWrite;
    GLenum    _renderStateCullFace;

    // ModelView transform
    Mat4 _mv;

    unsigned int _lightMask;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
=======

    // ModelView transform
    Mat4 _mv;
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    EventListenerCustom* _rendererRecreatedListener;
#endif
};

NS_CC_END

#endif //_CC_MESHCOMMAND_H_
