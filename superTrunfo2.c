#include <stdio.h> // Para entrada e saída
#include <string.h> // Para trabalhar com cadeia de caracteres
#include <stdlib.h> // Para a função exit()
#include <stdbool.h> // Permite variavel booleana para corrigir o switch

int main() {

    // Declarando as variaveis
    char cidade1[50], cidade2[50], jogarNovamente;
    unsigned long int populacao1, populacao2;
    int pontosturisticos1, pontosturisticos2, escolha;
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
        scanf("%lu", &populacao1); // %lu para unsigned long int
        
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
        pibpercapita1 = (pib1 * 1000000000) / (float)populacao1; // Já que o pib está em bilhões, multiplica por bilhão
        pibpercapita2 = (pib2 * 1000000000) / (float)populacao2;

        // Calculo do Super Poder
        float superpoder1 = populacao1 + area1 + pib1 + pontosturisticos1 + pibpercapita1 + (1/densidadepopulacional1);
        float superpoder2 = populacao2 + area2 + pib2 + pontosturisticos2 + pibpercapita2 + (1/densidadepopulacional2);
        
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
            printf("\nEscolha o atributo para comparar\n");
            printf("1 - Populacao\n");
            printf("2- Area\n");
            printf("3- PIB\n");
            printf("4 - Pontos turisticos\n");
            printf("5 - Densidade Populacional\n");
            printf("6 - PIB per Capita\n");
            printf("7 - Super Poder\n");
            printf("0 - Sair do jogo\n");
            printf("Digite sua escolha: ");
            scanf("%d", &escolha);
            getchar();

            printf("\nResultado da comparacao:\n");

            // Comparando as cartas com switch
            switch (escolha)
            {
            case 1:
                printf("Atributo: Populacao\n");
                printf("%s: %lu\n", cidade1, populacao1);
                printf("%s: %lu\n", cidade2, populacao2);
                if (populacao1 > populacao2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (populacao2 > populacao1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 2:
                printf("Atributo: Area\n");
                printf("%s: %.2f km²\n", cidade1, area1);
                printf("%s: %.2f km²\n", cidade2, area2);
                if (area1 > area2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (area2 > area1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 3:
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhoes de reais\n", cidade1, pib1);
                printf("%s: %.2f bilhoes de reais\n", cidade2, pib2);
                if (pib1 > pib2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (pib2 > pib1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 4:
                printf("Atributo: Numero de Pontos Turisticos\n");
                printf("%s: %d\n", cidade1, pontosturisticos1);
                printf("%s: %d\n", cidade2, pontosturisticos2);
                if (pontosturisticos1 > pontosturisticos2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (pontosturisticos2 > pontosturisticos1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 5:
                printf("Atributo: Densidade Populacional\n");
                printf("%s: %.2f hab/km²\n", cidade1, densidadepopulacional1);
                printf("%s: %.2f hab/km²\n", cidade2, densidadepopulacional2);
                if (densidadepopulacional1 < densidadepopulacional2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (densidadepopulacional2 < densidadepopulacional1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 6:
                printf("Atributo: PIB per Capita\n");
                printf("%s: %.2f\n", cidade1, pibpercapita1);
                printf("%s: %.2f\n", cidade2, pibpercapita2);
                if (pibpercapita1 > pibpercapita2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (pibpercapita2 > pibpercapita1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 7:
                printf("Atributo: Super Poder\n");
                printf("%s: %.2f\n", cidade1, superpoder1);
                printf("%s: %.2f\n", cidade2, superpoder2);
                if (superpoder1 > superpoder2) {
                    printf("Vencedor: %s\n", cidade1);
                } else if (superpoder2 > superpoder1) {
                    printf("Vencedor: %s\n", cidade2);
                } else {
                    printf("Empate!\n");
                }
                break;
            case 0:
                printf("Saindo do jogo.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                escolhaInvalida = true; // Marca a escolha como invalida, forçando o usuário a escolher um caso válido
            }
        } while (escolhaInvalida);
        
        /*

        COMPARAÇÃO ANTIGA

        printf("\n");
        printf("======================\n");
        printf("COMPARACAO DAS CARTAS\n");
        printf("======================\n");
        printf("Populacao: %s venceu\n", (populacao1 > populacao2) ? cidade1 : cidade2);
        printf("Area: %s venceu\n", (area1 > area2) ? cidade1 : cidade2);
        printf("PIB: %s venceu\n", (pib1 > pib2) ? cidade1 : cidade2);
        printf("Pontos Turisticos: %s venceu\n", (pontosturisticos1 > pontosturisticos2) ? cidade1 : cidade2);
        printf("Densidade Populacional: %s venceu\n", (densidadepopulacional1 < densidadepopulacional2) ? cidade1 : cidade2);
        printf("PIB per Capita: %s venceu\n", (pibpercapita1 > pibpercapita2) ? cidade1 : cidade2);
        printf("Super Poder: %s venceu\n", (superpoder1 > superpoder2) ? cidade1 : cidade2);
        */

        // Agradecendo o jogador por jogar
        if (escolha != 0) {
            printf("Obrigado por jogar\n");
        }

        // Obtendo a resposta se o jogador quer continuar jogando
        if (escolha != 0) {
            printf("Deseja jogar novamente? (s/n): ");
            scanf("%c", &jogarNovamente);
            getchar();
        } else {
            jogarNovamente = 'n'; // Para sair do loop
        }
    
    } while (jogarNovamente == 's');

    return 0;
}