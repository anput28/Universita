import numpy as np

def Lagrange_baricentrica(xn, yn, x):
	n = len(x)
	zn = coefficienti(xn, yn)
	
	pn = np.zeros(n)
	for i in range(n):
		pn[i] = calcolo_polinomio(xn, zn, yn, x[i])
	return pn

def coefficienti(xn, yn):
	n = len(xn)
	#inizializzo la matrice delle differenze
	X = np.ones((n,n))
	for j in range(n):
		for k in range(n):
			if k > j:
				X[j, k] = xn[j] - xn[k]
			elif k < j:
				X[j, k] = -X[k, j]
	
	zn = np.zeros(n)
	for j in range(n):
		zn[j] = yn[j]/np.prod(X[j, :])
	return zn
 
#funzione che calcola il polinomio se xi non è uno dei nodi di interpolazione
#se invece restituisce il valore associato al nodo
def calcolo_polinomio(xn, zn, yn, xi):
	check_nodi = abs(xi-xn) < 1.0e-14
	if True in check_nodi:
		#estraggo tutti gli indici degli elementi che in check_nodi sono uguali a True
		indice = np.flatnonzero(check_nodi == True)
		p = yn[indice[0]]
	else:
		n = len(xn)
		somma = 0
		for j in range(n):
			somma = somma + (zn[j]/(xi - xn[j]))
		p = np.prod(xi-xn)*somma
	return p

