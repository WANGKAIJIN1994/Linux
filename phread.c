#include<stdio.h>
#include<pthread.h>
void testphread1(int *shared){
    int i;
    for(i=0;i<5;i++){
        sleep(1); (*shared)++;
        printf("child1:%d,shared:%d  ",i,*shared);
    }
}
void testphread2(int *shared){
    int s;
    for(s=0;s<5;s++){
        sleep(1); (*shared)++;
        printf("child2:%d,shared:%d  ",s,*shared);
    }
}
int main(){
    int j,err1,err2;
    int shared = 0;
    pthread_t id1,id2;
    err1 = pthread_create(&id1,NULL,(void*)testphread1,&shared);
    err2 = pthread_create(&id2,NULL,(void*)testphread2,&shared);
    if(err1 !=0||err2!=0){
        printf("%d\n",strerror(err1));
        printf("%d\n",strerror(err2));
    }
    for(j=0;j<5;j++){
        sleep(1); shared--;
        printf("main:%d,shared:%d  ",j,shared);
    }  
    return 0;
}
