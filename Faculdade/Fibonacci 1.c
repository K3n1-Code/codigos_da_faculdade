#include <stdio.h>

int main(){
    int start, end, current=1,before=0,K=0;
    scanf("%d%d",&start,&end);


    while(K<end){
        if(K>= start-1){
            printf("%d ",current);
        }
        current+= before;
        before=current- before;

        K++;



    }

return 0;

};
