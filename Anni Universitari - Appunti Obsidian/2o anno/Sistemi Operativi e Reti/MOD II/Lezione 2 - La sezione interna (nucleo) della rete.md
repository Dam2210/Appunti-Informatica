La sezione interna (subnet) della rete è costituita da un insieme di router e di linee di comunicazione che collegano i router stessi

![[immagine12.png]]

## Commutazione di circuito e commutazione di pacchetto

- Esistono due principali tecnologie utilizzate per realizzare le subnet: la commutazione di circuito (circuit switching) e la commutazione di pacchetto (packet switching)
- Non tutte le reti di comunicazione hanno un funzionamento nettamente a commutazione di circuito o a commutazione di pacchetto
- in Internet si usa prevalentemente la commutazione di pacchetto

## Commutazione di circuito

- Nelle reti a commutazione di circuito le risorse, come le linee di comunicazione e la larghezza di banda, sono assegnate durante la fase iniziale della comunicazione, detta fase di setup, e restano allocate e riservate durante la comunicazione.
- Nei commutatori lungo il percorso sono mantenute le informazioni della connessione tra mittente e destinatario per la durata della comunicazione.
- Quando si stabilisce un circuito, esso sarà a velocità costante garantita.
- La rete telefonica generale è un esempio di rete a commutazione di circuito. Infatti, prima che le due persone possano comunicare è necessario che la rete stabilisca un cicuito costituito da un percorso fisso tra i due telefoni.
- La figura seguente illustra una rete a commutazione di circuito. In questa rete, ogni link è costituito da $N$ circuiti, in modo che ogni link possa permettere $N$ connessioni simultanee.
- Gli host sono collegati direttamente a uno dei commutatori mediante linea analogica oppure con accesso numerico diretto. Per l'accesso analogico è richiesto l'uso di un modem.
- Affinché l'host $A$ comunichi con l'host $B$, la rete deve prima attivare e quindi riservare un circuito su ciascuno dei due link. Se ogni link ha $N$ circuiti di uguale larghezza di banda, a ciascun circuito viene dedicata $1/N$ della larghezza di banda del link per la durata del circuito.

![[immagine13.png]]

## Multiplazione (multiplexing ) nelle reti a commutazione di circuito

- Quando la larghezza di banda di un link è superiore alla larghezza di banda necessaria per un circuito si può usare la multiplazione.
- Un circuito in un link si ottiene mediante la multiplazione a divisione di frequenza (Frequency Division Multiplexing, FDM) o mediante la multiplazione a divisione di tempo (Time Division Multiplexing, TDM).
- L'FDM divide la banda di frequenza $B_L$ di un link fisico in $N$ circuiti logici, in modo che sia:
	- $B_L\geq \sum _i  B_{ci} \ \ \ (i=1,...,N)$ 
- Le sotto bande $B_{ci}$ dei circuiti logici possono avere misure diverse tra loro.
- Quando due host vogliono comunicare la rete stabilisce un circuito logico sul link per la comunicazione dei suddetti host.

![[immagine14.png]]

- Nelle reti telefoniche commutate, ad esempio, la banda di frequenza di un circuito ha una larghezza tipica di 2 kHz
- Anche le stazioni radio FM e le trasmissioni televisive usano l'FDM suddividendosi la banda di frequenza delle microonde.
- Nel TDM, il tempo di utilizzo del link è suddiviso in intervalli di durata fissa detti frame, ciascuno dei quali è ulteriormente suddiviso in un numero fisso di slot.

![[immagine15.png]]

- Quando due host vogliono comunicare, la rete stabilisce una connessione attraverso il link, dedicando uno slot di tempo di ciascun frame alla connessione dedicata ai suddetti host.
- Oggi si tende a sostituire l'FDM con TDM.
- La figura illustra FDM e TDM per uno specifico link della rete che supporta fino a $N$ circuiti.
- Per l'FDM, la larghezza di banda $B_L$ in frequenza del link è suddivisa in $N$ bande, ciascuna con larghezza di banda di $B_C$ Hz.
- Per il TDM, il dominio temporale è suddiviso tra $N circuiti con $N$ slot in ciascun frame; a ciascun circuito è assegnato lo stesso slot nei frame TDM che si succedono.
- La velocità di trasmissione di ciascun circuito è uguale alla frequenza con cui è spedito il frame moltiplicata per il numero di bit contenuti in uno slot. Per esempio, se il link trasmette $8000$ frame al secondo e ogni slot è costituito da $8$ bit, la velocità di trasmissione del circuito è di $64$ kbit/s.
- Vediamo un esempio numerico che ci permette di chiarire l'argomento.

