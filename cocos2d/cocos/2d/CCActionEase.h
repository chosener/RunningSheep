/****************************************************************************
Copyright (c) 2008-2009 Jason Booth
Copyright (c) 2010-2012 cocos2d-x.org
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

#ifndef __ACTION_CCEASE_ACTION_H__
#define __ACTION_CCEASE_ACTION_H__

#include "2d/CCActionInterval.h"

NS_CC_BEGIN

/**
 * @addtogroup actions
 * @{
 */

/** 
<<<<<<< HEAD
 @class ActionEase
 @brief Base class for Easing actions.
 @details Ease actions are created from other interval actions.
         The ease action will change the timeline of the inner action.
=======
 @brief Base class for Easing actions
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL ActionEase : public ActionInterval
{
public:

<<<<<<< HEAD
    /**
    @brief Get the pointer of the inner action.
    @return The pointer of the inner action.
    */
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual ActionInterval* getInnerAction();

    //
    // Overrides
    //
<<<<<<< HEAD
    virtual ActionEase* clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
    
    virtual ActionEase* reverse() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }

=======
	virtual ActionEase* clone() const override = 0;
    virtual ActionEase* reverse() const override = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    virtual void startWithTarget(Node *target) override;
    virtual void stop() override;
    virtual void update(float time) override;

CC_CONSTRUCTOR_ACCESS:
    ActionEase() {}
    virtual ~ActionEase();
<<<<<<< HEAD
    /** 
     @brief Initializes the action.
     @return Return true when the initialization success, otherwise return false.
    */
=======
    /** initializes the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithAction(ActionInterval *action);

protected:
    /** The inner action */
    ActionInterval *_inner;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(ActionEase);
};

/** 
<<<<<<< HEAD
 @class EaseRateAction
 @brief Base class for Easing actions with rate parameters.
 @details Ease the inner action with specified rate.
=======
 @brief Base class for Easing actions with rate parameters
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseRateAction : public ActionEase
{
public:
<<<<<<< HEAD
    /**
     @brief Set the rate value for the ease rate action.
     @param rate The value will be set.
     */
    inline void setRate(float rate) { _rate = rate; }
    /**
     @brief Get the rate value of the ease rate action.
     @return Return the rate value of the ease rate action.
     */
=======
    /** set rate value for the actions */
    inline void setRate(float rate) { _rate = rate; }
    /** get rate value for the actions */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline float getRate() const { return _rate; }

    //
    // Overrides
    //
<<<<<<< HEAD
    virtual EaseRateAction* clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
    virtual EaseRateAction* reverse() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
=======
	virtual EaseRateAction* clone() const override = 0;
    virtual EaseRateAction* reverse() const override = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseRateAction() {}
    virtual ~EaseRateAction();
<<<<<<< HEAD
    /** 
     @brief Initializes the action with the inner action and the rate parameter.
     @param pAction The pointer of the inner action.
     @param fRate The value of the rate parameter.
     @return Return true when the initialization success, otherwise return false.
     */
=======
    /** Initializes the action with the inner action and the rate parameter */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithAction(ActionInterval *pAction, float fRate);

protected:
    float _rate;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseRateAction);
};

/** 
<<<<<<< HEAD
 @class EaseIn
 @brief EaseIn action with a rate.
 @details The timeline of inner action will be changed by:
         \f${ time }^{ rate }\f$.
=======
 @brief EaseIn action with a rate
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseIn : public EaseRateAction
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action and the rate parameter.
     @param action The pointer of the inner action.
     @param rate The value of the rate parameter.
     @return A pointer of EaseIn action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the rate parameter */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseIn* create(ActionInterval* action, float rate);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseIn* clone() const override;
    virtual EaseIn* reverse() const override;
=======
	virtual EaseIn* clone() const override;
	virtual EaseIn* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseIn() {}
    virtual ~EaseIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseIn);
};

/** 
<<<<<<< HEAD
 @class EaseOut
 @brief EaseOut action with a rate.
 @details The timeline of inner action will be changed by:
         \f${ time }^ { (1/rate) }\f$.
=======
 @brief EaseOut action with a rate
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseOut : public EaseRateAction
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action and the rate parameter.
     @param action The pointer of the inner action.
     @param rate The value of the rate parameter.
     @return A pointer of EaseOut action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the rate parameter */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseOut* create(ActionInterval* action, float rate);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseOut* clone() const  override;
    virtual EaseOut* reverse() const  override;
