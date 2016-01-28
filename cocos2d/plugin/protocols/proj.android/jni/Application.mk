# it is needed for ndk-r5
APP_PLATFORM := android-10
<<<<<<< HEAD
APP_STL := c++_static
APP_CPPFLAGS := -frtti -std=c++11 -fsigned-char
=======
APP_STL := gnustl_static
APP_CPPFLAGS += -frtti
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
APP_MODULES := PluginProtocolStatic
APP_ABI :=armeabi armeabi-v7a
#APP_ABI :=x86
#APP_ABI :=mips mips-r2 mips-r2-sf armeabi
