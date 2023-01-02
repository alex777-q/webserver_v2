#include "./comm.h"

int main(){

    key_t key = ftok(FTOK_FILE, FTOK_ID);
    int semid = semget(key, 0, 0);
    semctl(semid, 0, IPC_RMID);

    return 0;
}