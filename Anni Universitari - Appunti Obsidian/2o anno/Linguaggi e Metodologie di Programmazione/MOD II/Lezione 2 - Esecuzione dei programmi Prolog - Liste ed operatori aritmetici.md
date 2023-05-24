
![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine5.png]]

## Esecuzione programma

- Analizza i fatti/regole dall'alto verso il basso quindi è importante l'ordine in cui vengono scritti
- Utilizzo di BackTracking per tornare indietro a prima che una variabile fosse unificata o che una certa regola fosse esplorata.
- Utilizzo della ricorsione per chiamare le altre regole.
- Per avere altre risposte, e quindi forzare il backtraking anche se il programma ne ha già trovata una che funziona, basta premere ; 

## "Letture" dei programmi Prolog

- Il mondo dei SE può essere letto in maniera:
	- Dichiarativa: I problemi sono risolubili attraverso la scrittura di un insieme di regole
	- Procedurale: I problemi sono risolubili attraverso la scrittura di sequenze di istruzioni.

### "Lettura" Dichiarativa del Prolog

E' la lettura classica (e più corretta):

- Una clausola con variabili come:
	- $grandparent(X,Y):-$
		- $parent(X,Z),$
		- $parent(Z,Y).$

- Viene letta:
	- Per ogni X e Y e Z,
		 - $grandparent(X,Y)$ è vero se
			 - $parent(X,Y)$ è vero e
			 - $parent(Z,Y)$ è vero

- Una query come:
	- $?-grandparent(X,mario)$.

- Viene letta come:
	- Esiste un X tale che $grandparent(X,mario)$ è vero?

### "Lettura" Procedurale del Prolog

E' una lettura necessaria:

- Una clausula con variabili come:
	- $grandparent(X,Y):-$
		- $parent(X,Z),$
		- $parent(Z,Y).$

- Può essere anche letta:
	- Per qualsiasi valore delle variabili X e Y e Z,
		- Per soddisfare il goal $grandparent(X,Y)$ soddisfa prima il goal $parent(Z,Y)$.

>[!danger]- Attenzione:
>Le variabili NON variano valore durante il soddisfamento del goal.

- Una query come:
	- $?-grandparent(X,mario)$.

- Viene letta come:
	- Soddisfare il goal $grandparent(X,mario)$ trovando il valore della variabile X?

>[!note]- Osservazioni:
>- Importanza dell'ordine delle clausule e nelle clausule.
>
>	- $path(X,Y):- path(X,Z), path(Z,Y).$
>	- $path(X,Y):-edge(X,Y).$
>
>	Genera un loop infinito!!!

## Liste

- In prolog le liste sono molto utilizzate
- Lista: sequenza di vari elementi (anche ripetuti), che possono essere a loro volta delle liste

- Es: $[primo, secondo, [primo2, secondo2]]$.
	- Lista composta da tre elementi
	- Il terzo elemento è a sua volta una lista

- La lista può essere vuota (caso molto importante e utilizzato)

- Ogni lista è composta da due parti:
	- Head: è il primo elemento
	- Tail: è il resto della lista (a sua volta una lista)

- Le liste possono essere rappresentate in due modi:
	- $[a,b,c,d]$
	- $.(a,.(b,.(c,.(d,[]))))$

- Per estrarre la Testa di una lista si usa la notazione:
	- $[H \ | \ T]$, dove H èla testa e T è la lista rimanente senza il primo elemento

- Si possono estrearre più elementi contemporaneamente:
	- $[H1, \ H2  \ | \ T]$ 
	- H1 e H2 sono il primo e il secondo elemento.
	- T è la lista rimanente (la lista di partenza meno i primi due elementi)

## Operatori su liste

- Restituisce true se Elem si trova nella lista, può essere usato in vari modi:
	- $member(b, [a, b, c, d]$). $\rightarrow$ true
	- $member(e,[a,b,c,d])$. $\rightarrow$ false
	- $member(X,[a,b,c,d])$. $\rightarrow$ X = a; X = b; ...
	- $member(c,[a,b,c,d])$. $\rightarrow$ X = c

- $member(?Elem, ?List)$

- Possibile implementazione:
	- $member2(X,[X \ | \_ ]).$
	-  $member2(X,[\_ | \ T]):-$
		- $member2(X,T).$

- $append(?List1, ?List2, ?List1AndList2)$
	- $List1AndList2$ è la concatenazione di $List1$ e $List2$. Vari utilizzi:
		- $append([a,b],[c,d],X). \rightarrow X=[a,b,c,d]$
		- $append([a,b],X,[a,b,c,d]). \rightarrow X=[c,d]$
		- $append([a,b],[X,d],[a,b,c,d]). \rightarrow X=c$
		- $append(X,Y,[a,b,c,d]).$

>[!info]- Esercizio:
>- Scrivere una possibile implementazione della $append$
>
>- Scrivere la regola per invertire tutti gli elementi di una lista, in modo da avere:
>	$?-([a,b,c,d,e,f],X).$
>	$X=[f,e,d,c,b,a]$
>	


## Operatori

- In Prolog è possibile definire nuovi operatori, ma ne esistono già alcuni definiti (esempio gli operatori aritmetici)

- $1*2+3*4$ ha i due operatori $+$ e $*$ 
- La scrittura in Prolog sarebbe:
	- $+(*(1,2),*(3,4))$ 

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine6.png]]

## Definire un operatore

- Ogni operatore ha una sua priorità
- $a+b*c$ come deve essere letto?
	- $+(a,*(b,c)?$
	- $*(+(a,b),c)?$

- In matematica $*$ lega di più di $+$, e quindi $+$ ha priorità più alta di $*$

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine7.png]]


## Aritmetica

- Prolog può essere usato anche per fare dei calcoli con alcune limitazioni.

- Come detto gli operatori aritmetici sono già definiti

- $A=B+C$  assegna ad $A$ non il risultato della somma ma assegna proprio $B+C$

- Per eseguire l'operazione bisogna usare $is$

- $A$ is $5+6$ fa si che in A venga messo il valore $11$

- $B \ is \ 8+2*3$ mette in B 14 (rispetta la priorità)

- A destra di $is$ non possono esserci variabili non ancora istanziate

- $A=3, B \ is \ A+4$
	- $A=3$ e $B=7$

- $A=3$, $B \ is \ A+C, C=4$
	- ERROR: $is/2$: Arguments are not sufficiently instantiated

## Operatori per i calcoli

- Gli operatori direttamente utilizzabili sono:
	- $+$
	- $-$
	- $*$
	- /
	- ** (elevamento a potenza)
	- // (divisione intera)
	- mod (modulo, resto della divisione)
	- <, >, >=, =<, =, \= (sono confronti booleani utili come predicati, ma non utilizzabili a sinistra di is)
	- $number(X)$ (vero se X è un numero, falso negli altri casi)

>Per gli esercizi vedere le ultime slide della Lezione 2.