//
//  AudioManager.h
//  MagicTouch
//
//  Created by SaiDong on 28/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#ifndef __MagicTouch__AudioManager__
#define __MagicTouch__AudioManager__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
//#include "../../Common/GlobalDefine.h"
//#include "../../Common/GlobalString.h"
//#include "../../Common/DSConfig.h"
#include "../../System/Debug/DLog.h"
//#include "../../Manager/DataManager.h"
#include "../../System/Sms/JniSms.h"

/*音乐管理*/

typedef struct {
    unsigned int soundId;
    const char* soundFilePath;
}Sound;


typedef struct {
    const char* musicFilePath;
} Music;

/*
 * 注意，Andoird下面只支持.ogg
 *
 */

static Music bgMusic =
{
    "sounds/beijingyinyue.mp3"
};
static Sound testSound =
{
    0,
    "sounds/bianyangyinxiao.wma"
};

class AudioManager  : public Ref
{
public:
    AudioManager();
    ~AudioManager();
    
    /*  注意，此方法在进入游戏前调用  */
    bool init();
    
    static AudioManager* getInstance();
public:
    ///加载
    void loadAllMusic();
    
    /* 预加载 */
    void preLoadBgMusic(Music& music);
    void preLoadSound(Sound& sound);
    
    /* 播放 */
    void playMusic(Music& music,bool loop = true);
    void playSound(Sound& sound,bool loop = false);
    
    void playMusic(int _index,bool loop = true);
    void playSound(int _index,bool loop = false);
    
    /* 暂停 */
    void pauseMusic(Music& music);
    void pauseMusic();
    void pauseSound(Sound& sound);
    
    void pauseAllSound();
    
    /* 停止 */
    void stopMusic(Music& music,bool release = true);
    void stopSound(Sound& sound);
    void stopAllSound();

    
    /* 恢复 */
    void resumeMusic();
    
    void resumeAllSound();
    
    /* 全部结束 */
    void end();
    
    ///事件音乐设置
    void onEventOptionMusic(EventCustom* event);
    ///事件音效设置
    void onEventOptionSound(EventCustom* event);
    
    ///当前背景音乐
    CC_SYNTHESIZE(Music, m_bgMusic, bgMusic);
    
    ///是否开启音乐
    CC_SYNTHESIZE(bool, m_bIsOpenMusic, bIsOpenMusic);
    ///是否开启音效
    CC_SYNTHESIZE(bool, m_bIsOpenSound, bIsOpenSound);
};

#endif /* defined(__MagicTouch__AudioManager__) */