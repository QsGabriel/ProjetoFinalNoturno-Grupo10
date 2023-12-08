#include <stdio.h>
#include <string.h>

#define NUM_QUARTOS 10
#define TAM_NOME 50

int i = 0;
typedef struct {
    char nome[TAM_NOME];
    int quarto;
} Hospede;

// Função para inserir um novo hóspede em um quarto vazio
void inserirHospede(Hospede hospedes[], int numeroQuarto) {
    if (hospedes[numeroQuarto - 1].quarto == 0) {
        hospedes[numeroQuarto - 1].quarto = numeroQuarto;
        printf("Digite o nome do hospede: ");
        scanf("%s", hospedes[numeroQuarto - 1].nome);
        printf("Hóspede inserido no quarto %d com sucesso.\n", numeroQuarto);
    } else {
        printf("O quarto %d está ocupado. Escolha outro quarto.\n", numeroQuarto);
    }
}

void listarHospedes(Hospede hospedes[]) {
    printf("Lista de Hospedes:\n");
    for (int i = 0; i < NUM_QUARTOS; i++) {
        if (hospedes[i].quarto != 0) {
            printf("Quarto %d: %s\n", hospedes[i].quarto, hospedes[i].nome);
        }
    }
}

void buscarHospede(Hospede hospedes[]) {
    char nome[TAM_NOME];
    printf("Digite o nome do hospede: ");
    scanf("%s", nome);

    for (int i = 0; i < NUM_QUARTOS; i++) {
        if (hospedes[i].quarto != 0 && strcmp(hospedes[i].nome, nome) == 0) {
            printf("Hospede encontrado no quarto %d.\n", hospedes[i].quarto);
            return;
        }
    }

    printf("Hospede nao encontrado.\n");
}
// Função principal
int main() {
    Hospede hospedes[NUM_QUARTOS];
    int opcao, numeroQuarto;

    // Inicializar todos os quartos como vazios
    for (i = 0; i < NUM_QUARTOS; i++) {
        hospedes[i].quarto = 0;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Inserir um novo hospede em um quarto vazio\n");
        printf("2. Listar hospedes\n");
        printf("3. Buscar hospede\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero do quarto: ");
                scanf("%d", &numeroQuarto);
                inserirHospede(hospedes, numeroQuarto);
                break;
            case 2:
                listarHospedes(hospedes);
                break;
            case 3:
                buscarHospede(hospedes);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}