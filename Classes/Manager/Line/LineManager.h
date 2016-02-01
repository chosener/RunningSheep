//
//  LineManager.h
//  MagicTouch
//
//  Created by DongSai on 4/9/15.
//
//

#ifndef __MagicTouch__LineManager__
#define __MagicTouch__LineManager__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"
#include "../../Object/Sheep/SheepWhite.h"
#include "../../Object/Sheep/SheepBlack.h"
#include "../../Object/Line/Line.h"

class LineManager : public Ref
{
public:
    LineManager();
    ~LineManager();
    
    bool init();
    /**任务管理器的实例*/
    static LineManager* getInstance();
    
    void update(float dt);
    
    void addLineToLayer();
    
    void pushSheepIntoLine(int _line,SheepWhite* _sheep);
    void pushSheepIntoLine(int _line,SheepBlack* _sheep);
    
    void eraseSheepIntoLine(int _line,SheepWhite* _sheep);
    void eraseSheepIntoLine(int _line,SheepBlack* _sheep);
    
public:
    Line* getLine(int index);

private:
    Vector<Line*> m_vecLine;

    ///游戏层
    CC_SYNTHESIZE(Layer*, m_Layer, Layer);
};

#endif /* defined(__MagicTouch__LineManager__) */
