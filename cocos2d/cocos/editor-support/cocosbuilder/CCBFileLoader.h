#ifndef _CCB_CCBFILELOADER_H_
#define _CCB_CCBFILELOADER_H_

#include "CCNodeLoader.h"
<<<<<<< HEAD
=======
#include "CCBReader.h"
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

<<<<<<< HEAD
class CC_DLL CCBFileLoader : public NodeLoader {
=======
class CCBFileLoader : public NodeLoader {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~CCBFileLoader() {};
        /**
         * @js NA
         * @lua NA
         */
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCBFileLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCBFile);

        virtual void onHandlePropTypeCCBFile(cocos2d::Node * pNode, cocos2d::Node * pParent, const char * pPropertyName, cocos2d::Node * pCCBFileNode, CCBReader * ccbReader);
};

}

#endif
