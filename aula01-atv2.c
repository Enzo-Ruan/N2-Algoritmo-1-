#include<stdio.h>
#include<string.h>

#define MAX_LETRAS (125)

int main(){

    char nome[MAX_LETRAS];
    char nomeADM[40] = "Enzo Ruan";
    char saldo[] = "Seu saldo e de: 1000\n";
    char negado[] = "Acesso negado\n";
    char info[100];
    
    printf("\n Insira seu nome de usuario:\n");
    scanf("%[^\n]", &nome);


    if(strcmp(nome, nomeADM) == 0){

        strcpy(info, saldo);
        printf("%s", info);
    } else{

        strcpy(info, negado);
        printf("%s", info);
    }
    
}
