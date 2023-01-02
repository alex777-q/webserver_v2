#include "./comm.h"

int main(){

    int nsems = 3;
    int oflag = IPC_CREAT | SEM_MODE;
    key_t key = ftok(FTOK_FILE,FTOK_ID);
    int semid = semget(key, nsems, oflag);
    if(semid == -1){
        perror("semget");
        return -1;
    }printf("semcreate success, semid: %d\n",semid);

    return 0;

}