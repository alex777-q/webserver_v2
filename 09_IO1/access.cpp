#include<unistd.h>
#include<stdio.h>

int main(){

	int ret = access("./a.txt",R_OK);
	if(ret == -1){
		perror("access");
	}
	else printf("a.txt can read!\n");


	ret = access("./b.txt",W_OK);
	if(ret == -1){
		perror("access");
	}
	else printf("b.txt can write!\n");

	ret = access("./c.txt",X_OK);
	if(ret == -1){
		perror("access");
	}
	else printf("c.txt can X!\n");

	ret = access("./d.txt",F_OK);
	if(ret == -1){
		perror("access");
	}
	else printf("d.txt exited!\n");


	

	return 0;

}
