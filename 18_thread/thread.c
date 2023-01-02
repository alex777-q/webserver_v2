#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int add(int x, int y){
    return x+y;
}

void *thread(void *args){
    int num = 0;
    while(1){
        num += add(1,2);
        sleep(1);
    }
}

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    int num = 0;
    while(1){
        num += add(10,20);
        sleep(1);
    }
    return 0;
}