import numpy as np 
import matplotlib.pyplot as plt
import interpolazione.lagrange_baricentrica as lb
import interpolazione.polinomio_lagrange as pl
import time

def fun(x):
	y = np.cos(x**2)
	return y

#intervallo di interpolazione
a = -np.pi; b = np.pi

#punti in cui calcolare il polinomio
x = np.linspace(a, b, 200)

#massimo grado del polinomio di interpolazione
nmax = range(50)
tempo_lagrange = np.zeros(len(nmax))
tempo_baricentrica = np.zeros(len(nmax))
k = 0
for n in nmax:
	#nodi di interplazione
	xn = np.linspace(a, b, n+1)
	#valori associati ai nodi
	yn = fun(xn)
	
	#calcolo il polinomio di Lagrange
	inizio = time.time()
	pn = pl.Lagrange(xn, yn, x)
	fine = time.time()
	tempo_lagrange[k] = fine - inizio
	
	#calcolo il polinomio con formula baricentrica di lagrange
	inizio = time.time()
	pn2 = lb.Lagrange_baricentrica(xn, yn, x)
	fine = time.time()
	tempo_baricentrica[k] = fine - inizio
	
	k = k + 1

#visualizzazione grafica dei risultati
plt.figure(1)
plt.title("Confronto tempi di calcolo tra le formule di Lagrange")
plt.plot(nmax, tempo_lagrange, "k-", label="Tempo formula Lagrange")
plt.plot(nmax, tempo_baricentrica, "b-", label="Tempo formula baricentrica")
plt.xlabel("grado del polinomio")
plt.ylabel("tempo")
plt.legend()
plt.show()


