#include "comm.h"

int main(int argc, char **argv)
{
    int msgid = msgget(ftok(FTOK_FILE, FTOK_ID), 0);
    msgctl(msgid, IPC_RMID, 0);

    return 0;
}
