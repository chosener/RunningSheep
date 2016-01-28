set(UNZIP_SRC
  ioapi.cpp
  unzip.cpp
<<<<<<< HEAD
  ioapi_mem.cpp
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
)

add_library(unzip STATIC
  ${UNZIP_SRC}
)

set_target_properties(unzip
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

