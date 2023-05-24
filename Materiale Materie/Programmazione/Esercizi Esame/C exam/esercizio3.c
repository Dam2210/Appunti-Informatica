#include <stdlib.h>
#include <stdio.h>

/*Progettare una funzione C che acquisisce l'input da terminale e termina non appena l'utente digita
una stringa che non rappresenta un intero. Durante il processo di acquisizione ogni intero digitato
deve essere inserito in fondo ad una lista inizialmente vuota. La funzione deve restituire la lista
creata.*/

struct nodo 
{
    int valore;
    struct nodo *succ;
    struct nodo *prec;
};

typedef struct nodo nodo;

nodo *input_list();
nodo *lista_in0(nodo*, int); /* Aggiunge un elemento in posizione 0 */
nodo *lista_in1(nodo*, int); /* Aggiunge un elemento in posizione 1 */
nodo *lista_append(nodo*, int);
void lista_print(nodo*);

void main()
{
    nodo *a = NULL;
    a = input_list();
    lista_print(a);
}


nodo *input_list()
{
    nodo *p = NULL;
    int i;
    int len;
    /*printf("quanti elementi vuoi inserire nella lista?: ");
    scanf("%d", &len);
    for(i = 0; i < len; i++)
    {*/
        int val;
        while(1){
            printf("Inserisci un elemento: ");
            if(scanf("%d", &val) == 0)
            {
                break;
            }
            else
            {
                p = lista_append(p, val);
            }
        }
        
    return p;
}

nodo *lista_in0(nodo *a, int v)
{
    nodo *p = malloc(sizeof(nodo*));

    if(p == NULL)
    {
        return a;
    }
    p->valore = v;
    p->prec = NULL;
    p->succ = a;
    if(a != NULL)
    {
        a->prec = p;
    }
    
    return p;
}

nodo *lista_in1(nodo *a, int v)
{
    nodo *p = malloc(sizeof(nodo*));
    
    if(p == NULL)
    {
        return p;
    }
    p->valore = v;
    p->prec = a;
    p->succ = a->succ;

    if(a->succ != NULL)
    {
        a->succ->prec = p;
    }
    a->succ = p;
    return a;
}

nodo *lista_append(nodo *a, int v)
{
    nodo *p = a;

    if(p == NULL) /* Lista vuota */
    {
        return lista_in0(a, v);
    }

    while(p->succ != NULL)
    {
        p = p->succ;
    }

    p = lista_in1(p, v);

    return a;
}

void lista_print (nodo *a)
{
    nodo *p = a;

    printf("=============\n");

    while(p!=NULL){
        printf("%d ", p->valore); /* equivalente a (*p).val */ 
        p=p->succ; 
    }
    printf("\n");
}