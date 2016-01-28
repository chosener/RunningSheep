/****************************************************************************
Copyright (c) 2013-2014 Chukong Technologies Inc.

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

#ifndef __UILABELATLAS_H__
#define __UILABELATLAS_H__

#include "ui/UIWidget.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

NS_CC_BEGIN

/**
 * @addtogroup ui
 * @{
 */

=======

NS_CC_BEGIN

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
class Label;

namespace ui {
    
/**
<<<<<<< HEAD
 * @brief UI TextAtlas widget.
 */
class CC_GUI_DLL TextAtlas : public Widget
=======
 *   @js NA
 *   @lua NA
 */
class TextAtlas : public Widget
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
    /**
<<<<<<< HEAD
     * Default constructor.
     *
     * @lua new
=======
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    TextAtlas();
    
    /**
<<<<<<< HEAD
     * Default destructor.
     *
     * @lua NA
=======
     * Default destructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~TextAtlas();
    
    /**
<<<<<<< HEAD
     * Create a TexAtlas object.
     *
     * @return An autoreleased TextAtlas object.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static TextAtlas* create();
    
    /**
<<<<<<< HEAD
     * Create a LabelAtlas from a char map file.
     *
     * @param stringValue A given string needs to be displayed.
     * @param charMapFile A given char map file name.
     * @param itemWidth The element width.
     * @param itemHeight The element height.
     * @param startCharMap The starting char of the atlas.
     * @return An autoreleased TextAtlas object.
=======
     * create a LabelAtlas from a char map file
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static TextAtlas* create(const std::string& stringValue,
                             const std::string& charMapFile,
                             int itemWidth,
                             int itemHeight,
                             const std::string& startCharMap);
    
<<<<<<< HEAD
    /** Initializes the LabelAtlas with a string, a char map file(the atlas), the width and height of each element and the starting char of the atlas.
     *
     * @param stringValue A given string needs to be displayed.
     * @param charMapFile A given char map file name.
     * @param itemWidth The element width.
     * @param itemHeight The element height.
     * @param startCharMap The starting char of the atlas.
     */
    
=======
    /** initializes the LabelAtlas with a string, a char map file(the atlas), the width and height of each element and the starting char of the atlas */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void setProperty(const std::string& stringValue,
                     const std::string& charMapFile,
                     int itemWidth,
                     int itemHeight,
                     const std::string& startCharMap);
    
<<<<<<< HEAD
    /**Set string value for labelatlas.
     *
     * @param value A given string needs to be displayed.
     */
    CC_DEPRECATED_ATTRIBUTE void setStringValue(const std::string& value){this->setString(value);}
    void setString(const std::string& value);
    
    /**Get string value for labelatlas.
     *
     * @return The string value of TextAtlas.
     */
=======
    //set string value for labelatlas.
    CC_DEPRECATED_ATTRIBUTE void setStringValue(const std::string& value){this->setString(value);}
    void setString(const std::string& value);
    
    //get string value for labelatlas.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    CC_DEPRECATED_ATTRIBUTE const std::string& getStringValue() const{return this->getString();}
    const std::string& getString() const;
    
    /**
     * Gets the string length of the label.
     * Note: This length will be larger than the raw string length,
     * if you want to get the raw string length, you should call this->getString().size() instead
     *
     * @return  string length.
     */
    ssize_t getStringLength()const;
    
    //override "getVirtualRendererSize" method of widget.
<<<<<<< HEAD
    virtual Size getVirtualRendererSize() const override;
=======
    virtual const Size& getVirtualRendererSize() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    //override "getVirtualRenderer" method of widget.
    virtual Node* getVirtualRenderer() override;
    
    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;
    
<<<<<<< HEAD
    /**
     * @js NA
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void adaptRenderers() override;
protected:
    virtual void initRenderer() override;
    virtual void onSizeChanged() override;
  
    void labelAtlasScaleChangedWithSize();
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
protected:
    Label* _labelAtlasRenderer;
    std::string _stringValue;
    std::string _charMapFileName;
    int _itemWidth;
    int _itemHeight;
    std::string _startCharMap;
    bool _labelAtlasRendererAdaptDirty;
};

}
<<<<<<< HEAD

// end of ui group
/// @}

=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END

#endif /* defined(__CocoGUI__LabelAtlas__) */
