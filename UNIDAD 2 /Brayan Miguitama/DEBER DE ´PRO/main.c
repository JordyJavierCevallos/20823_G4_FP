#include <stdio.h>
#include "mimath.h"

int main() {
    float a = 5.0, b = 3.0;
    int n = 5;

    printf("Suma: %.2f\n", suma(a, b));
    printf("Resta: %.2f\n", resta(a, b));
    printf("División: %.2f\n", division(a, b));
    printf("Factorial de %d: %d\n", n, factorial(n));

    return 0;
}
