#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma in linguaggio C che,
letti tre numeri interi a, b, c dallo standard
input, stampi a terminale la sequenza dei tre
numeri in ordine monotono non decrescente.
• Esempio: a = 10, b = 7, c = 9 deve dare in
uscita 7 9 10. */

void stampa_numeri_dec(int a, int b, int c);

void main()
{
    stampa_numeri_dec(8, 7, 900);
}

void stampa_numeri_dec(int a, int b, int c)
{
    if(a < b && a < c)
    {
        printf("%d ", a);
        if(b < c)
        {
            printf("%d ", b);
            printf("%d \n", c);
        }
        else
        {
            printf("%d ", c);
            printf("%d \n", b);
        }
    }
    else if(b < a && b < c)
    {
        printf("%d ", b);
        if(a < c)
        {
            printf("%d ", a);
            printf("%d \n", c);
        }
        else
        {
            printf("%d ", c);
            printf("%d \n", a);
        }
    }
    else if(c < a && c < b)
    {
        printf("%d ", c);
        if(a > b)
        {
            printf("%d ", a);
            printf("%d \n", b);
        }
        else
        {
            printf("%d ", b);
            printf("%d \n", a);
        }
    }
}