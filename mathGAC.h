/*
    BACHARELADO MATEMÁTICA UNIVERSIDADE POSITIVO / CRUZEIRO DO SUL 2024-2026
    Biblioteca de funções matemáticas para a Linguagem C
    Autor: Giovanni de Almeida Costa - RGM 38153386
*/

#ifndef MATHGAC_H_INCLUDED
#define MATHGAC_H_INCLUDED

#include <math.h>
#include <stdlib.h>

/*
CONSTANTES & ESTRUTURAS 
*/

#define PI 3.14159265358979323846

// Estrutura para armazenar os fatores e suas quantidades
struct Fator {
    int valor;
    int quantidade;
};


/*
FUNÇÕES GERAIS
*/

// Retorna o número de dígitos de um número inteiro
int countDigits(unsigned long long num);

// Retorna se o número é palíndromo ou não
int isPalindrome(int num);


/*
TEORIA DOS NÚMEROS (NÚMEROS NATURAIS E INTEIROS)
*/

// Função para fatorar um número e preencher o vetor de fatores  --- TEOREMA FUNDAMENTAL DA ARTMÉTICA
void fatorar(int n, struct Fator fatores[], int *tamanho);

// Retorna o fatorial (n!) de um número inteiro
unsigned long long factorial(int n);

// Retorna se um número inteiro é primo ou não
int isPrime(int n);

// Retorna o número em uma determinada posição da sequência de Fibonacci
unsigned long long fibonacci(unsigned int pos);

// Retorna o mínimo múltiplo comum entre dois números
int leastCommonMultiple(int num1, int num2);

// Retorna o máximo divisor comum entre dois números
int greatestCommonDivisor(int num1, int num2);

// Define se o número é um número Armstrong ou não
int isArmstrongNumber(int candidate);


//
// FUNÇÕES
//

// Retorna as raízes de uma equação do 2o. Grau
int solveQuadraticEquation(float a, float b, float c, float *solutions);


#endif // MATHGAC_H_INCLUDED

// Retorna o número de dígitos de um número inteiro
int countDigits(unsigned long long num) {
    int count = 0;
    for (unsigned long long temp = num; temp > 0; temp /= 10) {
        ++count;
    }
    return count;
}

// Retorna se o número é palíndromo ou não
int isPalindrome(int num) {
    int originalNumber = num, reversed = 0, digit;

    while (originalNumber != 0) {
        digit = originalNumber % 10;
        reversed = reversed * 10 + digit;
        originalNumber /= 10;
    }

    return reversed == num;
}

// Retorna o fatorial (n!) de um número inteiro
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    
    unsigned long long result = 1;
    
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
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



// Retorna se um número é primo ou não
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 2) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    
    return 1;
}

// Retorna o número em uma determinada posição da sequência de Fibonacci
// Utilizando a fórmula fechada de Fibonacci
unsigned long long fibonacci(unsigned int pos) {
    unsigned long long result = 0;
    result = (pow((1+sqrt(5))/2,pos)-pow((1-sqrt(5))/2,pos))/sqrt(5);

    return result;
}

// Retorna o mínimo múltiplo comum entre dois números
int leastCommonMultiple(int num1, int num2) {
    int lcm = num1;

    for (int i = num1; i <= num1 * num2; i += num1) {
        if (i % num2 == 0) {
            lcm = i;
            break;
        }
    }

    return lcm;
}

// Retorna o máximo divisor comum entre dois números
int greatestCommonDivisor(int num1, int num2) {
    int temp;

    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return num1;
}

// Define se o número é um número Armstrong ou não
int isArmstrongNumber(int candidate) {
    int numberOfDigits = countDigits(candidate);
    int power = pow(10, numberOfDigits);
    int sum = 0;

    for (int i = candidate; i != 0; i /= 10) {
        int digit = i % 10;
        sum += pow(digit, numberOfDigits);
    }

    return sum == candidate;
}

// Retorna as raízes de uma equação do 2o. Grau
int solveQuadraticEquation(float a, float b, float c, float *solutions) {
    float delta = b * b - 4 * a * c;

    if (a == 0) {
        // a é zero, a equação é linear
        if (b == 0) {
            // b também é zero, a equação é degenerada
            return -1;
        } else {
            solutions[0] = -c / b;
            return 1;
        }
    } else if (delta > 0) {
        // duas raízes reais distintas
        solutions[0] = (-b + sqrt(delta)) / (2 * a);
        solutions[1] = (-b - sqrt(delta)) / (2 * a);
        return 2;
    } else if (delta == 0) {
        // uma raiz real dupla
        solutions[0] = -b / (2 * a);
        return 1;
    } else {
        // duas raízes complexas conjugadas
        solutions[0] = -b / (2 * a);
        solutions[1] = sqrt(-delta) / (2 * a);
        return 0;
    }
}
