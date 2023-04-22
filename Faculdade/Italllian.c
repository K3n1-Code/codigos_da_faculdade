#include <stdio.h>

int main(){
    int start=0,K,num=1;
    scanf("%d",&K);

    while(K>0){
        printf("%d ",num);
        K--; num+=start; start=num-start;

    }


}
