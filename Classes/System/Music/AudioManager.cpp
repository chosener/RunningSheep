//
//  AudioManager.cpp
//  MagicTouch
//
//  Created by SaiDong on 28/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "AudioManager.h"

static AudioManager* m_AudioManager = nullptr;

AudioManager::AudioManager()
{
    
}

AudioManager::~AudioManager()
{
    
}

AudioManager* AudioManager::getInstance()
{
    if(m_AudioManager == nullptr)
    {
        m_AudioManager = new AudioManager();
        //初始化
        if (m_AudioManager && m_AudioManager->init()) {
            m_AudioManager->autorelease();
            m_AudioManager->retain();
        }
    }
    return m_AudioManager;
}

bool AudioManager::init()
{

    return true;
}
void AudioManager::loadAllMusic()
{
    DLog::d(">>>>>[AudioManager::loadAllMusic()]");
    bool bIsOpenMusic = true;
    bool bIsOpenSound = true;
    
<<<<<<< HEAD
    int chanelGame = DSConfig::getInstance()->getiChannelGame();
    
    switch (chanelGame)
    {
        case En_ChannelGame_1:
        {
            //咪咕
            bool isEnable = getMusicEnable();
            DLog::d("Music Enable",getMusicEnable());
            //bIsOpenMusic = UserDefault::getInstance()->getBoolForKey("music_open", isEnable);
            //bIsOpenSound = UserDefault::getInstance()->getBoolForKey("sound_open", isEnable);
            bIsOpenMusic = isEnable;
            bIsOpenSound = isEnable;
        }
            break;
        case En_ChannelGame_0:
        case En_ChannelGame_100:
        {
            bIsOpenMusic = UserDefault::getInstance()->getBoolForKey("music_open", true);
            bIsOpenSound = UserDefault::getInstance()->getBoolForKey("sound_open", true);
        }
            break;
            
        default:
            break;
    }
=======
    bIsOpenMusic = UserDefault::getInstance()->getBoolForKey("music_open", true);
    bIsOpenSound = UserDefault::getInstance()->getBoolForKey("sound_open", true);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    setbIsOpenMusic(bIsOpenMusic);
    setbIsOpenSound(bIsOpenSound);
    
    /* 例子 */
    preLoadBgMusic(bgMusic);
    preLoadSound(testSound);
    
<<<<<<< HEAD
=======
#if 0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    auto musicOptionListener = EventListenerCustom::create("event_option_music", CC_CALLBACK_1(AudioManager::onEventOptionMusic, this));
    //添加自定义事件监听器，优先权为1
    EVENT_DISPATCHER->addEventListenerWithFixedPriority(musicOptionListener, 1);
    
    auto soundOptionListener = EventListenerCustom::create("event_option_sound", CC_CALLBACK_1(AudioManager::onEventOptionSound, this));
    //添加自定义事件监听器，优先权为1
    EVENT_DISPATCHER->addEventListenerWithFixedPriority(soundOptionListener, 1);
    
<<<<<<< HEAD
=======
#endif
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    setbgMusic(bgMusic);
}


/*********************************************************
 一些方法的封装
 *********************************************************/
void AudioManager::preLoadBgMusic(Music& music)
{

    //music.musicFilePath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(music.musicFilePath);
    
    //CCLOG(music.musicFilePath);
    
    if(music.musicFilePath == NULL || music.musicFilePath[0] == '\0')
        return;
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(music.musicFilePath);
}

void AudioManager::preLoadSound(Sound& sound)
{
    
    if(sound.soundFilePath == NULL || sound.soundFilePath[0] == '\0')
        return;
    
    //sound.soundFilePath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(sound.soundFilePath);
    
    SimpleAudioEngine::getInstance()->preloadEffect(sound.soundFilePath);
}

void AudioManager::playMusic(Music& music,bool loop/* default = true */)
{
    if(music.musicFilePath == NULL || music.musicFilePath[0] == '\0')
        return;
    bool bIsOpenMusic = getbIsOpenMusic();
    if(!bIsOpenMusic)
        return;
    /* 先判断是否已经在播放,如果在播放，则直接返回 */
    if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
        return;
    }
    
    SimpleAudioEngine::getInstance()->playBackgroundMusic(music.musicFilePath, loop);
    
    setbgMusic(music);
}


