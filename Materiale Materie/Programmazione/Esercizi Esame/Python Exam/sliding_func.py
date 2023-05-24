"""
Si scriva una funzione, denominata sliding_func, che prenda in input una lista a, un
intero positivo k ed una funzione f e restituisca una nuova lista b di dimensione n tale
che b[i] sia il risultato di f applicato alla sotto-sequenza di a contenente i k elementi
che precedono a[i], lo stesso a[i] ed i k elementi che seguono a[i]. Nel caso in cui non
ci siano k elementi prima di a[i] allora devono essere presi tutti gli elementi prima di
a[i]. Simmetricamente, nel caso in cui non ci siano k elementi dopo a[i] si devono
prendere tutti gli elementi dopo a[i].
"""

def sliding_func(a : list, k : int, f) -> list:
    n = len(a)
    b = []

    # per gli elementi "troppo" a sinistra
    for i in range(k):
        b.append(f(a[:i+k+1]))

    # per gli elementi "abbastanza" al centro
    for i in range(k, n-k):
        b.append(f(a[i-k:i+k+1]))

    # per gli elementi "troppo" a destra
    for i in range(n-k, n):
        b.append(f(a[i-k:]))
    
    return b

a = [2, 2, 4, 1, 5, 6, 8]
a = sliding_func(a, 2, max)
print(a)
