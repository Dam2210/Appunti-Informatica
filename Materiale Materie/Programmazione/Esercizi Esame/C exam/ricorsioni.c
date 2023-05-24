#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma C che, dato un numero
calcola la somma dei primi N numeri pari positivi in
maniera ricorsiva.*/

int somma_pari(int);

void main()
{
    int ris;
    ris = somma_pari(4);
    printf("somma dei primi 4 numeri interi:%d\n", ris);
}

int somma_pari(int a)
{
    int somma;
    if(a == 1)
    {
        return 2;
    }
    else
    {
        return 2*a + somma_pari(a-1);
    }
}