>[!example]- Esempio:
>Calcoliamo il tempo necessario per inviare un messaggio di 640.000 bit  dall'host A all'host B su una rete a commutazione di circuito, supponendo che tutti i linkdella rete usino TDM a  24 slot, che i link abbiano una velocità di trasmissione di 1536 Kbit/s e che per stabilire il circuito (tempo di setup) servano 500 ms.
>
>Ogni circuito ha una velocità di trasmissione di 1536/24 = 10 secondi per trasmettere il messaggio.
>
>A questi 10 secondi aggiungiamo il tempo necessario per stabilire il collegamento, quindi per la trasmissione del messaggio arriviamo a 10,5 secondi.
>
>Si può notare che, trascurando il ritardo di propagazione, il tempo di trasmissione è indipendente dal numero di link: è sempre 10 secondi sia nel caso in cui gli host A e B siano connessi da un link sia che siano connessi da 100 link.

## Commutazione di pacchetto

- Le applicazionidi rete si scambiano messaggi tramte protocolli. Generalmente i messaggi hanno un formato costituito da vari campi di controllo e un campo contenente i dati da trasferire (payload).
c1|c2| |cn|dati
--- | --- | --- | --- | -----

- Nelle reti a commutazione di pacchetto, il mittente divide il messaggio da trasmettere in frammenti di piccole dimensioni detti pacchetti. I pacchetti sono trasmessi sulla linea di comunicazione alla massima velocità consentita.
- Nelle reti a commutazione di pacchetto le risorse sono condivise. I pacchetti appartenenti ad una comunicazione usano le risorse a richiesta e di conseguenza, quando arrivano ad un router, devono attendere in coda per accedere al link quando è occupato da un'altra comunicazione.

- Molti router utilizzano la trasmissione store-and-forward (immagazzinamento e rilascio ) che prevede che il router deve ricevere l'intero pacchetto prima di poterlo ritrasmettere su un link in uscita. Quindi, questi router introducono un ritardo store-and-forward (ritardo di trasmissione).
- Altri router usano la trasmissione cut-throw, consente il rilascio del pacchetto appena sono stati elaborati solo alcuni campi tra cui l'indirizzo di destinazione, senza memorizzare quindi l'intero pacchetto.
- Considerando i router store-and-forward, il ritardo è proporzionale alla dimensione del pacchetto ed inversamente proporzionale alla larghezza di banda del link. Se un router dedve rinviare un pacchetto di $L$ bit che arriva da una porta di ingresso e la velocità del link in ingresso è $R$  bit/s, il ritardo store-and-forward è di $L/R$ secondi.

![[immagine16.png]]

- Un router è collegato a vari link. Per ogni link il router ha un buffer di uscita (coda di uscita), che memorizza i pacchetti che devono essere rinviati su quel determinato link.
- Se un pacchetto in arrivo deve essere ritrasmesso su un link che è occupato dalla trasmissione di un altro pacchetto, il pacchetto in arrivo deve attendere nel buffer di uscita.
- Oltre al ritardo store-and-forward, quindi, i pacchetti subiscono il ritardo dovuto alla presenza di altri pacchetti nel buffer di uscita (ritardo di coda).
- La grandezza di questi ritardi  è variabile e dipende dal livello di congestione della rete. Se il buffer è pieno i prossimi pacchetti in arrivo di perdono.
- La figura mostra una sempice rete a commutazione di pacchetto. Supponiamo che gli host A e B stiano inviando pacchetti all'host D.

![[immagine17.png]]

- Gli host A e B inviano i loro pacchetti sui link a $100$ Mbit/s verso il primo commutatore di pacchetto.
- Il commutatore di pacchetto rinvia i pacchetti sul link a 10 Mbit/s. Se in questo link esiste una congestione, i pacchetti si accodano nel buffer in uscita prima di pote essere trasmessi sul link.
- Gli host A e B inviano pacchetti in modo casuale, senza alcun ordine periodico. Per via di questo ordinamento casuale che si crea nella coda di uscita si dice che la commutazione di pacchetto effetui una "multiplazione statistica"
- Calcoliamo quanto tempo occorre per inviare un pacchetto di $L$ bit da un host ad un altro in una rete a commutazione di pacchetto. Supponiamo che i due host siano separati da $N$ link, ciascuno dei quali ha una larghezza di banda $B1,\ B2 ... \ Bn$ bit/s. Supponiamo che la rete sia poco trafficata in modo che sia possibile trascurare il ritardo di coda. Trascuriamo poi il ritardo di propagazione e di elaborazione (da vedere in seguito).
- Il pacchetto impiega $L/B1$ secondi per giungere al primo router cui è connesso l'host. Deve poi essere trasmesso su ognuno dei rimanenti $N-1$ link, cioè deve essere memorizzato e rinviato $N-1$ volte. Il ritardo totale è quindi:
	- $Rt=L(1/B1+1/B2+...+1/Bn)$ 

![[immagine18.png]]

- Nel caso particolare, in cui tutti i link hanno la stessa larghezza di banda $B$ si ha:
	- $Rt=N\cdot L/B$.

## Confronto tra commutazione di circuito e commutazione di pacchetto

- La commutazione di pacchetto è poco adatta per un servizio in tempo reale (es. videoconferenze, comunicazioni telefoniche) a causa del suo ritardo variabile e non prevedibile causato principalmente dal ritardo di coda che è variabile e imprevedibile.
- La commutazione di pacchetto offre un migliore utilizzo della larghezza di banda rispetto alla commutazione di circuito; è più semplice ma nache più efficiente e meno costosa della commutazione di circuito.

