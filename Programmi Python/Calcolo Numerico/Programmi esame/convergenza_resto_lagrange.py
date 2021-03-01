import numpy as np
import interpolazione.lagrange_baricentrica as lb
import matplotlib.pyplot as plt

#routine che calcola i nodi di Chebyshev
def Chebyshev(a, b, n):
	xn = np.zeros(n)
	for i in range(n):
		cos = np.cos(((2*i + 1)/(2*n + 2))*np.pi)
		xn[i] = a + (cos + 1)*((b-a)/2)
	return xn

def fun(x):
	y = x**2 + np.cos(2*x)
	return y

#intervallo di interpolazione
a = -np.pi; b = np.pi

#punti in cui calcolare il polinomio
x = np.linspace(a, b, 400)
#calcolo la funzione nei punti generati
fx = fun(x)

#massimo grado del polinomio di interpolazione
nmax = range(50)
resto_equi = np.zeros(len(nmax))
resto_cheby = np.zeros(len(nmax))
k = 0
for n in nmax:
	# ================= nodi equidistanti =================
	xn_equi = np.linspace(a, b, n+1)
	#valori associati ai nodi
	yn_equi = fun(xn_equi)
	
	#calcolo il polinomio di Lagrange su nodi equidistanti
	pn_equi = lb.Lagrange_baricentrica(xn_equi, yn_equi, x)
	resto_equi[k] = max(abs(fx - pn_equi))	
	# =====================================================
	
	# ================= nodi di Chebyshev =================
	xn_cheby = Chebyshev(a, b, n+1)
	#valori associati ai nodi
	yn_cheby = fun(xn_cheby)
	
	#calcolo il polinomio di Lagrange su nodi equidistanti
	pn_cheby = lb.Lagrange_baricentrica(xn_cheby, yn_cheby, x)
	resto_cheby[k] = max(abs(fx - pn_cheby))
	# ====================================================
	
	k = k + 1

plt.figure(1)
plt.title("Confronto resto formula di Lagrange")
plt.semilogy(nmax, resto_equi, "k-", label="Resto con nodi equidistanti")
plt.semilogy(nmax, resto_cheby, "b-", label="Resto con nodi di Chebyshev")
plt.xlabel("grado del polinomio")
plt.legend()
plt.show()


