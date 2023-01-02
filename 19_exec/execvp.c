#include<unistd.h>
#include<stdio.h>

int main(){

    printf("execvp begin**\n");
    char *argv[] = {"man","execvp",NULL};
    if(execvp("man",argv) == -1){
        perror("execvp");
    }
    printf("execvp end**\n");
    return 0;
}