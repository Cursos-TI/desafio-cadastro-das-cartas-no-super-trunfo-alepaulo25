#include <stdio.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;                // Letra de 'A' a 'H'
    char codigo[4];             // Código da carta (ex: A01, B03)
    char nomeCidade[50];        // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area;                 // Área em km²
    float PIB;                  // PIB em bilhões de reais
    int num_pontos_turisticos;  // Número de pontos turísticos
    float densidade_populacional; // Habitantes por km²
    float pib_per_capita;        // PIB per capita
    float super_poder;           // Super Poder da carta
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
    limparBuffer();

    printf("Digite o código da carta (ex: A01, B03): ");
    scanf(" %3s", carta->codigo);
    limparBuffer();

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    limparBuffer();

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
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

    // Cálculo da densidade populacional e PIB per capita
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;  // Evita divisão por zero
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = (carta->PIB * 1000000000) / carta->populacao; // Convertendo PIB para reais
    } else {
        carta->pib_per_capita = 0;
    }

    if (carta->densidade_populacional > 0) {
        carta->super_poder = carta->populacao + carta->area + carta->PIB + carta->num_pontos_turisticos +
                             carta->pib_per_capita + (1.0 / carta->densidade_populacional);
    } else {
        carta->super_poder = carta->populacao + carta->area + carta->PIB + carta->num_pontos_turisticos +
                             carta->pib_per_capita;
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %lu habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta->pib_per_capita);
    printf("Super Poder: %.2f\n", carta->super_poder);
}

// Função para comparar cartas
void compararCartas(const Carta *carta1, const Carta *carta2) {
    printf("\n=== Comparação de Cartas ===\n");
    printf("População: Carta %d venceu (%d)\n", carta1->populacao > carta2->populacao ? 1 : 2, carta1->populacao > carta2->populacao);
    printf("Área: Carta %d venceu (%d)\n", carta1->area > carta2->area ? 1 : 2, carta1->area > carta2->area);
    printf("PIB: Carta %d venceu (%d)\n", carta1->PIB > carta2->PIB ? 1 : 2, carta1->PIB > carta2->PIB);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", carta1->num_pontos_turisticos > carta2->num_pontos_turisticos ? 1 : 2, carta1->num_pontos_turisticos > carta2->num_pontos_turisticos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", carta1->densidade_populacional < carta2->densidade_populacional ? 1 : 2, carta1->densidade_populacional < carta2->densidade_populacional);
    printf("PIB per Capita: Carta %d venceu (%d)\n", carta1->pib_per_capita > carta2->pib_per_capita ? 1 : 2, carta1->pib_per_capita > carta2->pib_per_capita);
    printf("Super Poder: Carta %d venceu (%d)\n", carta1->super_poder > carta2->super_poder ? 1 : 2, carta1->super_poder > carta2->super_poder);
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

    // Comparação entre as cartas
    compararCartas(&carta1, &carta2);

    return 0;
}
