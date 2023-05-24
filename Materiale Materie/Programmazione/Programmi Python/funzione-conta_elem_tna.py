# -*- coding: utf-8 -*-
"""
Created on Sat Nov 27 11:28:25 2021

@author: damia

Scrivere una funzione, chiamata conta_elem_tna(), che prende in input 
una tna e restituisce il numero totale di float ed int dentro la tna.
"""
#tna = tupla numerica annidata

def conta_elem_tna( t ):
    '''
    Restituisce il numero degli elementi numerici della tna
    '''
    #t è una tna e la funzione restituisce il numero di elementi di t
    if type(t) in (float, int): # t è un numero
        return 1
    elif type(t) == tuple:
        c = 0
        for x in t:
            c += conta_elem_tna( x )
        return c
    return 0 
#se il tipo del numero nella tna è diverso da int o float viene restituito 0


t = ( 3.14, (2,3), (2.71, (7, 5)), 9, (12, ( 4, )) ) 
help(conta_elem_tna) #restituisce quello scritto tra ''' nella funznione
print("gli elementi numerici della tna sono:", conta_elem_tna(t))

