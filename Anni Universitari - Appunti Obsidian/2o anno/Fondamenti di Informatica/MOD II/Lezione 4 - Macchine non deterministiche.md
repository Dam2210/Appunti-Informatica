>[!info]-
> Dispensa 2 paragrafo 2.3
## Strutture di $P$ e macchine di Turing non deterministiche

Fino ad ora non abbiamo posto alcun vincolo sulla struttura dell'insieme $P$ delle quintuple che definisce una particolare macchina di Turing.
Ricordiamo, che data una macchina di Turing a un solo nastro, definita sull'alfabeto $\Sigma$ e sull'insieme $Q$ di stati, un elemento $P$ è una quintupla $<q_1,s_1,s_2,q_2,m>$ il cui scopo è quello di indicare alla macchina quali azioni intraprendere, quando trovandosi nello stato interno $q_1$, la sua testina legge il simbolo $s_1$. Quindi una quintupla è una istruzione del linguaggio associato alle macchine di Turing, può essere vista come una istruzione condizionale:
- Se la macchina $T$ si trova nello stato interno $q_1\in Q$ e legge il simbolo $s_1\in \Sigma$ sul nastro, allora deve scrivere sul nastro il simbolo $s_2$, assumere lo stato interno $q_2$ e muovere la testina in accordo a quanto specificato da $m$.

Possiamo dire che $P$ è una corrispondenza che associa ad elementi dell'insieme $Q\times \Sigma$ (la condizione dell'istruzione) elementi dell'insieme $\Sigma \times Q \times \{destra,sinistra,ferma\}$ (le azioni da intraprendere). Ma di che tipo di corrispondenza si tratta?

### Totalità:
Non abbiamo detto nulla circa la totalità di tale corrispondenza, ossia se per ogni coppia $(q_1,s_1)\in(Q-Q_f)\times\Sigma$ (dove $q_1$ non è uno stato finale) esiste una tripla $(s_2,q_2,m)\in\Sigma\times Q\times \{destra,sinistra,ferma\}$ tale che $<q_1,s_1,s_2,q_2,m>\in P$. Questa questione è connessa alla verifica delle precondizioni:
- Quando progettiamo una macchina di Turing assumiamo che l'input venga scritto sul nastro in un certo formato, quindi che soddisfi un certo insieme di vincoli.
- Per esempio quando abbiamo progettato il trasduttore ad un nastro che calcola la somma di due numeri codificati in binario abbiamo assunto che le cifre del primo numero fossero scritte in celle consecutive, con la cifra più significativa a sinistra, che fossero immediatamente seguite (senza $\square$ intermedi) da $+$ e che quest'ultimo fosse subito seguito dalle cifre del secondo numero scritte in celle consecutive. Così la parola $1\square + 1$ non è un input valido per la nostra macchina.

Per questa ragione non abbiamo previsto alcuna quintupla i cui primi due elementi fossero $(q_0,\square)$.
In sostanza la corrispondenza $P$ può non essere totale: questo significa che, considerando $P$ come un insieme di quintuple, esso può non contenere le quintuple che iniziano con coppie di simboli $(stato\_attuale,simbolo\_letto)$ che si riferiscono a configurazioni del nastro che non rispettano le precondizioni che abbiamo previsto. In effetti, il codice di una macchina di Turing dovrebbe essere sempre fornito insieme alla specifica delle precondizioni rispetto alle quali ne garantiamo il corretto funzionamento: in tal modo, da un lato guidiamo l'utente all'utilizzo del nostro codice, dall'altro ci liberiamo delle responsabilità inerenti gli eventuali danni derivanti da un suo utilizzo improprio.

Resta da chiarire il significato che associamo all'assenza di una quintupla che inizi con un dato stato e un dato simbolo.
Consideriamo nuovamente la macchina di tipo riconoscitore ad un nastro $T$, supponiamo che questa si trovi nello stato $q$, che la sua testina legga il simbolo $s$ e che nell'insieme $P$ delle sue quintuple non esista alcuna quintupla che inizi con la coppia $(q,s)$: in tal caso, la macchina $T$ non riuscirà a raggiungere lo stato di accettazione. Possiamo quindi aggiungere all'insieme $P$ la quintupla $<q,s,s,q,fermo>$ senza alterare l'insieme delle parole accettate da $T$.

Uguale risulta la situazione nel caso di macchine di tipo trasduttore. Sia $T_t$ una macchina di tipo trasduttore, ad un nastro, che ad un certo passo della computazione iniziata con input $x\in\Sigma^*$, si trovi nello stato $q$ e con la testina che legge il simbolo $s$, nel caso in cui nell'insieme $P$ delle sue quintuple non esista alcuna quintupla che inizia con la coppia $(q,s)$: in tal caso, $T_t$ non è in grado di completare il suo compito, ossia $T_t$ non è in grado di produrre l'output corrispondente all'input $x$ che era scritto sul suo nastro all'inizio della computazione e che l'ha portata, nello stato $q$, a leggere $s$. Quindi la computazione $T_t(x)$ non produce alcun output. 

Possiamo quindi ora considerare una nuova macchina $T_t'$ il cui insieme delle quintuple $P'$ sia l'unione dell'insieme $P$ e dell'insieme delle quintuple aggiuntive $\{<q,(s,x),(s,x),q,fermo>:x\in\Sigma\}$ il cui comportamento coincide con il comportamento di $T_t:T_t'(x)=T_t(x)$ per ogni $x\in\Sigma^*$ tale che $T_t(x)$ calcola un output, e $T_t'(x)$ non termina per ogni $x\in\Sigma^*$ tale che $T_t(x)$ non calcola un output.

Infine possiamo sempre assumere che in ogni macchina di Turing la corrispondenza $P$ che definisce il suo insieme delle quintuple sia totale. Assumeremo da ora in poi che, ogni volta che nella descrizione dell'insieme $P$ delle quintuple di una macchina di Turing non descriveremo alcuna quintupla che inizi con la coppia $(q,\sigma)\in Q\times\Sigma$, allora $P$ conterrà la quintupla $<q,\sigma,\sigma,q,fermo>$.

### P è una corrispondenza o una funzione?
L'insieme P delle quintuple è una corrispondenza fra $Q\times \Sigma$ e $\Sigma\times Q \times\{destra,sinistra,ferma\}$. Negli esempi visti in precedenza tale corrispondenza si è rivelata essere una funzione, P non conteneva coppie di quintuple che avevano gli stessi due elementi iniziali. Questo corrisponde alla nostra idea intuitiva di algoritmo: una sequenza di istruzioni che devono essere eseguite ogni volta che si verifica una certa eventualità. Quando vogliamo verificare che una parola è palindroma, dobbiamo dire alla macchina che, se legge $a$ all'inizio della parola allora deve verificare che la parola termini con $a$. Non prendiamo in considerazioni altre eventualità. Il comportamento della macchina è totalmente determinato. Le macchine di Turing di questo genere vengono dette deterministiche.


 

