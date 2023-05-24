#include <stdio.h>
#include <stdlib.h>

/* 
    Lezione n38.
    &i tira fuori l'indirizzo di memoria nel quale è memorizzato i.
    *(*i) tira fuori il valore puntato da i se i è un puntatore.
*/

struct array_item
{
    char type; /* 'd' per int, 'f' per float, 'c' per char */
    void *p;
};

typedef struct array_item array_item;
void array_set_int(array_item *q, int v);
void array_set_char(array_item *q, int v);
void array_set_float(array_item *q, int v);
void array_print(array_item a[], int n);
void *array_assign_var(array_item *q, void *x);

/* q punta ad un elemento dell'array*/
void array_set_int(array_item *q, int v)
{
    q->type = 'd'; /* q punta al campo type dell'elemento nell'array */
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(int));
    *((int*)(q->p)) = v;  /* Converto il puntatore di tipo void a tipo int in questo modo. con lo * davanti ottengo il valore puntato (cioè v). */
}

void array_set_char(array_item *q, int v)
{
    q->type = 'c'; /* q punta al campo type dell'elemento nell'array */
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(char));
    *((char*)(q->p)) = v;  /* Converto il puntatore di tipo void a tipo int in questo modo. con lo * davanti ottengo il valore puntato (cioè v). */
}

void array_set_float(array_item *q, int v)
{
    q->type = 'f'; /* q punta al campo type dell'elemento nell'array */
    if (q->p != NULL)
        free(q->p);
    q->p = malloc(sizeof(float));
    *((float*)(q->p)) = v;  /* Converto il puntatore di tipo void a tipo int in questo modo. con lo * davanti ottengo il valore puntato (cioè v). */
}

void array_print(array_item a[], int n)
{
    int i;
    printf("==================\n");
    for(i = 0; i < n; i++)
    {
        if (a[i].type == 'c')
        {
            printf("%c\n", *((char*)(a[i].p)));
        }
        else if (a[i].type == 'd')
        {
            printf("%d\n", *((int*)(a[i].p)));
        }
        if (a[i].type == 'f')
        {
            printf("%f\n", *((float*)(a[i].p)));
        }
    }
}

void *array_assign_var(array_item *q, void *x)
{
    if(x != NULL)
        free(x);
    if(q->type == 'd')
    {
        x = malloc(sizeof(int));
        *((int*)x) = *((int*)q->p);
    }
    else if(q->type == 'f')
    {
        x = malloc(sizeof(float));
        *((float*)x) = *((float*)q->p);
    }
    else if(q->type == 'c')
    {
        x = malloc(sizeof(char));
        *((char*)x) = *((char*)q->p);
    }
    return x;
}

void main()
{
    int i;
    array_item a[3];
    int n = sizeof(a)/sizeof(void*);
    void *x = NULL;

    for(i = 0; i < n; i++)
    {
        a[i].p = NULL;
    }

    /* assegnare un valore ad un elemento dell'array: equivalente C di a[0] = 4 in Python */
    array_set_int(a+0, 4); /* a è un array*/
    array_set_float(a+1, 3.14); /* Faccio la stessa cosa di prima ma per un float. */
    array_set_char(a+2, 'x'); /* Faccio la stessa cosa di prima ma per un char. */

    array_print(a, n);
    array_set_float(a+2, 2.71);

    array_print(a, n);

    x = array_assign_var(a+0, x);
    printf("x = %d\n", *((int*)x));
    x = array_assign_var(a+1, x);
    printf("x = %f\n", *((float*)x));
    x = array_assign_var(a+2, x);
    printf("x = %f\n", *((float*)x));
}