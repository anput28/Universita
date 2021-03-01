import numpy as np
import algebra_lineare as al
import time
import matplotlib.pyplot as plt

#dimensione della matrice dei cefficienti
nmax = 500
n_range = range(100, nmax, 10)
tempi_J = np.zeros(len(n_range))
errori_J = np.zeros(len(n_range))

tempi_GS = np.zeros(len(n_range))
errori_GS = np.zeros(len(n_range))
k = 0

for n in n_range:
	#creo la matrice dei coefficienti
	c = -10
	e1 = np.ones(n-1)
	A = np.diag(e1,-1) + c*np.eye(n) + np.diag(e1,1)
	
	#inizializzo il vettore delle soluzioni
	x = np.ones(n)
	#calcolo il vettore dei termini noti
	b = np.dot(A, x)
	
	#parametri per i metodi iterativi
	x0 = np.zeros(n)
	tol = 1.0e-12
	kmax = 500
	
	#calcolo soluzioni del sistema con i metodi iterativi
	inizio = time.time()
	x_pert_J = al.Jacobi(A, b, x0, tol, kmax)
	fine = time.time()
	tempi_J[k] = fine - inizio
	
	inizio = time.time()
	x_pert_GS = al.Gauss_Seidel(A, b, x0, tol, kmax)
	fine = time.time()
	tempi_GS[k] = fine - inizio
	
	#calcolo errori
	errori_J[k] = np.linalg.norm(x-x_pert_J)/ np.linalg.norm(x)
	errori_GS[k] = np.linalg.norm(x-x_pert_GS)/ np.linalg.norm(x)
	k = k + 1

#visualizzazione grafica dei risultati
plt.figure(1)
plt.title("Confronto tempi di esecuzione tra Jacobi e Gauss-Seidel")
plt.plot(n_range, tempi_J, "k-", label="Tempi Jacobi")
plt.plot(n_range, tempi_GS, "b-", label="Tempi Gauss-Seidel")
plt.legend()
plt.show()

plt.figure(2)
plt.title("Confronto errori tra Jacobi e Gauss-Seidel")
plt.semilogy(n_range, errori_J, "k-", label="Errori Jacobi")
plt.plot(n_range, errori_GS, "b-", label="Errori Gauss-Seidel")
plt.legend()
plt.show()





