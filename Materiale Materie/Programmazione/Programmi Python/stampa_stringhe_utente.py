"""
Sia a una lista lunga n, scrivere un programma che chiede 
all'utente di digitare m stringhe e per ognuna di queste il programma deve stampare quante volte compare 
in a ed in che posizione si trova l'ultima occorrenza (se il numero di occorrenze è >0). Il costo della soluzione deve essere O(n+m).
"""

a = ['ciao', 'gatto', 'python', 'geova', 'cane', 'geova', 'ciao']
d = {}
n, i = len(a), 0

print(a)
while i < n: #costo lineare in n
    x = a[i]
    if x not in d: #costo costante c
        d[x] = (1, i) 
#se x non è nel dizionario lo inserisco come chiave che punta al numero di occorrenze e all'ultima posizione conosciuta
    else:
        d[x] = (d[x][0] + 1, i)
    i += 1
    #la chiave rimane d[x] ma il primo valore della tupla puntato cioè il numero di volte che è presente viene incrementato.
    #il secondo valore della tupla (posizione) viene aggiornato con l'ultima posizione nota.
    #il costo medio della costruzione del dizionario è di O(n)
m, i = 5, 0
while i < m: #costo lineare in m
    x = input("inserisci una stringa:")
    if x in d: #costo lineare in m
        print(x, "compare", d[x][0], "volte e l'ultima occorrenza è in posizione", d[x][1])
    else:
        print(x, "non è nella lista")
    i += 1
print(d)

#il costo totale è O(n + m)


