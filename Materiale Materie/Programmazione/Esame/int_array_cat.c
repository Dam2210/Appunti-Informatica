#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct int_array 
{
    int *a;
    int size;
};
typedef struct int_array int_array;;

void int_array_cat( int_array *v0, int_array v1 );
void int_array_cat1( int_array *v0, int_array v1 );
void array_print(int_array ad);

void main()
{
    int i = 0;
    int_array v0 = {NULL, 0};
    v0.size = 5;
    v0.a = malloc(sizeof(int)*(v0.size));
    for(i = 0; i < v0.size; i++)
    {
        v0.a[i] = i*2;
    } 
    array_print(v0);
    int_array v1 = {NULL, 0};
    v1.size = 5;
    v1.a = malloc(sizeof(int)*(v1.size));
    for(i = 0; i < v1.size; i++)
    {
        v1.a[i] = i*10;
    } 
    array_print(v1);
    int_array *p = &v0;
    int_array_cat1(p, v1);
    array_print(v0);
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

void int_array_cat( int_array *v0, int_array v1 )
{
    int j = v0->size; // j parte dall'ultimo elemento nell'array v0
    int n_size = v0->size + v1.size; //n_size è la nuova size dell'array v0
    v0->size = n_size; // assegno la nuova size a v0
    v0->a = realloc(v0->a, sizeof(int)*(n_size)); //rialloco la memoria con la nuova size per aggiungere i nuovi elementi
    while(j < n_size) //Finchè j è minore della nuova size di v0
    {
        for(int i = 0; i < v1.size; i++) //mi scorro l'array v1
        {
            v0->a[j] = v1.a[i]; //copio gli elementi di v1 nelle posizioni vuote dell'array v0
            j++; //incremento il contatore
        }
    } //costo: O(n*m): n = lunghezza che scorre il while, m = lunghezza array v1 per il for
}

// array_cat ottimizzato in ordine di O(n)
void int_array_cat1( int_array *v0, int_array v1 )
{
    int j = v0->size; // j parte dall'ultimo elemento nell'array v0
    int n_size = v0->size + v1.size; //n_size è la nuova size dell'array v0
    v0->size = n_size; // assegno la nuova size a v0
    v0->a = realloc(v0->a, sizeof(int)*(n_size)); //rialloco la memoria con la nuova size per aggiungere i nuovi elementi
    for(int i = 0; i < v1.size; i++) //mi scorro l'array v1
    {
        v0->a[j] = v1.a[i]; //copio gli elementi di v1 nelle posizioni vuote dell'array v0
        j++; //incremento il contatore
    }   //costo: O(n): n = lunghezza che scorre il for cioè v1.size
}




