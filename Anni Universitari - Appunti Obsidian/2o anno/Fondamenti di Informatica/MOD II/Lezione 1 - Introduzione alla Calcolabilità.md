## Problemi e istanze

- Cos'è un problema?
	- "Quanto fa $5+2$?" oppure "Quanto misura l'area di un rettangolo la cui base è lunga 28 e la cui altezza è lunga 21?": ecco due esempi di problema.
	- Nell'esempio, sono illustrate due istanze di due problemi diversi, i problemi cui corrispondono quelle istanze sono:
		- Problema Somma: dati due numeri naturali, n e k, calcolare il valore della somma di n con k (ossia, n+k)
		- Problema Area; dato un rettangolo , la cui base è lunga b e la cui altezza è lunga h, calcolare l'area A di quel rettangolo.

- Quindi la distionzione è:
	- Un problema è la descrizione di un insieme di parametri, che chiameremo dati, collegati da un certo insieme di relazioni, associata alla richiesta di derivare da essi un altro insieme di parametri, che costituiscono la soluzione.
	- Un'istanza di un problema è un particolare insieme di valori associati ai dati.

## Trovare una soluzione di un'istanza

- Per trovare la soluzione di talune istanze di taluni problemi posso sfruttare le caratteritiche di quelle istanze
	- Se chiedi a un bambino quanto fa $2+5$, quello può contare sulle dita.
	- Se hai bisogno di trovare $sen(\frac{\pi}{2})$, puoi disegnare la circonferenza goniometrica e vederlo.
- D'altra parte, a volte non è così semplice
	- Le dita non bastano per calcolare $67387283672+1638798393823$
	- E calcolare $sen(\frac{\sqrt[3]{\pi^{\pi}+8ln\pi}}{5}$ ) non è semplice.
- Altre volte risulta proprio impossibile
	- Per esempio un numero che corrisponde a $\sqrt{-4}$ non riuscirai mai a trovarlo.
	- Quando l'istanza di un problema non ha soluzione diciamo che essa è un'istanza negativa.

## Risolvere un problema

- Risolvere un problema significa individuare un metodo che sappia trovare la soluzione di qualunque istanza positiva del problema e, in più che sappia riconoscere se un'istanza è negativa.
- Quindi in sostanza significa trovare un procedimento che, data una qualunque istanza del problema, indichi la sequenza di azioni che devono essere eseguite per trovare la soluzione di quell'istanza o per poter concludere che, quell'istanza, una soluzione non ce l'ha
- Qui sorgono un bel po' di questioni:
	- Cos'è un procedimento?
	- Cos'è un azione?
	- Chi è supposto debba eseguire le azioni indicate?
	Queste questioni sono tra loro interconnesse.

>[!important]- Definizione: Cos'è un procedimento?
>Un procedimento è la descrizione di un insieme di azioni unita alla specifica dell'ordine con il quale le azioni devono essere eseguite.

>[!important]- Definizione: Cos'è un azione?
>E' qualcosa che deve esser fatto. Anche "data un'istanza del problema, trova la soluzione di quell'istanza" è un'azione. Quindi dobbiamo dire che le azioni in un procedimento, devono essere azioni semplici, azioni, cioè, che possono essere eseguite con facilità.

>Esempio: data una funzione $f:\mathbb R \rightarrow \mathbb R^+$ e dati due numeri reali a e b, calcolare la misura dell'area della regione di piano compresa fra la funzione, l'asse x e le rette $y=a$ e $y=b$ 
>- Procedimento:
>	1. Calcola la funzione primitiva $F(x)$ di $f(x)$
>	2. Calcola $F(b)-F(a)$

## L'istruzione elementare 

- Se vogliamo svincolare la definizione di procedimento risolutivo di un problema da quello di esecutore delle azioni in esso indicate, è necessario, prima di tutto, chiarire formalmente cosa si intende con istruzione elementare.
- Vediamo la soluzione ideata da Alan Turing a questa questione:
	- Turing, osservò che, indipendentemente dall'esecutore, qualunque istruzione, per poter essere definita elementare, deve avere le seguenti caratteristiche:
		- deve essere scelta in un insieme di "poche" istruzioni disponibili
		- deve scegliere l'azione da eseguire all'interno di un insieme di "poche" azioni possibili
		- deve poter essere eseguita ricordando una quantità limitata di dati, ossia, utilizzando una quantità limitata di memoria.
