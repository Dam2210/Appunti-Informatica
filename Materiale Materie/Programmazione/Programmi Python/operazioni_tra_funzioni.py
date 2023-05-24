# -*- coding: utf-8 -*-
"""
Created on Sun Nov 21 11:51:49 2021

@author: damia
"""
#STACK FRAME

def g(a, b = 3, c = 2):
    r = a+b+c
    return r

def f(a):
    r = g(a) + g(a-1, c = 1) #faccio (((2+3+2=7)+(1+3+1=5))=12)
    return r

n = f(2)
print("il risultato di n è:",n )