#pragma once

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

#define PATH_NAME "./"
#define PROJ_ID 0x6666

struct msg_st{
    long mtype;
    char mtext[1024];
}msg;