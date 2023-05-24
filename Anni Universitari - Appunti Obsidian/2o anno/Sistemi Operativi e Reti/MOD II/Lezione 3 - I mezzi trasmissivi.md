
## I mezzi trasmissivi

![[immagine27.png]]

- I mezzi trasmissivi si dividono in due categorie: mezzi trasmissivi guidati e mezzi trasmissivi non guidati.
	- Es mezzi trasmissivi guidati: doppini in rame, cavi coassiali, cavi in fibra ottica.
	- Es mezzi trasmissivi non guidati: onde radio nella banda terrestre e satellitare (in questi mezzi le onde si propagano nello spazio, come in una wireless LAN o in un canale satelliatre).

## Doppino

- Il mezzo trasmissivo più economico è il doppino che consiste in due fili, di rame e alluminio, isolati tra loro, avvolti a  spirale e aventi diametro di circa $1$ mm. L'avvolgimento dei fili consente la riduzione di interferenze elettriche con altri doppini vicini.
- Molti doppini sono impaccati in un cavo e protetti da guaina esterna.
- Il doppino telefonico è usato per l'accesso residenziale a Internet.
- Varie coppie di doppino sono usate per realizzare varie categorie di cavo nelle reti locali (LAN).
- Questi cavi sono spesso chiamati chiavi ethernet.

![[immagine28.png]]

- La velocità di trasmissioni delle LAN che usano cavi ethernet è $10$ Mbit/s (obsoleta), $100$ Mbit/s, $1$ Gbit/s e $10$ Gbit/s.
- Cavi utilizzati dalle LAN: categoria $5$ (in disuso), $5$e (1 Gbit/s), 6 (10 Gbit/s), 6A (10 Gbit/s) e 7 (10 Gbit/s).
- Tutti i tipi di cavo ethernet usano il connettore $RJ45$.  I cavi si differenziano per le prestazioni e per il livello di immunità alle interferenze. Le principali categorie di cavi ethernet sono:
	- CAT 5 (in disuso): cavi in grado di arrivare a una velocità massima di trasmissione di 100 Mbps (Fast Ethernet) con larghezza di banda fino a 100 MHz.
	- CAT 5e: è un miglioramento della precedente categoria 5 (trasmissione massima di 1 Gbit/s)
	- CAT 6: velocità fino a 10 Gbps e larghezza di banda fino a 250 MHz.
	- CAT 6A: miglioramento della categoria 6.
	- CAT 7 : categoria di cavo con migliori prestazioni - velocità 10 Gbps e larghezza di banda di 600 Mhz.
- Una caratteristica importante dei cavi ethernet è la schermatura. La schermatura è indicata sul cavo con le sigle, come UTP, STP, FTP.

![[immagine29.png]]

- UTP (Unshielded Twisted Pair): indica cavi senza schermatura.
- STP (Shielded Twisted Pair) e FTP: indicano cavi con schermatura aggiuntiva contro le interferenze.

![[immagine30.png]]

- I cavi con doppia schermatura si indicano con le sigle S-STP e S-FTP (Screened Shielded Twisted Pair).

![[immagine31.png]]

## Cavi coassiali

I cavi coassiali consistono di due conduttori in rame concentrici. Hanno una trasmissione dati più elevata dei doppini.
Essi sono di due tipi:
- Cavo coassiale in banda base.
- Cavo coassiale in banda traslata.

- Il cavo coassiale in banda traslata è leggermente più spesso di quello di banda base. Usato principalmente per impianti di TV via cavo.
- Con il cavo coassiale in banda traslata il trasmettitore modula il segnale digitale traslandolo su una specifica banda di frequenza, il segnale analogico risultante è inviato dal trasmettitore a uno o più ricevitori. 
- Molti host possono essere collegati direttamente al cavo, e tutti gli host ricevono tutti i segnali che vengono trasmessi dagli altri host.

![[immagine32.png]]

