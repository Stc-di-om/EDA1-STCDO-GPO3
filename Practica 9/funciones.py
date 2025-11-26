# Función que regresa dos valores
def operaciones(a, b):
    suma = a + b
    resta = a - b
    return suma, resta

x, y = operaciones(10, 4)
print("Suma:", x)
print("Resta:", y)

# Ignorar un valor con '_'
suma, _ = operaciones(7, 2)
print("Suma ignorando la resta:", suma)
