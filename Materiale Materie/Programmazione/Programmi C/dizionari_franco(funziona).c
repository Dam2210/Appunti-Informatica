#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
struct dict_item
{
    char *k;
    float v;
};
typedef struct dict_item dict_item;
struct list_item
{
    dict_item val; //informazione
    struct list_item *next;
    struct list_item *prev;
};
typedef struct list_item list_item;
typedef list_item *lista; /*NULL sta per lista vuota*/

struct dizionario
{
    lista *a; //array di liste
    int n;//n di item del dizionario
    int m;//numero di liste, dimensione(lunghezza) di a
};
typedef struct dizionario dizionario;

dizionario dizionario_new();
int hash(dizionario d,char *k);//funzione hash, vedi appunti
dizionario dizionario_add(dizionario d, dict_item e);
dizionario dizionario_del(dizionario d, char *k);
dizionario dict_del_prof(dizionario d,char *k);// dict del fatta dal prof
void dizionario_print(dizionario d);

list_item *dict_search(dizionario d, char *k);
lista list_del0(lista a);
lista list_del1(lista a);
lista list_del(lista a,int pos);
lista list_in0(lista a,dict_item e);
list_item *list_search_val(lista a,char *s);

void main(int argc,char* argv[]){ 
    dizionario d = dizionario_new();
    dict_item e;
    list_item *p;

    if(argc == 1){
        printf("Devi aggiungere qualche stringa\n");
        return;
    }
    for(int i=1;i<argc-1;i++){
        e.k=argv[i];
        e.v=1.0*strlen(argv[i])/argc;
        d = dizionario_add(d,e);
    }
    p=dict_search(d,argv[argc-1]);
    if(p==NULL){
        printf("Ricerca fallita per la chiave '%s'\n",argv[argc-1]);
    }else{
        printf("Valore associato alla chiave '%s' è %f\n",argv[argc-1],p->val.v);
    }

    dizionario_print(d);
    //d = dizionario_del(d,argv[argc-3]);
    d= dict_del_prof(d,argv[argc-1]);
    dizionario_print(d);
    printf("====================\n");
    p=dict_search(d,argv[argc-1]);
    if(p==NULL){
        printf("Ricerca fallita per la chiave '%s'\n",argv[argc-1]);
    }else{
        printf("Valore associato alla chiave '%s' è %f\n",argv[argc-1],p->val.v);
    }
}

dizionario dizionario_new(){
    dizionario d;
    d.m = M;
    //lista b[M];non va bene,vedi appunti
    d.n=0;
    d.a=malloc(sizeof(lista)*d.m);
    //d.a=b; non va bene, vedi appunti lez 20 maggio
    for(int i=0;i<d.m;i++){
        d.a[i] = NULL;
    }
    return d;
}

