a = [2, 6, 7, 7, 11]
b = [0, 1, 8, 10, 13]

def merge(a, b):
    """
    Precondizione: a e b sono due liste numerieche ordinate in modo non decrescente.
    Restituisce una lista c ordinata ottenuta dalla fusione di a e b
    """
    n_a, n_b = len(a), len(b)
    i, j = 0, 0 #i = indice a, j = indice in b
    c = [] #lista di output
    while i < n_a and j < n_b:
        if a[i] < b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    #if i == n_a:
        #c += b[j:]
    #else:
        #c += a[i:]
    c += a[i:] + b[j:]
    return c
    
#Il costo della funzione è O(n) cioè lineare in n

c = merge(a, b)
print("La lista di fusione ordinata di a e b è:", c)