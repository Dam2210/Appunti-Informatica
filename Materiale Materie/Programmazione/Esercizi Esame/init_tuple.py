"""
Si progetti una funzione denominata init_tuple che prenda in input un intero positivo n e, opzionalmente, 
una funzione v. La funzione restituisca una tupla di lunghezza n che in posizione i contenga v(i).
Qualora il parametro v non fosse specificato, la funzione restituirebbe una tupla composta da n zeri.

Suggerimento. Potrebbe essere utile partire da una tupla vuota - si indica così () - e poi procedere 
per concatenazioni successive. A tal proposito si provi ad usare l'operatore + come si fa con le stringhe. 
Una tupla composta da un unico elemento e si definisce in questo modo (e, ).

Utilizzare la funzione init_tuple per creare una tupla contenente i primi 10 numeri dispari

Utilizzare la funzione init_tuple per creare una tupla contenente 10 stringhe non vuote di lunghezza crescente

Utilizzare la funzione init_tuple per creare una tupla contenente 10 tuple tali che la tupla in posizione i 
sia lunga 10 e contenga i in ogni posizione. Suggerimento: come per le stringhe, * sulle tuple è l'operatore 
di ripetizione.
"""

def fun_gen(x):
    if type(x) == int:
        return x + 1
    else:
        return 0

def make_odd(n):
   n =(n*2)+1
   return n

def make_x(n):
    n = 'x'*(n+1)
    return n

def make_n(n):
    n = (n,)*10
    return n

def init_tuple(n, v = None):
    a = ()
    if v == None:
        a += (0,) * n
    else:
        for i in range(n):
            a += (v(i),)
    return a

a = init_tuple(10, make_odd)
print(a)
