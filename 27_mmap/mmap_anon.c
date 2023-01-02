/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-09 18:05:27
 * @LastEditors: lls
 * @LastEditTime: 2022-12-09 18:28:27
 * @Descripttion: 
            MAP_ANONYMOUS
              The mapping is not backed by any file; its contents are
              initialized  to zero.  The fd argument is ignored; how‐
              ever, some implementations  require  fd  to  be  -1  if
              MAP_ANONYMOUS  (or MAP_ANON) is specified, and portable
              applications should ensure this.  The  offset  argument
              should  be  zero.  The use of MAP_ANONYMOUS in conjunc‐
              tion with MAP_SHARED is supported on Linux  only  since
              kernel 2.4.
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<wait.h>

int main(){

    int len = 4096;

    void*ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, 
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(ptr == (void*)-1){
        perror("mmap");
        return 0;
    }

    pid_t pid = fork();

    // if(pid > 0 ){
    //     printf("this is father process\n");
    //     char buff[64] = "hello,son!";
    //     memcpy(ptr, buff, strlen(buff));

    // }else if(pid == 0){
    //     printf("this is child process\n");
    //     char buf[64];
    //     strcpy(buf, (char*)ptr);
    //     printf("recv data : %s\n",buf);
    //     sleep(1);
    // }

    if(pid > 0 ){
        printf("this is father process\n");
        strcpy((char *)ptr, "hello son!!");
        wait(NULL);
    }else if(pid == 0){
        sleep(1);
        printf("this is child process\n");
        printf("recv data : %s\n",(char*)ptr);
    }


    munmap(ptr, len);
    return 0;
    

}