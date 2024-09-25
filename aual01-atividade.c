#include<stdio.h>
#include<string.h>

#define MAX_LETRAS (125)

int main(){

    char nome[MAX_LETRAS];
    char nomeADM[40] = "Enzo Ruan";

    printf("\n Insira seu nome:");
    scanf("%[^\n]", &nome);

    if(strcmp(nome, nomeADM) == 0){

        printf("Ola ADM %s", nomeADM);

    } else{

        printf("Voce nao tem acesso");
    }

}