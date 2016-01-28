LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cocos_freetype2_static
LOCAL_MODULE_FILENAME := freetype2
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libfreetype.a
<<<<<<< HEAD
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include/android \
                         $(LOCAL_PATH)/../../include/android/freetype2
=======
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include/android $(LOCAL_PATH)/../../include/android/freetype2
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
include $(PREBUILT_STATIC_LIBRARY)
