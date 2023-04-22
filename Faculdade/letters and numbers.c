#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
char c[100];
int K=0,nums=0,letters=0;
scanf("%[^\n]s",c);
while(c[K]!='\0'){
    if (isalpha(c[K])) {
    letters++;
    }
    else if (isdigit(c[K])) {
    nums++;}

    K++;
}
   printf("Total de letras: %d\nLetras: %d\nNumeros: %d",K,letters,nums);


}
