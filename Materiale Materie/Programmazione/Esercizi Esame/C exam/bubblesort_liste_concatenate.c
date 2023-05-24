#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Definizione della struct list_item
 * value   Valore salvato all'interno dell'elemento della lista
 * next    Puntatore all'elemento successivo della lista
 * prev    Puntatore all'elemento precedente della lista
 **/
struct list_item {
    int val;
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;

typedef list_item* list;

/**
 * Funzione che inserisce in testa alla lista un nuovo elemento
 * La funzione restituisce la lista con l'elemento aggiunto in testa
 * lista   Lista a cui si aggiunge il nuovo elemento in testa
 * n       Valore da salvare all'interno del nuovo elemento
 **/
list listaAddTesta(list lista, int n) {
    list_item *elemento = malloc(sizeof(list_item));

    if (elemento == NULL){
        return lista;
    }

    elemento->val = n;
    elemento->prev = NULL;
    elemento->next = lista;

    if (lista != NULL){
        lista->prev = elemento;
    }

    return elemento;
}

/**
 * Funzione che crea una lista casuale
 * n     Numero di elementi da cui sarà composta la lista
 * min   Valore minimo che può assumere ogni valore degli elementi
 * max   Valore massimo che può assumere ogni valore degli elementi
 **/
list generaLista(int n, int min, int max) {
    list lista = NULL;
    int i;

    for (i = 0; i < n; i++) {
        int valore = (rand()%((max+1)-min))+min;
        lista = listaAddTesta(lista, valore);
    }

    return lista;
}

/**
 * Funzione che stampa una lista
 * lista   La lista da stampare
 **/
void stampaLista(list lista, char* label) {
    list_item *elemento;

    printf("Stampa della lista %s:\n", label);

    for(elemento = lista; elemento != NULL; elemento = elemento->next){
        printf("%d ", elemento->val);
    }

    printf("\n");
}

/**
 * Funzione che effettua il Bubble Sort su di una lista
 * lista   Lista su cui effettuare il Bubble Sort
 **/
void bubbleSort(list lista) {
  int temp=0;
  list p1=lista;
  list p2=NULL;


  while(p1->next!=NULL){
  p2=p1->next;
    while(p2!=NULL){

      if (  (p1->val) > (p2->val)  ){
          temp=p1->val;
          p1->val=p2->val;
          p2->val=temp;
      }

      p2=p2->next;
    }

    p1=p1->next;
  }
}

/**
 * Funzione che effettua l'Insertion Sort su di una lista
 * lista   Lista su cui effettuare il Bubble Sort
 **/
void insertionSort(list lista) {
  int temp=0;
  list p1=lista;
  list p2=NULL;

  while(p1!=NULL){
    temp=p1->val;
    p2=p1->prev;
    while(p2!=NULL && ((p2->val) > temp) ){
      p2->next->val=p2->val;
      p2=p2->prev;
      //p2->next->val=temp;
      }
    p2->next->val=temp;

    p1=p1->next;
  }


}

int main() {
    srand(time(NULL));

    list lista_1 = generaLista(10, -10, 10);
    stampaLista(lista_1, "1 non ordinata");

    bubbleSort(lista_1);
    stampaLista(lista_1, "1 ordinata con Bubble Sort");

    list lista_2 = generaLista(10, -10, 10);
    stampaLista(lista_2, "2 non ordinata");

    insertionSort(lista_2);
    stampaLista(lista_2, "2 ordinata con Insertion Sort");
}
