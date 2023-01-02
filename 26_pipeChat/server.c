/*
 * @Author: lls
 * @email: lls840308420@163.com
 * @Date: 2022-12-08 17:02:02
 * @LastEditors: lls
 * @LastEditTime: 2022-12-08 19:42:08
 * @Descripttion: 
 */

#include"head.h"
#include"datatype.h"

void sys_error(const char * e){
    perror(e);
    exit(1);
}

struct user_list{
    struct user_info user;
    int userfifo;
    struct user_list *next;
};

struct user_list *user_list_head = NULL;

pthread_mutex_t mutex;

void *registerFn(void *p);
int cnt = 0;

int main(int argc, char ** argv){
#define BUF_SIZE (1024)
    int ret = 0;
    if(argc != 2){
        fprintf(stderr, "Usage: argv[%s] fifo name\n",argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutex, NULL);
    registerFn((void*)argv[1]);
    pthread_mutex_destroy(&mutex);
    return 0;
}

void *clientThread(void *p);

void sendMsgToClient(struct msg_type *m, char *msg, int msglen);

void *registerFn(void *p){

    //open server's fifo
    //listen register_info
    int ret = 0;
    char *serverfifoname = (char *)p;

    ret = mkfifo(serverfifoname, 0666);
    if(ret == -1){
        if(errno == EEXIST){
            printf("server fifo already exist\n");
        }
        else{
            perror("mkfifo error");
        }
    }

    int fifofd = open(serverfifoname, O_RDONLY);
    if(fifofd == -1){
        sys_error("open error");
    }

    struct msg_type m;

    while(1){

        memset(&m, 0, sizeof(m));  // sizeof(struct)??
        int len = read(fifofd, &m, sizeof(m));
        if(len == -1){
            sys_error("read error");
        }
        if(len == 0){
            printf("Server: no client\n");
            return 0;
        }
        if(len > 0){
            if(m.msgType == MSG_TYPE_REGISTRATION){
            #define ENTERCHATROOM " enter chat room."
                printf("new user : %s fifoname %s\n",m.data.user.userName, m.data.user.fifoName);
                struct user_list *u = (struct user_list *)malloc(sizeof(struct user_list));
                if(!u){
                    continue;
                }
                memset(u, 0, sizeof(struct user_list));
                strncpy(u->user.userName, m.data.user.userName, sizeof(m.data.user.userName));
                strncpy(u->user.fifoName, m.data.user.fifoName, sizeof(m.data.user.fifoName));
                u->user.id = m.data.user.id;
                u->userfifo = open(u->user.fifoName, O_RDWR);
                if(u->userfifo == -1){
                    printf("open user fifo error\n");
                }
                pthread_mutex_lock(&mutex);
                u->next = user_list_head;
                user_list_head = u;
                pthread_mutex_unlock(&mutex);
                char tmp[64+18+1];
                CLEAR_ARRAY(tmp);
                snprintf(tmp, sizeof(tmp)-1, "%s %s", m.data.user.userName,ENTERCHATROOM);
                sendMsgToClient(&m, tmp, strlen(tmp));            
            }
            else if(m.msgType == MSG_TYPE_COMMON_MSG){
                //send msg to other members of chat room
                printf("get a new message user id = %d, len = %d\n",m.data.commonMsg.id, m.data.commonMsg.datalen);
                sendMsgToClient(&m, m.data.commonMsg.buf, m.data.commonMsg.datalen);
            }
            else if(m.msgType == MSG_TYPE_QUIT){
            #define STRLEAVE "leaves chatroom"
                sendMsgToClient(&m, STRLEAVE, strlen(STRLEAVE));
                void deleteClient(int pid);
                deleteClient(m.data.commonMsg.id);
            }
        }
    }
}

void sendMsgToClient(struct msg_type *m, char *msg, int msglen){
    struct user_list *p = user_list_head;
    char s[65];
    memset(s, 0, sizeof(s));
    
    // get userName of sender
    while(p){
        if(p->user.id == m->data.commonMsg.id){
            strcpy(s, p->user.userName);
            strcat(s, ":");
            break;
        }
        p = p->next;
    }
    p = user_list_head;

    //send msg to other members of char room
    while(p){
        if(p->user.id != m->data.commonMsg.id && p->user.id != m->data.user.id){
            write(p->userfifo, s, strlen(s));
            int len = write(p->userfifo, msg, msglen);
            // printf("server send to [%d] write len = %d\n",p->user.id, len);
        }
        p = p->next;
    }
}

void deleteClient(int pid){

    struct user_list *prev = user_list_head;
    if(user_list_head->user.id == pid){
        user_list_head = user_list_head->next;
        free(prev);
    }
    else{
        for(struct user_list *k = user_list_head; k; k = k->next){
            if(k->user.id == pid){
                prev->next = k->next;
                free(k);
                break;
            }
            prev = k;
        }
    }
}

void *clientThread(void *p){

    // listen client's fifo
    // read and send to other members
    // realize net-chatroom
    struct user_list *client = (struct user_list *)p;
    int clientFifo = open(client->user.fifoName, O_RDWR);
    if(clientFifo == -1){
        printf("open error\n");
    }

    return NULL;
}
