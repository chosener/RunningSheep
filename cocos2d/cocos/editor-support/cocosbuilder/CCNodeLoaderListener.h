#ifndef _CCB_CCNODELOADERLISTENER_H_
#define _CCB_CCNODELOADERLISTENER_H_


namespace cocosbuilder {

<<<<<<< HEAD
class CC_DLL NodeLoaderListener {
=======
class NodeLoaderListener {
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    public:
        /**
         * @js NA
         * @lua NA
         */
        virtual ~NodeLoaderListener() {};
        /**
         * @js NA
         * @lua NA
         */
        virtual void onNodeLoaded(cocos2d::Node * pNode, NodeLoader * pNodeLoader) = 0;
};

}

#endif
