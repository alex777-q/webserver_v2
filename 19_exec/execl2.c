#include<unistd.h>
#include<stdio.h>

int main(){
    //和test.c嵌套调用
    printf("execl begin**\n");
    if(execl("test","test", NULL) == -1){
        perror("execl");
    }
    printf("execl after**\n");
    return 0;
}