## Fibre ottiche

Una fibra ottica è un sottile mezzo di vetro e plastica che conduce impulsi di luce. Una fibra ottica consente velocità di trasmissione superiori a centinaia di Gbit/s. Le fibre ottiche sono immuni alle interferenze elettromagnetiche, provocano attenuazioni dei segnali molto ridotte e fino a 50 km possono essere usate senza un ripetitore, mentre doppini e cavi coassiali necessitano di un ripetitore ogni 5 Km. Queste caratteristiche fanno in modo che la fibra ottica sia il mezzo di trasmissione più adatto per le lunghe distanze.
- La fibra ottica è utilizzata anche nelle reti dorsali (backbone) di Internet.

![[immagine33.png]]
![[immagine34.png]]

- Tuttavia, gli altri costi dei dispositivi ottici (trasmettitori, ricevitori ecc..) hanno limitato uso per trasmissioni per brevi distanze, come nelle LAN o nelle reti di accesso residenziale.

## Canali radio terrestri

- I canali radio trasportano segnali tramite onde elettromagnetiche.
- Le caratteristiche di un canale radio dipendono dall'ambiente di propagazione e dalla distanza a cui un segnale deve arrivare. Il segnale è sogetto a vari problemi tra i quali attenuazione, zone d'ombra e interferenze.
- I canali radio sono calssificati in sue gruppi:
	- Canali per reti in area locale: copertura tipica da decine a poche centinaia di metri.
	- Canali in area geografica: copertura di decine di chilometri.

## Canali radio satellitari

- Un satellite per comunicazioni collega due o più trasmettitori/ricevitori a microonde situati sulla Terra, detti stazioni al suolo. Il satellite riceve trasmissioni su una banda di frequenza per evitare interferenze. I satelliti possono fornire larghezze di banda dell'ordine dei Gbit/s.
- Esistono vari tipi di satelliti per comunicazioni tre i quali:
	- Geostazionari (GEO, Geostationary Earth Orbit)
	- Orbita bassa (LEO, Low Earth Orbit)

- I satelliti geostazionari sono sempre visibili nella stessa posizione da un punto sulla Terra. Questa posizione stazionaria è ottenuta posizonando il satellite su un'orbita di circa 36.000 Km dalla superficie terrestre. Questa enorme distanza che va dalla stazione a terra al satellite e dal satellite all'indietro, verso la stazione a terra, introduce un rilevante ritardo di propagazione di circa 240 millisecondi.
- I collegamenti via satellite, con velocità di trasmissione di centinaia di Mbit/s, sono spesso usati nelle reti telefoniche e nelle reti dorsali di Internet.
- I satelliti a orbita bassa sono posti du orbite più vicine alla Terra a distanze comprese tra 160 e 2000 Km. Non sono fissi in corrispondenza dello stesso luogo sulla Terra ma ruotano intorno alla Terra come la Luna. Hanno un periodo di rivoluzione di circa 90 minuti e quindi una velocità di circa 27400 Km/h. Per fornire una copertura devono essere posti in orbita molti satelliti. Introducono un ritardo di propagazione di 20 - 25 ms.

![[immagine35.png]]

## Accesso alla rete Internet

- Gli host possono connettersi a Internet mediante vari tipi di accesso che sono generalmente classificati in tre classi:
	- accesso residenziale - collega alla rete i computer di casa.
	- accesso aziendale - collega alla rete i computer di aziende e istituti vari
	- accesso a wireless - collega alla rete i computer portatili, tablet e smarthphone.

- Queste categorie sono solo schematiche, alcuni host di enti potrebbero usare sia tecnologia ad accesso aziendale che quella ad accesso residenziale.

![[immagine36.png]]

## Accesso residenziale

