#include <stdio.h>
#include <stdlib.h>

int main(){
FILE *search_file,*save_file;
char *nat;
int K=0;

nat= (char *)malloc(sizeof(char)*20);

search_file=fopen("Folder/Origem.txt", "r");
save_file=fopen("Folder/Destino.txt","w");

if (search_file != NULL){

    while(K<12){
    fscanf(search_file,"%s\n",nat);
    printf("%s\n",nat);
    fprintf(save_file,"%s\n",nat);
    K++;
    }


}

fclose(save_file);


}
