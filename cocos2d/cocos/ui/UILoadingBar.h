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

#ifndef __UILOADINGBAR_H__
#define __UILOADINGBAR_H__

#include "ui/UIWidget.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

NS_CC_BEGIN
/**
 * @addtogroup ui
 * @{
 */

namespace ui {
    class Scale9Sprite;

/**
 *@brief Visual indicator of progress in some operation.
 * Displays a bar to the user representing how far the operation has progressed.
 *
 */
class CC_GUI_DLL LoadingBar : public Widget
=======

NS_CC_BEGIN

namespace ui {

/**
*   @js NA
*   @lua NA
*/
class LoadingBar : public Widget
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
{
    
    DECLARE_CLASS_GUI_INFO
    
public:
<<<<<<< HEAD
    /**
     * Loading bar progress direction.
     */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class Direction
    {
        LEFT,
        RIGHT
    };
<<<<<<< HEAD

    /**
     * Default constructor.
     * @js ctor
     * @lua new
=======
    /**
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    LoadingBar();
    
    /**
<<<<<<< HEAD
     * Default destructor.
     * @js NA
     * @lua NA
=======
     * Default destructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~LoadingBar();
    
    /**
<<<<<<< HEAD
     * Create an empty LoadingBar.
     *@return A LoadingBar instance.
     */
    static LoadingBar* create();
    
     
    /**
     * @brief Create a LoadingBar with a texture name and a predefined progress value.
     *
     * @param textureName LoadingBar background texture name.
     * @param percentage A percentage in float.
     * @return A LoadingBar instance.
     */
    static LoadingBar* create(const std::string& textureName, float percentage = 0);
    
    
    /**
     * @brief Create a LoadingBar with a texture name along with its texture type and a predefined progress value.
     *
     * @param textureName LoadingBar background texture name.
     * @param texType LoadingBar background texture type.
     * @param percentage A percentage in float, default value is 0.
     * @return A LoadingBar instance.
     */
    static LoadingBar* create(const std::string& textureName,
                              TextureResType texType,
                              float percentage = 0);
    
    /**
     * Change the progress direction of LoadingBar.
     *
     * @see Direction  `LEFT` means progress left to right, `RIGHT` otherwise.
=======
     * Allocates and initializes.
     */
    static LoadingBar* create();
    
    /**
     * create a LoadingBar with a texture and a percentage
     **/
    static LoadingBar* create(const std::string& textureName, float percentage = 0);
    
    /**
     * Changes the progress direction of loadingbar.
     *
     * @see Direction  LEFT means progress left to right, RIGHT otherwise.
     *
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @param direction Direction
     */
    void setDirection(Direction direction);
    
    /**
<<<<<<< HEAD
     * Get the progress direction of LoadingBar.
     *
     * @see Direction  `LEFT` means progress left to right, `RIGHT` otherwise.
     * @return LoadingBar progress direction.
=======
     * Gets the progress direction of loadingbar.
     *
     * @see Direction  LEFT means progress left to right, RIGHT otherwise.
     *
     * @return Direction
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    Direction getDirection()const;
    
    /**
<<<<<<< HEAD
     * Load texture for LoadingBar.
     *
     * @param texture   File name of texture.
     * @param texType   Texture resource type,@see TextureResType.
=======
     * Load texture for loadingbar.
     *
     * @param texture   file name of texture.
     *
     * @param texType    @see TextureResType
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void loadTexture(const std::string& texture,TextureResType texType = TextureResType::LOCAL);
    
    /**
<<<<<<< HEAD
     * Changes the progress value of LoadingBar.
     *
     * @param percent   Percent value from 1 to 100.
=======
     * Changes the progress direction of loadingbar.
     *
     * @param percent    percent value from 1 to 100.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setPercent(float percent);
    
    /**
<<<<<<< HEAD
     * Get the progress value of LoadingBar.
     *
     * @return Progress value from 1 to 100.
=======
     * Gets the progress direction of loadingbar.
     *
     * @return percent value from 1 to 100.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    float getPercent() const;
    
    /**
<<<<<<< HEAD
     * Enable scale9 renderer.
     *
     * @param enabled Set to true will use scale9 renderer, false otherwise.
     */
    void setScale9Enabled(bool enabled);
    
    
    /**
     * @brief Query whether LoadingBar is using scale9 renderer or not.
     * @return Whether LoadingBar uses scale9 renderer or not.
     */
    bool isScale9Enabled()const;
    
    /**
     * Set capInsets for LoadingBar.
     * This setting only take effect when enable scale9 renderer.
     * @param capInsets CapInset in `Rect`.
     */
    void setCapInsets(const Rect &capInsets);
    
    
    /**
     * @brief Query LoadingBar's capInsets.
     * @return CapInsets of LoadingBar.
     */
    const Rect& getCapInsets()const;
    
    //override methods.
    virtual void ignoreContentAdaptWithSize(bool ignore) override;
    virtual Size getVirtualRendererSize() const override;
    virtual Node* getVirtualRenderer() override;
=======
     * Sets if loadingbar is using scale9 renderer.
     *
     * @param enabled true that using scale9 renderer, false otherwise.
     */
    void setScale9Enabled(bool enabled);
    
    bool isScale9Enabled()const;
    
    /**
     * Sets capinsets for loadingbar, if loadingbar is using scale9 renderer.
     *
     * @param capInsets    capinsets for loadingbar
     */
    void setCapInsets(const Rect &capInsets);
    
    const Rect& getCapInsets()const;
    
    //override "ignoreContentAdaptWithSize" method of widget.
    virtual void ignoreContentAdaptWithSize(bool ignore) override;
    
    //override "getVirtualRendererSize" method of widget.
    virtual const Size& getVirtualRendererSize() const override;
    
    //override "getVirtualRenderer" method of widget.
    virtual Node* getVirtualRenderer() override;
    
    /**
     * Returns the "class name" of widget.
     */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual std::string getDescription() const override;
protected:
    virtual void initRenderer() override;
    virtual void onSizeChanged() override;
   
    void setScale9Scale();
<<<<<<< HEAD
    void updateProgressBar();
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    void barRendererScaleChangedWithSize();
    
    virtual void adaptRenderers() override;
    
    virtual Widget* createCloneInstance() override;
    virtual void copySpecialProperties(Widget* model) override;
protected:
    Direction _direction;
    float _percent;
    float _totalLength;
<<<<<<< HEAD
    Scale9Sprite* _barRenderer;
=======
    Node* _barRenderer;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    TextureResType _renderBarTexType;
    Size _barRendererTextureSize;
    bool _scale9Enabled;
    bool _prevIgnoreSize;
    Rect _capInsets;
    std::string _textureFile;
    bool _barRendererAdaptDirty;
};

}
<<<<<<< HEAD
// end of ui group
/// @}
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_END
#endif /* defined(__CocoGUI__LoadingBar__) */
