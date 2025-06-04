#include <stdio.h>

int main() {
    int vector[11];
    int num1, num2, bandera1 = 0, bandera2 = 0;
    int i;

    printf("Ingrese 11 numeros para el vector:\n");
    for (i = 0; i < 11; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("Ingrese el primer numero a buscar: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero a buscar: ");
    scanf("%d", &num2);

    for (i = 0; i < 11; i++) {
        if (vector[i] == num1) {
            bandera1 = 1;
        }
        if (vector[i] == num2) {
            bandera2 = 1;
        }
    }

    if (bandera1 == 1 && bandera2 == 1) {
        printf("Ambos numeros pertenecen al vector.\n");
    } else {
        printf("Uno o ambos numeros no pertenecen al vector.\n");
    }

    return 0; 
}

