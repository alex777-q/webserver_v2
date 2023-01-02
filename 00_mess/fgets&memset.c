#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define FILE "./test.txt"

int main(){

    char buf[128];
    memset(buf, 0, 128);
    while(1)
        fgets(buf, 128, stdout);

    // int fd = open(FILE, O_RDWR);
    // if(fd == -1){

    //     perror("open");
    //     return -1;
    // }

    // int ret = write(fd, buf, strlen(buf));
    // if(ret == -1){
    //     perror("write");
    //     return -1;
    // }
    // sleep(2);
    // system("cat test.txt");
    return 0;

}