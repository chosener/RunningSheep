/****************************************************************************
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
#ifndef __SUPPORT_CCUSERDEFAULT_H__
#define __SUPPORT_CCUSERDEFAULT_H__

<<<<<<< HEAD
#include "platform/CCPlatformMacros.h"
#include <string>
#include "base/CCData.h"

/**
 * @addtogroup base
 * @{
 */
NS_CC_BEGIN

=======
#include "base/CCPlatformMacros.h"
#include <string>
#include "base/CCData.h"

NS_CC_BEGIN

/**
 * @addtogroup data_storage
 * @{
 */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

/**
 * UserDefault acts as a tiny database. You can save and get base type values by it.
 * For example, setBoolForKey("played", true) will add a bool value true into the database.
 * Its key is "played". You can get the value of the key by getBoolForKey("played").
 * 
 * It supports the following base types:
 * bool, int, float, double, string
 */
class CC_DLL UserDefault
{
public:
    // get value methods

    /**
<<<<<<< HEAD
     * Get bool value by key, if the key doesn't exist, will return false.
     * You can set the default value, or it is false.
     * @param key The key to get value.
     * @return Bool value by `key`.
     * @js NA
     */
    bool    getBoolForKey(const char* key);
    
    /**
     * Get bool value by key, if the key doesn't exist, will return passed default value.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @js NA
     */
    virtual bool getBoolForKey(const char* key, bool defaultValue);
    
    /**
     * Get integer value by key, if the key doesn't exist, will return 0.
     * You can set the default value, or it is 0.
     * @param key The key to get value.
     * @return Integer value of the key.
     * @js NA
     */
    int     getIntegerForKey(const char* key);
    
    /**
     * Get bool value by key, if the key doesn't exist, will return passed default value.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @return Integer value of the key.
     * @js NA
     */
    virtual int getIntegerForKey(const char* key, int defaultValue);
    
    /**
     * Get float value by key, if the key doesn't exist, will return 0.0.
     * @param key The key to get value.
     * @return Float value of the key.
     * @js NA
     */
    float    getFloatForKey(const char* key);
    
    /**
     * Get float value by key, if the key doesn't exist, will return passed default value.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @return Float value of the key.
     * @js NA
     */
    virtual float getFloatForKey(const char* key, float defaultValue);
    
    /**
     * Get double value by key, if the key doesn't exist, will return 0.0.
     * @param key The key to get value.
     * @return Double value of the key.
     * @js NA
     */
    double  getDoubleForKey(const char* key);
    
    /**
     * Get double value by key, if the key doesn't exist, will return passed default value.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @return Double value of the key.
     * @js NA
     */
    virtual double getDoubleForKey(const char* key, double defaultValue);
    
    /**
     * Get string value by key, if the key doesn't exist, will return an empty string.
     * @param key The key to get value.
     * @return String value of the key.
     * @js NA
     */
    std::string getStringForKey(const char* key);
    
    /**
     * Get string value by key, if the key doesn't exist, will return passed default value.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @return String value of the key.
     * @js NA
     */
    virtual std::string getStringForKey(const char* key, const std::string & defaultValue);
    
    /**
     * Get Data value by key, if the key doesn't exist, will return an empty Data.
     * @param key The key to get value.
     * @return Data value of the key.
     * @js NA
     */
    Data getDataForKey(const char* key);
    
    /**
     * Get Data value by key, if the key doesn't exist, will return an empty Data.
     * @param key The key to get value.
     * @param defaultValue The default value to return if the key doesn't exist.
     * @return Data value of the key.
     * @js NA
     */
    virtual Data getDataForKey(const char* key, const Data& defaultValue);
=======
    @brief Get bool value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is false.
    * @js NA
    */
    bool    getBoolForKey(const char* pKey);
    /**
     * @js NA
     */
    bool    getBoolForKey(const char* pKey, bool defaultValue);
    /**
    @brief Get integer value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.
    * @js NA
    */
    int     getIntegerForKey(const char* pKey);
    /**
     * @js NA
     */
    int     getIntegerForKey(const char* pKey, int defaultValue);
    /**
    @brief Get float value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0f.
    * @js NA
    */
    float    getFloatForKey(const char* pKey);
    /**
     * @js NA
     */
    float    getFloatForKey(const char* pKey, float defaultValue);
    /**
    @brief Get double value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0.
    * @js NA
    */
    double  getDoubleForKey(const char* pKey);
    /**
     * @js NA
     */
    double  getDoubleForKey(const char* pKey, double defaultValue);
    /**
    @brief Get string value by key, if the key doesn't exist, a default value will return.
    You can set the default value, or it is "".
    * @js NA
    */
    std::string getStringForKey(const char* pKey);
    /**
     * @js NA
     */
    std::string getStringForKey(const char* pKey, const std::string & defaultValue);
    /**
     @brief Get binary data value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is null.
     * @js NA
     * @lua NA
     */
    Data getDataForKey(const char* pKey);
    /**
     * @js NA
     * @lua NA
     */
    Data getDataForKey(const char* pKey, const Data& defaultValue);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    // set value methods

