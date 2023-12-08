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

// Função para editar o nome de um hóspede
void editarHospede(Hospede hospedes[]) {
    int numeroQuarto;
    printf("Digite o numero do quarto do hospede que deseja editar: ");
    scanf("%d", &numeroQuarto);

    if (numeroQuarto >= 1 && numeroQuarto <= NUM_QUARTOS) {
        if (hospedes[numeroQuarto - 1].quarto != 0) {
            printf("Digite o novo nome do hospede: ");
            scanf("%s", hospedes[numeroQuarto - 1].nome);
            printf("Nome do hospede no quarto %d atualizado com sucesso.\n", numeroQuarto);
        } else {
            printf("Nenhum hospede encontrado no quarto %d.\n", numeroQuarto);
        }
    } else {
        printf("Quarto invalido. Tente novamente.\n");
    }
}

// Função para remover um hóspede
void removerHospede(Hospede hospedes[]) {
    int numeroQuarto;
    printf("Digite o numero do quarto do hospede que deseja remover: ");
    scanf("%d", &numeroQuarto);

    if (numeroQuarto >= 1 && numeroQuarto <= NUM_QUARTOS) {
        if (hospedes[numeroQuarto - 1].quarto != 0) {
            printf("Removendo hóspede do quarto %d...\n", numeroQuarto);
            hospedes[numeroQuarto - 1].quarto = 0;
            hospedes[numeroQuarto - 1].nome[0] = '\0';
            printf("Hóspede removido com sucesso.\n");
        } else {
            printf("Nenhum hospede encontrado no quarto %d.\n", numeroQuarto);
        }
    } else {
        printf("Quarto invalido. Tente novamente.\n");
    }
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
        printf("4. Editar hospede\n");
        printf("5. Remover hospede\n");
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
            case 4:
                editarHospede(hospedes);
                break;
            case 5:
                removerHospede(hospedes);
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