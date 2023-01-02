#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
        
        
        //open a file
        int fd = open("./a.txt",O_RDONLY);
        if(fd == -1){
                perror("open");
                return -1;
        }               
        
        //create a new file(copy)
        int destfd = open("./b.txt",O_WRONLY | O_CREAT, 0664);
        if(destfd == -1){
                perror("open");
                return -1;
        }

        //read/write
        char buff[1024] = {0};
        int len = 0;
        while((len = read(fd, buff, sizeof(buff))) > 0){
        	write(destfd, buff, len);
        }

        //close files
        close(fd);
        close(destfd);

        return 0;
}