void AudioManager::playSound(Sound& sound,bool loop/* default is false */)
{
    if(sound.soundFilePath == NULL || sound.soundFilePath[0] == '\0')
        return;
    
    bool bIsOpenSound = getbIsOpenSound();
    if(!bIsOpenSound)
        return;
    
    sound.soundId = SimpleAudioEngine::getInstance()->playEffect(sound.soundFilePath, loop);
}

void AudioManager::playMusic(int _index,bool loop/* default = true */)
{
<<<<<<< HEAD
    InfoSound* infoSound = DataManager::getInstance()->getInfoSoundType(_index);
    
    string path = infoSound->path;
=======
#if 0
    InfoSound* infoSound = DataManager::getInstance()->getInfoSoundType(_index);
    
    string path = infoSound->path;
#endif
    string path = "";
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    Music music = {path.c_str()};
    
    if(music.musicFilePath == NULL || music.musicFilePath[0] == '\0')
        return;
    bool bIsOpenMusic = getbIsOpenMusic();
    if(!bIsOpenMusic)
        return;
    /* 先判断是否已经在播放,如果在播放，则直接返回 */
    if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
        return;
    }
    
    SimpleAudioEngine::getInstance()->playBackgroundMusic(music.musicFilePath, loop);
    
    setbgMusic(music);
}


void AudioManager::playSound(int _index,bool loop/* default is false */)
{
<<<<<<< HEAD
=======
#if 0
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    InfoSound* infoSound = DataManager::getInstance()->getInfoSoundType(_index);
    
    unsigned int id = infoSound->id;
    
    string path = infoSound->path;
<<<<<<< HEAD
=======
#endif
    unsigned int id = 0;
    
    string path = "";
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    Sound sound = {id,path.c_str()};
    
    if(sound.soundFilePath == NULL || sound.soundFilePath[0] == '\0')
        return;
    
    bool bIsOpenSound = getbIsOpenSound();
    if(!bIsOpenSound)
        return;
    
    sound.soundId = SimpleAudioEngine::getInstance()->playEffect(sound.soundFilePath, loop);
}


void AudioManager::pauseMusic(Music& music)
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}
void AudioManager::pauseMusic()
{
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AudioManager::pauseSound(Sound& sound)
{
    SimpleAudioEngine::getInstance()->pauseEffect(sound.soundId);
}

void AudioManager::pauseAllSound()
{
    SimpleAudioEngine::getInstance()->pauseAllEffects();

}
void AudioManager::resumeAllSound()
{
    SimpleAudioEngine::getInstance()->resumeAllEffects();
}

void AudioManager::stopMusic(Music& music,bool release/* default is true */)
{
    SimpleAudioEngine::getInstance()->stopBackgroundMusic(release);
}

void AudioManager::stopSound(Sound& sound)
{
    SimpleAudioEngine::getInstance()->stopEffect(sound.soundId);
}

void AudioManager::stopAllSound()
{
    SimpleAudioEngine::getInstance()->stopAllEffects();
}

void AudioManager::resumeMusic()
{
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->rewindBackgroundMusic();//从头播放
}

void AudioManager::end()
{
    SimpleAudioEngine::getInstance()->end();
}
///事件音乐设置
void AudioManager::onEventOptionMusic(EventCustom* event)
{
    bool isOpen = event->getUserData();
    setbIsOpenMusic(isOpen);
<<<<<<< HEAD
    UserDefault::getInstance()->setBoolForKey(s_music_open, isOpen);
=======
    UserDefault::getInstance()->setBoolForKey("s_music_open", isOpen);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    DLog::d("music isOpen", isOpen);
    
    //设置背景音乐
    if(isOpen)
    {
        resumeMusic();
    }
    else
    {
        pauseMusic();
    }
    
    setbIsOpenMusic(isOpen);
}
///事件音效设置
void AudioManager::onEventOptionSound(EventCustom* event)
{
    bool isOpen = event->getUserData();
    setbIsOpenSound(isOpen);
<<<<<<< HEAD
    UserDefault::getInstance()->setBoolForKey(s_sound_open, isOpen);
=======
    UserDefault::getInstance()->setBoolForKey("s_sound_open", isOpen);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    DLog::d("sound isOpen", isOpen);
    
    //设置音效
    if(isOpen)
    {
        resumeAllSound();
    }
    else
    {
        pauseAllSound();
    }

    setbIsOpenSound(isOpen);
}















