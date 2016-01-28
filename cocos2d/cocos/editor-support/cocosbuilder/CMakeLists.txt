<<<<<<< HEAD

set(COCOS_CCB_SRC

  editor-support/cocosbuilder/CCBAnimationManager.cpp
  editor-support/cocosbuilder/CCBFileLoader.cpp
  editor-support/cocosbuilder/CCBKeyframe.cpp
  editor-support/cocosbuilder/CCBReader.cpp
  editor-support/cocosbuilder/CCBSequence.cpp
  editor-support/cocosbuilder/CCBSequenceProperty.cpp
  editor-support/cocosbuilder/CCControlButtonLoader.cpp
  editor-support/cocosbuilder/CCControlLoader.cpp
  editor-support/cocosbuilder/CCLabelBMFontLoader.cpp
  editor-support/cocosbuilder/CCLabelTTFLoader.cpp
  editor-support/cocosbuilder/CCLayerColorLoader.cpp
  editor-support/cocosbuilder/CCLayerGradientLoader.cpp
  editor-support/cocosbuilder/CCLayerLoader.cpp
  editor-support/cocosbuilder/CCMenuItemImageLoader.cpp
  editor-support/cocosbuilder/CCMenuItemLoader.cpp
  editor-support/cocosbuilder/CCNode+CCBRelativePositioning.cpp
  editor-support/cocosbuilder/CCNodeLoader.cpp
  editor-support/cocosbuilder/CCNodeLoaderLibrary.cpp
  editor-support/cocosbuilder/CCParticleSystemQuadLoader.cpp
  editor-support/cocosbuilder/CCScale9SpriteLoader.cpp
  editor-support/cocosbuilder/CCScrollViewLoader.cpp
  editor-support/cocosbuilder/CCSpriteLoader.cpp

)

include_directories( editor-support )
=======
set(CCB_SRC
  CCBFileLoader.cpp
  CCMenuItemImageLoader.cpp
  CCBReader.cpp
  CCMenuItemLoader.cpp
  CCControlButtonLoader.cpp
  CCNodeLoader.cpp
  CCControlLoader.cpp
  CCNodeLoaderLibrary.cpp
  CCLabelBMFontLoader.cpp
  CCParticleSystemQuadLoader.cpp
  CCLabelTTFLoader.cpp
  CCScale9SpriteLoader.cpp
  CCLayerColorLoader.cpp
  CCScrollViewLoader.cpp
  CCLayerGradientLoader.cpp
  CCSpriteLoader.cpp
  CCLayerLoader.cpp
  CCBAnimationManager.cpp
  CCBKeyframe.cpp
  CCBSequence.cpp
  CCBSequenceProperty.cpp
  CCNode+CCBRelativePositioning.cpp
)

include_directories(
  ..
)

add_library(cocosbuilder STATIC
  ${CCB_SRC}
)

set_target_properties(cocosbuilder
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
