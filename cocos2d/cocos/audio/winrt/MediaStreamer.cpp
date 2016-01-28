<<<<<<< HEAD
/*
* cocos2d-x   http://www.cocos2d-x.org
*
* Copyright (c) 2010-2011 - cocos2d-x community
* 
* Portions Copyright (c) Microsoft Open Technologies, Inc.
* All Rights Reserved
* 
* Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. 
* You may obtain a copy of the License at 
* 
* http://www.apache.org/licenses/LICENSE-2.0 
* 
* Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an 
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
* See the License for the specific language governing permissions and limitations under the License.
*/

#include "MediaStreamer.h"

#include <Mfidl.h>
#include <Mfreadwrite.h>
#include <Mfapi.h>

#include <wrl\wrappers\corewrappers.h>
#include <ppltasks.h>

using namespace Microsoft::WRL;
using namespace Windows::Storage;
using namespace Windows::Storage::FileProperties;
using namespace Windows::Storage::Streams;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel;
using namespace Concurrency;

#ifndef MAKEFOURCC
    #define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((uint32)(byte)(ch0) | ((uint32)(byte)(ch1) << 8) |       \
                ((uint32)(byte)(ch2) << 16) | ((uint32)(byte)(ch3) << 24 ))
#endif /* defined(MAKEFOURCC) */

inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        // Set a breakpoint on this line to catch DX API errors.
=======
//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//// PARTICULAR PURPOSE.
////
//// Copyright (c) Microsoft Corporation. All rights reserved

#include "pch.h"
#include "MediaStreamer.h"

using namespace Windows::ApplicationModel;

static inline void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        // Set a breakpoint on this line to catch DirectX API errors
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        throw Platform::Exception::CreateException(hr);
    }
}

