#include <stdio.h>

int main(void) {
    int n;
    const int MAX = 100;  // tamaño máximo permitido
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

    // Mostrar elementos ingresados
    printf("\nLos elementos del array son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Cálculos
    int suma = 0;
    int resta = a[0];  // empezamos con el primer elemento
    int min = a[0], max = a[0];
    int pos_min = 0, pos_max = 0;

    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (i > 0) resta -= a[i];

        if (a[i] < min) {
            min = a[i];
            pos_min = i;
        }
        if (a[i] > max) {
            max = a[i];
            pos_max = i;
        }
    }

    float promedio = (float)suma / n;

    // Resultados
    printf("\nResultados:\n");
    printf("Suma = %d\n", suma);
    printf("Resta = %d\n", resta);
    printf("Promedio = %.2f\n", promedio);
    printf("Minimo = %d (posicion %d)\n", min, pos_min);
    printf("Maximo = %d (posicion %d)\n", max, pos_max);

    return 0;
}
