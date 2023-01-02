/*
    #include<stdlib.h>
    void exit(int status);

    #include<unistd.h>
    void _exit(int status);

    status: imfomation when process exits can get, 
            when the father one recycle the child one
            can get

*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

    printf("hello\n");
    printf("world");

    // exit(0);
    _exit(0);

    return 0;
}