=======
	virtual EaseOut* clone() const  override;
	virtual EaseOut* reverse() const  override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseOut() {}
    virtual ~EaseOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseOut);
};

/** 
<<<<<<< HEAD
 @class EaseInOut
 @brief EaseInOut action with a rate
 @details If time * 2 < 1, the timeline of inner action will be changed by:
         \f$0.5*{ time }^{ rate }\f$.
         Else, the timeline of inner action will be changed by:
         \f$1.0-0.5*{ 2-time }^{ rate }\f$.
=======
 @brief EaseInOut action with a rate
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseInOut : public EaseRateAction
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action and the rate parameter.
     @param action The pointer of the inner action.
     @param rate The value of the rate parameter.
     @return A pointer of EaseInOut action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the rate parameter */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseInOut* create(ActionInterval* action, float rate);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseInOut* clone() const  override;
    virtual EaseInOut* reverse() const  override;
=======
	virtual EaseInOut* clone() const  override;
	virtual EaseInOut* reverse() const  override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseInOut() {}
    virtual ~EaseInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseInOut);
};

/** 
<<<<<<< HEAD
 @class EaseExponentialIn
 @brief Ease Exponential In action.
 @details The timeline of inner action will be changed by:
         \f${ 2 }^{ 10*(time-1) }-1*0.001\f$.
=======
 @brief Ease Exponential In
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseExponentialIn : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialIn action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseExponentialIn* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseExponentialIn* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseExponentialIn* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseExponentialIn() {}
    virtual ~EaseExponentialIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseExponentialIn);
};

/** 
<<<<<<< HEAD
 @class EaseExponentialOut
 @brief Ease Exponential Out
 @details The timeline of inner action will be changed by:
         \f$1-{ 2 }^{ -10*(time-1) }\f$.
=======
 @brief Ease Exponential Out
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseExponentialOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseExponentialOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseExponentialOut* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseExponentialOut* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseExponentialOut() {}
    virtual ~EaseExponentialOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseExponentialOut);
};

/** 
<<<<<<< HEAD
 @class EaseExponentialInOut
 @brief Ease Exponential InOut
 @details If time * 2 < 1, the timeline of inner action will be changed by:
         \f$0.5*{ 2 }^{ 10*(time-1) }\f$.
         else, the timeline of inner action will be changed by:
         \f$0.5*(2-{ 2 }^{ -10*(time-1) })\f$.
=======
 @brief Ease Exponential InOut
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseExponentialInOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseExponentialInOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseExponentialInOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseExponentialInOut* clone() const override;
    virtual EaseExponentialInOut* reverse() const override;
=======
	virtual EaseExponentialInOut* clone() const override;
	virtual EaseExponentialInOut* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseExponentialInOut() {}
    virtual ~EaseExponentialInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseExponentialInOut);
};

/** 
<<<<<<< HEAD
 @class EaseSineIn
 @brief Ease Sine In
 @details The timeline of inner action will be changed by:
         \f$1-cos(time*\frac { \pi  }{ 2 } )\f$.
=======
 @brief Ease Sine In
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseSineIn : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseSineIn action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseSineIn* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseSineIn* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseSineIn* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseSineIn() {}
    virtual ~EaseSineIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseSineIn);
};

/** 
<<<<<<< HEAD
 @class EaseSineOut
 @brief Ease Sine Out
 @details The timeline of inner action will be changed by:
         \f$sin(time*\frac { \pi  }{ 2 } )\f$.
=======
 @brief Ease Sine Out
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseSineOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseSineOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseSineOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseSineOut* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseSineOut* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseSineOut() {}
    virtual ~EaseSineOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseSineOut);
};

/** 
<<<<<<< HEAD
 @class EaseSineInOut
 @brief Ease Sine InOut
 @details The timeline of inner action will be changed by:
         \f$-0.5*(cos(\pi *time)-1)\f$.
=======
 @brief Ease Sine InOut
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @ingroup Actions
 */
class CC_DLL EaseSineInOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseSineInOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseSineInOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseSineInOut* clone() const override;
    virtual EaseSineInOut* reverse() const override;
