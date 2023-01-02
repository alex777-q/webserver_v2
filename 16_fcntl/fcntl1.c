/*

F_DUPFD (int)
              Duplicate the file descriptor fd using the lowest-numbered avail‐
              able  file descriptor greater than or equal to arg.  This is dif‐
              ferent from dup2(2), which uses exactly the file descriptor spec‐
              ified.

              On success, the new file descriptor is returned.

              See dup(2) for further details.

F_GETFD (void)
              Return (as the function result) the file descriptor flags; arg is
              ignored.

F_SETFD (int)
              Set the file descriptor flags to the value specified by arg.

*/

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char ** argv){
	int fd = open("test.txt",O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}

	int ret = fcntl(fd, F_DUPFD);
	if(ret == -1){
		perror("fcntl");
		return -1;
	}

	close(fd);
	
	char buff[1024] = {0};
	int len = read(ret,buff,sizeof(buff));
	if(len == -1){
		perror("read");
		return -1;
	}
	
	printf("%s",buff);
	close(ret);
	return 0;

}
