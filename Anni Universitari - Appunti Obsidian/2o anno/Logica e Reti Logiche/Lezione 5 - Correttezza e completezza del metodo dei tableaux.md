## Insiemi soddisfacibili e correttezza del metodo

Diciamo che una formula $\mathcal F$ è soddisfacibile se esiste una interpretazione in cui è $T$ (osservate che una formula è soddisfacibile se e solo se è o una tautologia o una contigenza). Diciamo che un insieme $S$ di formule è soddisfacibile, se esiste una interpretazione in cui tutte le formule di $S$ sono $T$.

## Insiemi di Hintikka e completezza del metodo

Per dimostrare la correttezza del metodo abbiamo usato la definizione di insiemi di formule soddisfacibili. Per dimostrarne la completezza introduciamo un'altra classe di insiemi di formule, che chiamiamo insiemi di Hintikka.

>[!important]- Definizione (Insiemi di Hintikka)
>Un insieme di formule $S$ per cui valgono le tre proprietà seguenti si chiama insieme di Hintikka:
>$H_0$: $S$ non contiene sia una variabile $p$ che la sua negata $\lnot p$;
>$H_1$: Se $S$ contiene una $\alpha-formula$, allora $S$ contiene anche entrambe le sue componenti $\alpha_1$ e $\alpha_2$; 
>$H_2$: Se $S$ contiene una $\beta-formula$ allora $S$ contiene anche almeno una delle sue componenti $\beta_1$ e $\beta_2$.

>Teorema 2.2: Se $\mathcal F$ è una tautologia allora è dimostrabile con il metodo dei tableaux.
>
>Dimostrazione: Se non fosse dimostrabile allora partendo da $\lnot \mathcal F$ ed espandendo tutte le formule di otterrebbe un tableau completo con almeno un ramo aperto $\theta$. L'insieme delle formule sul ramo $\theta$ quindi sarebbe un insieme di Hintikka. Ma ogni insieme di Hintikka è soddifacibile. Quindi in particolare sarebbe soddisfacibile la formula $\lnot \mathcal F$, che è assurdo perchè per ipotesi $\mathcal F$ è una tautologia.

## Conclusioni

Il metodo dei tableaux è un metodo di refutazione: per dimostrare che $\mathcal F$ è una tautologia, partiamo da $\lnot \mathcal F$ e verifichiamo che non è soddisfacibile.