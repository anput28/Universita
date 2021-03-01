import numpy as np
import formule_quadratura as fq
import matplotlib.pyplot as plt

#funzione da integrare
def f(x):
	y = 3*np.log(x)
	return y

#primitiva di f
def F(x):
	y = 3*(x*np.log(x) - x)
	return y

#intervallo di integrazione
a = 1; b = 2

#calcolo l'integrale tramite la primitiva
I = F(b) - F(a)

#calcolo integrale tramite la formula del trapezio
T = fq.formula_trapezio(a, b, f)

#calcolo integrale tramite la formula di Simpson
S = fq.formula_Simpson(a, b, f)

#calcolo errori
Err_T = abs(I-T)/abs(I)
Err_S = abs(I-S)/abs(I)

#visualizzazione risultati
print("Confronto tra formula del trapezio e di Simpson:")
print("Integrale esatto: %f" % I)
print("Formula del trapezio:")
print("\t - Approssimazione : %f" % T)
print("\t - Errore : %e" % Err_T)
print("Formula di Simpson:")
print("\t - Approssimazione : %f" % S)
print("\t - Errore : %e" % Err_S)

#rappresentazione grafica
x = np.linspace(a-0.2, b+0.2, 400)
fx = f(x)

plt.figure(1)
plt.title("Confronto calcolo integrale con Trapezio e Simpson")
plt.plot(x, fx, "k-", label="f(x)")
#costruzione del trapezio	
xx_T = np.array([a, a, b, b, a]) 
yy_T = np.array([0, f(a), f(b), 0, 0])

#costruzione approssimazione di Simpson
c = (a+b)/2
xx_S = np.array([a, a, c, b, b, c, a]) 
yy_S = np.array([0, f(a), f(c), f(b), 0, 0, 0])
plt.plot(xx_T, yy_T, "r-", label="Trapezio")
plt.plot(xx_S, yy_S, "b:", label="Simpson")
plt.legend()
plt.show()

