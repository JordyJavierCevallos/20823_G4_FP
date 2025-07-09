#include <stdio.h>

int main() {
    char nombres[100][50];
    char apellidos[100][50];
    char telefonos[100][20];
    char correos[100][50];
    int opcion, total = 0;

    while (1) {
        printf("\n----- AGENDA TELEF�NICA -----\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Salir\n");
        printf("Elige una opci�n: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            printf("\nIngrese el nombre: ");
            fgets(nombres[total], 50, stdin);

            printf("Ingrese el apellido: ");
            fgets(apellidos[total], 50, stdin);

            printf("Ingrese el n�mero telef�nico: ");
            fgets(telefonos[total], 20, stdin);

            printf("Ingrese el correo electr�nico: ");
            fgets(correos[total], 50, stdin);

            total++;
            printf("Contacto agregado correctamente.\n");
        }
        else if (opcion == 2) {
            if (total == 0) {
                printf("\nNo hay contactos registrados.\n");
            } else {
                printf("\n--- Lista de contactos ---\n");
                for (int i = 0; i < total; i++) {
                    printf("\nContacto %d:\n", i + 1);
                    printf("Nombre: %s", nombres[i]);
                    printf("Apellido: %s", apellidos[i]);
                    printf("Tel�fono: %s", telefonos[i]);
                    printf("Correo: %s", correos[i]);
                }
            }
        }
        else if (opcion == 3) {
            printf("\nSaliendo del programa...\n");
            break;
        }
        else {
            printf("\nOpci�n no v�lida. Intenta de nuevo.\n");
        }
    }

    return 0;
}
