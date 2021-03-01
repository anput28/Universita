import numpy as np
import algebra_lineare as al
import matplotlib.pyplot as plt

#costruzione del problema test
nmax = 200
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
	L, U = al.fattorizzazione_LU(A)
	L2, U2, indice = al.fattorizzazione_LU_pivoting(A)

	if al.isSingolare(U) or al.isSingolare(U2):
		print("Errore: la matrice dei coefficienti potrebbe essere singolare.")
	else:	
		#risolvo il primo sistema
		y = al.sostituzione_avanti(L, b)
		x_pert = al.sostituzione_indietro(U, y)
		
		#risolvo il secondo sistema
		b = b[indice]
		y2 = al.sostituzione_avanti(L2, b)
		x_pert2 = al.sostituzione_indietro(U2, y2)
		
		#calcolo errori
		err_senza_pivot[k] = np.linalg.norm(x-x_pert)/np.linalg.norm(x)
		err_con_pivot[k] = np.linalg.norm(x-x_pert2)/np.linalg.norm(x)
		k = k+1

#visualizzazione grafica dei risultati
plt.figure(1)
plt.title("Confronto stabilità fatt. A=LU con e senza pivoting")
plt.semilogy(n_range, err_senza_pivot, "k-", label="Err. rel. fatt.A=LU senza pivot")
plt.semilogy(n_range, err_con_pivot, "b-", label="Err. rel. fatt.A=LU con pivot")
plt.xlabel("dim(A)")
plt.legend()
plt.show()

			
