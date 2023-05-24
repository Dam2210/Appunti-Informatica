# -*- coding: utf-8 -*-
"""
Created on Sat Nov 27 14:34:34 2021

@author: damia

Esercizio: scrivere un programma che, data una lista contenente numeri, 
porta il valore massimo in ultima posizione e gli altri elementi nelle posizioni precedenti
"""

n =int(input("quanti numeri vuoi inserire alla lista?:"))
lista = []
c=n
print('puoi aggiungere fino a', c,'numeri nella lista...')


for i in range(n):
    print('puoi aggiungere ancora', c, 'numeri:')
    c-=1
    m=int(input('Inserisci un numero nella lista:'))
    lista.append(m)

print("la tua lista è:", lista)
    
for x in lista:
    if x == max(lista):
        a = lista.index(x) #metto in a la posizione di x 
        lista.append(x) #aggiungo x alla lista = [10, 2, 10]
        lista.pop(a) #elimino x che era nella posizione a = [2, 10]
       
print("la lista con il numero più grande messo nella posizione finale è:", lista)
print("la lunghezza della lista è:", n) 