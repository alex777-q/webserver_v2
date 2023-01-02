#include "comm.h"

int main()
{
    key_t key = ftok(FTOK_FILE, FTOK_ID);
    int oflag = IPC_CREAT | MSG_RW_PERMISSION;
    int msgid = msgget(key, oflag);

    if (msgid >= 0)
    {
        printf("msgget create success, msgid = %d\n", msgid);
    }

    return 0;
}
