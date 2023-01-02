/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-08 17:17:16
 * @LastEditors: lls
 * @LastEditTime: 2022-12-08 17:17:54
 * @Descripttion: 
 */
#ifndef __OK_H_
#define __OK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/mman.h>
#include <sys/signal.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>

#define CLEAR_ARRAY(a) memset(a,0,sizeof(a))


#define DBG_PRINT_DEFINE
#ifdef DBG_PRINT_DEFINE
#define DEBUG_MSG(fmt ,...) printf("Func():%s Line:%d " fmt,__func__,__LINE__,##__VA_ARGS__)
#else
#define DEBUG_MSG(...)
//#define printf(...)
#endif

#endif

