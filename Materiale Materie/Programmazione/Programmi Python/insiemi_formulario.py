# -*- coding: utf-8 -*-
"""
Created on Tue Dec 21 14:54:25 2021

@author: damia
"""

a = {2, 3, 4, 5}
b = {0, 6, 3, 1}

print(type(a))

print(a)

b.add('python') #aggiunge all'insieme un nuovo elemento e modifica l'insieme
print(b)

print(a|b) #stampa l'unione tra a e b

print(a.union(b)) #fa sempre l'unione tra insiemi

print(a & b) #stampa l'inersezione
print(a.intersection(b)) #stampa l'inersezione

print(a-b) #stampa la differenza 
print(a.difference(b)) #stampa la differenza 

a.remove(2) #rimuove un elemento dall'insieme e modifica l'insieme
print(a) 

c = [1, 3, 6, 6, 6, 8, 0] #c è una lista
s = set(c) #crea un insieme dalla lista c
print(s)

f = {} #questo è un insieme vuoto

#le liste non possono essere aggiunti agli insiemi
#le tuple possono essere aggiunte agli insiemi invece
#gli insiemi non possono essere aggiunti agli insiemi

#agli insiemi non possono essere aggiunti elementi modificabili (es. liste)
#ma solo non modificabili (es. tuple)