import ricerca_radici as rr
import numpy as np
import matplotlib.pyplot as plt

def fun(x):
	y = x**3 - 3*x
	return y

#derivata della funzione fun
def der(x):
	y = 3*x**2 - 3
	return y

#parametri del metodo delle tangenti
tol = 1.0e-14
x0 = 2
kmax = 200

#cerco la radice
radice = rr.metodo_corde(x0, fun, 5, tol, kmax)
f_radice = fun(radice)

#costruisco il grafico delle funzione
#l'intervallo è stato preso in modo da contenere abbondantemente
#l'approssimazione iniziale x0
a = -10; b = 10
x = np.linspace(a, b, 400)
fx = fun(x)

plt.figure(1)
plt.title("Approssimazione trovata x = %f, f(x) = %f" % (radice, f_radice))
zero = np.zeros(len(x))
plt.plot(x, zero, "b:")
plt.plot(x, fx, "k-", label="f(x)")
plt.plot(radice, f_radice, "ro", label = "Approssimazione della radice")
plt.legend()
plt.show()


