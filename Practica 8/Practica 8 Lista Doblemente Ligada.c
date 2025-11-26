#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

void insertarInicio(Nodo **inicio, int valor);
void insertarFinal(Nodo **inicio, int valor);
void recorrerAdelante(Nodo *inicio);
void recorrerAtras(Nodo *inicio);
void eliminar(Nodo **inicio, int valor);
void liberar(Nodo *inicio);

int main() {
    Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    // --- Inserción al inicio ---
    printf("¿Cuántos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

    printf("\nRecorrido adelante:\n");
    recorrerAdelante(inicio);

    printf("Recorrido atrás:\n");
    recorrerAtras(inicio);

    // --- Inserción al final ---
    printf("\n¿Cuántos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    printf("\nLista después de insertar al final:\n");
    recorrerAdelante(inicio);

    // --- Eliminación ---
    printf("\nValor a eliminar: ");
    scanf("%d", &eliminarValor);
    eliminar(&inicio, eliminarValor);

    printf("\nLista después de eliminar:\n");
    recorrerAdelante(inicio);

    // --- Liberación ---
    liberar(inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

void insertarInicio(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL)
        (*inicio)->anterior = nuevo;

    *inicio = nuevo;
}

void insertarFinal(Nodo **inicio, int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }

    Nodo *temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(Nodo *inicio) {
    Nodo *temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->dato);
        if (temp->siguiente == NULL) break;
        temp = temp->siguiente;
    }
    printf("\n");
}

void recorrerAtras(Nodo *inicio) {
    if (inicio == NULL) return;

    Nodo *temp = inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

void eliminar(Nodo **inicio, int valor) {
    Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor)
        temp = temp->siguiente;

    if (temp == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (temp->anterior != NULL)
        temp->anterior->siguiente = temp->siguiente;
    else
        *inicio = temp->siguiente;

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
}

void liberar(Nodo *inicio) {
    Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
}
