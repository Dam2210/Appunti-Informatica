# -*- coding: utf-8 -*-
"""
Created on Sun Nov 14 15:38:12 2021

@author: damia
"""

b = 10
x = 22
err = 0.0001

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
        
print(y)