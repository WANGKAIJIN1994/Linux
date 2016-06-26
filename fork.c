#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int shared = 0;//global

int main(){
    //int shared = 0;local
    int i,j;
    pid_t id;
    id = fork();
    if(id>0){
      for(i=0;i<5;i++){
        shared++;    
        printf("shared:%d,pid:%d\n",shared,id);
      }
    }
    else if(id==0){
      for(j=0;j<5;j++){
        shared--;
        printf("shared:%d,pid:%d\n",shared,id);
      }
    }
    return 0;
}
