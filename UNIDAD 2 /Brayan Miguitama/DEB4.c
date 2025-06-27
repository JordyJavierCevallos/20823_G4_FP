#include "mimath.h"

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b != 0)
        return a / b;
    else
        return 0; // manejo básico de división por cero
}
