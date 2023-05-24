"""
Sia a una lista che contiene k elementi di tipo int, k elementi di tipo float e k
elementi di tipo str. Si scriva un frammento di codice Python che stampi k
righe tali che la prima contienga il primo int seguito dalla prima str seguita
dal primo float; la seconda riga mostri il secondo int, la seconda str e il
secondo float… e così via fino alla k-esima riga che elenchi l’ultimo int,
l’ultima str e l’ultimo float.
"""
def matrice(lista):
    lista_int = []
    lista_str = []
    lista_float =[]
    k = 0
    for x in lista: #costa lineare in n
        if type(x) == int:
            lista_int.append(x)
            k += 1
        if type(x) == str:
            lista_str.append(x)
        if type(x) == float:
            lista_float.append(x)
    for i in range(k): #costante in quanto k è una costante
        print(lista_int[i], lista_str[i], lista_float[i])

    #il costo computazionale della funzione e lineare in n (n = lunghezza di lista)
    
lista = ['ciao', 9, 0.1, 0.5, 6, 'cane']
matrice(lista)



        