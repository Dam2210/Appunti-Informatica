def ordina(elemento):
    return elemento[1]

def sort_by_occurences(stringa):

    '''
    dizionario per contare le occorrenze
    '''
    d = {}
    for elemento in stringa: #tutto questo for ha costo n in quanto la verifica delle chiavi nel dizionario ha costo costante O(1).
        if elemento not in d:
            d[elemento] = 1
        else:
            d[elemento] += 1
            
    '''
    creo una lista di tuple contenti le chiavi con corrispondenti valori e ordino in
    base alla funzione ordina che prende in considerazione il secondo valore della tupla
    '''
    print('il dizionario è:', d)
    lista=[] 
    for k in d:
        c = (k , d[k])
        lista.append(c) #lista di tuple
    print('la lista di tuple associata al dizionario è:', lista)
    lista = sorted(lista, key = ordina) #costo del sorted è nlog(n)
    print('la lista ordinata è:', lista)
    stringa2 = ''
    for x in lista:
        stringa2 += x[0]
    
    return stringa2
            
a = ')-:))-'
a = sort_by_occurences(a)
print('la stringa ordinata in base alle occorrenze è:', a)