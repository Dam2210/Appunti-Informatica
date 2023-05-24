"""
tramite la funzione sorted ordina la lista dal numero più piccolo al più grande.
"""
a = [7, 6, 5, 4, 3, 2, 1, 0]
a = sorted(a) #sorted ha costo nlog(n)
print(a)

print("---------------------------------------------")

"""
tramite la funzione sorted ordina le lettere della stringa in ordina lessicografico.
"""
b = 'ciao'
stringa = ''
b = sorted(b)
for x in b:
    stringa += x
b = stringa
print(b)

print("---------------------------------------------")

"""
tramite il sorted ordina una lista di stringhe in base alla lunghezza delle stringhe dalla più corta alla 
più lunga.
"""
def len_str(list):
    return len(list) 

c = ['Franco', 'Damiano', 'Andrea', 'Marco', 'Luca', 'Antonello', 'Mia']
c = sorted(c, key = len_str) #sorted ha costo nlog(n)
print(c)

print("---------------------------------------------")

"""
tramite il sorted ordina una lista di stringhe in base alla lunghezza delle stringhe dalla più lunga alla 
più corta.
"""
def len_str(list):
    return len(list) 

c = ['Franco', 'Damiano', 'Andrea', 'Marco', 'Luca', 'Antonello', 'Mia']
c = sorted(c, key = len_str, reverse = True) #con la variabile reverse = True la funzione sorted ordina dalla più lunga alla più corta.
print(c)

print("---------------------------------------------")

"""
date tre stringhe a,b,c restituire la lista ordinata dei DIVERSI caratteri che compongono le stringhe stesse
suggerimenti:
- usare i set
"""
def set1(a, b, c):
    s = set(a)|set(b)|set(c)
    return sorted(s)
    
a = 'geova'
b = 'figa'
c = 'tumadre'
abc = set1(a, b, c)
print(abc)

print("---------------------------------------------")

"""
ordinare la lista di tuple in base al primo elemento di ogni tupla
"""
def ordina(lista):
    return lista[0]

list1 = [(7, 3, 4), (0, 9, 5), (6, 8, 2), (11, 3, 0), (10, 9, 8)]
list1 = sorted(list1, key = ordina) #reverse = True ordina al contrario.
print(list1)

print("---------------------------------------------")

"""
ordinare la lista di tuple in base alla lunghezza di ogni tupla e in ordine crescente confrontando il primo elemento
di ogni tupla.
"""
def ordina1(lista):
   return lista[0] 

def ordina2(lista):
    return len(lista) 

list2 = [(7, 3, 6, 8, 9, 10), (100, 0), (6, 8, 2), (11, 3, 0, 12), (10, 9, 8, 5), (0, 100)]
list2 = sorted(list2, key = ordina1) #prima ordino in base al primo elemnto della tupla
print(list2)
list2 = sorted(list2, key = ordina2) #dopo ordino in base alla lunghezza della tupla.
print(list2)