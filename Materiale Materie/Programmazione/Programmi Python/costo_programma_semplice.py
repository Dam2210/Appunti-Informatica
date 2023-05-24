# -*- coding: utf-8 -*-
"""
Created on Thu Dec 23 14:09:40 2021

@author: damia
"""
 
a = ['uno', 'sei', 'due', 'zero', 'nove']
n = len(a)
s = set(a) #il costo è lineare in n
#faccio diventare a un insieme in modo tale da fargli avere costo costante
m = 4

for i in range(m):
    stringa = input('inserisci una stringa:')

    if stringa in s: #il costo dell'istruzione con l'insieme è 'O(m)'
        print('Si')
    else:
        print('No')

#il costo totale del programma è quindi O(n+m)