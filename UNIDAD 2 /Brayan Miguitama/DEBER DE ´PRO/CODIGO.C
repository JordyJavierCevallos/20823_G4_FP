#include <stdio.h>

// Declaraci�n de funciones
float suma(float a, float b);
float resta(float a, float b);
float division(float a, float b);
int factorial(int n);

// Definici�n de funciones
float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float division(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        printf("Error: divisi�n por cero.\n");
        return 0;
    }
}

int factorial(int n) {
    if (n < 0) {
        printf("Error: factorial no definido para n�meros negativos.\n");
        return 0;
    }
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Funci�n principal
int main() {
    float a = 5.0, b = 3.0;
    int n = 5;

    printf("Suma: %.2f\n", suma(a, b));
    printf("Resta: %.2f\n", resta(a, b));
    printf("Divisi�n: %.2f\n", division(a, b));
    printf("Factorial de %d: %d\n", n, factorial(n));

    return 0;
}
