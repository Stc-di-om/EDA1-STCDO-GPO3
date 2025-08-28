#include <stdio.h>

int main(void) {
    int n;
    const int MAX = 100;  
    int a[MAX];

    // Validar cantidad de elementos
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

    // Mostrar elementos originales
    printf("\nVector original:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Invertir vector SIN arreglo auxiliar
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    // Mostrar vector invertido
    printf("\nVector invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
