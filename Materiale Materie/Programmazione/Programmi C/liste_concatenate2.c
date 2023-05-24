#include <stdlib.h>
#include <stdio.h>

struct list_item
{
    float val;
    struct list_item *next; 
    struct list_item *prev;
};
typedef struct list_item list_item;

typedef list_item* lista; /* = NULL per lista vuota */

lista lista_in0(lista, float); /* Aggiunge un elemento in posizione 0 */
lista lista_in1(lista, float); /* Aggiunge un elemento in posizione 1 */
lista lista_in(lista, int, float); /* Aggiunge un elemento nella posizione desiderata */
lista lista_append(lista, float); /* Aggiunge un elemento alla lista */
lista lista_out0(lista); /* Elimina l'elemento in posizione 0 */
lista lista_out1(lista); /* Elimina l'elemento in posizione 1 */
lista lista_out(lista, int); /* Elimina l'elemento nella posizione desiderata */
void lista_print(lista); /* Stampa la lista */
list_item *lista_search(lista, int); /* Cerca l'elemento nella lista */

void main()
{
    lista a = NULL, b = NULL, c, d; 
    int i, n = 12;
    list_item *p, *u;

    for(i = 0; i < n; i++)
    {
        a = lista_in0(a, i);
    }

    lista_print(a);

    p = lista_search(a, 4);
    if(p != NULL)
    {
        printf("%f\n", p->val);
    }
    a = lista_in1(a, 100);
    lista_print(a);

    b = lista_in0(b, 200);
    b = lista_in1(b, 210);
    b = lista_in(b, 2, 250);
    b = lista_in(b, 1, 300);
    lista_print(b);

    c = NULL;
    for(i = 0; i < n; i++)
    {
        c = lista_append(c, 100+i);
    }
    lista_print(c);

    d = NULL;
    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            d = lista_in0(d, 200+i);
            u = d;
        }
        else 
        {
            u = lista_in1(u, 200+i);
            u = u->next;
        }
    }
    lista_print(d);

    d = lista_out(d, 6);

    while(n >= 0)
    {
        d = lista_out(d, n);
        lista_print(d);
        n--;
    }
}

lista lista_in0(lista a, float v)
{
    list_item *p = malloc(sizeof(list_item));

    if(p == NULL)
    {
        return a;
    }
    p->val = v;
    p->prev = NULL;
    p->next = a;
    if(a != NULL)
    {
        a->prev = p;
    }
    
    return p;
}

/* Precondizione: La lista non è vuota */
lista lista_in1(lista a, float v)
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

lista lista_in(lista a, int pos, float v)
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
        printf("%f\n ", p->val); /* equivalente a (*p).val */  
    }
}

lista lista_append(lista a, float v)
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


