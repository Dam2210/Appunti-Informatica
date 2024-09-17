//Si scriva un programma con tre thread che risolvono il seguente problema:
//Un buffer di n elementi inizializzato con a -1 viene riempito nel seguente modo:
//    - Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
//    - Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
//    - Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
//        buff[0] = buff[0], buff[1] = buff[1] + buff[0], buff[2] = buff[1] + buff[2]  quindi aggiungendo il valore attuale + il valore precedente.
//Si proponga una soluzione di mutua esclusione.

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

#define BUFFERSIZE 10 //definisco la dimensione del buffer

int buffer[BUFFERSIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //inizializzo la variabile per la mutua esclusione
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //inizializzo la variabile per la condizione

void StampaBuffer()
{
    for(int i=0; i<BUFFERSIZE; i++)
    {
        printf("[%d]--->%d\n", i, buffer[i]);
    }
}

void *num_posP()
{
    pthread_mutex_lock(&mutex); //metto a lock la variabile mutex creata
    for(int i = 0; i < BUFFERSIZE; i+=2)
    {
        // Inizializza il generatore di numeri casuali
        //srand(time(0));

        int num = rand() % 101;
        buffer[i] = num;
        printf("primo --> ho messo nella posizione %d il numero %d\n", i, num);
    }

    StampaBuffer();

    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    int sleeptime = rand() % 4;

    sleep(sleeptime);
}

void *num_posD()
{
    pthread_mutex_lock(&mutex); //metto a lock la variabile mutex creata
    for(int i = 1; i < BUFFERSIZE; i+=2)
    {
        // Inizializza il generatore di numeri casuali
        //srand(time(0));

        int num = (rand() % 101) + 100;
        buffer[i] = num;
        printf("secondo --> ho messo nella posizione %d il numero %d\n", i, num);
    }
    StampaBuffer();
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    int sleeptime = rand() % 4;

    sleep(sleeptime);
}

void *sommaBuffer()
{
    pthread_mutex_lock(&mutex);
    for(int i = 1; i<BUFFERSIZE; i++)
    {
        buffer[i] = buffer[i] + buffer[i-1];
    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
    int sleeptime = rand() % 4;

    sleep(sleeptime);
}

int main(int argc, char* argv[])
{
    srand(time(0));
    pthread_t p1, p2, p3;

    StampaBuffer();

    printf("-----------------------------------------------------------------\n");

    pthread_create(&p1, NULL, &num_posP, NULL);
    pthread_create(&p2, NULL, &num_posD, NULL);
    pthread_create(&p3, NULL, &sommaBuffer, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("-----------------------------------------------------------------\n");

    pthread_join(p3, NULL);

    StampaBuffer();

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}