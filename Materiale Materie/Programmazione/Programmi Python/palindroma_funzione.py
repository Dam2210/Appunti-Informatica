# -*- coding: utf-8 -*-
"""
Created on Sun Nov 14 15:40:44 2021

@author: damia
"""

def palindromo( a ):
    if a == a[::-1]: # l'inverso di a
        return True
    else:
        return False
    
a = input('Inserisci una stringa: ')

if palindromo( a ):
    print('La stringa', a, 'è palindroma')
else:
    print('La stringa', a, 'non è palindroma')