# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""


parola=str(input('inserire una parola:'))
#prendo la parola inserita dall'utente

lunghezza_parola=int(len(parola))
#verifico quante lettere è lunga la parola
ci=0 
#contatore pper l'inizio della parola
cf=lunghezza_parola-1
#contatore per la fine della parola

palindroma=False 
#valore finale

while(ci<cf):
#finchè non sono nella stessa posizione verificano le lettere
    if(parola[ci]==parola[cf]):
#verifica l'uguaglianza delle lettere
        print('parola uguale in questa lettera', parola[ci])
        ci+=1 #incremento contatore
        cf-=1 #decremento contatore
        palindroma=True
    else:
        palindroma=False
        break

if(palindroma):
    print('la parola', parola, 'è palindroma')
else:
    print('la parola inserita non è palindroma')
