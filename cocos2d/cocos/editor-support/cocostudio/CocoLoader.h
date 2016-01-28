/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
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

#ifndef _COCOLOADER_H
#define _COCOLOADER_H

<<<<<<< HEAD
#include <stdint.h>
#include "json/document.h"
#include "cocostudio/CocosStudioExport.h"
=======
#include <stdio.h>
#include <vector>
#include <cstdio>
#include <stdint.h>
#include "json/rapidjson.h"
#include "json/document.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#pragma pack (4)

namespace cocostudio{
        
class CocoLoader;
    
<<<<<<< HEAD
struct CC_STUDIO_DLL stExpCocoAttribDesc
=======
struct  stExpCocoAttribDesc
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    char	m_cTypeName;
    uint32_t m_szName;
public:
    char* GetName(CocoLoader*	pCoco);
};

<<<<<<< HEAD
struct CC_STUDIO_DLL stExpCocoObjectDesc
=======
struct  stExpCocoObjectDesc
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    unsigned char	m_cAttribNum;
    uint32_t		m_szName;
    uint32_t		m_pAttribDescArray;
public:
    char*	GetName(CocoLoader*	pCoco);
    int		GetAttribNum();
    stExpCocoAttribDesc*	GetAttribDescArray(CocoLoader*	pCoco);
};

<<<<<<< HEAD
struct CC_STUDIO_DLL stExpCocoNode
=======
struct  stExpCocoNode
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
public:
    int16_t			m_ObjIndex;
    int16_t			m_AttribIndex;
    unsigned char	m_ChildNum;
    uint32_t		m_szValue;
    uint32_t		m_ChildArray;
public:
    rapidjson::Type		GetType(CocoLoader*	pCoco);
    char*				GetName(CocoLoader*	pCoco);
    char*				GetValue(CocoLoader*	pCoco);
    int					GetChildNum();
    stExpCocoNode*		GetChildArray(CocoLoader*	pCoco);
public:
    void WriteJson(CocoLoader* pCoco,void* pFileName = nullptr, int vLayer = 0, bool bEndNode = false, bool bParentNodeIsArray = false);
};

<<<<<<< HEAD
struct CC_STUDIO_DLL stCocoFileHeader
=======
struct	stCocoFileHeader
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    char		m_FileDesc[32];
    char		m_Version[32];
    uint32_t	m_nDataSize;
    uint32_t	m_nCompressSize;
    uint32_t	m_ObjectCount;
    uint32_t	m_lAttribMemAddr;
    uint32_t	m_CocoNodeMemAddr;
    uint32_t	m_lStringMemAddr;
    
};

<<<<<<< HEAD
class CC_STUDIO_DLL CocoLoader
=======
class CocoLoader
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    stCocoFileHeader*			m_pFileHeader;
    stExpCocoNode*				m_pRootNode;
    stExpCocoObjectDesc*		m_pObjectDescArray;
    char*						m_pMemoryBuff;
    
public:
    CocoLoader();
    ~CocoLoader();
public:
    
    bool					ReadCocoBinBuff(char* pBinBuff);
    stCocoFileHeader*		GetFileHeader(){return m_pFileHeader;}
    stExpCocoNode*			GetRootCocoNode(){return	m_pRootNode;}
    stExpCocoObjectDesc*	GetCocoObjectDescArray(){return	m_pObjectDescArray;}
    char*					GetMemoryAddr_AttribDesc();
    char*					GetMemoryAddr_CocoNode();
    char*					GetMemoryAddr_String();
    
};

}

#pragma pack ()
#endif
