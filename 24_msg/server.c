#include"./comm.h"
#include<unistd.h>

int main(){

    key_t key = ftok(PATH_NAME,PROJ_ID);
    if(key == -1){
        perror("ftok");
        return -1;
    }

    int msgid = msgget(key, IPC_CREAT | IPC_EXCL |0666);
    if(msgid == -1){
        perror("msgget");
        return -1;
    }

    printf("key: 0x%x, msgid: %u\n",key,msgid);
    // sleep(10);
    // for(int i = 0; i < 10; i++){
    //     printf("wait...\n");
    //     sleep(1);
    // }
    // msgctl(msgid, IPC_RMID, NULL);
    // printf("msg delete success...\n");

    int ret = msgrcv(msgid, &msg, 1024, 0, 0);
    if(ret == -1){
        perror("msgrcv");
        return -1;
    }
    msg.mtype = 0;

    int time = 5;
    while(time--){
        printf("received: %s\n",msg.mtext);
        system("ipcs -q");
        sleep(2);
    }
    
    ret = msgctl(msgid, IPC_RMID, 0);
    if(ret == -1){
        perror("msgctl");
        return -1;
    }
    
    return 0;
    




}
