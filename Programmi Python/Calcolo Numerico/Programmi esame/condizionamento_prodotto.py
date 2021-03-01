"""
Test da eseguire per la presentazione:
    - prodotto tra numeri casuali
    - aumentare la perturbazione

"""

from random import random

#dati esatti 
x = float(input("Inserire dato x: "))
y = float(input("Inserire dato y: "))

#costruzione dati perturbati
x_pert = x + x*random()*1.0e-4
y_pert = y + y*random()*1.0e-4

#calcolo prodotto
s = x * y
s_pert = x_pert * y_pert
print("\nProdotto sui dati esatti: %f + %f = %f" % (x, y, s))
print("Prodotto sui dati perturbati: %f + %f = %f" % (x_pert, y_pert, s_pert))

#calcolo degli errori
err_x = abs(x-x_pert)/abs(x)
err_y = abs(y-y_pert)/abs(y)
err_s = abs(s-s_pert)/abs(s)
print("\n-------------Errori in input-------------")
print("Errore su x = %f" % err_x)
print("Errore su x = %f" % err_y)
print("\n-------------Errori in output-------------")
print("Errore sul prodotto = %f" % err_s)

