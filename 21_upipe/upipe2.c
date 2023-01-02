#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int main(){
    int pipefd[2] = {0};
    if(pipe(pipefd) == -1){
        perror("pipe");
        return -1;
    }
    printf("pipefd[0]: %d\n", pipefd[0]); //3    
     printf("pipefd[1]: %d\n", pipefd[1]); //4    
      
    if(fork()==0){
        //child    
        close(pipefd[0]);
        int count = 0;
        const char *buff = "a";
        while(1){
            write(pipefd[1],buff,strlen(buff));
            count ++;
            printf("count: %d\n",count);
        }
        exit(0);
    }

    
    close(pipefd[1]);
    while(1){
        ////without taking data
        //sleep(1);

        //taking some data
        sleep(5);
        char buff1[4*1024] = {0};  //4KB
        ssize_t s = read(pipefd[0], buff1, sizeof(buff1));
            printf("child is taking 4KB data...\n");
    }

    return 0;


}