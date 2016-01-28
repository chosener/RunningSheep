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

#ifndef __CCBUNDLE3D_H__
#define __CCBUNDLE3D_H__

<<<<<<< HEAD
#include "3d/CCBundle3DData.h"
#include "3d/CCBundleReader.h"
#include "json/document.h"

NS_CC_BEGIN

/**
 * @addtogroup _3d
 * @{
 */

=======
#include <map>

#include "3d/CCBundle3DData.h"

#include "base/ccMacros.h"
#include "base/CCRef.h"
#include "base/ccTypes.h"

#include "json/document.h"
#include "CCBundleReader.h"

NS_CC_BEGIN
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
class Animation3D;
class Data;

/**
<<<<<<< HEAD
 * @brief Defines a bundle file that contains a collection of assets. Mesh, Material, MeshSkin, Animation
 * There are two types of bundle files, c3t and c3b.
 * c3t text file
 * c3b binary file
 * @js NA
 * @lua NA
 */
class CC_DLL Bundle3D
{
public:
    /**
     * create a new bundle, destroy it when finish using it
     */
    static Bundle3D* createBundle();
    
    static void destroyBundle(Bundle3D* bundle);
    
	virtual void clear();
=======
 * Defines a bundle file that contains a collection of assets. Mesh, Material, MeshSkin, Animation
 * There are two types of bundle files, c3t and c3b.
 * c3t text file
 * c3b binary file
 */
class Bundle3D
{
public:
    
    static Bundle3D* getInstance();
    
    static void destroyInstance();
    
	void clear();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * load a file. You must load a file first, then call loadMeshData, loadSkinData, and so on
     * @param path File to be loaded
     * @return result of load
     */
<<<<<<< HEAD
    virtual bool load(const std::string& path);
=======
    bool load(const std::string& path);
    
    /**
     * load mesh data from bundle
     * @param id The ID of the mesh, load the first Mesh in the bundle if it is empty
     */
    bool loadMeshData(const std::string& id, MeshData* meshdata);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    /**
     * load skin data from bundle
     * @param id The ID of the skin, load the first Skin in the bundle if it is empty
     */
<<<<<<< HEAD
    virtual bool loadSkinData(const std::string& id, SkinData* skindata);
=======
    bool loadSkinData(const std::string& id, SkinData* skindata);
    
    /**
     * load material data from bundle
     * @param id The ID of the material, load the first Material in the bundle if it is empty
     */
    bool loadMaterialData(const std::string& id, MaterialData* materialdata);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    /**
     * load material data from bundle
     * @param id The ID of the animation, load the first animation in the bundle if it is empty
     */
<<<<<<< HEAD
    virtual bool loadAnimationData(const std::string& id, Animation3DData* animationdata);
    
    //since 3.3, to support reskin
    virtual bool loadMeshDatas(MeshDatas& meshdatas);
    //since 3.3, to support reskin
    virtual bool loadNodes(NodeDatas& nodedatas);
    //since 3.3, to support reskin
    virtual bool loadMaterials(MaterialDatas& materialdatas);
    
    //load .obj file
    static bool loadObj(MeshDatas& meshdatas, MaterialDatas& materialdatas, NodeDatas& nodedatas, const std::string& fullPath, const char* mtl_basepath = nullptr);
    
    //calculate aabb
    static AABB calculateAABB(const std::vector<float>& vertex, int stride, const std::vector<unsigned short>& index);
  
protected:

    bool loadJson(const std::string& path);
    bool loadBinary(const std::string& path);
    bool loadMeshDatasJson(MeshDatas& meshdatas);
    bool loadMeshDataJson_0_1(MeshDatas& meshdatas);
    bool loadMeshDataJson_0_2(MeshDatas& meshdatas);
    bool loadMeshDatasBinary(MeshDatas& meshdatas);
    bool loadMeshDatasBinary_0_1(MeshDatas& meshdatas);
    bool loadMeshDatasBinary_0_2(MeshDatas& meshdatas);
    bool loadMaterialsJson(MaterialDatas& materialdatas);
    bool loadMaterialDataJson_0_1(MaterialDatas& materialdatas);
    bool loadMaterialDataJson_0_2(MaterialDatas& materialdatas);
    bool loadMaterialsBinary(MaterialDatas& materialdatas);
    bool loadMaterialsBinary_0_1(MaterialDatas& materialdatas);
    bool loadMaterialsBinary_0_2(MaterialDatas& materialdatas);
    bool loadMeshDataJson(MeshData* meshdata){return true;}
    bool loadMeshDataJson_0_1(MeshData* meshdata){return true;}
    bool loadMeshDataJson_0_2(MeshData* meshdata){return true;}
    bool loadSkinDataJson(SkinData* skindata);
    bool loadSkinDataBinary(SkinData* skindata);
    bool loadMaterialDataJson(MaterialData* materialdata){return true;}
    bool loadMaterialDataJson_0_1(MaterialData* materialdata){return true;}
    bool loadMaterialDataJson_0_2(MaterialData* materialdata){return true;}
    bool loadAnimationDataJson(const std::string& id,Animation3DData* animationdata);
    bool loadAnimationDataBinary(const std::string& id,Animation3DData* animationdata);