- DSL (Linea Digitale per abbonati) e l'HFC (Hybrid Coaxial Fiber Cable) sono due tecnologie per l'accesso residenziale a banda larga. HFC usa reti per trasmissioni televisive via cavo, basate su cavo coassiale.
- DSL è una famiglia di tecnologie di trasmissione utilizzate per l'accesso residenziale a Internet progettata per funzionare con le reti telefoniche cablate esistenti, basate su doppino telefonico.
- Le velocità di trasmissione sono generalmente asimmetriche nelle due direzioni, con velocità maggiore dalla rete dell'ISP verso casa (download) che da casa verso la rete dell'ISP (upload). Questa asimmetria è dovuta al comportamento dell'utente.
- Gli accessi a Internet Dsl sono considerati a "banda larga".
- La banda trasmissiva in ricezione e trasmissione varia a seconda della particolare tecnologia DSL, delle condizioni della linea e del livello di servizio.
- Esistono limitazioni in velocità di trasmissione che dipendono dalla qualità del doppino telefonico e dalla distanza tra l'abitazione dell'utente e la centrale telefonica.
- Sono state standardizzate e utilizzate diverse tecnologie DSL: ADSL (Asymmetric Digital Subscriber Line), ADSL2, ADSL2+ ecc...

- La DSL usa tecniche FDM (multiplazione a divisione di frequenza). In particolare, la larghezza di banda della linea di comunicazione tra l'abitazione e ISP è divisa in tre bande di frequenza:
	- canale telefonico: nella banda da 0 a 4 kHz.
	- canale in upstream: a media velocità.
	- canale in downstream: ad alta velocità.

![[immagine37.png]]

- Il doppino telefonico i rame era stato progettato e viene tuttora usato per la comunicazione in voce.
- Per utilizzare tutta la banda effettivamente disponibile vengono utilizzate tecniche di multiplazione a divisione di frequenza (FDM) per separare il segnale vocale dal traffico dati in upload e in download.
- Il collegamento DSL consiste in un modem DSL, posto a casa dall'utente, e da un DSLAM, nella centrale telefonica.
- La separazione tra il segnale vocale e i dati viene effettuato tramite appositi filtri detti splitter posti nel dispositivo dell'utente e nella centrale telefonica.
- La parte a bassa frequenza del segnale, cioè la fonia, viene inviata rispettivamente ai telefoni e ai commutatori telefonici preesistenti, preservando il servizio telefonico; la parte in alta frequenza, cioè la parte dati, ai DSLAM o modem/router a casa dell'utente.

![[immagine38.png]]

- La banda del canale trasmissivo viene suddivisa in sotto bande di circa 4 kHz 
- I canali compresi tra le frequenze Fu1 e Fu2 sono usati per l'upload, mentre quelli da Fd1 e Fd2 sono usati per il download.

![[immagine39.png]]

- La modulazione utilizzata è di tipo OFDM, che permette di utilizzare i mezzi trasmissivi, come il doppino, sogetto a disturbi sotto forma di rumore e interferenza, in modo adattivo.
- Questa adattabilità è necessaria perchè le linee di trasmissionebasate su doppino hanno caratteristiche eterogenee e sono sogette a forte attenuazione del segnale e a varie forme di interferenza, come ad esempio la diafonia. La velocità di trasmissione non è dunque costante e dipende dallo stato del mezzo trasmissivo. 
- Al momento di stabilire la connessione, il modem ADSL e il DSLAM analizzano la qualità della linea su ciascun canale e decidono come utilizzarli.
- Questa operazione è detta "sincronizzazione" del modem e può richiedere anche alcune decine di secondi.
- Nel selezionare i canali viene scelto un compromesso tra velocità di trasmissione e affidabilità. Più canali sono attivati per la comunicazione più la velocità di trasmissione è elevata.

## FTTC e FTTH

