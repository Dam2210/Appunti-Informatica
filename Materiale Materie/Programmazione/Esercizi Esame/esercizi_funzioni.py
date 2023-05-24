a = [1, 4, 5, 7, 10, 5, 20, 3, 1]
b = input(str("inserisci una stringa per visualizzare il contrario:"))
stringa = input(str("inserisci una stringa per verificare se è palindroma:"))
c = ["cane", "gatto", "topo", "cammello", "ricchione"]
d = "abaa"
print("la lista è:", a)

def sommatrice(lista): #somma tutti gli elemnti della lista
    b = 0
    lun_list = len(lista)
    for i in range(lun_list):
        b += lista[i]
    return b

def moltiplicatrice(lista): #moltiplica tutti gli elementi della lista 
    b = 1
    lun_list = len(lista)
    for i in range(lun_list):
        b = b*lista[i]
    return b

def reverse(stringa): #ritorna un stringa scritta al contrario
    reverse = stringa[::-1]
    return reverse

def palindroma_ric(stringa): #verifica se una stringa è palindroma
    n = len(stringa)
    if n in (0, 1):
        return True
    else:
        if stringa[0] == stringa[-1]:
            return palindroma_ric(stringa[1:-1])
        else:
            return False

def lunghezza(var): #calcola la lunghezza di una stringa o una lista
    c = 0
    for x in var:
        c += 1
    return c

def istogramma(lista): #stampa il carattere * in base a ogni elemento intero della lista (es: 3 = ***)
    isto = "*"
    print("l'istogramma della lista", lista, "è:")
    print("")
    for x in lista:
        print(isto*x)
        print("")

def conta_char(lista): #conta quanti caratteri ci sono in ogni stringa contenuta in una lista di stringhe
    for x in lista:
        c = 0
        for i in x:
            c+=1
        print("la lunghezza della parola", x, "è:", c)

def apparizione(stringa): #conta quante volte una lettera appare nella stringa
    lista = []
    lun = len(stringa)
    for x in stringa:
        if x not in lista:
            lista.append(x)
    for x in lista:
        c = 0
        for i in range (lun):
            if x in stringa[i]:
                c += 1
        print("l'elemento", x, "è presente in", stringa, c, "volte")

def el_in_list(el, lista): #verifica se un elemento è presente nella lista
    trovato =  False
    if el in lista:
        trovato = True
    return trovato

def linguaggio_dei_furfanti():
    """
    In Svezia, i bambini giocano spesso utilizzando un linguaggio un po' particolare detto "rövarspråket", 
    che significa "linguaggio dei furfanti": consiste nel raddoppiare ogni consonante di una parola e inserire 
    una "o" nel mezzo. Ad esempio la parola "mangiare" diventa "momanongogiarore".
    Scrivi una funzione in grado di tradurre una parola o frase passata tramite input in "rövarspråket".
    Dopo aver tradotto una frase, il programma dovrà chiedere all'utente se intende tradurne un'altra, e in caso 
    di risposta positiva, dovrà attendere l'inserimento di una nuova parola da parte dell'utente.
    """
    check = str(input("vuoi tradurre una frase?(si/no):"))
    lista = []
    if check == "si":
        parola = str(input("inserisci la frase da tradurre in rövarspråket:"))
        lista.append(parola)
        tradotta = ""
        vocali = "aeiou"
        speciali =[" ", "?", ",", "!", ".", ";", '"', "'"]
        for x in parola:
            if x in vocali or x in speciali:
                tradotta += x
            else:
                tradotta = tradotta + x + "o" + x
        print("la frase tradotta è:", tradotta)
        linguaggio_dei_furfanti()


print("=======================================================")   
print("la somma dell'intera lista", a, "è:", sommatrice(a))
print("la moltiplicazione dell'intera lista", a, "è:", moltiplicatrice(a))
print("=======================================================") 
print("la stringa", b, "al contrario è:", reverse(b))
print("la stringa", stringa, "risulta palindroma?:", palindroma_ric(stringa))
print ("la lunghezza di", stringa, "è:", lunghezza(stringa))
print("=======================================================") 
istogramma(a)
print("=======================================================") 
conta_char(c)
apparizione(d)
print("la lista a è:", a)
var = int(input("quale elemento vuoi cercare nella lista a?:"))
print("l'elemento", var, "è nella lista", a,"?:", el_in_list(var, a))
print("=======================================================") 
linguaggio_dei_furfanti()


