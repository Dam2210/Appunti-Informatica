# -*- coding: utf-8 -*-
"""
Created on Sun Nov 21 13:28:51 2021

@author: damia
"""

def palidrome_ricorsiva(a,c,lungh):
    #c=0
    palindroma=True
    if (a[c]==a[lungh]) and c<lungh:
            # print(f'Lettera uguale beccata : {a[c]}')
            # c=c+1
            # lungh=lungh-1
            # palindroma=True
        palindroma = True
        palidrome_ricorsiva(a,c=c+1,lungh=lungh-1)
    else:
        palindroma=False

    return palindroma
    # if(palindroma):
    #     print(f'La parola {a} è palindroma')
    # else:
    #     print(f'La parola {a} non è palindroma')
a = str(input('Inserisci stringa : '))
len = len(a)-1
c=0
ris = palidrome_ricorsiva(a,c,len)
print(ris)
    
    
    