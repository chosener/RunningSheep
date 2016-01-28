/****************************************************************************
 Copyright (c) 2012      greathqy
 Copyright (c) 2012      cocos2d-x.org
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

<<<<<<< HEAD
#ifndef __CCHTTPCLIENT_H__
#define __CCHTTPCLIENT_H__

#include "network/HttpRequest.h"
#include "network/HttpResponse.h"

/**
 * @addtogroup core
 * @{
 */

NS_CC_BEGIN

namespace network {

/** Singleton that handles asynchrounous http requests.
 *
 * Once the request completed, a callback will issued in main thread when it provided during make request.
 *
 * @lua NA
 */
class CC_DLL HttpClient
{
public:
    /**
     * Get instance of HttpClient.
     *
     * @return the instance of HttpClient.
     */
    static HttpClient *getInstance();
    
    /** 
     * Relase the instance of HttpClient. 
     */
    static void destroyInstance();

    /** 
     * Enable cookie support.
     *
     * @param cookieFile the filepath of cookie file.
     */
    void enableCookies(const char* cookieFile);
    
    /**
     * Set root certificate path for SSL verification.
     *
     * @param caFile a full path of root certificate.if it is empty, SSL verification is disabled.
     */
    void setSSLVerification(const std::string& caFile);
        
    /**
     * Add a get request to task queue
     *
=======
#ifndef __CCHTTPREQUEST_H__
#define __CCHTTPREQUEST_H__

#include "network/HttpRequest.h"
#include "network/HttpResponse.h"
#include "network/HttpClient.h"

NS_CC_BEGIN

namespace network {

/**
 * @addtogroup Network
 * @{
 */


/** @brief Singleton that handles asynchrounous http requests
 * Once the request completed, a callback will issued in main thread when it provided during make request
 */
class HttpClient
{
public:
    /** Return the shared instance **/
    static HttpClient *getInstance();
    
    /** Relase the shared instance **/
    static void destroyInstance();

    /** Enable cookie support. **/
    void enableCookies(const char* cookieFile);
        
    /**
     * Add a get request to task queue
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @param request a HttpRequest object, which includes url, response callback etc.
                      please make sure request->_requestData is clear before calling "send" here.
     */
    void send(HttpRequest* request);

    /**
     * Immediate send a request
<<<<<<< HEAD
     *
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @param request a HttpRequest object, which includes url, response callback etc.
                      please make sure request->_requestData is clear before calling "sendImmediate" here.
     */
    void sendImmediate(HttpRequest* request);
  
    
    /**
<<<<<<< HEAD
     * Set the timeout value for connecting.
     *
     * @param value the timeout value for connecting.
=======
     * Change the connect timeout
     * @param value The desired timeout.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setTimeoutForConnect(int value) {_timeoutForConnect = value;};
    
    /**
<<<<<<< HEAD
     * Get the timeout value for connecting.
     *
     * @return int the timeout value for connecting.
=======
     * Get connect timeout
     * @return int
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline int getTimeoutForConnect() {return _timeoutForConnect;}
    
    
    /**
<<<<<<< HEAD
     * Set the timeout value for reading.
     *
     * @param value the timeout value for reading.
=======
     * Change the download timeout
     * @param value
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline void setTimeoutForRead(int value) {_timeoutForRead = value;};
    

    /**
<<<<<<< HEAD
     * Get the timeout value for reading.
     *
     * @return int the timeout value for reading.
=======
     * Get download timeout
     * @return int
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    inline int getTimeoutForRead() {return _timeoutForRead;};
        
private:
    HttpClient();
    virtual ~HttpClient();
    bool init(void);
    
    /**
     * Init pthread mutex, semaphore, and create new thread for http requests
     * @return bool
     */
    bool lazyInitThreadSemphore();
    void networkThread();
<<<<<<< HEAD
    void networkThreadAlone(HttpRequest* request, HttpResponse* response);
=======
    void networkThreadAlone(HttpRequest* request);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /** Poll function called from main thread to dispatch callbacks when http requests finished **/
    void dispatchResponseCallbacks();
    
private:
    int _timeoutForConnect;
    int _timeoutForRead;
};

<<<<<<< HEAD
=======
// end of Network group
/// @}

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

NS_CC_END

<<<<<<< HEAD
// end group
/// @}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif //__CCHTTPREQUEST_H__
