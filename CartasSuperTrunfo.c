#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;                // Letra de 'A' a 'H'
    char codigo[4];             // Código da carta (ex: A01, B03)
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População da cidade (número inteiro)
    float area;                 // Área em km² (pode ter casas decimais)
    float PIB;                  // PIB em bilhões de reais (pode ter casas decimais)
    int num_pontos_turisticos;  // Número de pontos turísticos
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    while (getchar() != '\n');  // Remove caracteres extras do buffer até encontrar '\n'
}

// Função para inserir os dados de uma carta
void inserirCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    
    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta->estado);
    limparBuffer();  // Limpa o buffer após ler um caractere

    printf("Digite o código da carta (ex: A01, B03): ");
    scanf(" %3s", carta->codigo);
    limparBuffer();  // Limpa o buffer após ler string curta

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    limparBuffer();  // Limpa o buffer após ler string longa

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    limparBuffer();

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    limparBuffer();

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->PIB);
    limparBuffer();

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
    limparBuffer();
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
}

int main() {
    printf("=== Super Trunfo - Cadastro de Cartas ===\n");

    Carta carta1, carta2; // Criando duas cartas

    // Inserindo e exibindo a Carta 1
    inserirCarta(&carta1, 1);
    exibirCarta(&carta1, 1);

    // Inserindo e exibindo a Carta 2
    inserirCarta(&carta2, 2);
    exibirCarta(&carta2, 2);

    return 0;
}