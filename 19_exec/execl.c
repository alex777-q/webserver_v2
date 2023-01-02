/*
     #include <unistd.h>
       int execl(const char *pathname, const char *arg, ...);

*/


#include<unistd.h>
#include<stdio.h>


int main(){


    pid_t pid = fork();

    if(pid > 0 ){
        //父进程
        printf("i am father process, pid: %d\n",getpid());
        sleep(1);  //延迟时间
    }else if(pid == 0){
        //子进程

        //execl("hello","hello",NULL);
        execl("/bin/ps","ps","aux",NULL);
        printf("i am child process, pid: %d\n",getpid());

    }

    for(int i = 0; i < 3; i++){
        printf("i = %d, pid = %d\n",i,getpid());
    }

    return 0; 
}