#include <stdio.h>

void main(){
    int array[10],search,K=10,R=0;
    while(K>0){
    scanf("%d",&array[--K]);
    //printf("%d",K);
    }
    scanf("%d",&search);
    while(K<10){
    if(array[K]==search){R=1; break;}
    K++;}

    if(R){printf("Achei, posicao: %d", 10-K);}
    else{printf("Nao achei");}
}
