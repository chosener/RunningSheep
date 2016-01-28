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

#ifndef __UIIMAGEVIEW_H__
#define __UIIMAGEVIEW_H__

#include "ui/UIWidget.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

/**
 * @addtogroup ui
 * @{
 */
NS_CC_BEGIN

namespace ui {
    class Scale9Sprite;
/**
 * @brief A widget to display images.
 */
class CC_GUI_DLL ImageView : public Widget
=======

NS_CC_BEGIN

namespace ui {

/**
*   @js NA
*   @lua NA
*/
class ImageView : public Widget
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
    /**
     * Default constructor
<<<<<<< HEAD
     * @js ctor
     * @lua new
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    ImageView();

    /**
     * Default destructor
<<<<<<< HEAD
     * @js NA
     * @lua NA
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~ImageView();

    /**
<<<<<<< HEAD
     * Create a empty ImageView.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static ImageView* create();
    
    /**
<<<<<<< HEAD
     * Create a  imageview  with a image name.
     *
     * @param imageFileName   file name of texture.
     * @param texType    @see `Widget::TextureResType`
     * @return A ImageView instance.
=======
     * create a  imageview 
     *
     * @param imageFileName   file name of texture.
     *
     * @param texType    @see TextureResType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static ImageView* create(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL);
    

    /**
     * Load texture for imageview.
     *
     * @param fileName   file name of texture.
<<<<<<< HEAD
     * @param texType    @see `Widget::TextureResType`
=======
     *
     * @param texType    @see TextureResType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void loadTexture(const std::string& fileName,TextureResType texType = TextureResType::LOCAL);

    /**
     * Updates the texture rect of the ImageView in points.
     * It will call setTextureRect:rotated:untrimmedSize with rotated = NO, and utrimmedSize = rect.size.
     */
    void setTextureRect(const Rect& rect);

    /**
<<<<<<< HEAD
     * Enable scale9 renderer.
     *
     * @param enabled Set to true will use scale9 renderer, false otherwise.
     */
    void setScale9Enabled(bool enabled);

    /**
     * Query whether button is using scale9 renderer or not.
     *@return whether button use scale9 renderer or not.
     */
    bool isScale9Enabled()const;

    /**
     * Sets capInsets for imageview.
     * The capInsets affects the ImageView's renderer only if `setScale9Enabled(true)` is called.
=======
     * Sets if imageview is using scale9 renderer.
     *
     * @param able true that using scale9 renderer, false otherwise.
     */
    void setScale9Enabled(bool able);

    bool isScale9Enabled()const;

    /**
     * Sets capinsets for imageview, if imageview is using scale9 renderer.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     *
     * @param capInsets    capinsets for imageview
     */
    void setCapInsets(const Rect &capInsets);

<<<<<<< HEAD
    /**
     * Get ImageView's capInsets size.
     * @return Query capInsets size in Rect
     * @see `setCapInsets(const Rect&)`
     */
    const Rect& getCapInsets()const;

    //override methods.
    virtual void ignoreContentAdaptWithSize(bool ignore) override;
    virtual std::string getDescription() const override;
    virtual Size getVirtualRendererSize() const override;
=======
    const Rect& getCapInsets()const;

    //override "ignoreContentAdaptWithSize" method of widget.
    virtual void ignoreContentAdaptWithSize(bool ignore) override;

    /**
     * Returns the "class name" of widget.
     */
    virtual std::string getDescription() const override;

    virtual const Size& getVirtualRendererSize() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual Node* getVirtualRenderer() override;
    
CC_CONSTRUCTOR_ACCESS:
    //initializes state of widget.
    virtual bool init() override;
    virtual bool init(const std::string& imageFileName, TextureResType texType = TextureResType::LOCAL);

protected:
    virtual void initRenderer() override;
    virtual void onSizeChanged() override;
<<<<<<< HEAD
=======
  
    virtual void updateFlippedX() override;
    virtual void updateFlippedY() override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    
    virtual void adaptRenderers() override;
    
    void imageTextureScaleChangedWithSize();
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
protected:
    bool _scale9Enabled;
    bool _prevIgnoreSize;
    Rect _capInsets;
<<<<<<< HEAD
    Scale9Sprite* _imageRenderer;
=======
    Node* _imageRenderer;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    std::string _textureFile;
    TextureResType _imageTexType;
    Size _imageTextureSize;
    bool _imageRendererAdaptDirty;
};

}

NS_CC_END
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__CocoGUI__ImageView__) */
