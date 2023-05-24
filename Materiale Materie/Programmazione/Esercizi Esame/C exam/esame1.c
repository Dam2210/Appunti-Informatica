#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * funzione(char a)
{
    int i;
    int n = strlen(a);
    int c = 0;
    int j = 0;
    
    //conto il numero di vocali così da avere la dimensione di p
    
    for(i = 0; i < n ; i++){
        if( a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'
        || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            c ++;
        } 
	}
    
    char **p = malloc(sizeof(char *) * (c+1));
    
    //se a[i] una vocale assegno il suo indirizzo al puntatore in posizione j e aggiorno j
    for(i = 0; i < n ; i++){
        if( a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'
        || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            p[j] = &a[i];
            j++;
        }
    }
    p[j] = NULL;
    //ultimo puntatore è null
    return p;
} 
