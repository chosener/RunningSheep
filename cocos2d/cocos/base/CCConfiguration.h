/****************************************************************************
Copyright (c) 2010      Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
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

#ifndef __CCCONFIGURATION_H__
#define __CCCONFIGURATION_H__

<<<<<<< HEAD
#include <string>

#include "base/CCRef.h"
#include "base/CCValue.h"
#include "platform/CCGL.h"
#include "3d/CCAnimate3D.h"

/**
 * @addtogroup base
 * @{
 */
NS_CC_BEGIN

/** @class Configuration
 * @brief Configuration contains some openGL variables
 * @since v0.99.0
 * @js NA
=======
#include "base/CCRef.h"
#include "CCGL.h"
#include "base/CCValue.h"
#include <string>

NS_CC_BEGIN

/**
 * @addtogroup global
 * @{
 */
/**
 @brief Configuration contains some openGL variables
 @since v0.99.0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */
class CC_DLL Configuration : public Ref
{
public:
    
<<<<<<< HEAD
    /** Returns a shared instance of Configuration.
     * 
     * @return An autoreleased Configuration object.
     */
    static Configuration *getInstance();

    /** Purge the shared instance of Configuration.
     */
=======
    /** returns a shared instance of Configuration */
    static Configuration *getInstance();

    /** purge the shared instance of Configuration */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static void destroyInstance();

    /** @deprecated Use getInstance() instead */
    CC_DEPRECATED_ATTRIBUTE static Configuration *sharedConfiguration();

    /** @deprecated Use destroyInstance() instead */
    CC_DEPRECATED_ATTRIBUTE static void purgeConfiguration();

public:
<<<<<<< HEAD
    /** Destructor
=======
    /**
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
	virtual ~Configuration();

<<<<<<< HEAD
    /** OpenGL Max texture size.
     * 
     * @return The OpenGL Max texture size.
     */
	int getMaxTextureSize() const;

    /** OpenGL Max Modelview Stack Depth.
     *
     * @return The OpenGL Max Modelview Stack Depth.
     */
	int getMaxModelviewStackDepth() const;

    /** Returns the maximum texture units.
     *
     * @return The maximum texture units.
     * @since v2.0.0
=======
    /** OpenGL Max texture size. */
	int getMaxTextureSize() const;

    /** OpenGL Max Modelview Stack Depth. */
	int getMaxModelviewStackDepth() const;

    /** returns the maximum texture units
     @since v2.0.0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
	int getMaxTextureUnits() const;

    /** Whether or not the GPU supports NPOT (Non Power Of Two) textures.
     OpenGL ES 2.0 already supports NPOT (iOS).
<<<<<<< HEAD
     * 
     * @return Is true if supports NPOT.
     * @since v0.99.2
     */
	bool supportsNPOT() const;

    /** Whether or not PVR Texture Compressed is supported.
     *
     * @return Is true if supports PVR Texture Compressed.
     */
	bool supportsPVRTC() const;
    
    /** Whether or not ETC Texture Compressed is supported.
     * 
     *
     * @return Is true if supports ETC Texture Compressed.
     */
    bool supportsETC() const;
    
    /** Whether or not S3TC Texture Compressed is supported.
     *
     * @return Is true if supports S3TC Texture Compressed.
     */
    bool supportsS3TC() const;
    
    /** Whether or not ATITC Texture Compressed is supported.
     *
     * @return Is true if supports ATITC Texture Compressed.
     */
    bool supportsATITC() const;
    
    /** Whether or not BGRA8888 textures are supported.
     *
     * @return Is true if supports BGRA8888 textures.
     * @since v0.99.2
     */
	bool supportsBGRA8888() const;

    /** Whether or not glDiscardFramebufferEXT is supported.
     * @return Is true if supports glDiscardFramebufferEXT.
     * @since v0.99.2
=======
     
     @since v0.99.2
     */
	bool supportsNPOT() const;

    /** Whether or not PVR Texture Compressed is supported */
	bool supportsPVRTC() const;
    
     /** Whether or not ETC Texture Compressed is supported */
    bool supportsETC() const;
    
    /** Whether or  not S3TC Texture Compressed is supported */
    bool supportsS3TC() const;
    
