
def merge(a, lx, cx, rx):
    """
    Precondizione: a è una lista e a[lx:cx] e a[cx:rx] ordinate in modo non decrescente.
    Modifica a fondendo le due sottoliste in modo che a[lx:rx] risulti ordinata.

    Sia n = len(a) e k = rx-lx
    Costo: lineare in k
    """
    #Costa O(k)
    i, j = lx, cx #i = indice in a[lx:cx], j = indice in a[cx:rx]
    c = [] #lista di output
    while i < cx and j < rx:
        if a[i] < a[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(a[j])
            j += 1
    #Costa O(k)
    c += a[i:cx] + a[j:rx]
    print(c)
    #a = a[:lx] + c + a[rx:] #Costo: lx + (rx-lx) + (n-rx) = O(n)
    #Costa O(k)
    for i in range(len(c)):
        a[lx+i] = c[i]

def merge_sort(a, lx, rx):
    """ 
    Precondizione: a è una lista numerica
    Ordina a[lx:rx]
    """
    if lx <= rx-2:
        cx = (rx+lx)//2

        merge_sort(a, lx, cx)
        merge_sort(a, cx, rx)
        merge(a, lx, cx, rx)
        

a = [10, 10, 10, 2, 4, 6, 0, 1, 5, 0, 0, 0]
print("lista a:", merge(a, 3, 6, 9))  
b = [4, 2, 1]
print("la lista b:", b)
n = len(b)
merge_sort(b, 0, n)
print("la lista ordinata b:", b)