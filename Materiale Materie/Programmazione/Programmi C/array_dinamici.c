#include <stdio.h>
#include <stdlib.h>

int *append(int *a, int *c, int *n, int e)
{
    int *b, i;
    if (*n == *c) /* se il numero di elementi è uguale alla dimensione dell'array */
    {
        *c = (*c)*2; /* raddoppio la dimensione dell'array */
        b = malloc((*c)*sizeof(int)); /* creo un nuovo array (b) con la dimensione raddoppiata del primo array (a) */
        for(i = 0; i < *n; i++)
        {
            b[i] = a[i]; /* copio ogni elemento di a dentro l'array b finchè i due array non hanno stesso numero di elementi */
        }
        free(a); /* dealloca dalla memoria l'array a */
        a = b; /* a assume l'array b */
    }
    a[*n] = e; /* aggiungo e all'array in posizione n */
    (*n)++; /* incremento il contatore di elementi */

    return a; 
}

void print_array_dinamico(int *a, int n)
{
    int i; 
    for(i = 0; i < n; i++)
    {
        printf("%d, ", a[i]); /* stampo l'array */
    }
    printf("\n");
}

void main()
{
    int *a = NULL;
    int c = 10; /* dimensione dell'array a */
    int n = 0; /* numero di elementi memorizzati in a */
    int i;
    a = malloc(c*sizeof(int)); /* alloco memoria per a di dimensione c per la dimensione delle variabili di tipo int */

    for (i = 0; i < 10; i++) /* finchè l'array ha meno di 10 elementi continuo ad aggiungere valori */
    {
        a = append(a, &c, &n, i*10); /* aggiungo valori tramite la funzione append strutturata in precedenza */
        print_array_dinamico(a, n); /* stampo l'array dinamici tramite la funzione print strutturata in precedenza */
        printf("%d, %d\n", n, c); /* stampo il numero di elementi e la dimensione dell'array */
    }

}