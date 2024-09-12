#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h> //per usare rand()
// nella compilazione usare -lpthred per usare i thread

typedef struct
{
    int r;
    char c;
}param; //definisco i parametri da passare al thread tramite questa struttura e posso passarla tramite il parametro *arg definito nel thread void *cavallo(void *arg)

char vincitore = 0;

void *cavallo(void *arg) //struttura del prototipo thread cavallo
{
    int cl; //variabile colonna inizializzata nel processo
    int rg;
    char ch;
    param *c;//serve dichiarare all'interno del thread un operatore di tipo param per passare gli argomenti al thread e fare un casting su *arg
    c=(param *) arg; //faccio il casting in questo modo sull'argomento del thread
    rg=c->r++; //memorizzo la coordinata di riga e la incremento
    ch=c->c++; //faccio la stessa cosa con il carattere c
    for(cl=0; cl<30; cl++)
    {
        printf("\033[%d;%dH%C]", rg, cl, ch); // (rg = riga, cl = colonna, ch = carattere) vanno passati nella variabile *arg del prototipo tranne cl che è interna al processo
        fflush(stdout); //stampa forzatamente a video
        sleep(rand()%2); //il thread si sospende per un tempo random per simulare il carattere che verrà stampato poco a poco
    }
    if(vincitore==0)
    {
        vincitore = ch;
    }
    pthread_exit(0);

    
}

int main(int argc, char **argv)
{
    pthread_t t[20]; //inizializzo un'array di thread t[20] -> inizializzo quindi 20 thread

    int i;
    param *p; //serve dichiarare un puntatore di tipo param (struttura definita a inizio programma) per passare i parametri al thread
    //serve dichiarare un puntatore che punta al numero di byte in memoria alla struttura param definita in precedenza
    p=malloc(sizeof(param));//serve allocare per *p la dimensione di memoria per allocare le variabili r e c definite nella struttura param a inizio programma
    p->r=1; //inizializzo la variabile r a 1 della struttura dati
    p->c='A'; //inizzializzo la variabile c con 'A', questi sono i miei due punti di partenza
    for(i=0; i<20; i++)
    {
        pthread_create(&t[i], NULL, cavallo, p); //ad ogni thread inizializzato tramite il for passo l'indirizzo di memoria del thread e gli assegno un cavallo tramite il prototipo a inizio programma
        //passo p al thread a questo punto perchè definito in precedenza tramite la struttura dati definita da me
        /*
        -----------------------------------------------------------------------------------------------------------------------------------------------------------
        La funzione `pthread_create` viene utilizzata per creare un nuovo thread in un programma C che utilizza i thread POSIX. La sua firma è:

        ```c
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
        ```

        Ecco una spiegazione dettagliata dei suoi argomenti:

        ### 1. **`pthread_t *thread`** (identificatore del thread)
        - Questo è un puntatore a una variabile di tipo `pthread_t` dove verrà memorizzato l'identificatore del thread creato. Questo identificatore verrà usato per riferirsi al thread, ad esempio, quando vuoi aspettare che termini con `pthread_join`.
        - **Esempio**: Se hai dichiarato `pthread_t t1;`, allora passeresti l'indirizzo di questa variabile: `&t1`.

        ### 2. **`const pthread_attr_t *attr`** (attributi del thread, opzionale)
        - Questo argomento specifica gli attributi del thread che si vuole creare, come la dimensione dello stack, la priorità e la modalità di joinability. Può essere utilizzato per personalizzare il comportamento del thread.
        - Se non vuoi impostare attributi personalizzati, puoi passare `NULL`, che significa che verranno utilizzati gli attributi predefiniti.
        - **Esempio**: `NULL` per usare gli attributi di default, oppure un puntatore a un oggetto `pthread_attr_t` per attributi specifici.

        ### 3. **`void *(*start_routine)(void *)`** (funzione da eseguire nel thread)
        - Questo è un puntatore alla funzione che il thread eseguirà quando verrà creato. La funzione deve avere la seguente firma:
            ```c
            void *funzione(void *arg);
            ```
        - La funzione prende un singolo argomento di tipo `void *` e restituisce un valore di tipo `void *`. Questo consente di passare qualsiasi tipo di dato alla funzione utilizzando il cast a `void *`.
        - **Esempio**: Se vuoi che il thread esegua una funzione chiamata `worker`, passeresti `worker` come terzo argomento.

        ### 4. **`void *arg`** (argomento da passare alla funzione)
        - Questo è il singolo argomento che viene passato alla funzione indicata da `start_routine`. È di tipo generico `void *`, quindi può rappresentare un puntatore a qualsiasi tipo di dato.
        - **Esempio**: Se la funzione ha bisogno di un argomento (es. un numero), puoi passare il puntatore a quel dato (es. `&n`). Se non hai bisogno di passare argomenti, puoi passare `NULL`.

        ### Esempio di utilizzo di `pthread_create`:

        ```c
        #include <pthread.h>
        #include <stdio.h>

        void *my_thread_function(void *arg) {
            int num = *((int *)arg);  // Cast dell'argomento e utilizzo
            printf("Thread %d in esecuzione\n", num);
            return NULL;
        }

        int main() {
            pthread_t t;
            int arg = 42;

            // Creazione del thread
            pthread_create(&t, NULL, my_thread_function, &arg);

            // Attesa della terminazione del thread
            pthread_join(t, NULL);

            return 0;
        }
        ```

        In questo esempio:
        - Il puntatore a `t` è passato come primo argomento, dove l'identificatore del thread sarà memorizzato.
        - Vengono usati gli attributi predefiniti (`NULL`).
        - La funzione `my_thread_function` è il codice che verrà eseguito dal thread.
        - L'argomento `&arg` viene passato come input alla funzione eseguita dal thread.
        -------------------------------------------------------------------------------------------------------------------------------------------------------------------
        */
    }

    for(i=0; i<20; i++)
    {
        pthread_join(t[i], NULL);
    }
    printf("vincitore:%c\n", vincitore);
    return 0;
}

/* clear && ./a.out -> per eseguire*/