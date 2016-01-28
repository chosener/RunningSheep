LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := PluginProtocolStatic

LOCAL_MODULE_FILENAME := libPluginProtocolStatic

LOCAL_SRC_FILES :=\
$(addprefix ../../platform/android/, \
	PluginFactory.cpp \
    PluginJniHelper.cpp \
    PluginUtils.cpp \
    PluginProtocol.cpp \
    ProtocolAnalytics.cpp \
    ProtocolIAP.cpp \
    ProtocolAds.cpp \
    ProtocolShare.cpp \
    ProtocolUser.cpp \
    ProtocolSocial.cpp \
<<<<<<< HEAD
    AgentManager.cpp \
    FacebookAgent.cpp \
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
) \
../../PluginManager.cpp \
../../PluginParam.cpp

<<<<<<< HEAD
LOCAL_CFLAGS := -std=c++11 -Wno-psabi
=======
LOCAL_CFLAGS := -Wno-psabi
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
LOCAL_EXPORT_CFLAGS := -Wno-psabi

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../include $(LOCAL_PATH)/../../platform/android
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../include $(LOCAL_PATH)/../../platform/android

LOCAL_LDLIBS := -landroid
LOCAL_LDLIBS += -llog
LOCAL_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_STATIC_LIBRARY)

$(call import-module,android/native_app_glue)
