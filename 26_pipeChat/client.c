/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-08 17:21:46
 * @LastEditors: lls
 * @LastEditTime: 2022-12-08 20:40:00
 * @Descripttion: 
 */
 
#include"head.h"
#include"datatype.h"

void sys_error(const char *e){
    perror(e);
    exit(1);
}

int fifofd = 0;

void *tfn(void *p);

int main(int argc, char **argv){
#define BUF_SIZE (1024)
    int ret = 0;
    char buf[BUF_SIZE];
    pthread_t tid;
    if(argc != 4){
        fprintf(stderr,"Usage:%s  serverfifoname username fifoname\n",argv[0]);
        exit(1);
    }

    printf("Connect to sever...\n");
    fifofd = open(argv[1], O_WRONLY);
    if(fifofd == -1){
        sys_error("open error");
    }
    printf("Connect to server success\n");
    struct msg_type m;
    memset(&m, 0, sizeof(m));
    m.msgType = MSG_TYPE_REGISTRATION;
    strncpy((m.data.user.userName),argv[2],sizeof((m.data.user.userName)));
    strncpy((m.data.user.fifoName),argv[3],sizeof(m.data.user.fifoName));
    m.data.user.id = getpid();
    write(fifofd, &m, sizeof(m));  // why not strlen(m)??

    ret = mkfifo(argv[3], 0666);
    if(ret == -1){
        if(errno == EEXIST){
            printf("user fifo already exist\n");
        }
        else{
            sys_error("mkfifo error");
        }
    }
    int myfifo = open(argv[3], O_RDWR);
    if(myfifo == -1){
        sys_error("open error");
    }
    ret = pthread_create(&tid, NULL, tfn, (void*)argv[2]);

    while(1){
        // read msg from my fifo
        char buf[BUF_SIZE];
        memset(buf, 0, sizeof(buf));
        int ret = read(myfifo, buf, BUF_SIZE-1);
        if(ret == 0){
            printf("no more data\n");
            return 0;
        }
        if(ret > 0){
            printf("%s\n",buf);
        }
    }
    pthread_join(tid, NULL);
    return 0;
}

//send msg from common fifo
void *tfn(void *p){
    struct msg_type m;
    m.data.commonMsg.id = getpid();
    // char cmd[20] = "rm -f ";
    // strcat(cmd, m.data.user.fifoName);
    while(1){
        memset(&(m.data.commonMsg.buf), 0, sizeof(m.data.commonMsg.buf));
        fgets(m.data.commonMsg.buf, sizeof(m.data.commonMsg.buf), stdin);
        int len = strlen(m.data.commonMsg.buf);
        m.data.commonMsg.buf[len--] = 0;  // do not send '\n'
        m.data.commonMsg.datalen = len;
        if(len){
            if(0 == strncmp("quit", m.data.commonMsg.buf, 4)){
                m.msgType = MSG_TYPE_QUIT;
                write(fifofd, &m, sizeof(m));
                // system(cmd);
                exit(0);
            }
            else{
                m.msgType = MSG_TYPE_COMMON_MSG;
                len = write(fifofd, &m, sizeof(m));
            }
        }
        if(len == -1){
            sys_error("write error");
        }
    }
}