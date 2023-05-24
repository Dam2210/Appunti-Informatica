"""
Popolare una lista di 5 elementi con il valore del suo indice, posizionando ciascun elemento in testa alla lista. 
Dopo visualizzare ogni elemento della lista con il valore del suo indice. Infine rimuovere tutti gli elementi.
"""

n = 5
a = []

for i in range(n):
    a.insert(0,i) #inserisci i valori di i al contrario [0, 1, 2, 3, 4] diventa [4, 3, 2, 1, 0]

print(a)

for i in range(n):
    print(i, "-->", a[i])

for i in range(n-1,-1,-1): #parto da n-1 (ultima pos) poi arrivo a -1 che sarebbe la posizione finale a sinistra e -1 è il valore di quanto mi devo spostare
    a.remove(a[i])
    print(a)