#include <stdio.h>
#include <stdlib.h>

#define C 100000 /* definisco una costante che prende il valore indicato per tutto il programma */

void print_array_int(int *x, int n) /* x è un puntatore ad un intero e si indica con il tipo e l'asterisco(*) */
{
    int i;

    printf("Numero di byte di x: %ld\n", sizeof(x));

    for(i = 0; i < n; i++)
    {
        printf("%d, ", *(x+i));
    }
    printf("\n");
}

int *crea_array_int(int n)
{
    int size = n * sizeof(int);
    int *p = malloc(size); /* funzione che verifica se ci sono byte liberi consecutivi identificati da "size", se ci sono li assegna alla variabile. */
    int i;

    if (p != NULL) /* ho l'array */
    {
        for(i = 0; i < n; i++) 
        {
            p[i] = 0;
        }
    }
    return p;
}

void main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; /* definisco i valori presenti nell'array */
    int *p = NULL; /* p è un puntatore */
    int  n = sizeof(a)/sizeof(int);
    int i;
    int b[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int c[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    float e = 2.71;

    printf("Numero di byte di a: %ld\n", sizeof(a));
    printf("Numero di byte di int: %ld\n", sizeof(int));

    print_array_int(a, n);

    printf("%p\n", &e); /* stampa l'indirizzo della variabile e */

    /* p = &e;  ATTENZIONE */
    /* printf("%f\n", *p); ATTENZIONE */

    p = crea_array_int(10);
    print_array_int(p, 10);
    free(p); /* funzione che libera la memoria puntata da p (deallocazione) */
    
    p = a; /* p punta all'indirizzo in memoria di a */
    print_array_int(p, n); /* oppure print_array_int(a, n), a e p puntano agli stessi elementi e lo stesso indirizzo in memoria. */

    p = b;
    print_array_int(p, n);

    /* a = b è vietato non posso modificare l'indirizzo di un array */

    printf("il valore della costante C definita all'inizio del prog: %d\n", C);

    p = a;
    if( p == a)
    {
        printf("a == p\n");
    }
    else
    {
        printf("a != p\n"); 
    }

    if( c == a) /* c ed a hanno gli stessi elementi ma il loro indirizzo di memoria è diverso, quindi risulteranno diversi */
    {
        printf("a == c\n");
    }
    else
    {
        printf("a != c\n"); 
    }

    printf("%d\n", *p); /* l'asterisco davanti un puntatore serve per tirar fuori il valore puntato appunto dal puntatore */
    printf("%d\n", *(p+1)); /* p nel caso precedente puntava al primo elemento di a (cioè 0), adesso punta al secondo elemento di a (cioè 1) */
}