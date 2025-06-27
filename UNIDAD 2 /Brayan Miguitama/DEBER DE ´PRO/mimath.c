#include <stdio.h>
#include "mimath.h"

// Funci�n para sumar dos n�meros
float suma(float a, float b) {
    return a + b;
}

// Funci�n para restar dos n�meros
float resta(float a, float b) {
    return a - b;
}

// Funci�n para dividir dos n�meros
float division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: divisi�n por cero.\n");
        return 0;
    }
}

// Funci�n para calcular el factorial de un n�mero entero
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
