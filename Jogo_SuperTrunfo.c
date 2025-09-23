#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARTAS 2

typedef struct{
    char Estado;
    char Codigo[4];
    char NomeCidade[100];
    unsigned long int Populacao;
    float Area;
    float PIB;
    int PontosTuristicos;
    float Densidade;
    float PIBPercapita;
    float SuperPoder;
}CARTA;

void LerCarta(CARTA *carta, int numero){
    printf("\nDigite os dados da carta %d:\n", numero);

    do{
        printf("Estado (Letra A a H): ");
        scanf("%c", &carta -> Estado);
        if(carta -> Estado < 'A' || carta -> Estado > 'H' ) {
            printf("Estado invalido ! Digite uma letra de A a H.\n");
        }
    }while (carta -> Estado < 'A' || carta -> Estado > 'H');

    printf("Codigo da Carta: ");
    scanf("%s", carta -> Codigo);

    printf("Nome da Cidade:\n");
    getchar();
    fgets(carta -> NomeCidade, sizeof(carta -> NomeCidade), stdin);

    for (int i = 0; carta -> NomeCidade[i] != '\0'; i++){
        if (carta -> NomeCidade [i] == '\n'){
            carta -> NomeCidade [i] = '\0'
        }
    } 

    printf("Populacao: ");
    scanf("%lu", carta -> Populacao);

    do{
        printf("Area (Em Km²): ");
        scanf("%f", &carta -> Area);
        if (carta -> Area <= 0){
            printf("Area invalida!");
        }
    }while (carta -> Area <= 0);

    printf("PIB (Em bilhoes de reais): ");
    scanf("%f", &carta -> PIB);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta -> PontosTuristicos);

    carta -> Densidade = carta -> Populacao / carta -> Area;
    carta -> PIBPercapita = (carta -> PIB * 1e9) / carta -> Populacao;
    carta -> SuperPoder =
        (float)carta -> Populacao +
        carta -> Area +
        carta -> PIB +
        (float) carta -> PontosTuristicos +
        carta -> PIBPercapita +
        (1.0f / carta -> Densidade);
}

void ImprimirCarta(CARTA carta, int numero){
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.Estado);
    printf("Codigo: %s\n", carta.Codigo);
    printf("Nome da Cidade: %s\n", carta.NomeCidade);
    printf("Populacao: %lu\n", carta.Populacao);
    printf("Area: %.3f Km²\n", carta.Area);
    printf("PIB: %.3f bilhoes de Reais\n", carta.PIB)
}