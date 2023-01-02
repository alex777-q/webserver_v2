#ifndef _COMM_H_
#define _COMM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define FTOK_FILE          "./"
#define FTOK_ID            1

#define MSG_RD_PERMISSION  0444
#define MSG_WR_PERMISSION  0222
#define MSG_RW_PERMISSION  (MSG_RD_PERMISSION | MSG_WR_PERMISSION)

#define MAX_MSG_LEN        (8192 + sizeof(long))

struct msgbuf
{
    long type;
    char *data;
};

#endif