    /** Whether or  not ATITC Texture Compressed is supported */
    bool supportsATITC() const;
    
    /** Whether or not BGRA8888 textures are supported.
     @since v0.99.2
     */
	bool supportsBGRA8888() const;

    /** Whether or not glDiscardFramebufferEXT is supported
     @since v0.99.2
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
	bool supportsDiscardFramebuffer() const;

    /** Whether or not shareable VAOs are supported.
<<<<<<< HEAD
     *
     * @return Is true if supports shareable VAOs.
     * @since v2.0.0
     */
	bool supportsShareableVAO() const;
    
    /** Max support directional light in shader, for Sprite3D.
     *
     * @return Maximum supports directional light in shader.
     * @since v3.3
     */
    int getMaxSupportDirLightInShader() const;
    
    /** Max support point light in shader, for Sprite3D.
     *
     * @return Maximum supports point light in shader.
     * @since v3.3
     */
    int getMaxSupportPointLightInShader() const;
    
    /** Max support spot light in shader, for Sprite3D.
     *
     * @return Maximum supports spot light in shader.
     * @since v3.3
     */
    int getMaxSupportSpotLightInShader() const;

    /** get 3d animate quality*/
    Animate3DQuality getAnimate3DQuality() const;
    
    /** Returns whether or not an OpenGL is supported. 
     *
     * @param searchName A given search name.
     * @return Is true if an OpenGL is supported.
     */
    bool checkForGLExtension(const std::string &searchName) const;

    /** Initialize method.
     *
     * @return Is true if initialize success.
     */
    bool init();

	/** Returns the value of a given key as a double.
     *
     * @param key A given key.
     * @param defaultValue if not find the value, return the defaultValue.
     * @return 
     */
	const Value& getValue(const std::string& key, const Value& defaultValue = Value::Null) const;

	/** Sets a new key/value pair  in the configuration dictionary.
     *
     * @param key A given key.
     * @param value A given value.
     */
	void setValue(const std::string& key, const Value& value);

    /** Returns the Configuration info.
     *
     * @return The Configuration info.
     */
    std::string getInfo() const;

	/** Gathers OpenGL / GPU information.
     */
	void gatherGPUInfo();

	/** Loads a config file. If the keys are already present, then they are going to be replaced. Otherwise the new keys are added.
     * 
     * @param filename Config file name.
     */
=======
     @since v2.0.0
     */
	bool supportsShareableVAO() const;

    /** returns whether or not an OpenGL is supported */
    bool checkForGLExtension(const std::string &searchName) const;

    bool init();

	/** returns the value of a given key as a double */
	const Value& getValue(const std::string& key, const Value& defaultValue = Value::Null) const;

	/** sets a new key/value pair  in the configuration dictionary */
	void setValue(const std::string& key, const Value& value);

    /** returns the Configuration info */
    std::string getInfo() const;

	/** gathers OpenGL / GPU information */
	void gatherGPUInfo();

	/** Loads a config file. If the keys are already present, then they are going to be replaced. Otherwise the new keys are added. */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	void loadConfigFile(const std::string& filename);

private:
    Configuration(void);
    static Configuration    *s_sharedConfiguration;
	static std::string		s_configfile;
    
protected:
    GLint           _maxTextureSize;
    GLint           _maxModelviewStackDepth;
    bool            _supportsPVRTC;
    bool            _supportsETC1;
    bool            _supportsS3TC;
    bool            _supportsATITC;
    bool            _supportsNPOT;
    bool            _supportsBGRA8888;
    bool            _supportsDiscardFramebuffer;
    bool            _supportsShareableVAO;
    GLint           _maxSamplesAllowed;
    GLint           _maxTextureUnits;
    char *          _glExtensions;
<<<<<<< HEAD
    int             _maxDirLightInShader; //max support directional light in shader
    int             _maxPointLightInShader; // max support point light in shader
    int             _maxSpotLightInShader; // max support spot light in shader
    Animate3DQuality  _animate3DQuality; // animate 3d quality
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	
	ValueMap        _valueDict;
};

<<<<<<< HEAD

NS_CC_END
// end of base group
/// @}
=======
// end of global group
/// @}

NS_CC_END
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif // __CCCONFIGURATION_H__
