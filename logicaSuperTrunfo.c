#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas com Valor Super Trunfo

// Estrutura para armazenar os dados de uma carta (cidade)
struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float valorTotal; // valor calculado automaticamente
};

// Função para ler os dados de uma carta
void lerCarta(struct CartaSuperTrunfo *carta) {
    printf("\nDigite o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta: ");
    scanf(" %s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // cálculo automático do valor total da carta
    carta->valorTotal = (carta->populacao / 1000.0) + carta->area + (carta->pib * 100) + (carta->pontosTuristicos * 50);
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    lerCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    lerCarta(&carta2);

    int opcao;

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Valor Super Trunfo (total)\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n=== Resultado da Comparação ===\n");

    switch (opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao)
                printf("%s venceu! (Maior população)\n", carta1.cidade);
            else if (carta2.populacao > carta1.populacao)
                printf("%s venceu! (Maior população)\n", carta2.cidade);
            else
                printf("Empate em população!\n");
            break;

        case 2:
            if (carta1.area > carta2.area)
                printf("%s venceu! (Maior área)\n", carta1.cidade);
            else if (carta2.area > carta1.area)
                printf("%s venceu! (Maior área)\n", carta2.cidade);
            else
                printf("Empate em área!\n");
            break;

        case 3:
            if (carta1.pib > carta2.pib)
                printf("%s venceu! (Maior PIB)\n", carta1.cidade);
            else if (carta2.pib > carta1.pib)
                printf("%s venceu! (Maior PIB)\n", carta2.cidade);
            else
                printf("Empate em PIB!\n");
            break;

        case 4:
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("%s venceu! (Mais pontos turísticos)\n", carta1.cidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("%s venceu! (Mais pontos turísticos)\n", carta2.cidade);
            else
                printf("Empate em pontos turísticos!\n");
            break;

        case 5:
            printf("\nValor total da %s: %.2f", carta1.cidade, carta1.valorTotal);
            printf("\nValor total da %s: %.2f\n", carta2.cidade, carta2.valorTotal);

            if (carta1.valorTotal > carta2.valorTotal)
                printf("\n🏆 %s venceu! (Maior valor total Super Trunfo)\n", carta1.cidade);
            else if (carta2.valorTotal > carta1.valorTotal)
                printf("\n🏆 %s venceu! (Maior valor total Super Trunfo)\n", carta2.cidade);
            else
                printf("\nEmpate em valor total!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
