#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];             // Estado (ex: "SP", "RJ")
    char codigo[4];             // Código da carta (ex: "A01", "B03")
    char nomeCidade[50];        // Nome da cidade
    unsigned long int populacao;// População da cidade
    float area;                 // Área em km²
    float PIB;                  // PIB em bilhões de reais
    int num_pontos_turisticos;  // Número de pontos turísticos
    float densidade_populacional; // Habitantes por km²
    float pib_per_capita;        // PIB per capita
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    while (getchar() != '\n');  // Remove caracteres extras do buffer até encontrar '\n'
}

// Função para inserir os dados de uma carta
void inserirCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);
    
    printf("Digite o estado (ex: SP, RJ): ");
    scanf(" %2s", carta->estado);
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
    carta->densidade_populacional = (carta->area > 0) ? (carta->populacao / carta->area) : 0;
    carta->pib_per_capita = (carta->populacao > 0) ? ((carta->PIB * 1000000000) / carta->populacao) : 0;
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %lu habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta->pib_per_capita);
}

// Função para comparar as cartas
void compararCartas(const Carta *carta1, const Carta *carta2, int atributo) {
    printf("\n=== Comparação de Cartas ===\n");

    float valor1, valor2;
    char atributoNome[30];

    switch (atributo) {
        case 1:
            valor1 = carta1->populacao;
            valor2 = carta2->populacao;
            strcpy(atributoNome, "População");
            break;
        case 2:
            valor1 = carta1->area;
            valor2 = carta2->area;
            strcpy(atributoNome, "Área");
            break;
        case 3:
            valor1 = carta1->PIB;
            valor2 = carta2->PIB;
            strcpy(atributoNome, "PIB");
            break;
        case 4:
            valor1 = carta1->num_pontos_turisticos;
            valor2 = carta2->num_pontos_turisticos;
            strcpy(atributoNome, "Pontos Turísticos");
            break;
        case 5:
            valor1 = carta1->densidade_populacional;
            valor2 = carta2->densidade_populacional;
            strcpy(atributoNome, "Densidade Populacional");
            break;
        case 6:
            valor1 = carta1->pib_per_capita;
            valor2 = carta2->pib_per_capita;
            strcpy(atributoNome, "PIB per Capita");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\nComparação pelo atributo: %s\n", atributoNome);
    printf("Carta 1 - %s (%s): %.2f\n", carta1->nomeCidade, carta1->estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2->nomeCidade, carta2->estado, valor2);

    if (atributo == 5) { // Para Densidade Populacional, menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
        } else if (valor1 > valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else { // Para os outros atributos, maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->nomeCidade);
        } else if (valor1 < valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    printf("=== Super Trunfo - Cadastro de Cartas ===\n");

    Carta carta1, carta2;

    // Inserindo as cartas
    inserirCarta(&carta1, 1);
    inserirCarta(&carta2, 2);

    // Exibindo as cartas
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);

    // Escolha do atributo para comparação
    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite o número correspondente: ");
    scanf("%d", &escolha);
    limparBuffer();

    // Comparação das cartas
    compararCartas(&carta1, &carta2, escolha);

    return 0;
}
