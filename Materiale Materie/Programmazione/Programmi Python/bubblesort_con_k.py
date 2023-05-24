# -*- coding: utf-8 -*-
"""
Created on Thu Dec  9 14:56:58 2021

@author: damia
"""

def bubblesort(a, k = lambda x : x):
    '''
    ordina la lista dall'elemento più piccolo a quello più grande
    questo algoritmo si chiama bubblesort
    '''
    n = len(a)
    ordinata = False
    num_scansioni = 1 #contatore numero scansioni
    while not ordinata: #finchè non è ordinata (cioè ordinata == False)
        #print(num_scansioni) stampo il numero di scansioni
        num_scansioni += 1 #incremento il contatore delle scansioni
        ordinata = True
        for i in range(n-1):
            if k(a[i]) > k(a[i+1]):
                a[i], a[i+1] = (a[i+1], a[i])
                ordinata = False
        num_scansioni += 1
        
x = ["zero", "uno", "due", "tre", "quattro"]
bubblesort(x, len)
print(x)

y = [4, 3, 2.71, 0, 1]
bubblesort(y)
print(y)

