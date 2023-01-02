#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

//F_GETFL  F_SETFL
int main(){


	int fd = open("test.txt", O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}

	int flag = fcntl(fd, F_GETFL);
	if(flag == -1){
		perror("fcntl");
		return -1;
	}
	flag |= O_APPEND;

	int ret = fcntl(fd, F_SETFL, flag);
	if(ret == -1){
		perror("fcntl");
		return -1;
	}

	char *str = "hello\n";
	write(fd, str, strlen(str));

	close(fd);



}
