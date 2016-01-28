LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := cocos_localstorage_static

LOCAL_MODULE_FILENAME := liblocalstorage

LOCAL_SRC_FILES := LocalStorage.cpp \
<<<<<<< HEAD
LocalStorage-android.cpp 
=======
LocalStorageAndroid.cpp 
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../..

LOCAL_CFLAGS += -Wno-psabi
LOCAL_EXPORT_CFLAGS += -Wno-psabi

<<<<<<< HEAD
LOCAL_STATIC_LIBRARIES := cocos2dx_internal_static
=======
LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

include $(BUILD_STATIC_LIBRARY)

$(call import-module,.)
