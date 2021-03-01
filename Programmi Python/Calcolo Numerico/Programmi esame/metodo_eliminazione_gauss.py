import numpy as np
import algebra_lineare as al
import matplotlib.pyplot as plt

#costruzione del problema test
nmax = 300
n_range = range(2, nmax, 10)
err_con_pivot = np.zeros(len(n_range))
err_senza_pivot = np.zeros(len(n_range))
k = 0
for n in n_range:
	#genero una matrice n*n con valori random tra -2 e 2
	A = (2*np.random.random((n,n)) - 1)*2
	
	x = np.ones(n) #vettore delle soluzioni attese
	b = np.dot(A, x) #vettore dei termini noti
	
	#applicazione M.E.G. con e senza pivoting
	U,c = al.eliminazione_Gauss(A,b)
	U2, c2 = al.eliminazione_Gauss_pivoting(A, b)
	
	"""
	Lo scopo del programma è confrontare gli errori delle due versioni
	del M.E.G. quindi se una tra le matrici U e U2 è potenzialmente
	singolare non risolvo nessuno dei due sistemi
	"""
	if al.isSingolare(U) or al.isSingolare(U2):
		print("Errore: la matrice dei coefficienti potrebbe essere singolare.")
	else:	
		#risolvo i sistemi
		x_pert = al.sostituzione_indietro(U, c)
		x_pert2 = al.sostituzione_indietro(U2, c2)
		
		#calcolo errori
		err_senza_pivot[k] = np.linalg.norm(x-x_pert)/np.linalg.norm(x)
		err_con_pivot[k] = np.linalg.norm(x-x_pert2)/np.linalg.norm(x)
		k = k+1

#visualizzazione grafica dei risultati
plt.figure(1)
plt.title("Confronto stabilità M.E.G. con e senza pivoting")
plt.semilogy(n_range, err_senza_pivot, "k-", label="Err. rel. M.E.G. senza pivot")
plt.semilogy(n_range, err_con_pivot, "b-", label="Err. rel. M.E.G. con pivot")
plt.xlabel("dim(A)")
plt.legend()
plt.show()
