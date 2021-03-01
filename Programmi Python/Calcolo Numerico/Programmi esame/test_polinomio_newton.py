import numpy as np 
import matplotlib.pyplot as plt
import interpolazione.polinomio_newton as pn

def fun(x):
	y = np.exp(np.sin(x))
	return y

#intervallo di interpolazione
a = 0; b = 5

#grado del polinomio di interpolazione
n = 2

#nodi di interplazione
xn = np.linspace(a, b, n+1)
#valori associati ai nodi
yn = fun(xn)

#punti in cui calcolare il polinomio
x = np.linspace(a, b, 400)
#calcolo la funzione nei punti generati
fx = fun(x)

#calcolo il polinomio di interpolazione
pn = pn.Newton(xn, yn, x)

#Visualizzazione grafica del polinomio
plt.figure(1)
plt.title("Polinomio di interpolazione di Newton di grado <= %d" % n)
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

