#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char pais[50];              // Nome do país
    unsigned long int populacao;// População do país
    float area;                 // Área em km²
    float PIB;                  // PIB em bilhões de dólares
    int num_pontos_turisticos;  // Número de pontos turísticos
    float densidade_demografica;// Habitantes por km²
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para inserir os dados de uma carta
void inserirCarta(Carta *carta, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);

    printf("Digite o nome do país: ");
    scanf(" %49[^\n]", carta->pais);
    limparBuffer();

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    limparBuffer();

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    limparBuffer();

    printf("Digite o PIB (em bilhões de dólares): ");
    scanf("%f", &carta->PIB);
    limparBuffer();

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->num_pontos_turisticos);
    limparBuffer();

    // Cálculo da densidade demográfica
    carta->densidade_demografica = (carta->area > 0) ? (carta->populacao / carta->area) : 0;
}

// Função para exibir os dados de uma carta
void exibirCarta(const Carta *carta, int numero) {
    printf("\n=== Carta %d ===\n", numero);
    printf("País: %s\n", carta->pais);
    printf("População: %lu habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de dólares\n", carta->PIB);
    printf("Número de Pontos Turísticos: %d\n", carta->num_pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", carta->densidade_demografica);
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
            valor1 = carta1->densidade_demografica;
            valor2 = carta2->densidade_demografica;
            strcpy(atributoNome, "Densidade Demográfica");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\nComparação pelo atributo: %s\n", atributoNome);
    printf("Carta 1 - %s: %.2f\n", carta1->pais, valor1);
    printf("Carta 2 - %s: %.2f\n", carta2->pais, valor2);

    if (atributo == 5) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->pais);
        } else if (valor1 > valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1->pais);
        } else if (valor1 < valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2->pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    printf("=== Super Trunfo - Cadastro de Cartas ===\n");

    Carta carta1, carta2;

    inserirCarta(&carta1, 1);
    inserirCarta(&carta2, 2);

    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);

    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite o número correspondente: ");
    scanf("%d", &escolha);
    limparBuffer();

    compararCartas(&carta1, &carta2, escolha);

    return 0;
}


