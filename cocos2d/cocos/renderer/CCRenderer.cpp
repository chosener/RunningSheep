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

#include "renderer/CCRenderer.h"

#include <algorithm>

<<<<<<< HEAD
#include "renderer/CCTrianglesCommand.h"
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "renderer/CCQuadCommand.h"
#include "renderer/CCBatchCommand.h"
#include "renderer/CCCustomCommand.h"
#include "renderer/CCGroupCommand.h"
<<<<<<< HEAD
#include "renderer/CCPrimitiveCommand.h"
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "renderer/CCGLProgramCache.h"
#include "renderer/ccGLStateCache.h"
#include "renderer/CCMeshCommand.h"
#include "base/CCConfiguration.h"
#include "base/CCDirector.h"
#include "base/CCEventDispatcher.h"
#include "base/CCEventListenerCustom.h"
#include "base/CCEventType.h"
<<<<<<< HEAD
#include "2d/CCCamera.h"
#include "2d/CCScene.h"
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_BEGIN

// helper
static bool compareRenderCommand(RenderCommand* a, RenderCommand* b)
{
    return a->getGlobalOrder() < b->getGlobalOrder();
}

<<<<<<< HEAD
static bool compare3DCommand(RenderCommand* a, RenderCommand* b)
{
    return  a->getDepth() > b->getDepth();
}

// queue
RenderQueue::RenderQueue()
{
    
}
=======
// queue
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

void RenderQueue::push_back(RenderCommand* command)
{
    float z = command->getGlobalOrder();
    if(z < 0)
<<<<<<< HEAD
    {
        _commands[QUEUE_GROUP::GLOBALZ_NEG].push_back(command);
    }
    else if(z > 0)
    {
        _commands[QUEUE_GROUP::GLOBALZ_POS].push_back(command);
    }
    else
    {
        if(command->is3D())
        {
            if(command->isTransparent())
            {
                _commands[QUEUE_GROUP::TRANSPARENT_3D].push_back(command);
            }
            else
            {
                _commands[QUEUE_GROUP::OPAQUE_3D].push_back(command);
            }
        }
        else
        {
            _commands[QUEUE_GROUP::GLOBALZ_ZERO].push_back(command);
        }
    }
=======
        _queueNegZ.push_back(command);
    else if(z > 0)
        _queuePosZ.push_back(command);
    else
        _queue0.push_back(command);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

ssize_t RenderQueue::size() const
{
<<<<<<< HEAD
    ssize_t result(0);
    for(int index = 0; index < QUEUE_GROUP::QUEUE_COUNT; ++index)
    {
        result += _commands[index].size();
    }
    
    return result;
=======
    return _queueNegZ.size() + _queue0.size() + _queuePosZ.size();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void RenderQueue::sort()
{
    // Don't sort _queue0, it already comes sorted
<<<<<<< HEAD
    std::sort(std::begin(_commands[QUEUE_GROUP::TRANSPARENT_3D]), std::end(_commands[QUEUE_GROUP::TRANSPARENT_3D]), compare3DCommand);
    std::sort(std::begin(_commands[QUEUE_GROUP::GLOBALZ_NEG]), std::end(_commands[QUEUE_GROUP::GLOBALZ_NEG]), compareRenderCommand);
    std::sort(std::begin(_commands[QUEUE_GROUP::GLOBALZ_POS]), std::end(_commands[QUEUE_GROUP::GLOBALZ_POS]), compareRenderCommand);
=======
    std::sort(std::begin(_queueNegZ), std::end(_queueNegZ), compareRenderCommand);
    std::sort(std::begin(_queuePosZ), std::end(_queuePosZ), compareRenderCommand);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

RenderCommand* RenderQueue::operator[](ssize_t index) const
{
<<<<<<< HEAD
    for(int queIndex = 0; queIndex < QUEUE_GROUP::QUEUE_COUNT; ++queIndex)
    {
        if(index < static_cast<ssize_t>(_commands[queIndex].size()))
            return _commands[queIndex][index];
        else
        {
            index -= _commands[queIndex].size();
        }
    }
    
    CCASSERT(false, "invalid index");
    return nullptr;


}

void RenderQueue::clear()
{
    for(int i = 0; i < QUEUE_COUNT; ++i)
    {
        _commands[i].clear();
    }
}

void RenderQueue::realloc(size_t reserveSize)
{
    for(int i = 0; i < QUEUE_COUNT; ++i)
    {
        _commands[i] = std::vector<RenderCommand*>();
        _commands[i].reserve(reserveSize);
    }
}

void RenderQueue::saveRenderState()
{
    _isDepthEnabled = glIsEnabled(GL_DEPTH_TEST) != GL_FALSE;
    _isCullEnabled = glIsEnabled(GL_CULL_FACE) != GL_FALSE;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &_isDepthWrite);
    
    CHECK_GL_ERROR_DEBUG();
}

void RenderQueue::restoreRenderState()
{
    if (_isCullEnabled)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }
    
    
    if (_isDepthEnabled)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }
    
    glDepthMask(_isDepthWrite);
    
    CHECK_GL_ERROR_DEBUG();
=======
    if(index < static_cast<ssize_t>(_queueNegZ.size()))
        return _queueNegZ[index];

    index -= _queueNegZ.size();

    if(index < static_cast<ssize_t>(_queue0.size()))
        return _queue0[index];

    index -= _queue0.size();

    if(index < static_cast<ssize_t>(_queuePosZ.size()))
        return _queuePosZ[index];

    CCASSERT(false, "invalid index");
    return nullptr;
}