- Osserviamo che le caratteristiche individuate da Turing indicano come istruzione elementare un'operazione che possa essere eseguita a mente, come per esempio la somma di due numeri naturali n e k, che risulta molto semplice ed elementare.
	- ma se $n = 37895$ e $k = 441238$ a nessuno di noi, soltanto guardando i due addendi, salta in mente il risultato, anche se le addizioni le sappiamo fare benissimo. Questo perchè la nostra memoria è limitata.
- Chiariamo: in qualche modo, quando abbiamo imparato a fare le addizioni, abbiamo memorizzato la tabella che ci permette di calcolare a mente la somma di qualunque coppia di numeri di una cifra ciascuno.

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine1.png]]

- Se $n = 37895$ e $k = 441238$ e disponessimo una tabella sufficientemente grande che indica le somme di tutti i numeri naturali compresi tra $0$ e $1000000$ (ad esempio), ci basterebbe guardare nella cella opportuna e avremmo la somma cercata: al volo, ad occhio...

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine2.png]]

Purtroppo non funziona in questo modo...
- Il problema è che, per risolvere il problema somma, occorre indicare un procedimento che sappia addizionare qualunque coppia di numeri neturali, per quanto grandi siano.
- Quindi, se volessimo considerare istruzione elementare la somma di qualunque coppia di numeri, dovremmo costruire una tabella infinita.

- Visto che la nostra memoria è limitata, per eseguire la somma di qualunque coppia di numeri naturali, utilizziamo un procedimento che...
	- Utilizza un numero limitato di operazioni elementari (le somme di coppie di numeri di una sola cifra)
	- E in cui ogni operazione elementare utilizza una quantità limitata di dati (due cifre e l'eventuale riporto).
In accordo con le caratteristiche enunciate da Turing.

## La somma di due numeri naturali

- Ripassiamo questo procedimento:

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine3.png]]

- Potremmo descrivere il procedimento per calcolare la "somma in colonna" di due numeri naturali nel modo seguente:
	1. Posizionati sulla coppia di cifre più a destra, e poni $r=0$.
	2. Fino a quando leggi una coppia di cifre, esegui la somma della coppia di cifre sulle quali sei posizionato, aggiungi $r$ a tale valore e scrivi una cifra del risultato calcolando anche il nuovo valore di $r$, e poi spostati a sinistra - ossia:
		- se $r=0$ e le due cifre sono $0$ e $0$, allora scrivi $0$, poni $r=0$, e spostati di una posizione a sinistra 
		- se $r=1$ e le due cifre sono $0$ e $0$, allora scrivi $1$, poni $r=0$, e spostati di una posizione a sinistra 
		- ........
		- se $r=0$ e le due cifre sono $9$ e $9$, allora scrivi $8$, poni $r=1$, e spostati di una posizione a sinistra 
		- se $r=1$ e le due cifre sono $9$ e $9$, allora scrivi $9$, poni $r=1$, e spostati di una posizione a sinistra 
		- $[...continua...]$ 

	3. Fino a quando leggi una sola cifra (ossia, le cifre di uno dei due numeri sono terminate) aggiungi $r$ ad essa e scrivi una cifra del risultato calcolando anche il nuovo valore di $r$, e poi spostati a sinistra - ossia:
		- se $r=0$ e l'unica cifra è $0$, allora scrivi $0$, poni $r=0$, e spostati di una posizione a sinistra
		- se $r=0$ e l'unica cifra è $1$, allora scrivi $1$, poni $r=0$, e spostati di una posizione a sinistra
		- ........
		- se $r=1$ e l'unica cifra è $8$, allora scrivi $9$, poni $r=0$, e spostati di una posizione a sinistra
		- se $r=1$ e l'unica cifra è $9$, allora scrivi $0$, poni $r=1$, e spostati di una posizione a sinistra
		- $[...continua...]$
	4. Se le cifre di entrambi i numeri sono terminate, allora calcola l'eventuale ultima cifra del risultato e termina - ossia:
		- se $r=0$ e le cifre di entrambi i numeri sono terminate, allora termina
		- se $r=1$ e le cifre di entrambi i numeri sono terminate, allora scrivi $1$ e termina.

- Ossia il procedimento per calcolare la " somma in colonna" di due numeri naturali è una sequenza di:
	"se sono vere certe condizioni allora esegui queste azioni"
