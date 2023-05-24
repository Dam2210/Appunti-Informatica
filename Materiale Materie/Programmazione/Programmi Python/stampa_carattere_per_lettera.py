# -*- coding: utf-8 -*-
"""
Created on Tue Nov  2 13:30:37 2021

@author: damia
"""

a = input('Inserisci una stringa: ')

soluzione = ''

for x in a:
    if x >= 'a' and x <= 'z':
    		soluzione += '*' 
    elif x >= 'A' and x <= 'Z':
        soluzione += '-' 
    elif  x >= '0' and x <= '9':
        soluzione += ':'
    else:
         soluzione += ' '
		
print(a)
print(soluzione)