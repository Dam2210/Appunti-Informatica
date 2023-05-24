#include <stdlib.h>
#include <stdio.h>

/*
Scrivere un programma che dato un numero
N>0 di valori da inserire da tastiera, stampi a
video il massimo della sequenza inserita e la
posizione in cui tale valore è stato inserito.
• Supponiamo, per semplicità, che non ci siano
duplicati
• Esempio: N=5 sequenza: 3, 2, 9, 5, 1
Max=9 Pos=3 
*/

void carica_array();
void maxseq(int *p, int n); 

void main()
{   
    carica_array();
}

void carica_array()
{   
    int n;
    printf("Quanti valori vuoi inserire?:");
    scanf("%d", &n);
    printf("inserisci i %d valori...\n", n);
    if(n > 0)
    {
        int *p = malloc(sizeof(int)*n);
        int i;
        for (i = 0; i < n; i++)
        {
            printf("inserisci intero:");
            scanf("%d", &p[i]);
        }
        printf("l'array è:\n");
        for ( i = 0; i < n; i++)
        {
            printf("%d ", p[i]);
        }
        printf("\n");
        maxseq(p, n);
        
    }
    else
    {
        printf("devi inserire dei numeri...");
    }
}

void maxseq(int *p, int n)
{
    int i = 0;
    int j;
    int max = p[i];
    int pos = i;
    for (i = 0; i < n; i++)
    {
        if(max < p[i+1])
        {
            max = p[i+1];
            pos = i+1;
        }
    }
    printf("il numero massimo nell'array è: %d\n", max);
    printf("la posizione del numero è: %d\n", pos);  
}