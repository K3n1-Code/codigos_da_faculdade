#include <stdio.h>
int main(){
int N,sum=0,K = 1;

scanf("%d",&N);

while(K <= N){
    if(K % 3 ==0||K % 5 == 0) {

    sum += K;
    printf("%d ",K);

    }
K++;



}
if(sum != 0){
 printf("\n");
}
 printf("%d ",sum);
return 0;
}

