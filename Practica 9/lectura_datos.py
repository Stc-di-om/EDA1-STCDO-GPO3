print("Hola, ¿cómo te llamas?")
nombre = input()
print("Buen día {}".format(nombre))

while True:
    print("\n---Calculadora---")
    print("1- Sumar")
    print("2- Restar")
    print("3- Multiplicar")
    print("4- Dividir")
    print("5- Salir")

    op = int(input("Opción: "))

    if op == 5:
        print("Hasta luego!")
        break

    a = float(input("Primer número: "))
    b = float(input("Segundo número: "))

    if op == 1:
        print("Resultado:", a + b)
    elif op == 2:
        print("Resultado:", a - b)
    elif op == 3:
        print("Resultado:", a * b)
    elif op == 4:
        if b != 0:
            print("Resultado:", a / b)
        else:
            print("Error: división entre cero.")
    else:
        print("Opción no válida.")
