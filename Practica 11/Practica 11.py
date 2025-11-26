# fibonacci.py

memo = {}

def fibonacci(n):
    """Función recursiva de Fibonacci con memoización."""
    if n in memo:
        return memo[n]
    if n <= 1:
        memo[n] = n
        return n
    memo[n] = fibonacci(n-1) + fibonacci(n-2)
    return memo[n]

# Posiciones requeridas
posiciones = [7, 21, 40, 71, 94]

print("Resultados de Fibonacci en posiciones solicitadas:")
for p in posiciones:
    print(f"F({p}) = {fibonacci(p)}")
