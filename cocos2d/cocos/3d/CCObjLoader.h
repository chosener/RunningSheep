//
// Copyright 2012-2013, Syoyo Fujita.
//
// Licensed under 2-clause BSD liecense.
//
// copied from Syoyo Fujita
// https://github.com/syoyo/tinyobjloader

#ifndef __CCOBJLOADER_H__
#define __CCOBJLOADER_H__

#include <string>
#include <vector>
#include <map>
#include "base/ccTypes.h"

NS_CC_BEGIN

<<<<<<< HEAD
/**
 * @addtogroup _3d
 * @{
 */

/**
 * @brief .obj file Loader
 * @js NA
 * @lua NA
 **/
class ObjLoader
{
public:

    /**
     * model's material struct
     **/
=======
class ObjLoader
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    typedef struct
    {
        std::string name;
        
        float ambient[3];
        float diffuse[3];
        float specular[3];
        float transmittance[3];
        float emission[3];
        float shininess;
        float ior;                // index of refraction
        float dissolve;           // 1 == opaque; 0 == fully transparent
        // illumination model (see http://www.fileformat.info/format/material/)
        int illum;
        
        std::string ambient_texname;
        std::string diffuse_texname;
        std::string specular_texname;
        std::string normal_texname;
        std::map<std::string, std::string> unknown_parameter;
    } material_t;
    
<<<<<<< HEAD
    /**
     * model's indices struct
     **/
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    typedef struct
    {
        std::vector<unsigned short>   indices;
    } mesh_t;
    
<<<<<<< HEAD
    /**
     * model's shape struct
     **/
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    typedef struct
    {
        std::string  name;
        material_t   material;
        mesh_t       mesh;
    } shape_t;
    
<<<<<<< HEAD
    /**
     * model's shapes struct
     **/
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    typedef struct
    {
        std::vector<float>          positions;
        std::vector<float>          normals;
        std::vector<float>          texcoords;
        
        std::vector<shape_t>  shapes;
        
        void reset()
        {
            positions.clear();
            normals.clear();
            texcoords.clear();
            shapes.clear();
        }
    }shapes_t;
    
<<<<<<< HEAD
    /**
     * Loads .obj from a file.
     * @param shapes will be filled with parsed shape data
     * @param filename the .obj file path .
     * @param mtl_basepath It's optional, and used for base path for .mtl file
     * @return The function returns error string, return empty string when loading .obj success.
    */
=======
    /// Loads .obj from a file.
    /// 'shapes' will be filled with parsed shape data
    /// The function returns error string.
    /// Returns empty string when loading .obj success.
    /// 'mtl_basepath' is optional, and used for base path for .mtl file.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static std::string LoadObj(
                        shapes_t& shapes,   // [output]
                        const char* filename,
                        const char* mtl_basepath = NULL);

};

<<<<<<< HEAD
// end of 3d group
/// @}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END

#endif  // _TINY_OBJ_LOADER_H
