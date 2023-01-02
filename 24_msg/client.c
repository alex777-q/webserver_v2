#include"./comm.h"
#include<unistd.h>
#include<string.h>

int main(){

    key_t key = ftok(PATH_NAME, PROJ_ID);
    if(key == -1){

        perror("ftok");
        return 0;
    }

    int msgid = msgget(key, IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        return 0;
    }
    msg.mtype = 1;

    strcpy(msg.mtext,"hello server, im 1st.");
    
    int ret = msgsnd(msgid, &msg, 1024, 0);
    if(ret == -1){
        perror("msgsnd");
        return -1;
    }

    return 0;
}