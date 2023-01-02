/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-09 17:26:08
 * @LastEditors: lls
 * @LastEditTime: 2022-12-09 18:37:00
 * @Descripttion: use mmap to realize files copying
 */
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main(){

    int fda = open("a.txt", O_RDWR);
    int fdb = open("b.txt", O_RDWR);

    int len = lseek(fda, 0, SEEK_END);
    if(len == -1){
        perror("lseek");
        return -1;
    }
    
    truncate("b.txt", len);
    write(fdb, " ", 1);

    void *a_ptr = mmap(NULL, len, PROT_READ | PROT_WRITE,
                        MAP_SHARED, fda, 0);
    if(a_ptr == (void *)-1){
        perror("mmap");
        return -1;
    } 

    void *b_ptr = mmap(NULL, len, PROT_READ | PROT_WRITE,
                        MAP_SHARED, fdb, 0);
    if(b_ptr == (void *)-1){
        perror("mmap");
        return -1;
    }

    memcpy(b_ptr, a_ptr, len);

    char buf[64];
    strcpy(buf, (char * )b_ptr);
    printf("b.txt : %s\n",buf);

    munmap(a_ptr, len);
    munmap(b_ptr, len);


    

    close(fda);
    close(fdb);
    return 0;

}