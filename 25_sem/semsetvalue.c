#include "./comm.h"

int main(int argc, char **argv){

    key_t key;
    int semid;
    int nsems;
    unsigned short *semvals;
    union semun arg;
    struct semid_ds seminfo;
    int i;

    //  open the sems which semcreate creates 
    key = ftok(FTOK_FILE, FTOK_ID);
        if(key == -1){
        perror("ftok");
        return -1;
    }
    semid = semget(key, 0, 0);

    //  get the num of sem in the sems
    arg.buf = &seminfo;
    semctl(semid, 0, IPC_STAT, arg);
    nsems = arg.buf->sem_nsems;

    //  set the value of each sem in the sems
    semvals = (unsigned short *)calloc(nsems, sizeof(unsigned short));

    for(i = 0; i < nsems; i++){

        /*  respectively specified the value of each sem
        in the sems via cmd line args*/
        semvals[i] = atoi(argv[i + 1]);
    }

    arg.array = semvals;
    semctl(semid, 0, SETALL, arg);

    return 0;
}