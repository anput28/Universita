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
T = fq.formula_trapezio(a, b, f)

#calcolo errore
E = abs(I-T)/abs(I)

#visualizzazione risultati
print("Integrale esatto: %f" % I)
print("Formula del trapezio : %f" % T)
print("Errore commesso: %e" % E)

#rappresentazione grafica
x = np.linspace(a-0.2, b+0.2, 400)
fx = f(x)

plt.figure(1)
plt.title("Calcolo integrale con formula del trapezio composta")
plt.plot(x, fx, "k-", label="f(x)")
#costruzione del trapezio	
xx = np.array([a, a, b, b, a]) 
yy = np.array([0, f(a), f(b), 0, 0])
plt.plot(xx, yy, "b-")
plt.legend()
plt.show()

