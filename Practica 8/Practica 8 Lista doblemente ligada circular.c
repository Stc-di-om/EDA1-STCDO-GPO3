#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void insertarCircular(Nodo **inicio, int valor);
void recorrerCircular(Nodo *inicio);
void eliminarCircular(Nodo **inicio, int valor);

int main() {
    Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar en la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&inicio, valor);
    }

    printf("\nRecorrido circular:\n");
    recorrerCircular(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &eliminarValor);

    eliminarCircular(&inicio, eliminarValor);

    printf("\nLista después de eliminar:\n");
    recorrerCircular(inicio);

    return 0;
}

void insertarCircular(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        return;
    }

    Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(Nodo *inicio) {
    if (inicio == NULL) return;

    Nodo *temp = inicio;
    do {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("\n");
}

void eliminarCircular(Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    Nodo *temp = *inicio;

    do {
        if (temp->dato == valor) break;
        temp = temp->siguiente;
    } while (temp != *inicio);

    if (temp->dato != valor) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (temp->siguiente == temp) {
        free(temp);
        *inicio = NULL;
        return;
    }

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    if (temp == *inicio)
        *inicio = temp->siguiente;

    free(temp);
}