=======
	virtual EaseSineInOut* clone() const override;
	virtual EaseSineInOut* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseSineInOut() {}
    virtual ~EaseSineInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseSineInOut);
};

/** 
<<<<<<< HEAD
 @class EaseElastic
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @brief Ease Elastic abstract class
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseElastic : public ActionEase
{
public:

<<<<<<< HEAD
    /** 
     @brief Get period of the wave in radians. Default value is 0.3.
     @return Return the period of the wave in radians.
    */
    inline float getPeriod() const { return _period; }
    /**
     @brief Set period of the wave in radians.
     @param fPeriod The value will be set.
    */
=======
    /** get period of the wave in radians. default is 0.3 */
    inline float getPeriod() const { return _period; }
    /** set period of the wave in radians. */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    inline void setPeriod(float fPeriod) { _period = fPeriod; }

    //
    // Overrides
    //
<<<<<<< HEAD
    virtual EaseElastic* clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
    
    virtual EaseElastic* reverse() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
=======
	virtual EaseElastic* clone() const override = 0;
	virtual EaseElastic* reverse() const override = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseElastic() {}
    virtual ~EaseElastic() {}
<<<<<<< HEAD
    /** 
     @brief Initializes the action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians. Default is 0.3.
     @return Return true when the initialization success, otherwise return false.
    */
=======
    /** Initializes the action with the inner action and the period in radians (default is 0.3) */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    bool initWithAction(ActionInterval *action, float period = 0.3f);

protected:
    float _period;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseElastic);

};

/** 
<<<<<<< HEAD
 @class EaseElasticIn
 @brief Ease Elastic In action.
 @details If time == 0 or time == 1, the timeline of inner action will not be changed.
         Else, the timeline of inner action will be changed by:
         \f$-{ 2 }^{ 10*(time-1) }*sin((time-1-\frac { period }{ 4 } )*\pi *2/period)\f$.

 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief Ease Elastic In action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseElasticIn : public EaseElastic
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the EaseElasticIn action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticIn action. If creation failed, return nil.
    */
    static EaseElasticIn* create(ActionInterval *action, float period);

    /** 
     @brief Create the EaseElasticIn action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticIn action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static EaseElasticIn* create(ActionInterval *action, float period);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseElasticIn* create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseElasticIn* clone() const override;
    virtual EaseElastic* reverse() const override;
=======
	virtual EaseElasticIn* clone() const override;
	virtual EaseElastic* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseElasticIn() {}
    virtual ~EaseElasticIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseElasticIn);
};

/** 
<<<<<<< HEAD
 @class EaseElasticOut
 @brief Ease Elastic Out action.
 @details If time == 0 or time == 1, the timeline of inner action will not be changed.
         Else, the timeline of inner action will be changed by:
         \f${ 2 }^{ -10*time }*sin((time-\frac { period }{ 4 } )*\pi *2/period)+1\f$.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief Ease Elastic Out action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseElasticOut : public EaseElastic
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the EaseElasticOut action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticOut action. If creation failed, return nil.
    */
    static EaseElasticOut* create(ActionInterval *action, float period);

    /** 
     @brief Create the EaseElasticOut action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticOut action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static EaseElasticOut* create(ActionInterval *action, float period);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseElasticOut* create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseElasticOut* clone() const override;
    virtual EaseElastic* reverse() const override;
=======
	virtual EaseElasticOut* clone() const override;
	virtual EaseElastic* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseElasticOut() {}
    virtual ~EaseElasticOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseElasticOut);
};

/** 
<<<<<<< HEAD
 @class EaseElasticInOut
 @brief Ease Elastic InOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief Ease Elastic InOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseElasticInOut : public EaseElastic
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the EaseElasticInOut action with the inner action and the period in radians.
     @param action The pointer of the inner action.
     @param period Period of the wave in radians.
     @return A pointer of EaseElasticInOut action. If creation failed, return nil.
    */
    static EaseElasticInOut* create(ActionInterval *action, float period);

    /** 
     @brief Create the EaseElasticInOut action with the inner action and period value is 0.3.
     @param action The pointer of the inner action.
     @return A pointer of EaseElasticInOut action. If creation failed, return nil.
    */
