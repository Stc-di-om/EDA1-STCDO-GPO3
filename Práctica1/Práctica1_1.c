#include <stdio.h>

int main(void) {
    int n;
    const int MAX = 100;  // tamaño máximo permitido
    int a[MAX];

    // Validar que n esté en el rango permitido
    do {
        printf("Ingresa una cantidad (1 - %d): ", MAX);
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("⚠️  Error: la cantidad debe estar entre 1 y %d.\n", MAX);
        }
    } while (n <= 0 || n > MAX);

    // Ingreso de los elementos
    printf("\nIngrese %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    // Mostrar los elementos ingresados
    printf("\nLos elementos del array son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
