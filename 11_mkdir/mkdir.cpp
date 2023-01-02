#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<iostream>

int main(int argc, char *argv[]){
        // using namespace std;
        // char *pathname = {0};
        // cin>>pathname;

        char *pathname = argv[1];
        int ret = mkdir(pathname,0777);

        if(ret == -1){
                perror("mkdir");
                return -1;
        }else printf("new_mkdir create!\n");

        return 0;
}


