/* Scrivere un programma c che prende in ingresso da tastiera una serie di 20
numeri interi. I numeri immessi devono essere salvati all’interno di un array.
Una volta terminata l’immissione. Stampare a video l’array e successivamente
ordinare una copia dell’array in ordine crescente.*/

#include <stdlib.h>
#include <stdio.h>

void BubbleSort(int*, int);
 
void main()
{
    int i;
    int n;
    int num = 4;
    int *p = malloc(sizeof(int)*num);
    int *c = malloc(sizeof(int)*num);
    for (i = 0; i < num; i++)
    {
        printf("inserisci un numero intero:");
        scanf("%d", &n);
        printf("%d\n", n);
        p[i] = n;
    }
    for (i = 0; i < num; i++)
    {
        printf("p[%d]----->%d\n", i, p[i]);
        c[i] = p[i];
    }

    printf("--------------------------------------------------------\n");

    for (i = 0; i < num; i++)
    {
        printf("c[%d]----->%d\n", i, c[i]);
    }

    printf("--------------------------------------------------------\n");

    BubbleSort(c, num);
    printf("array c ordinato: ");
    for (i = 0; i < num; i++)
    {
        printf("%d", c[i]);
        if (i < num-1) 
        {
            printf(", "); 
        }
        else 
        {
            printf("\n");
        }  
    }
    
}

void BubbleSort(int *x, int num){  //t:n se ordinata,n^2 se non,m:costante
	int n = num;
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