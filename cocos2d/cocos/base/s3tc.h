/****************************************************************************
<<<<<<< HEAD
 Copyright (c) 2013-2015 Chukong Technologies
=======
 Copyright (c) 2013-2014 Chukong Technologies
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

<<<<<<< HEAD
#ifndef COCOS2DX_PLATFORM_THIRDPARTY_S3TC_
#define COCOS2DX_PLATFORM_THIRDPARTY_S3TC_
/// @cond DO_NOT_SHOW

#include "platform/CCStdC.h"
=======

#ifndef COCOS2DX_PLATFORM_THIRDPARTY_S3TC_
#define COCOS2DX_PLATFORM_THIRDPARTY_S3TC_

#include "CCStdC.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

enum class S3TCDecodeFlag
{
    DXT1 = 1,
    DXT3 = 3,
    DXT5 = 5,
};

//Decode S3TC encode data to RGB32
 void s3tc_decode(uint8_t *encode_data,
                 uint8_t *decode_data,
                 const int pixelsWidth,
                 const int pixelsHeight,
                 S3TCDecodeFlag decodeFlag
                 );

<<<<<<< HEAD
 /// @endcond
#endif /* defined(COCOS2DX_PLATFORM_THIRDPARTY_S3TC_) */
=======

#endif /* defined(COCOS2DX_PLATFORM_THIRDPARTY_S3TC_) */

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
