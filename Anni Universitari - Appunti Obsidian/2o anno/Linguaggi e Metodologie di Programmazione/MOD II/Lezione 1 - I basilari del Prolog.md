## Elementi del Prolog

- Termini
- Predicati
- Clausule (Fatti e Regole)
- Programma logico

## Termini

- Automi: nomi che iniziano con la lettera MINUSCOLA, sequenze di caratteri tra '', numeri preceduti da caratteri
	- andrea
	- 'Corso di Prolog'
	- clp8

- Numeri
	- 12345

- Variabili: nomi che iniziano con la lettera MAIUSCOLA o con _
	- Tizio
	- $\_andrea$
	- _

- Termini composti
	- somma$(1, 2, X)$ 
	- $1+2$

## Predicati

- Espressi tramite la notazione $f(t_1,...,t_n)$

- $f$ è un atomo che prende il nome di funtore

- $t_1,...,t_n$ sono gli argomenti e sono dei termini (predicato $f$ con $n$ argomenti, ha arità $n$)

## Clausole (Fatti e Regole)

- Le clausole: fatti e regole
	- i fatti sono regole senza corpo

- Fatti:
	- parent$(ben,\ jim)$
	- friend$(luke, \ daisy)$

- Regole:
	- grandparent$(X, Y)$:-
	- parent$(X, Z)$,
	- parent$(Z,Y)$.

## Regole

- Head :- Body . significa che affinché la Head sia vera deve essere vero il Body (e quindi i predicati che lo compongono)

- Nel Body ci sono 1 o più predicati separati da , (and) o da ; (or)

- Ogni regola termina con .

## Fatti

- Un fatto è un predicato seguito da .

- Un fatto può essere composto da più termini
	- amico(fratello(alice, X), bob).

## Programma logico

- Insieme di regole/fatti

- Risponde alle query con true o false e assegna dei valori alle variabili

>Esempio: Famigliadonnie
>parent(annie, bill).
>parent(annie, charlie).
>parent(bill, donnie).
>grandparent(X,Z):-
>		- parent(X,Z),
>		- parent(Z,Y).
>
>Query:
>	?-parent(annie,X).
>Risposta:
>	true
>Query:
>	?-parent(annie,X).
>Risposta:
>	X=bill
>	(premo ; )
>	X=charlie
>	(premo ; )
>	false
>Query:
>	?-parent(X, Y).
>Risposta:
>	X=annie, Y=bill
>	(premo ; )
>	X=bill, Y=donnie
>	(premo ; )
>	false

## Esecuzione del programma

- Prolog cerca nel proprio database di regole e fatti, quelli che soddisfano la nostra query, istanziando le variabili.

- Ogni variabile, una volta istanziata (unificata), non può assumere un secondo valore (a differenza dei linguaggi classici di programmazione, come Java, C, C++, ecc)

>Dati i fatti: 
>- parent(pam,bob).
>- parent(bob,tom).
>- parent(tom,ann).
>- parent(bob,jerry).
>
>- female(pam).
>- male(bob).
>- male(tom).
>- female(ann).
>- male(jerry).
>
>E le regole:
>father(X,Y):-
>	male(X),
>	parent(X,Y).
>	
>mother(X,Y):-
>	female(X),
>	parent(X,Y).
>	
>Query:
>?- mother(ann,X).

Che risposta ho alle seguenti interrogazioni?
- ?- mother(X,Y).
- ?- father(X,Y).
- ?- mother(X,ann).
- ?- father(X,ann).
- ?- mother(ann, X).

## L'interprete Prolog

- https://swish.swi-prolog.org

## Comadi Utili

- edit.
	- apre l'editor per modificare/aggiungere fatti e regole al file in esame

- consult('nome_file').
	- carica un file con i suoi dati

- reconsult('nome_file').
	- ricarica il file con i suoi dati

- trace/notrace.
	- abilita/disabilita la stampa di tutti i passaggi intermedi (molto utile per seguire lo svolgersi del programma)

>[!info]- Esercizio in classe delle parole crociate:
>schema(A1,A2,A3,A4,A5,
> 	B1,B3,B5,
> 	C1,C2,C3,C4,C5,C6,
> 	D1,D5):-
> 	word(A1,A2,A3,A4,A5),
> 	word(C1,C2,C3,C4,C5,C6),
> 	word(A1,B1,C1,D1),
> 	word(A3,B3,C3),
> 	word(A5,B5,C5,D5).
> 	
> 	word(d,o,g).
> 	word(r,u,n).
> 	word(t,o,p).
> 	word(m,e,s,s).
> 	word(f,o,u,r).
> 	word(l,o,s,t).
> 	word(f,i,v,e).
> 	word(u,n,i,t).
> 	word(b,a,k,e,r).
> 	word(f,o,r,u,m).
> 	word(g,r,e,e,n).
> 	word(p,r,o,l,o,g).
> 	word(v,a,n,i,s,h).
> 	word(w,o,n,d,e,r).
> 	word(y,e,l,l,o,w).

## Prolog

- E' un linguaggio di programmazione logica
- E' un linguaggio dichiarativo
- Si basa su una restrizione delle logiche del primo ordine (Horn Clauses)

## Linguaggio dichiarativo

- Indica "cosa" serve per arrivare alla soluzione desiderata, ma non il "come", cioè l'implementazione utilizzata
- Si contrappone ai linguaggi imperativi e procedurali (Java, C, C++, ecc)


