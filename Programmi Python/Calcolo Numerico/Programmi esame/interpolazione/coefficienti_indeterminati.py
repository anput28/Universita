import numpy as np
import algebra_lineare as al

def Vandermonde(xn):
	n = len(xn)
	Vm = np.zeros((n, n))
	for i in range(n):
		for j in range(n):
			Vm[i,j] = xn[i]**j
	return Vm

def coefficienti_indeterminati(xn, yn):
	Vm = Vandermonde(xn)
	U, c = al. eliminazione_Gauss_pivoting_ottim(Vm, yn)
	coeff = al.sostituzione_indietro(U, c)
	return coeff

