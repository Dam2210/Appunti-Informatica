def ordina(elemento):
    return elemento[1]

def sort_by_point(a):
    print(a)
    d = {}
    c = 0
    ind = 1
    for x in a:
        x = str(x) #trasformo ogni numero in stringa
        for i in range(len(x)):
            if(x[i-ind] == '.'):
                ind += 1
                if(x[i] != '.'):
                    c += 1 #conto le cifre dopo la virgola
        if x is float:
            x = float(x) #trasformo il numero da stringa a float se è di tipo float
        if x is int:
            x = int(x) #trasformo il numero da stringa a int se è di tipo int
        d[x] = c
        c = 0
        ind = 0
    print('il dizionario è:', d)
    lista=[] 
    for k in d:
        c = (k , d[k])
        lista.append(c)
    print('la lista di tuple associata al dizionario è:', lista)
    lista = sorted(lista, key = ordina) #costo del sorted è nlog(n)
    for x in lista:
        print(x[0])
#il costo della funzione sort_by_point è O(n*m)
                

a = [3.14, 0.0001, 52.612, 2.718, 5.0, 123, 1000.0000001]
sort_by_point(a)