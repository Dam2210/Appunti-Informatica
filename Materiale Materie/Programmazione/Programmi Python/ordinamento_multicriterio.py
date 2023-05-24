# -*- coding: utf-8 -*-
"""
Created on Thu Dec  9 14:00:15 2021

@author: damia

1. i numeri precedano le stringhe
2. i numeri siano ordinati dal più piccolo al più grande
3. le stringhe siano ordinate da quella più corta a quella più lunga
Progettare ed implementare una opportuna funzione di confronto da utilizzare con la lunzione bubble_sort

"""

def cmp_len(x, y):
    return len(x) <= len (y)

def cmp_val(x, y):
    return x <= y
        
def ordinamento_multicriterio(x, y):
   if type(x) in (float, int) and type(y) in (float, int):
       return x <= y
   if type(x) == str and type(y) == str:
       return len(x) <= len(y)
   if type(x) in (float, int):
       return True
   else:
       return False

def bubblesort(a, cmp_func = cmp_val):
    '''
    ordina la lista dall'elemento più piccolo a quello più grande
    questo algoritmo si chiama bubblesort
    '''
    n = len(a)
    ordinata = False
    num_scansioni = 0 # numero di scansioni (esecuzioni for) già eseguite
    while not ordinata:
        ordinata = True
        for i in range(n-1-num_scansioni):
            # confrontiamo l'elemento in posizione i e i+1
            if not cmp_func(a[i], a[i+1]) :
                # scambio gli elementi, non posso dire che la lista è ordinata
                a[i], a[i+1] = a[i+1], a[i]
                ordinata = False
        num_scansioni += 1
        
x = [2, 0, 1, "ciao", 10, "hello", 4, "python", 9] #1

y = [2, 7, 5, 3, 0, 89, 10, 30, 20] #2

z = ["sette", "uno", "ottanta", "due", "cinque", ] #3

bubblesort(x, ordinamento_multicriterio)
bubblesort(y, ordinamento_multicriterio)
bubblesort(z, ordinamento_multicriterio)

print("i numeri precedano le stringhe:", x)
print("i numeri sono ordinati dal più piccolo al più grande:", y)
print("le stringhe vengono ordinate da quella più corta a quella più lunga:", z)