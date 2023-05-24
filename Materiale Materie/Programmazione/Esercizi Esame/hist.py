"""
Dati 3 segmenti adiacenti ed n float si vuole calcolare quanti degli 
n float ricadono in ogni segmento. I segmenti sono rappresentati da 2 float h0 e h1 
che definiscono i segmenti: (-∞, h0), [h0, h1), [h1, ∞). Si progetti una funzione che 
prenda in input la descrizione di 3 segmenti (h0 e h1) e un numero variabile di float 
e restituisca una terna di interi che rappresenta il numero di float che ricade in ciascuno dei 3 segmenti
"""
def hist(h0, h1, *numbers):
    c0, c1, c2 = 0, 0, 0
    for x in numbers:
        if x < h0:
            c0 += 1
        elif x >= h0 and x < h1:
            c1 += 1
        elif x >= h1:
            c2 += 1
    print(c0, c1, c2)

hist(-7, 5, 3, 10, -4, 5, -12, 6, 0)


