#include <stdio.h>
#include "mimath.h"

// Función para sumar dos números
float suma(float a, float b) {
    return a + b;
}

// Función para restar dos números
float resta(float a, float b) {
    return a - b;
}

// Función para dividir dos números
float division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: división por cero.\n");
        return 0;
    }
}

// Función para calcular el factorial de un número entero
int factorial(int n) {
    if (n < 0) {
        printf("Error: factorial no definido para negativos.\n");
        return 0;
    }
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}
