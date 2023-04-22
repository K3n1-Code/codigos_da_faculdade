#include <stdio.h>

int isnt_prime(int K){
 int Sd=0,box=K;

while(K>0){
    if(box%K==0){Sd++;}
    K--;
}

return Sd - 2;
}

int mmc_simplified(int mmc[]){
 int K=0,verify=1;


while(K<20){

    if(mmc[K]!=1){verify=0; break;}
    K++;

}

return verify;




}


int main(){

    int input,box,K=0,A=2,R=1,skip=0,mmc[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    scanf("%d", &input);
    box=input;

    while(K<input){
        mmc[K]=box--;
        K++;
    }

    while(!mmc_simplified(mmc)){
    if(!isnt_prime(A)){
        K=0;
        while(K<20){
          if(mmc[K]%A==0 && mmc[K]!=1){mmc[K]/=A;}else{skip++;}
          K++;
        }

        if(skip>=20){A++; skip=0;}else{R*=A;}



    }else{A++; skip=0;}

    skip=0;
    }

    printf("%d", R);
}
