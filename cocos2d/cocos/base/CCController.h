/****************************************************************************
<<<<<<< HEAD
 Copyright (c) 2014-2015 Chukong Technologies Inc.
=======
 Copyright (c) 2014 cocos2d-x.org
 Copyright (c) 2014 Chukong Technologies Inc.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 
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

#ifndef __cocos2d_libs__CCController__
#define __cocos2d_libs__CCController__

<<<<<<< HEAD
#include "platform/CCPlatformMacros.h"
=======
#include "CCPlatformMacros.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include <string>
#include <vector>
#include <unordered_map>

NS_CC_BEGIN

class ControllerImpl;
class EventListenerController;
class EventController;
class EventDispatcher;

<<<<<<< HEAD
/**
 * @addtogroup base
 * @{
 */

/**
 * @class Controller
 * @brief A Controller object represents a connected physical game controller.
 * @js NA
 */
class Controller
{
public:
    /** 
     * Controllers' standard  key
=======
class Controller
{
public:
    /** Controllers' standard  key
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * Controller receives only standard key which contained within enum Key by default.
     */
    enum Key
    {
        JOYSTICK_LEFT_X = 1000,
        JOYSTICK_LEFT_Y,
        JOYSTICK_RIGHT_X,
        JOYSTICK_RIGHT_Y,

        BUTTON_A,
        BUTTON_B,
        BUTTON_C,
        BUTTON_X,
        BUTTON_Y,
        BUTTON_Z,
       
        BUTTON_DPAD_UP,
        BUTTON_DPAD_DOWN,
        BUTTON_DPAD_LEFT,
        BUTTON_DPAD_RIGHT,
        BUTTON_DPAD_CENTER,

        BUTTON_LEFT_SHOULDER,
        BUTTON_RIGHT_SHOULDER,

        AXIS_LEFT_TRIGGER,
        AXIS_RIGHT_TRIGGER,

        BUTTON_LEFT_THUMBSTICK,
        BUTTON_RIGHT_THUMBSTICK,

        BUTTON_START,
        BUTTON_SELECT,

        BUTTON_PAUSE,
        KEY_MAX
    };

<<<<<<< HEAD
    /**
     * @struct KeyStatus
     * 
     */
    typedef struct _keyStatus
    {
        /** A Boolean value that indicates whether the key is considered pressed. */
        bool isPressed;
        /** The value of key.This value is used in conjunction with the isPressed parameter. */
        float value;
        /** A Boolean value that indicates whether the value of key is analog.
         * If isAnalog is true, the key value might be a float from -1 to 1. 
         * If isAnalog is false, the key value would be contain one number: 0 or 1.
         */
=======
    typedef struct _keyStatus
    {
        bool isPressed;
        float value;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        bool isAnalog;
    }KeyStatus;
    
    static const int TAG_UNSET = -1;

<<<<<<< HEAD
    /**
     * Gets all Controller objects.
     */
    static const std::vector<Controller*>& getAllController(){ return s_allController;}

    /** 
     * Gets a Controller object with tag.
     *
     * @param tag   An identifier to find the controller.
     * @return A Controller object.
     */
    static Controller* getControllerByTag(int tag);

    /**
     * Start discovering new controllers.
     *
     * @warning The API only work on the IOS platform. Empty implementation on other platform.
     */
    static void startDiscoveryController();

    /** 
     * Stop the discovery process.
     *
     * @warning The API only work on the IOS platform.Empty implementation on other platform.
     */
    static void stopDiscoveryController();

    /**
     * Gets the name of this Controller object.
     */
    const std::string& getDeviceName() const { return _deviceName;}

    /**
     * Gets the Controller id.
     */
    int getDeviceId() const { return _deviceId;}

    /**
     * Indicates whether the Controller is connected.
     */
    bool isConnected() const;

    /**
     * 
     */
    const KeyStatus& getKeyStatus(int keyCode);
    
    /** 
     * Activate receives key event from external key. e.g. back,menu.
     * Controller receives only standard key which contained within enum Key by default.
     *
     * @warning The API only work on the android platform for support diversified game controller.
     *
     * @param externalKeyCode   External key code.
     * @param receive   True if external key event on this controller should be receive, false otherwise.
     */
    void receiveExternalKeyEvent(int externalKeyCode,bool receive);

    /** 
     * Changes the tag that is used to identify the controller easily.
     * @param tag   A integer that identifies the controller.
     */
    void setTag(int tag) { _controllerTag = tag;}

=======
    static const std::vector<Controller*>& getAllController(){ return s_allController;}
    /** Gets a controller with its tag
     * @param tag   An identifier to find the controller.
     */
    static Controller* getControllerByTag(int tag);
    /** To start discovering new controllers
     * @warning The API only work on the IOS platform.Empty implementation on Android
     */
    static void startDiscoveryController();
    /** End the discovery process
     * @warning The API only work on the IOS platform.Empty implementation on Android
     */
    static void stopDiscoveryController();

    const std::string& getDeviceName() const { return _deviceName;}
    int getDeviceId() const { return _deviceId;}

    bool isConnected() const;

    const KeyStatus& getKeyStatus(int keyCode);
    
    /** Activate receives key event from external key. e.g. back,menu.
     * Controller receives only standard key which contained within enum Key by default.
     * @warning The API only work on the android platform for support diversified game controller.
     *
     * @param externalKeyCode  external key code
     * @param receive  true if external key event on this controller should be receive, false otherwise.
     */
    void receiveExternalKeyEvent(int externalKeyCode,bool receive);

    /** Changes the tag that is used to identify the controller easily.
     * @param tag   A integer that identifies the controller.
     */
    void setTag(int tag) { _controllerTag = tag;}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /**
     * Returns a tag that is used to identify the controller easily.
     *
     * @return An integer that identifies the controller.
     */
    int getTag() const { return _controllerTag;}

private:
    static std::vector<Controller*> s_allController;

    Controller();
    virtual ~Controller();

    void init();

    void onConnected();
    void onDisconnected();
    void onButtonEvent(int keyCode, bool isPressed, float value, bool isAnalog);
    void onAxisEvent(int axisCode, float value, bool isAnalog);
    void registerListeners();

    std::unordered_map<int, KeyStatus> _allKeyStatus;
    std::unordered_map<int, KeyStatus> _allKeyPrevStatus;

    std::string _deviceName;
    int _deviceId;

    int _controllerTag;

    ControllerImpl* _impl;

    EventDispatcher* _eventDispatcher;
    EventController *_connectEvent;
    EventController *_keyEvent;
    EventController *_axisEvent;

    friend class ControllerImpl;
    friend class EventListenerController;
};

<<<<<<< HEAD
// end group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

NS_CC_END

#endif /* defined(__cocos2d_libs__CCController__) */
