## Programma

### Programmazione ad Oggetti
Linguaggio di esempio: Java

### Programmazione dichiarativa
Linguaggio di esempio: Prolog
Compagno di viaggio: Ivan Bratko, Prolog Programming for Artificial Intelligence, Addison Wesley ($4^a$ edizione)

### Programmazione Funzionale
Linguaggio di esempio: Python
Compagno di viaggio: dispense del corso

## Da che mondo veniamo?

### Domande 
- Quali sono i problemi che possiamo risolvere?
- Come li risolviamo?
	- Attraverso delle procedure che sono sequenze di ordini
	- Queste sono in genere raccolte in funzioni, procedure, e/o metodi
- E' accettato che tutto ciò che è computabile è risolvibile attraverso delle macchine basate su delle procedure

## Esempio 1: Costruire un Cruciverba

- Primo problema: vogliamo costruire gli incastri di parole per un cruciverba

### Risoluzione
- Predisponiamo lo schema
- Indichiamo le parole che possiamo usare
- Il programma deve decidere:
	- Quali parole usare
	- Come riempire lo schema

![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine1.png]]
![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine2.png]]
- Scrivere un programma che permetta di trovare tutte le soluzioni ammesse.

## Esempio 2: Colorare una mappa

- Classico problema: usando un certo numero di colori, trovare una colorazione della mappa tale che 2 stati adiacenti non abbiano lo stesso colore. (graph colouring)

- Dati iniziali
![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine3.png]]
- Risultato atteso
![[Anni Universitari - Appunti Obsidian/2o anno/Linguaggi e Metodologie di Programmazione/MOD II/Immagini LMP MOD II/immagine4.png]]
- Scrivere un programma che permetta di trovare tutte le soluzioni ammesse

## Esempio 3: Organizzare una giornata di lavoro in team

- Si vuole organizzare una giornata di lavoro in cui:
	- Ci devono essere tre sessioni per i tre argomenti del progetto: intelligenza artificiale, bioinformatica e database
	- Ci sono due orari possibili: mattina e pomeriggio
	- Ogni sessione deve avere un argomento e deve avere almeno due persone esperte del argomento
- Problema
	Assegnare l'orario e gli esperti per ciascuna delle sessioni
- Scrivere un programma che permetta di trovare tutte le soluzioni ammesse.

