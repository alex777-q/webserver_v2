#include<stdio.h>

int main(){
	
	int ret = rename("11_rename1", "12_rename1");
	if(ret == -1){
		perror("rename");
		return -1;
	}
	printf("now the file is 11_name1.\n");
	
	return 0;
}