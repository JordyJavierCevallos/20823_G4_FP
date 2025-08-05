/*UNIVERSIDAD DE LAS FUERZAS ARMADAS
            ESPE
PROYECTO DE FUNDAMENTOS DE PROGRAMACION
INTEGRANTES: JORDY CEVALLOS, ANA ULLOA, BRYAN MIGUITAMA
        PARQUEADERO AUTOMATIZADO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifdef _WIN32
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

#define MAX_VEHICULOS 60

typedef struct {
    char placa[10];
    char marca[20];
    char color[15];
    char horaEntrada[6];
    char horaSalida[6];
    float precioPagado;
} Vehiculo;

// Limpia buffer para evitar problemas
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Espera que el usuario presione ENTER una sola vez
void esperarEnter() {
    printf("Presione ENTER para continuar...");
    limpiarBuffer();
    getchar();
}

// Función para convertir cadena a mayúsculas
void convertirAMayusculas(char *cadena) {
    for (int i = 0; cadena[i]; i++) {
        cadena[i] = toupper((unsigned char)cadena[i]);
    }
}

// Función para validar que solo contenga letras
int esTextoValido(const char *texto) {
    for (int i = 0; texto[i]; i++) {
        if (!isalpha((unsigned char)texto[i])) {
            return 0;  // No es letra
        }
    }
    return 1;  // Solo letras
}

void crearDirectorioResumenes() {
    mkdir("resumenes", 0777); // Crear carpeta si no existe
}

int convertirHoraAMinutos(const char *hora) {
    int h, m;
    sscanf(hora, "%d:%d", &h, &m);
    return h * 60 + m;
}

float calcularPrecio(char *entrada, char *salida) {
    int minutosEntrada = convertirHoraAMinutos(entrada);
    int minutosSalida = convertirHoraAMinutos(salida);
    int duracion = minutosSalida - minutosEntrada;

    if (duracion <= 15) return 0.0;
    if (duracion < 60) return 0.50;

    int horasCompletas = duracion / 60;
    int minutosRestantes = duracion % 60;
    float precio = horasCompletas * 0.75;

    if (minutosRestantes >= 30) {
        precio += 0.50;
    }

    return precio;
}

int validarPlaca(const char *placa) {
    int len = strlen(placa);
    if (len < 6 || len > 7) return 0;  // Acepta solo placas de 6 o 7 caracteres

    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i])) return 0;  // Primeros 3 deben ser letras
    }
    for (int i = 3; i < len; i++) {
        if (!isdigit(placa[i])) return 0;  // Resto deben ser dígitos
    }
    return 1;
}

int esHoraValida(const char *hora) {
    int h, m;
    if (sscanf(hora, "%d:%d", &h, &m) != 2) return 0;
    if (h < 0 || h > 23 || m < 0 || m > 59) return 0;
    return 1;
}

void registrarIngreso(Vehiculo parqueadero[], int *cantidad) {
    if (*cantidad >= MAX_VEHICULOS) {
        printf("\nEl parqueadero esta lleno.\n");
        return;
    }

    Vehiculo nuevo;
    do {
        printf("\nIngrese la placa (formato ABC1234): ");
        scanf("%9s", nuevo.placa);
        convertirAMayusculas(nuevo.placa);
        if (!validarPlaca(nuevo.placa)) {
            printf("Placa invalida. Debe tener 3 letras y 4 numeros.\n");
            limpiarBuffer();
        }
    } while (!validarPlaca(nuevo.placa));

    do {
        printf("Ingrese la marca: ");
        scanf("%19s", nuevo.marca);
        if (!esTextoValido(nuevo.marca)) {
            printf("Marca invalida. Solo se permiten letras.\n");
            limpiarBuffer();
        }
    } while (!esTextoValido(nuevo.marca));

    do {
        printf("Ingrese el color: ");
        scanf("%14s", nuevo.color);
        if (!esTextoValido(nuevo.color)) {
            printf("Color invalido. Solo se permiten letras.\n");
            limpiarBuffer();
        }
    } while (!esTextoValido(nuevo.color));

    do {
        printf("Ingrese la hora de entrada (hh:mm): ");
        scanf("%5s", nuevo.horaEntrada);
        if (!esHoraValida(nuevo.horaEntrada)) {
            printf("Hora de entrada invalida. Formato correcto HH:MM, rango 00:00 a 23:59.\n");
            limpiarBuffer();
        }
    } while (!esHoraValida(nuevo.horaEntrada));

    strcpy(nuevo.horaSalida, "");
    nuevo.precioPagado = 0.0;

    parqueadero[*cantidad] = nuevo;
    (*cantidad)++;

    printf("Vehiculo registrado exitosamente.\n");
}

void registrarSalida(Vehiculo parqueadero[], int cantidad) {
    char placa[10];
    do {
        printf("\nIngrese la placa del vehiculo que va a salir: ");
        scanf("%9s", placa);
        convertirAMayusculas(placa);
        if (!validarPlaca(placa)) {
            printf("Placa invalida. Debe tener 3 letras y 4 numeros.\n");
            limpiarBuffer();
        } else break;
    } while (1);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(parqueadero[i].placa, placa) == 0 && parqueadero[i].precioPagado == 0.0) {
            do {
                printf("Ingrese la hora de salida (hh:mm): ");
                scanf("%5s", parqueadero[i].horaSalida);
                if (!esHoraValida(parqueadero[i].horaSalida)) {
                    printf("Hora de salida invalida. Formato correcto HH:MM, rango 00:00 a 23:59.\n");
                    limpiarBuffer();
                }
            } while (!esHoraValida(parqueadero[i].horaSalida));

            int minutosEntrada = convertirHoraAMinutos(parqueadero[i].horaEntrada);
            int minutosSalida = convertirHoraAMinutos(parqueadero[i].horaSalida);

            if (minutosSalida < minutosEntrada) {
                printf("La hora de salida no puede ser anterior a la hora de entrada.\n");
                strcpy(parqueadero[i].horaSalida, "");
                return;
            }

            parqueadero[i].precioPagado = calcularPrecio(parqueadero[i].horaEntrada, parqueadero[i].horaSalida);
            printf("Precio a pagar: $%.2f\n", parqueadero[i].precioPagado);
            return;
        }
    }
    printf("Vehiculo no encontrado o ya salio.\n");
}

void mostrarVehiculos(Vehiculo parqueadero[], int cantidad) {
    printf("\n--- Lista de Vehiculos ---\n");

    if (cantidad == 0) {
        printf("No ha ingresado ningun vehiculo al parqueadero.\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("Placa: %s | Marca: %s | Color: %s | Entrada: %s | Salida: %s | Pagado: $%.2f\n",
               parqueadero[i].placa,
               parqueadero[i].marca,
               parqueadero[i].color,
               parqueadero[i].horaEntrada,
               strcmp(parqueadero[i].horaSalida, "") == 0 ? "--:--" : parqueadero[i].horaSalida,
               parqueadero[i].precioPagado);
    }
}

void buscarVehiculo(Vehiculo parqueadero[], int cantidad) {
    char placa[10];
    do {
        printf("\nIngrese la placa a buscar: ");
        scanf("%9s", placa);
        convertirAMayusculas(placa);
        if (!validarPlaca(placa)) {
            printf("Placa invalida. Debe tener 3 letras y 4 numeros.\n");
            limpiarBuffer();
        } else break;
    } while (1);

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(parqueadero[i].placa, placa) == 0) {
            printf("Placa: %s | Marca: %s | Color: %s | Entrada: %s | Salida: %s | Pagado: $%.2f\n",
                   parqueadero[i].placa,
                   parqueadero[i].marca,
                   parqueadero[i].color,
                   parqueadero[i].horaEntrada,
                   strcmp(parqueadero[i].horaSalida, "") == 0 ? "--:--" : parqueadero[i].horaSalida,
                   parqueadero[i].precioPagado);
            return;
        }
    }
    printf("Vehiculo no encontrado.\n");
}

void modificarVehiculo(Vehiculo parqueadero[], int cantidad) {
	if (cantidad == 0){
		 printf("\nNo ha ingresado ningun vehiculo al parqueadero.\n");
        return;
	}
    char placa[10];
    int encontrado = 0;

    do {
        printf("\nIngrese la placa del vehiculo a modificar: ");
        scanf("%9s", placa);
        convertirAMayusculas(placa);

        if (!validarPlaca(placa)) {
            printf("Placa invalida. Debe tener 3 letras y 4 numeros.\n");
            // No limpiar buffer aquí porque scanf ya lee solo hasta espacio
            continue; // volver a pedir placa
        }

        // Buscar si la placa existe en el parqueadero
        encontrado = 0;
        for (int i = 0; i < cantidad; i++) {
            if (strcmp(parqueadero[i].placa, placa) == 0) {
                encontrado = 1;

                // Empezar proceso de modificación
                char nuevaPlaca[10];
                do {
                    printf("Ingrese la nueva placa (formato ABC1234): ");
                    scanf("%9s", nuevaPlaca);
                    convertirAMayusculas(nuevaPlaca);
                    if (!validarPlaca(nuevaPlaca)) {
                        printf("Placa invalida. Debe tener 3 letras y 4 numeros.\n");
                    }
                } while (!validarPlaca(nuevaPlaca));
                strcpy(parqueadero[i].placa, nuevaPlaca);

                do {
                    printf("Ingrese la nueva marca: ");
                    scanf("%19s", parqueadero[i].marca);
                    if (!esTextoValido(parqueadero[i].marca)) {
                        printf("Marca invalida. Solo se permiten letras.\n");
                    }
                } while (!esTextoValido(parqueadero[i].marca));

                do {
                    printf("Ingrese el nuevo color: ");
                    scanf("%14s", parqueadero[i].color);
                    if (!esTextoValido(parqueadero[i].color)) {
                        printf("Color invalido. Solo se permiten letras.\n");
                    }
                } while (!esTextoValido(parqueadero[i].color));

                printf("Vehiculo modificado correctamente.\n");
                break;  // salir del for
            }
        }

        if (!encontrado) {
            printf("Vehiculo no encontrado con la placa ingresada. Intente nuevamente.\n");
        }

    } while (!encontrado);
}


void finalizarDia(Vehiculo parqueadero[], int cantidad) {
    float total = 0.0;

    crearDirectorioResumenes();

    time_t t = time(NULL);
    struct tm *fecha = localtime(&t);

    // Crear nombre del archivo con la fecha actual
    char nombreArchivo[100];
    strftime(nombreArchivo, sizeof(nombreArchivo), "resumenes/resumen_%Y-%m-%d.txt", fecha);

    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo de resumen.\n");
        return;
    }

    // Obtener la fecha como texto
    char fechaTexto[30];
    strftime(fechaTexto, sizeof(fechaTexto), "%Y-%m-%d", fecha);

    fprintf(archivo, "--- RESUMEN DEL DIA ---\n");
    fprintf(archivo, "Fecha: %s\n\n", fechaTexto);

    printf("\n--- Cierre del Dia ---\n");
    printf("Fecha: %s\n", fechaTexto);

    for (int i = 0; i < cantidad; i++) {
        if (parqueadero[i].precioPagado > 0) {
            fprintf(archivo, "Placa: %s\n", parqueadero[i].placa);
            fprintf(archivo, "Marca: %s\n", parqueadero[i].marca);
            fprintf(archivo, "Color: %s\n", parqueadero[i].color);
            fprintf(archivo, "Hora de entrada: %s\n", parqueadero[i].horaEntrada);
            fprintf(archivo, "Hora de salida: %s\n", parqueadero[i].horaSalida);
            fprintf(archivo, "Precio pagado: $%.2f\n", parqueadero[i].precioPagado);
            fprintf(archivo, "-------------------------\n");

            printf("Placa: %s - Pago: $%.2f\n", parqueadero[i].placa, parqueadero[i].precioPagado);
            total += parqueadero[i].precioPagado;
        }
    }

    fprintf(archivo, "TOTAL RECAUDADO: $%.2f\n", total);
    fclose(archivo);

    printf("Total recaudado: $%.2f\n", total);
    printf("Resumen guardado en: %s\n", nombreArchivo);

#ifdef _WIN32
    // Ejecutar el bloc de notas en segundo plano
    char comando[150];
    sprintf(comando, "start notepad.exe %s", nombreArchivo);
    system(comando);
#endif
}


int main() {
    Vehiculo parqueadero[MAX_VEHICULOS];
    int cantidad = 0;
    int opcion;

    do {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("\n--- MENU PARQUEADERO ---\n");
        printf("1. Registrar ingreso de vehiculo\n");
        printf("2. Registrar salida de vehiculo\n");
        printf("3. Mostrar todos los vehiculos\n");
        printf("4. Buscar vehiculo por placa\n");
        printf("5. Modificar datos de vehiculo\n");
        printf("6. Finalizar dia y mostrar resumen\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        while (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida. Intente de nuevo.\n");
            limpiarBuffer();
            printf("Seleccione una opcion: ");
        }


        switch (opcion) {
            case 1:
                registrarIngreso(parqueadero, &cantidad);
                esperarEnter();
                break;
            case 2:
                registrarSalida(parqueadero, cantidad);
                esperarEnter();
                break;
            case 3:
                mostrarVehiculos(parqueadero, cantidad);
                esperarEnter();
                break;
            case 4:
                buscarVehiculo(parqueadero, cantidad);
                esperarEnter();
                break;
            case 5:
                modificarVehiculo(parqueadero, cantidad);
                esperarEnter();
                break;
            case 6:
                finalizarDia(parqueadero, cantidad);
                esperarEnter();
                break;
            case 7:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                esperarEnter();
                break;
        }

    } while (opcion != 7);

    return 0;
}
