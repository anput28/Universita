import formule_quadratura as fq
import matplotlib.pyplot as plt
import numpy as np

#funzione da integrare
def f(x):
	y = 2-np.exp(x)
	return y

#primitiva di f
def F(x):
	y = 2*x - np.exp(x)
	return y

#intervallo di integrazione
a = -5; b = -3

#calcolo integrale tramite primitiva
I = F(b) - F(a)

#calcolo l'integrale usando le formule composte del trapezio
# e di Simpson all'aumentare degli intervalli
Nmax = 200
range_Nmax = range(1, Nmax, 2)
errori_T = np.zeros(len(range_Nmax))
errori_S = np.zeros(len(range_Nmax))
k = 0
for N in range_Nmax:
	#calcolo integrali
	TN = fq.formula_composta_trapezio(a, b, N, f)
	SN = fq.formula_composta_Simpson(a, b, N, f)
	
	#calcolo errori
	errori_T[k] = abs(I-TN)/abs(I)
	errori_S[k] = abs(I-SN)/abs(I)
	k = k + 1
	
#grafico degli errori
plt.figure(1)
plt.title("Confronto convergenza Trapezio e Simpson")
plt.semilogy(range_Nmax, errori_T, "k-", label="Err. Trapezio")
plt.semilogy(range_Nmax, errori_S, "b-", label="Err. Simpson")
plt.legend()
plt.show()

