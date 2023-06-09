#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define M 10

struct dict_item
{
    char *k; /* k è la chiave del dizionario */
    float v; /* v è il valore associato alla chiave k */
};
typedef struct dict_item dict_item;

struct list_item
{
    dict_item val;
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;

typedef list_item* lista; /* = NULL per lista vuota */

struct dizionario
{
    lista *a; /* a è un array di liste */
    int m; /* Numero di liste, lunghezza di a */
    int n; /* Numero di item del dizionario */
};
typedef struct dizionario dizionario;

dizionario dizionario_new(); /* Crea un nuovo dizionario */
int hash(dizionario, char*); /* Genera l'hash della chiave */ 
list_item *dizionario_search(dizionario, char*);
dizionario dizionario_add(dizionario, dict_item);
void dizionario_mostra(dizionario);
dizionario dizionario_out(dizionario, char*);

lista lista_in0(lista, dict_item); /* Aggiunge un elemento in posizione 0 */
list_item *lista_search_val(lista, char*); /*cerca un valore nella lista*/
lista lista_out0(lista);
lista lista_out1(lista);

void main(int n_args, char *args[]) /* scrivi altre parole dopo il comando di esecuzione del programma sul cp (es: ./liste_concatenate_str ciao come stai) */
{
    dizionario d = dizionario_new();
    int i;
    dict_item e;
    list_item *p;

    if (n_args == 1)
    {
       printf("usa %s seguito da un elenco di stringhe\n", args[0]);
       return;
    }

    for (i = 1; i < n_args-1; i++)
    {
        e.k = args[i];
        e.v = 1.0*strlen(args[i])/n_args;
        d = dizionario_add(d, e);
    }

    p = dizionario_search(d, args[n_args-1]);

    if(p == NULL)
    {
        printf("%s non appartiene al dizionario\n", args[n_args-1]);
    }
    else
    {
        printf("il valore associato a %s è %f\n", args[n_args-1], p->val.v);
    }

    dizionario_mostra(d);
    
    //d = dizionario_out(d, args[n_args-1]);

    dizionario_mostra(d); 
}

/************** Funzioni Dizionari **************/

dizionario dizionario_new()
{
    int i;
    dizionario d;
    d.m = M;
    d.n = 0;
    d.a = malloc(sizeof(lista)*d.m); /* d.a ha dimensione di una lista moltiplicata per M che è 10 */
    for ( i = 0; i < d.m; i++)
    {
        d.a[i] = NULL;
    }
    return d;
}

int hash(dizionario d, char *k)
{
    int i, pos = 0; /* pos è l'indice di output */
    char c;
    for (i = 0; k[i] != '\0'; i++)
    {
        pos = pos ^ k[i]; /* con questa operazione faccio lo xor bit a bit */
    }
    return pos%d.m;
}

list_item *dizionario_search(dizionario d, char *k)
{
    int list_index = hash(d, k);
    list_item *p;

    p = lista_search_val(d.a[list_index], k);

    return p;
}

dizionario dizionario_add(dizionario d, dict_item e)
{
    int list_index = hash(d, e.k);
    list_item *p;
    /* eventualmente l'elemento va inserito nella lista d.a[list.index] */
    p = dizionario_search(d, e.k);

    if(p == NULL)
    {
        /* e.k non è una chiave, aggiungiamo e in d.a[list_index] */
        d.a[list_index] = lista_in0(d.a[list_index], e);
    }
    else
    {
        /*aggiorno il valore associato alla chiavee.k gia in d */
        p->val.v = e.v;
    }
    return d;
}

void dizionario_mostra(dizionario d)
{
    int i;
    list_item *p;

    printf("====================================\n");

    for (i = 0; i < d.m; i++)
    {
        /* stampare gli elementi di d.a[i] */
        printf("d[%d] = ", i);
        for (p = d.a[i]; p != NULL; p = p->next)
        {
            printf("(%s, %f), ", p->val.k, p->val.v);
        }    
        printf("\n");
    }
    
}

dizionario dizionario_out(dizionario d, char *k)
{  
    int list_index = hash(d, k);
    list_item *p = dizionario_search(d, k);
    list_item *q;

    /* eventualmente l'elemento va cancellato dalla lista d.a[list_index] */
    if(p == NULL)
    {
        /* k non è una chiave, niente da fare */
        return d;
    }

    if(p == d.a[list_index]) /* elimino il primo elemento della lista */
    {
        d.a[list_index] = lista_out0(d.a[list_index]);
    }
    else
    {
        q = p->prev;
        p = lista_out0(p);
        q->next = p;

        if(p!= NULL)
        {
            p->prev = q;
        }
    }
    return d;
}
/************** Funzioni Liste **************/

list_item *lista_search_val(lista a, char *s)
{
    list_item *p = a;

    while(p != NULL)
    {
       if(strcmp(p->val.k, s) == 0); /*strcmp = funzione che prende in input due stringhe e le confronta (se il valore è 0 le stringhe sono uguali) */
       {
        return p;  
       }
       p = p->next;
    }

    return p; /* La chiave s non è in d */
}

lista lista_in0(lista a, dict_item e)
{
    list_item *p = malloc(sizeof(list_item));
    int n;

    if(p == NULL)
    {
        return a;
    }

    p->val = e;

    p->prev = NULL;
    p->next = a;
    if(a != NULL)
    {
        a->prev = p;
    }
    
    return p;
}

lista lista_out0(lista a)
{
    lista p = a;

    if(a == NULL)
    {
        return NULL;
    }

    a = a->next;

    if(a != NULL)
    {
        a->prev = NULL;
    }
    free(p);
    return a;
}

lista lista_out1(lista a)
{
    lista p;

    if(a == NULL || a->next == NULL)
    {
        return NULL;
    }

    p = a->next; /* Sappiamo che è diverso da NULL */
    a->next = p->next;

    if(p->next != NULL)
    {
        p->next->prev = a;
    }

    free(p);
    return a;

}