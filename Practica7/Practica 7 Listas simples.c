#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

// Prototipos
void insertarInicio(Nodo **cabeza, int valor);
void recorrer(Nodo *cabeza);
void eliminar(Nodo **cabeza, int valor);
void liberar(Nodo *cabeza);

// Inserta al inicio de la lista
void insertarInicio(Nodo **cabeza, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = *cabeza;
    *cabeza = nuevo;
    printf("Insertado %d al inicio.\n", valor);
}

// Recorre toda la lista
void recorrer(Nodo *cabeza) {
    Nodo *actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->sig;
    }
    printf("NULL\n");
}

// Eliminar un valor específico
void eliminar(Nodo **cabeza, int valor) {
    if (*cabeza == NULL) return;

    Nodo *temp = *cabeza;

    // Caso 1: el valor está en la cabeza
    if (temp->dato == valor) {
        *cabeza = temp->sig;
        free(temp);
        printf("Eliminado %d (estaba en cabeza)\n", valor);
        return;
    }

    // Caso 2: valor en medio
    Nodo *anterior = NULL;
    while (temp != NULL && temp->dato != valor) {
        anterior = temp;
        temp = temp->sig;
    }

    if (temp == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    anterior->sig = temp->sig;
    free(temp);
    printf("Eliminado %d de la lista.\n", valor);
}

// Liberar memoria
void liberar(Nodo *cabeza) {
    Nodo *actual = cabeza;
    while (actual != NULL) {
        Nodo *temp = actual;
        actual = actual->sig;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    Nodo *cabeza = NULL;
    int n, v;

    // Paso A2: inserción
    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &v);
        insertarInicio(&cabeza, v);
        recorrer(cabeza);
    }

    // Paso A3: eliminación
    printf("Valor a eliminar: ");
    scanf("%d", &v);
    eliminar(&cabeza, v);
    recorrer(cabeza);

    // Paso A4: liberar memoria
    liberar(cabeza);

    return 0;
}
