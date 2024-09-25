#include<stdio.h>

#define MAX_LETRAS (134)

int main(){

    char nome[MAX_LETRAS];
    int count;

    printf("\nInsira seu nome:");
    scanf("%[^\n]", &nome);//[%^n] pega tudo incluindo os espaços

    for( count = 0; count < MAX_LETRAS; count++ ){

        if(nome[count] == '\0'){

            break;

        }


    } 

    printf("\n Existem %d caracteres:", count);

    return 0;

}