//UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
//NOMBRES: BRYAN MIGUITAMA, ANA ULLOA, JORDY CEVALLOS
//NRC:20823
//GRUPO:4

#include <stdio.h>

#define MAX 100  // Maximo tamano del vector

// Declaracion de funciones
int ingresarCantidad();
void calcularVector(int vec[], int n);
void mostrarVector(int vec[], int n);

int main() {
    int opcion, n = 0;
    int vec[MAX];  // Vector principal

    do {
        // Menu principal
        printf("  MENU DE OPCIONES\n\n");


        printf("1. Ingresar numero de terminos\n");
        printf("2. Calcular vector\n");
        printf("3. Mostrar vector\n");
        printf("4. Salir\n\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                n = ingresarCantidad();
                break;
            case 2:
                if (n > 0)
                    calcularVector(vec, n);
                else
                    printf("Primero debe ingresar un numero valido.\n");
                break;
            case 3:
                if (n > 0)
                    mostrarVector(vec, n);
                else
                    printf("Debe calcular primero el vector.\n");
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}

// Funcion para ingresar el numero de terminos
int ingresarCantidad() {
    int n;
    printf("Ingrese el numero de terminos (1 a 100): ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Error: numero fuera de rango.\n");
        return 0;
    }
    return n;
}

// Funcion que calcula el vector y muestra el proceso de calculo
void calcularVector(int vec[], int n) {
    printf("\nCalculando valores con la formula: (i + 1)^2 + 3\n");
    for (int i = 0; i < n; i++) {
        int base = i + 1;
        vec[i] = base * base + 3;
        printf("vec[%d] = (%d)^2 + 3 = %d\n", i + 1, base, vec[i]);
    }
    printf("Vector calculado correctamente.\n");
}

// Funcion que solo muestra los valores ya calculados
void mostrarVector(int vec[], int n) {
    printf("\nResultados del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("vec[%d] = %d\n", i + 1, vec[i]);
    }
}
