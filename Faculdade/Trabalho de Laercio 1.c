#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
char nome [60];
char cpf[12];
char dataDeNascimento [11];
float salarioBase;
float totalVendido;
} vendedor;

vendedor *CadastrarNovos(vendedor *vetor, int *quantidadeVendedorAtual);
void ListarVendedores(vendedor *vetor, int quantidadeVendedorAtual);
void CalcularComissoes(vendedor *vetor, int quantidadeVendedorAtual);
int buscarVendedor(vendedor *vetor, int quantidadeVendedorAtual, char *nomeBuscado);

int main () {
    FILE *save;
    vendedor *a;
    int n=0,option,o=-1,k=0;
    char m[60];


    save=fopen("sellers.file","rb");

    if(save==NULL){
        a= (vendedor *) malloc(sizeof(vendedor)*n );}
    else{

        a= (vendedor *) malloc(sizeof(vendedor)*++n );
        while(fread(&a[n-1],sizeof(vendedor),1,save)){
          a= (vendedor *) realloc(a,sizeof(vendedor)*++n );
          fseek(save,sizeof(vendedor)*n,SEEK_SET);


    }
    a= (vendedor *) realloc(a,sizeof(vendedor)*--n );
    }






    while(1){

    printf("O que deseja fazer? Digite a opção Desejada: ");
    scanf("%d",&option);


    switch(option){
    case 0:
      save=fopen("sellers.file","wb");
      if(save==NULL){printf("AAAAAAAAAAAAAA");}
      k=0;
      while(k<n){
            fwrite(&a[k],sizeof(vendedor),1,save);
            k++;
      }
      fclose(save);

      return 0;
      break;

    case 1:
      a=CadastrarNovos(a,&n);
      break;
    case 2:
       printf("Os vendedores: \n");
       ListarVendedores(a,n);

    break;
    case 3:
       CalcularComissoes(a,n);

    break;
    case 4:
       printf("Insira o nome do vendedor \n");
       scanf("%s",m);

       o=buscarVendedor(a,n,m);

       if(o!=-1){
         printf("\n%d", o);
         printf("\n%s", a[o].cpf);
         printf("\n%s", a[o].dataDeNascimento);
         printf("\n%.2f", a[o].salarioBase);
         printf("\n%.2f\n", a[o].totalVendido);

       }
    break;
    default: return -1;
    }}




}

vendedor *CadastrarNovos(vendedor *vetor, int *quantidadeVendedorAtual){
  int n,m=*quantidadeVendedorAtual;
  vendedor store;
  printf("\n Quantos deseja registar? ");
  scanf("%d",&n);


  vetor=(vendedor *)realloc(vetor, (sizeof(*vetor) + n*sizeof(vendedor)));


  while(*quantidadeVendedorAtual<n+m){
    printf("\nNome: ");
    scanf("%s",vetor[*quantidadeVendedorAtual].nome);
    printf("\nCpf: ");
    scanf("%s",vetor[*quantidadeVendedorAtual].cpf);
    printf("\nData de Nascimento: ");
    scanf("%s",vetor[*quantidadeVendedorAtual].dataDeNascimento);
    printf("\nSalário: ");
    scanf("%f",&vetor[*quantidadeVendedorAtual].salarioBase);
    printf("\nVendas: ");
    scanf("%f",&vetor[*quantidadeVendedorAtual].totalVendido);


    *quantidadeVendedorAtual+=1;
  }


  return vetor;

}

void CalcularComissoes(vendedor * vetor, int quantidadeVendedorAtual) {

    int i;

    printf("Comissoes:\n");

    for(i=0;i<quantidadeVendedorAtual;i++) {
        printf("%s: ", vetor[i].nome);
        printf("R$ %.2f\n", vetor[i].totalVendido * 0.03);

    }
}

void ListarVendedores(vendedor *vetor, int quantidadeVendedorAtual){

    int i;

    for (i=0;i<quantidadeVendedorAtual;i++) {

        printf("%s", vetor[i].nome);
        printf("\n%s", vetor[i].cpf);
        printf("\n%s", vetor[i].dataDeNascimento);
        printf("\n%.2f", vetor[i].salarioBase);
        printf("\n%.2f\n", vetor[i].totalVendido);

    }
}


int buscarVendedor(vendedor * vetor, int quantidadeVendedorAtual, char *nomeBuscado){

    int i=0,j=0,k;
    int ini = 0, meio=0, fim = quantidadeVendedorAtual -1;
    vendedor aux;
    if(quantidadeVendedorAtual>1){
    while(i<quantidadeVendedorAtual-1){j=0; while(j<quantidadeVendedorAtual-1){
    if(strcmp(vetor[j].nome,vetor[j+1].nome)>0){
        aux=vetor[j];
        vetor[j]=vetor[j+1];
        vetor[j+1]=aux;

    } j++;
    }i++;

    }}





while (ini <= fim) {

meio = (ini + fim)/2;

if (strcmp(nomeBuscado,vetor[meio].nome)<0) {
fim = meio-1;
}
else if (strcmp(nomeBuscado,vetor[meio].nome)>0) {
ini = meio+1;

}
else {

return meio;
}



}
printf("Vendedor inexistente\n");
return -1;

}