- Ad ogni coppia (certe condizioni, queste azioni) corrisponde un'istruzione,  "certe condizioni" è ciò che viene letto (la coppia di cifre dei due numeri eventualmente assenti) e il valore del riporto, mentre "queste azioni" è ciò che viene scritto, la modifica del valore del riporto, e lo spostamento (in alcuni casi "queste azioni" è l'indicazione che la somma è stata completata  (termina)).
- Questo procedimento potrebbe eseguirlo chiunque sappia leggere e scrivere e distinguere fra destra e sinistra. Ma pur essendo istruzioni elementari da un punto di vista intuitivo, sono quelle appena individuate istruzioni elementari nel senso indicato da Turing?

- Abbiamo già visto che nel procedimento che esegue la somma le azioni che vengono eseguite sono due: scrittura di una cifra e spostamento e possiamo quindi affermare che loro sono davvero "poche", come detto da Turing.
- Ma è vero che il procedimento che esegue la somma ha un insieme di "poche" istruzioni disponibili ciascuna delle quali utilizza una quantità limitata di memoria?
	- Riflettiamo:
		- Il numero di istruzioni disponibili è pari al numero di coppie di cifre moltiplicato per il numero di possibili valori per il riporto, ossia $10\times 10\times 2=200$ 
		- Per sapere quale istruzione dobbiamo eseguire abbiamo bisogno di conoscere le due cifre da sommare e il valore del riporto, ossia, $3$ numeri di una cifra.
- Ricapitolando: per sommare qualunque coppia di interi (grandi quanto ci pare) abbiamo a disposizione $222$ istruzioni (che eseguono 2 azioni) fra le quali scegliere quella da eseguire utilizzando una memoria di $3$ cifre.
- Ossia, il numero di istruzioni, azioni e la quantità di memoria necessaria sono costanti: non dipendono da quello che chiameremo input
	- Quindi ora è chiaro cosa si intende con "poche" e con quantità limitata, chiara è anche la scelta di Turing delle sue tre caratteristiche.

- Il procedimento per calcolare la "somma in colonna" di due numeri naturali, come abbiamo già detto, è una sequenza di "se sono vere certe condizioni esegui queste azioni".
- Le istruzioni ti dicono, per ogni condizione possibile, esattamente quali azioni devi eseguire in quelle condizioni.
- Questo significa che l'insieme di istruzioni non è ambiguo: non può contenere due (o più) istruzioni che, a partire dalle stesse condizioni, ti indica diverse azioni da eseguire.
- Dunque l'ordine in cui eseguire le istruzioni è indicato implicitamente nel meccanismo stesso de "se... allora..."
	- In ogni istante devi eseguire l'unica possibile istruzione che è possibile eseguire, fino a quando non incontri un'istruzione che ti dice di terminare. Non si può fare altro.
	- Le istruzioni sono una sorta di ordini, loro ti dicono di fare qualcosa e tu lo fai. (Questo concetto è alla base di molti linguaggi di programmazione detti imperativi).
- Questo procedimento potrebbe anche essere eseguito da un'automa.

## Risolvere automaticamente un problema

- Eccoci al nocciolo della questione:
	- Informalmente, risolvere automaticamente un problema significa progettare un procedimento che risolve tutte le istanze di quel problema e che può essere eseguito da un automa
		- Ovvero da un esecutore che può non avere alcuna idea del problema né del significato delle istruzioni contenute nel procedimento.

## Un nuovo linguaggio...

Ripensiamo alla somma di due numeri naturali:
1. Il procedimento che abbiamo visto è costituito di sole istruzioni "se sono vere certe condizioni allora esegui queste azioni", ripetute fino a quando non incontra il comando "termina".
2. In ciascuna istruzione le azioni da eseguire sono le 3 azioni seguenti:
	- La scrittura di una cifra, la (eventuale) modifica del riporto, il movimento a sinistra per considerare le successive due cifre da sommare.
3. Infine, le condizioni di ognuna delle istruzioni dipendono da due tipi di parametri:
	- Il valore del riporto lo teniamo a mente ad ogni coppia di cifre sommate è quindi qualcosa che caratterizza il nostro "stato interiore."

