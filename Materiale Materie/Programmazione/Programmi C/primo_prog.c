#include <stdio.h>

void main() /* questa è l'inizio della funzione e va indicato con main() void indica che non c'è un return alla fine della funzione */
{
    int x = 2; /* Dichiarazione e inizializzazione della variabile intera x */
    float y; /* Dichiarazione variabile y di tipo float */
    char c = 'd';
    char s[] = "questa stringa finisce qua";
    int i;
    x = x+1;
    printf("\tQuesto è un programma scritto in C \n"); /* \t serve per la tabulazione e \n per andare a capo*/
    printf("il valore corrente di x e': %d\n", x); /* %d assume il valore di una variabile di tipo int */

    y = x+6.5; /* inizializzazione variabile y */
    printf("il valore di y è: %f\n", y); /* %f assume il valore della variabile di tipo float */

    x = y+0.5;
    printf("il valore corrente di x è: %d\n", x);

    printf("il valore corrente di c è: %c\n", c); /* %c assume il valore della variabile di tipo char */
    printf("il valore corrente della stringa s è: %s\n", s); /* %s assume il valore della variabile di tipo string */
    printf("il valore corrente di s[%d] è: %c\n", 3, s[3]); /* Questo stampa il carattere in posizione 3 della stringa s */

    i = 0;
    while(i<7) /* ciclo che continua finchè i è minore di 7 */
    {
        printf("\t%c\n", s[i]); 
        i += 1; /* incremento del contatore */
    }

    i = 0;
    while (s[i] != '\0') /* \0 è il carattere speciale che indica la fine della stringa */
    {
        printf("\t%c\n", s[i]); /* stampa tutti i caratteri della stringa */
        i += 1; /* incremento del contatore */
    }
    printf("la lunghezza totale della stringa s è: %d\n", i); /* i in questo caso sarà la lunghezza della stringa */
    printf("ciao\n");
}

/*per compilare il programma sul terminale:
gcc primo_prog.c
per lanciare il programma:
./a.out
per rinominare il file eseguibile:
mv a.out programma_eseguibile

per compilare il programma appena creato e creare direttamente l'eseguibile:
gcc primo_prog.c -o primo_prog
per eseguirlo:
./primo_prog
*/