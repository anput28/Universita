import numpy as np
import matplotlib.pyplot as plt
import formule_quadratura as fq

#funzione di cui calcolare l'integrale
def f(x):
	y = 2*np.log(x)
	return y

#primitiva di fun
def F(x):
	y = 2*x*np.log(x) - 2*x
	return y

# intervallo di integrazione 
a = 1.5; b = 2

#calcolo l'integrale tramite la primitiva
I = F(b) - F(a)

#calcolo l'integrale con la formula del trapezio
N = 20
TN = fq.formula_composta_trapezio(a, b, N, f)

#calcolo errore
E = abs(I-TN)/abs(I)

#visualizzazione risultati
print("Integrale esatto: %f" % I)
print("Formula del trapezio con N = %d : %f" % (N,TN))
print("Errore commesso: %e" % E)

#rappresentazione grafica
x = np.linspace(a-0.2, b+0.2, 400)
fx = f(x)

plt.figure(1)
plt.title("Calcolo integrale con formula composta del trapezio")
plt.plot(x, fx, "k-", label="f(x)")
#costruzione degli N trapezi
x = np.linspace(a, b, N+1)
for i in range(N):	
	xx = np.array([x[i], x[i], x[i+1], x[i+1], x[i]]) 
	yy = np.array([0, f(x[i]), f(x[i+1]), 0, 0])
	plt.plot(xx, yy, "b-")
plt.legend()
plt.show()

