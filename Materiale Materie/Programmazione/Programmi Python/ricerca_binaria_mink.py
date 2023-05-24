def bin_search_mink(a, k):
    """
    Ricerca k nella lista a, ritorna la posizione di k in a
    Precondizione: a è una lista di elementi ordinati dal più piccolo al più grande.
    """
    n = len(a)
    lx = 0
    rx = n-1
    while lx <= rx: #finchè lo spazio di ricerca non è vuoto.
        cx = (lx+rx)//2 #divisione che restituisce la parte intera di una divisione es: se il risultato è 2,5 restituisce 2
        if k >= a[cx] and (cx == n-1 or a[cx+1] > k):
            return cx+1
        if k < a[cx]:
            rx = cx-1
        else: #k > a[cx]
            lx = cx+1
    return 0

a = [-8, 1, 1, 2, 2, 5, 5, 10, 10, 12, 12, 13, 15, 16, 16, 20, 22, 22]
k = int(input("inserisci l'elemento da cercare nella lista:"))
pos= bin_search_mink(a, k)

if pos==0:
    print("L'elemento", k, "non è in lista")
    print ("Gli elementi minori di", k, "in lista sono:", pos)
else:
    print("La posizione dell'elemento", k, "è:", pos)
    print ("Gli elementi minori di", k, "in lista sono:", pos)
#print("Il numero di elementi minori di", k, "è")