<<<<<<< HEAD

if(WINDOWS)
  set(PLATFORM_LINK websockets)
elseif(LINUX)
  set(PLATFORM_LINK websockets ssl crypto)
else()
  set(PLATFORM_LINK websockets)
endif()

set(COCOS_NETWORK_SRC

    network/HttpClient.cpp
    network/SocketIO.cpp
    network/WebSocket.cpp

)

if(MSVC)
  set(COCOS_NETWORK_LINK 
    libcurl_imp 
    ${PLATFORM_LINK}
  )
else()
  set(COCOS_NETWORK_LINK 
    curl
    ${PLATFORM_LINK} 
  )
endif()
=======
if(WIN32)
  set(PLATFORM_SRC
    network/WebSocket.cpp
  )

  set(PLATFORM_LINK
    websockets
  )
elseif(NOT APPLE)
  set(PLATFORM_SRC
    network/WebSocket.cpp
  )

  set(PLATFORM_LINK
    websockets
    ssl
    crypto
  )
endif()

set(COCOS_NETWORK_SRC
  network/HttpClient.cpp
  network/SocketIO.cpp
  ${PLATFORM_SRC}
)

IF (WIN32 AND NOT MINGW)
  set(COCOS_NETWORK_LINK
    libcurl_imp
    ${PLATFORM_LINK}
  )
ELSE()
  set(COCOS_NETWORK_LINK
    curl
    ${PLATFORM_LINK}
  )
ENDIF()
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
