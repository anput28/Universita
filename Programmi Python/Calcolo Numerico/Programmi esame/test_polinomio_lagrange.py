import numpy as np 
import matplotlib.pyplot as plt
import interpolazione.polinomio_lagrange as pl

def fun(x):
	y = np.cos(x**2)
	return y

#intervallo di interpolazione
a = -np.pi; b = np.pi

#grado del polinomio di interpolazione
n = 7

#nodi di interplazione
xn = np.linspace(a, b, n+1)
#valori associati ai nodi
yn = fun(xn)

#punti in cui calcolare il polinomio
x = np.linspace(a, b, 200)
#calcolo la funzione nei punti generati
fx = fun(x)

#calcolo il polinomio di interpolazione
pn = pl.Lagrange(xn, yn, x)

#Visualizzazione grafica del polinomio
plt.figure(1)
plt.title("Polinomio di interpolazione di Lagrange di grado <= %d" % n)
plt.plot(x, fx, "k-", label="f(x)")
plt.plot(x, pn, "b-", label="Pn(x)")
plt.plot(xn, yn, "ro", label="nodi di interp.")
plt.legend()
plt.show()

#Visualizzazione grafica del resto del polinomio
plt.figure(2)
plt.title("Resto del polinomio")
plt.semilogy(x, abs(fx-pn), "k-", label="|f(x) - Pn(x)|")
plt.legend()
plt.show() 
