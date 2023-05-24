#include <stdio.h>
#include <stdlib.h>

struct array_dinamico 
{
    float *a;
    int c; /* capacità */
    int n; /* dimensione */
};

typedef struct array_dinamico array_dinamico;

array_dinamico array_init(); 
array_dinamico array_append(array_dinamico ad, float e);  
void array_print(array_dinamico ad);
array_dinamico array_insert(array_dinamico v, int p, float e);
array_dinamico array_pop(array_dinamico v);
int array_empty(array_dinamico v);

void main()
{
    int i;
    array_dinamico v = array_init(); /* v = [] */
    v = array_append(v, 3.14); /* v.append(3.14) */
    v = array_insert(v, 0, -8);
    for(i = 0; i < 10; i++)
    {
        v = array_append(v, i*10+i);
    }
    v = array_insert(v, v.n, -8);
    array_print(v);

    while(array_empty(v) == 0)
    {
        v = array_pop(v);
    }

    array_print(v);
}

/* Funzione che crea un array dinamico vuoto */
array_dinamico array_init()
{ 
    array_dinamico ad = {NULL, 0, 0};
    return ad;
}

/* Aggiunge un nuovo elemento in fondo all'array dinamico */
array_dinamico array_append(array_dinamico ad, float e)
{
    int i;
    float *b;
    if (ad.n == ad.c) /* se il numero di elementi è uguale alla dimensione dell'array */
    {
        ad.c = 1 + (ad.c)*2; /* raddoppio la dimensione dell'array */
        b = realloc(ad.a,(ad.c)*sizeof(float)); /* creo un nuovo array (b) con la dimensione raddoppiata del primo array (a) */
        if(b == NULL)
        {
            return ad;
        }
        ad.a = b; /* a assume l'array b */
    }
    ad.a[ad.n] = e; /* aggiungo e all'array in posizione n */
    (ad.n)++; /* incremento il contatore di elementi */

    return ad;
}

void array_print(array_dinamico ad)
{
    int i;
    printf("c = %d; n = %d\n", ad.c, ad.n);
    for(i = 0; i < ad.n; i++)
    {
        printf("\t%d ------ %f\n", i, ad.a[i]);
    }
}

/* 
   Inserisce e in posizione p di v.
   Precondizione: p >= 0 e p <= n.
*/
array_dinamico array_insert(array_dinamico v, int p, float e)
{
    int cur_pos;
    v = array_append(v, e);
    cur_pos = v.n-1;
    if(p < 0)
    {
       abort();
    }
    while(cur_pos > p)
    {
        /* Scambiare l'elemento in cur_pos con quello in posizione cur_pos-1 */
        v.a[cur_pos] = v.a[cur_pos-1];
        cur_pos--; /* Decremento cur_pos */
    }
    v.a[p] = e;
    return v;
}

array_dinamico array_pop(array_dinamico v)
{
    if(v.n == 0)
    {
        return v;
    }
    if(4*v.n < v.c)
    {
        /* Dimezziamo la capacità dell'array */
        v.a = realloc(v.a, (v.c/2 + 1)*sizeof(float));
        v.c = v.c/2 + 1;
    }
    v.n--; /* Riducendo il campo n l'ultimo elemento risulterà virtualmente eliminato. */
    return v;
}

/* 
   Costi: prima di una realloc devono essere eseguite almeno n/2 pop a costo costante.
   Il costo complessivo delle n/2+1 operazioni è n/2+n/2 quindi in mesia il costo di una
   operazione è costante.
*/

int array_empty(array_dinamico v)
{
    if(v.n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}