/* UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
NOMBRE: JORDY CEVALLOS
PRUEBA PARCIAL 2 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int minrango, maxrango;
    int numerosecreto;
    int intentousuario;
    int intentosrealizados = 0;
    int adivinado = 0;
    int maxintentos;
    int intentos[10];               // Para verificar duplicados
    int matrizintentos[10][2];      // [numero de intento][0=valor, 1=resultado]

    // RF01 – Usuario define el rango
    do {
        printf("Ingrese el valor minimo del rango: ");
        scanf("%d", &minrango);
        printf("Ingrese el valor maximo del rango: ");
        scanf("%d", &maxrango);

        if (minrango >= maxrango) {
            printf("El valor minimo debe ser menor que el maximo. Intenta de nuevo.\n");
        }
    } while (minrango >= maxrango);

    // Generar número secreto dentro del rango definido
    numerosecreto = rand() % (maxrango - minrango + 1) + minrango;

    // RF02 – Configuración dinámica de intentos
    do {
        printf("Cuantos intentos deseas tener Maximo 10: ");
        scanf("%d", &maxintentos);
        if (maxintentos < 1 || maxintentos > 10) {
            printf("Numero no valido. Debe estar entre 1 y 10.\n");
        }
    } while (maxintentos < 1 || maxintentos > 10);

    printf("Adivina el numero entre %d y %d. Tienes %d intentos.\n\n", minrango, maxrango, maxintentos);

    for (int i = 0; i < maxintentos; ) {
        int duplicado = 0;
        printf("Intento %d: ", i + 1);
        scanf("%d", &intentousuario);

        // RF03 – Validacion de rango
        if (intentousuario < minrango || intentousuario > maxrango) {
            printf("Por favor ingresa un numero entre %d y %d.\n", minrango, maxrango);
            continue;
        }

        // RF03 – Validacion de duplicados
        for (int j = 0; j < i; j++) {
            if (intentousuario == intentos[j]) {
                duplicado = 1;
                break;
            }
        }
        if (duplicado) {
            printf("Ya ingresaste ese numero. Intenta con uno diferente.\n");
            continue;
        }

        // Almacenar intento
        intentos[i] = intentousuario;
        matrizintentos[i][0] = intentousuario;

        if (intentousuario == numerosecreto) {
            printf("Correcto Has adivinado el numero.\n");
            matrizintentos[i][1] = 2; // Correcto
            adivinado = 1;
            intentosrealizados = i + 1;
            break;
        } else if (intentousuario < numerosecreto) {
            printf("Muy bajo.\n");
            matrizintentos[i][1] = 0; // Muy bajo
        } else {
            printf("Muy alto.\n");
            matrizintentos[i][1] = 1; // Muy alto
        }

        i++;  // Aumenta solo si el intento es válido
        intentosrealizados = i;
    }

    // RF05 – Visualización de resumen detallado
    printf("\n----- RESUMEN DEL JUEGO -----\n");
    printf("Numero secreto: %d\n", numerosecreto);
    printf("Intentos realizados: %d\n", intentosrealizados);
    printf("\nIntento   Valor ingresado   Resultado\n");

    for (int i = 0; i < intentosrealizados; i++) {
        printf("%d          %d              ", i + 1, matrizintentos[i][0]);
        switch (matrizintentos[i][1]) {
            case 0:
                printf("Muy bajo\n");
                break;
            case 1:
                printf("Muy alto\n");
                break;
            case 2:
                printf("Correcto\n");
                break;
        }
    }

    if (!adivinado) {
        printf("\nNo adivinaste el número.Sigue participando\n");
    } else {
        printf("\nFelicidades, eres un genio \n");
    }

    return 0;
}
