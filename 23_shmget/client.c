#include "./comm.h"
#include<unistd.h>

int main(){


    key_t key = ftok(PATH_NAME, PROJ_ID);
    if(key == -1){
        perror("ftok");
        return -1;
    }

    //client only need get
    int shmid = shmget(key, SIZE, IPC_CREAT);
    if(shmid == -1){
        perror("shmget");
        return -1;
    }
    printf("key: 0x%x, shmid: %u\n",key,shmid);

    char *men = (char*)shmat(shmid, NULL, 0);
    //sleep(5);
    printf("client attach shm done...\n");

    //communicate
    char c = 'a';
    while(c <= 'z'){
        sleep(1);
        men[c - 'a'] = c;
        c++;
        men[c - 'a'] = 0;
    }

    shmdt(men);
    printf("client detach shm done...\n");
    //sleep(5);

    //donot need delete shm
    return 0;

}