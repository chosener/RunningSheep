<<<<<<< HEAD

if(WINDOWS AND BUILD_SHARED_LIBS)
  ADD_DEFINITIONS (-D_USRSTUDIODLL)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

set(COCOS_CS_SRC

  editor-support/cocostudio/CCActionFrame.cpp
  editor-support/cocostudio/CCActionFrameEasing.cpp
  editor-support/cocostudio/CCActionManagerEx.cpp
  editor-support/cocostudio/CCActionNode.cpp
  editor-support/cocostudio/CCActionObject.cpp
  editor-support/cocostudio/CCArmature.cpp
  editor-support/cocostudio/CCArmatureAnimation.cpp
  editor-support/cocostudio/CCArmatureDataManager.cpp
  editor-support/cocostudio/CCArmatureDefine.cpp
  editor-support/cocostudio/CCBatchNode.cpp
  editor-support/cocostudio/CCBone.cpp
  editor-support/cocostudio/CCColliderDetector.cpp
  editor-support/cocostudio/CCComAttribute.cpp
  editor-support/cocostudio/CCComAudio.cpp
  editor-support/cocostudio/CCComController.cpp
  editor-support/cocostudio/CCComRender.cpp
  editor-support/cocostudio/CCDataReaderHelper.cpp
  editor-support/cocostudio/CCDatas.cpp
  editor-support/cocostudio/CCDecorativeDisplay.cpp
  editor-support/cocostudio/CCDisplayFactory.cpp
  editor-support/cocostudio/CCDisplayManager.cpp
  editor-support/cocostudio/CCInputDelegate.cpp
  editor-support/cocostudio/CCProcessBase.cpp
  editor-support/cocostudio/CCSGUIReader.cpp
  editor-support/cocostudio/CCSSceneReader.cpp
  editor-support/cocostudio/CCSkin.cpp
  editor-support/cocostudio/CCSpriteFrameCacheHelper.cpp
  editor-support/cocostudio/CCTransformHelp.cpp
  editor-support/cocostudio/CCTween.cpp
  editor-support/cocostudio/CCUtilMath.cpp
  editor-support/cocostudio/CocoLoader.cpp
  editor-support/cocostudio/DictionaryHelper.cpp
  editor-support/cocostudio/TriggerBase.cpp
  editor-support/cocostudio/TriggerMng.cpp
  editor-support/cocostudio/TriggerObj.cpp
  editor-support/cocostudio/FlatBuffersSerialize.cpp
  editor-support/cocostudio/CCObjectExtensionData.cpp
  editor-support/cocostudio/CocoStudio.cpp
  editor-support/cocostudio/WidgetReader/NodeReader/NodeReader.cpp
  editor-support/cocostudio/WidgetReader/SingleNodeReader/SingleNodeReader.cpp
  editor-support/cocostudio/WidgetReader/SpriteReader/SpriteReader.cpp 
  editor-support/cocostudio/WidgetReader/ParticleReader/ParticleReader.cpp 
  editor-support/cocostudio/WidgetReader/GameMapReader/GameMapReader.cpp 
  editor-support/cocostudio/WidgetReader/ProjectNodeReader/ProjectNodeReader.cpp 
  editor-support/cocostudio/WidgetReader/ComAudioReader/ComAudioReader.cpp 
  editor-support/cocostudio/WidgetReader/WidgetReader.cpp
  editor-support/cocostudio/WidgetReader/LoadingBarReader/LoadingBarReader.cpp
  editor-support/cocostudio/WidgetReader/ListViewReader/ListViewReader.cpp
  editor-support/cocostudio/WidgetReader/TextFieldReader/TextFieldReader.cpp
  editor-support/cocostudio/WidgetReader/WidgetReader.cpp
  editor-support/cocostudio/WidgetReader/CheckBoxReader/CheckBoxReader.cpp
  editor-support/cocostudio/WidgetReader/SliderReader/SliderReader.cpp
  editor-support/cocostudio/WidgetReader/PageViewReader/PageViewReader.cpp
  editor-support/cocostudio/WidgetReader/TextReader/TextReader.cpp
  editor-support/cocostudio/WidgetReader/Node3DReader/Node3DReader.cpp
  editor-support/cocostudio/WidgetReader/UserCameraReader/UserCameraReader.cpp
  editor-support/cocostudio/WidgetReader/Particle3DReader/Particle3DReader.cpp    
  editor-support/cocostudio/WidgetReader/Sprite3DReader/Sprite3DReader.cpp
  editor-support/cocostudio/WidgetReader/TextAtlasReader/TextAtlasReader.cpp
  editor-support/cocostudio/WidgetReader/LayoutReader/LayoutReader.cpp
  editor-support/cocostudio/WidgetReader/TextBMFontReader/TextBMFontReader.cpp
  editor-support/cocostudio/WidgetReader/ImageViewReader/ImageViewReader.cpp
  editor-support/cocostudio/WidgetReader/ButtonReader/ButtonReader.cpp
  editor-support/cocostudio/WidgetReader/ScrollViewReader/ScrollViewReader.cpp
  editor-support/cocostudio/ActionTimeline/CCActionTimelineCache.cpp
  editor-support/cocostudio/ActionTimeline/CCActionTimeline.cpp
  editor-support/cocostudio/ActionTimeline/CCActionTimelineNode.cpp
  editor-support/cocostudio/ActionTimeline/CCFrame.cpp
  editor-support/cocostudio/ActionTimeline/CCTimeLine.cpp
  editor-support/cocostudio/ActionTimeline/CSLoader.cpp
  editor-support/cocostudio/FlatBuffersSerialize.cpp
  editor-support/cocostudio/WidgetReader/ArmatureNodeReader/ArmatureNodeReader.cpp
)

