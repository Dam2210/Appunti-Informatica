def deep_copy( t ):
    '''
    Copia la lista annidata e tutti i suoi elementi
    
    #t è una lista annidata e la funzione la copia completamente
    a = [ ]
    for x in t:
        if type(x) in (float, int): # x è un numero
            a.append(x)
        elif type(x) == list: #x è una lista 
            a.append(deep_copy(x)) #uso la ricorsione
    return a
'''
    a = [ ]
    for x in t:
        if type(x) == list:  # x è una lista 
            a.append(deep_copy(x)) #uso la ricorsione
        else: 
            a.append(x) 
    return a


t = [3.14, [2,3], [2.71, [7, 5]], 9, [12, [ 4, 'ciao']] ] 
print("la lista è:", t)
b = deep_copy(t)
print("la copia della lista è:", b)

print("l'id della lista data è:", id(t)) 
#l'id è il codice identificativo dell'oggetto
print("l'id della lista copiata è:", id(b))


if id(t) != id(b): #se gli id sono diversi
    print(True) #stampa vero
else: #altrimenti
    print(False) #stampa falso
