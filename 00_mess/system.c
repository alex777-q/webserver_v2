/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-08 19:57:59
 * @LastEditors: lls
 * @LastEditTime: 2022-12-08 20:08:13
 * @Descripttion: 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char fifo[10] = "fifo";
    strcpy(fifo,"fifo");
    char buf[10];
    strcpy(buf,"rm ");
    strcat(buf,fifo);
    system(buf);
    return 0;
}