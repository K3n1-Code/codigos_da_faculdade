#include <stdio.h>

int main(){
    int times, num1,num2,biggest;

    scanf("%d",&times);
    while(times>0)
    {
        times--;
        scanf("%d%d",&num1,&num2);
        if(num1>num2){biggest=num1;}else if (num1==num2){printf("Iguais\n"); continue;}else{biggest=num2;}
        printf("Maior entre %d e %d : %d\n",num1,num2,biggest);

    }


}
