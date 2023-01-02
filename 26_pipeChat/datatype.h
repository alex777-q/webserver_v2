/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-08 17:18:19
 * @LastEditors: lls
 * @LastEditTime: 2022-12-08 19:27:20
 * @Descripttion: 
 */
#ifndef __DATA_TYPE_H
#define __DATA_TYPE_H

struct user_info{
    char userName[64];
    char fifoName[64];
    int id;
};

struct common_msg{
    int id;
    int datalen;
    char buf[1000];
};

struct msg_type{
    int msgType;
    union{
        struct common_msg commonMsg;
        struct user_info user;
    }data;
};

enum{
    MSG_TYPE_REGISTRATION = 1,
    MSG_TYPE_COMMON_MSG,
    MSG_TYPE_QUIT,
};

#endif
