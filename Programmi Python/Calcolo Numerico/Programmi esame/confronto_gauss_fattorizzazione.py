import numpy as np 
import algebra_lineare as al
import time

# dimensione della matrice
n = 100

#creo una matrice con valori random tra -10 e 10
A = (2*np.random.random((n, n)) - 1)*10

#creo la matrice identità
I = np.eye(n)

#inizializzo le matrici inverse
X = np.zeros((n,n)) #sarà calcolata con la fatt. A=LU e gli alg. di sost.
X2 =  np.zeros((n,n)) #sarà calcolata con Gauss e l'alg. di sost. indietro

inizio1 = time.time()
#Fattorizzo la matrice A nelle matrici L e U che userò per risolvere i vari sistemi.
L, U, indice = al.fattorizzazione_LU_pivoting(A)
fine1 = time.time()

if al.isSingolare(L) or al.isSingolare(U):
	print("Errore: la matrice è probabilmente singolare")
else:

	# ============= CALCOLO INVERSA USANDO LE TRASFORMAZIONI L e U =============
	inizio2 = time.time()
	for j in range(n):
		b = I[:, j]
		b = b[indice]
		y = al.sostituzione_avanti(L, b)
		X[:, j] = al.sostituzione_indietro(U, y)
	fine2 = time.time()

	tempo_fatt = (fine1 - inizio1) + (fine2 - inizio2)
	# ==========================================================================

	# ====================== CALCOLO INVERSA USANDO GAUSS ======================
	inizio = time.time()
	for j in range(n):
		U, c = al.eliminazione_Gauss_pivoting_ottim(A, I[:, j])
		X2[:, j] = al.sostituzione_indietro(U, c)
	fine = time.time()

	tempo_gauss = (fine - inizio)
	# ==========================================================================

	#visualizzazione risultati
	print("Test eseguito su una matrice %d x %d" %(n,n))
	print("Tempo impiegato con fatt. e alg. di sost.: %f" %tempo_fatt)
	print("Tempo impiegato con Gauss e alg. di sost. indietro: %f" %tempo_gauss)



