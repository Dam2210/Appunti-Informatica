#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list_item
{
    char *val;
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;

typedef list_item* lista; /* = NULL per lista vuota */

lista lista_in0(lista, char*); /* Aggiunge un elemento in posizione 0 */
lista lista_in1(lista, char*); /* Aggiunge un elemento in posizione 1 */
lista lista_in(lista, int, char*); /* Aggiunge un elemento nella posizione desiderata */ 
lista lista_append(lista, char*); /* Aggiunge un elemento alla lista */
lista lista_out0(lista); /* Elimina l'elemento in posizione 0 */
lista lista_out1(lista); /* Elimina l'elemento in posizione 1 */
lista lista_out(lista, int); /* Elimina l'elemento nella posizione desiderata */
void lista_print(lista); /* Stampa la lista */
list_item *lista_search(lista, int); /* Cerca l'elemento nella lista */

void main(int n_args, char *args[]) /* scrivi altre parole dopo il comando di esecuzione del programma sul cp (es: ./liste_concatenate_str ciao come stai) */
{
    lista a = NULL;
    int i;

    if (n_args == 1)
    {
       printf("usa %s seguito da un elenco di stringhe\n", args[0]);
       return;
    }
    
 
    for(i = 0; i < n_args; i++)
    {
        printf("stringa %d: %s\n", i, args[i]);
        a = lista_in0(a, args[i]);
    }

    while (a != NULL)
    {
        a = lista_out0(a);
        lista_print(a);
    }
}

lista lista_in0(lista a, char *v)
{
    list_item *p = malloc(sizeof(list_item));
    char *copy_v;
    int n;

    if(p == NULL)
    {
        return a;
    }

    n = strlen(v);

    p->val = malloc(sizeof(char)*(n + 1));
    if(p->val == NULL)
    {
        return a;
    }
    strcpy(p->val, v); /* Crea una copia di v e la mette in p->val */
    p->val[n] = '\0';

    /*p->val = v;*/

    p->prev = NULL;
    p->next = a;
    if(a != NULL)
    {
        a->prev = p;
    }
    
    return p;
}

/* Precondizione: La lista non è vuota */
lista lista_in1(lista a, char *v)
{
    list_item *p = malloc(sizeof(list_item));

    if(p == NULL)
    {
        return a;
    }
    p->val = v;
    p->prev = a;
    p->next = a->next;

    if(a->next != NULL)
    {
        a->next->prev = p;
    }
    a->next = p;
    return a;
}

lista lista_in(lista a, int pos, char *v)
{
    lista p;

    if(pos == 0)
    {
        return lista_in0(a, v);
    }

    p = lista_search(a, pos-1);

    if(p == NULL)
    {
        return a;
    }

    p = lista_in1(p, v);
    return a;
}

void lista_print (lista a)
{
    list_item *p = a;

    printf("=============\n");

    for(p = a; p != NULL; p = p->next)
    {
        printf("%s\n ", p->val); /* equivalente a (*p).val */  
    }
}

lista lista_append(lista a, char *v)
{
    lista p = a;

    if(p == NULL) /* Lista vuota */
    {
        return lista_in0(a, v);
    }

    while(p->next != NULL)
    {
        p = p->next;
    }

    p = lista_in1(p, v);

    return a;
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

    free(p->val);
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

lista lista_out(lista a, int pos)
{
    lista p;

    if(pos == 0)
    {
        return lista_out0(a);
    }

    p = lista_search(a, pos-1);

    if(p == NULL)
    {
        return a;
    }

    p = lista_out1(a);

    return a;
}


list_item *lista_search(lista a, int pos)
{
    list_item *p = a;

    if(pos < 0)
    {
        return NULL;
    }
    while(pos > 0 && p != NULL)
    {
        p = p->next;
        pos--;
    }

    return p;
}


