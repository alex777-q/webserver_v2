#include<unistd.h>
#include<stdio.h>

extern char **environ;
int main(){

    int i = 0;
    char **ptr;
    for(ptr == environ; ptr != 0; ptr++){
        printf("%s\n",*ptr);
    }
    return 0;
}