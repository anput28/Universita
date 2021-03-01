import ricerca_radici as rr

def fun(x):
	y = x**3 - 3*x
	return y

#derivata della funzione fun
def der(x):
	y = 3*x**2 - 3
	return y

#parametri dei metodi per la ricerca della radice
tol = 1.0e-14
x0 = 2
#seconda approssimazione per il metodo delle secanti
x1 = 3
#coefficiente angolare per il metodo delle corde
m = 15
kmax = 200

#ricerca con il metodo delle tangenti
r_tan, k_tan = rr.metodo_tangenti(x0, fun, der, tol, kmax)

#ricerca con il metodo delle corde
r_cor, k_cor = rr.metodo_corde(x0, fun, m, tol, kmax)

#ricerca con il metodo delle tangenti
r_sec, k_sec = rr.metodo_secanti(x0, x1, fun, tol, kmax)

#visualizzazione dei risultati
print("Risultati ottenuti da ciascun metodo:")
print("- Metodo delle tangenti:")
print("\tApprossimazione trovata: x = %.15f => f(x) = %.15f" % (r_tan, fun(r_tan)))
print("\tNumero di iterazioni effettuate: %d" % k_tan)

print("\n- Metodo delle secanti:")
print("\tApprossimazione trovata: x = %.15f => f(x) = %.15f" % (r_sec, fun(r_sec)))
print("\tNumero di iterazioni effettuate: %d" % k_sec)

print("\n- Metodo delle corde (con m = %d):" % m)
print("\tApprossimazione trovata: x = %.15f => f(x) = %.15f" % (r_cor, fun(r_cor)))
print("\tNumero di iterazioni effettuate: %d" % k_cor)

