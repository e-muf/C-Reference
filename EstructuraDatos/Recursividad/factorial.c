#include <stdio.h>

// Prototipos
int factorial(int);
int factorialRecursivo(int);

int main() {
    
    int number;

    printf("FACTORIAL");

    printf("\nIngrese el número a calcular: ");
    scanf("%d", &number);

    printf("\nFactorial secuencial: %d", factorial(number));

    printf("\nFactorial recursivo: %d\n", factorialRecursivo(number));

    return 0;
}

// Factorial de un número (normal)
int factorial(int number) {
    int i = number-1;
    
    for(; i > 0; i--) {
        number *= i;
    }

    return number>0 ? number : 1;
}

// Factorial recursivo
int factorialRecursivo(int number) {
    // Caso base
    if(number <= 1)
        return 1;

    // Caso recursivo
    else {
        return number * factorial(number - 1);
    }
}