#include <stdio.h>
int main(){

 char start;
//printf(""); /* */ scanf("%c",&start);


    printf(" The Adventures of Starchild! \n Press \"Enter\" to proceed"); /* */ scanf("%c",&start);
    printf("Once upon a time, one of the most pretty stars there once were on the sky fell on earth"); /* */ scanf("%c",&start);
    printf("Its shine spread across all lands and tribes."); /* */ scanf("%c",&start);
    printf("A child, who saw the star falling on earth, decided to get closer"); /* */ scanf("%c",&start);
    printf("They raised their hand upon it"); /* */ scanf("%c",&start);
    printf("The star Asked for their name"); /* */ scanf("%c",&start);

    char child_name[32];

    printf("Type the Child's name: \n"); /* */ scanf("%s",&child_name);
    printf("\"Oh! %s, such a marvelous name!\"\n",child_name); /* */ scanf("%c",&start);
    printf("\"Dear %s, I ask for your help to return home. To the sky i fell, but once were\"",child_name); /* */ scanf("%c",&start);
    printf("Said the shining star to the little kid"); /* */ scanf("%c",&start);

    char choice1="";
    int choice_1=0;

    printf("Do you accept this quest?"); /* */ scanf("%c",&start);

    while(choice1!='y' && choice1!='n'){printf("type \"y\" or \"n\" to accept or Deny: \n"); /* */ scanf("%c",&choice1);}

    if(choice1=='y'){

    printf("Thank you my dear child. This favor will not be forgotten.\n"); /* */ scanf("%c",&start);
    choice_1=1;
    }

    if(choice1=='n'){
    printf("Farewell, begone then. \n"); /* */ scanf("%c",&start);
    return 1;
    }


        if(choice_1==1){

        printf("And so, the child grabbed the star and and held it"); /* */ scanf("%c",&start);
        printf("They asked how both could reach the sky"); /* */ scanf("%c",&start);
        printf("The star answered that they needed to reach the peak of the Sky Roaring Mountain"); /* */ scanf("%c",&start);
        printf("And just like this, then went on their adventure to return the Star to the skies"); /* */ scanf("%c",&start);
        printf("THE END"); /* */ scanf("%c",&start);

        }


    return 0;


}
