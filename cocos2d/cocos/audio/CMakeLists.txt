<<<<<<< HEAD

set(COCOS_AUDIO_SRC
    audio/AudioEngine.cpp
    )

if(WINDOWS)
    set(COCOS_AUDIO_PLATFORM_SRC
        audio/win32/SimpleAudioEngine.cpp
        audio/win32/MciPlayer.cpp
        audio/win32/MciPlayer.h
        audio/win32/AudioEngine-win32.cpp
        audio/win32/AudioCache.cpp
        audio/win32/AudioPlayer.cpp
    )

elseif(LINUX)
    set(COCOS_AUDIO_PLATFORM_SRC
        audio/linux/SimpleAudioEngineFMOD.cpp
        audio/linux/FmodAudioPlayer.cpp
        audio/linux/FmodAudioPlayer.h
        audio/linux/AudioPlayer.h
    )

elseif(MACOSX)
    # split it in _C and non C
    # because C files needs to be compiled with C compiler and not C++
    # compiler
    set(COCOS_AUDIO_PLATFORM_SRC_C
        audio/mac/CDAudioManager.m
        audio/mac/CDOpenALSupport.m
        audio/mac/CocosDenshion.m
        audio/mac/SimpleAudioEngine_objc.m
    )
    set(COCOS_AUDIO_PLATFORM_SRC
        ${COCOS_AUDIO_PLATFORM_SRC_C}
        audio/apple/AudioCache.mm
        audio/apple/AudioEngine-inl.mm
        audio/apple/AudioPlayer.mm
        audio/mac/SimpleAudioEngine.mm
        audio/mac/CDXMacOSXSupport.mm
    )
    set_source_files_properties(
        ${COCOS_AUDIO_PLATFORM_SRC_C}
        PROPERTIES LANGUAGE C
    )
endif()

list(APPEND COCOS_AUDIO_SRC ${COCOS_AUDIO_PLATFORM_SRC})
=======
# architecture
if ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
set(ARCH_DIR "64-bit")
else()
set(ARCH_DIR "32-bit")
endif()

if(WIN32)
  set(AUDIO_SRC
    win32/SimpleAudioEngine.cpp
    win32/MciPlayer.cpp
	win32/MciPlayer.h
  )
elseif(APPLE)

else()
  set(AUDIO_SRC
    linux/SimpleAudioEngineFMOD.cpp
    linux/FmodAudioPlayer.cpp
	linux/FmodAudioPlayer.h
	linux/AudioPlayer.h
  )

  include_directories(
    ../../external/linux-specific/fmod/include/${ARCH_DIR}
  )

endif()

add_library(audio STATIC
  ${AUDIO_SRC}
  include/Export.h
  include/SimpleAudioEngine.h
)

if((NOT APPLE) AND (NOT WIN32))

if ( CMAKE_SIZEOF_VOID_P EQUAL 8 )
set(FMOD_LIB "fmodex64")
else()
set(FMOD_LIB "fmodex")
endif()

target_link_libraries(audio
  ${FMOD_LIB}
)

set_target_properties(audio
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

elseif(WIN32)

target_link_libraries(audio
  Winmm
)

endif()
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
