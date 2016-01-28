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

#ifndef __LAYOUTPARMETER_H__
#define __LAYOUTPARMETER_H__

#include <string>
#include "base/CCRef.h"
<<<<<<< HEAD
#include "ui/GUIExport.h"

/**
 * @addtogroup ui
 * @{
 */
=======


>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
NS_CC_BEGIN

namespace ui {

/**
<<<<<<< HEAD
 *@brief Margin of widget's in point. Margin value should be positive.
 *@lua NA
 */
class CC_GUI_DLL Margin
{
public:
    /**
     * Left margin.
     */
    float left;
    /**
     * Top margin.
     */
    float top;
    /**
     * Right margin.
     */
    float right;
    /**
     * Bottom margin.
     */
    float bottom;
    
public:
    /**
     * Default constructor.
     */
    Margin();

    /**
     * Construct a Margin instance with left, top, right and bottom margins.
     *@param l Left margin in float.
     *@param t Top margin in float.
     *@param r Right margin in float.
     *@param b Bottom margin in float.
     */
    Margin(float l, float t, float r, float b);

    /**
     * Copy constructor.
     */
    Margin(const Margin& other);

    /**
     * Copy assignment operator.
     */
    Margin& operator= (const Margin& other);

    /**
     * Change margin with left, top, right and bottom margin.
     *@param l Left margin in float.
     *@param t Top margin in float.
     *@param r Right margin in float.
     *@param b Bottom margin in float.
     */
    void setMargin(float l, float t, float r, float b);

    /**
     * Test equality of two margins.
     *@param target A Margin instance.
     *@return True if two margins are equal, false otherwise.
     */
    bool equals(const Margin& target) const;
    
    /**
     * A margin constant with all margins equal zero.
     */
=======
 *   @js NA
 *   @lua NA
 */
class Margin
{
public:
    float left;
    float top;
    float right;
    float bottom;
    
public:
    Margin();
    Margin(float l, float t, float r, float b);
    Margin(const Margin& other);
    Margin& operator= (const Margin& other);
    void setMargin(float l, float t, float r, float b);
    bool equals(const Margin& target) const;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static const Margin ZERO;

};


<<<<<<< HEAD
=======
/**
*   @js NA
*   @lua NA
*/

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
#ifdef RELATIVE
#undef RELATIVE
#endif
#endif

<<<<<<< HEAD
/**
 *@brief Base class for various LayoutParameter.
 */
class CC_GUI_DLL LayoutParameter : public Ref
{
public:
    /**
     *Layout parameter type.
     * There are mainly two types:
     * - Linear: Elements will  be arranged by margin.
     * - Relative: Elements will be arranged by margin and relative widget name.
     */
=======
class LayoutParameter : public Ref
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class Type
    {
        NONE = 0,
        LINEAR,
        RELATIVE
    };
    /**
<<<<<<< HEAD
     * Default constructor.
     *
     * @lua new
=======
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    LayoutParameter() : _margin(Margin())
    {
        _layoutParameterType = Type::NONE;
    };
    
    /**
<<<<<<< HEAD
     * Default destructor.
     * @lua NA
=======
     * Default destructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~LayoutParameter(){};
    
    /**
<<<<<<< HEAD
     * Create a empty LayoutParameter.
     * @return A autorelease LayoutParameter instance.
=======
     * Allocates and initializes.
     * @return A initialized LayoutParameter which is marked as "autorelease".
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    static LayoutParameter* create();
    
    /**
<<<<<<< HEAD
     * Set margin parameter for LayoutParameter.
     * 
     * @see Margin
=======
     * Sets Margin parameter for LayoutParameter.
     * 
     * @see Margin
     *
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @param margin
     */
    void setMargin(const Margin& margin);
    
    /**
<<<<<<< HEAD
     * Gets margin parameter of LayoutParameter.
     *
     * @see Margin
     * @return Margin of layout parameter.
=======
     * Gets Margin parameter of LayoutParameter.
     *
     * @see Margin
     *
     * @return const Margin&
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    const Margin& getMargin() const;
    
    /**
     * Gets LayoutParameterType of LayoutParameter.
     *
<<<<<<< HEAD
     * @see LayoutParameterType.
=======
     * @see LayoutParameterType
     *
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return LayoutParameterType
     */
    Type getLayoutType() const;
    
<<<<<<< HEAD
    /**
     * Create a copy of original LayoutParameter.
     *@return A LayoutParameter pointer.
     */
    LayoutParameter* clone();

