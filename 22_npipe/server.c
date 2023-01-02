#include "comm.h"
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    if(mkfifo(MY_FIFO,0666) < 0){
        perror("mkfifo");
        return -1;
    }

    int fd = open(MY_FIFO, O_RDONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }

    while(1){

        char buff[64] = {0};
        ssize_t s = read(fd,buff,sizeof(buff)-1);
        if(s > 0){
            //success
            buff[s] = 0;
            //printf("client: %s\n",buff);
            

            //additonal function ##
            if(strcmp(buff,"show") == 0){
                if(fork() == 0){
                    execlp("ls","ls","-l",NULL);
                    exit(1);
                }
                waitpid(-1,NULL,0);
            }
            else if(strcmp(buff, "wait for me") == 0){
                if(fork() == 0){
                    execl("/usr/bin/sl","sl",NULL);
                    exit(1);
                }
                waitpid(-1,NULL,0);

            }
            else{
                printf("client: %s\n",buff);
            }
            //additional function ##

        }
        else if(s == 0){
            //peer close
            printf("client quit...\n");
            break;
        }
        else {
            //error
            perror("read");
            break;
        }
    }
    close(fd);
    return 0;
}