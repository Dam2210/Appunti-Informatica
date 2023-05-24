"""
Scrivere un metodo che, date due liste a e b di interi, restituisce true se tutti gli elementi
della lista b compaiono nella lista a nello stesso ordine in cui compaiono in b, altrimenti il
metodo restituisce false.
a = [-5, 4, 7, -1, 10, 21, 9, -7] e b = [4, -1, 9, -7] restituisce true
"""

def stesso_ordine(a, b):
    d_a = {}
    d_b = {}
    c = 1
    d = 1
    ordine = False
    len_a = len(a)
    len_b = len(b)
    for i in range(len_b):
        d_b[b[i]] = c
        c += 1
    for i in range(len_a):
        if a[i] in b:
            d_a[a[i]] = d
            d += 1
    print("d_a:", d_a)
    print("d_b:", d_b)
    if d_b == d_a:
        ordine = True
        return ordine
    else:
        return ordine


a = [-5, 4, 7, -1, 10, 21, 9, -7]
b = [4, -1, 9, -7]
print(stesso_ordine(a, b))