import itertools
import string
import time

def brute_force(length, password):
    chars = string.ascii_letters + string.digits  # a-zA-Z0-9
    print(f"\n[Brute Force] Buscando contraseña de {length} dígitos...")

    start = time.time()

    # Genera todas las combinaciones posibles
    for combo in itertools.product(chars, repeat=length):
        guess = ''.join(combo)
        if guess == password:
            end = time.time()
            print(f"Contraseña encontrada: {guess}")
            print(f"Tiempo total: {end - start:.4f} segundos\n")
            return guess

    print("Contraseña no encontrada.")
    return None


if __name__ == "__main__":
    # --------- CONTRASEÑA DE 4 DÍGITOS (Ejecutable) ----------
    brute_force(4, "Ab1c")

    # --------- CONTRASEÑA DE 8 DÍGITOS (CUIDADO) --------------
    brute_force(8, "A1b2C3d4")

    # --------- CONTRASEÑA DE 10 DÍGITOS (MUY PESADO) ---------
    brute_force(10, "Ab12Cd34Ef")
