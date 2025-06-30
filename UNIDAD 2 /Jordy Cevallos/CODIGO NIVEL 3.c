/* UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
NOMBRE: JORDY CEVALLOS
REQUISITOS FUNCIONALES NIVEL 2 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int minRango, maxRango;
    int numeroSecreto;
    int intentoUsuario;
    int intentosRealizados = 0;
    int adivinado = 0;
    int maxIntentos;

    int intentos[10];               // Para verificar duplicados
    int matrizIntentos[10][3];      // [n° intento][0=valor, 1=resultado, 2=no usado]

    // Inicializar generador aleatorio
    srand(time(NULL));

    // RF01 – Configuración dinámica del rango
    do {
        printf("Ingrese el valor mínimo del rango: ");
        scanf("%d", &minRango);
        printf("Ingrese el valor máximo del rango: ");
        scanf("%d", &maxRango);

        if (minRango >= maxRango) {
            printf("El valor mínimo debe ser menor que el máximo. Intenta de nuevo.\n");
        }
    } while (minRango >= maxRango);

    // Generar número secreto dentro del rango definido
    numeroSecreto = rand() % (maxRango - minRango + 1) + minRango;

    // RF02 – Configuración dinámica de intentos
    do {
        printf("¿Cuántos intentos deseas tener? (Máximo 10): ");
        scanf("%d", &maxIntentos);
        if (maxIntentos < 1 || maxIntentos > 10) {
            printf("Número no válido. Debe estar entre 1 y 10.\n");
        }
    } while (maxIntentos < 1 || maxIntentos > 10);

    printf("Adivina el número entre %d y %d. Tienes %d intentos.\n\n", minRango, maxRango, maxIntentos);

    for (int i = 0; i < maxIntentos; ) {
        int duplicado = 0;
        printf("Intento %d: ", i + 1);
        scanf("%d", &intentoUsuario);

        // RF03 – Validación de rango
        if (intentoUsuario < minRango || intentoUsuario > maxRango) {
            printf("Por favor ingresa un número entre %d y %d.\n", minRango, maxRango);
            continue;
        }

        // RF03 – Validación de duplicados
        for (int j = 0; j < i; j++) {
            if (intentoUsuario == intentos[j]) {
                duplicado = 1;
                break;
            }
        }

        if (duplicado) {
            printf("Ya ingresaste ese número. Intenta con uno diferente.\n");
            continue;
        }

        // Almacenar intento
        intentos[i] = intentoUsuario;
        matrizIntentos[i][0] = intentoUsuario;

        if (intentoUsuario == numeroSecreto) {
            printf("¡Correcto! Has adivinado el número.\n");
            matrizIntentos[i][1] = 2; // correcto
            adivinado = 1;
            intentosRealizados = i + 1;
            break;
        } else if (intentoUsuario < numeroSecreto) {
            printf("Muy bajo.\n");
            matrizIntentos[i][1] = 0;
        } else {
            printf("Muy alto.\n");
            matrizIntentos[i][1] = 1;
        }

        i++;
        intentosRealizados = i;
    }

    // RF05 – Visualización de resumen detallado
    printf("\n----- RESUMEN DEL JUEGO -----\n");
    printf("Número secreto: %d\n", numeroSecreto);
    printf("Intentos realizados: %d\n", intentosRealizados);
    printf("\n%-10s %-15s %-15s\n", "Intento", "Valor ingresado", "Resultado");
    for (int i = 0; i < intentosRealizados; i++) {
        printf("%-10d %-15d ", i + 1, matrizIntentos[i][0]);
        switch (matrizIntentos[i][1]) {
            case 0:
                printf("%-15s\n", "Muy bajo");
                break;
            case 1:
                printf("%-15s\n", "Muy alto");
                break;
            case 2:
                printf("%-15s\n", "¡Correcto!");
                break;
        }
    }

    if (!adivinado) {
        printf("\nNo adivinaste el número. ¡Sigue participando!\n");
    } else {
        printf("\n¡Felicidades, eres un ganador! ¡Sigue así!\n");
        printf("Mensaje secreto: ¡Eres un genio!\n");
    }

    return 0;
}
