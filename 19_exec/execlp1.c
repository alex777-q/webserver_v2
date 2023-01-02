#include<unistd.h>
#include<stdio.h>

int main(){

    printf("execlp begin**\n");
    if(execlp("ps","ps","-l",NULL) == -1){
        perror("execlp");
    }
    printf("execlp end**\n");
    return 0;
}