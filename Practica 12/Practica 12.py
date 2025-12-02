# ---------------------------
# Bottom-Up Fibonacci
# ---------------------------
def fibonacci_bottom_up(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    f_parciales = [0, 1]
    for i in range(2, n + 1):
        f_parciales.append(f_parciales[i - 1] + f_parciales[i - 2])
    return f_parciales[n]


# ---------------------------
# Top-Down Fibonacci (Memoization)
# ---------------------------
def fibonacci_top_down(n, memoria=None):
    if memoria is None:
        memoria = {}

    if n == 0:
        return 0
    if n == 1:
        return 1

    if n in memoria:
        return memoria[n]

    memoria[n] = fibonacci_top_down(n - 1, memoria) + fibonacci_top_down(n - 2, memoria)
    return memoria[n]


# ---------------------------
# QuickSort - Divide & Conquer
# ---------------------------
def quicksort(lista):
    if len(lista) <= 1:
        return lista

    pivote = lista[len(lista) // 2]
    menores = [x for x in lista if x < pivote]
    iguales = [x for x in lista if x == pivote]
    mayores = [x for x in lista if x > pivote]

    return quicksort(menores) + iguales + quicksort(mayores)


# ---------------------------
# Ejemplo de uso
# ---------------------------
if __name__ == "__main__":
    print("Bottom-Up Fibonacci (n=10):", fibonacci_bottom_up(10))
    print("Top-Down Fibonacci (n=10):", fibonacci_top_down(10))

    lista = [6, 3, 8, 1, 5, 9, 2]
    print("QuickSort:", quicksort(lista))
