#include<unistd.h>
#include<stdio.h>

char *env_init[] = {"AA = aa","BB = bb",NULL};
int main(){
    printf("execle begin**\n");
    if(execle("test1","test1",NULL,env_init) == -1){
        perror("execle");
    }
    printf("execle end**\n");
    return 0;
}