from random import random
from scipy.misc import derivative
import numpy as np
import matplotlib.pyplot as plt

def fun(x):
    y = np.log(x)
    return y

#intervallo di punti in cui calcolare la funzione
a = 2; b = 100
x = np.array(range(a, b))

#applico una perturbazione ai dati
x_pert = np.full(len(x), x + x*random()*1.0e-12)

#calcolo della funzione
fx = fun(x)
fx_pert = fun(x_pert)

#calcolo fattore di amplificazione dell'errore
dx = derivative(fun, x)
fatt_ampl = abs(x*dx)/abs(fx)

#calcolo degli errori
err_rel = abs(fx-fx_pert)/abs(fx)

#visualizzazione grafica dei risultati
plt.figure(1)
plt.title("Errori nel calcolo di f(x) nell'intervallo [%d, %d]" % (a, b))
plt.semilogy(x, err_rel, "k-",  label="Errori relativi")
plt.xlabel("x")
plt.legend()
plt.show()

plt.figure(2)
plt.title("Fattore di amplificazione")
plt.semilogy(x, fatt_ampl, "b-", label="Fatt. ampl.")
plt.xlabel("x")
plt.legend()
plt.show()
