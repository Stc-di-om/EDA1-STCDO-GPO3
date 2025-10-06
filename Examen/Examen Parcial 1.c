#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 0;           // Número inicial de estudiantes
    int agregar = 0;     // Cantidad adicional de estudiantes
    float *notas = NULL; // Puntero al arreglo dinámico
    float suma = 0.0f;
    float promedio = 0.0f;

    printf("¿Cuántos estudiantes deseas registrar? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Entrada inválida. Debes introducir un número entero mayor que 0.\n");
        return 1;
    }

    notas = malloc(n * sizeof(float));
    if (notas == NULL) {
        fprintf(stderr, "Error: malloc() devolvió NULL.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Calificación del estudiante %d: ", i + 1);
        if (scanf("%f", &notas[i]) != 1) {
            fprintf(stderr, "Entrada inválida al leer la calificación.\n");
            free(notas);
            return 1;
        }
    }

    suma = 0.0f;
    for (int i = 0; i < n; ++i) suma += notas[i];
    promedio = (n > 0) ? (suma / n) : 0.0f;
    printf("\nPromedio inicial: %.2f\n\n", promedio);

    printf("¿Deseas agregar más estudiantes? (Ingresa la cantidad o 0 para no agregar más): ");
    if (scanf("%d", &agregar) != 1) {
        fprintf(stderr, "Entrada inválida.\n");
        free(notas);
        return 1;
    }

    if (agregar > 0) {
        float *tmp = realloc(notas, (n + agregar) * sizeof(float));
        if (tmp == NULL) {
            fprintf(stderr, "Error: realloc() devolvió NULL. No se amplió el arreglo.\n");
            free(notas);
            return 1;
        }
        notas = tmp;

        for (int i = n; i < n + agregar; ++i) {
            printf("Calificación del estudiante %d: ", i + 1);
            if (scanf("%f", &notas[i]) != 1) {
                fprintf(stderr, "Entrada inválida al leer calificación nueva.\n");
                free(notas);
                return 1;
            }
        }

        n += agregar;
        suma = 0.0f;
        for (int i = 0; i < n; ++i) suma += notas[i];
        promedio = (n > 0) ? (suma / n) : 0.0f;
    }

    printf("\n=== Calificaciones registradas ===\n");
    for (int i = 0; i < n; ++i) {
        printf("Estudiante %d: %.2f\n", i + 1, notas[i]);
    }
    printf("Promedio general: %.2f\n", promedio);

    free(notas);
    notas = NULL;
    printf("\nMemoria liberada correctamente. Programa finalizado.\n");

    return 0;
}
