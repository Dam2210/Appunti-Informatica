# BucketSort
Algoritmo di ordinamento per ordinare n record con chiavi intere $[1,k]$

**Esempio**: ordinare n record con campi:
- nome, cognome, anno di nascita, matricola...
Si potrebbe voler ordinare per matricola o per anno di nascita

**Input** del problema:
- n record mantenuti in un array
- ogni elemento dell'array è un record con:
	- campo chiave (rispetto al quale ordinare)
	- altri campi associati alla chiave (informazione satellite)

- Basta mantenere un array di liste, anzichè di contatori, ed operare come per [[Capitolo 4.3 - Lower bound al problema di ordinamento e Algoritmi Lineari#IntegerSort|IntegerSort]]
- La lista $Y[i]$ conterrà gli elementi con chiave uguale a i
- Concatenare poi le liste

Tempo $O(n+k)$ come per IntegerSort 

**Esempio**
![[img62.png|center|200]]
![[img63.png|center|200]]
![[img64.png|center|200]]
... e così via...
![[img65.png|center|200]]
fino a...
![[img66.png|center|400]]

## Pseudocodice

![[img67.png|center|400]]

## Stabilità

>**Def.**
>Un algoritmo è **stabile** se preserva l'ordine iniziale tra elementi con la stessa chiave

Il BucketSort è stabile?

> Il BucketSort è stabile se si appendono agli elementi di X in coda alla opportuna lista $Y[i]$

# RadixSort

Ordina n interi con valori in $[1,k]$
Rappresentiamo gli elementi in **base b**, ed eseguiamo una serie di BucketSort
Partiamo dalla cifra meno significativa verso quella più significativa:
- Ordiniamo per l'i-esima cifra con una passata di BucketSort (stabile)
- i-esima cifra è la chiave, il numero info satellite

**Esempio**

![[img68.png|center|500]]

## Correttezza
- Se x e y hanno una diversa t-esima cifra, la t-esima passata di BucketSort li ordina
- Se x e y hanno la stessa t-esima cifra, la prorpeità di stabilità del BucketSort li mantiene ordinati correttamente
Quindi possiamo dire che, dopo la t-esima passata di BucketSort, i numeri sono correttamente ordinati rispetto alle t cifre meno significative

## Tempo di esecuzione

$O(log_bk)$ passate di BucketSort
Ciascuna passata richiede tempo $O(n+b)$
Quindi:
$$O((n+b)log_bk)$$
Se $b=\Theta(n)$, si ha $$O(nlog_nk)=O\left[n\frac{log(k)}{log(n)}\right]$$

Tempo lineare se $k=O(n^c)$ con c costante.