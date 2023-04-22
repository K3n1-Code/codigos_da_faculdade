#include <stdio.h>

int main(){
    int end, current=1,before=0,K=0, sum=0;
    scanf("%d",&end);


    while(K<end){
        if(current%2==0){
            printf("%d ",current);
            sum+=current;
        }
        current+= before;
        before=current- before;

        K++;



    }

    if(sum!=0){printf("\n");}
    printf("%d", sum);
return 0;

};
