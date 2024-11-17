/*
BACHARELADO MATEMÁTICA UNIVERSIDADE POSITIVO / CRUZEIRO DO SUL 2024-2026
Autor: GIOVANNI DE ALMEIDA COSTA - RGM 38153386
--- TEORIA ARITMÉTICA DOS NÚMEROS ---
TEOREMA FUNDAMENTAL DA ARITMÉTICA - FATORAÇÃO
*/

#include <stdio.h>
#include "mathGAC.h"

int main() {
    int numero;
    struct Fator fatores[100]; // Tamanho máximo do vetor de fatores126
    printf("Fatorar que numero? : ");
    scanf("%d",&numero);
    int tamanho = 0;

    fatorar(numero, fatores, &tamanho);

    printf("%d fatores: ", numero);
    for (int i = 0; i < tamanho; ++i) {
        printf("[%d,%d]", fatores[i].valor, fatores[i].quantidade);
        if (i < tamanho - 1) {
            printf("; ");
        }
    }
    printf("\n");

    return 0;
}
