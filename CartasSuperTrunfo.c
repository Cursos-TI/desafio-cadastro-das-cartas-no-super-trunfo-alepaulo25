#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];             // Sigla do estado (ex: SP, RJ, MG)
    char codigo[4];             // Código da carta (ex: A01, B03)
    char nomeCidade[50];        // Nome da cidade
    int populacao;              // População da cidade
    float area;                 // Área em km²
    float PIB;                  // PIB em bilhões de reais
    int num_pontos_turisticos;  // Número de pontos turísticos
    float densidadePopulacional; // Habitantes por km²
    float PIBperCapita;          // PIB per capita em reais
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para inserir os dados de uma carta
void inserirCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    
    printf("Digite a sigla do estado (ex: SP, RJ): ");
    scanf(" %2s", carta->estado);
    limparBuffer(); 

    printf("Digite o código da carta (ex: A01, B03): ");
    scanf(" %3s", carta->codigo);
    limparBuffer();

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    limparBuffer();

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

    // Cálculo da densidade populacional (habitantes por km²)
    carta->densidadePopulacional = carta->populacao / carta->area;

    // Cálculo do PIB per capita (PIB em bilhões convertido para reais)
    carta->PIBperCapita = (carta->PIB * 1000000000.0) / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta->PIBperCapita);
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
