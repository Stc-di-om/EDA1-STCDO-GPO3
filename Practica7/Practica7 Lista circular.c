#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void insertarCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void recorrerCircular(Nodo *cabeza);
void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void liberarCircular(Nodo **cabeza, Nodo **ultimo);

// Inserta al inicio de una lista circular
void insertarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        // Primer nodo → apunta a sí mismo
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->sig = nuevo;
    } else {
        nuevo->sig = *cabeza;
        (*ultimo)->sig = nuevo;
        *cabeza = nuevo;
    }
    printf("Insertado %d en lista circular.\n", valor);
}

void recorrerCircular(Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista circular vacía.\n");
        return;
    }

    Nodo *actual = cabeza;
    printf("Circular: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->sig;
    } while (actual != cabeza);
    printf("(vuelve a cabeza)\n");
}

void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    Nodo *actual = *cabeza;
    Nodo *anterior = *ultimo;

    // Buscar nodo
    do {
        if (actual->dato == valor) break;
        anterior = actual;
        actual = actual->sig;
    } while (actual != *cabeza);

    if (actual->dato != valor) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    // Caso: único nodo
    if (actual == *cabeza && actual == *ultimo) {
        *cabeza = NULL;
        *ultimo = NULL;
    }
    // Caso: eliminar cabeza
    else if (actual == *cabeza) {
        *cabeza = actual->sig;
        (*ultimo)->sig = *cabeza;
    }
    // Caso general o eliminar último
    else {
        anterior->sig = actual->sig;
        if (actual == *ultimo) {
            *ultimo = anterior;
        }
    }

    free(actual);
    printf("Eliminado %d de lista circular.\n", valor);
}

void liberarCircular(Nodo **cabeza, Nodo **ultimo) {
    if (*cabeza == NULL) return;

    Nodo *actual = *cabeza;
    Nodo *sig;

    do {
        sig = actual->sig;
        free(actual);
        actual = sig;
    } while (actual != *cabeza);

    *cabeza = NULL;
    *ultimo = NULL;

    printf("Memoria liberada correctamente.\n");
}

int main() {
    Nodo *cabeza = NULL;
    Nodo *ultimo = NULL;
    int n, v, eliminar;

    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &v);
        insertarCircular(&cabeza, &ultimo, v);
        recorrerCircular(cabeza);
    }

    printf("Valor a eliminar: ");
    scanf("%d", &eliminar);
    eliminarCircular(&cabeza, &ultimo, eliminar);
    recorrerCircular(cabeza);

    liberarCircular(&cabeza, &ultimo);

    return 0;
}
