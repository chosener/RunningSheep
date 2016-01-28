#include "CCScale9SpriteLoader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

#define PROPERTY_CONTENTSIZE "contentSize"
#define PROPERTY_SPRITEFRAME "spriteFrame"
#define PROPERTY_COLOR "color"
#define PROPERTY_OPACITY "opacity"
#define PROPERTY_BLENDFUNC "blendFunc"
<<<<<<< HEAD
// TODO: Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
#define PROPERTY_PREFEREDSIZE "preferedSize"
=======
#define PROPERTY_PREFEREDSIZE "preferedSize" // TODO Should be "preferredSize". This is a typo in cocos2d-iphone, cocos2d-x and CocosBuilder!
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#define PROPERTY_INSETLEFT "insetLeft"
#define PROPERTY_INSETTOP "insetTop"
#define PROPERTY_INSETRIGHT "insetRight"
#define PROPERTY_INSETBOTTOM "insetBottom"

namespace cocosbuilder {

void Scale9SpriteLoader::onHandlePropTypeSpriteFrame(Node * pNode, Node * pParent, const char * pPropertyName, SpriteFrame * pSpriteFrame, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_SPRITEFRAME) == 0) {
<<<<<<< HEAD
        ((cocos2d::ui::Scale9Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
=======
        ((Scale9Sprite *)pNode)->setSpriteFrame(pSpriteFrame);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    } else {
        NodeLoader::onHandlePropTypeSpriteFrame(pNode, pParent, pPropertyName, pSpriteFrame, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeColor3(Node * pNode, Node * pParent, const char * pPropertyName, Color3B pColor3B, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_COLOR) == 0) {
<<<<<<< HEAD
        ((cocos2d::ui::Scale9Sprite *)pNode)->setColor(pColor3B);
=======
        ((Scale9Sprite *)pNode)->setColor(pColor3B);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    } else {
        NodeLoader::onHandlePropTypeColor3(pNode, pParent, pPropertyName, pColor3B, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeByte(Node * pNode, Node * pParent, const char * pPropertyName, unsigned char pByte, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_OPACITY) == 0) {
<<<<<<< HEAD
        ((cocos2d::ui::Scale9Sprite *)pNode)->setOpacity(pByte);
=======
        ((Scale9Sprite *)pNode)->setOpacity(pByte);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    } else {
        NodeLoader::onHandlePropTypeByte(pNode, pParent, pPropertyName, pByte, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeBlendFunc(Node * pNode, Node * pParent, const char * pPropertyName, BlendFunc pBlendFunc, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_BLENDFUNC) == 0) {
        // TODO Not exported by CocosBuilder yet!
        // ((Scale9Sprite *)pNode)->setBlendFunc(pBlendFunc);
    } else {
        NodeLoader::onHandlePropTypeBlendFunc(pNode, pParent, pPropertyName, pBlendFunc, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeSize(Node * pNode, Node * pParent, const char * pPropertyName, Size pSize, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CONTENTSIZE) == 0) {
        //((Scale9Sprite *)pNode)->setContentSize(pSize);
    } else if(strcmp(pPropertyName, PROPERTY_PREFEREDSIZE) == 0) {
<<<<<<< HEAD
        ((cocos2d::ui::Scale9Sprite *)pNode)->setPreferredSize(pSize);
=======
        ((Scale9Sprite *)pNode)->setPreferredSize(pSize);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    } else {
        NodeLoader::onHandlePropTypeSize(pNode, pParent, pPropertyName, pSize, ccbReader);
    }
}

void Scale9SpriteLoader::onHandlePropTypeFloat(Node * pNode, Node * pParent, const char * pPropertyName, float pFloat, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_INSETLEFT) == 0) {
<<<<<<< HEAD
        ((cocos2d::ui::Scale9Sprite *)pNode)->setInsetLeft(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETTOP) == 0) {
        ((cocos2d::ui::Scale9Sprite *)pNode)->setInsetTop(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETRIGHT) == 0) {
        ((cocos2d::ui::Scale9Sprite *)pNode)->setInsetRight(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETBOTTOM) == 0) {
        ((cocos2d::ui::Scale9Sprite *)pNode)->setInsetBottom(pFloat);
=======
        ((Scale9Sprite *)pNode)->setInsetLeft(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETTOP) == 0) {
        ((Scale9Sprite *)pNode)->setInsetTop(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETRIGHT) == 0) {
        ((Scale9Sprite *)pNode)->setInsetRight(pFloat);
    } else if(strcmp(pPropertyName, PROPERTY_INSETBOTTOM) == 0) {
        ((Scale9Sprite *)pNode)->setInsetBottom(pFloat);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    } else {
        NodeLoader::onHandlePropTypeFloat(pNode, pParent, pPropertyName, pFloat, ccbReader);
    }
}

}
