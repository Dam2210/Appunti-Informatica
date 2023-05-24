a = [3, 81, 4, 17, 0, 9, 11]
print("la lista è:", a)
n = len(a) #metto in una variabile la lunghezza della lista

for i in range(n-1):
    #confrontiamo l'elemento in posizione i e i + 1
    if a[i] > a[i+1]:
        a[i], a[i+1] = (a[i+1], a[i])
        #facciamo uno slice di variabili, quella in posizione i
        #passa in posizione i + 1 e viceversa

print("la lista è diventata:", a)