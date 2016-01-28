/****************************************************************************
Copyright (c) 2010-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.

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
#include "platform/CCPlatformConfig.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
#include "platform/winrt/CCGLViewImpl-winrt.h"
using namespace Windows::UI::Core;
using namespace Windows::Foundation;

#else
#include "platform/wp8/CCGLViewImpl-wp8.h"
=======
#include "CCApplication.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
#include "platform/winrt/CCGLView.h"
#else
#include "platform/wp8/CCGLView.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif
#include "base/CCDirector.h"
#include <algorithm>
#include "platform/CCFileUtils.h"
#include "CCWinRTUtils.h"

/**
@brief    This function change the PVRFrame show/hide setting in register.
@param  bEnable If true show the PVRFrame window, otherwise hide.
*/

NS_CC_BEGIN

// sharedApplication pointer
Application * Application::sm_pSharedApplication = 0;





////////////////////////////////////////////////////////////////////////////////
// implement Application
////////////////////////////////////////////////////////////////////////////////

// sharedApplication pointer
Application * s_pSharedApplication = 0;

<<<<<<< HEAD
Application::Application() :
m_openURLDelegate(nullptr)
=======
Application::Application()
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    m_nAnimationInterval.QuadPart = 0;
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

Application::~Application()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = NULL;
}

int Application::run()
{
    // Initialize instance and cocos2d.
    if (!applicationDidFinishLaunching())
    {
        return 0;
    }

<<<<<<< HEAD
	GLViewImpl::sharedOpenGLView()->Run();
=======
	GLView::sharedOpenGLView()->Run();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
	return 0;
}

void Application::setAnimationInterval(double interval)
{
    LARGE_INTEGER nFreq;
    QueryPerformanceFrequency(&nFreq);
    m_nAnimationInterval.QuadPart = (LONGLONG)(interval * nFreq.QuadPart);
}

//////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////
Application* Application::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

const char * Application::getCurrentLanguageCode()
{
<<<<<<< HEAD
	static std::string code = "en";

#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
    auto languages = Windows::System::UserProfile::GlobalizationPreferences::Languages;
    code = PlatformStringToString(languages->GetAt(0));
#else
    ULONG numLanguages = 0;
    DWORD cchLanguagesBuffer = 0;
    BOOL result = GetUserPreferredUILanguages(MUI_LANGUAGE_NAME, &numLanguages, NULL, &cchLanguagesBuffer);

    if (result) {
        WCHAR* pwszLanguagesBuffer = new WCHAR[cchLanguagesBuffer];
        result = GetUserPreferredUILanguages(MUI_LANGUAGE_NAME, &numLanguages, pwszLanguagesBuffer, &cchLanguagesBuffer);
        if (result) {

            code = CCUnicodeToUtf8(pwszLanguagesBuffer);
        }

        if (pwszLanguagesBuffer)
        {
            delete pwszLanguagesBuffer;
        }
    }


#endif
=======
	static std::string code = "";

    wchar_t localeName[LOCALE_NAME_MAX_LENGTH] = {0};
    if (GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH))
    {
        wchar_t* primary = wcstok(localeName, L"-");
        code = CCUnicodeToUtf8(primary);
    }
    else
    {
        code = "en";
    }

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return code.c_str();
}


