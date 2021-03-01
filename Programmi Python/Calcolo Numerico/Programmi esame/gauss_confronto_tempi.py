import numpy as np
import matplotlib.pyplot as plt
import time
import algebra_lineare as al

nmax = 300
n_range = range(2, nmax, 10)

tempo_ottim = np.zeros(len(n_range))
tempo_non_ottim = np.zeros(len(n_range))
k = 0
for n in n_range:
	A = (2*np.random.random((n, n)) - 1)*2
	x = np.ones(n)
	b = np.dot(A, x)
	
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


