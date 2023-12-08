#include <stdio.h>
#include <string.h>

#define NUM_QUARTOS 15
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
        printf("Hospede inserido no quarto %d com sucesso.\n", numeroQuarto);
    } else {
        printf("O quarto %d esta ocupado. Escolha outro quarto.\n", numeroQuarto);
    }
}
// Função para listar os hóspedes
void listarHospedes(Hospede hospedes[]) {
    printf("Lista de Hospedes:\n");
    for (int i = 0; i < NUM_QUARTOS; i++) {
        if (hospedes[i].quarto != 0) {
            printf("Quarto %d: %s\n", hospedes[i].quarto, hospedes[i].nome);
        }
    }
}
// Função para buscar hóspedes
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
// Função para editar hóspedes
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
// Função para remover hóspedes
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
// Função para exibir quartos vazios
void mostrarQuartosVazios(Hospede hospedes[]) {
    printf("Quartos vazios:\n");
    int vazio = 1;
    for (int i = 0; i < NUM_QUARTOS; i++) {
        if (hospedes[i].quarto == 0) {
            printf("%d ", i + 1);
            vazio = 0;
        }
    }
    if (vazio)
        printf("Nenhum quarto vazio.\n");
    else
        printf("\n");
}
// Função para salvar listagem de hóspedes
void salvarHospedes(Hospede hospedes[]) {
    FILE *arquivo;
    arquivo = fopen("lista_hospedes.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < NUM_QUARTOS; i++) {
        if (hospedes[i].quarto != 0) {
            fprintf(arquivo, "Quarto %d: %s\n", hospedes[i].quarto, hospedes[i].nome);
        }
    }

    fclose(arquivo);
    printf("Lista de hospedes salva no arquivo 'lista_hospedes.txt'.\n");
}

int main() {
    Hospede hospedes[NUM_QUARTOS];
    int opcao, numeroQuarto;

    for (i = 0; i < NUM_QUARTOS; i++) {
        hospedes[i].quarto = 0;
    }
    // Impressões do menu
    do {
        printf("\nBem-vindo(a) ao Menu do HostSystem, escolha uma opcao abaixo:\n");
        printf("1. Inserir um novo hospede em um quarto vazio\n");
        printf("2. Listar hospedes\n");
        printf("3. Buscar hospede\n");
        printf("4. Editar hospede\n");
        printf("5. Remover hospede\n");
        printf("6. Mostrar quartos vazios\n");
        printf("7. Salvar lista de hospedes com respectivos quartos em arquivo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    // Detalhamento de opções do menu
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
            case 6:
                mostrarQuartosVazios(hospedes);
                break;
            case 7:
                salvarHospedes(hospedes);
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