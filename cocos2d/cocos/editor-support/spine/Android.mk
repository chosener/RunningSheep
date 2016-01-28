LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := spine_static

LOCAL_MODULE_FILENAME := libspine

<<<<<<< HEAD
LOCAL_SRC_FILES := Animation.c \
AnimationState.c \
AnimationStateData.c \
Atlas.c \
AtlasAttachmentLoader.c \
Attachment.c \
AttachmentLoader.c \
Bone.c \
BoneData.c \
BoundingBoxAttachment.c \
Event.c \
EventData.c \
extension.c \
IkConstraint.c \
IkConstraintData.c \
Json.c \
MeshAttachment.c \
PolygonBatch.cpp \
RegionAttachment.c \
Skeleton.c \
SkeletonAnimation.cpp \
SkeletonBounds.c \
SkeletonData.c \
SkeletonJson.c \
SkeletonRenderer.cpp \
Skin.c \
SkinnedMeshAttachment.c \
Slot.c \
SlotData.c \
=======
LOCAL_SRC_FILES := Animation.cpp \
AnimationState.cpp \
AnimationStateData.cpp \
Atlas.cpp \
AtlasAttachmentLoader.cpp \
Attachment.cpp \
AttachmentLoader.cpp \
Bone.cpp \
BoneData.cpp \
CCSkeleton.cpp \
CCSkeletonAnimation.cpp \
Json.cpp \
RegionAttachment.cpp \
Skeleton.cpp \
SkeletonData.cpp \
SkeletonJson.cpp \
Skin.cpp \
Slot.cpp \
SlotData.cpp \
BoundingBoxAttachment.cpp \
Event.cpp \
EventData.cpp \
SkeletonBounds.cpp \
extension.cpp \
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
spine-cocos2dx.cpp

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/..

<<<<<<< HEAD
LOCAL_C_INCLUDES := $(LOCAL_PATH)/..

LOCAL_STATIC_LIBRARIES := cocos2dx_internal_static

include $(BUILD_STATIC_LIBRARY)
=======
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../.. \
$(LOCAL_PATH)/..

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_STATIC_LIBRARY)

$(call import-module,.)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