=======
    /** Creates the action with the inner action and the period in radians (default is 0.3) */
    static EaseElasticInOut* create(ActionInterval *action, float period);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseElasticInOut* create(ActionInterval *action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseElasticInOut* clone() const override;
    virtual EaseElasticInOut* reverse() const override;
=======
	virtual EaseElasticInOut* clone() const override;
	virtual EaseElasticInOut* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseElasticInOut() {}
    virtual ~EaseElasticInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseElasticInOut);
};

/** 
<<<<<<< HEAD
 @class EaseBounce
=======
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @brief EaseBounce abstract class.
 @since v0.8.2
 @ingroup Actions
*/
class CC_DLL EaseBounce : public ActionEase
{
public:

    // Overrides
<<<<<<< HEAD
    virtual EaseBounce* clone() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }

    virtual EaseBounce* reverse() const override
    {
        CC_ASSERT(0);
        return nullptr;
    }
=======
	virtual EaseBounce* clone() const override = 0;
	virtual EaseBounce* reverse() const override = 0;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBounce() {}
    virtual ~EaseBounce() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBounce);
};

/** 
<<<<<<< HEAD
 @class EaseBounceIn
 @brief EaseBounceIn action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBounceIn action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
*/
class CC_DLL EaseBounceIn : public EaseBounce
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceIn action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBounceIn* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBounceIn* clone() const override;
    virtual EaseBounce* reverse() const override;
=======
	virtual EaseBounceIn* clone() const override;
	virtual EaseBounce* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBounceIn() {}
    virtual ~EaseBounceIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBounceIn);
};

/** 
<<<<<<< HEAD
 @class EaseBounceOut
 @brief EaseBounceOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBounceOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseBounceOut : public EaseBounce
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBounceOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBounceOut* clone() const override;
    virtual EaseBounce* reverse() const override;
=======
	virtual EaseBounceOut* clone() const override;
	virtual EaseBounce* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBounceOut() {}
    virtual ~EaseBounceOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBounceOut);
};

/** 
<<<<<<< HEAD
 @class EaseBounceInOut
 @brief EaseBounceInOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBounceInOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseBounceInOut : public EaseBounce
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBounceInOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBounceInOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBounceInOut* clone() const override;
    virtual EaseBounceInOut* reverse() const override;
=======
	virtual EaseBounceInOut* clone() const override;
	virtual EaseBounceInOut* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBounceInOut() {}
    virtual ~EaseBounceInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBounceInOut);
};

/** 
<<<<<<< HEAD
 @class EaseBackIn
 @brief EaseBackIn action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBackIn action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseBackIn : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackIn action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBackIn* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBackIn* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseBackIn* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBackIn() {}
    virtual ~EaseBackIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBackIn);
};

/** 
<<<<<<< HEAD
 @class EaseBackOut
 @brief EaseBackOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBackOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseBackOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBackOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBackOut* clone() const override;
    virtual ActionEase* reverse() const override;
=======
	virtual EaseBackOut* clone() const override;
	virtual ActionEase* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBackOut() {}
    virtual ~EaseBackOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBackOut);
};

/** 
<<<<<<< HEAD
 @class EaseBackInOut
 @brief EaseBackInOut action.
 @warning This action doesn't use a bijective function.
          Actions like Sequence might have an unexpected result when used with this action.
=======
 @brief EaseBackInOut action.
 @warning This action doesn't use a bijective function. Actions like Sequence might have an unexpected result when used with this action.
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
 @since v0.8.2
 @ingroup Actions
 */
class CC_DLL EaseBackInOut : public ActionEase
{
public:
<<<<<<< HEAD
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBackInOut action. If creation failed, return nil.
    */
=======
    /** creates the action */
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
    static EaseBackInOut* create(ActionInterval* action);

    // Overrides
    virtual void update(float time) override;
<<<<<<< HEAD
    virtual EaseBackInOut* clone() const override;
    virtual EaseBackInOut* reverse() const override;
=======
	virtual EaseBackInOut* clone() const override;
	virtual EaseBackInOut* reverse() const override;
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

CC_CONSTRUCTOR_ACCESS:
    EaseBackInOut() {}
    virtual ~EaseBackInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBackInOut);
};


