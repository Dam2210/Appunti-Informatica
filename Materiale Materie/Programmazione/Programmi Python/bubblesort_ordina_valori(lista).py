# -*- coding: utf-8 -*-
"""
Created on Thu Dec  2 14:47:46 2021

@author: damia
"""

def bubblesort(a):
    '''
    ordina la lista dall'elemento più piccolo a quello più grande
    questo algoritmo si chiama bubblesort
    '''
    n = len(a)
    ordinata = False
    num_scansioni = 1 #contatore numero scansioni
    while not ordinata: #finchè non è ordinata (cioè ordinata == False)
        print(num_scansioni) # stampo il numero di scansioni
        num_scansioni += 1 #incremento il contatore delle scansioni
        ordinata = True
        for i in range(n-1):
            if a[i] > a[i+1]:
                a[i], a[i+1] = (a[i+1], a[i])
                ordinata = False
        print(ordinata)
    
    
b=[3, 81, 4, 17, 0, 9, 11] #definisco una lista

help(bubblesort)

print("la lista è:", b)

print(" ")

bubblesort(b) #eseguo la funzione bubblesort della lista b
print (b) 

print(" ")
print("la lista ordinata è:", b)