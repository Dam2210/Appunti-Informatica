//Scrivere un programma in C con tre thread che operano su due array di dimensione N con tutti gli elementi a 0.
//
//Il primo thread scrive in un array A numeri casuali tra 1 e 150, scrivendo un numero per volta in posizioni randomiche.
//Il secondo thread scrive in un array B numeri cassuali tra 150 e 300, scrivendo un numero per volta in posizioni randomiche.
//Il terzo thread controlla se entrambi gli array sono stati inizializzati, in caso affermativo calcola il massimo in A e in B, calcola il minimo in A e in B. Infine determina il max{max(A), max(B)} e il min{min(A), min(B)}.


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

#define BUFFERSIZE 10 //definisco la dimensione del buffer

int arrayA[BUFFERSIZE] = {0,0,0,0,0,0,0,0,0,0};
int arrayB[BUFFERSIZE] = {0,0,0,0,0,0,0,0,0,0};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //inizializzo la variabile per la mutua esclusione
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; //inizializzo la variabile per la condizione

void StampaArray(int *array)
{
    for(int i=0; i<BUFFERSIZE; i++)
    {
        printf("[%d]--->%d\n", i, array[i]);
    }
}

int ArrayInizializzato(int *array)
{
    for(int i=0; i<BUFFERSIZE; i++)
    {
        if(array[i]==0)
        {
            return 0;
        }
    }
    return 1;
}

int maxInArray(int *array)
{
    int appo = array[0];
    for(int i = 1; i<BUFFERSIZE; i++)
    {
        if(appo<array[i])
        {
            appo = array[i];
        }
    }
    return appo;
}

int minInArray(int *array)
{
    int appo = array[0];
    for(int i = 1; i<BUFFERSIZE; i++)
    {
        if(appo>array[i])
        {
            appo = array[i];
        }
    }
    return appo;
}

void *PrimaFunc()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);

        int position = rand() % 11; //scelta posizione randomica nel array

        int num = (rand() % 150) + 1; //scelgo la posizione che devo far scegliere al buffer casualmente

        arrayA[position] = num;

        printf("[Primo] - Ho scritto %d  nella posizione %d\n", num, position);

        //invia un segnale a tutti i thread in attesa che sta rilasciando il mutex
        pthread_cond_signal(&cond);

        //sblocco il mutex
        pthread_mutex_unlock(&mutex);
        
        sleep(1);
    }
}

void *SecondaFunc()
{
        while(1)
    {
        pthread_mutex_lock(&mutex);

        int position = rand() % 11; //scelta posizione randomica nel array

        int num = (rand() % 151) + 150; //scelgo la posizione che devo far scegliere al buffer casualmente

        arrayB[position] = num;

        printf("[secondo] - Ho scritto %d  nella posizione %d\n", num, position);

        //invia un segnale a tutti i thread in attesa che sta rilasciando il mutex
        pthread_cond_signal(&cond);

        //sblocco il mutex
        pthread_mutex_unlock(&mutex);
        
        sleep(1);
    }
}

void *TerzaFunc()
{
    pthread_mutex_lock(&mutex);

    //con questo loop aspetto che i due array siano inizializzati
    while((ArrayInizializzato(arrayA) == 0) || (ArrayInizializzato(arrayB) == 0))
    {
        
        //se mi trovo qua dentro significa che il buffer non è inizializzato e devo aspettare che i 2 thread lo inizializzino
        printf("[Terzo] - Array non inizializzati attendo\n");
        //stampo semplicemente il buffer
        printf("-------arrayA-------\n");
        StampaArray(arrayA);
        printf("-------arrayB-------\n");
        StampaArray(arrayB);

        //mi metto in attesa tramite la variabile di condizione sul mutex
        //ogni volta che verrà lanciata una SIGNAL sulla variabile di condizione verrò risvegliato
        pthread_cond_wait(&cond,&mutex);
    }

    printf("-------arrayA inizializzato-------\n");
    StampaArray(arrayA);
    printf("-------arrayB inizializzato-------\n");
    StampaArray(arrayB);

    int maxA = maxInArray(arrayA);
    int maxB = maxInArray(arrayB);
    int minA = minInArray(arrayA);
    int minB = minInArray(arrayB);

    if(maxA > maxB)
    {
        printf("il massimo è nell'arrayA: %d\n", maxA);
    }
    else
    {
        printf("il massimo è nell'arrayB %d\n", maxB);
    }

       if(minA < minB)
    {
        printf("il minimo è nell'arrayA: %d\n", minA);
    }
    else
    {
        printf("il minimo è nell'arrayB %d\n", minB);
    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);

    exit(0);

}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    pthread_t p1, p2, p3;

    pthread_create(&p1, NULL, PrimaFunc, NULL);
    pthread_create(&p2, NULL, SecondaFunc, NULL);
    pthread_create(&p3, NULL, TerzaFunc, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    pthread_join(p3, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}