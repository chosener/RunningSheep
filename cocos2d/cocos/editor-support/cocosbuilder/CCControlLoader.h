#ifndef _CCB_CCCONTROLLOADER_H_
#define _CCB_CCCONTROLLOADER_H_

#include "CCNodeLoader.h"
#include "extensions/GUI/CCControlExtension/CCControl.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

<<<<<<< HEAD
class CC_DLL ControlLoader : public NodeLoader {
=======
class ControlLoader : public NodeLoader {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
public:
    /**
    * @js NA
    * @lua NA
    */
    virtual ~ControlLoader() {};

protected:
    CCB_PURE_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(cocos2d::extension::Control);

    virtual void onHandlePropTypeBlockControl(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, BlockControlData * pBlockControlData, CCBReader * ccbReader);
    virtual void onHandlePropTypeCheck(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, bool pCheck, CCBReader * ccbReader);
};

}

#endif
