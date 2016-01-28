<<<<<<< HEAD
/****************************************************************************
 Copyright (c) 2014 Chukong Technologies Inc.
 
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

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "CCBundleReader.h"
#include "platform/CCFileUtils.h"

NS_CC_BEGIN

BundleReader::BundleReader()
{
<<<<<<< HEAD
    _buffer = nullptr;
    _position = 0;
    _length = 0;
=======
    m_buffer = nullptr;
    m_position = 0;
    m_length = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
};

BundleReader::~BundleReader()
{
    
};

<<<<<<< HEAD
void BundleReader::init(char* buffer, ssize_t length)
{
    _position = 0;
    _buffer  = buffer;
    _length = length;
=======
void BundleReader::init(char* lpbuffer, ssize_t length)
{
    m_position = 0;
    m_buffer  = lpbuffer;
    m_length = length;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

ssize_t BundleReader::read(void* ptr, ssize_t size, ssize_t count)
{
<<<<<<< HEAD
    if (!_buffer || eof())
    {
        CCLOG("warning: bundle reader out of range");
        return 0;
    }

    ssize_t validCount;
    ssize_t validLength = _length - _position;
    ssize_t needLength = size*count;
    char* ptr1 = (char*)ptr;
    if(validLength < needLength)
    {
        validCount = validLength/size;
        ssize_t readLength = size*validCount;
        memcpy(ptr1,(char*)_buffer+_position,readLength);
        ptr1 += readLength;
        _position += readLength;
        readLength = validLength - readLength;
        if(readLength>0)
        {
            memcpy(ptr1,(char*)_buffer+_position,readLength);
            _position += readLength;
            validCount+=1;
        }
        CCLOG("warning: bundle reader out of range");
    }
    else
    {
        memcpy(ptr1,(char*)_buffer+_position,needLength);
        _position += needLength;
=======
    if (!m_buffer || eof())
        return 0;

    ssize_t validCount;
    ssize_t validLength = m_length - m_position;
    ssize_t needLength = size*count;
    char* ptr1 = (char*)ptr;
    if(validLength <= needLength)
    {
        validCount = validLength/size;
        ssize_t readLength = size*validCount;
        memcpy(ptr1,(char*)m_buffer+m_position,readLength);
        ptr1 += readLength;
        m_position += readLength;
        readLength = validLength - readLength;
        if(readLength>0)
        {
            memcpy(ptr1,(char*)m_buffer+m_position,readLength);
            m_position += readLength;
            validCount+=1;
        }
    }
    else
    {
        memcpy(ptr1,(char*)m_buffer+m_position,needLength);
        m_position += needLength;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        validCount = count;
    }

    return validCount;
}

char* BundleReader::readLine(int num,char* line)
{
<<<<<<< HEAD
    if (!_buffer)
        return 0;

    char* buffer = (char*)_buffer+_position;
    char* p = line;
    char c;
    ssize_t readNum = 0;
    while((c=*buffer) != 10 && readNum < (ssize_t)num && _position < _length)
=======
    if (!m_buffer)
        return 0;

    char* buffer = (char*)m_buffer+m_position;
    char* p = line;
    char c;
    ssize_t readNum = 0;
    while((c=*buffer) != 10 && readNum < (ssize_t)num && m_position < m_length)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        *p = c;
        p++;
        buffer++;
<<<<<<< HEAD
        _position++;
=======
        m_position++;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        readNum++;
    }
    *p = '\0';

    return line;
}

bool BundleReader::eof()
{
<<<<<<< HEAD
    if (!_buffer)
=======
    if (!m_buffer)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return true;
    
    return ((ssize_t)tell()) >= length();
}

ssize_t BundleReader::length()
{
<<<<<<< HEAD
    return _length;
=======
    return m_length;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

ssize_t BundleReader::tell()
{
<<<<<<< HEAD
    if (!_buffer)
        return -1;
    return _position;
=======
    if (!m_buffer)
        return -1;
    return m_position;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

bool BundleReader::seek(long int offset, int origin)
{
<<<<<<< HEAD
    if (!_buffer)
=======
    if (!m_buffer)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return false;

    if(origin == SEEK_CUR)
    {
<<<<<<< HEAD
        _position += offset;
    }
    else if(origin == SEEK_SET)
    {
        _position = offset;
    }
    else if(origin == SEEK_END)
    {
        _position = _length+offset;
=======
        m_position += offset;
    }
    else if(origin == SEEK_SET)
    {
        m_position = offset;
    }
    else if(origin == SEEK_END)
    {
        m_position = m_length+offset;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }
    else
        return false;

    return true;
}

bool BundleReader::rewind()
{
<<<<<<< HEAD
    if (_buffer != nullptr)
    {
        _position = 0;
=======
    if (m_buffer != nullptr)
    {
        m_position = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        return true;
    }
    return false;
}

std::string BundleReader::readString()
{
    unsigned int length;
    if(read(&length, 4, 1) != 1)
    {
        return std::string();
    }

    std::string str;
<<<<<<< HEAD
    
    ssize_t validLength = _length - _position;
    if (length > 0 && static_cast<ssize_t>(length) <= validLength)
=======
    if (length > 0)
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    {
        str.resize(length);
        if (read(&str[0], 1, length) != length)
        {
            return std::string();
        }
    }
<<<<<<< HEAD
    
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return str;
}

bool BundleReader::readMatrix(float* m)
{
    return (read(m, sizeof(float), 16) == 16);
}

<<<<<<< HEAD
NS_CC_END
=======
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
