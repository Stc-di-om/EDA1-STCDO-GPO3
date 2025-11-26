#include <stdio.h>

#define MAX 5

// ---------------------------
// Estructura de la Pila
// ---------------------------
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int dato) {
    if (pilaLlena(p)) {
        printf("Error: La pila está llena.\n");
        return;
    }
    p->datos[++p->tope] = dato;
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: La pila está vacía.\n");
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

// ---------------------------
// Estructura de la Cola
// ---------------------------
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int dato) {
    if (colaLlena(c)) {
        printf("Error: La cola está llena.\n");
        return;
    }
    c->datos[++c->final] = dato;
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: La cola está vacía.\n");
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

// ---------------------------
// Programa principal
// ---------------------------
int main() {
    Pila pila;
    Cola cola;

    int n, dato;

    // ---------------------------
    // Paso 1: Crear pila
    // ---------------------------
    inicializarPila(&pila);

    // Paso 2: Insertar elementos
    printf("\n¿Cuántos elementos quieres apilar? (max 5): ");
    scanf("%d", &n);

    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i+1);
        scanf("%d", &dato);
        push(&pila, dato);
        mostrarPila(&pila);
    }

    // Paso 3: Extraer elementos
    printf("\n¿Cuántos elementos quieres desapilar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int valor = pop(&pila);
        if (valor != -1)
            printf("Elemento desapilado: %d\n", valor);
        mostrarPila(&pila);
    }

    // ---------------------------
    // Paso 4: Crear cola
    // ---------------------------
    printf("\n");
    inicializarCola(&cola);

    // Paso 5: Insertar en la cola
    printf("\n¿Cuántos elementos quieres encolar? (max 5): ");
    scanf("%d", &n);

    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        printf("Ingrese elemento %d: ", i+1);
        scanf("%d", &dato);
        enqueue(&cola, dato);
        mostrarCola(&cola);
    }

    // Paso 6: Extraer de la cola
    printf("\n¿Cuántos elementos quieres desencolar?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int valor = dequeue(&cola);
        if (valor != -1)
            printf("Elemento desencolado: %d\n", valor);
        mostrarCola(&cola);
    }

    return 0;
}
