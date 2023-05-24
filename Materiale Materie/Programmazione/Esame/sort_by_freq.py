def sort_by_freq(a):
    d = {} # creo un dizionario vuoto
    for i in a: # con questo for aggiungo ogni elemento della lista come chiave nel dizionario 
        if i in d: # se l'elemento è nel dizionario
            d[i] += 1 # incremento il numero di volte in cui compare nella lista 
        else: # altrimento
            d[i] = 1 # lo aggiungo come chiave e assegno come valore 1 (prima volta che è comparso nella lista) 
    print(d)
    a.sort(key=lambda x: d[x]) # ordina a in base al valore delle chavi nel dizionario

#costo O(nlogn) per la funzione sorted mentre la creazione del dizionario è O(1) cioè costante e il for ha costo O(n)

l = ['a', 2, 2, 'b', 'b', 4, 'b', 2, 2, 1.31, 5, 5, 'b', 2]
sort_by_freq(l)
print(l)