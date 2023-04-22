#include <stdio.h>

//Sempre que você precisar ler uma matriz:
void read_array(int *array, int lenght){
  int K=0;

  while(K<lenght){
    scanf("%d",&array[K]);
    K++;
  }


}

int main(){
  int A[10],highest[2],K=0,K2=0,m_K2=3,boolean=0,equal=0;
  read_array(A,10);

   while(K<9){
    if(A[K]==A[K+1]){equal=1;}else{equal=0; break;}
    K++;
   }


  if(equal==0){
  while(K2<m_K2){
    highest[K2]=A[0]-K2;
    K=0;

    while(K<10){
        boolean=0;
        if(K2>0){
          if(highest[K2]<highest[K2-1]){boolean=1;
          if(A[K]==highest[K2-1]){boolean=0;}
          }
          }else{
          boolean=1;
        }

        if(highest[K2]<A[K] && boolean==1){highest[K2]=A[K]; }
        K++;
    }
    K2++;
  }

  printf("Maior: %d \nSegundo maior: %d",highest[0],highest[1]);
  }else{printf("Maior: %d",A[0]);}


}


//Forma mais eficiente de organizar: Pular *POZIÇÃO* do maior
