"""
 Scrivere una funzione denominata inverti_dizionario che prende in input un dizionario d e restituisce 
 un dizionario d_inv che ha per chiavi i valori in d e d_inv[v] è la lista di chiavi che d mappa in v.
"""
def inv_d(d):
    d1 = {}
    for k in d: #costo lineare in n perchè per n volte eseguo un'operazione costante.
        lista = [k]
        if d[k] in d1:
            d1[d[k]] += lista
        else:
            d1[d[k]] = lista
    return d1

d = { 'k0': 'v0', 'k1': 'v1', 'k2': 'v0' }
d = inv_d(d)
print("dizionario invertito:", d) 

print("---------------------------------------------------------")

def inverti_dizionario_prof(d):
    d_inv = {}
    for k, v in d.items(): #creiamo una tupla chiave e valore (k, v)
        # per ogni coppia k, v nel dizionario in input aggiungiamo o
        # aggiorniamo d_inv[v]
        if v not in d_inv:
            d_inv[v] = [k]  # inserimento della nuova chiave v
        else:
            d_inv[v].append(k) # aggiornamento della lista d_inv[v]
            
    return d_inv

d_prof= { 'k0': 'v0', 'k1': 'v1', 'k2': 'v0' }
d_prof = inverti_dizionario_prof(d_prof)
print("dizionario invertito del prof:", d_prof)

print("---------------------------------------------------------")

"""
Scrivere una funzione che prende due dizionari in input a e b e restituisce un terzo dizionario c che ha 
per chiavi tutte quelle in a che non sono in b e tutte quelle in b che non sono in a.
I valori associati a queste chiavi devono essere quelli del dizionario di partenza. 
La funzione deve chiamarsi differenza_simmetrica.
"""
def differenza_simmetrica(a, b):
    c = {}
    for k in a: #lineare in len(a) = n
        if k not in b:
            c[k] = a[k]
    for x in b: #lineare in len(b) = m
        if x not in a:
            c[x] = b[x]
    return c


a = {'k0': 'v0', 'k1': 'v1', 'k2': 'v0'}
b = {'k1': 'v7', 'k2': 'v1', 'k3': 'v3'}
c = differenza_simmetrica(a, b)
print("differenza simmetrica:", c)

print("---------------------------------------------------------")

"""
dato un dizionario d2 restituisci la lista delle sue chiavi e dei suoi valori.
"""

d2 = {'ciao' : 0, 'come' : 1, 'stai': 2, '?' : 100, 'viva' : 30, 'il' : 8, 'DUCE' : 7000}
chiavi = d2.keys()
valori = d2.values()
print('chiavi:', d2.keys())
print('valori:', d2.values())

print("---------------------------------------------------------")

"""
usare la funzione d.clear() per svuotare il dizionario.
"""
d3 = {'ciao' : 0, 'come' : 1, 'stai': 2, '?' : 100, 'viva' : 30, 'il' : 8, 'DUCE' : 7000}
print("dizionario d3 pieno:", d3)
print("d3 vuoto tramite clear:", d3.clear())

print("---------------------------------------------------------")


