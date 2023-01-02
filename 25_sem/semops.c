#include "./comm.h"

int main(int argc, char **argv){

    key_t key;
    int semid;
    int nsems;
    union semun arg;
    struct semid_ds seminfo;
    struct sembuf *semops;
    int i;

    //  open the sems which semcreate creates 
    key = ftok(FTOK_FILE, FTOK_ID);
        if(key == -1){
        perror("ftok");
        return -1;
    }

    //  get the num of sem in the sems
    arg.buf = &seminfo;
    semctl(semid, 0, IPC_STAT, arg);
    nsems = arg.buf->sem_nsems;

    /*  The same SEMOP operation is performed 
    on all semaphore in the semaphore set*/
    semops = (struct sembuf *)calloc(nsems, sizeof(struct sembuf));

    for(i = 0; i < nsems; i++){

        semops[i].sem_num = i;
        semops[i].sem_op = atoi(argv[1]);  //  opt-type specifies by cmd args, >0, 0, <0
        semops[i].sem_flg = 0;
    }

    semop(semid, semops, nsems);

    return 0;
}