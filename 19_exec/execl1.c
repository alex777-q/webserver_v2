#include<unistd.h>
#include<stdio.h>

int main(){


    // execl("hello", "hello", NULL);
    // sleep(1);
    // printf("i will show\n");
    printf("begin **\n");
    if(execl("hello","hello",NULL) == -1){
        // printf("execl failed!\n");
        perror("execl");
    }
    printf("after **\n");

    return 0;


}