
#include <stdio.h>
#include "mimath.h"
#include "factorial.h"

int main() {
    float a = 5.0, b = 3.0;
    int n = 5;

    printf("Suma: %.2f\n", suma(a, b));
    printf("Resta: %.2f\n", resta(a, b));
    printf("Multiplicación: %.2f\n", multiplicacion(a, b));
    printf("División: %.2f\n", division(a, b));
    printf("Fibonacci de %d: %d\n", n, fibonacci(n));

    return 0;
}