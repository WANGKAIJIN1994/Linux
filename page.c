#include<stdio.h>
#include<stdlib.h>
#include"time.h"
#define pagenum 4

int getit(int page[4],int k){
    int i,tem;
    tem = k/10;
    for(i=0;i<pagenum;i++){
        if(page[i]==tem)
             return 1;
    }
    return 0;
}

int main(){
    int i,a[320],count = 0;
    int point = 0;
    int page[pagenum] = {-1};
    srand(time(NULL));
    a[0]=1.0*rand()/RAND_MAX*319+1;
    printf("this is sequence of instructioon\n");
    for(i=0;i<320;i++){
        if(i%4 == 1||i%4 == 3){
            a[i] = a[i-1] + 1;
        }
        if(i%4 == 2){
            a[i]=1.0*rand()/RAND_MAX*(a[i-1]-1)+1;  
        }
        if(i%4 == 0){
            a[i]=319-1.0*rand()/RAND_MAX*(a[i-1]-1); 
        }
        printf("%4d",a[i]);
    }
    for(i=0;i<320;i++){
        if(getit(page,a[i])){
            count++;
            printf("get page id :%2d,now page %2d, %2d, %2d, %2d\n",a[i]/10,page[0],page[1],page[2],page[3]);
        }
        else{
            page[point]=a[i]/10;//fifo
            point++;
            point = point%pagenum;
            printf("unget page id :%2d,now page %2d, %2d, %2d, %2d\n",a[i]/10,page[0],page[1],page[2],page[3]);
        }    
    }
    printf("%4f\n",(float)count/320);
}
