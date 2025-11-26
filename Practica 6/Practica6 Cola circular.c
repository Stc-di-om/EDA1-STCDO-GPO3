#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

// ------------------ Funciones -------------------

void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("ERROR: Cola llena, no se puede encolar %d\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("ERROR: Cola vacía, no se puede desencolar\n");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("ERROR: Cola vacía\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Cola = [ ");
    for (int i = 0; i < c->size; i++) {
        int index = (c->frente + i) % MAX;
        printf("%d ", c->datos[index]);
    }
    printf("]  frente=%d final=%d size=%d\n", c->frente, c->final, c->size);
}

// ------------------ Pruebas -------------------

int main() {
    ColaCircular c;
    inicializar(&c);

    printf("\n--- Encolar 5, 10, 15 ---\n");
    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);

    printf("\n--- Desencolar uno ---\n");
    dequeue(&c);
    printQueue(&c);

    printf("\n--- Encolar 20, 25, 30 ---\n");
    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30);  // Este debería reciclar espacio
    printQueue(&c);

    return 0;
}
