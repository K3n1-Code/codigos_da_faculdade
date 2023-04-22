#include <stdio.h>
#include <stdlib.h>
typedef struct{

char nome[30];
float nota;


} Aluno;

void swap(Aluno *a, int x, int y){
Aluno box;
box=a[x];
a[x]=a[y];
a[y]=box;


}
void sort(Aluno *array,int L,int R){
int i,j,am;
i=L;
j=R;
am=array[(i+j)/2].nota;
do{
    while(array[i].nota<am) {i++;}
    while(array[j].nota>am) {j--;}
        if(i<=j){
            swap(array,i,j);
            i++;
            j--;
        }
}while(i<=j);
if(L<j){sort(array,L,j);}
if(R>i){sort(array,i,R);}


}



int main(){
Aluno alunos[15];
int I=0,k=7,k2=0;
float pick;

while(I<15){
    printf("Nome: ");
    scanf("%s",alunos[I].nome);
    printf("Nota: ");
    scanf("%f",&alunos[I].nota);
    I++;

}

scanf("%f",&pick);
sort(alunos,0,14);

while(alunos[k].nota!=pick){
    if(pick>alunos[k].nota){k2++; k+=15/(k2+1);}
    if(pick<alunos[k].nota){k2++; k-=15/(k2+1);}

    if((15/k2)==0){printf("Not found"); break;}
}

printf("Aluno> %s, nota: %d",alunos[k].nome,alunos[k].nota);


}
