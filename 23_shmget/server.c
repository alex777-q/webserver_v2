#include "./comm.h"
#include<unistd.h>

int main(){

    key_t key = ftok(PATH_NAME, PROJ_ID);
    if(key == -1){
        perror("ftok");
        return -1;
    }

    int shmid = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);
    if(shmid < 0){
        perror("shmget");
        return -1;
    }
    printf("key: 0x%x, shmid: %u\n",key,shmid);

    //sleep(2);
    char* men = (char*)shmat(shmid, NULL, 0);
    printf("attach shm done...\n");
    //slepp(10);

    //communicate
    while(1){
        sleep(1);
        printf("%s\n",men);
    }

    shmdt(men);
    printf("detach shm done...\n");
    //sleep(5);

    shmctl(shmid, IPC_RMID, NULL);
    printf("shm delete success...\n");

    sleep(10);
    return 0;


}