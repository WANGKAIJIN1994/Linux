#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MSGKEY 75

struct msgform{
    long mtype;
    char mtext[256];
}msg;

void cleanup(int signo);
int msggid;

int main(){
    int i,pid,*pint;
    for(i=0;i<23;i++){
        signal(i,cleanup);
    }
    msggid = msgget(MSGKEY,0777|IPC_CREAT);
    printf("server:pid=%d\n",getpid());
    for(;;){
        msgrcv(msggid,&msg,256,1,0);
        pint = (int*)msg.mtext;
        pid = *pint;
        printf("server:receive from pid%d\n",pid);
        msg.mtype = pid;
        *pint = getpid();
         msgsnd(msggid,&msg,sizeof(int),0);
    }      
    return 0;
}
 
void cleanup(int signo){
    msgctl(msggid,IPC_RMID,0);
    exit(0);
}
