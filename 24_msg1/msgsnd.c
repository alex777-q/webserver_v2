#include "comm.h"

int main(int argc, char **argv)
{
    int msgid;
    int msglen;
    long msgtype;
    struct msgbuf *msg;

    msgid   = msgget(ftok(FTOK_FILE, FTOK_ID), MSG_WR_PERMISSION);
    msglen  = atoi(argv[1]);
    msgtype = atol(argv[2]);

    msg = (struct msgbuf *)calloc(sizeof(long) + msglen, sizeof(char));
    msg->type = msgtype;

    msgsnd(msgid, msg, msglen, 0);

    return 0;
}
