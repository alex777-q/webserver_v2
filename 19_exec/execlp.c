#include<stdio.h>
#include<unistd.h>

int main(){

    printf("execlp begin**\n");
    if(execlp("./hello","hello",NULL) == -1){
        perror("execlp");
    }
    printf("execlp end**\n");
    return 0;
}