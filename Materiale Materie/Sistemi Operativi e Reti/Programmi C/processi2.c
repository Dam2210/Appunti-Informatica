//Un processo padre genera due processi figli.
//Il primo processo figlio invia al padre un numero casuale da 0 a 100.
//Il padre legge questo numero, lo moltiplica per un k causale e lo manda al secondo figlio.
//Il secondo figlio legge il numero inviato dal padre e lo stampa a video.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h> //serve per usare la chiamata wait

#define READ 0
#define WRITE 1

int main()
{
    //questa istruzione va messa all'inizio del main ogni volta che si vuole utilizzare la funzione random
    //serve ad inizializzare la funzione casuale
    srand(time(NULL));

    //creo 2 figli istanziando 2 variabili di tipo pid_t
    pid_t ch1, ch2; //pid_t potrebbe risultare come errore ma è un bug di visual studio

    //istanzio le 2 pipe (ogni pipe è un array di interi)
    int pipe1[2], pipe2[2];

    pipe(pipe1); //creo la pipe1
    pipe(pipe2); //creo la pipe2

    ch1 = fork();

    //controllo errori nella creazione del primo figlio
    if(ch1 < 0)
    {
        printf("Errore nella creazione del primo processo figlio\n");
    }
    if(ch1 == 0) //primo processo figlio creato correttamente
    {
        //utilizzo la pipe per scrivere il numero generato al padre (quindi utilizzerò il canale WRITE)
        //chiudo quindi il canale di lettura READ visto che non lo utilizzerò
        close(pipe1[READ]);

        int num = rand() % 101;

        printf("[Primo figlio] --> Ho generato il numero: %d\n",num);

        write(pipe1[WRITE], &num, sizeof(num)); //lo invio al padre

        printf("[Primo figlio] --> Ho inviato il numero %d al padre\n", num);

        close(pipe1[WRITE]);

        exit(0); //chiude primo processo figlio, evito kill dal padre
    }
    else
    {
        ch2 = fork();

        if(ch2 < 0)
        {
            printf("Errore nella creazione del secondo figlio\n");
        }
        if(ch2 == 0) //secondo processo figlio creato correttamente
        {
            //codice secondo figlio

            //chiudo il canale di scrittura visto che non lo utilizzerò ma dovrò leggere
            close(pipe2[WRITE]);
            close(pipe1[READ]);
            close(pipe1[WRITE]);

            //creo una variabile intera in cui salvo il numero che invierà il padre al secondo figlio
            int numRicevuto;

            //leggo il numero inviato dal padre utilizzando la funzione READ
            //la funzione READ accetta come parametri:
            //pipe e canale nel quale si vuole scrivere/leggere
            //dove salvare il numero letto
            //dimensione del numero sizeof(...)
            read(pipe2[READ], &numRicevuto, sizeof(numRicevuto));

            printf("[Secondo figlio] --> Ho letto il numero %d inviato dal processo padre\n", numRicevuto);

            close(pipe2[READ]);

            exit(0);
                
            
        }
        else
        {
            //codice del padre

            //chiudo il canale di scrittura della prima pipe e il canale di lettura della seconda pipe
            //chiudo il canale di scrittura della prima pip perchè dovrò solo leggere il numero inviato dal primo figlio
            //chiudo il canale di lettura della seconda pipe perchè dovrò solo scrivere il numero
            close(pipe1[WRITE]);
            close(pipe2[READ]);

            //creo una variabile intera che salva il numero letto dal primo figlio
            int numRicevutoFiglio;

            read(pipe1[READ], &numRicevutoFiglio, sizeof(numRicevutoFiglio));

            //genero un numero casuale da 0 a 10 per il quale moltiplicherò il numero ricevuto
            int k = rand() % 11;

            //moltiplico il numero ricevuto per k
            int numDaInviare = numRicevutoFiglio * k;

            //comunico il numero al secondo figlio tramite la pipe utilizzando la funzione WRITE
            write(pipe2[WRITE], &numDaInviare, sizeof(numDaInviare));

            printf("[Padre] --> Ho inviato il numero %d * %d = %d al secondo processo figlio\n", numRicevutoFiglio, k, numDaInviare);

            close(pipe2[WRITE]);
                
            wait(NULL);//aspetto terminazione primo processo figlio
            wait(NULL);//aspetto terminazione secondo processo figlio
        }
    }
    return 0;
}