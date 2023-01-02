#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

#define myfifo "./fifo"
#define myfile "./myfile.txt"

int main(){

    int fd = open(myfile, O_WRONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }

    system("cat myfile.txt");
    return 0;
}