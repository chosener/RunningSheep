/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2013-2014 Chukong Technologies

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

#ifndef __MATH_CCGEOMETRY_H__
#define __MATH_CCGEOMETRY_H__

#include <math.h>
<<<<<<< HEAD

#include "platform/CCPlatformMacros.h"
#include "base/ccMacros.h"
#include "math/CCMath.h"

/**
 * @addtogroup base
 * @{
 */

NS_CC_BEGIN

class CC_DLL Size
{
public:
    /**Width of the Size.*/
    float width;
    /**Height of the Size.*/
    float height;
public:
    /**Conversion from Vec2 to Size.*/
=======
#include <functional>

#include "base/CCPlatformMacros.h"
#include "base/ccMacros.h"
#include "math/CCMath.h"

NS_CC_BEGIN

/**
 * @addtogroup data_structures
 * @{
 */

class CC_DLL Size
{
public:
    float width;
    float height;
public:
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    operator Vec2() const
    {
        return Vec2(width, height);
    }

public:
    /**
<<<<<<< HEAD
    @{
    Constructor.
    @param width Width of the size.
    @param height Height of the size.
    @param other Copy constructor.
    @param point Conversion from a point.
     */
    Size();
    Size(float width, float height);
    Size(const Size& other);
    explicit Size(const Vec2& point);
    /**@}*/

=======
     * @js NA
     */
    Size();
    /**
     * @js NA
     */
    Size(float width, float height);
    /**
     * @js NA
     * @lua NA
     */
    Size(const Size& other);
    /**
     * @js NA
     * @lua NA
     */
    explicit Size(const Vec2& point);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    /**
     * @js NA
     * @lua NA
     */
    Size& operator= (const Size& other);
    /**
     * @js NA
     * @lua NA
     */
    Size& operator= (const Vec2& point);
    /**
     * @js NA
     * @lua NA
     */
    Size operator+(const Size& right) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator-(const Size& right) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator*(float a) const;
    /**
     * @js NA
     * @lua NA
     */
    Size operator/(float a) const;
    /**
<<<<<<< HEAD
    Set the width and height of Size.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    void setSize(float width, float height);
    /**
<<<<<<< HEAD
    Check if two size is the same.
     * @js NA
     */
    bool equals(const Size& target) const;
    /**Size(0,0).*/
    static const Size ZERO;
};

/**Rectangle area.*/
class CC_DLL Rect
{
public:
    /**Low left point of rect.*/
    Vec2 origin;
    /**Width and height of the rect.*/
=======
     * @js NA
     */
    bool equals(const Size& target) const;
    
    static const Size ZERO;
};

class CC_DLL Rect
{
public:
    Vec2 origin;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    Size  size;

public:
    /**
<<<<<<< HEAD
    Constructor an empty Rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    Rect();
    /**
<<<<<<< HEAD
    Constructor a rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    Rect(float x, float y, float width, float height);
    /**
<<<<<<< HEAD
    Copy constructor.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    Rect(const Rect& other);
    /**
     * @js NA
     * @lua NA
     */
    Rect& operator= (const Rect& other);
    /**
<<<<<<< HEAD
    Set the x, y, width and height of Rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    void setRect(float x, float y, float width, float height);
    /**
<<<<<<< HEAD
    Get the left of the rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMinX() const; /// return the leftmost x-value of current rect
    /**
<<<<<<< HEAD
    Get the X coordinate of center point.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMidX() const; /// return the midpoint x-value of current rect
    /**
<<<<<<< HEAD
    Get the right of rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMaxX() const; /// return the rightmost x-value of current rect
    /**
<<<<<<< HEAD
    Get the bottom of rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMinY() const; /// return the bottommost y-value of current rect
    /**
<<<<<<< HEAD
    Get the Y coordinate of center point.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMidY() const; /// return the midpoint y-value of current rect
    /**
<<<<<<< HEAD
    Get top of rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    float getMaxY() const; /// return the topmost y-value of current rect
    /**
<<<<<<< HEAD
    Compare two rects.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    bool equals(const Rect& rect) const;
    /**
<<<<<<< HEAD
    Check if the points is contained in the rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    bool containsPoint(const Vec2& point) const;
    /**
<<<<<<< HEAD
    Check the intersect status of two rects.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     */
    bool intersectsRect(const Rect& rect) const;
    /**
<<<<<<< HEAD
    Check the intersect status of the rect and a circle.
     * @js NA
     */
    bool intersectsCircle(const Vec2& center, float radius) const;
    /**
    Get the min rect which can contain this and rect.
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
     * @js NA
     * @lua NA
     */
    Rect unionWithRect(const Rect & rect) const;
<<<<<<< HEAD
    /**Compute the min rect which can contain this and rect, assign it to this.*/
    void merge(const Rect& rect);
    /**An empty Rect.*/
    static const Rect ZERO;
};

NS_CC_END

// end of base group
/// @}

=======
    
    static const Rect ZERO;
};

// end of data_structure group
/// @}

NS_CC_END

>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
#endif // __MATH_CCGEOMETRY_H__
