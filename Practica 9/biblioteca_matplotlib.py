import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [i*i for i in x]

plt.plot(x, y)
plt.title("Gráfica de x^2")
plt.xlabel("x")
plt.ylabel("y")
plt.show()
