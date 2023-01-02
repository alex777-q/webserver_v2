#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
int main(int argc, char *argv[]){
	char *pathname = argv[1];
	int ret = rmdir(pathname);

	if(ret == -1){
		perror("rmdir");
		return -1;
	}else printf("empty new_mkdir is deleted!\n");

	return 0;
}