    /**
     * Create a cloned instance of LayoutParameter.
     *@return A LayoutParameter pointer.
     */
    virtual LayoutParameter* createCloneInstance();
    
    /**
     * Copy all the member field from argument LayoutParameter to self.
     *@param model A LayoutParameter instance.
     */
=======
    LayoutParameter* clone();
    virtual LayoutParameter* createCloneInstance();
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void copyProperties(LayoutParameter* model);
protected:
    Margin _margin;
    Type _layoutParameterType;
};
    
<<<<<<< HEAD
/**
 * Protocol for getting a LayoutParameter.
 * Every element want to have layout parameter should inherit from this class.
 */
class CC_GUI_DLL LayoutParameterProtocol
{
public:
    /**
     * Default destructor.
     */
    virtual ~LayoutParameterProtocol(){}

    /**
     *
     *@return A LayoutParameter and its descendant pointer.
     */
=======
class LayoutParameterProtocol
{
public:
    LayoutParameterProtocol(){}
    virtual ~LayoutParameterProtocol(){}
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual LayoutParameter* getLayoutParameter() const= 0;
};

    
/**
<<<<<<< HEAD
 * @brief Linear layout parameter.
 * It is used by linear layout manager for arranging elements linearly.
 */
class CC_GUI_DLL LinearLayoutParameter : public LayoutParameter
{
public:
    /**
     * Linear gravity.
     */
=======
*   @js NA
*   @lua NA
*/
class LinearLayoutParameter : public LayoutParameter
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class LinearGravity
    {
        NONE,
        LEFT,
        TOP,
        RIGHT,
        BOTTOM,
        CENTER_VERTICAL,
        CENTER_HORIZONTAL
    };
<<<<<<< HEAD

    /**
     * Default constructor.
     *
     * @lua new
=======
    /**
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    LinearLayoutParameter()
    : _linearGravity(LinearGravity::NONE)
    {
        _layoutParameterType = Type::LINEAR;
    };
    
    /**
<<<<<<< HEAD
     * Default destructor.
     *
     * @lua NA
=======
     * Default destructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~LinearLayoutParameter(){};
    
    /**
<<<<<<< HEAD
     * Create a empty LinearLayoutParameter instance.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return A initialized LayoutParameter which is marked as "autorelease".
     */
    static LinearLayoutParameter* create();
    
    /**
     * Sets LinearGravity parameter for LayoutParameter.
     *
     * @see LinearGravity
<<<<<<< HEAD
     * @param gravity Gravity in LinearGravity.
=======
     *
     * @param LinearGravity
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setGravity(LinearGravity gravity);
    
    /**
     * Gets LinearGravity parameter for LayoutParameter.
     *
     * @see LinearGravity
<<<<<<< HEAD
     * @return LinearGravity
     */
    LinearGravity getGravity() const;

