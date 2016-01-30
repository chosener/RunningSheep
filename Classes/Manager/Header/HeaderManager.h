//
//  HeaderManager.h
//  RunningSheep
//
//  Created by DongSai on 4/9/15.
//
//

#ifndef __RunningSheep__HeaderManager__
#define __RunningSheep__HeaderManager__

#include <stdio.h>
#include "../../Framework/CocosHead.h"
#include "../../Framework/GameHeader.h"

#include "../../Object/Header/Header.h"


///头像管理
class HeaderManager : public Ref
{
public:
    HeaderManager();
    ~HeaderManager();
    
    bool init();
    /**任务管理器的实例*/
    static HeaderManager* getInstance();
    
    void update(float dt);

    void addStartHeader();
    
    void removeHeaderFront(int camp);
private:
    void initVariables();
    ///添加头像(阵营,位置)
    void addHeader(int camp,int num);
    ///要生成哪一个头像
    int getHeaderIndex();
    ///生成这个头像的概率
    int getHeaderRate();
    ///头像位置
    Vec2 getPosHeader(int camp,int num);
    
    void setHeaderFrontOpen();
    
    void moveLeftHeader();
    void moveRightHeader();
    
    void callBackMove(Node* node);
private:
    ///左边头像组
    deque<Header*> m_dequeHeaderLeft;
    deque<Header*> m_dequeHeaderRight;
    ///游戏层
    CC_SYNTHESIZE(Layer*, m_Layer, Layer);
    ///左边组是不是被锁定
    CC_SYNTHESIZE(bool, m_HeadLeftLocked, HeadLeftLocked);
    ///右边组是不是被锁定
    CC_SYNTHESIZE(bool, m_HeadRightLocked, HeadRightLocked);
    ///是否开始
    CC_SYNTHESIZE(bool, m_bIsStart, bIsStart);
};

#endif /* defined(__RunningSheep__HeaderManager__) */
