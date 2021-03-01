import numpy as np

"""
metodo che verifica se una matrice triangolare o 
diagonale è potenzialmente singolare
"""
def isSingolare(A):
	return abs(np.prod(np.diag(A))) <= 1.0e-14

def sostituzione_avanti(A, b):
	A = np.copy(A)
	b = np.copy(b)

	#dimensione della matrice dei coefficienti
	n = len(A)

	#inizializzo il vettore delle soluzioni
	x = np.zeros(n)

	#algoritmo di sostituzione in avanti
	for i in range(n):
		somma = 0
		for j in range(i):
			somma = somma + A[i,j]*x[j]
		x[i] = (b[i] - somma)/A[i,i]
	return x

def sostituzione_indietro(A, b):
	A = np.copy(A)
	b = np.copy(b)

	#dimensione della matrice dei coefficienti
	n = len(A)

	#inizializzo il vettore delle soluzioni
	x = np.zeros(n)

	#algoritmo di sostituzione all'indietro
	for i in range(n-1, -1, -1):
		somma = 0
		for j in range(i+1, n):
			somma = somma + A[i,j]*x[j]
		x[i] = (b[i] - somma)/A[i,i]
	return x

#routine che implementa il M.E.G.
def eliminazione_Gauss(A,b):
	U = np.copy(A)
	c = np.copy(b)

	n = len(U)
	for j in range(n-1):
		for i in range(j+1, n):
			m = U[i,j]/U[j,j]
			U[i,j] = 0
			for k in range(j+1, n):
				U[i,k] = U[i,k] - m*U[j,k]
			c[i] = c[i] - m*c[j]
	return U, c

#routine che implementa il M.E.G.
def eliminazione_Gauss_ottim(A,b):
	U = np.copy(A)
	c = np.copy(b)

	n = len(U)
	for j in range(n-1):
		for i in range(j+1, n):
			m = U[i,j]/U[j,j]
			U[i,j] = 0
			U[i, j+1:n] = U[i, j+1:n] - m*U[j, j+1:n]
			c[i] = c[i] - m*c[j]
	return U, c

def eliminazione_Gauss_pivoting(A,b):
	U = np.copy(A)
	c = np.copy(b)

	n = len(U)
	for j in range(n-1):
		#individuazione elemento pivot
		pivot = abs(U[j,j])
		i_pivot = j
		for i in range(j+1, n):
			if abs(U[i, j]) > pivot:
				pivot = abs(U[i, j])
				i_pivot = i
		
		#eventuale scambio di riga
		if i_pivot > j:
			for k in range(j, n):
				U_temp = U[j, k]
				U[j, k] = U[i_pivot, k]
				U[i_pivot, k] = U_temp
			c_temp = c[j]
			c[j] = c[i_pivot]
			c[i_pivot] = c_temp
		
		#M.E.G.
		for i in range(j+1, n):
			m = U[i,j]/U[j,j]
			U[i,j] = 0
			for k in range(j+1, n):
				U[i,k] = U[i,k] - m*U[j,k]
			c[i] = c[i] - m*c[j]
	return U, c

def eliminazione_Gauss_pivoting_ottim(A,b):
	U = np.copy(A)
	c = np.copy(b)

	n = len(U)
	for j in range(n-1):
		#individuazione elemento pivot
		i_pivot = np.argmax(abs(U[j:n, j])) + j

		#eventuale scambio di riga
		if i_pivot > j:
			U[[i_pivot, j], :] = U[[j, i_pivot], :]
			c[[i_pivot, j]] = c[[j, i_pivot]] 
		
		#M.E.G.
		for i in range(j+1, n):
			m = U[i,j]/U[j,j]
			U[i,j] = 0
			U[i, j+1:n] = U[i, j+1:n]-m*U[j, j+1:n]
			c[i] = c[i] - m*c[j]
	return U, c

#implementa la fattorizzazione A = LU senza pivoting
def fattorizzazione_LU(A):
	A = np.copy(A)
	
	n = len(A)
	for j in range(n-1):
		for i in range(j+1, n):
			A[i, j] = A[i, j]/A[j, j]
			for k in range(j+1, n):
				A[i, k] = A[i, k] - A[i,j]*A[j, k]
	L = np.tril(A, -1) + np.eye(n)
	U = np.triu(A)
	return L, U

def fattorizzazione_LU_ottim(A):
	A = np.copy(A)
	
	n = len(A)
	for j in range(n-1):
		for i in range(j+1, n):
			A[i, j] = A[i, j]/A[j, j]
			A[i, j+1:n] = A[i, j+1:n] - A[i,j]*A[j, j+1:n]
	L = np.tril(A, -1) + np.eye(n)
	U = np.triu(A)
	return L, U

