LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_network_static

LOCAL_MODULE_FILENAME := libnetwork

<<<<<<< HEAD
LOCAL_SRC_FILES := HttpClient-android.cpp \
SocketIO.cpp \
WebSocket.cpp

LOCAL_EXPORT_C_INCLUDES :=

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../external/curl/include/android \
                    $(LOCAL_PATH)/../../external/websockets/include/android

LOCAL_STATIC_LIBRARIES := cocos2dx_internal_static
LOCAL_STATIC_LIBRARIES += cocos_curl_static
LOCAL_STATIC_LIBRARIES += libwebsockets_static

include $(BUILD_STATIC_LIBRARY)
=======
LOCAL_SRC_FILES := HttpClient.cpp \
SocketIO.cpp \
WebSocket.cpp


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../.. \
$(LOCAL_PATH)/..


LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_curl_static
LOCAL_WHOLE_STATIC_LIBRARIES += libwebsockets_static

include $(BUILD_STATIC_LIBRARY)

$(call import-module,.)
$(call import-module,curl/prebuilt/android)
$(call import-module,websockets/prebuilt/android)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
