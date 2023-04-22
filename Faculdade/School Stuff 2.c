#include <stdio.h>
int main(){
    int use, use_a, flag, user;
    float Flag_Val[24]={0.62833, 0.64333, 0.66833, 0.68833, 0.19712, 0.20237, 0.21112, 0.21812, 0.33793, 0.34693, 0.36193, 0.37393, 0.50689, 0.52039, 0.54289, 0.56089, 0.56321, 0.57821, 0.60321, 0.62321, 0.34559, 0.36059, 0.38559, 0.40559};
    //Chorei de ter que copiar esses números à mão do site porque ele tinha caracteres invisiveis TvT
    scanf("%d\n%d\n%d",&use,&flag,&user);
    float bill=0, ilumination=0, taxes=0, total=0;
    flag--;
    use_a=use;

    switch(user){
        case 1:
            if(use>=30){bill+=30*Flag_Val[flag+4]; use-=30;}else{bill+=use*Flag_Val[flag+4]; use=0;}
            if(use>=70){bill+=70*Flag_Val[flag+8]; use-=70;}else{bill+=use*Flag_Val[flag+8]; use=0;}
            if(use>=120){bill+=120*Flag_Val[flag+12]; use-=120;}else{bill+=use*Flag_Val[flag+12]; use=0;}
            bill+=use*Flag_Val[flag+16]; use=use_a;

        break;
        case 2:
            bill=use*Flag_Val[flag];

        break;

    }
    ilumination=use*Flag_Val[flag+20];
    taxes=(bill+ilumination)*0.37;
    total=bill+ilumination+taxes;
    printf("Valor da conta: %.2f \nIluminacao: %.2f \nValor dos impostos: %.2f \nValor total da conta: %.2f",bill,ilumination,taxes,total);
    return 0;
}
