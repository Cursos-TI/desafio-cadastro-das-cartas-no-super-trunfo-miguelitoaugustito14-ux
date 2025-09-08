#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARTAS 2

typedef struct {
    char Estado;
    char Codigo[4];
    char nomeCidade[100];
    unsigned long int Populacao;
    float Area;
    float PIB;
    int PontosTuristicos;
    float Densidade;
    float PibPercapita;
    float SuperPoder;

}CARTA;

void lerCarta(CARTA *carta, int numero){
    printf("\nDigite os dados da Carta %d:\n", numero);

    do{
        printf("Estado (Letra de A a H): ");
        scaf("%c", &carta->Estado);
        if (carta->Estado< 'A' || carta->Estado > 'H' ) {
            printf("Estado Invalido! Digite uma letra de A a H.\n");
        }
    }while (carta->Estado < 'A' || carta->Estado > 'H');

    printf("Codigo da Carta: ");
    scanf("%s", carta->Codigo);
    
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta-> nomeCidade, sizeof(carta->nomeCidade), stdin);

    for (int i = 0; carta->nomeCidade[i] != '\0'; i++) {
        if (carta->nomeCidade[i] == '\n'){
            carta->nomeCidade[i] = '\0';
        }
    }
    printf("Populacao: ");
    scanf("%lu", &carta->Populacao);

    do {
        printf("Area (em Km²): ");
        scanf("%f", &carta->Area);
        if (carta->Area <= 0){
            printf("Area Invalida!\n");
        }
    } while (carta -> Area <= 0);

    printf(" PIB (Em bilhoes de reais): ");
    scanf("%f", &carta -> PIB);

    printf(" Numero de Pontos Turisticos: ");
    scanf("%d", &carta -> PontosTuristicos);

    carta->Densidade = carta->Populacao / carta->Area;
    carta->PibPercapita = (carta->PIB * 1e9) / carta-> Populacao;
    carta->SuperPoder =
        (float)carta->Populacao +
        carta->Area +
        carta->PIB +
        (float)carta->PontosTuristicos +
        carta->PibPercapita +
        (1.0f / carta->Densidade);;

}
