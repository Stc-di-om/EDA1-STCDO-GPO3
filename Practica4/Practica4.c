#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr, *arr2;

    // -------------------------------
    // Paso 1: Reservar memoria con malloc
    // -------------------------------
    printf("¿Cuántos enteros deseas almacenar con malloc? ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: no se pudo reservar memoria con malloc.\n");
        return 1;
    }

    printf("\nValores iniciales (malloc):\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // valores basura
    }

    // -------------------------------
    // Paso 2: Reservar memoria con calloc
    // -------------------------------
    printf("\n¿Cuántos enteros deseas almacenar con calloc? ");
    scanf("%d", &n);

    arr2 = (int*) calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Error: no se pudo reservar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales (calloc):\n");
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);  // deben ser 0
    }

    // -------------------------------
    // Paso 3: Llenar el arreglo arr2
    // -------------------------------
    printf("\nIngresa %d valores para llenar arr2:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    // -------------------------------
    // Paso 4: Redimensionar con realloc
    // -------------------------------
    printf("\nNuevo tamaño del arreglo: ");
    scanf("%d", &m);

    int *temp = realloc(arr2, m * sizeof(int));

    if (temp == NULL) {
        printf("Error: no se pudo redimensionar la memoria con realloc.\n");
        free(arr);
        free(arr2);  // arr2 aún es válido porque realloc falló
        return 1;
    }

    arr2 = temp;  // ahora sí actualizamos el puntero

    // Si el arreglo creció, pedir los nuevos valores
    if (m > n) {
        printf("\nIngresa los %d valores adicionales:\n", m - n);
        for (int i = n; i < m; i++) {
            printf("arr2[%d] = ", i);
            scanf("%d", &arr2[i]);
        }
    }

    // Imprimir los valores finales
    printf("\nValores finales en arr2:\n");
    for (int i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // -------------------------------
    // Paso 5: Liberar memoria
    // -------------------------------
    free(arr);
    free(arr2);

    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
