import ricerca_radici as rr
import numpy as np
import matplotlib.pyplot as plt

def fun(x):
	y = np.sin(x)
	return y

#intervallo in cui cercare la radice
a = -np.pi/2; b = (5*np.pi)/2
tol = 1.0e-14

#cerco la radice
radice = rr.bisezioni_successive(fun, a, b, tol)
f_radice = fun(radice)

#calcolo la funzione
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

