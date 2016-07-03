#include<stdio.h>
#include<stdlib.h>

int main(){
    int p1,p2,i;
    p1 = fork();
    if(p1==0){
        lockf(1,1,0);
        for(i=0;i<10;i++)
            printf("parent%d\n",i);
        lockf(1,0,0);
        wait(0);
        exit(0);
    }
    else{
        p2=fork();
        if(p2==0){
            lockf(1,1,0);
            for(i=0;i<10;i++)
                printf("son%d\n",i);
            lockf(1,0,0);
            wait(0);
            exit(0);
        }
        else{
            sleep(1);
            lockf(1,1,0);
            for(i=0;i<10;i++)
                printf("grandchild%d\n",i);
            lockf(1,0,0);
            exit(0);
        }
    }
    return 0;
}
