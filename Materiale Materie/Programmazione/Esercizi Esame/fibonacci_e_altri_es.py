"""
Nella serie di Fibonacci, ciascun numero della serie è la somma dei due numeri nella serie che lo precedono, 
ad esempio:

1, 1, 2, 3, 5, 8, 13 (...)

Scrivi una funzione ricorsiva che restituisce in output i numeri della sequenza di Fibonacci, 
entro una soglia specifica impostata dall'utente.
"""

def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

limite = int(input("Inserisci il numero di valori della serie che desideri vedere: "))

for num in range(1, limite+1):
    print(fibonacci(num))

"""
Calcolare la somma dei primi 500 numeri
naturali (da 0 a 500 escluso)
"""
def calcola_somma(num):
    a = []
    ris = 0
    for x in range(num):
        a.append(x)
        
    print(a)
    
    for i in range(len(a)):
        ris = ris + a[i]
    return ris

num = int(input("inserisci il numero per calcolare la somma:"))
print(calcola_somma(num))

"""
ALTERNATIVA:

n = 0
    for i in range(0,500):
    n += i
    n
"""

"""
Data la stringa 'abcdefghi', scrivere
un programma che analizzi la stringa e
stampi a video:
Lettera 1: a
Lettera 2: b
...
"""

def stampa_lett(stringa):
    lista = []
    for x in stringa:
        lista.append(x)
        print(lista)
    for i in range(len(lista)):
        print("lettera ", i, ":", lista[i])

a = 'abcdefghi'
stampa_lett(a)

"""
Scrivere un programma che stampi la
lunghezza delle stringhe fornite dall'utente,
finchè l'utente non inserisce la stringa
'exit'
"""

def lunghezza_stringa():
    stringa = str(input("inserisci la stringa di cui vuoi la lunghezza (per uscire digita: exit):"))
    if(stringa != 'exit'):
        c = 0
        for x in stringa:
            c += 1
        print(c)
        lunghezza_stringa()
    else:
        print("fine funzione...")
   

lunghezza_stringa()