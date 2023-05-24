## Internet
Faremo riferimento a Internet per studiare i protocolli che consentono di comunicare a dispositivi di vario tipo.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine1.png]]

- Internet è una rete di reti che collega tra loro miliardi di dispositivi di vario tipo sparsi in tutto il mondo. Inizialmente, alla rete erano connessi prevalentemente computer come server, PC, workstation e portatili. Attualmente, sono connessi alla rete anche molti altri tipi di dispositivi, come macro controller, smartphone, stampanti, camere IP, sensori, elettrodomestici  etc. Indicheremo tutti questi tipi di dispositivo con il termine host o end system.
- Gli host sono connessi tra loro mediante linee di comunicazione (link) e dispositivi di commutazione, tra i quali router e switch. Esistono vari tipi di linee di comunicazione, detti mezzi trasmissivi, di diversa tecnologia, come ad esempio cavi elettrici costituiti da varie coppie di doppioni in rame, cavi coassiali, fibre ottiche e onde radio con portanti a varia frequenza.
- Un importante parametro che caratterizza le varie tecnologie di link è la velocità di trasmiassione (o larghezza di banda) che si misura in multipli di bit/secondo (Kbps, Mbps, Gbps).
	In internet si usa prevalentemente la commutazione di pacchetto (packet switching), una tecnica che permette a più host di condividere un percorso, o parte di esso.
	
![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine2.png]]

- Un host per inviare i dati ad altri host, li frammenta in piccoli parti e aggiunge a ciascuna parte un'intestazione: l'informazione ottenuta prende il nome di pacchetto.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine3.png]]

- Un router è un dispositivo dotato di varie porte ingresso/uscita. I pacchetti, quando arrivano a una porta di ingresso, in base a specifici protocolli di instradamento, sono rinviati a una delle sue porte di uscita.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine4.png]]

- Un pacchetto, partendo dall'host sorgente e attraversando una serie di linee di comunicazione e router fino all'host ricevente, compie un tragitto detto percorso (path) o cammino (route).

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine5.png]]

- Gli host sono connessi a Internet attraverso Internet Service Provider (ISP) come ad esempio gli ISP per l'utenza privata, gli ISP aziendali e gli ISP universitari. Ogni ISP è costituito da una rete di router e di linee di comunicazione.
- I diversi ISP si caratterizzano per le diverse tecnologie di accesso alla rete, con differenti larghezze di banda, come ad esempio l'accesso via DSL, l'accesso wireless e l'accesso via LAN ad alta velocità.
- I suddetti ISP, detti di livello inferiore sono interconnessi attraverso ISP di livello superiore (regionali, nazionali e internazionali).
- Gli ISP di livello superiore utilizzano router ad alte prestazioni interconnessi mediante linee ad alta velocità in fibra ottica. La rete di ogni ISP è gestita in modo autonomo sia a livello tecnico che amministrativo.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine6.png]]

>Esitono anche reti, appartenenti a società private o enti statali, i cui host sono generalmente parzialmente o del tutto isolati dalla rete pubblica mediante firewall, tecnologie hardware/software, che servono a limitare e selezionare il traffico in entrata e in uscita dalla rete.
>Queste sono reti chiamate Intranet.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine7.png]]

## Protocolli di rete

- Gli host, i router, gli switch e altri dispositivi, usano molti protocolli per scambiarsi dati tra loro.
- I due principali protocolli di internet sono il TCP (Transmission Control Protocol, Protocollo di Controllo della Trasmissione) e l'IP (Internet Protocol, Protocollo Internet). I due protocolli sono chiamati spesso con l'unico termine TCP/Ip
- Un protocollo definisce:
	- le strutture dei messaggi e l'ordine in cui essi sono trasmessi tra due o più dispositivi, 
	- le operazioni che sono eseguite al momento della trasmissione e alla ricezione di messaggi (di dati o di controllo), o di altri eventi.

Ad esempio:
- Specifici protocolli utilizzati nei router stabiliscono il percorso che il pacchetto seguirà dalla sorgente alla destinazione.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine8.png]]

- Negli host un protocollo di controllo del flusso regola la velocità con cui i pacchetti sono trasmessi tra la sorgente e la destinazione. Questa regolazione consente la comunicazione tra host veloci e host lenti.

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine9.png]]

- Un protocollo oltre che di tipo software può anche essere di tipo hardware, ad esempio le dimensioni dei connettori presenti nelle schede di rete consentono la connessione fisica degli host a qualche tipo di dispositivo di rete, etc..

![[Anni Universitari - Appunti Obsidian/2o anno/Sistemi Operativi e Reti/MOD II/Immagini Lezioni - SOR MOD II/immagine10.png]]

## Applicazione client e server

- In questi anni, sono state realizzate molte applicazioni per internet, le quali consentono il traferimento di informazioni tra gli host. ALcune delle più diffuse applicazioni sono: posta elettronica, Web, condivizione di file peer-to-peer (P2P), chat , streaming audio e video , telefonia su Internet e login remoto.
- Il modello client/server è il modello più usato per realizzare le applicazioni di rete. Con tale modello un'applicazione  di rete si realizza in due parti: il lato client che gira su un host che richiede servizi e un lato server chegira su un host che fornisce servizi. Per estensione, gli host sono chiamati rispettivamente client e server.
- Il lato client e il lato server comunicano tra loro mediante vari protocolli.
- Tipicamente i server, a livello hardware, sono macchine molto potenti sulle quali sono installati server Web, DBMS, server di posta elettronica, applicazioni web e altri servizi.
- Esempi di applicazione che usano il modello client/server sono la posta elettronica, il Web, login remoti (come ssh e telnet), il trasferimento di file (FTP), e molte altre applicazioni.

