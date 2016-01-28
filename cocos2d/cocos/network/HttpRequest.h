/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
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

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <string>
#include <vector>
#include "base/CCRef.h"
#include "base/ccMacros.h"

<<<<<<< HEAD
/**
 * @addtogroup core
 * @{
 */

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_BEGIN

namespace network {

class HttpClient;
class HttpResponse;

typedef std::function<void(HttpClient* client, HttpResponse* response)> ccHttpRequestCallback;
typedef void (cocos2d::Ref::*SEL_HttpResponse)(HttpClient* client, HttpResponse* response);
#define httpresponse_selector(_SELECTOR) (cocos2d::network::SEL_HttpResponse)(&_SELECTOR)

/** 
<<<<<<< HEAD
 * Defines the object which users must packed for HttpClient::send(HttpRequest*) method.
 * Please refer to tests/test-cpp/Classes/ExtensionTest/NetworkTest/HttpClientTest.cpp as a sample
 * @since v2.0.2
 *
 * @lua NA
=======
 @brief defines the object which users must packed for HttpClient::send(HttpRequest*) method.
 Please refer to tests/test-cpp/Classes/ExtensionTest/NetworkTest/HttpClientTest.cpp as a sample
 @since v2.0.2
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 */

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#ifdef DELETE
#undef DELETE
#endif
#endif

<<<<<<< HEAD
class CC_DLL HttpRequest : public Ref
{
public:
    /**
     * The HttpRequest type enum used in the HttpRequest::setRequestType.
     */
=======
class HttpRequest : public Ref
{
public:
    /** Use this enum type as param in setReqeustType(param) */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class Type
    {
        GET,
        POST,
        PUT,
        DELETE,
        UNKNOWN,
    };
    
<<<<<<< HEAD
    /** 
     *  Constructor.
     *   Because HttpRequest object will be used between UI thead and network thread,
         requestObj->autorelease() is forbidden to avoid crashes in AutoreleasePool
         new/retain/release still works, which means you need to release it manually
         Please refer to HttpRequestTest.cpp to find its usage.
=======
    /** Constructor
        Because HttpRequest object will be used between UI thead and network thread,
        requestObj->autorelease() is forbidden to avoid crashes in AutoreleasePool
        new/retain/release still works, which means you need to release it manually
        Please refer to HttpRequestTest.cpp to find its usage
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    HttpRequest()
    {
        _requestType = Type::UNKNOWN;
        _url.clear();
        _requestData.clear();
        _tag.clear();
        _pTarget = nullptr;
        _pSelector = nullptr;
        _pCallback = nullptr;
        _pUserData = nullptr;
    };
    
<<<<<<< HEAD
    /** Destructor. */
=======
    /** Destructor */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ~HttpRequest()
    {
        if (_pTarget)
        {
            _pTarget->release();
        }
    };
    
<<<<<<< HEAD
    /** 
     * Override autorelease method to avoid developers to call it.
     * If this function was called, it would trigger assert in debug mode
     *
     * @return Ref* always return nullptr.
     */
=======
    /** Override autorelease method to avoid developers to call it */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Ref* autorelease(void)
    {
        CCASSERT(false, "HttpResponse is used between network thread and ui thread \
                 therefore, autorelease is forbidden here");
        return NULL;
    }
            
