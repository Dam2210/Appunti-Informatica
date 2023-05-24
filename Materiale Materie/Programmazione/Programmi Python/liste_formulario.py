
"""
Created on Sat Nov 27 12:29:00 2021

@author: damia
"""

a = [1, 2.1, (2, 1), [3.14, 'ciao'], 'python'] #è una lista

print("stampo la lista a:", a)

print("stampo il tipo di a:", type(a)) #il tipo di a è 'list'

print("stampo il valore in posizione 0 della lista a[1:3]:", a[1:3][0])
"""
prende gli elementi della lista da 1 a 3:
[ 2.1, (2, 1), [3.14, 'ciao']]
escludendo il 3: [2.1, (2, 1)]
e stampa solo quello in posizione 0: [2.1] 
"""
print("stampo 2 volte a in una nuova lista:", a*2) #stampa 2 volte la lista a

b=[6, 7] #b è una lista
print("stampo la lista b:",b)

print("stampo la lista a + la lista b:", a+b) 
#stampa una lista contenente tutti gli elementi di a più quelli di b

print("il numero di elementi della lista b è:", len(b)) #stampa il numero di elementi di b

b[1]='hello world'
#sostituisco il valore in posizione 1 (7) con 'hello world'

print("la lista b è stata modificata nella posizione 1:", b) 
#stampo la lista modificata

b.append(80) #appen si può usare solo con le liste
#aggiunge alla lista b un valore

print("gli elementi della lista b con il valore aggiunto sono:", b)

b.insert(1, 'code') #insert si può usare solo con le liste
#inserice nella posizione 1 della lista b la parola 'code'

print("stampo la lista b con valore aggiunto in posizione 1:", b)