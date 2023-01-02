#include "comm.h"

int main(int argc, char **argv)
{
    int msgid;
    int rcvlen;
    long msgtype;
    struct msgbuf *msg;

    msgid   = msgget(ftok(FTOK_FILE, FTOK_ID), MSG_RD_PERMISSION);
    msgtype = atol(argv[1]);
    msg = (struct msgbuf *)calloc(MAX_MSG_LEN, 1);

    rcvlen = msgrcv(msgid, msg, MAX_MSG_LEN, msgtype, 0);
    printf("read %d bytes, type = %ld\n", rcvlen, msg->type);

    return 0;
}