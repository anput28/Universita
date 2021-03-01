import numpy as np
import matplotlib.pyplot as plt
import time
import algebra_lineare as al

nmax = 300
n_range = range(2, nmax, 10)

tempo_MI = np.zeros(len(n_range))
errore_MI = np.zeros(len(n_range))

errore_Sos = np.zeros(len(n_range))
tempo_Sos = np.zeros(len(n_range))

k = 0
for n in n_range:
	#creo la matrice dei coefficienti
	c = -8
	e1 = np.ones(n-1)
	A = np.diag(e1,-1) + c*np.eye(n) + np.diag(e1,1)
	
	inizio = time.time()
	U, c = al.eliminazione_Gauss_pivoting_ottim(A, b)
	fine = time.time()
	tempo_ottim[k] = fine - inizio
	
	inizio = time.time()
	U2, c2 = al.eliminazione_Gauss_pivoting(A, b)
	fine = time.time()
	tempo_non_ottim[k] = fine - inizio
	k = k+1

#visualizzione grafica dei risultati
plt.figure(1)
plt.title("Confronto tempo di esecuzione M.E.G. ottimizzato e non")
plt.plot(n_range, tempo_ottim, "k-", label="Tempi M.E.G. ottim.")
plt.plot(n_range, tempo_non_ottim, "b-", label="Tempi M.E.G. non ottim.")
plt.xlabel("dim(A)")
plt.ylabel("Tempo di esecuzione")
plt.legend()
plt.show()
