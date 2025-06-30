// UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE//
// ANA SOFIA ULLOA
// 30/06/2025
//NRC: 20823

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10

int main() {
    int minimo, maximo;

    // RF01 - Configuración dinámica del rango
    printf("Ingrese el valor minimo : ");
    scanf("%d", &minimo);
    printf("Ingrese el valor maximo : ");
    scanf("%d", &maximo);

    if (minimo >= maximo) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 1;
    }

    int intentosPermitidos;

    // RF02 - Configuracion dinámica de intentos
    do {
        printf("Ingrese la cantidad de intentos (max %d): ", MAX_INTENTOS);
        scanf("%d", &intentosPermitidos);
        if (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS) {
            printf("Numero de intentos no valido. Intente nuevamente.\n");
        }
    } while (intentosPermitidos < 1 || intentosPermitidos > MAX_INTENTOS);

    // RF04 - Registro de intentos en matriz
    int intentos[MAX_INTENTOS][3];
    for (int i = 0; i < MAX_INTENTOS; i++) {
        intentos[i][0] = i + 1;
        intentos[i][1] = 0;    // inicia en 0
        intentos[i][2] = -1;   
    }

    int numeroSecreto;
    int adivinado = 0;
    int numIntentosValidos = 0;

    srand(time(NULL));
    numeroSecreto = rand() % (maximo - minimo + 1) + minimo;

    for (int i = 0; i < intentosPermitidos; ) {
        int intento;
        printf("Intento %d: Ingresa un numero entre %d y %d: ", i + 1, minimo, maximo);
        scanf("%d", &intento);

        // RF03 - Validación de rango y duplicados
        if (intento < minimo || intento > maximo) {
            printf("Numero fuera del rango.\n");
            continue;
        }

        // RF03 - Validación de rango y duplicados
        int repetido = 0;
        for (int j = 0; j < numIntentosValidos; j++) {
            if (intentos[j][1] == intento) {
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            printf("Ya ingresaste ese numero. Intenta con otro.\n");
            continue;
        }

        // Guardar intentos valiudos
        intentos[i][1] = intento;

        // Determina si el intento fue correcto si fue muy alto o muy bajo
        if (intento == numeroSecreto) {
            intentos[i][2] = 2; // correcto
            printf("\nAdivinaste, el numero secreto es %d .\n",numeroSecreto);
            adivinado = 1;
            numIntentosValidos++;
            i++;
            break;
        } else if (intento < numeroSecreto) {
            intentos[i][2] = 0; // bajo
            printf("Muy bajo.\n");
        } else {
            intentos[i][2] = 1; // alto
            printf("Muy alto.\n");
        }

        numIntentosValidos++;
        i++;
    }

    // Rellena intentos restantes con 0 
    for (int k = numIntentosValidos; k < intentosPermitidos; k++) {
        intentos[k][1] = 0;
        intentos[k][2] = -1; // indica que no fue un intento real
    }

    // RF05 -  Visualización de resumen detallado
    printf("\nResumen detallado de intentos:\n");
    printf("Intento | Valor  | Resultado\n");
    printf("-------------------------------------\n");
    for (int k = 0; k < intentosPermitidos; k++) {
        printf("%6d | %6d | ", intentos[k][0], intentos[k][1]);
        switch (intentos[k][2]) {
            case 0:
                printf("Muy bajo\n");
                break;
            case 1:
                printf("muy alto\n");
                break;
            case 2:
                printf("Correcto\n");
                break;
            case -1:
                printf("Vacio\n");
                break;
        }
    }

    if (!adivinado) {
        printf("\nNo lograste adivinar el numero secreto.\n");
        printf("El numero secreto era: %d\n", numeroSecreto);
    }

    return 0;
}