LanguageType Application::getCurrentLanguage()
{
    LanguageType ret = LanguageType::ENGLISH;
<<<<<<< HEAD
    
    const char* code = getCurrentLanguageCode();
    
    if (strncmp(code, "zh", 2) == 0)
    {
        ret = LanguageType::CHINESE;
    }
    else if (strncmp(code, "ja", 2) == 0)
    {
        ret = LanguageType::JAPANESE;
    }
    else if (strncmp(code, "fr", 2) == 0)
    {
        ret = LanguageType::FRENCH;
    }
    else if (strncmp(code, "it", 2) == 0)
    {
        ret = LanguageType::ITALIAN;
    }
    else if (strncmp(code, "de", 2) == 0)
    {
        ret = LanguageType::GERMAN;
    }
    else if (strncmp(code, "es", 2) == 0)
    {
        ret = LanguageType::SPANISH;
    }
    else if (strncmp(code, "nl", 2) == 0)
    {
        ret = LanguageType::DUTCH;
    }
    else if (strncmp(code, "ru", 2) == 0)
    {
        ret = LanguageType::RUSSIAN;
    }
    else if (strncmp(code, "hu", 2) == 0)
    {
        ret = LanguageType::HUNGARIAN;
    }
    else if (strncmp(code, "pt", 2) == 0)
    {
        ret = LanguageType::PORTUGUESE;
    }
    else if (strncmp(code, "ko", 2) == 0)
    {
        ret = LanguageType::KOREAN;
    }
    else if (strncmp(code, "ar", 2) == 0)
    {
        ret = LanguageType::ARABIC;
    }
    else if (strncmp(code, "nb", 2) == 0)
    {
        ret = LanguageType::NORWEGIAN;
    }
    else if (strncmp(code, "pl", 2) == 0)
    {
        ret = LanguageType::POLISH;
    }
    else if (strncmp(code, "tr", 2) == 0)
    {
        ret = LanguageType::TURKISH;
    }
    else if (strncmp(code, "uk", 2) == 0)
    {
        ret = LanguageType::UKRAINIAN;
    }
    else if (strncmp(code, "ro", 2) == 0)
    {
        ret = LanguageType::ROMANIAN;
    }
    else if (strncmp(code, "bg", 2) == 0)
    {
        ret = LanguageType::BULGARIAN;
    }
=======

    const char* code = getCurrentLanguageCode();

    if (strcmp(code, "zh") == 0)
    {
        ret = LanguageType::CHINESE;
    }
    else if (strcmp(code, "ja") == 0)
    {
        ret = LanguageType::JAPANESE;
    }
    else if (strcmp(code, "fr") == 0)
    {
        ret = LanguageType::FRENCH;
    }
    else if (strcmp(code, "it") == 0)
    {
        ret = LanguageType::ITALIAN;
    }
    else if (strcmp(code, "de") == 0)
    {
        ret = LanguageType::GERMAN;
    }
    else if (strcmp(code, "es") == 0)
    {
        ret = LanguageType::SPANISH;
    }
    else if (strcmp(code, "nl") == 0)
    {
        ret = LanguageType::DUTCH;
    }
    else if (strcmp(code, "ru") == 0)
    {
        ret = LanguageType::RUSSIAN;
    }
    else if (strcmp(code, "hu") == 0)
    {
        ret = LanguageType::HUNGARIAN;
    }
    else if (strcmp(code, "pt") == 0)
    {
        ret = LanguageType::PORTUGUESE;
    }
    else if (strcmp(code, "ko") == 0)
    {
        ret = LanguageType::KOREAN;
    }
    else if (strcmp(code, "ar") == 0)
    {
        ret = LanguageType::ARABIC;
    } 

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return ret;
}

Application::Platform  Application::getTargetPlatform()
{
    return Platform::OS_WP8;
}

<<<<<<< HEAD
bool Application::openURL(const std::string &url)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
    auto dispatcher = cocos2d::GLViewImpl::sharedOpenGLView()->getDispatcher();
    dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new DispatchedHandler([url]() {
        auto uri = ref new Windows::Foundation::Uri(PlatformStringFromString(url));
        concurrency::task<bool> launchUriOperation(Windows::System::Launcher::LaunchUriAsync(uri));
    }));
    return true;
#else
    if (m_openURLDelegate)
    {
        m_openURLDelegate(PlatformStringFromString(url));
        return true;
    }
    else
    {
        return false;
    }
#endif
}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
void Application::setResourceRootPath(const std::string& rootResDir)
{
    m_resourceRootPath = rootResDir;
    std::replace(m_resourceRootPath.begin(), m_resourceRootPath.end(), '\\', '/');
    if (m_resourceRootPath[m_resourceRootPath.length() - 1] != '/')
    {
        m_resourceRootPath += '/';
    }
    FileUtils* pFileUtils = FileUtils::getInstance();
    std::vector<std::string> searchPaths = pFileUtils->getSearchPaths();
    searchPaths.insert(searchPaths.begin(), m_resourceRootPath);
    pFileUtils->setSearchPaths(searchPaths);
}

const std::string& Application::getResourceRootPath(void)
{
    return m_resourceRootPath;
}

void Application::setStartupScriptFilename(const std::string& startupScriptFile)
{
    m_startupScriptFilename = startupScriptFile;
    std::replace(m_startupScriptFilename.begin(), m_startupScriptFilename.end(), '\\', '/');
}

NS_CC_END


