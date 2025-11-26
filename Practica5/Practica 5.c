#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// ----------------------
//      ESTRUCTURA PILA
// ----------------------
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("\nPila inicializada vacía.\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: la pila está llena.\n");
        return;
    }
    p->datos[++p->tope] = valor;
    printf("Elemento %d insertado en la pila.\n", valor);
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: la pila está vacía.\n");
        return -1;
    }
    return p->datos[p->tope--];
}

void mostrarPila(Pila *p) {
    printf("Estado actual de la pila: ");
    if (pilaVacia(p)) {
        printf("[vacía]\n");
        return;
    }
    for (int i = 0; i <= p->tope; i++)
        printf("%d ", p->datos[i]);
    printf("\n");
}

// ----------------------
//      ESTRUCTURA COLA
// ----------------------
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("\nCola inicializada vacía.\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: la cola está llena.\n");
        return;
    }
    c->datos[++c->final] = valor;
    printf("Elemento %d insertado en la cola.\n", valor);
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: la cola está vacía.\n");
        return -1;
    }
    return c->datos[c->frente++];
}

void mostrarCola(Cola *c) {
    printf("Estado actual de la cola: ");
    if (colaVacia(c)) {
        printf("[vacía]\n");
        return;
    }
    for (int i = c->frente; i <= c->final; i++)
        printf("%d ", c->datos[i]);
    printf("\n");
}

// --------------------------------------
//      PROGRAMA PRINCIPAL
// --------------------------------------
int main() {
    Pila pila;
    Cola cola;

    inicializarPila(&pila);
    inicializarCola(&cola);

    int n, valor;

    // --------------------------
    //      INSERTAR EN PILA
    // --------------------------
    printf("\n¿Cuántos elementos quieres apilar? (máximo 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n && i < MAX; i++) {
        printf("Ingresa el elemento %d: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }

    // --------------------------
    //      SACAR DE PILA
    // --------------------------
    printf("\n¿Cuántos elementos quieres desapilar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int salido = pop(&pila);
        if (salido != -1)
            printf("Salió de la pila: %d\n", salido);
        mostrarPila(&pila);
    }

    // --------------------------
    //      INSERTAR EN COLA
    // --------------------------
    printf("\n¿Cuántos elementos quieres encolar? (máximo 5): ");
    scanf("%d", &n);

    for (int i = 0; i < n && i < MAX; i++) {
        printf("Ingresa el elemento %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }

    // --------------------------
    //      SACAR DE COLA
    // --------------------------
    printf("\n¿Cuántos elementos quieres desencolar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int salido = dequeue(&cola);
        if (salido != -1)
            printf("Salió de la cola: %d\n", salido);
        mostrarCola(&cola);
    }

    // --------------------------
    //      COMPARACIÓN
    // --------------------------
    printf("\n--------------------------------------\n");
    printf("   Comparación entre Pila y Cola\n");
    printf("--------------------------------------\n");
    printf("Pila → LIFO (último en entrar, primero en salir)\n");
    printf("Cola → FIFO (primero en entrar, primero en salir)\n");

    return 0;
}

