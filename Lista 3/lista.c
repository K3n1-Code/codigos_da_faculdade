/* Inicializa um polinômio vazio. */
#include "polinomio.h"
#include <stdlib.h>
void inicializa_polinomio(Polinomio * ap_pol){

*ap_pol=(No *)malloc(sizeof(No));

(*(*ap_pol)).prox=*ap_pol;
(*(*ap_pol)).antec=*ap_pol;

}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    Lista pointer,p_old,New;

    pointer=(*pol).prox;

    while(((*pointer).valor).grau<grau){
        if(pointer==pol){break;}

        pointer=(*pointer).prox;
    }

    p_old=(*pointer).prox;
    New=(Lista)malloc(sizeof(No));
    (*(*pointer).antec).prox=New;
    if(((*pointer).valor).grau==grau){
        (*New).prox=p_old;
        (*New).antec=(*pointer).antec;
        (*p_old).antec=New;
        if(pointer!=pol){free(pointer);}
    }else{
        (*New).prox=pointer;
        (*New).antec=(*pointer).antec;
        (*pointer).antec=New;
      }


    ((*New).valor).grau=grau;
    ((*New).valor).coef=coef;

    if(coef==0){
        (*(*New).antec).prox=(*New).prox;
        (*(*New).prox).antec=(*New).antec;
        free(New);
    }

}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){
 Lista pointer;

 pointer=(*pol).prox;

 while(pointer!=pol){
    pointer=(*pointer).prox;
    free((*pointer).antec);
 }

 inicializa_polinomio(&pol);

}

/* Computa a soma dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
    Lista point1,point2,soma;
    int found=0;
    inicializa_polinomio(&soma);

    point1=(*a).prox;
    point2=(*b).prox;

    while(point1!=a){

        define_coeficiente(soma,((*point1).valor).grau,((*point1).valor).coef);
        point1=(*point1).prox;
    }



    while(point2!=b){
        found=0;
        point1=(*a).prox;
        while(point1!=a){
            if(((*point2).valor).grau==((*point1).valor).grau){
            define_coeficiente(soma,((*point2).valor).grau,((*point1).valor).coef+((*point2).valor).coef);
            found=1;
            break;
            }else{
            point1=(*point1).prox;
        }}
        if(found==0){
            define_coeficiente(soma,((*point2).valor).grau,((*point2).valor).coef);
        }
        point2=(*point2).prox;
    }

    Lista pont;

    pont=(*res).prox;
    while(pont!=res){
        pont=(*pont).prox;
        free((*pont).antec);

    }

    (*res).prox=(*soma).prox;
    (*res).antec=(*soma).antec;
    free(soma);
    (*(*res).prox).antec=res;
    (*(*res).antec).prox=res;
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){
     Lista point1,point2,soma;
    int found=0;
    inicializa_polinomio(&soma);

    point1=(*a).prox;
    point2=(*b).prox;

    while(point1!=a){

        define_coeficiente(soma,((*point1).valor).grau,((*point1).valor).coef);
        point1=(*point1).prox;
    }



    while(point2!=b){
        found=0;
        point1=(*a).prox;
        while(point1!=a){
            if(((*point2).valor).grau==((*point1).valor).grau){
            define_coeficiente(soma,((*point2).valor).grau,((*point1).valor).coef-((*point2).valor).coef);
            found=1;
            break;
            }else{
            point1=(*point1).prox;
        }}
        if(found==0){
            define_coeficiente(soma,((*point2).valor).grau,-((*point2).valor).coef);
        }
        point2=(*point2).prox;
    }

    Lista pont;

    pont=(*res).prox;
    while(pont!=res){
        pont=(*pont).prox;
        free((*pont).antec);

    }

    (*res).prox=(*soma).prox;
    (*res).antec=(*soma).antec;
    free(soma);
    (*(*res).prox).antec=res;
    (*(*res).antec).prox=res;
}

/* /\* Computa a multiplicacao dos polinomios a e b colocando o resultado em res.  */
/*  * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. *\/ */
/* void multiplica(Polinomio res, Polinomio a, Polinomio b); */

/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5.
 */
void imprime(Polinomio pol){
    Lista pont;

    pont=(*pol).prox;
    printf("[");
    while(pont!=pol){
        printf("(%d,%d)",((*pont).valor).grau,((*pont).valor).coef);
        if((*pont).prox!=pol){ printf(",");}
        pont=(*pont).prox;


    }

    printf("]\n");
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol){
    Lista pont;

    pont=(*(*ap_pol)).prox;
    while(pont!=*ap_pol){
        pont=(*pont).prox;
        free((*pont).antec);
    }

    free((*ap_pol));


}
