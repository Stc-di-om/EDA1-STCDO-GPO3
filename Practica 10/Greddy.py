def greedy_change(amount, coins):
    coins.sort(reverse=True)  # Orden de mayor a menor
    solution = []

    for coin in coins:
        while amount >= coin:
            amount -= coin
            solution.append(coin)

    return solution


if __name__ == "__main__":
    monedas = [50, 20, 10, 5, 1]
    cambio = greedy_change(87, monedas)

    print("Cambio para 87 usando monedas", monedas)
    print("Solución:", cambio)
