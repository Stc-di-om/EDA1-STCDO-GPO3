#include <stdio.h>
#include <string.h>

#define TAM 3       // número de películas en la videoteca
#define NUM_DIR 3   // número máximo de directores por película

struct pelicula {
    char nombre[30];
    char genero[20];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][30];
};

int main(void) {
    struct pelicula videoteca[TAM];

 
    for (int i = 0; i < TAM; i++) {
        printf("\n--- Captura de Pelicula %d ---\n", i + 1);

        printf("Nombre: ");
        scanf(" %[^\n]", videoteca[i].nombre);

        printf("Genero: ");
        scanf(" %[^\n]", videoteca[i].genero);

        printf("Anio: ");
        scanf("%d", &videoteca[i].anio);

        printf("Numero de directores: ");
        scanf("%d", &videoteca[i].numDirectores);

        // Validación simple
        if (videoteca[i].numDirectores <= 0) {
            printf("Numero de directores invalido. Se asigna 1.\n");
            videoteca[i].numDirectores = 1;
        }

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director %d: ", j + 1);
            scanf(" %[^\n]", videoteca[i].directores[j]);
        }
    }

   
    printf("\n####### Videoteca (orden inverso) #######\n");
    for (int i = TAM - 1; i >= 0; i--) {
        printf("\nPelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
    }

   
    char buscador[30];
    int anioBuscado;

    
    printf("\n>>> Buscar por nombre: ");
    scanf(" %[^\n]", buscador);
    for (int i = 0; i < TAM; i++) {
        if (strcmp(videoteca[i].nombre, buscador) == 0) {
            printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
        }
    }

    
    printf("\n>>> Buscar por director: ");
    scanf(" %[^\n]", buscador);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            if (strcmp(videoteca[i].directores[j], buscador) == 0) {
                printf("Pelicula de %s: %s (%d)\n",
                       buscador, videoteca[i].nombre, videoteca[i].anio);
            }
        }
    }

    printf("\n>>> Buscar por anio: ");
    scanf("%d", &anioBuscado);
    for (int i = 0; i < TAM; i++) {
        if (videoteca[i].anio == anioBuscado) {
            printf("En %d: %s\n", anioBuscado, videoteca[i].nombre);
        }
    }

    char generoBuscado[20];
    int contador = 0;
    printf("\n>>> Contar peliculas por genero: ");
    scanf(" %[^\n]", generoBuscado);
    for (int i = 0; i < TAM; i++) {
        if (strcmp(videoteca[i].genero, generoBuscado) == 0) {
            contador++;
        }
    }
    printf("Hay %d pelicula(s) del genero %s.\n", contador, generoBuscado);

    
    if (TAM <= 0) {
        printf("ERROR: Videoteca vacia o invalida.\n");
    }

    return 0;
}
