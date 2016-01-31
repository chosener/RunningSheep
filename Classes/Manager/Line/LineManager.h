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


class LineManager : public Ref
{
public:
    LineManager();
    ~LineManager();
    
    bool init();
    /**任务管理器的实例*/
    static LineManager* getInstance();
    
    void update(float dt);

    
private:

};

#endif /* defined(__MagicTouch__LineManager__) */
