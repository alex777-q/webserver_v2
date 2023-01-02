#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<sys/wait.h>

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
        const char *buff = "hello,upipe.";
        while(1){
            write(pipefd[1],buff,strlen(buff));
            // sleep(5);
            // break;
        }
        close(pipefd[1]);
        exit(0);
    }

    char buff1[1024] = {0};
    close(pipefd[1]);
    while(1){
        ssize_t s = read(pipefd[0],buff1,sizeof(buff1)-1);
        if(s == 0){
            printf("write quit ...\n");
            break;
        }else if(s > 0){
            buff1[s] = 0;
            printf("child said to father: %s\n",buff1);
        }
        else{
            printf("read error ...\n");
            break;
        }
        printf("reader is going to leave...\n");
        sleep(5);
        break;

    }
    close(pipefd[0]);
    //check how child exit
    int status = 0;
    waitpid(-1,&status,0);
    printf("exit code: %d\n",(status>>8)&0xff);
    printf("signal: %d\n",status&0x7f);

    return 0;


}