//
//  DLog.h
//  MagicTouch
//
//  Created by SaiDong on 23/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#ifndef  MagicTouch_DLog_h
#define MagicTouch_DLog_h

#include "../../Framework/CocosHead.h"

/**
 *  DLog工具类
 */
class DLog {
public:
    //Dlog
    //set the flag true or false
    const static bool flag = true;
    const static bool flag_draw = false;
    
public:
    
    DLog();
    ~DLog();
    static void d(const char* content);
    static void d(const char* content,const char* content1);
    static void d(const char* content,int t);
    static void d(const char* content,int t,const char* content1);
    static void d(const char* content,int t,const char* content1,int t1);
    static void d(const char* content,float f);
    static void d(const char* content,double d);
    static void d(const char* notice, std::string content );
    static void d(string notice,string content);
    static void d_messagebox(const char* title,const char* content);
    static void d_messagebox(const char* content);

};

#endif
