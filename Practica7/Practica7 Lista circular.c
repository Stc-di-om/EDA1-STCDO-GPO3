#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

void insertarCircular(Nodo **cabeza, Nodo **ultimo, int valor);
void recorrerCircular(Nodo *cabeza);
void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor);

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
    if (cabeza == NULL) return;

    Nodo *actual = cabeza;
    printf("Circular: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->sig;
    } while (actual != cabeza);
    printf("(vuelve a cabeza)\n");
}

void eliminarCircular(Nodo **cabeza, Nodo **ultimo, int valor) {
    if (*cabeza == NULL) return;

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
    // Caso general
    else {
        anterior->sig = actual->sig;
        if (actual == *ultimo) {
            *ultimo = anterior;
        }
    }

    free(actual);
    printf("Eliminado %d de lista circular.\n", valor);
}
