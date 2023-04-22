#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicializa_lista(Lista *ap_lista){
    *ap_lista=NULL;
}
/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor){
    Lista L,var;

    L=*ap_lista;


    while(L!=NULL){
        if((*L).proximo==NULL){
            break;
        }else{
        L=(*L).proximo;
    }}


    var=(No *)malloc(sizeof(No));
    if(*ap_lista==NULL){*ap_lista=var;}
    else{(*L).proximo=var;}
    L=var;

    (*L).proximo=NULL;
    (*L).valor=valor;}

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor){

    Lista L,var;

    L=*ap_lista;

    *ap_lista=(No *)malloc(sizeof(No));
    var=*ap_lista;
    (*var).proximo=L;
    (*var).valor=valor;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista){
Lista L,var;
int val;
    L=*ap_lista;
    if((*L).proximo==NULL){
    val=(*L).valor;
    free(L);
    *ap_lista=NULL;
    return val;
    }
    while(L!=NULL){

        if((*L).proximo==NULL){
            break;
        }else{
        var=L;
        L=(*L).proximo;
    }}
    val=(*L).valor;
    free(L);

    (*var).proximo=NULL;
    return val;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
int remove_inicio(Lista * ap_lista){

    Lista L;

    L=*ap_lista;

    *ap_lista=(*L).proximo;
    free(L);

}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista.
 * Retorna o numero de ocorrencias removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor){
    Lista L,K;

    inicializa_lista(&L);
    K=*ap_lista;
    while(K!=NULL){
        if((*K).valor!=valor){
            insere_fim(&L,(*K).valor);
        }
        K=(*K).proximo;
    }
    remove_inicio(&L);
    desaloca_lista(ap_lista);
    *ap_lista=L;
}

/* Busca elemento valor na lista.
   Retorna a posição na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado.
*/
int busca(Lista lista, int valor){

   Lista L;
    int ammount=0;
    L=lista;

    while(L!=NULL){
        if((*L).valor==valor){

            break;
        }
        ammount++;
        L=(*L).proximo;
    }
    if(L==NULL){
        ammount=-1;
    }
    return ammount;
}

/* Imprime a lista na saida padrao, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
 */
void imprime(Lista lista){
   Lista L;
   int a;
    int ammount=0;
    L=lista;
    printf("(");
    while(L!=NULL){
        printf("%d",(*L).valor);
        if((*L).proximo!=NULL){
        printf(",");
        }
        L=(*L).proximo;
        
    }
    printf(")\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista){
   Lista L,var;
    int ammount=0;
    L=*ap_lista;
    while(L!=NULL){
        var=L;
        L=(*L).proximo;
        free(var);
    }
}
