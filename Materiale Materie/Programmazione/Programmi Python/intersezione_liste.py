# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 14:05:36 2021

@author: damia
"""

def intersezione(a, b):
    c = []
    for x in a:
        if x in b and x not in c:
            c.append(x)
    return c

a = ["ciao", 1, 6, 9]
b = ["python", 5, 9, 7, "ciao"]

c = intersezione(a, b)

print(c)