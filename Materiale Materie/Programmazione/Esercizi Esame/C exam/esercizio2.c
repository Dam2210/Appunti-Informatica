#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Date due stringhe a e b, progettare una funzione che rimuove b da a nel caso in cui b sia sottostringa di a. 
La funzione deve restituire 0 se b non è sottostringa di a, 1 altrimenti. Infine, la quantità di memoria 
supplementare utilizzata dalla funzione (ovvero quella allocata all’interno della funzione) deve essere 
costante */

struct array_dinamico 
{
      int *a;
      int c; /*capacita*/
      int n; /*dimensione*/
};

typedef struct array_dinamico array_dinamico;

array_dinamico array_init();
array_dinamico array_append(array_dinamico ad, int e);
char *elimina_char(char*, array_dinamico);
void array_print(array_dinamico ad);

int rimuovi_stringa(char*, char*);
char *elimina_char(char*, array_dinamico);



void main()
{
    char a[] = "programmazione dei calcolatori";
    char b[] = "azione";
    printf("Stringa:%s\n", a);
    printf("Sottostringa:%s\n", b);
    int ris;

    ris = rimuovi_stringa(a, b);
    printf("%d\n", ris);
}

int rimuovi_stringa(char *a, char *b)
{
    array_dinamico pos = array_init();
    int i = 0;
    int check = 0;
    int len_b = strlen(b);
    while(i <= strlen(a))
    {
        int k = 0;
        if (a[i] == b[k])
        {
            while(k != len_b && a[i] == b[k])
            {
                pos = array_append(pos, i);
                k++;
                i++;
            }
        }
        else
        {
            i++;
            if(pos.n < strlen(b)) // || pos.n == 0
            {
                check = 0;
                pos = array_init();
            }
            else //(pos.n == strlen(b))
            {
                check = 1;
                i = strlen(a)+1;
            }
            
        }
        array_print(pos);
    }
    if(check == 1)
    {
        a = elimina_char(a, pos);
        printf("%s\n", a);
    }
    return check;
}

/* Funzione che crea un array dinamico vuoto */
array_dinamico array_init()
{
    array_dinamico ad = {NULL, 0, 0};
    return ad;
}

/* Aggiunge un nuovo elemento in fondo all'array dinamico */
array_dinamico array_append(array_dinamico ad, int e)
{
    int i;
    int *b;
    if (ad.n == ad.c) /* se il numero di elementi è uguale alla dimensione dell'array */
    {
        ad.c = 1 + (ad.c)*2; /* raddoppio la dimensione dell'array */
        b = realloc(ad.a,(ad.c)*sizeof(int)); /* creo un nuovo array (b) con la dimensione raddoppiata del primo array (a) */
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
        printf("\t%d ------ %d\n", i, ad.a[i]);
    }
}

char *elimina_char(char *a, array_dinamico ad)
{
    int i = 0;
    int j = 0;
    int p = 0;
    int len_a = strlen(a);
    char *str = NULL;
    str = malloc(sizeof(char)*(len_a - ad.n));
    printf("============================\n");
    array_print(ad);

    while(a[i] != '\0')
    {
        for(j = 0; j < ad.n; j++)
        {
            if(a[i] == ad.a[j])
            {
                i++;
            }
         }
        if(i < ad.a[0] || i > ad.a[ad.n])
        {
            str[p] = a[i];
        }
        i++;
        p++;
    }
    printf("%ld\n", strlen(a));
    printf("str:%s\n", str);
    str[p] = '\0';
    return str;
}
