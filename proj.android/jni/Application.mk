<<<<<<< HEAD
APP_STL := gnustl_static
=======
APP_STL := c++_static
NDK_TOOLCHAIN_VERSION=clang
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fsigned-char
APP_LDFLAGS := -latomic


<<<<<<< HEAD
ifeq ($(NDK_DEBUG),1)
=======
APP_DEBUG := $(strip $(NDK_DEBUG))
ifeq ($(APP_DEBUG),1)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
  APP_CPPFLAGS += -DCOCOS2D_DEBUG=1
  APP_OPTIM := debug
else
  APP_CPPFLAGS += -DNDEBUG
  APP_OPTIM := release
<<<<<<< HEAD
endif
=======
endif
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
