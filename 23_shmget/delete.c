#include"./comm.h"
#include<unistd.h>

int main(){
    key_t key = ftok(PATH_NAME, PROJ_ID);
    if(key == -1){
        perror("ftok");
        return -1;
    }

    int shmid = shmget(key, SIZE, IPC_CREAT);
    if(shmid < 0){
        perror("shmget");
        return -1;
    }

    int s = shmctl(shmid, IPC_RMID, NULL);
    if(s == -1){
        perror("shmctl");
        return -1;
    }
    printf("shm delete success...\n");

    return 0;
}
