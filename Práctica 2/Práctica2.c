#include <stdio.h>

int main(void) {
    // Declaramos un arreglo de 5 enteros
    int a[5] = {2, 4, 6, 8, 10};

    // Declaramos un apuntador y lo hacemos apuntar al primer elemento del arreglo
    int *p = a; // p = &a[0]

    // Acceso directo al arreglo con índice
    printf("1) a[1] = %d\n", a[1]); // a[1] = 4

    // Acceso usando aritmética de punteros: *(a+3) equivale a a[3]
    printf("2) *(a+3) = %d\n", *(a+3)); // *(a+3) = 8

    // Post-incremento: primero usa *p (a[0]) y luego incrementa p
    printf("3) *p++ = %d\n", *p++); // Imprime 2 y p ahora apunta a a[1]

    // Pre-incremento: primero incrementa p, luego lo desreferencia
    printf("4) *++p = %d\n", *++p); // p pasa de a[1] a a[2], imprime 6

    // p[1] equivale a *(p+1). Como p = a[2], p[1] = a[3] = 8
    printf("5) p[1] = %d\n", p[1]); 

    // p+=2 mueve el puntero dos posiciones hacia adelante
    // p estaba en a[2], ahora apunta a a[4], y *p = 10
    printf("6) *(p+=2) = %d\n", *(p+=2));

    // Diferencia entre punteros: p - a = número de posiciones de distancia
    // p = a[4], a = a[0], entonces p - a = 4
    printf("7) p - a = %ld\n", p - a);

    return 0;
}
