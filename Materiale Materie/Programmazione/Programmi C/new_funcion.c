#include <stdio.h>

/* prototipo, questo serve per accennare al compilatore quali funzioni incontrerà per evitare errori */
int len(char a[]);
float pi();
float nep();

void main()
{
    char x[] = "questo è un programma";
    printf("la lunghezza della stringa x è: %d\n", len(x));
    printf("il valore di pi-greco è: %f\n", pi());
    printf("il valore di e è: %f\n", nep());
}


int len(char a[]) /* funzione fuori dal main che restituisce la lunghezza della stringa in input*/
{
    int len = 0;

    while(a[len] != '\0')
    {
        len++; /* len += 1 */
    }

    return len;
}

float pi()
{
    return 3.14;
}