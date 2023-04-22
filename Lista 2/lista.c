#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){
*ap_lista=(No *)malloc(sizeof(No));

(*(*ap_lista)).prox=*ap_lista;
(*(*ap_lista)).antec=*ap_lista;

}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor){
    Lista ant;

    ant=(*ap_lista).antec;

    (*ap_lista).antec=(No *)malloc(sizeof(No));
    (*ant).prox=(*ap_lista).antec;
    (*(*ap_lista).antec).valor=valor;
    (*(*ap_lista).antec).antec=ant;
    (*(*ap_lista).antec).prox=ap_lista;


}
/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor){
    Lista p;

    p=(*ap_lista).prox;

    (*ap_lista).prox=(No *)malloc(sizeof(No));
    (*p).antec=(*ap_lista).prox;
    (*(*ap_lista).prox).valor=valor;
    (*(*ap_lista).prox).prox=p;
    (*(*ap_lista).prox).antec=ap_lista;

}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista){
    TipoDado valor;
    Lista lixo;

    lixo=(*ap_lista).antec;
    valor=(*lixo).valor;
    (*(*(*ap_lista).antec).antec).prox=ap_lista;
    (*ap_lista).antec=(*(*ap_lista).antec).antec;
    free(lixo);

    return valor;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista){
    TipoDado valor;
    Lista lixo;

    lixo=(*ap_lista).prox;
    valor=(*lixo).valor;
    (*(*(*ap_lista).prox).prox).antec=ap_lista;
    (*ap_lista).prox=(*(*ap_lista).prox).prox;
    free(lixo);

    return valor;


}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista.
 * Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    Lista caixa,caixa0;
    int ammount=0;

    caixa = (*ap_lista).prox;
    caixa0 = (*ap_lista).prox;

    while(caixa!=ap_lista){
        if(((*caixa).valor).grau==valor.grau &&((*caixa).valor).coef==valor.coef){
            caixa0=(*caixa).antec;
            (*caixa0).prox=(*caixa).prox;
            (*(*caixa0).prox).antec=caixa0;
            free(caixa);
            caixa=(*caixa0).prox;
            ammount++;
        }else{
        caixa=(*caixa).prox;

        }

    }

    return ammount;

}

/* Busca elemento valor na lista.
   Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor){
    Lista caixa,caixa0;
    int ammount=0;

    caixa = (*lista).prox;
    caixa0 = lista;

    while(caixa!=lista){
        if(((*caixa).valor).grau==valor.grau &&((*caixa).valor).coef==valor.coef){
            return ammount;
        }else{
        caixa=(*caixa).prox;
        ammount++;
        }

    }

    return -1;
}

/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau,
   e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau){
    Lista caixa,caixa0;
    int ammount=0;

    caixa = (*lista).prox;
    caixa0 = lista;

    while(caixa!=lista){
        if(((*caixa).valor).grau==grau){
            return ((*caixa).valor).coef;
        }else{
        caixa=(*caixa).prox;
        ammount++;
        }

    }

    return 0;


}

/* Imprime a lista na saida padrao, no formato:
   [(1,3),(2,3),(4,2),(3,1),(4,17)]
   em uma linha separada. */
void imprime(Lista lista){
    Lista caixa;

    caixa = (*lista).prox;

    printf("[");
    while(caixa!=lista){
        printf("(%d,%d)",((*caixa).valor).grau,((*caixa).valor).coef);
        if((*caixa).prox!=lista){
            printf(",");}
        caixa=(*caixa).prox;

    }
    printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista){
    Lista caixa;
    caixa = (*(*(*ap_lista)).prox).prox;

    printf("[");
    while(caixa!=*ap_lista){
            free((*caixa).antec);

        caixa=(*caixa).prox;
        }

    free(*ap_lista);

    *ap_lista=NULL;
    }

