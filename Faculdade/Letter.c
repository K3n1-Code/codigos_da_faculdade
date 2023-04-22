#include <stdio.h>
#include <ctype.h>

int main(){
    char a[100];
    int K=0;
    scanf("%[^\n]s",a);
    while(a[K]!='$'){
        if(a[K]==' '){K++; continue;}

        if (isalpha(a[K])) {
        switch(a[K]){
        case 'a': case 'e': case 'o': case 'i': case 'u': printf("Vogal.\n"); break;
        default: printf("Consoante.\n"); break;


        }
    }
    else {
    printf("Nao e uma letra do alfabeto.\n");

    }
        K++;}




}
