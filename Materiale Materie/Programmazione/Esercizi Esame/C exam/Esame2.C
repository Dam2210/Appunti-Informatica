#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
Date due stringhe a e b, progettare una funzione che rimuove b da a nel caso in cui b sia sottostringa di a.
La funzione deve restituire 0 se b non è sottostringa di a, 1 altrimenti. Infine, la quantità di memoria
supplementare utilizzata dalla funzione (ovvero quella allocata all’interno della funzione) deve essere
costante.
Esempio: Sia a[] = "programmazione dei calcolatori" e b[] = "azione”, la funzione deve restituire 1 e
modificare a in modo che essa rappresenti la stringa "programm dei calcolatori"
La funzione dovrà avere il seguente prototipo:
**/
struct array_dinamico {
      int *a;
      int c; /*capacita*/
      int n; /*dimensione*/
};
typedef struct array_dinamico array_dinamico;
array_dinamico array_init();
array_dinamico array_append(array_dinamico ad,int e);

int rimuovi_stringa(char *, char *);
void cancella_stringa(char *,int);

void main(){
    int test;
    char a[]="programmazione dei calcolatori";
    char b[]="progra";
    test=rimuovi_stringa(a,b);
    printf("%d \n",test );
}




void cancella_stringa(char*a,int start){
  int i=start+1;
  char c;
  while (start<=strlen(a)){
    c=a[i];
    a[i]=a[start];
    a[start]=c;
    start++;
    //printf("%s\n",a);
  }

}

int rimuovi_stringa(char *a,char *b){
  array_dinamico pos=array_init();
  int i=0;
  int check=0;
  while(i<=strlen(a)){
    if (a[i]==b[0]){
      pos=array_append(pos,i);
    }
    i++;
  }
  printf("%d\n",*(pos.a) );
  int j=0;
  while(j<sizeof(pos)/sizeof(int)){   //j<=4
    int k=*(pos.a+j);     //5,8,20,25
    int t=0;
    while(t<=strlen(b)){
      if (b[t]==a[k+t]){
        return 1;
      }
      else{
        check=0;
      }
      t++;
    }
    j++;
  }
  return check;
}

array_dinamico array_init(){
  array_dinamico ad={NULL,0,0};
  return ad;
}

/* aggiunge un nuovo elemento in fondo all'array dinamico */
array_dinamico array_append(array_dinamico ad,int e){
  int *b;
  int i;
  if (ad.n==ad.c){
    ad.c=1+2*ad.c;
    b=malloc(sizeof(int)*ad.c); /* O(1) */
    for (i=0; i<ad.n; i++){
      b[i]=ad.a[i];
    }
    free(ad.a); /* O(1) */
    ad.a=b;
  }
  ad.a[ad.n]=e;
  ad.n++;

  return ad;
}



   while(a[i] != '\0')
    {
        if(i != ad.a[j] && j < ad.n)
        {
            printf("a[i]:%c\n", a[i]);
            printf("i:%d\n", i);
            printf("ad.a:%d\n", ad.a[j]);
            str[p] = a[i];
        }
        while(i == ad.a[j] && j < ad.n)
        {
            j++;
        }
        if(j >= ad.n)
        {
            str[p] = a[i];
        }
        i++;
        p++;
    }
    str[p] = '\0';
    printf("str:%s\n", str);
    return str;
