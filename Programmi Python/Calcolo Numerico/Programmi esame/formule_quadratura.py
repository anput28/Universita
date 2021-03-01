import numpy as np

def formula_trapezio(a, b, fun):
	T = (b-a)/2
	T = T*(fun(a) + fun(b))
	return T

def formula_composta_trapezio(a, b, N, fun):
	#genero N+1 nodi equidistanti
	x = np.linspace(a, b, N+1)
	fx = fun(x)
	
	somma = 0
	for i in range(1, N):
		somma = somma + fx[i]
	TN = (b-a)/(2*N)
	TN = TN*(fx[0] + 2*somma + fx[N])
	return TN

def formula_Simpson(a, b, fun):
	#punto medio dell'intervallo
	c = (a+b)/2
	
	S = (b-a)/6
	S = S * (fun(a) + 4*fun(c) + fun(b))
	return S
	
def formula_composta_Simpson(a, b, N, fun):
	#genero N+1 nodi equidistanti
	x = np.linspace(a, b, N+1)
	fx = fun(x)
	
	somma1 = 0
	for i in range(N):
		c = (x[i] + x[i+1])/2
		somma1 = somma1 + fun(c)
	somma2 = 0
	for i in range(1, N):
		somma2 = somma2 + fx[i]
	S = (b-a)/(6*N)
	S = S * (fx[0] + 4*somma1 + 2*somma2 + fx[N])
	return S

























