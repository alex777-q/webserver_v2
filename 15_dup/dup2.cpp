#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<cstring>

int main(){

	int fd = open("b.txt", O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}

	int fd1 = open("c.txt", O_RDWR);
	if(fd1 == -1){
		perror("open");
		return -1;
	}

	printf("fd: %d. fd1: %d\n",fd,fd1);

	int ret = dup2(fd,fd1);
	if(ret == -1){
		perror("dup2");
		// return -1;
	}else printf("exchang success!\n");

	char *str  = "hello,dup2!\n";
	int len = write(fd1, str, strlen(str));

	if(len == -1){
		perror("write");
		return -1;
	}

	printf("fd: %d, fd1: %d, ret: %d\n",fd,fd1,ret);

	close(fd);
	close(fd1);

	return 0;






}