/** 
<<<<<<< HEAD
@class EaseBezierAction
@brief Ease Bezier
@ingroup Actions
*/
class CC_DLL EaseBezierAction : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseBezierAction action. If creation failed, return nil.
    */
    static EaseBezierAction* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseBezierAction* clone() const override;
    virtual EaseBezierAction* reverse() const override;

    /**
    @brief Set the bezier parameters.
    */
    virtual void setBezierParamer( float p0, float p1, float p2, float p3);

CC_CONSTRUCTOR_ACCESS:
    EaseBezierAction() {}
    virtual ~EaseBezierAction() {}

protected:
    float _p0;
    float _p1;
    float _p2;
    float _p3;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseBezierAction);
};

/** 
@class EaseQuadraticActionIn
@brief Ease Quadratic In
@ingroup Actions
*/
class CC_DLL EaseQuadraticActionIn : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionIn action. If creation failed, return nil.
    */
    static EaseQuadraticActionIn* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuadraticActionIn* clone() const override;
    virtual EaseQuadraticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuadraticActionIn() {}
    virtual ~EaseQuadraticActionIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionIn);
=======
@brief Ease Bezier
@ingroup Actions
*/
class EaseBezierAction : public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseBezierAction* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseBezierAction* clone() const override;
	virtual EaseBezierAction* reverse() const override;

	virtual void setBezierParamer( float p0, float p1, float p2, float p3);

CC_CONSTRUCTOR_ACCESS:
	EaseBezierAction() {}
	virtual ~EaseBezierAction() {}

protected:
	float _p0;
	float _p1;
	float _p2;
	float _p3;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseBezierAction);
};

/** 
@brief Ease Quadratic In
@ingroup Actions
*/
class EaseQuadraticActionIn:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuadraticActionIn* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuadraticActionIn* clone() const override;
	virtual EaseQuadraticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuadraticActionIn() {}
	virtual ~EaseQuadraticActionIn() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionIn);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

};

/** 
<<<<<<< HEAD
@class EaseQuadraticActionOut
@brief Ease Quadratic Out
@ingroup Actions
*/
class CC_DLL EaseQuadraticActionOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionOut action. If creation failed, return nil.
    */
    static EaseQuadraticActionOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuadraticActionOut* clone() const override;
    virtual EaseQuadraticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuadraticActionOut() {}
    virtual ~EaseQuadraticActionOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionOut);
=======
@brief Ease Quadratic Out
@ingroup Actions
*/
class EaseQuadraticActionOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuadraticActionOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuadraticActionOut* clone() const override;
	virtual EaseQuadraticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuadraticActionOut() {}
	virtual ~EaseQuadraticActionOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionOut);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896

};

/** 
<<<<<<< HEAD
@class EaseQuadraticActionInOut
@brief Ease Quadratic InOut
@ingroup Actions
*/
class CC_DLL EaseQuadraticActionInOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuadraticActionInOut action. If creation failed, return nil.
    */
    static EaseQuadraticActionInOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuadraticActionInOut* clone() const override;
    virtual EaseQuadraticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuadraticActionInOut() {}
    virtual ~EaseQuadraticActionInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionInOut);
};

/** 
@class EaseQuarticActionIn
@brief Ease Quartic In
@ingroup Actions
*/
class CC_DLL EaseQuarticActionIn : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionIn action. If creation failed, return nil.
    */
    static EaseQuarticActionIn* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuarticActionIn* clone() const override;
    virtual EaseQuarticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuarticActionIn() {}
    virtual ~EaseQuarticActionIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionIn);
};

/** 
@class EaseQuarticActionOut
@brief Ease Quartic Out
@ingroup Actions
*/
class CC_DLL EaseQuarticActionOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionOut action. If creation failed, return nil.
    */
    static EaseQuarticActionOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuarticActionOut* clone() const override;
    virtual EaseQuarticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuarticActionOut() {}
    virtual ~EaseQuarticActionOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionOut);
};

/** 
@class EaseQuarticActionInOut
@brief Ease Quartic InOut
@ingroup Actions
*/
class CC_DLL EaseQuarticActionInOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuarticActionInOut action. If creation failed, return nil.
    */
    static EaseQuarticActionInOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuarticActionInOut* clone() const override;
    virtual EaseQuarticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuarticActionInOut() {}
    virtual ~EaseQuarticActionInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionInOut);