    // setter/getters for properties
     
<<<<<<< HEAD
    /** 
     * Set request type of HttpRequest object before being sent,now it support the enum value of HttpRequest::Type.
     *
     * @param type the request type.
=======
    /** Required field for HttpRequest object before being sent.
        kHttpGet & kHttpPost is currently supported
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setRequestType(Type type)
    {
        _requestType = type;
    };
<<<<<<< HEAD
    /** 
     * Get the request type of HttpRequest object.
     *
     * @return HttpRequest::Type.
     */
=======
    /** Get back the kHttpGet/Post/... enum value */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline Type getRequestType()
    {
        return _requestType;
    };
    
<<<<<<< HEAD
    /** 
     * Set the url address of HttpRequest object.
     * The url value could be like these: "http://httpbin.org/ip" or "https://httpbin.org/get"
     *
     * @param url the string pointer.
=======
    /** Required field for HttpRequest object before being sent.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setUrl(const char* url)
    {
        _url = url;
    };
<<<<<<< HEAD
    /** 
     * Get the url address of HttpRequest object.
     *
     * @return const char* the pointer of _url.
     */
=======
    /** Get back the setted url */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline const char* getUrl()
    {
        return _url.c_str();
    };
    
<<<<<<< HEAD
    /** 
     * Set the request data of HttpRequest object.
     *
     * @param buffer the buffer of request data, it support binary data.
     * @param len    the size of request data.
=======
    /** Option field. You can set your post data here
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setRequestData(const char* buffer, size_t len)
    {
        _requestData.assign(buffer, buffer + len);
    };
<<<<<<< HEAD
    /** 
     * Get the request data pointer of HttpRequest object.
     *
     * @return char* the request data pointer.
     */
=======
    /** Get the request data pointer back */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline char* getRequestData()
    {
        if(_requestData.size() != 0)
            return &(_requestData.front());

        return nullptr;
    }
<<<<<<< HEAD
    /** 
     * Get the size of request data
     *
     * @return ssize_t the size of request data
     */
=======
    /** Get the size of request data back */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline ssize_t getRequestDataSize()
    {
        return _requestData.size();
    }
    
<<<<<<< HEAD
    /** 
     * Set a string tag to identify your request.
     * This tag can be found in HttpResponse->getHttpRequest->getTag().
     *
     * @param tag the string pointer
=======
    /** Option field. You can set a string tag to identify your request, this tag can be found in HttpResponse->getHttpRequest->getTag()
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setTag(const char* tag)
    {
        _tag = tag;
    };
<<<<<<< HEAD
    /** 
     * Get the string tag to identify the request.
     * The best practice is to use it in your MyClass::onMyHttpRequestCompleted(sender, HttpResponse*) callback.
     *
     * @return const char* the pointer of _tag
=======
    /** Get the string tag back to identify the request. 
        The best practice is to use it in your MyClass::onMyHttpRequestCompleted(sender, HttpResponse*) callback
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline const char* getTag()
    {
        return _tag.c_str();
    };
    
<<<<<<< HEAD
    /**
     * Set user-customed data of HttpRequest object.
     * You can attach a customed data in each request, and get it back in response callback.
     * But you need to new/delete the data pointer manully.
     *
     * @param pUserData the string pointer
=======
    /** Option field. You can attach a customed data in each request, and get it back in response callback.
        But you need to new/delete the data pointer manully
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setUserData(void* pUserData)
    {
        _pUserData = pUserData;
    };
<<<<<<< HEAD
    /** 
     * Get the user-customed data pointer which were pre-setted.
     * Don't forget to delete it. HttpClient/HttpResponse/HttpRequest will do nothing with this pointer.
     *
     * @return void* the pointer of user-customed data.
=======
    /** Get the pre-setted custom data pointer back.
        Don't forget to delete it. HttpClient/HttpResponse/HttpRequest will do nothing with this pointer
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void* getUserData()
    {
        return _pUserData;
    };
    
<<<<<<< HEAD
    /**
     * Set the target and related callback selector.
     * When response come back, it would call (pTarget->*pSelector) to process something.
     *
     * @param pTarget the target object pointer.
     * @param pSelector the callback function.
=======
    /** Required field. You should set the callback selector function at ack the http request completed
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    CC_DEPRECATED_ATTRIBUTE inline void setResponseCallback(Ref* pTarget, SEL_CallFuncND pSelector)
    {
        setResponseCallback(pTarget, (SEL_HttpResponse) pSelector);
    }
<<<<<<< HEAD
    
    /**
     * Set the target and related callback selector of HttpRequest object.
     * When response come back, we would call (pTarget->*pSelector) to process response data.
     *
     * @param pTarget the target object pointer.
     * @param pSelector the SEL_HttpResponse function.
     */
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE inline void setResponseCallback(Ref* pTarget, SEL_HttpResponse pSelector)
    {
        _pTarget = pTarget;
        _pSelector = pSelector;
        
        if (_pTarget)
        {
            _pTarget->retain();
        }
    }
<<<<<<< HEAD
    /**
     * Set response callback function of HttpRequest object.
     * When response come back, we would call _pCallback to process response data.
     *
     * @param callback the ccHttpRequestCallback function.
     */
=======
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setResponseCallback(const ccHttpRequestCallback& callback)
    {
        _pCallback = callback;
    }
    
<<<<<<< HEAD
    /** 
     * Get the target of callback selector funtion, mainly used by HttpClient.
     *
     * @return Ref* the target of callback selector funtion
     */
=======
    /** Get the target of callback selector funtion, mainly used by HttpClient */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline Ref* getTarget()
    {
        return _pTarget;
    }

<<<<<<< HEAD
    /**
     * This sub class is just for migration SEL_CallFuncND to SEL_HttpResponse,someday this way will be removed.
     * 
     * @lua NA
     */
    class _prxy
    {
    public:
        /** Constructor. */
        _prxy( SEL_HttpResponse cb ) :_cb(cb) {}
        /** Destructor. */
        ~_prxy(){};
        /** Destructor. */
=======
    /* This sub class is just for migration SEL_CallFuncND to SEL_HttpResponse, 
       someday this way will be removed */
    class _prxy
    {
    public:
        _prxy( SEL_HttpResponse cb ) :_cb(cb) {}
        ~_prxy(){};
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        operator SEL_HttpResponse() const { return _cb; }
        CC_DEPRECATED_ATTRIBUTE operator SEL_CallFuncND()   const { return (SEL_CallFuncND) _cb; }
    protected:
        SEL_HttpResponse _cb;
    };
    
<<<<<<< HEAD
    /** 
     * Get _prxy object by the _pSelector.
     *
     * @return _prxy the _prxy object
     */
=======
    /** Get the selector function pointer, mainly used by HttpClient */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline _prxy getSelector()
    {
        return _prxy(_pSelector);
    }
    
<<<<<<< HEAD
    /**
     * Get ccHttpRequestCallback callback function.
     *
     * @return const ccHttpRequestCallback& ccHttpRequestCallback callback function.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline const ccHttpRequestCallback& getCallback()
    {
        return _pCallback;
    }
    
<<<<<<< HEAD
    /** 
     * Set custom-defined headers.
     *
     * @param pHeaders the string vector of custom-defined headers.
     */
=======
    /** Set any custom headers **/
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setHeaders(std::vector<std::string> pHeaders)
   	{
   		_headers=pHeaders;
   	}
   
<<<<<<< HEAD
    /** 
     * Get custom headers.
     *
     * @return std::vector<std::string> the string vector of custom-defined headers.
     */
=======
    /** Get custom headers **/
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
   	inline std::vector<std::string> getHeaders()
   	{
   		return _headers;
   	}
    
protected:
    // properties
    Type                        _requestType;    /// kHttpRequestGet, kHttpRequestPost or other enums
    std::string                 _url;            /// target url that this request is sent to
    std::vector<char>           _requestData;    /// used for POST
    std::string                 _tag;            /// user defined tag, to identify different requests in response callback
    Ref*                        _pTarget;        /// callback target of pSelector function
    SEL_HttpResponse            _pSelector;      /// callback function, e.g. MyLayer::onHttpResponse(HttpClient *sender, HttpResponse * response)
    ccHttpRequestCallback       _pCallback;      /// C++11 style callbacks
    void*                       _pUserData;      /// You can add your customed data here 
    std::vector<std::string>    _headers;		      /// custom http headers
};

}

NS_CC_END

<<<<<<< HEAD
// end group
/// @}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif //__HTTP_REQUEST_H__
