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

#ifndef SPINE_ATTACHMENTLOADER_H_
#define SPINE_ATTACHMENTLOADER_H_

#include <spine/Attachment.h>
#include <spine/Skin.h>

#ifdef __cplusplus
extern "C" {
#endif

<<<<<<< HEAD
typedef struct spAttachmentLoader {
=======
typedef struct spAttachmentLoader spAttachmentLoader;
struct spAttachmentLoader {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	const char* error1;
	const char* error2;

	const void* const vtable;
#ifdef __cplusplus
	spAttachmentLoader () :
					error1(0),
					error2(0),
					vtable(0) {
	}
#endif
<<<<<<< HEAD
} spAttachmentLoader;
=======
};
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

void spAttachmentLoader_dispose (spAttachmentLoader* self);

/* Returns 0 to not load an attachment. If 0 is returned and spAttachmentLoader.error1 is set, an error occurred. */
<<<<<<< HEAD
spAttachment* spAttachmentLoader_newAttachment (spAttachmentLoader* self, spSkin* skin, spAttachmentType type, const char* name,
		const char* path);
=======
spAttachment* spAttachmentLoader_newAttachment (spAttachmentLoader* self, spSkin* skin, spAttachmentType type, const char* name);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#ifdef SPINE_SHORT_NAMES
typedef spAttachmentLoader AttachmentLoader;
#define AttachmentLoader_dispose(...) spAttachmentLoader_dispose(__VA_ARGS__)
#define AttachmentLoader_newAttachment(...) spAttachmentLoader_newAttachment(__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPINE_ATTACHMENTLOADER_H_ */