In virtù delle osservazioni 1. 2. e 3. possiamo scrivere il procedimento in forma più compatta:
- Poichè utilizziamo sole istruzioni "se condizione allora azione" evitiamo di scrivere sempre " se... allora..."
- Scriviamo, di seguito, le due condizioni seguite dalle tre azioni.

Ad esempio l'istruzione:
- "Se $r=0$ e le due cifre sono $4$ e $6$, allora scrivi $0$, poni $r=1$ e spostati di una posizione a sinistra" diventa:
$$<q_0,(4,6),0,q_1,sinistra>$$
	dove $q_0$ e $q_1$ sono due simboli che indicano, rispettivamente, $r=0$ e $r=1$

>[!info]- Osservazione: 
>In questo esempio sembrerebbe che anche "sinistra" possa essere omesso; vedremo che questa specifica, invece, occorre tenerla.

E l'istruzione:
- "Se $r=1$ e l'unica cifra è $5$, allora scrivi $6$, poni $r=0$, e spostati di una posizione a sinistra"
	nella quale le cifre di uno degli operandi sono terminate, diventa la coppia di istruzioni:
	- $<q_1,(5,\square),6,q_0,sinistra>$
	- $<q_1,(\square, 5),6,q_0,sinistra>$

>Dove il simbolo $\square$ indica che non viene letto alcunché o che non deve essere scritto alcunché e abbiamo due diverse istruzioni perché l'operando le cui cifre sono terminate può essere il primo o il secondo.

Infine, le istruzioni:
- "Se $r=1$ e le cifre di entrambi i numeri sono terminate, allora scrivi $1$ e termina".
- "Se $r=0$ e le cifre di entrambi i numeri sono terminate, allora termina".
Diventano rispettivamente:
- $<q_1, (\square, \square), 1, q_f, fermo>$
- $<q_0, (\square, \square), \square, q_f, fermo>$

>Dove $q_f$ è lo "stato interiore" che permette all'esecutore di comprendere che non deve più eseguire alcuna azione. Infine l'utilizzo di "fermo" mostra anche perché è necessario specificare come ci si deve muovere

## ...e una macchina che lo comprende

- Possiamo ora rappresentare graficamente l'esecuzione del procedimento che calcola la somma di due numeri qualsiasi.
- Per farlo, immaginiamo di disporre una sorta di automa che rappresentiamo come una specie di "testa robotizzata" e che può trovarsi in uno di tre possibili "stati interiori": $q_0, q_1$ e $q_f$. Utilizza questi stati per leggere e scrivere tre nastri suddivisi ciascuno in un numero infinito di celle tali che ciascuna cella, in ogni istante, può contenere o una cifra (un numero compreso fra $0$ e $9$) oppure può essere vuota (e indichiamo con $\square$ il simbolo di cella vuota)e tre testine di lettura/scrittura.
- Non appena viene scritto qualcosa sui nastri, dipendentemente dallo "stato interiore" dell'automa e da quello che viene letto, l'automa inizia a computare - ossia a eseguire le quintuple  del procedimento.

![[Anni Universitari - Appunti Obsidian/2o anno/Fondamenti di Informatica/MOD II/Immagini - Fondamenti MOD II/immagine4.png]]

## Quasi una macchina di Turing

- Quella che abbiamo visto è quasi una descrizione informale di una macchina di Turing.
- Quasi perché abbiamo utilizzato tre nastri e in una macchina di Turing bisogna descrivere cosa viene letto (nelle condizioni) e cosa viene scritto (nelle azioni) su ogni nastro così che l'istruzione:
	- "Se $r=0$ e le due cifre sono $4$ e $6$, allora scrivi $0$, poni $r=1$, spostati di una posizione a sinistra e torna al punto 2." diventa: 
		- $<q_0,(4,6,\square),(4,6,0),q_1,sinistra>$
>Poiché specifica $2$ condizioni e $3$ azioni, essa prende il nome di quintupla e quelli che abbiamo chiamato fino ad ora "stati interiori", si chiamano propriamente stati interni e l'esecuzione delle quintuple su un insieme fissato di dati si chiama computazione.

## Calcolabilità

- Quella che abbiamo visto è, dunque, una descrizione informale di una macchina di Turing (con la 'm' minuscola) che è la  descrizione di un procedimento di risoluzione di un problema espresso nel linguaggio definito da Alan Turing.
- Il linguaggio che costituisce un modello di calcolo è il modello Macchina di Turing (con la 'M' maiuscola).