<<<<<<< HEAD
MediaStreamer::MediaStreamer() :
    m_offset(0)
{
    ZeroMemory(&m_waveFormat, sizeof(m_waveFormat));
    m_location = Package::Current->InstalledLocation;
    m_locationPath = Platform::String::Concat(m_location->Path, "\\Assets\\Resources\\");
=======

MediaStreamer::MediaStreamer()
{
    m_reader = nullptr;
    m_audioType = nullptr;
    ZeroMemory(&m_waveFormat, sizeof(m_waveFormat));

    m_installedLocation = Package::Current->InstalledLocation;
    m_installedLocationPath = Platform::String::Concat(m_installedLocation->Path, "\\Assets\\Resources\\");
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

MediaStreamer::~MediaStreamer()
{
}
<<<<<<< HEAD
Platform::Array<byte>^ MediaStreamer::ReadData(
    _In_ Platform::String^ filename
    )
{
    CREATEFILE2_EXTENDED_PARAMETERS extendedParams = {0};
    extendedParams.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
    extendedParams.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
    extendedParams.dwFileFlags = FILE_FLAG_SEQUENTIAL_SCAN;
    extendedParams.dwSecurityQosFlags = SECURITY_ANONYMOUS;
    extendedParams.lpSecurityAttributes = nullptr;
    extendedParams.hTemplateFile = nullptr;

    Wrappers::FileHandle file(
        CreateFile2(
            filename->Data(),
            GENERIC_READ,
            FILE_SHARE_READ,
            OPEN_EXISTING,
            &extendedParams
            )
        );
    if (file.Get()==INVALID_HANDLE_VALUE)
    {
        throw ref new Platform::FailureException();
    }

    FILE_STANDARD_INFO fileInfo = {0};
    if (!GetFileInformationByHandleEx(
        file.Get(),
        FileStandardInfo,
        &fileInfo,
        sizeof(fileInfo)
        ))
    {
        throw ref new Platform::FailureException();
    }

    if (fileInfo.EndOfFile.HighPart != 0)
    {
        throw ref new Platform::OutOfMemoryException();
    }

    Platform::Array<byte>^ fileData = ref new Platform::Array<byte>(fileInfo.EndOfFile.LowPart);

    if (!ReadFile(
        file.Get(),
        fileData->Data,
        fileData->Length,
        nullptr,
        nullptr
        ) )
    {
        throw ref new Platform::FailureException();
    }

    return fileData;
}

void MediaStreamer::Initialize(__in const WCHAR* url)
{

    WCHAR filePath[MAX_PATH] = {0};
=======

void MediaStreamer::Initialize(__in const WCHAR* url)
{
    Microsoft::WRL::ComPtr<IMFMediaType> outputMediaType;
    Microsoft::WRL::ComPtr<IMFMediaType> mediaType;
  
    ThrowIfFailed(
        MFStartup(MF_VERSION)
        );

	WCHAR filePath[MAX_PATH] = {0};
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	if ((wcslen(url) > 1 && url[1] == ':'))
	{
		// path start with "x:", is absolute path
		wcscat_s(filePath, url);
	}
	else if (wcslen(url) > 0 
		&& (L'/' == url[0] || L'\\' == url[0]))
	{
		// path start with '/' or '\', is absolute path without driver name
<<<<<<< HEAD
		wcscat_s(filePath, m_locationPath->Data());
=======
		wcscat_s(filePath, m_installedLocationPath->Data());
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
		// remove '/' or '\\'
		wcscat_s(filePath, (const WCHAR*)url[1]);
	}else
	{
<<<<<<< HEAD
		wcscat_s(filePath, m_locationPath->Data());
		wcscat_s(filePath, url);
	}


	Platform::Array<byte>^ data = ReadData(ref new Platform::String(filePath));
	UINT32 length = data->Length;
	const byte * dataPtr = data->Data;
	UINT32 offset = 0;

	DWORD riffDataSize = 0;

	auto ReadChunk = [&length, &offset, &dataPtr, &riffDataSize](DWORD fourcc, DWORD& outChunkSize, DWORD& outChunkPos) -> HRESULT
	{
		while (true)
		{
			if (offset + sizeof(DWORD) * 2 >= length)
			{
				return E_FAIL;
			}

			// Read two DWORDs.
			DWORD chunkType = *reinterpret_cast<const DWORD *>(&dataPtr[offset]);
			DWORD chunkSize = *reinterpret_cast<const DWORD *>(&dataPtr[offset + sizeof(DWORD)]);
			offset += sizeof(DWORD) * 2;

			if (chunkType == MAKEFOURCC('R', 'I', 'F', 'F'))
			{
				riffDataSize = chunkSize;
				chunkSize = sizeof(DWORD);
				outChunkSize = sizeof(DWORD);
				outChunkPos = offset;
			}
			else
			{
				outChunkSize = chunkSize;
				outChunkPos = offset;
			}

			offset += chunkSize;

			if (chunkType == fourcc)
			{
				return S_OK;
			}
		}
	};

	// Locate riff chunk, check the file type.
	DWORD chunkSize = 0;
	DWORD chunkPos = 0;

	ThrowIfFailed(ReadChunk(MAKEFOURCC('R', 'I', 'F', 'F'), chunkSize, chunkPos));
	if (*reinterpret_cast<const DWORD *>(&dataPtr[chunkPos]) != MAKEFOURCC('W', 'A', 'V', 'E')) ThrowIfFailed(E_FAIL);

	// Locate 'fmt ' chunk, copy to WAVEFORMATEXTENSIBLE.
	ThrowIfFailed(ReadChunk(MAKEFOURCC('f', 'm', 't', ' '), chunkSize, chunkPos));
	ThrowIfFailed((chunkSize <= sizeof(m_waveFormat)) ? S_OK : E_FAIL);
	CopyMemory(&m_waveFormat, &dataPtr[chunkPos], chunkSize);

	// Locate the 'data' chunk and copy its contents to a buffer.
	ThrowIfFailed(ReadChunk(MAKEFOURCC('d', 'a', 't', 'a'), chunkSize, chunkPos));
	m_data.resize(chunkSize);
	CopyMemory(m_data.data(), &dataPtr[chunkPos], chunkSize);

	m_offset = 0;
=======
		wcscat_s(filePath, m_installedLocationPath->Data());
		wcscat_s(filePath, url);
	}

    ThrowIfFailed(
        MFCreateSourceReaderFromURL(filePath, nullptr, &m_reader)
        );

    // Set the decoded output format as PCM
    // XAudio2 on Windows can process PCM and ADPCM-encoded buffers.
    // When using MF, this sample always decodes into PCM.

    ThrowIfFailed(
        MFCreateMediaType(&mediaType)
        );

    ThrowIfFailed(
        mediaType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio)
        );

    ThrowIfFailed(
        mediaType->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM)
        );

    ThrowIfFailed(
        m_reader->SetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, 0, mediaType.Get())
        );

    // Get the complete WAVEFORMAT from the Media Type
    ThrowIfFailed(
        m_reader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, &outputMediaType)
        );

    uint32 formatSize = 0;
    WAVEFORMATEX* waveFormat;
    ThrowIfFailed(
        MFCreateWaveFormatExFromMFMediaType(outputMediaType.Get(), &waveFormat, &formatSize)
        );
    CopyMemory(&m_waveFormat, waveFormat, sizeof(m_waveFormat));
    CoTaskMemFree(waveFormat);

    // Get the total length of the stream in bytes
    PROPVARIANT var;
    ThrowIfFailed(
        m_reader->GetPresentationAttribute(MF_SOURCE_READER_MEDIASOURCE, MF_PD_DURATION, &var)
        );
    LONGLONG duration = var.uhVal.QuadPart;
    double durationInSeconds = (duration / static_cast<double>(10000000)); // duration is in 100ns units, convert to seconds
    m_maxStreamLengthInBytes = static_cast<unsigned int>(durationInSeconds * m_waveFormat.nAvgBytesPerSec);

    // Round up the buffer size to the nearest four bytes
    m_maxStreamLengthInBytes = (m_maxStreamLengthInBytes + 3) / 4 * 4;
}

