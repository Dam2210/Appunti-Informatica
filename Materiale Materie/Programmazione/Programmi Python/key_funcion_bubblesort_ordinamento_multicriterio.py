# -*- coding: utf-8 -*-
"""
Created on Tue Dec 14 14:07:06 2021

@author: damia

Ordinamento multi-criterio 2 La lista a è composta da numeri e stringhe, 
si vogliono ordinare gli elementi di a in modo che:

1. i numeri precedano le stringhe
2. i numeri siano ordinati dal più piccolo al più grande
3. le stringhe siano ordinate da quella più corta a quella più lunga
Progettare ed implementare una opportuna key-function da utilizzare con la 
lunzione bubble_sort
"""


def bubble_sort( a, k = lambda x: x, reverse = False):
    '''
    pre: a è una lista
    ordina gli elementi della lista in modo crescente rispetto ai valodi restituiti 
        dalla funzione k. Ovvero dopo l'esecuzione della funzine se
        a = [a_0, a_1,... a_n] allora k(a_i) <= k(a_i+1) per tutti gli i.
        Di default k è la funzione identità 
    '''
    #s = 1 if reverse == False else -1
    
    n = len(a)
    ordinata = False
    num_scansioni = 0 # numero di scansioni (esecuzioni for) già eseguite
    while not ordinata:
        ordinata = True
        for i in range(n-1-num_scansioni): # ad ogni iterazione il numero di coppie da
                                            # analizzare diminuisce di 1
            # confrontiamo l'elemento in posizione i e i+1
            if (reverse == False and k(a[i]) > k(a[i+1])) \
                or (reverse == True and k(a[i]) < k(a[i+1])):
                # scambio gli elementi, non posso dire che la lista è ordinata
                a[i], a[i+1] = a[i+1], a[i]
                ordinata = False
        num_scansioni += 1

def key_num_str(x):
    '''
    x è una stringa o un numero
    '''
    if type(x) in (int, float):
        return (0, x)
    else:
        return (1, len(x))


a = ['zero', 3.14, 'due', 1, 'x']

bubble_sort (a, k = key_num_str, reverse = True)
print(a)

