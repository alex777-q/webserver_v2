#include<iostream>
#include<sys/types.h>
#include<dirent.h>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
using namespace std;
int getFileNum(const char * path){

	DIR * dir = opendir(path);
	if(dir == NULL){
		perror("opendir");
		return 0;
	}

	struct dirent *ptr;

	int total = 0;

	while((ptr = readdir(dir)) != NULL){
		char * dname = ptr->d_name;

		if(strcmp(dname,".") == 0 || strcmp(dname,"..") == 0){
			continue;
		}

		if(ptr->d_type == DT_DIR){
			char newpath[256];
			sprintf(newpath, "%s/%s", path, dname);
			total += getFileNum(newpath);
		}

		if(ptr->d_type == DT_REG){
			total++;
		}

	}

	closedir(dir);

	return total;
}


int main(int argc, char **argv){

	int num = getFileNum(argv[1]);

	printf("普通文件的个数为：%d\n",num);



	return 0;
}