void RenderQueue::clear()
{
    _queueNegZ.clear();
    _queue0.clear();
    _queuePosZ.clear();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

//
//
//
static const int DEFAULT_RENDER_QUEUE = 0;

//
// constructors, destructors, init
//
Renderer::Renderer()
:_lastMaterialID(0)
,_lastBatchedMeshCommand(nullptr)
<<<<<<< HEAD
,_filledVertex(0)
,_filledIndex(0)
,_numberQuads(0)
,_glViewAssigned(false)
,_isRendering(false)
,_isDepthTestFor2D(false)
=======
,_numQuads(0)
,_glViewAssigned(false)
,_isRendering(false)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#if CC_ENABLE_CACHE_TEXTURE_DATA
,_cacheTextureListener(nullptr)
#endif
{
<<<<<<< HEAD
    _groupCommandManager = new (std::nothrow) GroupCommandManager();
=======
    _groupCommandManager = new GroupCommandManager();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    _commandGroupStack.push(DEFAULT_RENDER_QUEUE);
    
    RenderQueue defaultRenderQueue;
    _renderGroups.push_back(defaultRenderQueue);
<<<<<<< HEAD
    _batchedCommands.reserve(BATCH_QUADCOMMAND_RESEVER_SIZE);

    // default clear color
    _clearColor = Color4F::BLACK;
=======
    _batchedQuadCommands.reserve(BATCH_QUADCOMMAND_RESEVER_SIZE);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

Renderer::~Renderer()
{
    _renderGroups.clear();
    _groupCommandManager->release();
    
    glDeleteBuffers(2, _buffersVBO);
<<<<<<< HEAD
    glDeleteBuffers(2, _quadbuffersVBO);
    
    if (Configuration::getInstance()->supportsShareableVAO())
    {
        glDeleteVertexArrays(1, &_buffersVAO);
=======
    
    if (Configuration::getInstance()->supportsShareableVAO())
    {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        glDeleteVertexArrays(1, &_quadVAO);
        GL::bindVAO(0);
    }
#if CC_ENABLE_CACHE_TEXTURE_DATA
    Director::getInstance()->getEventDispatcher()->removeEventListener(_cacheTextureListener);
#endif
}

void Renderer::initGLView()
{
#if CC_ENABLE_CACHE_TEXTURE_DATA
    _cacheTextureListener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event){
        /** listen the event that renderer was recreated on Android/WP8 */
        this->setupBuffer();
    });
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_cacheTextureListener, -1);
#endif
<<<<<<< HEAD
    
    //setup index data for quads
    
    for( int i=0; i < VBO_SIZE/4; i++)
    {
        _quadIndices[i*6+0] = (GLushort) (i*4+0);
        _quadIndices[i*6+1] = (GLushort) (i*4+1);
        _quadIndices[i*6+2] = (GLushort) (i*4+2);
        _quadIndices[i*6+3] = (GLushort) (i*4+3);
        _quadIndices[i*6+4] = (GLushort) (i*4+2);
        _quadIndices[i*6+5] = (GLushort) (i*4+1);
    }
=======

    setupIndices();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    setupBuffer();
    
    _glViewAssigned = true;
}

<<<<<<< HEAD
=======
void Renderer::setupIndices()
{
    for( int i=0; i < VBO_SIZE; i++)
    {
        _indices[i*6+0] = (GLushort) (i*4+0);
        _indices[i*6+1] = (GLushort) (i*4+1);
        _indices[i*6+2] = (GLushort) (i*4+2);
        _indices[i*6+3] = (GLushort) (i*4+3);
        _indices[i*6+4] = (GLushort) (i*4+2);
        _indices[i*6+5] = (GLushort) (i*4+1);
    }
}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Renderer::setupBuffer()
{
    if(Configuration::getInstance()->supportsShareableVAO())
    {
        setupVBOAndVAO();
    }
    else
    {
        setupVBO();
    }
}