include_directories( editor-support )
=======
set(CS_SRC
  CCActionFrame.cpp
  CCActionFrameEasing.cpp
  CCActionManagerEx.cpp
  CCActionNode.cpp
  CCActionObject.cpp
  CCArmature.cpp
  CCBone.cpp
  CCArmatureAnimation.cpp
  CCProcessBase.cpp
  CCTween.cpp
  CCDatas.cpp
  CCBatchNode.cpp
  CCDecorativeDisplay.cpp
  CCDisplayFactory.cpp
  CCDisplayManager.cpp
  CCSkin.cpp
  CCColliderDetector.cpp
  CCArmatureDataManager.cpp
  CCArmatureDefine.cpp
  CCDataReaderHelper.cpp
  CCSpriteFrameCacheHelper.cpp
  CCTransformHelp.cpp
  CCUtilMath.cpp
  CCComAttribute.cpp
  CCComAudio.cpp
  CCComController.cpp
  CCComRender.cpp
  CCInputDelegate.cpp
  DictionaryHelper.cpp
  CCSGUIReader.cpp
  CCSSceneReader.cpp
  TriggerBase.cpp
  TriggerMng.cpp
  TriggerObj.cpp
  CocoLoader.cpp
  WidgetReader/WidgetReader.cpp
  WidgetReader/ButtonReader/ButtonReader.cpp
  WidgetReader/CheckBoxReader/CheckBoxReader.cpp
  WidgetReader/ImageViewReader/ImageViewReader.cpp
  WidgetReader/LayoutReader/LayoutReader.cpp
  WidgetReader/ListViewReader/ListViewReader.cpp
  WidgetReader/LoadingBarReader/LoadingBarReader.cpp
  WidgetReader/PageViewReader/PageViewReader.cpp
  WidgetReader/ScrollViewReader/ScrollViewReader.cpp
  WidgetReader/SliderReader/SliderReader.cpp
  WidgetReader/TextAtlasReader/TextAtlasReader.cpp
  WidgetReader/TextBMFontReader/TextBMFontReader.cpp
  WidgetReader/TextFieldReader/TextFieldReader.cpp
  WidgetReader/TextReader/TextReader.cpp
  ActionTimeline/CCActionTimeline.cpp
  ActionTimeline/CCActionTimelineCache.cpp
  ActionTimeline/CCFrame.cpp
  ActionTimeline/CCNodeReader.cpp
  ActionTimeline/CCTimeLine.cpp
)

include_directories(
  ..
)

add_library(cocostudio STATIC
  ${CS_SRC}
)

target_link_libraries(cocostudio
)

set_target_properties(cocostudio
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
