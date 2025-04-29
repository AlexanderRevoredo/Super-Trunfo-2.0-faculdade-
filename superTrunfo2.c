#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    char cidade1[50], cidade2[50], jogarNovamente;
    unsigned long int populacao1, populacao2;
    int pontosturisticos1, pontosturisticos2, escolha1, escolha2;
    float area1, area2, pib1, pib2, densidadepopulacional1, densidadepopulacional2, pibpercapita1, pibpercapita2;
    bool escolhaInvalida;

    // Criando um loop de repetição a partir da resposta do jogador

    do {

        printf("     _____                    _____             ___     \n");
        printf("    |   __|_ _ ___ ___ ___   |_   _|___ _ _ ___|  _|___ \n");
        printf("    |__   | | | . | -_|  _|    | | |  _| | |   |  _| . |\n");
        printf("    |_____|___|  _|___|_|      |_| |_| |___|_|_|_| |___|\n");
        printf("              |_|                                       \n"); 

        // Cadastrando a primeira carta
        printf("Digite o nome de um Estado? ");
        fgets(cidade1, 49, stdin);
        cidade1[strcspn(cidade1, "\n")] = '\0';

        printf("Qual a populacao? ");
        scanf("%lu", &populacao1);

        printf("Qual a area do Estado? ");
        scanf("%f", &area1);

        printf("Qual o PIB? ");
        scanf("%f", &pib1);

        printf("Qual o numero de pontos turisticos do Estado? ");
        scanf("%d", &pontosturisticos1);
        getchar();

        // Cadastrando a segunda carta
        printf("Digite o nome de um Estado? ");
        fgets(cidade2, 49, stdin);
        cidade2[strcspn(cidade2, "\n")] = '\0';

        printf("Qual a populacao? ");
        scanf("%lu", &populacao2);

        printf("Qual a area do Estado? ");
        scanf("%f", &area2);

        printf("Qual o PIB? ");
        scanf("%f", &pib2);

        printf("Qual o numero de pontos turisticos do Estado? ");
        scanf("%d", &pontosturisticos2);
        getchar();

        // Armazenando a densidade populacional e o PIB per Capita
        densidadepopulacional1 = populacao1 / area1;
        densidadepopulacional2 = populacao2 / area2;

        // Calculo PIB per capita
        pibpercapita1 = (pib1 * 1000000000) / (float)populacao1;
        pibpercapita2 = (pib2 * 1000000000) / (float)populacao2;

        // Calculo do Super Poder
        float superpoder1 = populacao1 + area1 + pib1 + pontosturisticos1 + pibpercapita1 + (1 / densidadepopulacional1);
        float superpoder2 = populacao2 + area2 + pib2 + pontosturisticos2 + pibpercapita2 + (1 / densidadepopulacional2);

        //Imprimindo a primeira carta
        printf("\n");
        printf("Primeira carta cadastrada\n");
        printf("-------------------------\n");

        printf("Carta 1\n");
        printf("Estado A\n");
        printf("Codigo: A01\n");
        printf("Nome da Cidade: %s\n", cidade1);
        printf("Populacao: %lu\n", populacao1);
        printf("Area: %.2f km²\n", area1);
        printf("PIB: %.2f bilhoes de reais\n", pib1);
        printf("Numero de Pontos Turisticos: %d\n", pontosturisticos1);
        printf("Densidade Populacional: %.2f hab/km²\n", densidadepopulacional1);
        printf("PIB per Capita: %.2f\n", pibpercapita1);

        // Imprimindo a segunda carta
        printf("\n");
        printf("Segunda carta cadastrada\n");
        printf("-------------------------\n");

        printf("Carta 2\n");
        printf("Estado B\n");
        printf("Codigo: B02\n");
        printf("Nome da Cidade: %s\n", cidade2);
        printf("Populacao: %lu\n", populacao2);
        printf("Area: %.2f km²\n", area2);
        printf("PIB: %.2f bilhoes de reais\n", pib2);
        printf("Numero de Pontos Turisticos: %d\n", pontosturisticos2);
        printf("Densidade Populacional: %.2f hab/km²\n", densidadepopulacional2);
        printf("PIB per Capita: %.2f\n", pibpercapita2);

        // Menu Interativo com loop booleano de validação
        do {
            escolhaInvalida = false; // Garante que a escolha é valida a cada iteração
            printf("\nEscolha o primeiro atributo para comparar\n");
            printf("1 - Populacao\n");
            printf("2- Area\n");
            printf("3- PIB\n");
            printf("4 - Pontos turisticos\n");
            printf("5 - Densidade Populacional\n");
            printf("6 - PIB per Capita\n");
            printf("7 - Super Poder\n");
            printf("0 - Sair do jogo\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha1);
            getchar();

            if (escolha1 >= 0 && escolha1 <= 7) { // Garante que a primeira escolha é válida antes de prosseguir
                printf("\nEscolha o segundo atributo para comparar\n");
                // Exibe as opções do segundo menu, omitindo a escolha1
                for (int i = 1; i <= 7; i++) {
                    if (i != escolha1) {
                        switch (i) {
                            case 1: printf("1 - Populacao\n"); break;
                            case 2: printf("2 - Area\n"); break;
                            case 3: printf("3 - PIB\n"); break;
                            case 4: printf("4 - Pontos turisticos\n"); break;
                            case 5: printf("5 - Densidade Populacional\n"); break;
                            case 6: printf("6 - PIB per Capita\n"); break;
                            case 7: printf("7 - Super Poder\n"); break;
                        }
                    }
                }
                printf("0 - Sair do jogo\n");
                printf("Digite sua segunda escolha: ");
                scanf("%d", &escolha2);
                getchar();

                if ((escolha2 >= 0 && escolha2 <= 7) && (escolha2 != escolha1)) {
                    printf("\nResultado da comparacao:\n");

                    // Comparando as cartas com switch (primeiro atributo)
                    switch (escolha1) {
                        case 1:
                            printf("Atributo 1: Populacao\n");
                            printf("%s: %lu\n", cidade1, populacao1);
                            printf("%s: %lu\n", cidade2, populacao2);
                            if (populacao1 > populacao2) printf("Vencedor (População): %s\n", cidade1);
                            else if (populacao2 > populacao1) printf("Vencedor (População): %s\n", cidade2);
                            else printf("Empate (População)!\n");
                            break;
                        case 2:
                            printf("Atributo 1: Area\n");
                            printf("%s: %.2f km²\n", cidade1, area1);
                            printf("%s: %.2f km²\n", cidade2, area2);
                            if (area1 > area2) printf("Vencedor (Area): %s\n", cidade1);
                            else if (area2 > area1) printf("Vencedor (Area): %s\n", cidade2);
                            else printf("Empate (Area)!\n");
                            break;
                        case 3:
                            printf("Atributo 1: PIB\n");
                            printf("%s: %.2f bilhoes de reais\n", cidade1, pib1);
                            printf("%s: %.2f bilhoes de reais\n", cidade2, pib2);
                            if (pib1 > pib2) printf("Vencedor (PIB): %s\n", cidade1);
                            else if (pib2 > pib1) printf("Vencedor (PIB): %s\n", cidade2);
                            else printf("Empate (PIB)!\n");
                            break;
                        case 4:
                            printf("Atributo 1: Numero de Pontos Turisticos\n");
                            printf("%s: %d\n", cidade1, pontosturisticos1);
                            printf("%s: %d\n", cidade2, pontosturisticos2);
                            if (pontosturisticos1 > pontosturisticos2) printf("Vencedor (Pontos Turisticos): %s\n", cidade1);
                            else if (pontosturisticos2 > pontosturisticos1) printf("Vencedor (Pontos Turisticos): %s\n", cidade2);
                            else printf("Empate (Pontos Turisticos)!\n");
                            break;
                        case 5:
                            printf("Atributo 1: Densidade Populacional\n");
                            printf("%s: %.2f hab/km²\n", cidade1, densidadepopulacional1);
                            printf("%s: %.2f hab/km²\n", cidade2, densidadepopulacional2);
                            if (densidadepopulacional1 < densidadepopulacional2) printf("Vencedor (Densidade Populacional): %s\n", cidade1);
                            else if (densidadepopulacional2 < densidadepopulacional1) printf("Vencedor (Densidade Populacional): %s\n", cidade2);
                            else printf("Empate (Densidade Populacional)!\n");
                            break;
                        case 6:
                            printf("Atributo 1: PIB per Capita\n");
                            printf("%s: %.2f\n", cidade1, pibpercapita1);
                            printf("%s: %.2f\n", cidade2, pibpercapita2);
                            if (pibpercapita1 > pibpercapita2) printf("Vencedor (PIB per Capita): %s\n", cidade1);
                            else if (pibpercapita2 > pibpercapita1) printf("Vencedor (PIB per Capita): %s\n", cidade2);
                            else printf("Empate (PIB per Capita)!\n");
                            break;
                        case 7:
                            printf("Atributo 1: Super Poder\n");
                            printf("%s: %.2f\n", cidade1, superpoder1);
                            printf("%s: %.2f\n", cidade2, superpoder2);
                            if (superpoder1 > superpoder2) printf("Vencedor (Super Poder): %s\n", cidade1);
                            else if (superpoder2 > superpoder1) printf("Vencedor (Super Poder): %s\n", cidade2);
                            else printf("Empate (Super Poder)!\n");
                            break;
                        case 0:
                            printf("Saindo do jogo.\n");
                            break;
                    }

                    printf("\n");

                    // Comparando as cartas com switch (segundo atributo)
                    switch (escolha2) {
                        case 1:
                            printf("Atributo 2: Populacao\n");
                            printf("%s: %lu\n", cidade1, populacao1);
                            printf("%s: %lu\n", cidade2, populacao2);
                            if (populacao1 > populacao2) printf("Vencedor (População): %s\n", cidade1);
                            else if (populacao2 > populacao1) printf("Vencedor (População): %s\n", cidade2);
                            else printf("Empate (População)!\n");
                            break;
                        case 2:
                            printf("Atributo 2: Area\n");
                            printf("%s: %.2f km²\n", cidade1, area1);
                            printf("%s: %.2f km²\n", cidade2, area2);
                            if (area1 > area2) printf("Vencedor (Area): %s\n", cidade1);
                            else if (area2 > area1) printf("Vencedor (Area): %s\n", cidade2);
                            else printf("Empate (Area)!\n");
                            break;
                        case 3:
                            printf("Atributo 2: PIB\n");
                            printf("%s: %.2f bilhoes de reais\n", cidade1, pib1);
                            printf("%s: %.2f bilhoes de reais\n", cidade2, pib2);
                            if (pib1 > pib2) printf("Vencedor (PIB): %s\n", cidade1);
                            else if (pib2 > pib1) printf("Vencedor (PIB): %s\n", cidade2);
                            else printf("Empate (PIB)!\n");
                            break;
                        case 4:
                            printf("Atributo 2: Numero de Pontos Turisticos\n");
                            printf("%s: %d\n", cidade1, pontosturisticos1);
                            printf("%s: %d\n", cidade2, pontosturisticos2);
                            if (pontosturisticos1 > pontosturisticos2) printf("Vencedor (Pontos Turisticos): %s\n", cidade1);
                            else if (pontosturisticos2 > pontosturisticos1) printf("Vencedor (Pontos Turisticos): %s\n", cidade2);
                            else printf("Empate (Pontos Turisticos)!\n");
                            break;
                        case 5:
                            printf("Atributo 2: Densidade Populacional\n");
                            printf("%s: %.2f hab/km²\n", cidade1, densidadepopulacional1);
                            printf("%s: %.2f hab/km²\n", cidade2, densidadepopulacional2);
                            if (densidadepopulacional1 < densidadepopulacional2) printf("Vencedor (Densidade Populacional): %s\n", cidade1);
                            else if (densidadepopulacional2 < densidadepopulacional1) printf("Vencedor (Densidade Populacional): %s\n", cidade2);
                            else printf("Empate (Densidade Populacional)!\n");
                            break;
                        case 6:
                            printf("Atributo 2: PIB per Capita\n");
                            printf("%s: %.2f\n", cidade1, pibpercapita1);
                            printf("%s: %.2f\n", cidade2, pibpercapita2);
                            if (pibpercapita1 > pibpercapita2) printf("Vencedor (PIB per Capita): %s\n", cidade1);
                            else if (pibpercapita2 > pibpercapita1) printf("Vencedor (PIB per Capita): %s\n", cidade2);
                            else printf("Empate (PIB per Capita)!\n");
                            break;
                        case 7:
                            printf("Atributo 2: Super Poder\n");
                            printf("%s: %.2f\n", cidade1, superpoder1);
                            printf("%s: %.2f\n", cidade2, superpoder2);
                            if (superpoder1 > superpoder2) printf("Vencedor (Super Poder): %s\n", cidade1);
                            else if (superpoder2 > superpoder1) printf("Vencedor (Super Poder): %s\n", cidade2);
                            else printf("Empate (Super Poder)!\n");
                            break;
                        case 0:
                            printf("Saindo do jogo.\n");
                            break;
                    }

                    // Calcular a soma dos atributos para cada carta
                    float somaCarta1 = 0;
                    float somaCarta2 = 0;

                    // Adicionar os valores do primeiro atributo escolhido
                    switch (escolha1) {
                        case 1: somaCarta1 += populacao1; somaCarta2 += populacao2; break;
                        case 2: somaCarta1 += area1; somaCarta2 += area2; break;
                        case 3: somaCarta1 += pib1; somaCarta2 += pib2; break;
                        case 4: somaCarta1 += pontosturisticos1; somaCarta2 += pontosturisticos2; break;
                        case 5: somaCarta1 += densidadepopulacional1; somaCarta2 += densidadepopulacional2; break;
                        case 6: somaCarta1 += pibpercapita1; somaCarta2 += pibpercapita2; break;
                        case 7: somaCarta1 += superpoder1; somaCarta2 += superpoder2;
                        case 0: break;
                    }

                    // Adicionar os valores do segundo atributo escolhido
                    switch (escolha2) {
                        case 1: somaCarta1 += populacao1; somaCarta2 += populacao2; break;
                        case 2: somaCarta1 += area1; somaCarta2 += area2; break;
                        case 3: somaCarta1 += pib1; somaCarta2 += pib2; break;
                        case 4: somaCarta1 += pontosturisticos1; somaCarta2 += pontosturisticos2; break;
                        case 5: somaCarta1 += densidadepopulacional1; somaCarta2 += densidadepopulacional2; break;
                        case 6: somaCarta1 += pibpercapita1; somaCarta2 += pibpercapita2; break;
                        case 7: somaCarta1 += superpoder1; somaCarta2 += superpoder2; break;
                        case 0: break;
                    }

                    printf("\nResultado da rodada (soma dos atributos):\n");
                    printf("Soma dos atributos de %s: %.2f\n", cidade1, somaCarta1);
                    printf("Soma dos atributos de %s: %.2f\n", cidade2, somaCarta2);

                    if (somaCarta1 > somaCarta2) {
                        printf("%s venceu a rodada!\n", cidade1);
                    } else if (somaCarta2 > somaCarta1) {
                        printf("%s venceu a rodada!\n", cidade2);
                    } else {
                        printf("A rodada terminou em empate!\n");
                    }

                } else if (escolha2 != 0) {
                    printf("Opcao invalida para o segundo atributo ou igual a primeira escolha. Tente novamente.\n");
                    escolhaInvalida = true; // Para repetir a escolha dos atributos
                } else if (escolha2 == 0) {
                    printf("Saindo do jogo.\n");
                    break; // Sai do loop de escolha de atributos e da rodada
                }

            } else if (escolha1 != 0) {
                printf("Opcao invalida para o primeiro atributo. Tente novamente.\n");
                escolhaInvalida = true; // Para repetir a escolha dos atributos
            } else if (escolha1 == 0) {
                printf("Saindo do jogo.\n");
                break; // Sai do loop de escolha de atributos e da rodada
            }

        } while (escolhaInvalida);

        // Agradecendo o jogador por jogar (movido para fora do loop interno)
        if (escolha1 != 0) {
            printf("Obrigado por jogar esta rodada!\n");
            printf("Deseja jogar novamente? (s/n): ");
            scanf("%c", &jogarNovamente);
            getchar();
        } else {
            jogarNovamente = 'n'; // Para sair do loop externo
        }

    } while (jogarNovamente == 's');

    printf("Obrigado por jogar o jogo!\n");

    return 0;
}