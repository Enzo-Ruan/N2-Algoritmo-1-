#include <stdio.h>
#include <string.h>

#define MARCA_LEN  128
#define MODELO_LEN 128
#define PN_LEN     128
#define MAX_NOTES  1000

struct notebook_tag {
    char marca[MARCA_LEN];
    char modelo[MODELO_LEN];
    char pn[PN_LEN];
    int tela_polegadas;
    int tela_resolucao;
    int ram_gb;
    int ssd_gb;
    int hd_gb;
    int quantidade;
    float valor;
};

typedef struct notebook_tag notebook_t;

int verificar_pn_unico(notebook_t *notebooks, int total, const char *pn) {
    for (int i = 0; i < total; i++) {
        if (strcmp(notebooks[i].pn, pn) == 0) {
            return 0; 
        }
    }
    return 1; 
}

void cadastrar_produto(notebook_t *notebooks, int *total) {
    notebook_t *nb = &notebooks[*total];
    char pn_temporario[PN_LEN];

    printf("\n\t Marca: ");
    scanf("%s", nb->marca);

    printf("\n\t Modelo: ");
    scanf("%s", nb->modelo);

    do {
        printf("\n\t PN (Part Number, único): ");
        scanf("%s", pn_temporario);

        if (!verificar_pn_unico(notebooks, *total, pn_temporario)) {
            printf("\n\t [ERRO] PN já cadastrado! Tente novamente.\n");
        } else {
            strcpy(nb->pn, pn_temporario);
            break;
        }
    } while (1);

    printf("\n\t Tamanho da tela (polegadas): ");
    scanf("%d", &nb->tela_polegadas);

    printf("\n\t Resolução da tela (pixels): ");
    scanf("%d", &nb->tela_resolucao);

    printf("\n\t RAM (GB): ");
    scanf("%d", &nb->ram_gb);

    printf("\n\t HD (GB): ");
    scanf("%d", &nb->hd_gb);

    printf("\n\t SSD (GB): ");
    scanf("%d", &nb->ssd_gb);

    printf("\n\t Quantidade: ");
    scanf("%d", &nb->quantidade);

    printf("\n\t Valor: ");
    scanf("%f", &nb->valor);

    printf("\n\n PRODUTO CADASTRADO COM SUCESSO!");
    (*total)++;
}

void consultar_por_marca(notebook_t *notebooks, int total) {
    char marca_pesquisa[MARCA_LEN];
    int encontrado = 0;

    printf("\n\t Digite a marca para pesquisar: ");
    scanf("%s", marca_pesquisa);

    for (int i = 0; i < total; i++) {
        if (strcmp(notebooks[i].marca, marca_pesquisa) == 0) {
            printf("\n\t [Encontrado] PN: %s, Modelo: %s, Quantidade: %d, Valor: %.2f",
                   notebooks[i].pn, notebooks[i].modelo, notebooks[i].quantidade, notebooks[i].valor);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\n\t Nenhum produto encontrado para a marca '%s'.\n", marca_pesquisa);
    }
}

void consultar_por_modelo(notebook_t *notebooks, int total) {
    char modelo_pesquisa[MODELO_LEN];
    int encontrado = 0;

    printf("\n\t Digite o modelo para pesquisar: ");
    scanf("%s", modelo_pesquisa);

    for (int i = 0; i < total; i++) {
        if (strcmp(notebooks[i].modelo, modelo_pesquisa) == 0) {
            printf("\n\t [Encontrado] PN: %s, Marca: %s, Quantidade: %d, Valor: %.2f",
                   notebooks[i].pn, notebooks[i].marca, notebooks[i].quantidade, notebooks[i].valor);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\n\t Nenhum produto encontrado para o modelo '%s'.\n", modelo_pesquisa);
    }
}

void consultar_por_pn(notebook_t *notebooks, int total) {
    char pn_pesquisa[PN_LEN];
    int encontrado = 0;

    printf("\n\t Digite o PN para pesquisar: ");
    scanf("%s", pn_pesquisa);

    for (int i = 0; i < total; i++) {
        if (strcmp(notebooks[i].pn, pn_pesquisa) == 0) {
            printf("\n\t [Encontrado] Marca: %s, Modelo: %s, Quantidade: %d, Valor: %.2f",
                   notebooks[i].marca, notebooks[i].modelo, notebooks[i].quantidade, notebooks[i].valor);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\t Nenhum produto encontrado para o PN '%s'.\n", pn_pesquisa);
    }
}

int main() {
    notebook_t notebooks[MAX_NOTES];
    int total_cadastrados = 0;
    int opcao;

    while (1) {
        printf("\n\n--- Menu ---");
        printf("\n 1. Cadastrar produto");
        printf("\n 2. Consultar por marca");
        printf("\n 3. Consultar por modelo");
        printf("\n 4. Consultar por PN");
        printf("\n 0. Sair");
        printf("\n Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            if (total_cadastrados < MAX_NOTES) {
                cadastrar_produto(notebooks, &total_cadastrados);
            } else {
                printf("\n\t Limite máximo de produtos atingido.\n");
            }
            break;
        case 2:
            consultar_por_marca(notebooks, total_cadastrados);
            break;
        case 3:
            consultar_por_modelo(notebooks, total_cadastrados);
            break;
        case 4:
            consultar_por_pn(notebooks, total_cadastrados);
            break;
        case 0:
            printf("\n\t Saindo...\n");
            return 0;
        default:
            printf("\n\t Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}