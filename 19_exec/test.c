#include<unistd.h>
#include<stdio.h>

int main(){

    printf("test begin**\n");
    if(execlp("ls","ls",NULL) == -1){
        perror("execl");
    }
    printf("test end**\n");
    return 0;
}