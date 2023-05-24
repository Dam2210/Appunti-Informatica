def bin_search(a, k):
    """
    Ricerca k nella lista a, ritorna la posizione di k in a
    Precondizione: a è una lista di elementi ordinati dal più piccolo al più grande.
    """
    n = len(a)
    lx = 0
    rx = n-1
    while lx <= rx: #finchè lo spazio di ricerca non è vuoto.
        cx = (lx+rx)//2 #divisione che restituisce la parte intera di una divisione es: se il risultato è 2,5 restituisce 2
        if k == a[cx]:
            return cx
        if k < a[cx]:
            rx = cx-1
        else: #k > a[cx]
            lx = cx+1
    return -1

a = [1, 1, 2, 2, 5, 5, 10, 10, 12, 12, 13, 15, 16, 16, 20, 22, 22]
k = int(input("inserisci l'elemento da cercare nella lista:"))
b = bin_search(a, k)

if b != -1:
    print("la posizione del valore", k, "è:", b)
else:
    print("il valore", k, "non è presente nella lista:", a)

#il costo nel caso peggiore è: costante * log(base 2) di n = O(n)
#costante = per l'esecuzione del while
#log(base 2) di n = volte che viene eseguito il while
#n = dimensione della lista