## Frammentazione del messaggio

- In una rete a commutazione di pacchetto, l'host mittente frammenta i messaggi in pacchetti più piccoli e li trasmette; il destinatario ricongiunge i pacchetti e ricostruisce il messaggio originale.
- La frammentazione e la ricostruzione del messaggio rendono più complessi i protocolli ma i vantaggi ottenuti superano gli svantaggi dovuti alla maggiore complessità.
- La figura illustra il trasferimento di un messaggio non frammentato in un percorso costituito da due commutatori di pacchetto e tre link. Dato che i commutatori sono del tipo store-and-forward, è necessario che un commutatore riceva l'intero messaggio prima di poterlo rinviare su un link in uscita.

![[immagine19.png]]

- La figura illustra la commutazione di pacchetto con il messaggio frammentato per la stessa rete.

![[immagine20.png]]

- Qui il messaggio originale è stato frammentato in quattro pacchetti. Supponendo che la trasmissione sia iniziata nell'istante $t_0$, il primo pacchetto è arrivato a destinazione nell'istante $t_3$, il secondoe il terzo stanno transitando sulla rete, e l'ultimo pacchetto è ancora alla sorgente.
- Quando un messaggio viene suddiviso in pacchetti, si dice che la rete effettua in pipeline la trasmissione dei messaggi; cioè, parti del messaggio vengono trasmesse in parallelo dalla sorgente e dai commutatori di pacchetto.
- Uno dei maggiori vantaggi della commutazione di pacchetto è che si ottengono ritardi end-to-end molto inferiori a quelli che si ottengono con la commutazione senza frammentazione.

![[immagine21.png]]
![[immagine22.png]]

>[!example]- Esempio
>Consideriamo un messaggio di $7,5\cdot 10^6$ bit. Supponiamo che tra sorgente e destinazione ci siano due commutatori di pacchetto e tre link, e che ciascun link abbia una velocità di trasmissione di $1,5$ Mbit/s. assumendo che la rete non sia congestionata:
>
>![[immagine23.png]]
>
>1.  Quanto tempo è richiesto per trasferire il messaggio dalla sorgente alla destinazione senza frammentarlo?
>2. Quanto tempo occorre per trasferire il messaggio suddividendolo in $5000$ pacchetti?
>
>Risposte:
>1. Occorrono $5$ secondi $(7,5\cdot 10^6/1,5\cdot 10^6=5 \ sec)$ per trasferire il messaggio dalla sorgente al primo commutatore. Dopo la ricezione del messaggio completo, occorrono $5$ secondi per trasferire il messaggio dal primo al secondo commutatore.
>	- Quindi per trasferire il messaggio dalla sorgente al secondo commutatore servono 10 secondi. Infine, sono necessari altri $5$ secondi per trasportare il messaggio dal secondo commutatore alla destinazione. Il tempo totale è quindi $15$ secondi.
>
>![[immagine24.png]]
>
>2. Suddividendo il messaggio di $7,5\cdot 10^6$ bit in $5000$ pacchetti, ogni pacchetto sarà lungo $1500$ bit:
>	$7,5\cdot 10^6/5\cdot 10^3=1,5\cdot 10^3=1500 \ bit$.
>	Occorre:
>	$1,5\cdot 10^3/1,5\cdot 10^6=1\cdot 10^{-3}=1 \ ms$
>	per trasmettere il primo pacchetto dalla sorgente al primo commutatore. Occorre anche $1$ ms per trasmettere il primo pacchetto al secondo commutatore. Ma mentre il primo pacchetto si sta muovendo dal primo al secondo commutatore, il secondo pacchetto, contemporaneamente, si sta spostando dalla sorgente al primo commutatore. Il secondo pacchetto raggiunge perciò il primo commutatore dopo $2$ ms dall'inizio. Seguendo questa logica vediamo che l'ultimo pacchetto è arrivato interamente al primo commutatore dopo $5000 \ ms=5 \ s$ dall'inizio. Poichè quest'ultimo pacchetto deve ancora essere trasmesso su altri due link, esso arriverà a destinazione dopo $5,002$ secondi.
>	
>	![[immagine25.png]]
>	

## Reti a commutazione di pacchetto datagram

- Le reti a commutazione di pacchetto possono essere di tipo a circuito virtuale o datagram. Internet è una rete datagram.
- In una rete datagram, ciascun pacchetto contiene nella sua intestazione gli indirizzi del destinatario e del mittente. L'indirizzo ha una struttura gerarchica. In particolare, l'indirizzo di un host, detto indirizzo IP, è composto da una parte relativo alla rete di appartenenza e da una parte che identifica l'host in quella rete.
- Quando un pacchetto arriva da un router, questo analizza l'indirizzo del destinatario e invia il pacchetto a un router adiacente. Più precisamente, ciascun router ha una tabella di instradamento che mette in corrispondenza l'indirizzo (o meglio la sua parte relativa alla rete di appartenenza) con un link in uscita.

![[immagine26.png]]











