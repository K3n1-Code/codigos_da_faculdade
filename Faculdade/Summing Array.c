#include <stdio.h>

int main(){
   int w=0,h=0,A[3][3];

   while(w<3){
    h=0;
    while(h<3){
        scanf("%d",&A[w][h]);
        h++;
    }
    w++;
   }

   h=0;

   while(h<3){
    printf("%d %d %d Soma da linha %d: %d\n",A[h][0],A[h][1],A[h][2],h+1,A[h][0]+A[h][1]+A[h][2]);
    h++;

   }



}