=======
@brief Ease Quadratic InOut
@ingroup Actions
*/
class EaseQuadraticActionInOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuadraticActionInOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuadraticActionInOut* clone() const override;
	virtual EaseQuadraticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuadraticActionInOut() {}
	virtual ~EaseQuadraticActionInOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuadraticActionInOut);
};

/** 
@brief Ease Quartic In
@ingroup Actions
*/
class EaseQuarticActionIn:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuarticActionIn* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuarticActionIn* clone() const override;
	virtual EaseQuarticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuarticActionIn() {}
	virtual ~EaseQuarticActionIn() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionIn);
};

/** 
@brief Ease Quartic Out
@ingroup Actions
*/
class EaseQuarticActionOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuarticActionOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuarticActionOut* clone() const override;
	virtual EaseQuarticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuarticActionOut() {}
	virtual ~EaseQuarticActionOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionOut);
};

/** 
@brief Ease Quartic InOut
@ingroup Actions
*/
class EaseQuarticActionInOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuarticActionInOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuarticActionInOut* clone() const override;
	virtual EaseQuarticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuarticActionInOut() {}
	virtual ~EaseQuarticActionInOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuarticActionInOut);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
};


/** 
<<<<<<< HEAD
@class EaseQuinticActionIn
@brief Ease Quintic In
@ingroup Actions
*/
class CC_DLL EaseQuinticActionIn : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionIn action. If creation failed, return nil.
    */
    static EaseQuinticActionIn* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuinticActionIn* clone() const override;
    virtual EaseQuinticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuinticActionIn() {}
    virtual ~EaseQuinticActionIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionIn);
};

/** 
@class EaseQuinticActionOut
@brief Ease Quintic Out
@ingroup Actions
*/
class CC_DLL EaseQuinticActionOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionOut action. If creation failed, return nil.
    */
    static EaseQuinticActionOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuinticActionOut* clone() const override;
    virtual EaseQuinticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuinticActionOut() {}
    virtual ~EaseQuinticActionOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionOut);
};

/** 
@class EaseQuinticActionInOut
@brief Ease Quintic InOut
@ingroup Actions
*/
class CC_DLL EaseQuinticActionInOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseQuinticActionInOut action. If creation failed, return nil.
    */
    static EaseQuinticActionInOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseQuinticActionInOut* clone() const override;
    virtual EaseQuinticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseQuinticActionInOut() {}
    virtual ~EaseQuinticActionInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionInOut);
};

/** 
@class EaseCircleActionIn
@brief Ease Circle In
@ingroup Actions
*/
class CC_DLL EaseCircleActionIn : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionIn action. If creation failed, return nil.
    */
    static EaseCircleActionIn* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCircleActionIn* clone() const override;
    virtual EaseCircleActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCircleActionIn() {}
    virtual ~EaseCircleActionIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionIn);
};

/** 
@class EaseCircleActionOut
@brief Ease Circle Out
@ingroup Actions
*/
class CC_DLL EaseCircleActionOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionOut action. If creation failed, return nil.
    */
    static EaseCircleActionOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCircleActionOut* clone() const override;
    virtual EaseCircleActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCircleActionOut() {}
    virtual ~EaseCircleActionOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionOut);
};

/** 
@class EaseCircleActionInOut
@brief Ease Circle InOut
@ingroup Actions
*/
class CC_DLL EaseCircleActionInOut:public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCircleActionInOut action. If creation failed, return nil.
    */
    static EaseCircleActionInOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCircleActionInOut* clone() const override;
    virtual EaseCircleActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCircleActionInOut() {}
    virtual ~EaseCircleActionInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionInOut);
};

/** 
@class EaseCubicActionIn
@brief Ease Cubic In
@ingroup Actions
*/
class CC_DLL EaseCubicActionIn:public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionIn action. If creation failed, return nil.
    */
    static EaseCubicActionIn* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCubicActionIn* clone() const override;
    virtual EaseCubicActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCubicActionIn() {}
    virtual ~EaseCubicActionIn() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionIn);
};

