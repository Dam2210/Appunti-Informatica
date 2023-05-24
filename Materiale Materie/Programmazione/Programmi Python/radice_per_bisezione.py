# -*- coding: utf-8 -*-
"""
Created on Sun Nov 14 16:08:25 2021

@author: damia
"""

def bisezione(x, err= 0.0001):
    b = 2
    i = 0
    while b**i < x:
        i += 1

    y_inf, y_sup = i-1, i

    trovato = False

    while not trovato:
        y = (y_inf + y_sup)/2
        if b**y < x - err:
            y_inf = y
        elif b**y > x + err:
            y_sup = y
        else:
            trovato = True
        
    return y

def radice_babilonese( x, err = 0.0001 ):
    g = x/2
    while abs( g*g - x ) > err: 
        g = 0.5 * ( g + x/g )
    return g

a=int(input("inserisci il valore:"))

z=bisezione(a)
print("La bisezione di", a, "è:", z)

f=radice_babilonese(a)
print("La radice babilonese di", a, "è:", f)


