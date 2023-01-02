#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(){

	pid_t pid = fork();

	if(pid > 0){
		printf("pid = %d\n",pid);
		printf("i am father process,pid: %d,ppid: %d\n",getpid(),getppid());

	}
	else if(pid == 0){
		printf("i am child process,pid: %d,ppid: %d\n",getpid(),getppid());

	}
	for(int i = 0; i < 3; i++){
		printf("%d\n",i);
		//sleep(1);
	}

	return 0;
}
