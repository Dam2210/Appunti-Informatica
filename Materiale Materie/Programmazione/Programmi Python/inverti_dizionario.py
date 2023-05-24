
"""
Scrivere una funzione denominata inverti_dizionario che prende in input un dizionario d 
e restituisce un dizionario d_inv che ha per chiavi i valori in d e d_inv[v] è la lista di chiavi che d mappa in v.
"""

def inverti_dizionario(d):
    d_inv = {}
    for k, v in d.items(): #restituisce la coppia chiave valore
        if v not in d_inv:
            d_inv[v] = [k]
        else:
            d_inv[v].append(k)
    return d_inv        
        
d = { 'k0': 'v0', 'k1': 'v1', 'k2': 'v0' }
d_inv = inverti_dizionario(d)
print(d_inv)
#il costo computazionale è lineare in O(n) cioè la grandezza costante del dizionario