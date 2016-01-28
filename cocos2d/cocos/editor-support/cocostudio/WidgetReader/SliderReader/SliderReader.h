/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __TestCpp__SliderReader__
#define __TestCpp__SliderReader__

<<<<<<< HEAD
#include "cocostudio/WidgetReader/WidgetReader.h"
#include "cocostudio/CocosStudioExport.h"

namespace cocostudio
{
    class CC_STUDIO_DLL SliderReader : public WidgetReader
    {
        DECLARE_CLASS_NODE_READER_INFO
        
    public:
=======
#include "../WidgetReader.h"

namespace cocostudio
{
    class SliderReader : public WidgetReader
    {
    public:
        DECLARE_CLASS_WIDGET_READER_INFO
        
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
        SliderReader();
        virtual ~SliderReader();
        
        static SliderReader* getInstance();
<<<<<<< HEAD
        /** @deprecated Use method destroyInstance() instead */
        CC_DEPRECATED_ATTRIBUTE static void purge();
        static void destroyInstance();
        
        virtual void setPropsFromJsonDictionary(cocos2d::ui::Widget* widget, const rapidjson::Value& options);
        virtual void setPropsFromBinary(cocos2d::ui::Widget* widget, CocoLoader* cocoLoader,  stExpCocoNode*	pCocoNode) ;        
        flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
                                                                             flatbuffers::FlatBufferBuilder* builder);
        void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* sliderOptions);
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* sliderOptions);
        
        int getResourceType(std::string key);
=======
        static void purge();
        
        virtual void setPropsFromJsonDictionary(cocos2d::ui::Widget* widget, const rapidjson::Value& options);
        virtual void setPropsFromBinary(cocos2d::ui::Widget* widget, CocoLoader* cocoLoader,  stExpCocoNode*	pCocoNode) ;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

    };
}

#endif /* defined(__TestCpp__SliderReader__) */
