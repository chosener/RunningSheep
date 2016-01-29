//
//  GlobalEnum.h
//  RunningSheep
//
//  Created by SaintKing on 1/29/16.
//
//

#ifndef GlobalEnum_h
#define GlobalEnum_h

///阵营
enum EnumCamp
{
    En_Camp_None,
    //队友
    En_Camp_Team,
    //敌方
    En_Camp_Enemy,
    En_Camp_Max,
};

///方向(朝向)
enum EnumDirection
{
    En_Direction_None,
    En_Direction_Left,
    En_Direction_Right,
    En_Direction_Max,
};

///类型
enum EnumSheepType
{
    En_SheepType_None,
    En_SheepType_High,
    En_SheepType_Big,
    En_SheepType_Normal,
    En_SheepType_Little,
    En_SheepType_Mini,
    En_SheepType_Max,
};

#endif /* GlobalEnum_h */
