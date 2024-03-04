
## Strutture Dati

- Le strutture dati, anche complesse, sono alla base dei vari linguaggi di programmazione.
- In Prolog è possibile creare ed utilizzarle in modo palese.

- Un database può essere rappresentato in Prolog come un elenco di fatti
- Per comprendere come creare/usare le strutture dati in Prolog useremo i seguenti esempi:
	- Famiglia
	- Automa non deterministico 
	- Problema delle 8 Regine

## Famiglia:

- Una famiglia può essere rappresentata da un fatto, family, con 3 argomenti:
	- Padre
	- Madre
	- Figli (tramite una lista)

- Gli elementi della famiglia sono delle persone (person), rappresentati a sua volta da dei termini complessi formati da 4 elementi: nome, cognome, data di nascita e salario.

- Rappresentazione della famiglia Smith:
	- family(
		person(bob, smith, date(7, may, 1968), 30000),
		person(ann, smith, date(18, july, 1970), 32000),
		$[$person(dave, smith, date(1, june, 1984), 0),
		person(edna, smith, date(25, may, 1990), 0 )$]$).

- Possiamo effettuare varie query, basandoci non solo sui valori ma anche sulla struttura stessa

- family(person(_ , fox,  _ , _ ), _ , _ ). si riferisce alla famiglia fox, usando solo il cognome del padre e nessun altra informazione

- Esiste un altro modo per riferirsi alla famiglia fox?

- family(_ , _ , $[$ _ , _ , _ $]$). Indica una famiglia con 3 figli

- Come si può indicare una famiglia con almeno 3 figli?
	- Creiamo ora delle regole più "generiche" che però  si appoggiano sempre al termine family

## Regole per family

husband(X):-
	family(X, _ , _ ).

wife(X):-
	family( __ , X, __ ).

 child(X):-
	 family(__ , __ , Children ).
	member(X, Children).

exist(X):-
	husband(X)
	;
	wife(X)
	;
	child(X)

salary(person(_ , _ , _ , S), S).

dateOfBirth(person(_ , _ , Date, _ ), Date).

## Possibili query

- ?- exists(person(mario, rossi, _ , _ )).

 - ?- exists(person(Name, Surname, _ , _ )).

- ?- child(X),
	dateOfBirth(X, date(_ , _ , Y )),
	Y > 30000.

## Automa non deterministico
	
	![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine8.png|center|500]]

final(s3).

trans(s1, a, s1).
trans(s1, a, s2).
trans(s1, b, s1).
trans(s2, b, s3).
trans(s3, b, s2).
trans(s1, a, s4).

silent(s2, s4).
silent(s3, s1).

accepts(State, $[ \ ]$):-
	final(State).

accepts(State, $[X|Rest]$):-
	trans(State, X, Stete1),
	accepts(Stete1, Rest).

accepts(Stete, Rest):-
	silent(State, State1),
	accepts(State1, Rest).

## Query Automa

- ?- accepts(s1, $[a,a,a,b]$).
	- true

- ?- accepts(S, $[a,b]$).
	- S=s1;
	- S=s3;

- ?- accepts(s1, $[X1,X2,X3]$).
	- X1=a     X2=a     X3=b
	- ...

- ?- String=$[ \_ \ , \_ \ , \_]$ , accepts(s1, String).
	- String=$[a,a,b]$;
	- ...

## Problema delle 8 regine

- Posizionare 8 regine su di una scacchiera vuota in modo che nessuna possa mangiare o essere mangiata da un'altra.

- Esistono varie soluzioni in prolog, qui ne viene presentata una semplice con il minimo numero di variabili

## 8 Regine

solution($[ \ ]$).

solution($[X/Y|Others]$):-         %First queen at X/Y, other queens at Others
	solution(Others),
	member(Y, $[1,2,3,4,5,6,7,8]$),
	noattack(X/Y, Others).       %First queen does not attack others

noattack( _ , $[ \ ]$).   %Nothing to attack

noattack(X/Y, $[X1/Y1|Others]$):-
	Y=\\=Y1,       %Different Y-coordinates
	Y1-Y=\\=X1-X     %Different diagonals
	Y1-Y=\\X-X1,
	noattack(X/Y, Others).

%A solution template

template($[1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]$).

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine9.png|center|500]]![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine10.png|center|500]]![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine11.png|center|500]]
## Operatori 

- In Prolog è possibile definire nuovi operatori, ma ne esitono già alcuni definiti (esempio gli operatori aritmetici)

- $1 * 2+3 * 4$ ha i due operatori $+$ e $\cdot$ 
- la scrittura in Prolog sarebbe:
	- - $+(*(1,2), *(3,4))$ 

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine12.png|center|500]]

## Definire un operatore 

- Ogni operatore ha una sua priorità 
- $a+b* c$ come deve essere letto?
	- - $+(a, *(b,c))$?
	- - $*(+(a,b),c)$?
- Nel senso comune trasmessoci, $*$ lega di più di $+$,

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine13.png|center|500]]

Codificare la priorità: l'albero delle interpretazioni ha priorità decrescenti
$+$ ha priorità 500
$*$ ha priorità 400

(e quindi $+$ ha priorità più alta di $*$)

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine14.png|center|500]]


:- op(Priorità, Tipo, Operatore).

- Priorità è un numero tra 0 e 1200

- Tipo:
	- - infisso: xfx, xfy, yfx
	- - prefisso: fx, fy
	- - postfisso: xf, fy

- Operatore: il nome/simbolo dell'operatore
- Il tipo serve ad indicare anche la precedenza degli operatori
	- - x: la sua priorità deve essere minore di quella dell'operatore
	- - y: la sua priorità deve essere minore o uguale a quella dell'operatore

- :- op(700, yfx, somma).
- Qual è l'albero risultante di :
	- 9 somma 5 somma 7?

- :- op(700, yfx, somma).
- 9 somma 5 somma 7

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine15.png|center|500]]

- Quello a sinistra è corretto, perchè?

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine16.png|center|500]]![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine17.png|center|500]]
