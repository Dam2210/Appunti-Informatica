#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_by_vocals(char *a);
void BubbleSort(char*);
int vocali(char a);

void main()
{
    char a[] = ".pr0grAmMaz1onE-C*";
    printf("la stringa è: %s\n", a);
    sort_by_vocals(a);
    printf("la stringa ordinata con vocali è: %s\n", a);
}

/*
Funzione che restituisce 1 se la il carattere passato è una vocale e restituisce 0 se il carattere passato è consonante.
*/
int vocali(char a){

	if (a == 'A' || a == 'E'|| a == 'I'||a == 'O'||a == 'U'||a == 'a'||a == 'e'||a == 'i'||a == 'o'||a == 'u'){
		return 1;
	}
	else{
		return 0;
	}
}
/*
Funzione che ordina una stringa ordinando prima le vocali e poi il resto.
*/
void sort_by_vocals(char *a){

    BubbleSort(a);

    int len = strlen(a);
    int i;
    int k=0;
	  char *c = malloc((len+1)*sizeof(char)); //creo un nuovo puntatore con spazio len+1 per car fine stringa.

    /*
    Mi riscrivo la nuova lista nella porzione di memoria puntata da c inserendo prima le vocali e poi le
    consonanti
    */
    for(i = 0; i < len ; i++){

    if(vocali(a[i]) == 1)
		{
			c[k] = a[i];
			k++;
		}
    }
	   for (i = 0; i < len; i++){

		      if(vocali(a[i]) == 0){
			         c[k] = a[i];
			            k++;
                }
	    }
	c[k] = '\0';   //inserisco carattere di fine stringa

  //ricarico l'array con l'ordinamento vocali->resto nel principale e libero il puntatore all'array di servizio
	for (i = 0; i < len; i++)
	{
		a[i] = c[i];
	}
	free(c);
}

void BubbleSort(char *x){  //t:n se ordinata,n^2 se non ordinata
	int n = strlen(x);
	int i, j = 0;
	char t;
	int scambi = 1;

	while( scambi > 0 )
	{
		i = 0;
		scambi = 0;
		while ( i < n-1-j )
		{
			/*
			 * Eventualmente scambia x[i] con x[i+1]
			 * */
			if ( x[i] > x[i+1] )
			{
				t = x[i+1];
				x[i+1] = x[i];
				x[i] = t;
				scambi++;
			}
			i++;
		}
		j++;
	}
}
