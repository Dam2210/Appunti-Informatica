"""
Created on Sat Nov 27 13:15:42 2021

@author: damia

Esercizio: scrivere un programma che, data una lista contenente numeri, 
porta il valore massimo in ultima posizione e gli altri elementi nelle posizioni precedenti
"""
'''

***Questo programma fa la stessa cosa del programma "valore_massimo_lista_in_ultima_posizione_2.py" ma in modo più 'complesso'***

'''
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
        lista += [lista.pop(a)] #aggiungo l'elemento eliminato nella posizione a alla lista
       
print("la lista con il numero più grande messo nella posizione finale è:", lista)
print("la lunghezza della lista è:", n)

#pop(a) elimina l'elemento nella posizione a
#lista += [lista.pop(a)] aggiunge alla lista l'elemento nella poosizione a che viene eliminato.