void Renderer::setupVBOAndVAO()
{
<<<<<<< HEAD
    //generate vbo and vao for trianglesCommand
    glGenVertexArrays(1, &_buffersVAO);
    GL::bindVAO(_buffersVAO);
=======
    glGenVertexArrays(1, &_quadVAO);
    GL::bindVAO(_quadVAO);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    glGenBuffers(2, &_buffersVBO[0]);

    glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);
<<<<<<< HEAD
    glBufferData(GL_ARRAY_BUFFER, sizeof(_verts[0]) * VBO_SIZE, _verts, GL_DYNAMIC_DRAW);
=======
    glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * VBO_SIZE, _quads, GL_DYNAMIC_DRAW);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    // vertices
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, vertices));

    // colors
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, colors));

    // tex coords
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_TEX_COORD);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, texCoords));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
<<<<<<< HEAD
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * INDEX_VBO_SIZE, _indices, GL_STATIC_DRAW);
=======
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * VBO_SIZE * 6, _indices, GL_STATIC_DRAW);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    // Must unbind the VAO before changing the element buffer.
    GL::bindVAO(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

<<<<<<< HEAD
    //generate vbo and vao for quadCommand
    glGenVertexArrays(1, &_quadVAO);
    GL::bindVAO(_quadVAO);
    
    glGenBuffers(2, &_quadbuffersVBO[0]);
    
    glBindBuffer(GL_ARRAY_BUFFER, _quadbuffersVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_quadVerts[0]) * VBO_SIZE, _quadVerts, GL_DYNAMIC_DRAW);
    
    // vertices
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, vertices));
    
    // colors
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, colors));
    
    // tex coords
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_TEX_COORD);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, sizeof(V3F_C4B_T2F), (GLvoid*) offsetof( V3F_C4B_T2F, texCoords));
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _quadbuffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_quadIndices[0]) * INDEX_VBO_SIZE, _quadIndices, GL_STATIC_DRAW);
    
    // Must unbind the VAO before changing the element buffer.
    GL::bindVAO(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CHECK_GL_ERROR_DEBUG();
}

void Renderer::setupVBO()
{
    glGenBuffers(2, &_buffersVBO[0]);
<<<<<<< HEAD
    glGenBuffers(2, &_quadbuffersVBO[0]);
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    mapBuffers();
}

void Renderer::mapBuffers()
{
    // Avoid changing the element buffer for whatever VAO might be bound.
    GL::bindVAO(0);

    glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);
<<<<<<< HEAD
    glBufferData(GL_ARRAY_BUFFER, sizeof(_verts[0]) * VBO_SIZE, _verts, GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, _quadbuffersVBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_quadVerts[0]) * VBO_SIZE, _quadVerts, GL_DYNAMIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * INDEX_VBO_SIZE, _indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _quadbuffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_quadIndices[0]) * INDEX_VBO_SIZE, _quadIndices, GL_STATIC_DRAW);
    
=======
    glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * VBO_SIZE, _quads, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * VBO_SIZE * 6, _indices, GL_STATIC_DRAW);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    CHECK_GL_ERROR_DEBUG();
}

void Renderer::addCommand(RenderCommand* command)
{
    int renderQueue =_commandGroupStack.top();
    addCommand(command, renderQueue);
}

void Renderer::addCommand(RenderCommand* command, int renderQueue)
{
    CCASSERT(!_isRendering, "Cannot add command while rendering");
    CCASSERT(renderQueue >=0, "Invalid render queue");
    CCASSERT(command->getType() != RenderCommand::Type::UNKNOWN_COMMAND, "Invalid Command Type");
<<<<<<< HEAD

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _renderGroups[renderQueue].push_back(command);
}

void Renderer::pushGroup(int renderQueueID)
{
    CCASSERT(!_isRendering, "Cannot change render queue while rendering");
    _commandGroupStack.push(renderQueueID);
}

void Renderer::popGroup()
{
    CCASSERT(!_isRendering, "Cannot change render queue while rendering");
    _commandGroupStack.pop();
}

int Renderer::createRenderQueue()
{
    RenderQueue newRenderQueue;
    _renderGroups.push_back(newRenderQueue);
    return (int)_renderGroups.size() - 1;
}

