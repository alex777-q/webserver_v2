#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>

void if_printf(int val){

	if(val == 0)  printf("a.txt can ");
	else printf("a.txt can not ");
}

int main(){

	int ret = chmod("./a.txt",0222);
	if(ret == -1){
		perror("chmod");
		// return -1;
	}
	else{
		int ret1 = access("./a.txt",R_OK);
		if_printf(ret1);
		printf("read\n");

		ret1 = access("./a.txt",W_OK);
		if_printf(ret1);
		printf("write\n");

		ret1 = access("./a.txt",X_OK);
		if_printf(ret1);
		printf("X\n");

	}

	return 0;

}
