#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

double saldo = 3000.00;

pthread_mutex_t mutex; //variabile globale per la mutua esclusione

void *conto()
{
    pthread_mutex_lock(&mutex); //via per il thread in esecuzione e rosso per gli altri
        int tipo;
        float importo;
        printf("immetti tipo: 1 = versamento, 2 = prelevameto\n");
        scanf("%d", &tipo);
        printf("immetti importo:");
        scanf("%f", &importo);
        if(tipo==1)
        {
            saldo+=importo;
        }
        else
        {
            saldo-=importo;
        }
    pthread_mutex_unlock(&mutex); //stop per il thread appena eseguito e anche per gli altri, via per il successivo
}

int main(int argc, char* argv[])
{
    pthread_t tid1,tid2,tid3,tid4;
    pthread_mutex_init(&mutex, NULL); //inizializzazione della variabile mutex creata, inizio ad usarla
    if(pthread_create(&tid1,NULL,&conto,NULL)!=0)
    {
        printf("Errore thread1\n");
    }
     if(pthread_create(&tid2,NULL,&conto,NULL)!=0)
    {
        printf("Errore thread2\n");
    }
     if(pthread_create(&tid3,NULL,&conto,NULL)!=0)
    {
        printf("Errore thread3\n");
    }
     if(pthread_create(&tid4,NULL,&conto,NULL)!=0)
    {
        printf("Errore thread4\n");
    }

    if(pthread_join(tid1,NULL)!=0)
    {
        printf("Errore Join tread 1\n");
    }
    if(pthread_join(tid2,NULL)!=0)
    {
        printf("Errore Join tread 2\n");
    }
    if(pthread_join(tid3,NULL)!=0)
    {
        printf("Errore Join tread 3\n");
    }
    if(pthread_join(tid4,NULL)!=0)
    {
        printf("Errore Join tread 4\n");
    }
    /*
    Con pthread_join ogni thread aspetta che gli altri thread finiscano il lavoro per proseguire.

    La funzione pthread_join è utilizzata per attendere che un thread creato con pthread_create termini la sua esecuzione. In altre parole, pthread_join permette di sincronizzare il thread chiamante con un thread specifico, aspettando che quest'ultimo completi il suo lavoro.
    Firma della funzione:

    c

    int pthread_join(pthread_t thread, void **retval);

    Argomenti:

    pthread_t thread:
        È l'identificatore del thread che si desidera attendere. Questo identificatore è stato ottenuto quando il thread è stato creato usando pthread_create.
        Esempio: Se hai creato un thread con pthread_t t;, passerai t come primo argomento a pthread_join.

    void **retval:
        È un puntatore a un puntatore che riceverà il valore di ritorno della funzione eseguita dal thread. Se non sei interessato a questo valore, puoi passare NULL.
        Se la funzione del thread ha restituito un valore usando pthread_exit, questo valore sarà disponibile qui.
        Esempio: Se desideri catturare il valore di ritorno, puoi dichiarare una variabile void *result; e passarla come secondo argomento: &result.

    Cosa fa pthread_join:

    Blocca il thread chiamante fino a quando il thread specificato non termina.
    Se il thread specificato ha già terminato, pthread_join restituisce immediatamente.
    Può anche ottenere il valore restituito dal thread che termina, se la funzione del thread restituisce un risultato.
    */

   printf("Saldo: %f", saldo);
   pthread_mutex_destroy(&mutex); //distruggo la mutex che ha finito il suo lavoro.
   return 0;
}