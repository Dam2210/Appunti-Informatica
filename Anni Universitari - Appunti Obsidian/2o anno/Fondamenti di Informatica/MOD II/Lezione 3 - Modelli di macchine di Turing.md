## Tanti modelli di macchine di Turing

Ci sono diversi modelli di macchine di Turing:
- _Macchine con tanti nastri con testine indipendenti_: quando viene eseguita una quintupla, la testina su un nastro si può muovere come vuole.
- _Macchine con tanti nastri con testine solidali_: quando viene eseguita una quintupla, se la testina su un nastro si muove in una certa direzione, anche le testine sugli altri nastri si muovono nella stessa direzione.
- _Macchine con un solo nastro di lettura/scrittura_
- _Macchine che usano un alfabeto con tanti simboli
- _Macchine che utilizzano un alfabeto binario, con due soli simboli (0,1)_

Tutto quello che possiamo fare con un modello è possibile farlo anche con gli altri.

## Testine indipendenti = Testine solidali

- Visto che una macchina a testine solidali è una particolare macchina a testine indipendenti nella quale, ogni volta che viene eseguita una quintupla, tutte le testine si muovono allo stesso modo, allora tutto ciò che facciamo con il modello a testine indipendenti riusciamo a farlo anche con il modello a testine solidali.
- Mostriamo ora l'inverso:
	- lo facciamo in un caso particolare: quando la macchina a testine indipendenti ha 2 nastri
	- ma si generalizza a quanti nastri ci pare
- Sia $T$ una macchina a 2 nastri con testine indipendenti: una sua quintupla è $<q_1,(a,b),(c,d),q_2,(m1,m2)>$ dove $m1$ è il movimento della testina sul primo nastro e $m2$ è il movimento della testina sul secondo nastro.
- Vediamo ora come trasformare quella quintupla in un insieme di quintuple di una macchina $T'$ a tre nastri a testine solidali che "si comporta come" la quintupla di $T$.

Vediamo come trasformare una quintupla $<q_1,(a,b),(c,d),q_2,(m1,m2)>$  di $T$ 
- dove $m1$ è il movimento della testina sul primo nastro e $m2$ è il movimento della testina sul secondo nastro.

In un insieme di quintuple di una macchina $T'$ a due nastri a testine solidali che "si comporta come" la quintupla di $T$.
- Per farlo, descriviamo prima le quintuple di $T'$, e solo in seguito il suo alfabeto e il suo inseme degli stati.

Ricordiamo che una quintupla di $T'$ ha la seguente struttura:
$<q_x,(u,v),(w,z),q_y,m>$ 

Torniamo alla quintupla $<q_1,(a,b),(c,d),q_2,(m1,m2)>$ di $T$.
- se $m1=m2$ (stesso movimento) risulta facile. la quintupla $<q,(a,b),(c,d),q_2,m1>=<q_1,(a,b),(c,d),q_2,m2>$ è inserita tra le quintuple $T'$ e fa le stesse cose che in $T$ sono fatte dalla quintupla $<q_1,(a,b),(c,d),q_2,(m1,m2)>$ 
- se invece $m1$ e $m2$ sono diversi, tipo $m1=$ destra e $m2=$ sinistra, allora è più complicato.
	- cosa accade in $T$ quando esegue $<q_1,(a,b),(c,d),q_2,(destra,sinistra)>$ 
	- Come facciamo ad ottenere lo stesso comportamento in $T$?
	- I nastri non si possono tirare da una parte o dall'altra, quindi ricordiamo la coppia di celle dalla quale partiamo:
		- dobbiamo quindi spostarci sul carattere più a destra del primo nastro, leggere quel carattere e ricordandolo, cancellarlo e copiarlo sulla cella a sinistra ricordando il carattere che vi era scritto in precedenza, e ripetere questo shift dei caratteri sul primo nastro, fino a raggiungere il carattere più a destra.
		- "memorizzo $a_s$" = entro in uno stato che dipende da $a_s$, del tipo q($a_s$)
	- La stessa cosa facciamo per spostare un  carattere a sinistra:
		- dobbiamo quindi spostarci sul carattere più a sinistra del secondo nastro, leggere quel carattere e ricordandolo, cancellarlo e copiarlo sulla cella a destra ricordando il carattere che vi era scritto in precedenza, e ripetere questo shift dei caratteri sul secondo nastro, fino a raggiungere il carattere più a destra.
	- Ora non ci resta che posizionarci sulla cella dalla quale eravamo partiti, abbiamo bisogno di un terzo nastro quindi sul quale dobbiamo scrivere un carattere speciale, tipo '$*$', che faccia da "segnaposto".
	- Nella prima, $T’$ ha appena sostituto ‘a’ con ‘c’ sul primo nastro e ‘b’ con ‘d’ sul secondo nastro, e si prepara ad eseguire lo shift sul primo nastro
	- Nella seconda, $T’$ ha appena finito lo shift sul primo nastro e si prepara ad eseguire lo shift sul secondo nastro