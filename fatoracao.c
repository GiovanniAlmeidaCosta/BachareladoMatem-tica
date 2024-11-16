/*
BACHARELADO MATEMÁTICA UNIVERSIDADE POSITIVO / CRUZEIRO DO SUL
2024-2026
GIOVANNI DE ALMEIDA COSTA - RGM 38153386
--- TEORIA ARITMÉTICA DOS NÚMEROS ---
TEOREMA FUNDAMENTAL DA ARITMÉTICA - FATORAÇÃO
*/

#include <stdio.h>

// Estrutura para armazenar os fatores e suas quantidades
struct Fator {
    int valor;
    int quantidade;
    };

void fatorar(int n, struct Fator fatores[], int *tamanho);

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

// Retorna os fatores de um inteiro qualquer
void fatorar(int n, struct Fator fatores[], int *tamanho) {
    *tamanho = 0; // Inicializa o tamanho do vetor de fatores

    for (int i = 2; i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            ++count;
        }

        if (count > 0) {
            fatores[*tamanho].valor = i;
            fatores[*tamanho].quantidade = count;
            (*tamanho)++;
        }
    }
}
