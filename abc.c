#include<stdio.h>

int main(){
    int p1,p2;
    p1 = fork();
    if(p1==0){
        sleep(2);
        printf("b\n");
    }
    else{
        p2=fork();
        if(p2==0){
            sleep(2);
            printf("c\n");
        }
        else{
            sleep(2);
            printf("a\n");
        }
    }
    return 0;
}
