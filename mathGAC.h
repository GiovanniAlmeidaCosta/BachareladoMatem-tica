/*
    BACHARELADO MATEMÁTICA UNIVERSIDADE POSITIVO / CRUZEIRO DO SUL 2024-2026
    Biblioteca de funções matemáticas para a Linguagem C
    Autor: Giovanni de Almeida Costa - RGM 38153386
    https://github.com/GiovanniAlmeidaCosta/BachareladoMatematica/tree/main
*/

#ifndef MATHGAC_H_INCLUDED
#define MATHGAC_H_INCLUDED

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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
int countDigits(unsigned long long num) {
    int count = 0;
    do {
        count++;
        num /= 10;
    } while (num > 0);
    return count;
}

// Retorna se o número é palíndromo ou não
int isPalindrome(int num) {
    int original = num, reversed = 0;
    while (original != 0) {
        reversed = reversed * 10 + (original % 10);
        original /= 10;
    }
    return reversed == num;
}

// Retorna se um número é divisor de outro
int is_divisor(int number, int divisor) {
    return number % divisor == 0;
}

// Retorna a soma dos divisores de um número
int sum_of_divisors(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (is_divisor(number, i)) {
            sum += i;
        }
    }
    return sum;
}

// Retorna se o número é perfeito
int is_perfect_number(int number) {
    return sum_of_divisors(number) == number;
}

// Retorna o fatorial (n!) de um número inteiro
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Retorna o número em uma determinada posição da sequência de Fibonacci
unsigned long long fibonacci(unsigned int pos) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, pos) / sqrt(5));
}

/*
TEORIA DOS NÚMEROS (NÚMEROS NATURAIS E INTEIROS)
*/

// Função para fatorar um número e preencher o vetor de fatores
void fatorar(int n, struct Fator fatores[], int *tamanho) {
    *tamanho = 0;
    for (int i = 2; i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            fatores[*tamanho].valor = i;
            fatores[*tamanho].quantidade = count;
            (*tamanho)++;
        }
    }
}

// Retorna o MDC de 2 números
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Retorna o MMC de 2 números
int mmc(int a, int b) {
    return (a / mdc(a, b)) * b;
}

// Retorna se um número é primo ou não
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Função para calcular o inverso modular
int modular_inverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;

    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;

        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }

    if (r > 1) return -1; // Não há inverso modular
    if (t < 0) t += phi;
    return t;
}

// Teorema Chinês do Resto
int teorema_chines(int num[], int rem[], int n) {
    int prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= num[i];
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        int pp = prod / num[i];
        result += rem[i] * inverso_modular(pp, num[i]) * pp;
    }
    return result % prod;
}

// Função para calcular a potência modular (base^exp % mod)
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Função para gerar as chaves RSA
void generate_rsa_keys(int p, int q, int *e, int *d, int *n) {
    *n = p * q; // Modulus
    int phi = (p - 1) * (q - 1); // Função totiente de Euler

    *e = 17; // Valor inicial para e
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    *d = modular_inverse(*e, phi);
    if (*d == -1) {
        printf("Erro: não foi possível calcular o inverso modular.\n");
        exit(1);
    }
}

// Função para encriptar uma mensagem
long long encrypt_message(int mensagem, int e, int n) {
    return mod_exp(mensagem, e, n);
}

// Função para decriptar uma mensagem
long long decrypt_message(long long mensagem_encriptada, int d, int n) {
    return mod_exp(mensagem_encriptada, d, n);
}


/*
FUNÇÕES
*/

// Retorna as raízes de uma equação do 2o. Grau
int solveQuadraticEquation(float a, float b, float c, float *solutions) {
    float delta = b * b - 4 * a * c;

    if (a == 0) {
        if (b == 0) {
            return -1; // Equação degenerada
        } else {
            solutions[0] = -c / b;
            return 1;
        }
    } else if (delta > 0) {
        solutions[0] = (-b + sqrt(delta)) / (2 * a);
        solutions[1] = (-b - sqrt(delta)) / (2 * a);
        return 2;
    } else if (delta == 0) {
        solutions[0] = -b / (2 * a);
        return 1;
    } else {
        return 0; // Raízes complexas
    }
}

#endif // MATHGAC_H_INCLUDED
