#include <stdlib.h>
#include <stdio.h>

struct array_int
{
    int *a;
    int n;
};

typedef struct array_int array_int;

array_int array_init();
void print_array(array_int);
array_int array_append(array_int, int);
array_int applica_soglia(int*, int, int);
void rimuovi(array_int ad, int pos);

void main()
{
    array_int a = array_init();
    a = array_append(a, 3);
    a = array_append(a, 6);
    a = array_append(a, 4);
    a = array_append(a, 2);
    a = array_append(a, 1);
    a = array_append(a, 7);
    a = array_append(a, 5);
    printf("l'array caricato è: ");
    print_array(a);

    a = applica_soglia(a.a, a.n, 3);
    print_array(a);
}

/* Funzione che crea un array dinamico vuoto */
array_int array_init()
{
    array_int ad = {NULL, 0};
    return ad;
}

void print_array(array_int ad)
{
    int i;
    printf("n = %d\n", ad.n);
    for(i = 0; i < ad.n; i++)
    {
        printf("\t%d ------ %d\n", i, ad.a[i]);
    }
}

/* Aggiunge un nuovo elemento in fondo all'array dinamico */
array_int array_append(array_int ad, int e)
{
    int i;
    int *b;
    b = realloc(ad.a,(ad.n+1)*sizeof(int)); /* creo un nuovo array (b) */
    if(b == NULL)
    {
        return ad;
    }
    ad.a = b; /* a assume l'array b */
    ad.a[ad.n] = e; /* aggiungo e all'array in posizione n */
    (ad.n)++;  /* incremento il contatore di elementi */

    return ad;
}

array_int applica_soglia(int *a_int, int n, int t)
{
    int i;
    array_int ad;
    ad.a = a_int;
    ad.n = n;
    for (i = 0; i < ad.n; i++)
    {
        if(ad.a[i] < t)
        {
            rimuovi(ad, i);
            ad.n--;
            i--;
            
        }
    }
    return ad;
}

void rimuovi(array_int ad, int pos)
{
    int i;
    
    for (i = pos; i < ad.n-1; i++)
    {
        ad.a[i] = ad.a[i+1];
    }
    
}