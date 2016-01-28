#ifndef _CCB_CCMENULOADER_H_
#define _CCB_CCMENULOADER_H_

#include "CCLayerLoader.h"
#include "base/CCRef.h"
#include "2d/CCMenu.h"

namespace cocosbuilder {

/* Forward declaration. */
class CCBReader;

<<<<<<< HEAD
class CC_DLL MenuLoader : public LayerLoader {
=======
class MenuLoader : public LayerLoader {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~MenuLoader() {};
    /**
     * @js NA
     * @lua NA
     */
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLoader, loader);

protected:
    virtual cocos2d::Menu * createNode(cocos2d::Node * pParent, cocosbuilder::CCBReader * ccbReader)
    {
        cocos2d::Menu * pMenu = cocos2d::Menu::create();
        
        pMenu->setContentSize(cocos2d::Size::ZERO);
        
        return pMenu;
    }
};

}

#endif
