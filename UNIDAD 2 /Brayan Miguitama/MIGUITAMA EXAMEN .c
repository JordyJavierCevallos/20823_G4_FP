//UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
// EXAMEN UNIDAD 2
// NOMBRE: BRYAN MIGUITAMA
//NRC: 20823

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INTENTOS 10 // Máximo número de intentos que se pueden guardar

// Estructura para almacenar los intentos
struct Intento {
    int numero;     // Número de intento (1, 2, 3, ...)
    int valor;      // Número ingresado por el usuario
    int resultado;  // 0 = bajo, 1 = alto, 2 = correcto
};

// Función para verificar si un número ya fue intentado
int ya_intentado(struct Intento intentos[], int total, int valor) {
    for (int i = 0; i < total; i++) {
        if (intentos[i].valor == valor)
            return 1; // Ya fue intentado
    }
    return 0; // No fue intentado aún
}

int main() {
    // ===== 1. INICIALIZACIÓN Y GENERACIÓN DEL NÚMERO ALEATORIO =====
    int rango_min, rango_max, max_intentos, secreto;
    struct Intento intentos[MAX_INTENTOS]; // ===== 3. MATRIZ PARA ALMACENAR DATOS =====
    int total_intentos = 0;

    srand(time(NULL)); // Inicializar semilla de números aleatorios

    // ===== 2. INGRESO Y VALIDACIÓN DE DATOS =====
    printf("Ingrese el rango minimo: ");
    scanf("%d", &rango_min);

    printf("Ingrese el rango maximo: ");
    scanf("%d", &rango_max);

    if (rango_min >= rango_max) {
        printf("Rango invalido. El minimo debe ser menor que el maximo.\n");
        return 0;
    }

    printf("Ingrese el numero maximo de intentos: ");
    scanf("%d", &max_intentos);

    if (max_intentos > MAX_INTENTOS) {
        printf("Demasiados intentos. Maximo permitido: %d\n", MAX_INTENTOS);
        return 0;
    }

    secreto = rand() % (rango_max - rango_min + 1) + rango_min;

    // ===== 4. CONDICIONES Y CONTROL DE FLUJO =====
    while (total_intentos < max_intentos) {
        int intento_valor;

        printf("\nIntento %d de %d. Ingrese un numero entre %d y %d: ",
               total_intentos + 1, max_intentos, rango_min, rango_max);
        scanf("%d", &intento_valor);

        if (intento_valor < rango_min || intento_valor > rango_max) {
            printf("El numero esta fuera del rango.\n");
            continue;
        }

        if (ya_intentado(intentos, total_intentos, intento_valor)) {
            printf("Ya intentaste ese numero. Intenta otro diferente.\n");
            continue;
        }

        int resultado;
        if (intento_valor < secreto) {
            resultado = 0;
            printf("Muy bajo.\n");
        } else if (intento_valor > secreto) {
            resultado = 1;
            printf("Muy alto.\n");
        } else {
            resultado = 2;
            printf("¡Correcto!\n");
        }

        // Guardar intento en la matriz
        intentos[total_intentos].numero = total_intentos + 1;
        intentos[total_intentos].valor = intento_valor;
        intentos[total_intentos].resultado = resultado;

        total_intentos++;

        if (resultado == 2) {
            break; // El número fue adivinado
        }
    }

    // ===== 5. MENSAJES FINALES Y CONDICIÓN DEL SECRETO =====
    printf("\nResumen de Intentos:\n");
    printf("Intento\tValor\tResultado\n");

    for (int i = 0; i < total_intentos; i++) {
        printf("%d\t%d\t", intentos[i].numero, intentos[i].valor);
        if (intentos[i].resultado == 0)
            printf("Muy bajo\n");
        else if (intentos[i].resultado == 1)
            printf("Muy alto\n");
        else
            printf("Correcto\n");
    }

    if (intentos[total_intentos - 1].resultado != 2) {
        printf("\nNo adivinaste el numero. El secreto era: %d\n", secreto);
    }

    return 0;
}
