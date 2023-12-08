![Alt text](<HOSTSYSTEM LOGO-1.png>)

# HostSystem

##### HostSystem é um sistema básico de controle de hospedagem redigido em C para o projeto final da disciplina de Algoritmo e programação estruturada (noturno).

```bash
Este sistema foi desenvolvido por:
Gabriel Queiroz
Janderson Moreira
Daniel Victor
Felipe Leite
```
### Este código em C apresenta um sistema simples de gerenciamento de hospedes em quartos de um estabelecimento.

```bash
Estrutura do Código:

1. Constantes e Estruturas:
   - Define constantes como NUM_QUARTOS (número total de quartos) e TAM_NOME (tamanho máximo do nome do hóspede).
   - Declara uma estrutura Hospede que armazena o nome do hóspede e o número do quarto.

2. Funcionalidades:
   - inserirHospede: Adiciona um novo hóspede em um quarto vazio.
   - listarHospedes: Mostra a lista de todos os hóspedes presentes nos quartos.
   - buscarHospede: Procura um hóspede pelo nome.
   - editarHospede: Permite editar o nome de um hóspede em um quarto específico.
   - removerHospede: Remove um hóspede de um quarto específico.
   - mostrarQuartosVazios: Exibe os números dos quartos que estão desocupados.
   - salvarHospedes: Salva a lista de hóspedes em um arquivo de texto.

3. Função main:
   - Inicializa um array de estruturas Hospede representando os quartos.
   - Apresenta um menu interativo onde o usuário escolhe as opções para interagir com as funções acima.
   - Usa um loop do-while para repetir o menu até que o usuário escolha a opção de sair (opção '0').

4. Entradas e Saídas:
   - Utiliza printf para exibir mensagens e scanf para capturar a entrada do usuário.

5. Manipulação de Arquivos:
   - Usa a biblioteca stdio.h para interagir com arquivos, permitindo salvar a lista de hóspedes em um arquivo de texto.

A estrutura modular facilita a compreensão e a manutenção do código, possibilitando adicionar ou modificar funcionalidades no sistema de gerenciamento de hóspedes em quartos de forma mais organizada e clara.
```