<<<<<<< HEAD
void Renderer::processRenderCommand(RenderCommand* command)
{
    auto commandType = command->getType();
    if( RenderCommand::Type::TRIANGLES_COMMAND == commandType)
    {
        //Draw if we have batched other commands which are not triangle command
        flush3D();
        flushQuads();
        
        //Process triangle command
        auto cmd = static_cast<TrianglesCommand*>(command);
        
        //Draw batched Triangles if necessary
        if(cmd->isSkipBatching() || _filledVertex + cmd->getVertexCount() > VBO_SIZE || _filledIndex + cmd->getIndexCount() > INDEX_VBO_SIZE)
        {
            CCASSERT(cmd->getVertexCount()>= 0 && cmd->getVertexCount() < VBO_SIZE, "VBO for vertex is not big enough, please break the data down or use customized render command");
            CCASSERT(cmd->getIndexCount()>= 0 && cmd->getIndexCount() < INDEX_VBO_SIZE, "VBO for index is not big enough, please break the data down or use customized render command");
            //Draw batched Triangles if VBO is full
            drawBatchedTriangles();
        }
        
        //Batch Triangles
        _batchedCommands.push_back(cmd);
        
        fillVerticesAndIndices(cmd);
        
        if(cmd->isSkipBatching())
        {
            drawBatchedTriangles();
        }
        
    }
    else if ( RenderCommand::Type::QUAD_COMMAND == commandType )
    {
        //Draw if we have batched other commands which are not quad command
        flush3D();
        flushTriangles();
        
        //Process quad command
        auto cmd = static_cast<QuadCommand*>(command);
        
        //Draw batched quads if necessary
        if(cmd->isSkipBatching()|| (_numberQuads + cmd->getQuadCount()) * 4 > VBO_SIZE )
        {
            CCASSERT(cmd->getQuadCount()>= 0 && cmd->getQuadCount() * 4 < VBO_SIZE, "VBO for vertex is not big enough, please break the data down or use customized render command");
            //Draw batched quads if VBO is full
            drawBatchedQuads();
        }
        
        //Batch Quads
        _batchQuadCommands.push_back(cmd);
        
        fillQuads(cmd);
        
        if(cmd->isSkipBatching())
        {
            drawBatchedQuads();
        }
    }
    else if (RenderCommand::Type::MESH_COMMAND == commandType)
    {
        flush2D();
        auto cmd = static_cast<MeshCommand*>(command);
        
        if (cmd->isSkipBatching() || _lastBatchedMeshCommand == nullptr || _lastBatchedMeshCommand->getMaterialID() != cmd->getMaterialID())
        {
            flush3D();
            
            if(cmd->isSkipBatching())
            {
                cmd->execute();
            }
            else
            {
                cmd->preBatchDraw();
                cmd->batchDraw();
                _lastBatchedMeshCommand = cmd;
=======
void Renderer::visitRenderQueue(const RenderQueue& queue)
{
    ssize_t size = queue.size();
    
    for (ssize_t index = 0; index < size; ++index)
    {
        auto command = queue[index];
        auto commandType = command->getType();
        if(RenderCommand::Type::QUAD_COMMAND == commandType)
        {
            flush3D();
            auto cmd = static_cast<QuadCommand*>(command);
            //Batch quads
            if(_numQuads + cmd->getQuadCount() > VBO_SIZE)
            {
                CCASSERT(cmd->getQuadCount()>= 0 && cmd->getQuadCount() < VBO_SIZE, "VBO is not big enough for quad data, please break the quad data down or use customized render command");
                
                //Draw batched quads if VBO is full
                drawBatchedQuads();
            }
            
            _batchedQuadCommands.push_back(cmd);
            
            memcpy(_quads + _numQuads, cmd->getQuads(), sizeof(V3F_C4B_T2F_Quad) * cmd->getQuadCount());
            convertToWorldCoordinates(_quads + _numQuads, cmd->getQuadCount(), cmd->getModelView());
            
            _numQuads += cmd->getQuadCount();

        }
        else if(RenderCommand::Type::GROUP_COMMAND == commandType)
        {
            flush();
            int renderQueueID = ((GroupCommand*) command)->getRenderQueueID();
            visitRenderQueue(_renderGroups[renderQueueID]);
        }
        else if(RenderCommand::Type::CUSTOM_COMMAND == commandType)
        {
            flush();
            auto cmd = static_cast<CustomCommand*>(command);
            cmd->execute();
        }
        else if(RenderCommand::Type::BATCH_COMMAND == commandType)
        {
            flush();
            auto cmd = static_cast<BatchCommand*>(command);
            cmd->execute();
        }
        else if (RenderCommand::Type::MESH_COMMAND == commandType)
        {
            flush2D();
            auto cmd = static_cast<MeshCommand*>(command);
            if (_lastBatchedMeshCommand == nullptr || _lastBatchedMeshCommand->getMaterialID() != cmd->getMaterialID())
            {
                flush3D();
                cmd->preBatchDraw();
                cmd->batchDraw();
                _lastBatchedMeshCommand = cmd;
            }
            else
            {
                cmd->batchDraw();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }
        }
        else
        {
<<<<<<< HEAD
            cmd->batchDraw();
        }
    }
    else if(RenderCommand::Type::GROUP_COMMAND == commandType)
    {
        flush();
        int renderQueueID = ((GroupCommand*) command)->getRenderQueueID();
        visitRenderQueue(_renderGroups[renderQueueID]);
    }
    else if(RenderCommand::Type::CUSTOM_COMMAND == commandType)
    {
        flush();
        auto cmd = static_cast<CustomCommand*>(command);
        cmd->execute();
    }
    else if(RenderCommand::Type::BATCH_COMMAND == commandType)
    {
        flush();
        auto cmd = static_cast<BatchCommand*>(command);
        cmd->execute();
    }
    else if(RenderCommand::Type::PRIMITIVE_COMMAND == commandType)
    {
        flush();
        auto cmd = static_cast<PrimitiveCommand*>(command);
        cmd->execute();
    }
    else
    {
        CCLOGERROR("Unknown commands in renderQueue");
    }
}

void Renderer::visitRenderQueue(RenderQueue& queue)
{
    queue.saveRenderState();
    
    //
    //Process Global-Z < 0 Objects
    //
    const auto& zNegQueue = queue.getSubQueue(RenderQueue::QUEUE_GROUP::GLOBALZ_NEG);
    if (zNegQueue.size() > 0)
    {
        if(_isDepthTestFor2D)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthMask(true);
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
            glDepthMask(false);
        }
        for (auto it = zNegQueue.cbegin(); it != zNegQueue.cend(); ++it)
        {
            processRenderCommand(*it);
        }
        flush();
    }
    
    //
    //Process Opaque Object
    //
    const auto& opaqueQueue = queue.getSubQueue(RenderQueue::QUEUE_GROUP::OPAQUE_3D);
    if (opaqueQueue.size() > 0)
    {
        //Clear depth to achieve layered rendering
        glDepthMask(true);
        glEnable(GL_DEPTH_TEST);
        
        for (auto it = opaqueQueue.cbegin(); it != opaqueQueue.cend(); ++it)
        {
            processRenderCommand(*it);
        }
        flush();
    }
    
    //
    //Process 3D Transparent object
    //
    const auto& transQueue = queue.getSubQueue(RenderQueue::QUEUE_GROUP::TRANSPARENT_3D);
    if (transQueue.size() > 0)
    {
        glEnable(GL_DEPTH_TEST);
        glDepthMask(false);
        
        for (auto it = transQueue.cbegin(); it != transQueue.cend(); ++it)
        {
            processRenderCommand(*it);
        }
        flush();
    }
    
    //
    //Process Global-Z = 0 Queue
    //
    const auto& zZeroQueue = queue.getSubQueue(RenderQueue::QUEUE_GROUP::GLOBALZ_ZERO);
    if (zZeroQueue.size() > 0)
    {
        if(_isDepthTestFor2D)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthMask(true);
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
            glDepthMask(false);
        }
        for (auto it = zZeroQueue.cbegin(); it != zZeroQueue.cend(); ++it)
        {
            processRenderCommand(*it);
        }
        flush();
    }
    
    //
    //Process Global-Z > 0 Queue
    //
    const auto& zPosQueue = queue.getSubQueue(RenderQueue::QUEUE_GROUP::GLOBALZ_POS);
    if (zPosQueue.size() > 0)
    {
        for (auto it = zPosQueue.cbegin(); it != zPosQueue.cend(); ++it)
        {
            processRenderCommand(*it);
        }
        flush();
    }
    
    queue.restoreRenderState();
=======
            CCLOGERROR("Unknown commands in renderQueue");
        }
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Renderer::render()
{
    //Uncomment this once everything is rendered by new renderer
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

<<<<<<< HEAD
    //TODO: setup camera or MVP
=======
    //TODO setup camera or MVP
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _isRendering = true;
    
    if (_glViewAssigned)
    {
<<<<<<< HEAD
=======
        // cleanup
        _drawnBatches = _drawnVertices = 0;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        //Process render commands
        //1. Sort render commands based on ID
        for (auto &renderqueue : _renderGroups)
        {
            renderqueue.sort();
        }
        visitRenderQueue(_renderGroups[0]);
<<<<<<< HEAD
=======
        flush();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
    clean();
    _isRendering = false;
}

void Renderer::clean()
{
    // Clear render group
    for (size_t j = 0 ; j < _renderGroups.size(); j++)
    {
        //commands are owned by nodes
        // for (const auto &cmd : _renderGroups[j])
        // {
        //     cmd->releaseToCommandPool();
        // }
        _renderGroups[j].clear();
    }

<<<<<<< HEAD
    // Clear batch commands
    _batchedCommands.clear();
    _batchQuadCommands.clear();
    _filledVertex = 0;
    _filledIndex = 0;
    _numberQuads = 0;
=======
    // Clear batch quad commands
    _batchedQuadCommands.clear();
    _numQuads = 0;

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    _lastMaterialID = 0;
    _lastBatchedMeshCommand = nullptr;
}

<<<<<<< HEAD
void Renderer::clear()
{
    //Enable Depth mask to make sure glClear clear the depth buffer correctly
    glDepthMask(true);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDepthMask(false);
}

void Renderer::setDepthTest(bool enable)
{
    if (enable)
    {
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
//        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }
    
    _isDepthTestFor2D = enable;
    CHECK_GL_ERROR_DEBUG();
}

void Renderer::fillVerticesAndIndices(const TrianglesCommand* cmd)
{
    memcpy(_verts + _filledVertex, cmd->getVertices(), sizeof(V3F_C4B_T2F) * cmd->getVertexCount());
    const Mat4& modelView = cmd->getModelView();
    
    for(ssize_t i=0; i< cmd->getVertexCount(); ++i)
    {
        V3F_C4B_T2F *q = &_verts[i + _filledVertex];
        Vec3 *vec1 = (Vec3*)&q->vertices;
        modelView.transformPoint(vec1);
    }
    
    const unsigned short* indices = cmd->getIndices();
    //fill index
    for(ssize_t i=0; i< cmd->getIndexCount(); ++i)
    {
        _indices[_filledIndex + i] = _filledVertex + indices[i];
    }
    
    _filledVertex += cmd->getVertexCount();
    _filledIndex += cmd->getIndexCount();
}

void Renderer::fillQuads(const QuadCommand *cmd)
{
    const Mat4& modelView = cmd->getModelView();
    const V3F_C4B_T2F* quads =  (V3F_C4B_T2F*)cmd->getQuads();
    for(ssize_t i=0; i< cmd->getQuadCount() * 4; ++i)
    {
        _quadVerts[i + _numberQuads * 4] = quads[i];
        modelView.transformPoint(quads[i].vertices,&(_quadVerts[i + _numberQuads * 4].vertices));
    }
    
    _numberQuads += cmd->getQuadCount();
}

void Renderer::drawBatchedTriangles()
{
    //TODO: we can improve the draw performance by insert material switching command before hand.

    int indexToDraw = 0;
    int startIndex = 0;

    //Upload buffer to VBO
    if(_filledVertex <= 0 || _filledIndex <= 0 || _batchedCommands.empty())
=======
void Renderer::convertToWorldCoordinates(V3F_C4B_T2F_Quad* quads, ssize_t quantity, const Mat4& modelView)
{
//    kmMat4 matrixP, mvp;
//    kmGLGetMatrix(KM_GL_PROJECTION, &matrixP);
//    kmMat4Multiply(&mvp, &matrixP, &modelView);
    for(ssize_t i=0; i<quantity; ++i)
    {
        V3F_C4B_T2F_Quad *q = &quads[i];
        Vec3 *vec1 = (Vec3*)&q->bl.vertices;
        modelView.transformPoint(vec1);

        Vec3 *vec2 = (Vec3*)&q->br.vertices;
        modelView.transformPoint(vec2);

        Vec3 *vec3 = (Vec3*)&q->tr.vertices;
        modelView.transformPoint(vec3);

        Vec3 *vec4 = (Vec3*)&q->tl.vertices;
        modelView.transformPoint(vec4);
    }
}

void Renderer::drawBatchedQuads()
{
    //TODO we can improve the draw performance by insert material switching command before hand.

    int quadsToDraw = 0;
    int startQuad = 0;

    //Upload buffer to VBO
    if(_numQuads <= 0 || _batchedQuadCommands.empty())
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        return;
    }

    if (Configuration::getInstance()->supportsShareableVAO())
    {
<<<<<<< HEAD
        //Bind VAO
        GL::bindVAO(_buffersVAO);
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        //Set VBO data
        glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);

        // option 1: subdata
//        glBufferSubData(GL_ARRAY_BUFFER, sizeof(_quads[0])*start, sizeof(_quads[0]) * n , &_quads[start] );

        // option 2: data
//        glBufferData(GL_ARRAY_BUFFER, sizeof(quads_[0]) * (n-start), &quads_[start], GL_DYNAMIC_DRAW);

        // option 3: orphaning + glMapBuffer
<<<<<<< HEAD
        glBufferData(GL_ARRAY_BUFFER, sizeof(_verts[0]) * _filledVertex, nullptr, GL_DYNAMIC_DRAW);
        void *buf = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        memcpy(buf, _verts, sizeof(_verts[0])* _filledVertex);
        glUnmapBuffer(GL_ARRAY_BUFFER);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * _filledIndex, _indices, GL_STATIC_DRAW);
    }
    else
    {
#define kQuadSize sizeof(_verts[0])
        glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);

        glBufferData(GL_ARRAY_BUFFER, sizeof(_verts[0]) * _filledVertex , _verts, GL_DYNAMIC_DRAW);
=======
        glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * (_numQuads), nullptr, GL_DYNAMIC_DRAW);
        void *buf = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        memcpy(buf, _quads, sizeof(_quads[0])* (_numQuads));
        glUnmapBuffer(GL_ARRAY_BUFFER);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        //Bind VAO
        GL::bindVAO(_quadVAO);
    }
    else
    {
#define kQuadSize sizeof(_quads[0].bl)
        glBindBuffer(GL_ARRAY_BUFFER, _buffersVBO[0]);

        glBufferData(GL_ARRAY_BUFFER, sizeof(_quads[0]) * _numQuads , _quads, GL_DYNAMIC_DRAW);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);

        // vertices
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, vertices));

        // colors
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, colors));

        // tex coords
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, texCoords));

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffersVBO[1]);
<<<<<<< HEAD
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices[0]) * _filledIndex, _indices, GL_STATIC_DRAW);
    }

    //Start drawing verties in batch
    for(const auto& cmd : _batchedCommands)
    {
        auto newMaterialID = cmd->getMaterialID();
        if(_lastMaterialID != newMaterialID || newMaterialID == MATERIAL_ID_DO_NOT_BATCH)
        {
            //Draw quads
            if(indexToDraw > 0)
            {
                glDrawElements(GL_TRIANGLES, (GLsizei) indexToDraw, GL_UNSIGNED_SHORT, (GLvoid*) (startIndex*sizeof(_indices[0])) );
                _drawnBatches++;
                _drawnVertices += indexToDraw;

                startIndex += indexToDraw;
                indexToDraw = 0;
=======
    }

    //Start drawing verties in batch
    for(const auto& cmd : _batchedQuadCommands)
    {
        auto newMaterialID = cmd->getMaterialID();
        if(_lastMaterialID != newMaterialID || newMaterialID == QuadCommand::MATERIAL_ID_DO_NOT_BATCH)
        {
            //Draw quads
            if(quadsToDraw > 0)
            {
                glDrawElements(GL_TRIANGLES, (GLsizei) quadsToDraw*6, GL_UNSIGNED_SHORT, (GLvoid*) (startQuad*6*sizeof(_indices[0])) );
                _drawnBatches++;
                _drawnVertices += quadsToDraw*6;

                startQuad += quadsToDraw;
                quadsToDraw = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
            }

            //Use new material
            cmd->useMaterial();
            _lastMaterialID = newMaterialID;
        }

<<<<<<< HEAD
        indexToDraw += cmd->getIndexCount();
    }

    //Draw any remaining triangles
    if(indexToDraw > 0)
    {
        glDrawElements(GL_TRIANGLES, (GLsizei) indexToDraw, GL_UNSIGNED_SHORT, (GLvoid*) (startIndex*sizeof(_indices[0])) );
        _drawnBatches++;
        _drawnVertices += indexToDraw;
=======
        quadsToDraw += cmd->getQuadCount();
    }

    //Draw any remaining quad
    if(quadsToDraw > 0)
    {
        glDrawElements(GL_TRIANGLES, (GLsizei) quadsToDraw*6, GL_UNSIGNED_SHORT, (GLvoid*) (startQuad*6*sizeof(_indices[0])) );
        _drawnBatches++;
        _drawnVertices += quadsToDraw*6;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }

    if (Configuration::getInstance()->supportsShareableVAO())
    {
        //Unbind VAO
        GL::bindVAO(0);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

<<<<<<< HEAD
    _batchedCommands.clear();
    _filledVertex = 0;
    _filledIndex = 0;
}

void Renderer::drawBatchedQuads()
{
    //TODO: we can improve the draw performance by insert material switching command before hand.
    
    int indexToDraw = 0;
    int startIndex = 0;
    
    //Upload buffer to VBO
    if(_numberQuads <= 0 || _batchQuadCommands.empty())
    {
        return;
    }
    
    if (Configuration::getInstance()->supportsShareableVAO())
    {
        //Bind VAO
        GL::bindVAO(_quadVAO);
        //Set VBO data
        glBindBuffer(GL_ARRAY_BUFFER, _quadbuffersVBO[0]);
        
        // option 1: subdata
        //        glBufferSubData(GL_ARRAY_BUFFER, sizeof(_quads[0])*start, sizeof(_quads[0]) * n , &_quads[start] );
        
        // option 2: data
        //        glBufferData(GL_ARRAY_BUFFER, sizeof(quads_[0]) * (n-start), &quads_[start], GL_DYNAMIC_DRAW);
        
        // option 3: orphaning + glMapBuffer
        glBufferData(GL_ARRAY_BUFFER, sizeof(_quadVerts[0]) * _numberQuads * 4, nullptr, GL_DYNAMIC_DRAW);
        void *buf = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        memcpy(buf, _quadVerts, sizeof(_quadVerts[0])* _numberQuads * 4);
        glUnmapBuffer(GL_ARRAY_BUFFER);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _quadbuffersVBO[1]);
    }
    else
    {
#define kQuadSize sizeof(_verts[0])
        glBindBuffer(GL_ARRAY_BUFFER, _quadbuffersVBO[0]);
        
        glBufferData(GL_ARRAY_BUFFER, sizeof(_quadVerts[0]) * _numberQuads * 4 , _quadVerts, GL_DYNAMIC_DRAW);
        
        GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POS_COLOR_TEX);
        
        // vertices
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, vertices));
        
        // colors
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, colors));
        
        // tex coords
        glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_TEX_COORD, 2, GL_FLOAT, GL_FALSE, kQuadSize, (GLvoid*) offsetof(V3F_C4B_T2F, texCoords));
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _quadbuffersVBO[1]);
    }
    
    //Start drawing verties in batch
    for(const auto& cmd : _batchQuadCommands)
    {
        auto newMaterialID = cmd->getMaterialID();
        if(_lastMaterialID != newMaterialID || newMaterialID == MATERIAL_ID_DO_NOT_BATCH)
        {
            //Draw quads
            if(indexToDraw > 0)
            {
                glDrawElements(GL_TRIANGLES, (GLsizei) indexToDraw, GL_UNSIGNED_SHORT, (GLvoid*) (startIndex*sizeof(_indices[0])) );
                _drawnBatches++;
                _drawnVertices += indexToDraw;
                
                startIndex += indexToDraw;
                indexToDraw = 0;
            }
            
            //Use new material
            cmd->useMaterial();
            _lastMaterialID = newMaterialID;
        }
        
        indexToDraw += cmd->getQuadCount() * 6;
    }
    
    //Draw any remaining quad
    if(indexToDraw > 0)
    {
        glDrawElements(GL_TRIANGLES, (GLsizei) indexToDraw, GL_UNSIGNED_SHORT, (GLvoid*) (startIndex*sizeof(_indices[0])) );
        _drawnBatches++;
        _drawnVertices += indexToDraw;
    }
    
    if (Configuration::getInstance()->supportsShareableVAO())
    {
        //Unbind VAO
        GL::bindVAO(0);
    }
    else
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    
    _batchQuadCommands.clear();
    _numberQuads = 0;