#implementa la fattorizzazione A = LU con pivoting
def fattorizzazione_LU_pivoting(A):
	A = np.copy(A)
	
	n = len(A)
	indice = np.array(range(n))
	for j in range(n-1):
		#individuazione elemento pivot
		pivot = abs(A[j,j])
		i_pivot = j
		for i in range(j+1, n):
			if abs(A[i, j]) > pivot:
				pivot = abs(A[i, j])
				i_pivot = i
		
		#eventuale scambio di riga
		if i_pivot > j:
			for k in range(n):
				A_temp = A[j, k]
				A[j, k] = A[i_pivot, k]
				A[i_pivot, k] = A_temp
			i_temp = indice[j]
			indice[j] = indice[i_pivot]
			indice[i_pivot] = i_temp
		
		#fattorizzazione LU
		for i in range(j+1, n):
			A[i, j] = A[i, j]/A[j, j]
			for k in range(j+1, n):
				A[i, k] = A[i, k] - A[i,j]*A[j, k]
	L = np.tril(A, -1) + np.eye(n)
	U = np.triu(A)
	return L, U, indice

#implementa la fattorizzazione A = LU con pivoting
def fattorizzazione_LU_pivoting_ottim(A):
	A = np.copy(A)
	
	n = len(A)
	indice = np.array(range(n))
	for j in range(n-1):
		#individuazione elemento pivot
		i_pivot = np.argmax(abs(A[j:n, j])) + j
		
		#eventuale scambio di riga
		if i_pivot > j:
			A[[i_pivot, j], :] = A[[j, i_pivot], :]
			indice[[i_pivot, j]] = indice[[j, i_pivot]] 
		
		#fattorizzazione LU
		for i in range(j+1, n):
			A[i, j] = A[i, j]/A[j, j]
			A[i, j+1:n] = A[i, j+1:n] - A[i,j]*A[j, j+1:n]
		
	L = np.tril(A, -1) + np.eye(n)
	U = np.triu(A)
	return L, U, indice

#metodo iterativo di Jacobi per risoluzione di sistemi di equazioni lineari
def Jacobi(A, b, x0, tol, kmax):
	A = np.copy(A)
	b = np.copy(b)
	n = len(A)

	#inzializzo vettore delle soluzioni
	x1 = np.zeros(n)
	#inizializzo vettore dei termini noti
	c = np.ones(n)

	k = 0
	stop = False
	while not(stop) and k <= kmax:
		#risoluzione del sistema Mx = c
		for i in range(n):
			c[i] = b[i]
			for j in range(n):
				if j != i:
					c[i] = c[i] - A[i, j]*x0[j]
			x1[i] = (c[i]/A[i,i])
		
		#applico i criteri di arresto
		r1 = b - np.dot(A, x1)
		arresto_r1 = np.linalg.norm(r1)/np.linalg.norm(b)
		diff_succ = np.linalg.norm(x1-x0)/np.linalg.norm(x1)
		stop = (arresto_r1 < tol) and (diff_succ < tol)

		x0 = np.copy(x1)
		k = k+1

	if not(stop):
		print("Attenzione: accuratezza %e non raggiunta in %d operazioni." % (tol, kmax))
	return x1


#metodo iterativo di Gauss-Seidel per risoluzione di sistemi di equazioni lineari
def Gauss_Seidel(A, b, x0, tol, kmax):
	A = np.copy(A)
	b = np.copy(b)
	n = len(A)

	#inzializzo vettore delle soluzioni
	x1 = np.zeros(n)
	
	k = 0
	stop = False
	while not(stop) and k <= kmax:
		#calcolo il vettore dei termini noti del sistema Mx = c
		for i in range(n):
			somma = 0
			for j in range(i):
				somma = somma + A[i,j]*x1[j]
			for j in range(i+1, n):
				somma = somma + A[i,j]*x0[j]
			x1[i] = (b[i] - somma)/A[i,i]

		#applico i criteri di arresto
		r1 = b - np.dot(A, x1)
		arresto_r1 = np.linalg.norm(r1)/np.linalg.norm(b)
		diff_succ = np.linalg.norm(x1-x0)/np.linalg.norm(x1)
		stop = (arresto_r1 < tol) and (diff_succ < tol)
		
		x0 = np.copy(x1)
		k = k+1

	if not(stop):
		print("Attenzione: accuratezza %e non raggiunta in %d operazioni." % (tol, kmax))
	return x1













