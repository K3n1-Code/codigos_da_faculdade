#include <stdio.h>
#include <string.h>

int main(){

    int cont=0;
    int r;
   int y;
   char palavra[50];
   char opalavra[50];

   scanf("%s%s",palavra,opalavra);
   for(r=0;r<strlen(palavra);r++){
    for(y=0;y<strlen(palavra);y++){

    if(opalavra[r]==palavra[y]){
   cont++;
    break;
    }


    }

}
if(strlen(palavra)==strlen(opalavra)){
cont == strlen(palavra)?printf("As palavras sao anagramas."):printf("Nao sao anagramas.");


}
else{
printf("Nao sao anagramas.");


}

return 0;
}
