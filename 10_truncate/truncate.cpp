#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int fd = open("./a.txt",O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}

	int ret1 = lseek(fd,0,SEEK_END);
	if(ret1 == -1){
	perror("lseek");
	}else printf("a.txt size is = %d\n",ret1);

	int ret = truncate("./a.txt",5);
	if(ret == -1){
	perror("truncate");
	return -1;
	}else {
		ret1 = lseek(fd,0,SEEK_END);
		printf("a.txt size now is = %d\n",ret1);
	}
	return 0;
}