    /**
<<<<<<< HEAD
     * Set bool value by key.
     * @param key The key to set.
     * @param value A bool value to set to the key.
     * @js NA
     */
    virtual void setBoolForKey(const char* key, bool value);
    /**
     * Set integer value by key.
     * @param key The key to set.
     * @param value A integer value to set to the key.
     * @js NA
     */
    virtual void setIntegerForKey(const char* key, int value);
    /**
     * Set float value by key.
     * @param key The key to set.
     * @param value A float value to set to the key.
     * @js NA
     */
    virtual void setFloatForKey(const char* key, float value);
    /**
     * Set double value by key.
     * @param key The key to set.
     * @param value A double value to set to the key.
     * @js NA
     */
    virtual void setDoubleForKey(const char* key, double value);
    /**
     * Set string value by key.
     * @param key The key to set.
     * @param value A string value to set to the key.
     * @js NA
     */
    virtual void setStringForKey(const char* key, const std::string & value);
    /**
     * Set Data value by key.
     * @param key The key to set.
     * @param value A Data value to set to the key.
     * @js NA
     */
    virtual void setDataForKey(const char* key, const Data& value);
    /**
     * You should invoke this function to save values set by setXXXForKey().
     * @js NA
     */
    virtual void flush();

    /** Returns the singleton.
=======
     @brief Set bool value by key.
     * @js NA
     */
    void    setBoolForKey(const char* pKey, bool value);
    /**
     @brief Set integer value by key.
     * @js NA
     */
    void    setIntegerForKey(const char* pKey, int value);
    /**
     @brief Set float value by key.
     * @js NA
     */
    void    setFloatForKey(const char* pKey, float value);
    /**
     @brief Set double value by key.
     * @js NA
     */
    void    setDoubleForKey(const char* pKey, double value);
    /**
     @brief Set string value by key.
     * @js NA
     */
    void    setStringForKey(const char* pKey, const std::string & value);
    /**
     @brief Set binary data value by key.
     * @js NA
     * @lua NA
     */
    void    setDataForKey(const char* pKey, const Data& value);
    /**
     @brief Save content to xml file
     * @js NA
     */
    void    flush();

    /** returns the singleton 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    static UserDefault* getInstance();
    /**
     * @js NA
     */
    static void destroyInstance();

<<<<<<< HEAD
    /**
    * You can inherit from platform dependent implementation of UserDefault, such as UserDefaultAndroid,
    * and use this function to set delegate, then UserDefault will invoke delegate's implementation.
    * For example, your store native data base or other format store.
    *
    * If you don't want to system default implementation after setting delegate, you can just pass nullptr
    * to this function.
    *
    * @warm It will delete previous delegate
    */
    static void setDelegate(UserDefault *delegate);

    /** @deprecated Use getInstace() instead.
=======
    /** deprecated. Use getInstace() instead 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    CC_DEPRECATED_ATTRIBUTE static UserDefault* sharedUserDefault();
<<<<<<< HEAD
    /**@deprecated Use destroyInstance() instead.
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE static void purgeSharedUserDefault();
    /** All supported platforms other iOS & Android use xml file to save values. This function is return the file path of the xml path.
     * @js NA
     */
    static const std::string& getXMLFilePath();
    /** All supported platforms other iOS & Android use xml file to save values. This function checks whether the xml file exists or not.
     * @return True if the xml file exists, flase if not.
=======
    /**
     * @js NA
     */
    CC_DEPRECATED_ATTRIBUTE static void purgeSharedUserDefault();
    /**
     * @js NA
     */
    static const std::string& getXMLFilePath();
    /**
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    static bool isXMLFileExist();

<<<<<<< HEAD
protected:
    UserDefault();
    ~UserDefault();
    
private:
    
=======
private:
    UserDefault();
    ~UserDefault();
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static bool createXMLFile();
    static void initXMLFilePath();
    
    static UserDefault* _userDefault;
    static std::string _filePath;
    static bool _isFilePathInitialized;
};

<<<<<<< HEAD

NS_CC_END
// end of base group
/** @} */
=======
// end of data_storage group
/// @}

NS_CC_END
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif // __SUPPORT_CCUSERDEFAULT_H__
