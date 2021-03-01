from math import ceil, log2
import sys

def bisezioni_successive(fun, a, b, tol):
	fa = fun(a)
	fb = fun(b)
	if fa*fb > 0:
		print("Errore: la presenza della radice non è garantita in [%f, %f]" % (a,b))
		sys.exit(-1)
	else:
		n = ceil(log2(b-a) - log2(tol)) - 1  
		for i in range(n+1):
			c = (a+b)/2
			fc = fun(c)
			if fa*fc <= 0:
				b = c
			else:
				a = c
				fa = fc
	return c

def metodo_tangenti(x0, fun, der, tol, kmax):
	stop = False
	k = 0

	while not(stop) and k < kmax:
		#calcolo gli elmenti da applicare nella formula
		y0 = fun(x0)
		d0 = der(x0)

		#calcolo la nuova approssimazione
		x1 = x0 - (y0/d0)

		#verifico se si è raggiunta l'accuratezza tramite i criteri di arresto
		stop = (abs(fun(x1)) < tol) and (abs(x1-x0)/(1 + abs(x1)) < tol)
		if not(stop):
			x0 = x1
		k +=1

	if not(stop):
		print("Il metodo non converge in %d iterazioni" % kmax)
	return x1, k

def metodo_secanti(x0, x1, fun, tol, kmax):
	stop = False
	k = 0

	while not(stop) and k < kmax:
		#calcolo gli elmenti da applicare nella formula
		y1 = fun(x1)
		s1 = (fun(x1)-fun(x0))/(x1-x0) #rapporto incrementale

		#calcolo la nuova approssimazione
		x2 = x1 - (y1/s1)

		#verifico se si è raggiunta l'accuratezza tramite i criteri di arresto
		stop = abs(fun(x2)) + ( abs(x2-x1)/(1+abs(x2)) ) < tol/5
		if not(stop):
			x0 = x1
			x1 = x2
		k +=1

	if not(stop):
		print("Il metodo non converge in %d iterazioni" % kmax)
	return x2, k

def metodo_corde(x0, fun, m, tol, kmax):
	stop = False
	k = 0 

	while not(stop) and k <= kmax:
		f0 = fun(x0)
		x1 = x0 - (f0/m)

		stop = abs(fun(x1)) + (abs(x1-x0)/(1+abs(x1))) < tol

		x0 = x1
		k = k+1
	return x1, k






















