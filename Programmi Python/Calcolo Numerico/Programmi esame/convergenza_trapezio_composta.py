import numpy as np
import matplotlib.pyplot as plt
import formule_quadratura as fq

#funzione di cui calcolare l'integrale
def f(x):
	y = 2*np.log(x)
	return y

#primitiva di fun
def F(x):
	y = 2*x*np.log(x) - 2*x
	return y

# intervallo di integrazione 
a = 1.5; b = 2

#calcolo l'integrale tramite la primitiva
I = F(b) - F(a)

#calcolo l'integrale al variare del numero di intervalli
Nmax = 100
range_Nmax = range(1, Nmax, 2)
errori = np.zeros(len(range_Nmax))
k = 0
for N in range_Nmax:
	TN = fq.formula_composta_trapezio(a, b, N, f)

	#calcolo errore
	errori[k] = abs(I-TN)/abs(I)
	k = k+1

#grafico degli errori
plt.figure(1)
plt.title("Errori formula composta del trapezio")
plt.semilogy(range_Nmax, errori, "k-", label="Err. Trap. Comp.")
plt.xlabel("N")
plt.legend()
plt.show()