bool MediaStreamer::GetNextBuffer(uint8* buffer, uint32 maxBufferSize, uint32* bufferLength)
{
    Microsoft::WRL::ComPtr<IMFSample> sample;
    Microsoft::WRL::ComPtr<IMFMediaBuffer> mediaBuffer;
    BYTE *audioData = nullptr;
    DWORD sampleBufferLength = 0;
    DWORD flags = 0;

    *bufferLength = 0;

    if (m_reader == nullptr)
    {
        return false;
    }

    ThrowIfFailed(
        m_reader->ReadSample(MF_SOURCE_READER_FIRST_AUDIO_STREAM, 0, nullptr, &flags, nullptr, &sample)
        );

    if (sample == nullptr)
    {
        if (flags & MF_SOURCE_READERF_ENDOFSTREAM)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    ThrowIfFailed(
        sample->ConvertToContiguousBuffer(&mediaBuffer)
        );

    ThrowIfFailed(
        mediaBuffer->Lock(&audioData, nullptr, &sampleBufferLength)
        );

    // If buffer isn't large enough, dump sample
    if (sampleBufferLength <= maxBufferSize)
    {
        CopyMemory(buffer, audioData, sampleBufferLength);
        *bufferLength = sampleBufferLength;
    }
    else
    {
#if defined(COCOS2D_DEBUG)
        OutputDebugString(L"Sample buffer dumped");
#endif
    }
    
    if (flags & MF_SOURCE_READERF_ENDOFSTREAM)
    {
        return true;
    }
    else
    {
        return false;
    }
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void MediaStreamer::ReadAll(uint8* buffer, uint32 maxBufferSize, uint32* bufferLength)
{
<<<<<<< HEAD
	UINT32 toCopy = m_data.size() - m_offset;
	if (toCopy > maxBufferSize) toCopy = maxBufferSize;

	CopyMemory(buffer, m_data.data(), toCopy);
	*bufferLength = toCopy;

	m_offset += toCopy;
	if (m_offset > m_data.size()) m_offset = m_data.size();
=======
    uint32 valuesWritten = 0;
    uint32 sampleBufferLength = 0;

    if (m_reader == nullptr)
    {
        return;
    }

    *bufferLength = 0;
    // If buffer isn't large enough, return
    if (maxBufferSize < m_maxStreamLengthInBytes)
    {
        return;
    }
 
    while (!GetNextBuffer(buffer + valuesWritten, maxBufferSize - valuesWritten, &sampleBufferLength))
    {
        valuesWritten += sampleBufferLength;
    }

    *bufferLength = valuesWritten + sampleBufferLength;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void MediaStreamer::Restart()
{
<<<<<<< HEAD
	m_offset = 0;
=======
    if (m_reader == nullptr)
    {
        return;
    }

    PROPVARIANT var = {0};
    var.vt = VT_I8;

    ThrowIfFailed(
        m_reader->SetCurrentPosition(GUID_NULL, var)
    );
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}