- Come previsto dalla nosrmativa europea entro il 2020 il 100% della popolazione dei paesi dell'Unione Europea dovrebbe avere accesso a una connessione Internet domestica a banda ultra larga, cioè con velocità di almeno 30 megabit al secondo.
- Per fare ciò si stanno investendo moltissimi soldi.
- Una connessione a rete  fissa è costituita da un mezzo trasmissivo, che collega l'abitazione dell'utente o l'azienda alla cosidetta centralina di prossimità, detta anche cabinet, la quale, a sua volta, è collegata alla centrale dell'ISP più vicina all'utente.

![[immagine40.png]]

- La diversa combinazione di mezzi trasmissivi utilizzati per coprire queste due tratte, dall'utente alla centralina e da questa alla centrale, definisce il tipo di collegamento che pertanto, è indicato con nomi differenti.

![[immagine41.png]]

- I termini FTTS (Fiber to the Street) oppure FTTC (Fiber to the Cabinet) indicano collegamenti nei quali si usa la fibra ottica, per connettere la centrale con il cabinet, conservando il doppino di rame per il collegamento tra cabinet e il modem DSL a casa dell'utente. Quest'ultimo tratto è solitamente di lunghezza inferiore ai 250-300 metri.
- Con FTTH(Fiber To The Home), si indicano collegamenti in cui la fibra ottica è usata in entrambe le tratte, partendo dalla centrale ed arrivando fino all'interno della casa dell'utente.
- Con la tecnologia VDSL (Very High-speed Digital Subscriber Line), è possibile raggiungere, per brevi distanze, velocità di trasmissione dell'ordine delle centinaia di mbps. Tali elevate velocità sono state raggiunte grazie al vectoring, una tecnica di cancellazione del rumore o interferenza elettromagnetica che consente il passaggio di segnali a frequenze più elevate.
- VDSL 2 enhanced è una tecnologia che consente di incrementare la velocità di trasmissione
- In conclusione, la differenza tra le varie tecnologie DSL sta nella larghezza di banda utilizzata per la codifica dei dati.
- E' da notare che più è alta la velocità di trasmissione e più è breve la distanza tra abitazione e cabinet.

## Accesso aziendale

- Nelle società o nelle università, una rete LAN (Local Area Network) viene utilizzata per collegare i computer a Internet.
- Ci sono differenti tipi di tecnologie LAN. la rete Ethernet è attualmente la tecnologia di accesso più diffusa per le reti locali.
- La velocità di trasmissione di Ethernet commutata che usa gli switch per connettere tra loro i computer. La connessione tra calcolatori e switch si ottiene fisicamente con cavi UTP. Vari switch possono essere connessi ad un router di default che ha il compito di instradare i pacchetti indirizzati all'estarno della LAN. La figura seguente mostra un semplice schema di Ethernet commutata.

![[immagine42.png| center | 600]]

## Accesso wireless

- Oggi esistono due ampie classi di accesso wireless a Internet
	- Wireless LAN: in sui gli uetnti con dispositivi mobili comunicano con una stazione base detta punto di accesso wireless, entro un raggio inferiore a cento metri. La stazione base è connessa a Internet.
	- Wireless in area geografica: in cui la stazione base è gestita da un gestore di servizi di telecomunicazione e serve gli utenti entro un raggio di una decina di chilometri.
- La LAN wireless (wireless Ethernet e Wi-Fi) è una tecnologia che attualmente è molto diffusa. La tecnologia 802.11b fornisce una banda condivisa di 11 Mbit/s, la 802.11g consente velocità di trasmissione fino a 54 Mbps, la 802.11n fino a 300 Mbps
- Lo standard 802.11ac è stato approvato nel gennaio 2014 e funziona solo nella banda delle frequenze dei 5 GHz. La velocità massima teorica di questo standard all'interno di una WLAN è di 1 Gbit/s con una velocità massima di un singolo collegamento di 500 Mbit/s.

![[immagine43.png | center | 600]]

- WiMax è una tecnologia wireless che consente velocità di trasmissione di oltre 10 Mbit/s su distanze di decine di kilometri.