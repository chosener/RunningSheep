//
//  SceneManager.h
//  MagicTouch
//
//  Created by SaiDong on 24/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#ifndef __MagicTouch__SceneManager__
#define __MagicTouch__SceneManager__

#include <stdio.h>

#include "../../Framework/CocosHead.h"
//#include "GlobalHead.h"

/****************************************************************************/
/****************************************************************************/
//场景管理器
/****************************************************************************/
/****************************************************************************/
class SceneManager : public Ref
{
public:
   /* 场景枚举类 */
    enum EnumSceneType
    {
        en_GameLogo,                /*Logo界面*/
<<<<<<< HEAD
=======
        en_GameStart,
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        en_GameMainMenu,            /*主菜单界面*/
        en_Loading,                 /*Loading*/
        en_GameScene,                     /* 关卡场景 */
        en_TollgateEditorScene,         /* 关卡编辑器场景 */
		en_WinScene,                        /* 胜利场景 */
		en_GameOverScene,              /* 游戏结束场景 */
		en_TollgateSelectScene,         /* 关卡选择场景 */
        en_SceneSelectProperty,
        en_SceneStorePet,  /*宠物商店*/
        en_SceneStoreProperty, /*道具商店*/
        en_SceneStoreGoldCoin, /*金币商店*/
        en_SceneStore,     /*商店界面*/
        en_SceneOption,     /*设置界面*/
        en_SceneGift, /*大礼包界面*/
        en_SceneMagician,/*魔法师选择界面*/
        en_SceneKengDie,/**弹出的三屏*/
    };
    
    /* 获取场景管理器对象 */
    static SceneManager* getInstance();
    
   /* 初始化 */
    virtual bool init();
    
    /* 切换场景 */
    void changeScene(EnumSceneType enScenType);
    
    /* 切换场景 */
    void changeLayer(EnumSceneType enScenType,Layer* _parent,int _zorder,int _tag = 1,int index = -1);
    
    /**层,移除场景*/
    void removeLayer(Layer* _layer);
    
    /**添加效果*/
    void addActionScale(Layer* _parent,Layer* layer,int _zorder);
    /**加遮罩层*/
    void addLayerColor(Layer* _parent,Layer* layer,int _zorder);
    
private:
    /* 场景管理器对象 */
    static SceneManager* mSceneManager;
};


#endif /* defined(__MagicTouch__SceneManager__) */
