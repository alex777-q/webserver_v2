#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>

int main(){

	char buff[256];
	getcwd(buff,sizeof(buff));
	printf("now the dir is: %s\n",buff);

	int ret = chdir("../13_chdir_getcwd_new");
	if(ret == -1){
		perror("chdir");
		return -1;
	}else printf("change success!\n");

	int fd = open("chdir.txt",O_CREAT|O_RDWR,0664);
	if(fd == -1){
		perror("open");
		return -1;
	}

	close(fd);

	char buff1[256];
	getcwd(buff1,sizeof(buff1));
	printf("now the dir is:%s\n",buff1);

	return 0;
}

