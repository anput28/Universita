import numpy as np
import algebra_lineare as al

# ================= COSTRUZIONE DEL PROBLEMA TEST =================
n = 15

#genero una matrice n*n con valori random tra -10 e 10
A = (2*np.random.random((n,n)) -1 )*10
A = np.triu(A) #rendo la matrice triangolare superiore

x = np.ones(n) #vettore delle soluzioni
b = np.dot(A, x) #vettore dei termini noti

if al.isSingolare(A):
	print("Errore: La matrice dei coefficienti potrebbe essere singolare.")
else:
	#calcolo la soluzione con l'algoritmo di sostituzione
	x_pert = al.sostituzione_indietro(A, b)

	#calcolo l'errore in output
	err_ass = np.linalg.norm(x-x_pert)
	err_rel = err_ass/np.linalg.norm(x)

	#stampo i risultati
	print("Soluzione attesa x =\n", x)
	print("\nSoluzione calcolata x_pert =\n", x_pert)
	print('\nAlgoritmo sostituzione indietro con matrice %d x %d' %(n,n))
	print("Errore assoluto = %e" % err_ass)
	print("Errore relativo = %e" % err_rel)


"""
# ================= COSTRUZIONE DEL PROBLEMA TEST =================
n = 50

#genero una matrice n*n con valori random tra -10 e 10
A = (2*np.random.random((n,n)) -1 )*10
A = np.tril(A) #rendo la matrice triangolare inferiore

x = np.ones(n) #vettore delle soluzioni
b = np.dot(A, x) #vettore dei termini noti

if al.isSingolare(A):
	print("Errore: La matrice dei coefficienti potrebbe essere singolare.")
else:
	#calcolo la soluzione con l'algoritmo di sostituzione
	x_pert = al.sostituzione_avanti(A, b)

	#calcolo l'errore in output
	err_ass = np.linalg.norm(x-x_pert)
	err_rel = err_ass/np.linalg.norm(x)

	#stampo i risultati
	print("Soluzione attesa x =\n", x)
	print("\nSoluzione calcolata x_pert =\n", x_pert)
	print('\nAlgoritmo sostituzione avanti con matrice %d x %d' %(n,n))
	print("Errore assoluto = %e" % err_ass)
	print("Errore relativo = %e" % err_rel)

"""