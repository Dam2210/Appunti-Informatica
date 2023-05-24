/*
La seguente struttura dati definisce una sequenza di interi: il valore del campo size
indica il numero di interi nella sequenza sequenza mentre il campo a è un puntatore
ad un array di size interi.

struct int_array {
int *a;
int size;
};
typedef struct int_array int_array;;

Si scriva una funzione che abbia il seguente prototipo:

void filtra_positivi( int_array *v );

questa deve modificare la sequenza definita dall’int_array puntato da v in modo da
eliminare tutti gli interi negativi.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct int_array 
{
  int *a;
  int size;
};
typedef struct int_array int_array;

void filtra_positivi(int_array *v);
void array_print(int_array ad);

void main()
{
  int i;
  int el;
  int_array v = {NULL, 0};
  v.size = 5;
  v.a = malloc(sizeof(int)*(v.size));
  for(i = 0; i < v.size; i++)
  {
    printf("inserisci %d elemento:", i);
    scanf("%d", &el);
    v.a[i] = el;
  }
  array_print(v);
  int_array *p = &v;
  filtra_positivi(p);
  array_print(v);
}

void array_print(int_array ad)
{
  int i;
  printf("size = %d\n", ad.size);
  for(i = 0; i < ad.size; i++)
  {
    printf("\t%d ------ %d\n", i, ad.a[i]);
  }
}

void filtra_positivi(int_array *v)
{
  int i;
  int c = 0;
  int j = 0;

  // conto il numero di positivi
  for (i = 0; i < v->size; i++)
  {
    if(v->a[i] > 0)
    {
      c = c + 1;
    }
  }

  int *a = (int*)malloc(sizeof(int)*(c));

  for (i = 0; i < v->size; i++)
  {
    if(v->a[i] > 0)
    {
        a[j] = v->a[i];
        j++;
    }
  }

  v->size = c;
  free(v->a);
  v->a = a;
}