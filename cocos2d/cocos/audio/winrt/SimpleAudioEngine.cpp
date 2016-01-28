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

=======
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
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#include "SimpleAudioEngine.h"
#include "Audio.h"

#include <map>
<<<<<<< HEAD
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
//#include "CCCommon.h"
using namespace std;

namespace CocosDenshion {

<<<<<<< HEAD
Audio* s_audioController = NULL;
bool s_initialized = false;

SimpleAudioEngine* SimpleAudioEngine::getInstance()
{
    static SimpleAudioEngine s_SharedEngine;
    return &s_SharedEngine;
}


static Audio* sharedAudioController()
{
    if (! s_audioController || !s_initialized)
    {
        if(s_audioController == NULL)
        {
            s_audioController = new Audio;
        }
        s_audioController->Initialize();
        s_audioController->CreateResources();
        s_initialized = true;
=======


Audio* s_audioController = NULL;
// a flag that if the s_audioController should be re-initialiezed
// see also in SimpleAudioEngine::end() in this file
bool s_bAudioControllerNeedReInitialize = true;

static Audio* sharedAudioController()
{
    if ((! s_audioController) || s_bAudioControllerNeedReInitialize)
    {
        s_audioController = new Audio;
        s_audioController->Initialize();
        s_audioController->CreateResources();
		s_bAudioControllerNeedReInitialize = false;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    }

    return s_audioController;
}

SimpleAudioEngine::SimpleAudioEngine()
{
}

SimpleAudioEngine::~SimpleAudioEngine()
{
}

<<<<<<< HEAD
=======
SimpleAudioEngine* SimpleAudioEngine::sharedEngine()
{
    static SimpleAudioEngine s_SharedEngine;
    return &s_SharedEngine;
}
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

void SimpleAudioEngine::end()
{
    sharedAudioController()->StopBackgroundMusic(true);
<<<<<<< HEAD
    sharedAudioController()->StopAllSoundEffects(true);
    sharedAudioController()->ReleaseResources();
    s_initialized = false;
}


=======
    sharedAudioController()->StopAllSoundEffects();
    sharedAudioController()->ReleaseResources();
	//set here to tell the s_bAudioControllerNeedReInitialize should be re-initialized
	s_bAudioControllerNeedReInitialize = true;
}


#if 0
void SimpleAudioEngine::render()
{
    sharedAudioController()->Render();
}
#endif

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

//////////////////////////////////////////////////////////////////////////
// BackgroundMusic
//////////////////////////////////////////////////////////////////////////

void SimpleAudioEngine::playBackgroundMusic(const char* pszFilePath, bool bLoop)
{
    if (! pszFilePath)
    {
        return;
    }

    sharedAudioController()->PlayBackgroundMusic(pszFilePath, bLoop);
}

void SimpleAudioEngine::stopBackgroundMusic(bool bReleaseData)
{
    sharedAudioController()->StopBackgroundMusic(bReleaseData);
}

void SimpleAudioEngine::pauseBackgroundMusic()
{
    sharedAudioController()->PauseBackgroundMusic();
}

void SimpleAudioEngine::resumeBackgroundMusic()
{
    sharedAudioController()->ResumeBackgroundMusic();
}

void SimpleAudioEngine::rewindBackgroundMusic()
{
    sharedAudioController()->RewindBackgroundMusic();
}

bool SimpleAudioEngine::willPlayBackgroundMusic()
{
    return false;
}

bool SimpleAudioEngine::isBackgroundMusicPlaying()
{
    return sharedAudioController()->IsBackgroundMusicPlaying();
}

//////////////////////////////////////////////////////////////////////////
// effect function
//////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
unsigned int SimpleAudioEngine::playEffect(const char* pszFilePath, bool bLoop,float pitch, float pan, float gain)
{
    unsigned int sound;
    sharedAudioController()->PlaySoundEffect(pszFilePath, bLoop, sound);
    // TODO: need to support playEffect parameters
=======
unsigned int SimpleAudioEngine::playEffect(const char* pszFilePath, bool bLoop)
{
    unsigned int sound;
    sharedAudioController()->PlaySoundEffect(pszFilePath, bLoop, sound);

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    return sound;
}

void SimpleAudioEngine::stopEffect(unsigned int nSoundId)
{
    sharedAudioController()->StopSoundEffect(nSoundId);
}

void SimpleAudioEngine::preloadEffect(const char* pszFilePath)
{
    sharedAudioController()->PreloadSoundEffect(pszFilePath);
}

void SimpleAudioEngine::pauseEffect(unsigned int nSoundId)
{
    sharedAudioController()->PauseSoundEffect(nSoundId);
}

void SimpleAudioEngine::resumeEffect(unsigned int nSoundId)
{
    sharedAudioController()->ResumeSoundEffect(nSoundId);
}

void SimpleAudioEngine::pauseAllEffects()
{
    sharedAudioController()->PauseAllSoundEffects();
}

void SimpleAudioEngine::resumeAllEffects()
{
    sharedAudioController()->ResumeAllSoundEffects();
}

void SimpleAudioEngine::stopAllEffects()
{
<<<<<<< HEAD
    sharedAudioController()->StopAllSoundEffects(false);
=======
    sharedAudioController()->StopAllSoundEffects();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void SimpleAudioEngine::preloadBackgroundMusic(const char* pszFilePath)
{
<<<<<<< HEAD
    UNUSED_PARAM(pszFilePath);
=======

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
}

void SimpleAudioEngine::unloadEffect(const char* pszFilePath)
{
    sharedAudioController()->UnloadSoundEffect(pszFilePath);
}

//////////////////////////////////////////////////////////////////////////
// volume interface
//////////////////////////////////////////////////////////////////////////

float SimpleAudioEngine::getBackgroundMusicVolume()
{
    return sharedAudioController()->GetBackgroundVolume();
}

void SimpleAudioEngine::setBackgroundMusicVolume(float volume)
{
	sharedAudioController()->SetBackgroundVolume((volume<=0.0f)? 0.0f : volume);
}

float SimpleAudioEngine::getEffectsVolume()
{
    return sharedAudioController()->GetSoundEffectVolume();
}

void SimpleAudioEngine::setEffectsVolume(float volume)
{
    sharedAudioController()->SetSoundEffectVolume((volume<=0.0f)? 0.0f : volume);
}

} // end of namespace CocosDenshion