int hash(dizionario d,char *k){
    int pos=0;//indice di output
    for(int i=0; k[i] != '\0'; i++){
        pos = pos^k[i];//con ^ si calcola lo xor bit-a-bit
    }
    return pos%d.m;
}
void dizionario_print(dizionario d){
    int i;
    list_item *p;
    printf("======================\n");
    for(i=0;i<d.m;i++){
        /*stampo gli elementi di d.a[i]*/
        printf("d[%d] = ",i);
        for(p=d.a[i];p!=NULL;p=p->next){
            printf("(%s,%f), ",p->val.k,p->val.v);    
        }
        printf("\n");
    }
}
list_item *dict_search(dizionario d, char *k){
    int lista_index=hash(d,k);
    list_item *p;
    p=list_search_val(d.a[lista_index],k);
    if(p==NULL){
        return NULL;
    }
    return p;
}
/*************************/
list_item *list_search_val(lista a,char *s){ //costo nel caso peggiore O(n)
    list_item *p=a;
    while(p != NULL){
        //strcmp compara la prima stringa con la seconda,se return 0 allora sono uguali
        if(strcmp(p->val.k,s) == 0){//p->val.k chiave k della lista
            return p;
        }
        p = p->next;
    }
    return p;
}
/**/
dizionario dizionario_add(dizionario d, dict_item e){
    int list_index = hash(d,e.k);
    /*eventualmente l'elemento va inserito nella lista d.a[list_index]*/
    list_item *p = dict_search(d,e.k);
    if(p==NULL){//e.k non è una chiave,aggiungio e in d.a[list_index]
        d.a[list_index]=list_in0(d.a[list_index],e);
    }else{
        /*aggiorno il valoro associato alla chaive e.k già presente*/
        p->val.v=e.v;
    }
    return d;
}
lista list_in0(lista a,dict_item e){ //costo nel caso peggiore O(n)
    list_item *p = malloc(sizeof(list_item));
    if(p == NULL){
        return a;
    }
    p->val = e;
    
    p->prev = NULL;
    p->next = a;
    if(a!=NULL){
        a->prev = p;
    }
    //a=p;
    return p;
}
/*elimina l'elemento con chiave k dal dizionario*/
dizionario dizionario_del(dizionario d,char*k){
    /*int list_index = hash(d,k);
    list_item *p,*q;
    p=dict_search(d,k);
    printf("%s -- %d\n",k,list_index);
    if(p==NULL){
        /*la chiave usata non è presente nel dizionario*/
        //printf("L'elemento con chiave '%s' non è presente nel dizionario\n",k);
        //return d;
    /*}else{
        /*elimino il valore*/
       /* printf("Elemento '%d' con chiave '%s' cancellato\n",list_index,k);
        d.a[list_index] = list_del(d.a[list_index],list_index);
        return d;
    }
    return d;*/
    list_item* p = dict_search(d, k);
    int list_index = hash(d, k);
    //printf(p->next->val.k);
    if(p == NULL){
        printf("L'elemento con chiave '%s' non è presente nel dizionario\n",k);
        return d;
    }
    else if(p->prev == NULL){
        
        d.a[list_index] = list_del0(p);
        printf("Elemento in pos d['%d'] con chiave '%s' cancellato(Elemento in pos 0 della lista concatenata)\n",list_index,k);
        return d;
    }
    else{
        //int list_index = hash(d, k);
        printf("Elemento in pos d['%d'] con chiave '%s' cancellato\n",list_index,k);
        d.a[list_index] = list_del1(p->prev);
        return d;
    }
}
dizionario dict_del_prof(dizionario d,char *k){
    int list_index = hash(d,k);
    /*eventualmente l'elemento va inserito nella lista d.a[list_index]*/
    list_item *p = dict_search(d,k);
    list_item *q;
    if(p==NULL){//e.k non è una chiave,aggiungio e in d.a[list_index]
       return d;
    }
    if(p==d.a[list_index]){
        /*elimino il primo elemento della lista*/
        printf("Elemento in pos d['%d'] con chiave '%s' cancellato\n",list_index,k);
        d.a[list_index] = list_del0(d.a[list_index]);
        
    }else{
        q = p->prev;
        p = list_del0(p);
        printf("Elemento in pos d['%d'] con chiave '%s' cancellato\n",list_index,k);
        q->next = p;
        if(p!=NULL){
            p->prev = q;
        }
        
    }
    return d;
}
lista list_del0(lista a){
    lista p = a;
    if(a == NULL){
        return a;
    }
    
    a = a->next;
    if(a != NULL){
        a->prev = NULL;
    }
    free(p);
    return a;  
}
lista list_del1(lista a){
    list_item *p;
    if(a == NULL){
        return a;
    }
    p = a->next;
    a->next = p->next;
    if(p->next != NULL){
        p->next->prev = a;
    }
    free(p);
    return a;
}
list_item *list_search(lista a,int pos){ //costo nel caso peggiore O(n)
    list_item *p=a;
    if(pos < 0){
        return NULL;
    }
    while(pos > 0 && p != NULL){
        p = p->next;
        pos--;
    }
    return p;
}
lista list_del(lista a,int pos){
    lista p;
    if(pos == 0){
        return list_del0(a);

    }
    p = list_search(a,pos-1);

    if(p==NULL){
        return a;
    }
    p = list_del1(p);
    return a;
}