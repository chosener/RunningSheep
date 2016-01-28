/******************************************************************************
<<<<<<< HEAD
 * Spine Runtimes Software License
 * Version 2.1
=======
 * Spine Runtime Software License - Version 1.1
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
<<<<<<< HEAD
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to install, execute and perform the Spine Runtimes
 * Software (the "Software") solely for internal use. Without the written
 * permission of Esoteric Software (typically granted by licensing Spine), you
 * may not (a) modify, translate, adapt or otherwise create derivative works,
 * improvements of the Software or develop new applications using the Software
 * or (b) remove, delete, alter or obscure any trademarks or any copyright,
 * trademark, patent or other intellectual property or proprietary rights
 * notices on or in the Software, including any copy thereof. Redistributions
 * in binary or source form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
=======
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Essential, Professional, Enterprise, or Education License must
 *    be purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 *****************************************************************************/

#ifndef SPINE_ATTACHMENT_H_
#define SPINE_ATTACHMENT_H_

#ifdef __cplusplus
extern "C" {
#endif

<<<<<<< HEAD
typedef enum {
	SP_ATTACHMENT_REGION, SP_ATTACHMENT_BOUNDING_BOX, SP_ATTACHMENT_MESH, SP_ATTACHMENT_SKINNED_MESH
} spAttachmentType;

typedef struct spAttachment {
	const char* const name;
	const spAttachmentType type;
	const void* const vtable;

#ifdef __cplusplus
	spAttachment() :
		name(0),
		type(SP_ATTACHMENT_REGION),
		vtable(0) {
	}
#endif
} spAttachment;
=======
struct spSlot;

typedef enum {
	ATTACHMENT_REGION, ATTACHMENT_REGION_SEQUENCE, ATTACHMENT_BOUNDING_BOX
} spAttachmentType;

typedef struct spAttachment spAttachment;
struct spAttachment {
	const char* const name;
	spAttachmentType type;

	const void* const vtable;
};
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

void spAttachment_dispose (spAttachment* self);

#ifdef SPINE_SHORT_NAMES
typedef spAttachmentType AttachmentType;
<<<<<<< HEAD
#define ATTACHMENT_REGION SP_ATTACHMENT_REGION
#define ATTACHMENT_BOUNDING_BOX SP_ATTACHMENT_BOUNDING_BOX
#define ATTACHMENT_MESH SP_ATTACHMENT_MESH
#define ATTACHMENT_SKINNED_MESH SP_ATTACHMENT_SKINNED_MESH
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
typedef spAttachment Attachment;
#define Attachment_dispose(...) spAttachment_dispose(__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPINE_ATTACHMENT_H_ */