## Servizi senza connessione e servizi orientati alla connessione

- Le applicazioni sviluppate per la rete Internet, utilizzano protocolli basati su due tipi di servizio: servizio orientato alla connessione e servizio senza connessione.
	- Il servizio orientato alla connessione è affidabile e garantisce che i dati trasmessi da un host mittente giungeranno al destinatario senza errori e nello stesso ordine con cui sono stati spediti.
	- Il servizio senza connessione non è affidabile e non garantisce che tutti i dati inviati dall'host mittente giungano a destinazione.
- Ad esempio la posta elettronica e il Web utilizzano il servizio orientato alla connessione mentre un'applicazione per la telefonia su Internet utilizza il servizio senza connessione.
- Attualmente (2019), Internet può consentire servizi in soft real-time ma non fornisce servizi in hard real-time, cioè servizi che garantiscono che i dati inviati dal mittente arrivino al destinatario entro un tempo stabilito (deadline).

## Servizio orientato alla connessione

- Con il servizio orientato alla connessione, le applicazioni client e server, prima di inviare i dati veri e propri, ad esempio messaggi di posta elettronica, eseguono una procedura detta handshaking (stretta di mano) mediente la quale si scambiano informazioni di controllo. La connessione tra due host si considera instaurata al termine della procedura di handshaking.
- Generalmente, il servizio orientato alla connessione è alquanto complesso ed è realiazzato in un insieme di servizi, come il trasferimento di dati affidabile, il controllo del flusso, il controllo della congestione.
- Il trasferimento di dati di dice affidabile, quando un'applicazione è in grado di trasmettere tutti i dati che invia senza errori e nell'ordine di partenza. L'affidabilità è ottenuta attraverso l'invio di messaggi di riscontro ed eventuali ritrasmissioni, nel caso si perdessero dati.

>[!info]- Esempio:
>Consideriamo ad esempio un'applicazione di rete tra due host A e B. L'host A invia a B uno o più pacchetti. Quando B riceve i pacchetti avvisa A inviando un messaggio di riscontro di avvenuta ricezione. Quando l'host A riceve il messaggio di riscontro è sicuro che i corrispondenti pacchetti sono stati completamente ricevuti. Se A non ottiene da B il messaggio di riscontro stabilisce che i pacchetti non sono stati ricevuti, e allora li ritrasmette.
>
>![[immagine11.png]]

- Il controllo del flusso garantisce che il mittente in fase di trasmissione non saturi il buffer di ricezione del destinatario, inviando pacchetti ad una velocità elevata. Infatti, il destinatario potrebbe non essere in grado di adattarsi alla velocità con cui il mittente invia i pacchetti. In tal caso, il servizio di controllo del flusso, diminuisce la velocità di trasmissione del mittente.
- Il servizio di controllo della congestione consente di prevenire che la rete entri in uno stato di congestione a causa di un traffico di pacchetti eccessivo. Quando ad un router arrivano in brevissimi intervalli di tempo troppi pacchetti, la sua memoria (buffer) può riempirsi causando quindi una perdita di pacchetti. Se gli host continuano ad inviare pacchetti alla maggiore velocità possibile, si verifica una perdita di pacchetti. Il controllo della congestione diminuisce la velocità di trasmissione degli host mittenti durante i periodi di congestione. Questi protocolli rilevano lo stato di congestione quando non ricevono più i riscontri di avvenuta ricezione dei pacchetti inviati.
- Il TCP (Transmission Control Protocol) è il protocollo standard "de facto" usato in Internet che implementa il servizio orientato alla connessione. Esso implementa i servizi di trasferimento di dati affidabile, di controllo del flusso e di controllo della congestione.
- Le applicazioni Internet più diffuse come ad esempio SMTP (posta elettronica), FTP (trasferimento di file) e HTTP (Web), ssh (login remoto) usano il TCP.

## Servizio senza connessione

- Il servizio senza connessione non esegue la procedura iniziale di handshake. Quando un lato di un'applicazione invia i pacchetti a l'altro lato li invia immediatamente. Poichè manca la procedura di handshake e i messaggi di riscontro da parte del ricevente, la velocità di trasmissione è più elevata. Ma la mancanza di messaggi di riscontro dell'avvenuta ricezione, non consente al mittente di avere la garanzia che i pacchetti siano arrivati a destinazione.
- inoltre, il servizio senza connessione non possiede i controlli di flusso e di congestione. Questa mancanza di servizi in alcuni casi potrebbe provocare problemi di congestione del traffico.
- L'UDP (User Datagram Protocol) è il protocollo usato in Internet che implementa il servizio senza connessione.
- L'UDP, è usato da molte applicazioni multimediali, come la telefonia Internet, l'audio e video a richiesta (on demand) e le video conferenze.



