# -*- coding: utf-8 -*-
"""
Created on Sun Nov 14 15:41:54 2021

@author: damia
"""

def radice( a, err = 0.0000001 ):
    g = a/2
    while abs( g*g - a ) > err: #abs=valore assoluto
        g = 0.5 * ( g + a/g )
    return g

x = float(input('Inserisci il valore di x: '))
y = float(input('Inserisci il valore di y: '))

r_x, r_y = radice( x, 1**(-9) ), radice( y )

print(r_x, r_y)

print(r_x + r_y)