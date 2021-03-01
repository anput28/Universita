import numpy as np

def Lagrange(xn, yn, x):
	n = len(x)

	pn = np.zeros(n)
	for i in range(n):
		pn[i] = calcolo_polinomio(xn, yn, x[i])
	return pn

def calcolo_polinomio(xn, yn, xi):
	n = len(xn)

	Dj = D(xn, n)
	pol = 0
	for j in range(n):
		Lj = N(xn, xi, j, n)/Dj[j]
		pol = pol + yn[j]*Lj
	return pol

#funzione che calcola la parte degli Lj(x) che varia per ogni x
def N(xn, xi, j, n):
	Nj = 1
	for k in range(n):
		if k != j:
			Nj = Nj * (xi - xn[k])
	return Nj

#funzione che calcola la parte fissa degli Lj(x)
def D(xn, n):
	#costruisco la matrice che memorizza le differenze
	A = np.ones((n,n))
	for j in range(n):
		for k in range(n):
			if k > j:
				A[j, k] = xn[j] - xn[k]
			elif k < j:
				A[j, k] = -A[k, j]
	
	#memorizzo il prodotto degli elementi di ogni riga in in vettore
	Dj = np.ones(n)
	for j in range(n):
		Dj[j] = np.prod(A[j, :])
	return Dj

