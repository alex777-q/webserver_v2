#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){

    // int fd = open("test.txt",O_RDWR);
    // if(fd == -1){
    //     perror("open");
    //     return -1;
    // }

    //create upipe
    int pipefd[2] = {0};
    if(pipe(pipefd) != 0){
        perror("pipe");
        return -1;
    }
    printf("pipefd[0]: %d\n",pipefd[0]);
    printf("pipefd[1]: %d\n",pipefd[1]);

    //create child process     
    pid_t pid = fork();

    if(pid == 0){
        const char buff[1024] = "hello,upipe!";
        
        close(pipefd[0]);  //child close read
        while(1){
            write(pipefd[1], buff, strlen(buff));
            sleep(1);
        }
        exit(0);
    }

    char buff1[1024] = {0};
    close(pipefd[1]);  //father close write
    while(1){
        ssize_t s = read(pipefd[0],buff1,sizeof(buff1)-1);
        if(s == 0){
            printf("write quit ...\n");
            break;
        }else if(s > 0){
            buff1[s] = 0;
            printf("child said to father: %s\n",buff1);
            // sleep(1);
        }
        else{
            printf("read error ...\n");
            break;
        }

    }
    return 0;
}