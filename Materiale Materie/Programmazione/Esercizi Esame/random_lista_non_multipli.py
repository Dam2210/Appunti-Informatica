
'''
In una lista, di numeri casuali, inserire n numeri interi random tra 1 e 30. Dopo l’inserimento 
visualizzare gli elementi della lista con gli indici.
Poi contare e visualizzare quanti numeri non multipli di 3 sono stati inseriti nella lista.
'''

def conta_non_multipli(a):
    c = 0
    for i in range (len(a)):
        if a[i]%3 != 0:
            print("non multiplo:", a[i])
            c += 1

    print("i numeri non multipli sono:", c)


n = int(input("quanti numeri vuoi inserire?:"))
a = []

from random import randint

for i in range (n):
    num = randint(1, 30)
    a.append(num)

conta_non_multipli(a)

for i in range (len(a)):
    print(i, "->", a[i])



