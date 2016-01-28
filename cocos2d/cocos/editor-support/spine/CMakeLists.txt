<<<<<<< HEAD

set(COCOS_SPINE_SRC

  editor-support/spine/Animation.c
  editor-support/spine/AnimationState.c
  editor-support/spine/AnimationStateData.c
  editor-support/spine/Atlas.c
  editor-support/spine/AtlasAttachmentLoader.c
  editor-support/spine/Attachment.c
  editor-support/spine/AttachmentLoader.c
  editor-support/spine/Bone.c
  editor-support/spine/BoneData.c
  editor-support/spine/BoundingBoxAttachment.c
  editor-support/spine/Event.c
  editor-support/spine/EventData.c
  editor-support/spine/extension.c
  editor-support/spine/IkConstraint.c
  editor-support/spine/IkConstraintData.c
  editor-support/spine/Json.c
  editor-support/spine/MeshAttachment.c
  editor-support/spine/PolygonBatch.cpp
  editor-support/spine/RegionAttachment.c
  editor-support/spine/Skeleton.c
  editor-support/spine/SkeletonAnimation.cpp
  editor-support/spine/SkeletonBounds.c
  editor-support/spine/SkeletonData.c
  editor-support/spine/SkeletonJson.c
  editor-support/spine/SkeletonRenderer.cpp
  editor-support/spine/Skin.c
  editor-support/spine/SkinnedMeshAttachment.c
  editor-support/spine/Slot.c
  editor-support/spine/SlotData.c
  editor-support/spine/spine-cocos2dx.cpp
)

include_directories( editor-support )
=======
set(SPINE_SRC
  Animation.cpp
  AnimationState.cpp
  AnimationStateData.cpp
  Atlas.cpp
  AtlasAttachmentLoader.cpp
  Attachment.cpp
  AttachmentLoader.cpp
  Bone.cpp
  BoneData.cpp
  BoundingBoxAttachment.cpp
  Event.cpp
  EventData.cpp
  Json.cpp
  RegionAttachment.cpp
  Skeleton.cpp
  SkeletonBounds.cpp
  SkeletonData.cpp
  SkeletonJson.cpp
  Skin.cpp
  Slot.cpp
  SlotData.cpp
  Slot.cpp
  SlotData.cpp
  extension.cpp
  spine-cocos2dx.cpp
  CCSkeleton.cpp
  CCSkeletonAnimation.cpp
  BoundingBoxAttachment.cpp
  Event.cpp
  EventData.cpp
  SkeletonBounds.cpp
)

include_directories(
  ..
)

add_library(spine STATIC
  ${SPINE_SRC}
)

set_target_properties(spine
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
