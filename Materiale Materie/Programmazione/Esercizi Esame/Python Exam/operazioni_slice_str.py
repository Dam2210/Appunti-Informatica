a = "parallelepipedo"
print(a[:4]) #stampa le prime 4 posizioni
print(a[10:13]) #stampa da n a m-1
print(a[:-1]) #senza la lettera finale
print(a[2:-2]) #stampa da posizione n e leva le ultime m lettere
print(a[::-1]) #fa il reverse di una stringa
print(a[2:]) #stampa senza le prime n lettere della stringa
print(a[:2]+a[2+1:])

def f (x):
    if type(x) == type(0):
        return x
    else:
        return -1

b = ['x', 1, 'y', 2, 0]

print(sorted(b, key = f))
