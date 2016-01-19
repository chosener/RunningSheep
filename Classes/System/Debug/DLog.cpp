//
//  DLog.cpp
//  MagicTouch
//
//  Created by SaiDong on 23/10/14.
//  Copyright (c) 2014 Saint Email:dongsai0520@gmail.com QQ:10219556. All rights reserved.
//

#include "DLog.h"

DLog::DLog(){

}
DLog::~DLog(){

}

void DLog::d( const char* content){
    
    if( flag ){
        log( "Log==>%s", content );
    }
}
void DLog::d( const char* content,const char* content1){
    
    if( flag ){
        log( "Log==>%s%s", content,content1);
    }
}

void DLog::d(const char* content,int t ){
      
    if( flag ){
        char str[128] = {0};
        sprintf(str, "Log==>%s = %d",content,t);
        log("%s",str);
    }
}
void DLog::d(const char* content,int t,const char* content1 ){
    
    if( flag ){
        char str[128] = {0};
        if(-1 == t)
        {
                sprintf(str, "Log==>%s%s",content,content1);
        }
        else
        {
                sprintf(str, "Log==>%s%d%s",content,t,content1);
        }

        log("%s",str);
    }
}
void DLog::d(const char* content,int t,const char* content1,int t1)
{
    
    if( flag ){
        char str[128] = {0};
        if(-1 == t)
        {
            sprintf(str, "Log==>%s%s",content,content1);
        }
        else
        {
            sprintf(str, "Log==>%s%d%s%d",content,t,content1,t1);
        }
        
        log("%s",str);
    }
}

void DLog::d(const char* content,float f ){
    
    if( flag ){
        char str[128] = {0};
        sprintf(str, "Log==>%s = %f",content,f);
        log("%s",str);
    }
}
void DLog::d(const char* content,double d){
    
    if( flag ){
        char str[128] = {0};
        sprintf(str, "Log==>%s = %f",content,d);
        log("%s",str);
    }
}

//notice 提示 content 内容
void DLog::d(const char* notice, std::string content )
{
    
    if( flag ){
        log( "Log==>%s:%s", notice,content.c_str());
    }
}

void DLog::d(string notice,string content)
{
    if( flag )
    {
        log( "Log==>%s:%s", notice.c_str(),content.c_str());
    }
}

//弹出调试对话框
void DLog::d_messagebox(const char* title,const char* content)
{
    if(flag)
    {
        MessageBox(content,title);
    }
        
}
//弹出调试对话框
void DLog::d_messagebox(const char* content)
{
    if(flag)
    {
        
        MessageBox(content,"调试对话框");
    }
    
}