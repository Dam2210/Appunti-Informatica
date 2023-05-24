"""
Scrivere una funzione che prende due dizionari in input a e b e restituisce un terzo dizionario c 
che ha per chiavi tutte quelle in a che non sono in b e tutte quelle in b che non sono in a. 
I valori associati a queste chiavi devono essere quelli del dizionario di partenza. 
La funzione deve chiamarsi differenza_simmetrica.
"""

def differenza_simmetrica(a, b):
    c = {}
    for k in a:
        if k not in b:
            c[k] = a[k]
    
    for k in b:
        if k not in a:
            c[k] = b[k]
    return c




a = {'k0': 'v0', 'k1': 'v1', 'k2': 'v0'}
b = {'k1': 'v7', 'k2': 'v1', 'k3': 'v3'}
c = differenza_simmetrica(a, b)
print (c)

#costo medio O(|a| + |b|)