#include <stdio.h>
#include <stdlib.h>

#define TOTAL_CARTAS 2

typedef struct {
    char Estado;
    char Codigo[4];
    char NomeCidade[100];
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
        scanf(" %c", &carta->Estado);
        if (carta->Estado< 'A' || carta->Estado > 'H' ) {
            printf("Estado Invalido! Digite uma letra de A a H.\n");
        }
    } while (carta->Estado < 'A' || carta->Estado > 'H');

    printf("Codigo da Carta: ");
    scanf(" %s", carta->Codigo);
    
    printf("Nome da Cidade: ");
    getchar();
    fgets(carta-> NomeCidade, sizeof(carta->NomeCidade), stdin);

    for (int i = 0; carta->NomeCidade[i] != '\0'; i++) {
        if (carta->NomeCidade[i] == '\n'){
            carta->NomeCidade[i] = '\0';
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


void imprimirCarta(CARTA carta, int numero){
    printf("\nCarta %d: \n", numero);
    printf("Estado: %c \n ", carta.Estado);
    printf("Codigo: %s \n", carta.Codigo);
    printf("Nome da Cidade: %s\n", carta.NomeCidade);
    printf("Populacao: %lu\n", carta.Populacao);
    printf("Area: %.3f Km²\n", carta.Area);
    printf("PIB: %.3f bilhoes de reais\n", carta.PIB);
    printf("Numero de Pontos Turisticos: %d\n", carta.PontosTuristicos);
    printf("Densidade Populacioanal: %.3f\n", carta.Densidade);
    printf("PIB per Capita: %.3f\n", carta.PibPercapita);
    printf("Super Poder: %.3f\n", carta.SuperPoder); 
}

void compararCartas(CARTA C1, CARTA C2){
    printf("\n=== Comparacao de Cartas ===\n");

    printf("Populacao: Carta 1 venceu! (%d)\n", C1.Populacao > C2.Populacao);
    printf("Area: Carta 1 venceu! (%d)\n", C1.Area > C2.Area);
    printf("PIB: Carta 1 venceu! (%d)\n", C1.PIB > C2.PIB);
    printf("Pontos Turisticos: Carta 1 venceu! (%d)\n", C1.PontosTuristicos > C2.PontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu! (%d)\n", C1.Densidade < C2.Densidade);
    printf("PIB per Capita: Carta 1 venceu! (%d)\n", C1.PibPercapita > C2.PibPercapita);
    printf("Super Poder: Carta 1 venceu! (%d)\n", C1.SuperPoder > C2.SuperPoder);
}

int main(){
    CARTA cartas[TOTAL_CARTAS];

    for (int i = 0; i < TOTAL_CARTAS; i++) {
        lerCarta(&cartas[i], i+1);
    }

    printf("\n=== Informacoes das Cartas ===\n");
    for(int = 0; i < TOTAL_CARTAS; i++) {
        imprimirCarta(cartas[i], i + 1);
    }

    compararCartas(cartas[0], cartas[1]);

    return 0;
}