#include <stdio.h>
int finder(int *a, int find, int size){

  int K=0;
  while(K<size){
    if(a[K]==find){return 1;}else{K++;}
  }
  return 0;
  }

void repeating_numbers(int *a,int *b,int size){
  int K=0,K2=0,K3=0;

  while(K<size){
    K2=0;
    while(K2<size){
      if(K2==K){
        K2++;}
        else{
        if(a[K2]==a[K] && !finder(b,a[K2],size)){
          b[K3++]=a[K2];
        }
      }
      K2++;

  }
    K++;
  }
}


void main(){
int array[10]={1,1,2,3,4,5,5,7,7,7},s_array[10]={0,0,0,0,0,0,0,0,0,0},K=0;

repeating_numbers(array,s_array,10);

while(K<10){
  printf("%d, ",s_array[K++]);


}



}


