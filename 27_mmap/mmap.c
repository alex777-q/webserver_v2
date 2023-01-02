/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-09 14:40:22
 * @LastEditors: lls
 * @LastEditTime: 2022-12-09 17:14:45
 * @Descripttion: 
 */

/*
    #include<sys/mman.h>
    void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
        - funtion: map or unmap a file or device on memory
        - args:
            - void *addr: NULL, choosed by kernel
            - size_t length: the length of data, can't be 0.
                            recommended to use file length.
                            [how to get the length? - stat lseek]
            - prot: op-permissions to memory.
                    - PROT_EXEC: exe
                    - PROT_READ (can't loss)
                    - PROT_WRITE
                    - PROT_NONE
            - flags: 
                    - MAP_SHARED: 映射区的数据会自动和磁盘文件进行同步，进程间通信，必须要设置
                    - MAP_PRIVATE: 不同步，内存映射区的数据改变了，对原本的文件不会修改，会重新创建一个新的文件。（copy on write)
            - fd: 
                - 要映射的那个文件的文件描述符
                - 通过open得到， open的是一个磁盘文件
                - 注意： 文件的大小不能为0， open指定的权限不能和prot参数有冲突
            - offset：
                    偏移量，一般不用，必须指定的是4K的整数倍，0表示不偏移

    int munmap(void *addr, size_t length);
        - function:
                    - free mmap
        - args:
                - addr: 要释放的内存的首地址
                - length: 要释放的内存的大小，要和map函数中的length参数的值一样。
*/

/*
    使用内存映射实现进程间通信:
    1.有关系的进程（父子进程）
        - 还没有子进程的时候
            -通过唯一的父进程，先创建内存映射区
        - 有了内存映射区以后，创建子进程
        - 父子进程共享创建的内存映射区
    
    2.没有关系的进程见通信
        - 准备一个大小不是0的磁盘文件
        - 进程1 通过磁盘文件创建内存映射区
            - 得到一个操作这块内存的指针
        - 进程2 通过磁盘文件创建内存映射区
            - 得到一个操作这块内存的指针
        - 使用这块映射区通信

    【注意：内存映射区通信，是非阻塞的；管道是阻塞的】
*/

#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<wait.h>


int main(){

    int fd = open("text.txt", O_RDWR);
    if(fd == -1){
        perror("open");
        return -1;
    }

    int fdlen = lseek(fd, 10, SEEK_END);
    if(fdlen == -1){
        perror("lseek");
        return -1;
    }
    printf("text.txt size is = %d\n", fdlen);

    void* map_ptr = mmap(NULL, fdlen, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(map_ptr == (void *)-1){
        perror("mmap");
        return -1;
    }

    pid_t pid = fork();
    
    if(pid > 0){
        printf("this is parent process.\n");
        // wait(NULL);
        strcpy((char *)map_ptr, "hello son!");
    }
    else if(pid == 0){
        printf("this is child process.\n");
        char buf[64];
        strcpy(buf, (char *)map_ptr);
        printf("read data: %s\n",buf);
            printf("text.txt size is = %d\n", fdlen);

    }
    int ret = munmap(map_ptr, fdlen);
    
    
    close(fd);


    return 0;
}