    /**
     * load nodes of json
     */
    bool loadNodesJson(NodeDatas& nodedatas);
    NodeData* parseNodesRecursivelyJson(const rapidjson::Value& jvalue, bool singleSprite);

    /**
     * load nodes of binary
     */
    bool loadNodesBinary(NodeDatas& nodedatas);
    NodeData* parseNodesRecursivelyBinary(bool& skeleton, bool singleSprite);

    /**
     * get define data type
     * @param str The type in string
     */
    GLenum parseGLType(const std::string& str);

     /**
     * get define data type
     * @param str The type in string
     */
    NTextureData::Usage parseGLTextureType(const std::string& str);
=======
    bool loadAnimationData(const std::string& id, Animation3DData* animationdata);

protected:

    bool loadJson(const std::string& path);
    
    bool loadMeshDataJson(MeshData* meshdata);
    
    bool loadSkinDataJson(SkinData* skindata);
    
    bool loadMaterialDataJson(MaterialData* materialdata);
    
    bool loadAnimationDataJson(Animation3DData* animationdata);

    /**
     * load data in binary
     * @param path The c3b file path
     */
    bool loadBinary(const std::string& path);

    /**
     * load mesh data in binary
     * @param meshdata The mesh data pointer
     */
    bool loadMeshDataBinary(MeshData* meshdata);

    /**
     * load skin data in binary
     * @param skindata The skin data pointer
     */
    bool loadSkinDataBinary(SkinData* skindata);

    /**
     * load material data in binary
     * @param materialdata The material pointer 
     */
    bool loadMaterialDataBinary(MaterialData* materialdata);

    /**
     * load animation data in binary
     * @param animationdata The animation data pointer
     */
    bool loadAnimationDataBinary(Animation3DData* animationdata);

protected:
    /**
     * get define data type
     * @param str The type in string
     */
    GLenum parseGLType(const std::string& str);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    /**
     * get vertex attribute type
     * @param str The type in string
     */
    unsigned int parseGLProgramAttribute(const std::string& str);

    /*
     * get model path
     * @param str Full path of model file
     */
    void getModelRelativePath(const std::string& path);

    /*
<<<<<<< HEAD
     * set the read position in buffer to the target type
     * @param The data type
     * @param The data id
     */
    Reference* seekToFirstType(unsigned int type, const std::string& id = "");

CC_CONSTRUCTOR_ACCESS:
    Bundle3D();
    virtual ~Bundle3D();
    
protected:
    std::string _modelPath;
    std::string _path;
    std::string _version;// the c3b or c3t version
=======
    * set the read position in buffer to the target type
    * @param The data type
    */
    Reference* seekToFirstType(unsigned int type);

protected:
CC_CONSTRUCTOR_ACCESS:
    Bundle3D();
    ~Bundle3D();
    
protected:
    
    static Bundle3D* _instance;
    
    std::string _modelRelativePath;
    std::string         _path;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    // for json reading
    char* _jsonBuffer;
    rapidjson::Document _jsonReader;

    // for binary reading
    Data* _binaryBuffer;
    BundleReader _binaryReader;
    unsigned int _referenceCount;
    Reference* _references;
<<<<<<< HEAD
    bool  _isBinary;
};

// end of 3d group
/// @}

NS_CC_END

#endif // __CCBUNDLE3D_H__
=======

    bool  _isBinary;
};

NS_CC_END

#endif // __CCANIMATE3D_H__
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
