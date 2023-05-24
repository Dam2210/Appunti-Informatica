
## Definizione di Macchina di Turing

- La macchina di Turing utilizza 3 nastri: sui primi due nastri, prima che la mcchina inizi ad operare, vengono scritti (dall'utente) i due numeri da sommare, sul terzo, inizialmente vuoto, la macchina scrive il risultato.

- Consideriamo macchine di Turing che utilizzano un solo nastro:
	- E' un'unità di controllo che, ad ogni istante, può trovarsi in uno stato interno appartenente ad un certo insieme Q che contiene, fra gli altri, lo stato particolare $q_0$ che fa partire la computazione e un sottoinsieme $Q_f$ di dtati che fanno terminare la computazione.
	- Un nastro suddivisio in un infinito numero di celle, ciascuna delle quali, ad ogni istante, può essere vuota o contenere un simbolo appartenente ad un alfabeto $\Sigma$, e sul quale nastro si muove una testina di lettura/scrittura.
	- Ad ogni istante, viene eseguita una quintupla scelta in un insieme $P$ di quintuple.

- Come funziona una macchina di Turing?
	- Quando l'unità di controllo si trova nello stato $q_0$, la testina legge il simbolo contenuto nella cella che sta scandendo, cerca una quintupla i cui primi due elementi sono $q_0$ e il simbolo letto dalla testina (che può essere anche il simbolo blank $\square$) e, se trova una tale quintupla, la esegue.
		- Se non la trova non compie alcuna azione e la computazione termina.
	- Eseguire una quintupla significa eseuire le tre azioni in essa indicate:
		- sovrascrivere il simbolo nella cella scandita dalla testina con il simbolo indicato nella quintupla.
		- cambiare (eventualmente) stato interno
			- eventualmente, ossia, a meno che nella quintupla non sia indicato di rimanere nel medesimo stato in cui ci si trovava prima della sua esecuzione.
		- muovere (eventualmente) la testina
			- eventualmente, ossia a meno che nella quintupla sia indicato "ferma".
	- Eseguita la prima quintupla, si cerca un'altra quintupla da eseguire (i cui primi due elementi sono lo stato in cui si trova la macchina e il simbolo letto dalla testina) e così via, fino a quando nessuna quintupla può essere eseguita.

## Esempio di macchina di Turing

- Consideriamo una macchina di Turing ad un nastro, $T_{parità}$ , definita sull'alfabeto:
	- $\Sigma = \{0,1,p,d\}$ e sull'insieme di stati $Q=\{q_0,q_p,q_d,q_f\}$
	con lo stato iniziale $q_0$ e stato finale $q_f$ il cui insieme delle quintuple è:

$$\begin{align}
P=\{ \ &<q_0,0,\square,q_p,destra>, \ <q_0,1,\square,q_d,destra>,\\
&<q_p,0,\square,q_p,destra>, \ <q_d,0,\square,q_d,destra>, \\
&<q_p,1,\square,q_d,destra>, \ <q_d,1,\square,q_p,destra>, \\
&<q_p,\square,p,q_f,fermo>, \ <q_d,\square,d,q_f,fermo> \ \}
\end{align}$$

- La macchina $T_{parità}$ scandisce la sequenza di caratteri scritta sul suo nastro, cancellandoli via via che vengono scanditi, e verificando se tale sequenza contiene un numero pari o un numero dispari di '$1$': al termine della scansione, nel primo caso scrive 'p' e termina, nel secondo caso scrive 'd' e termina.

- Vediamo ora la macchina $T_parità$ in azione:
	- poniamo la macchina nello stato $q_0$
	- scriviamo una sequenza di caratteri sul nastro - che era precedentemente vuoto
	- posizioniamo la testina sul carattere più a sinistra fra quelli scritti sul nastro e vediamo cosa succede

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine5.png | center]]

Osserviamo che $P$ contiene la quintupla $<q_0,1,\square,q_d,destra>$ e che esse può essere eseguita.

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine6.png | center]]
![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine7.png | center]]

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine8.png|center]]
![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine9.png|center]]

- Naturalmente, sul natro di $T_{parità}$ possiamo scrivere ciò che vogliamo:
	- possiamo per esempio scrivere la sequenza di caratteri $p010$ e vedere cosa succede facendo partire questa nuova computazione:

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine10.png|center]]

- $P$ non contiene alcuna quintupla che inizia con la coppia $(q_0,p)$ quindi nessuna quintupla può essere eseguita

In sintesi una macchina di Turing ad un nastro è completamente caratterizzata dai cinque elementi:
- $\Sigma$, ossia, un insieme finito di caratteri che prende il nome di alfabeto
- $Q$, ossia, un insieme finito di stati interni
- uno stato interno particolare (indicato come $q_0$) chiamato stato iniziale
- un sottoinsieme $Q_f$ di $Q$ di stati finali
- un insieme $P\subseteq Q\times \Sigma \times \Sigma \times Q \times \{sinistra,fermo,destra\}$ di quintuple non ambiguo, cioè, che non contiene coppie di quintuple che hanno uguali i primi due elementi.
	- $P$ è una funzione: $P:Q\times \Sigma \rightarrow \Sigma \times Q \times \{sinistra,fermo,destra\}$ 

Possiamo quindi dire che una macchina di Turing è una quintupla $<\Sigma,Q,q_0,Q_f,P>$  e dare per assodata l'esistenza di unità di controllo e nastro.

## Definizione di macchina di Turing

- E che dire di una macchina di Turing a  più nastri?
	- E' quasi la stessa cosa.