    //override functions.
=======
     *
     * @return LinearGravity
     */
    LinearGravity getGravity() const;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual LayoutParameter* createCloneInstance() override;
    virtual void copyProperties(LayoutParameter* model) override;
protected:
    LinearGravity _linearGravity;
<<<<<<< HEAD
    int i;
};
    
    

/**
 * @brief Relative layout parameter.
 * It is mainly used by  `RelativeLayoutManager`.
 */
class CC_GUI_DLL RelativeLayoutParameter : public LayoutParameter
{
public:
    /**
     * Relative Alignment type
     */
=======
};
    
    
/**
*   @js NA
*   @lua NA
*/

    
class RelativeLayoutParameter : public LayoutParameter
{
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    enum class RelativeAlign
    {
        NONE,
        PARENT_TOP_LEFT,
        PARENT_TOP_CENTER_HORIZONTAL,
        PARENT_TOP_RIGHT,
        PARENT_LEFT_CENTER_VERTICAL,
        
        CENTER_IN_PARENT,
        
        PARENT_RIGHT_CENTER_VERTICAL,
        PARENT_LEFT_BOTTOM,
        PARENT_BOTTOM_CENTER_HORIZONTAL,
        PARENT_RIGHT_BOTTOM,
        
        LOCATION_ABOVE_LEFTALIGN,
        LOCATION_ABOVE_CENTER,
        LOCATION_ABOVE_RIGHTALIGN,
        LOCATION_LEFT_OF_TOPALIGN,
        LOCATION_LEFT_OF_CENTER,
        LOCATION_LEFT_OF_BOTTOMALIGN,
        LOCATION_RIGHT_OF_TOPALIGN,
        LOCATION_RIGHT_OF_CENTER,
        LOCATION_RIGHT_OF_BOTTOMALIGN,
        LOCATION_BELOW_LEFTALIGN,
        LOCATION_BELOW_CENTER,
        LOCATION_BELOW_RIGHTALIGN
    };
<<<<<<< HEAD

    /**
     * Default constructor
     *
     * @lua new
=======
    /**
     * Default constructor
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    RelativeLayoutParameter()
    : _relativeAlign(RelativeAlign::NONE),
    _relativeWidgetName(""),
    _relativeLayoutName(""),
    _put(false)
    {
        _layoutParameterType = Type::RELATIVE;
    };
    
    /**
     * Default destructor
<<<<<<< HEAD
     *
     * @lua NA
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    virtual ~RelativeLayoutParameter(){};
    
    /**
<<<<<<< HEAD
     * Create a RelativeLayoutParameter instance.
=======
     * Allocates and initializes.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @return A initialized LayoutParameter which is marked as "autorelease".
     */
    static RelativeLayoutParameter* create();
    
    /**
     * Sets RelativeAlign parameter for LayoutParameter.
     *
     * @see RelativeAlign
<<<<<<< HEAD
     * @param align Relative align in  `RelativeAlign`.
=======
     *
     * @param RelativeAlign
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setAlign(RelativeAlign align);
    
    /**
<<<<<<< HEAD
     * Get RelativeAlign parameter for LayoutParameter.
     *
     * @see RelativeAlign
     * @return  A RelativeAlign variable.
=======
     * Gets RelativeAlign parameter for LayoutParameter.
     *
     * @see RelativeAlign
     *
     * @return RelativeAlign
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    RelativeAlign getAlign() const;
    
    /**
<<<<<<< HEAD
     * Set widget name your widget want to relative to.
     *
     * @param name Relative widget name.
=======
     * Sets a key for LayoutParameter. Witch widget named this is relative to.
     *
     * @param name
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setRelativeToWidgetName(const std::string& name);
    
    /**
<<<<<<< HEAD
     * Get the relative widget name.
     * @return name A relative widget name in string.
=======
     * Gets the key of LayoutParameter. Witch widget named this is relative to.
     *
     * @return name
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    const std::string& getRelativeToWidgetName() const;
    
    /**
<<<<<<< HEAD
     * Set a name for LayoutParameter in Relative Layout.
     *
     * @param name A string name.
=======
     * Sets a name in Relative Layout for LayoutParameter.
     *
     * @param name
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     */
    void setRelativeName(const std::string& name);
    
    /**
<<<<<<< HEAD
     * Get a name of LayoutParameter in Relative Layout.
     *
     * @return name Relative name in string.
     */
    const std::string& getRelativeName() const;
    
    //override functions.
=======
     * Gets a name in Relative Layout of LayoutParameter.
     *
     * @return name
     */
    const std::string& getRelativeName() const;
    
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual LayoutParameter* createCloneInstance() override;
    virtual void copyProperties(LayoutParameter* model) override;
protected:
    RelativeAlign _relativeAlign;
    std::string _relativeWidgetName;
    std::string _relativeLayoutName;
    bool _put;
    friend class RelativeLayoutManager;
};

}
<<<<<<< HEAD
NS_CC_END
// end of ui group
/// @}
=======

NS_CC_END
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

#endif /* defined(__LayoutParameter__) */
