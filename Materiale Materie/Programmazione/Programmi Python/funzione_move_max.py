def move_max(a):
    '''
    precondizione: a è una lista di numeri
    La funzione move_max sposta il massimo di a in
    fondo alla lista, gli altri elementi 
    occuperanno le posizioni precedenti
    '''
    a_copy = a[:] 
    #operazione di clonazione della lista a
    #(a_copy = a) - modifica il nome di a (alias) e non crea una copia della lista
    n = len(a_copy)
    for i in range(n-1):
    #confrontiamo l'elemento in posizione i e i + 1
        if a_copy[i] > a_copy[i+1]:
            a_copy[i], a_copy[i+1] = (a_copy[i+1], a_copy[i])
            #facciamo uno slice di variabili, quella in posizione i
            #passa in posizione i + 1 e viceversa
    return a_copy

lista = [3, 81, 4, 17, 0, 9, 11]
print("la lista è:", lista)
lista_2 = move_max(lista)
print("la lista modificata è:", lista_2)
