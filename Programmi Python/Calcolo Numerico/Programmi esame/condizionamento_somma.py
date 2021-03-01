"""
Test da eseguire per la presentazione:
    - somma tra numeri casuali
    - x=4  e y=-3 (situazione di mal condizionamento perchè differenza tra numeri vicini)
    - x = 32.75642 e y = -32.75641 (enfatizzo il malcodizionamento)
    - x = 6 e y = 6.9878 (enfatizzo di più)
"""

from random import random

#dati esatti 
x = float(input("Inserire dato x: "))
y = float(input("Inserire dato y: "))

#costruzione dati perturbati
x_pert = x + x*random()*1.0e-4
y_pert = y+ y*random()*1.0e-4

#calcolo somma
s = x+y
s_pert = x_pert+y_pert
print("\nSomma sui dati reali: %f + %f = %f" % (x, y, s))
print("Somma sui dati perturbati: %f + %f = %f" % (x_pert, y_pert, s_pert))

#calcolo degli errori
err_x = abs(x-x_pert)/abs(x)
err_y = abs(y-y_pert)/abs(y)
err_s = abs(s-s_pert)/abs(s)

#calcolo i fattori di amplificazione
ampl_x = abs(x)/abs(x+y)
ampl_y = abs(y)/abs(x+y)

print("\n-------------Errori in input-------------")
print("Errore su x = %e" % err_x)
print("Errore su y = %e" % err_y)
print("\n-------------Errori in output-------------")
print("Fattore di amplificazione |x|/|x+y|: %e" % ampl_x)
print("Fattore di amplificazione |y|/|x+y|: %e" % ampl_y)
print("Errore sulla somma = %e" % err_s)