/** 
@class EaseCubicActionOut
@brief Ease Cubic Out
@ingroup Actions
*/
class CC_DLL EaseCubicActionOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionOut action. If creation failed, return nil.
    */
    static EaseCubicActionOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCubicActionOut* clone() const override;
    virtual EaseCubicActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCubicActionOut() {}
    virtual ~EaseCubicActionOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionOut);
};

/** 
@class EaseCubicActionInOut
@brief Ease Cubic InOut
@ingroup Actions
*/
class CC_DLL EaseCubicActionInOut : public ActionEase
{
public:
    /** 
     @brief Create the action with the inner action.
     @param action The pointer of the inner action.
     @return A pointer of EaseCubicActionInOut action. If creation failed, return nil.
    */
    static EaseCubicActionInOut* create(ActionInterval* action);
    
    virtual void update(float time) override;
    virtual EaseCubicActionInOut* clone() const override;
    virtual EaseCubicActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
    EaseCubicActionInOut() {}
    virtual ~EaseCubicActionInOut() {}

private:
    CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionInOut);
=======
@brief Ease Quintic In
@ingroup Actions
*/
class EaseQuinticActionIn:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuinticActionIn* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuinticActionIn* clone() const override;
	virtual EaseQuinticActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuinticActionIn() {}
	virtual ~EaseQuinticActionIn() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionIn);
};

/** 
@brief Ease Quintic Out
@ingroup Actions
*/
class EaseQuinticActionOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuinticActionOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuinticActionOut* clone() const override;
	virtual EaseQuinticActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuinticActionOut() {}
	virtual ~EaseQuinticActionOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionOut);
};

/** 
@brief Ease Quintic InOut
@ingroup Actions
*/
class EaseQuinticActionInOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseQuinticActionInOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseQuinticActionInOut* clone() const override;
	virtual EaseQuinticActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseQuinticActionInOut() {}
	virtual ~EaseQuinticActionInOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseQuinticActionInOut);
};

/** 
@brief Ease Circle In
@ingroup Actions
*/
class EaseCircleActionIn:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCircleActionIn* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCircleActionIn* clone() const override;
	virtual EaseCircleActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCircleActionIn() {}
	virtual ~EaseCircleActionIn() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionIn);
};

/** 
@brief Ease Circle Out
@ingroup Actions
*/
class EaseCircleActionOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCircleActionOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCircleActionOut* clone() const override;
	virtual EaseCircleActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCircleActionOut() {}
	virtual ~EaseCircleActionOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionOut);
};

/** 
@brief Ease Circle InOut
@ingroup Actions
*/
class EaseCircleActionInOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCircleActionInOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCircleActionInOut* clone() const override;
	virtual EaseCircleActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCircleActionInOut() {}
	virtual ~EaseCircleActionInOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCircleActionInOut);
};

/** 
@brief Ease Cubic In
@ingroup Actions
*/
class EaseCubicActionIn:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCubicActionIn* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCubicActionIn* clone() const override;
	virtual EaseCubicActionIn* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCubicActionIn() {}
	virtual ~EaseCubicActionIn() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionIn);
};

/** 
@brief Ease Cubic Out
@ingroup Actions
*/
class EaseCubicActionOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCubicActionOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCubicActionOut* clone() const override;
	virtual EaseCubicActionOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCubicActionOut() {}
	virtual ~EaseCubicActionOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionOut);
};

/** 
@brief Ease Cubic InOut
@ingroup Actions
*/
class EaseCubicActionInOut:public cocos2d::ActionEase
{
public:
	/** creates the action */
	static EaseCubicActionInOut* create(cocos2d::ActionInterval* action);

	virtual void update(float time) override;
	virtual EaseCubicActionInOut* clone() const override;
	virtual EaseCubicActionInOut* reverse() const override;

CC_CONSTRUCTOR_ACCESS:
	EaseCubicActionInOut() {}
	virtual ~EaseCubicActionInOut() {}

private:
	CC_DISALLOW_COPY_AND_ASSIGN(EaseCubicActionInOut);
>>>>>>> b333405ba27397fdac44fd1fa8c67cd20c36e896
};

// end of actions group
/// @}

NS_CC_END

#endif // __ACTION_CCEASE_ACTION_H__
