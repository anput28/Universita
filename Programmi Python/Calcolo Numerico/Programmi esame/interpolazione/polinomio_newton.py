import numpy as np

def Newton(xn, yn, x):
	dn = differenze_divise(xn, yn)

	n = len(x)
	pn = np.zeros(n)
	for i in range(n):
		pn[i] = calcolo_polinomio(dn, xn, x[i])
	return pn

#calcolo il polinomio nel punto xi
def calcolo_polinomio(dn, xn, xi):
	n = len(xn)

	p = dn[n-1]
	for j in range(n-2, -1, -1):
		p = dn[j] + p*(xi - xn[j])
	return p

#calcolo differenze divise con la tecnica del vettore
def differenze_divise(xn, yn):
	n = len(xn)
	dn = np.copy(yn)
	for j in range(1, n):
		for i in range(n-1, j-1, -1):
			dn[i] = (dn[i] - dn[i-1])/(xn[i] - xn[i-j])
	return dn

