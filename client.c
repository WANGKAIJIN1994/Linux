#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MSGKEY 75

struct msgform{
    long mtype;
    char mtext[256];
};

int main(){
    struct msgform msg;
    int msggid,pid,*pint;
    msggid = msgget(MSGKEY,0777);
    pid = getpid();
    printf("client:pid=%d\n",pid);
    pint = (int*)msg.mtext;
    *pint = pid;
    msg.mtype = 1;
    msgsnd(msggid,&msg,sizeof(int),0);
    msgrcv(msggid,&msg,256,pid,0);
    printf("client:receive from pid%d\n",*pint); 
    return 0;
}
