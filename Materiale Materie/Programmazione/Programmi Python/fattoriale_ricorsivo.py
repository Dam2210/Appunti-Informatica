# -*- coding: utf-8 -*-
"""
Created on Tue Nov 23 14:15:23 2021

@author: damia
"""

def fattoriale_ricorsivo(n):
    if(n>=2):
        ris=n*fattoriale_ricorsivo(n-1)
    else:
        ris=n
    return ris

a=fattoriale_ricorsivo(int(input("inserisci il numero di cui vuoi calcolare il fattoriale:")))

if(a>=1):
    print(a)
else:
    print("non è possibile calcolare il fattoriale di", a)