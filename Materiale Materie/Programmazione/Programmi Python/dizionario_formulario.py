# -*- coding: utf-8 -*-
"""
Created on Thu Dec 23 14:46:02 2021

@author: damia
"""
#il dizionario è formato da una chiavi e un valore

d = {}
#questo è un dizionario vuoto
print(type(d)) 

d['k0'] = 3.14 #chiave: k0, valore: 3.14
print(d)

d[1000] = [2, 1] #chiave: 1000, valore: lista
print(d)

d[(7, 10)] = 'ciao'
#come chiave non possiamo usare tipi mutabili (list, set) ma solo immutabili (tupla, int)
#come valore posso usare sia mutabili che immutabili (tupla, list etc..)

d['k0'] = 'nuovo valore'
#aggiorno la coppia con chiave k0
print(d)

print(d[1000])
#stampo i valori con chiave 1000

if 'k0' in d:
    print(True)
else:
    print(False)
    
del d['k0']
#elimino la coppia con chiave k0
print(d)

for x in d:
    print(x, '----->', d[x])
    # x è la chiave, d[x] è il valore
 
print(d.keys()) #restituisce la lista delle chiavi

print(d.values()) #restituisce la lista dei valori