//
//  TestManager.h
//  MagicTouch
//
//  Created by DongSai on 4/9/15.
//
//

#ifndef __MagicTouch__TestManager__
#define __MagicTouch__TestManager__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"


class TestManager : public Ref
{
public:
    TestManager();
    ~TestManager();
    
    bool init();
    /**任务管理器的实例*/
    static TestManager* getInstance();
    
    void update(float dt);

    
private:

};

#endif /* defined(__MagicTouch__TestManager__) */
