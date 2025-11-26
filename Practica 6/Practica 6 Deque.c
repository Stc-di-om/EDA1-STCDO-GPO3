#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

// rear se calcula como: (front + size - 1) % MAX

// ----------------- Funciones ------------------

void inicializarDeque(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

int isEmptyDeque(Deque *d) {
    return d->size == 0;
}

int isFullDeque(Deque *d) {
    return d->size == MAX;
}

int getRear(Deque *d) {
    if (d->size == 0) return -1;
    return (d->front + d->size - 1) % MAX;
}

void insert_front(Deque *d, int val) {
    if (isFullDeque(d)) {
        printf("ERROR: Deque lleno\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = val;
    d->size++;
}

void insert_rear(Deque *d, int val) {
    if (isFullDeque(d)) {
        printf("ERROR: Deque lleno\n");
        return;
    }
    int rear = getRear(d);
    int newRear = (rear + 1) % MAX;
    d->datos[newRear] = val;
    d->size++;
}

int delete_front(Deque *d) {
    if (isEmptyDeque(d)) {
        printf("ERROR: Deque vacío\n");
        return -1;
    }
    int val = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return val;
}

int delete_rear(Deque *d) {
    if (isEmptyDeque(d)) {
        printf("ERROR: Deque vacío\n");
        return -1;
    }
    int rear = getRear(d);
    int val = d->datos[rear];
    d->size--;
    return val;
}

int peek_front(Deque *d) {
    if (isEmptyDeque(d)) return -1;
    return d->datos[d->front];
}

int peek_rear(Deque *d) {
    if (isEmptyDeque(d)) return -1;
    return d->datos[getRear(d)];
}

void printDeque(Deque *d) {
    printf("Deque = [ ");
    for (int i = 0; i < d->size; i++) {
        int index = (d->front + i) % MAX;
        printf("%d ", d->datos[index]);
    }
    printf("]  front=%d rear=%d size=%d\n", d->front, getRear(d), d->size);
}

// ---------------- Pruebas -------------------

int main() {
    Deque d;
    inicializarDeque(&d);

    printf("\n--- insert_front(10) ---\n");
    insert_front(&d, 10);
    printDeque(&d);

    printf("\n--- insert_rear(15), insert_rear(20) ---\n");
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    printDeque(&d);

    printf("\n--- insert_front(30) ---\n");
    insert_front(&d, 30);
    printDeque(&d);

    printf("\n--- insert_rear(40) ---\n");
    insert_rear(&d, 40);
    printDeque(&d);

    printf("\n--- delete_front() y delete_rear() ---\n");
    delete_front(&d);
    delete_rear(&d);
    printDeque(&d);

    return 0;
}
