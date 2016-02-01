//
//  SheepBlack.h
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#ifndef SheepBlack_h
#define SheepBlack_h

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"

#include "Sheep.h"

///黑羊
class SheepBlack : public Sheep
{
public:
    SheepBlack();
    ~SheepBlack();
    
public:
    bool initWithIndex(int index,int camp);
    bool initWithFile(const char* name);
    bool initWithSpriteFrameName(const char* name);
    bool initWithFrameAnim(const char* name);

    
public:
    static SheepBlack* create(int index,int camp);
    static SheepBlack* create(const char* name);
    static SheepBlack* createWithSpriteFrameName(const char* name);
    static SheepBlack* createWithFrameAnim(const char* name);
    
    
    void playAction(int _indexAction);
private:
    
    void initView();
    void callBackAni(Node* node);
    
    void releaseSelf();
    
    void update(float dt);
private:
    string getNamePng(int index,int camp);
    string getNamePngHit(int index,int camp);
    Size getAnimSize(int index,int _indexAction = En_Action_Run);
    Size getCollideSize(int index,int _indexAction = En_Action_Run);
};

#endif /* SheepBlack_h */
