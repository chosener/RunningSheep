//
//  SheepWhite.h
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#ifndef SheepWhite_h
#define SheepWhite_h

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"

#include "Sheep.h"
///白羊
class SheepWhite : public Sheep
{
public:
    SheepWhite();
    ~SheepWhite();
public:
    bool initWithIndex(int index);
    bool initWithFile(const char* name);
    bool initWithSpriteFrameName(const char* name);
    bool initWithFrameAnim(const char* name);
    
public:
    static SheepWhite* create(int index);
    static SheepWhite* create(const char* name);
    static SheepWhite* createWithSpriteFrameName(const char* name);
    static SheepWhite* createWithFrameAnim(const char* name);
private:
    string getNamePng(int index,int camp);
private:

    void initView();
    
};

#endif /* SheepWhite_h */
