#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){

	int fd = open("./c.txt", O_RDWR);

	if(fd == -1){
		perror("open");
		return -1;
	}

	int ret = lseek(fd, 0, SEEK_SET);
	if(ret == -1){
		perror("lseek");
		return -1;
	}else printf("file ptr now is: %d\n",ret);

	ret = lseek(fd, 2, SEEK_CUR);
	if(ret == -1){
		perror("lseek");
		return -1;
	}else printf("file ptr now is: %d\n",ret);

	ret = lseek(fd, 10, SEEK_END);
	if(ret == -1){
		perror("lseek");
		return -1;
	}else printf("file ptr now is: %d\n",ret);

	close(fd);


	return 0;
}
