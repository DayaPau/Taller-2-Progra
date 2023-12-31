#include <stdio.h>

void ingresarMascota(float *IDMas, char *nombre, char *tipo, char *nombredueño, float *edad);
void mostrarServicios(char IDs[][9], float precios[]);
void facturarServicio(float IDMas, char IDs[][9], float precios[]);

char IDs[5][9] = {
    "ABC12345",
    "DEF67890",
    "GHI54321",
    "JKL09876",
    "MNO13579"
};


int main() {
    int opcion;
    float IDMas;
    char nombre[20], tipo[10], nombredueño[20];
    float edad;
    float precios[5] = {15.0, 25.0, 10.0, 30.0, 20.0};  

    do {
        printf("===== MENÚ =====\n");
        printf("1. Ingreso Mascota\n");
        printf("2. Servicios\n");
        printf("3. Facturar Servicio\n");
        printf("0. Salir\n");
        printf("Ingrese el número de opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMascota(&IDMas, nombre, tipo, nombredueño, &edad);
                break;
            case 2:
                mostrarServicios(IDs, precios);
                break;
            case 3:
                facturarServicio(IDMas, IDs, precios);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
        printf("\n");
    } while (opcion != 0);
    return 0;
}

void ingresarMascota(float *IDMas, char *nombre, char *tipo, char *nombredueño, float *edad) {
    printf("Has seleccionado la opción: Ingreso Mascota\n");
    printf("Ingrese el ID de su mascota: ");
    scanf("%f", IDMas);

    printf("Ingrese el nombre de su mascota: ");
    scanf(" %[^\n]", nombre);

    printf("Ingrese el tipo de mascota: ");
    scanf(" %[^\n]", tipo);

    printf("Ingrese la edad de la mascota: ");
    scanf("%f", edad);

    printf("Ingrese el nombre del dueño: ");
    scanf(" %[^\n]", nombredueño);
}

void mostrarServicios(char IDs[][9], float precios[]) {
    char nombres[5][50] = {
        "1. Vacunación",
        "2. Esterilización",
        "3. Desparasitación",
        "4. Corte de pelo",
        "5. Control de salud"
    };

    char descripciones[5][100] = {
        "1. Proceso de administración de vacunas para prevenir enfermedades en la mascota.",
        "2. Intervención quirúrgica para evitar la reproducción",
        "3. Eliminación de parásitos internos y externos que afectan la salud de la mascota.",
        "4. Corte y arreglo del pelaje de la mascota para mantenerlo limpio y saludable.",
        "5. Revisión exhaustiva del estado general de salud de la mascota."
    };

    printf("Servicios disponibles:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", nombres[i]);
        printf("ID: %s\n", IDs[i]);
        printf("Descripción: %s\n", descripciones[i]);
        printf("Precio: $%.2f\n", precios[i]);
        printf("\n");
    }
}

void facturarServicio(float IDMas, char IDs[][9], float precios[]) {
    int servicioElegido;
    float precioTotal = 0;
    char opcion;
    char serviciosFacturados[5][9]; 
    float preciosFacturados[5]; 
    int numServiciosFacturados = 0; 
    char nombres[5][50] = {
        "1. Vacunación",
        "2. Esterilización",
        "3. Desparasitación",
        "4. Corte de pelo",
        "5. Control de salud"
    };



    do {
        printf("Ingrese el número de servicio a facturar: ");
        scanf("%d", &servicioElegido);

        if (servicioElegido < 1 || servicioElegido > 5) {
            printf("Número de servicio inválido. Debe seleccionar un número de servicio válido.\n");
            continue;
        }

        int index = servicioElegido - 1;
        printf("ID del servicio: %s\n", IDs[index]);
        printf("Precio: $%.2f\n", precios[index]);

       
        for (int i = 0; i < 9; i++) {
            serviciosFacturados[numServiciosFacturados][i] = IDs[index][i];
        }
        preciosFacturados[numServiciosFacturados] = precios[index];
        numServiciosFacturados++;

        precioTotal += precios[index];
        

        printf("Desea fa1cturar otro servicio? (S/N): ");
        scanf(" %c", &opcion);
    } while (opcion == 'S' || opcion == 's');

    printf("Factura de servicios:\n");
    printf("ID de la mascota: %.0f\n", IDMas);

    printf("Servicios facturados:\n");
    for (int i = 0; i < numServiciosFacturados; i++) {
        printf("ID: %s\n", serviciosFacturados[i]);
        printf("Nombre del servicio: %s\n",nombres[i] );
        printf("Precio: $%.2f\n", preciosFacturados[i]);
        printf("\n");
    }
    printf("Precio total: $%.2f\n", precioTotal);
}



