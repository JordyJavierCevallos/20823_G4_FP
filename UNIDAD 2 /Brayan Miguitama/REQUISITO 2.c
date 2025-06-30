#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int minimo, maximo;
    int intentosMax, intento, numeroSecreto;
    int intentos[10];  // RF04: Vector para almacenar los intentos
    int acierto = 0;

    // RF01: Configuración del rango
    printf("Ingrese el valor minimo del rango: ");
    scanf("%d", &minimo);
    printf("Ingrese el valor maximo del rango: ");
    scanf("%d", &maximo);

    // Validar que el rango sea correcto
    if (minimo >= maximo) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 1;
    }

    // RF02: Configuración del número de intentos
    do {
        printf("Ingrese la cantidad de intentos (maximo 10): ");
        scanf("%d", &intentosMax);
        if (intentosMax < 1 || intentosMax > 10) {
            printf("Cantidad invalida. Debe estar entre 1 y 10.\n");
        }
    } while (intentosMax < 1 || intentosMax > 10);

    // Generar número secreto dentro del rango
    srand(time(NULL));
    numeroSecreto = minimo + rand() % (maximo - minimo + 1);

    // RF03 y RF04: Intentos con validación y almacenamiento
    for (int i = 0; i < intentosMax; i++) {
        printf("Intento %d: Ingrese un numero entre %d y %d: ", i + 1, minimo, maximo);
        scanf("%d", &intento);

        if (intento < minimo || intento > maximo) {
            printf("El numero esta fuera del rango. No se cuenta el intento.\n");
            i--; // No se cuenta el intento inválido
            continue;
        }

        intentos[i] = intento;

        if (intento == numeroSecreto) {
            printf("¡Adivinaste el numero secreto!\n");
            acierto = 1;
            break;
        } else if (intento < numeroSecreto) {
            printf("El numero secreto es mayor.\n");
        } else {
            printf("El numero secreto es menor.\n");
        }
    }

    // RF05: Visualización de resultados
    printf("\n--- Resumen del juego ---\n");
    printf("Numero secreto: %d\n", numeroSecreto);
    printf("Intentos realizados:\n");
    for (int i = 0; i < intentosMax; i++) {
        if (intentos[i] >= minimo && intentos[i] <= maximo)
            printf("Intento %d: %d\n", i + 1, intentos[i]);
    }

    if (!acierto) {
        printf("No lograste adivinar el numero secreto.\n");
    }

    return 0;
}
