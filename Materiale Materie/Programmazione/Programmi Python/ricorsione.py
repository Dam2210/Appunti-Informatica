# -*- coding: utf-8 -*-
"""
Created on Sun Nov 21 12:27:43 2021

@author: damia
"""

def f(n):

    if n>0: #se n è positivo, se non ci fosse questo if per ogni valore di n negativo avremmo un errore di ricorsione.
    
        if n == 1: #vera per f(1)
            r = 1
        else:
            r = n + f(n-1) # f(3)=3+f(2)-->f(2)=2+f(1)-->f(1)=1 quindi: f(2)=2+1=3 e f(3)=3+3=6, 6 viene assegnato a c
            
    else:
        
        if n == 1:
            r = 1
        else:
            r = n + f(n+1) 
            
    return r
 
#c = f(3) questo è 6
c = f(int(input("inserisci un numero:")))

print(c)