- Una macchina di Turing a $k$ nastri è completamente caratterizzata da:
	- un alfabeto $\Sigma$, ossia, un insieme finito di caratteri
	- un insieme finito $Q$ di stati interni
	- uno stato interno iniziale
	- un sottoinsieme $Q_F$ di $Q$ di stati finali
	- un insieme $P$ di quintuple, ove in questo caso una quintupla ha la forma:
		- $<q_1, (a_1,a_2,...,a_k),(b_1,b_2,...;b_k),q_2,(m_1,m_2,...,m_k)>$
			- $(a_1,a_2,...,a_k)$ sono i caratteri che devono essere letti sui $k$ nastri
				- $a_1$ è il carattere che deve essere letto sul nastro 1, $a_2$ è il carattere che deve essere letto sul nastro 2, ...
			- $(b_1,b_2,...,b_k)$ sono i caratteri che devono essere scritti sui $k$ nastri (sovrascrivendo $(a_1,a_2,...,a_k)$)
				- $b_1$ è il carattere che deve essere scritto sul nastro 1, ...
			- $(m_1,m_2,...,m_k)$, sono i movimenti che devono essere eseguiti dalle $k$ testine
				- $m_1$ è il movimento che deve essere compiuto dalla testina sul nastro 1, ...
- Dunque, possiamo dire che, in generale, una macchina di Turing è una quintupla $<\Sigma, Q. q_0,Q_F,P>$

>[!note]- Osservazione:
>Per capire quale sia il numero di nastri di una macchina di Turing $<\Sigma, Q.q_0, Q_F, P>$ è sufficiene osservare le quintuple contenute in $P$:
>	- il numero di componenti del secondo elemento di una quintupla in $P$ (che specifica ciò che deve essere letto sui nastri per poter eseguire una quintupla) corrisponde la numero di nastri.
>	- es: Se le quintuple di una macchina di Turing hanno la forma $<q_1, a_1, ...>$ allora si tratta di una macchina ad un nastro.
>	- se le quintuple di una macchina di Turing hanno la forma $<q_1,(a_1,a_2),...>$ allora si tratta di una macchina a due nastri
>	- e così via...

- Una macchina di Turing è la descrizione di un procedimento di calcolo
	- cioè un algoritmo descritto utilizzando le regole introdotte da Alan Turing
- Le regole introdotte da Turing per descrivere procedimenti di calcolo costituiscono un modello di calcolo.
- Un modello di calcolo che prende il nome di Macchina di Turing.

>Es: slide da 15 a 21 - Lezione 2

## macchine di Turing

- Il modello di calcolo Macchina di Turing richiede che in ogni macchina l'insieme degli stati e l'alfabeto abbiano cardinalità finita - e lo stesso vale per il numero di nastri.
- Cerchiamo di capire perchè ripensando alla somma di due numeri:
	- Se fosse possibile avere un numero infinito di stati interni e un numero infinito di caratteri dell'alfabeto, il progetto di una macchina di Turing che esegue la "somma in riga" di due numeri sarebbe banale: basterebbe porre $\Sigma=\mathbb{N} \cup \{+\}$ e $Q=\{q_x:x \in \mathbb{N}\} \cup \{q_i,q_F\}$ e utilizzare la quintuple.
		- per ogni $n \in \mathbb{N} <q_i,(n, \square),(n,\square),q_n,(d,f)>$, che legge il primo numero, entra nello strato interno corrispondente e muove la testina del primo nastro a destra per andare a cercare il secondo numero
		- per ogni $n \in \mathbb{N} <q_n,(+, \square),(+,\square),q_n,(d,f)>$, che "scavalca" il '+'
		- per ogni $n,m \in \mathbb{N} <q_n,(m,\square),(m,h),q_f,(d,f)>$, dove $h=m+n$
- Il punto è che questa "macchina" non potremmo costruirla.
	- Possiamo pensare che gli stati siano realizzati mediante lampadine: a ciascuno stato corrisponde una lampadina (accesa o spenta a seconda se la macchina si trovi o meno in quello stato) e che ciascuna quintupla sia una sorta di circuito che si occupa di controllare, accendere e spegnere le lampadine.
	- Quindi dovremmo disporre tante lampadine e tanti circuiti quanti sono i numeri naturali e mi sa non ce la faremo mai nel corso della nostra vita.
- Il punto è che la forma abbreviata "per ogni $x \in A$ "dobbiamo poterla scrivere in forma esplicita, ovvero, anche se questa notazione è parecchio comoda dobbiamo poterla descrivere completamente con una macchina di Turing. E lo stesso vale per il numero di nastri.
	- Affinchè questo sia possibile è necessario che il numero di stati, il numero di simboli dell'alfabeto, il numero di quintuple e il numero di nastri siano finiti. Ovvero che il numero di stati, il numero di simboli dell'alfabeto, il numero di quintuple e il numero di nastri siano scelti una volta per tutte, non di volta in volta a seconda del dato particolare sul quale vogliamo operare. 
		- Ribadiamo che non possiamo scrivere "per ogni $n \in \mathbb{N} <q_i,(n,\square),(n,\square),q_n,(d,f)>$"
			- Quindi è necessario che il numero di stati, numero di simboli dell'alfabeto, numero di quintuple e numero di nastri siano costanti, ovvero, indipendenti dall'input.

## Tante definizioni per le macchine di Turing

- Dato un alfabeto finito $\Sigma$, una parola su $\Sigma$ e una sequenza finita di elementi di $\Sigma$
	- L'insieme delle parole su un alfabeto $\Sigma$ si indica con $\Sigma^*$.

## Stati Globali

slide 26 lezione 2