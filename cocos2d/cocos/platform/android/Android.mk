LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dxandroid_static

LOCAL_MODULE_FILENAME := libcocos2dandroid

LOCAL_SRC_FILES := \
<<<<<<< HEAD
CCApplication-android.cpp \
CCCommon-android.cpp \
CCDevice-android.cpp \
CCGLViewImpl-android.cpp \
CCFileUtils-android.cpp \
javaactivity-android.cpp \
=======
CCApplication.cpp \
CCCommon.cpp \
CCDevice.cpp \
CCGLView.cpp \
CCFileUtilsAndroid.cpp \
javaactivity.cpp \
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
jni/DPIJni.cpp \
jni/IMEJni.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxAccelerometer.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxBitmap.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxHelper.cpp \
jni/Java_org_cocos2dx_lib_Cocos2dxRenderer.cpp \
jni/JniHelper.cpp \
<<<<<<< HEAD
jni/TouchesJni.cpp \
jni/CocosPlayClient.cpp
=======
jni/TouchesJni.cpp
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_C_INCLUDES := $(LOCAL_PATH) \
                    $(LOCAL_PATH)/.. \
                    $(LOCAL_PATH)/../.. \

<<<<<<< HEAD
=======
LOCAL_LDLIBS := -lGLESv1_CM \
                -lGLESv2 \
                -lEGL \
                -llog \
                -lz \
                -landroid

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
LOCAL_EXPORT_LDLIBS := -lGLESv1_CM \
                       -lGLESv2 \
                       -lEGL \
                       -llog \
<<<<<<< HEAD
                       -landroid

LOCAL_CPPFLAGS := -Wno-extern-c-compat

LOCAL_EXPORT_CPPFLAGS := -Wno-extern-c-compat

include $(BUILD_STATIC_LIBRARY)
=======
                       -lz \
                       -landroid

LOCAL_WHOLE_STATIC_LIBRARIES	:= cocos_png_static cocos_jpeg_static cocos_tiff_static cocos_webp_static


include $(BUILD_STATIC_LIBRARY)

$(call import-module,jpeg/prebuilt/android)
$(call import-module,png/prebuilt/android)
$(call import-module,tiff/prebuilt/android)
$(call import-module,webp/prebuilt/android)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
