# -*- coding: utf-8 -*-
"""

Created on Sat Dec 11 14:17:57 2021

@author: damia

Ordinamento invertito Dopo aver risolto il precedente esercizio, modificare la funzione in modo che sia compreso un terzo parametro, 
chiamato reverse, di tipo bool che di default deve essere False. 
In caso questo sia True l'ordinamento deve essere invertito rispetto al criterio 
indotto alla key-function.
"""

def bubble_sort( a, k = lambda x: x, reverse = False):
    '''
    pre: a è una lista
    ordina gli elementi della lista in modo crescente rispetto ai valodi restituiti 
        dalla funzione k. Ovvero dopo l'esecuzione della funzine se
        a = [a_0, a_1,... a_n] allora k(a_i) <= k(a_i+1) per tutti gli i.
        Di default k è la funzione identità 
    '''
    s = 1 if reverse == False else -1
    
    n = len(a)
    ordinata = False
    num_scansioni = 0 # numero di scansioni (esecuzioni for) già eseguite
    while not ordinata:
        ordinata = True
        for i in range(n-1-num_scansioni): # ad ogni iterazione il numero di coppie da
                                            # analizzare diminuisce di 1
            # confrontiamo l'elemento in posizione i e i+1
            if s*k(a[i]) > s*k(a[i+1]):
                # scambio gli elementi, non posso dire che la lista è ordinata
                a[i], a[i+1] = a[i+1], a[i]
                ordinata = False
        num_scansioni += 1
        
a = ['zero', 'uno', 'due', 'tre', 'quattro']
bubble_sort(a, k = len, reverse = True) # ordinamento per lunghezze crescenti
print(a)