=======
    _batchedQuadCommands.clear();
    _numQuads = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Renderer::flush()
{
    flush2D();
    flush3D();
}

void Renderer::flush2D()
{
<<<<<<< HEAD
    flushQuads();
    flushTriangles();
=======
    drawBatchedQuads();
    _lastMaterialID = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void Renderer::flush3D()
{
    if (_lastBatchedMeshCommand)
    {
        _lastBatchedMeshCommand->postBatchDraw();
        _lastBatchedMeshCommand = nullptr;
    }
}

<<<<<<< HEAD
void Renderer::flushQuads()
{
    if(_numberQuads > 0)
    {
        drawBatchedQuads();
        _lastMaterialID = 0;
    }
}

void Renderer::flushTriangles()
{
    if(_filledIndex > 0)
    {
        drawBatchedTriangles();
        _lastMaterialID = 0;
    }
}

// helpers
bool Renderer::checkVisibility(const Mat4 &transform, const Size &size)
{
    auto scene = Director::getInstance()->getRunningScene();
    // only cull the default camera. The culling algorithm is valid for default camera.
    if (scene && scene->_defaultCamera != Camera::getVisitingCamera())
        return true;
    
=======
// helpers

bool Renderer::checkVisibility(const Mat4 &transform, const Size &size)
{
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    // half size of the screen
    Size screen_half = Director::getInstance()->getWinSize();
    screen_half.width /= 2;
    screen_half.height /= 2;

    float hSizeX = size.width/2;
    float hSizeY = size.height/2;

    Vec4 v4world, v4local;
    v4local.set(hSizeX, hSizeY, 0, 1);
    transform.transformVector(v4local, &v4world);

    // center of screen is (0,0)
    v4world.x -= screen_half.width;
    v4world.y -= screen_half.height;

    // convert content size to world coordinates
    float wshw = std::max(fabsf(hSizeX * transform.m[0] + hSizeY * transform.m[4]), fabsf(hSizeX * transform.m[0] - hSizeY * transform.m[4]));
    float wshh = std::max(fabsf(hSizeX * transform.m[1] + hSizeY * transform.m[5]), fabsf(hSizeX * transform.m[1] - hSizeY * transform.m[5]));

    // compare if it in the positive quadrant of the screen
    float tmpx = (fabsf(v4world.x)-wshw);
    float tmpy = (fabsf(v4world.y)-wshh);
    bool ret = (tmpx < screen_half.width && tmpy < screen_half.height);

    return ret;
}

<<<<<<< HEAD

void Renderer::setClearColor(const Color4F &clearColor)
{
    _clearColor = clearColor;
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END
