//
//  SceneManager.cpp
//  MagicTouch
//
//  Created by SaiDong on 24/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "SceneManager.h"
//#include "TowerPosEditorScene.h"
//#include "TollgateScene.h"
//#include "TollgateSelectScene.h"
//#include "WinScene.h"
//#include "GameOverScene.h"
//#include "../Scene/Logo/LogoLayer.h"
//#include "../Scene/Logo/TestLayer.h"
//#include "../Scene/MainMenu/MainMenuLayer.h"
//#include "../Scene/MainMenu/LoadingLayer.h"
//#include "../Scene/MainMenu/PassLayer.h"
//#include "../Scene/MainMenu/DSPassLayer.h"
//#include "../Scene/Game/GameLayer.h"
//#include "../Scene/MainMenu/DSPropertyLayer.h"
//#include "../Scene/Store/DSPanelGoldCoin.h"
//#include "../Scene/Store/DSPanelPet.h"
//#include "../Scene/Store/DSPanelProperty.h"
//#include "../Scene/Store/DSLayerStore.h"
//#include "../Scene/MainMenu/Option/DSLayerOption.h"
//#include "../Scene/MainMenu/Mode/DSLayerMode.h"
//#include "../Scene/Gift/LayerGift.h"
//#include "../Scene/Store/LayerMagician.h"
//#include "../Scene/Logo/DSLayerKengDie.h"
#include "../../Framework/GameHeader.h"

SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::getInstance() {
    if(mSceneManager == NULL) {
        mSceneManager = new SceneManager();
        if(mSceneManager && mSceneManager->init()) {
            mSceneManager->autorelease();
            mSceneManager->retain();
        }
        else {
            CC_SAFE_DELETE(mSceneManager);
            mSceneManager = NULL;
        }
    }
    
    return mSceneManager;
}

bool SceneManager::init() {
    
    return true;
}

void SceneManager::changeScene( EnumSceneType enScenType )
{
    Scene* pScene = NULL;
    
    switch (enScenType)
    {
        case en_SceneKengDie:
            //pScene = DSLayerKengDie::createScene();
            break;
        case en_GameLogo:
            break;
        case en_GameStart:
        {
            pScene = LayerStart::createScene();
        }
            break;
        case en_GameMainMenu:
        {
            pScene = LayerMainMenu::createScene();
        }
            break;
        case en_Loading:
            break;
        case en_GameScene:
        {
            pScene = LayerGame::createScene();
        }
            break;
        case en_TollgateEditorScene:

            break;
        case en_TollgateSelectScene:
            break;
        case en_WinScene:
            break;
        case en_GameOverScene:
            break;
        case en_SceneSelectProperty:
            break;
        case en_SceneStorePet:
            break;
        case en_SceneStoreProperty:
            break;
    }
    
    if(pScene == NULL) {
        return;
    }
    
    Director* pDirector = Director::getInstance();
    
    Scene* curScene = pDirector->getRunningScene();
    
    if(curScene == NULL)
    {
        pDirector->runWithScene(pScene);
    }
    else
    {
        pDirector->replaceScene(pScene);
    }
}

/* 切换场景 */
void SceneManager::changeLayer(EnumSceneType enScenType,Layer* _parent,int _zorder,int _tag,int index)
{
    
    if(_parent == NULL) {
        return;
    }
    
    switch (enScenType)
    {
        case en_GameLogo:
            /* 主菜单界面 */
            break;
        case en_GameMainMenu:
            /* 主菜单界面 */
            break;
        case en_Loading:
            /* loading界面 */
            break;
        case en_GameScene:
            /* 关卡场景 */
            break;
        case en_TollgateEditorScene:
            /* 关卡编辑器场景 */
            break;
        case en_TollgateSelectScene:
        {
            /* 关卡选择场景 */
        }
            break;
        case en_WinScene:
            /* 胜利场景 */
            break;
        case en_GameOverScene:
            /* 游戏结束场景 */
            break;
        case en_SceneSelectProperty:
        {
        }
            break;
        case en_SceneStorePet:
        {
            //DSPanelPet* layer = DSPanelPet::create();
            //_parent->addChild(layer,_zorder,_tag);
            //this->addLayerColor(_parent, layer, _zorder);
        }
            break;
        case en_SceneStoreProperty:
        {

        }
            break;
        case en_SceneStoreGoldCoin:
        {

        }
            break;
        case en_SceneStore:
        {

        }
            break;
        case en_SceneOption:
        {

        }
            break;
        case en_SceneGift:
        {
            //LayerGift* layer = LayerGift::create(index);
            //_parent->addChild(layer,_zorder,_tag);
            
            //登陆礼包时没有缩放效果
            //if(index == 0)
            //    return;
            //this->addActionScale(_parent, layer, _zorder);
        }
            break;
        case en_SceneMagician:
        {
            
        }
            break;
        default:
            break;
    }

}
/**加遮罩层*/
void SceneManager::addLayerColor(Layer* _parent,Layer* layer,int _zorder)
{
    _parent->addChild(LayerColor::create(Color4B(0, 0, 0, 100)),_zorder - 1,66666);
}
/**添加效果*/
void SceneManager::addActionScale(Layer* _parent,Layer* layer,int _zorder)
{
    _parent->addChild(LayerColor::create(Color4B(0, 0, 0, 200)),_zorder - 1,66666);
    
    layer->setScale(0.0f);
    
    ScaleTo* scaleTo0 = ScaleTo::create(0.1f, 1.05f);
    ScaleTo* scaleTo1 = ScaleTo::create(0.2f, 0.95f);
    ScaleTo* scaleTo2 = ScaleTo::create(0.2f, 1.02f);
    ScaleTo* scaleTo3 = ScaleTo::create(0.15f, 0.98f);
    ScaleTo* scaleTo4 = ScaleTo::create(0.15f, 1.0f);

    Sequence* seq = Sequence::create(scaleTo0,scaleTo1,scaleTo2,scaleTo3,scaleTo4, NULL);
    layer->runAction(seq);
}
/**层,移除场景*/
void SceneManager::removeLayer(Layer* _layer)
{
    _layer->removeFromParent();
}
