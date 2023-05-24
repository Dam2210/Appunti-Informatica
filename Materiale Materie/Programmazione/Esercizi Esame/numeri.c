#include <stdio.h>
#include <math.h>

 /*Si scriva un programma C che legga da tastiera 5 numeri e stampi a video il maggiore tra essi, la
loro media e la radice quadrata della somma.
Si noti che per effettuare la radice quadrata esiste la funzione double sqrt (double)definita
nel file di header: <math.h>*/

int max(int, int, int, int, int);
int media_rad(int, int, int, int, int);

void main()
{
    int a, b, c, d, e;
    printf("inserisci un numero:");
    scanf("%d", &a);
    printf("inserisci un numero:");
    scanf("%d", &b);
    printf("inserisci un numero:");
    scanf("%d", &c);
    printf("inserisci un numero:");
    scanf("%d", &d);
    printf("inserisci un numero:");
    scanf("%d", &e);
    max(a, b, c, d, e);
    media_rad(a, b, c, d, e);
}

int max(int a, int b, int c, int d, int e)
{
    if(a >= b && a >= c && a >= d && a >= e)
    {
        printf("il numero più grande è:%d\n", a);
    }
    else if(b >= a && b >= c && b >= d && b >= e)
    {
        printf("il numero più grande è:%d\n", b);
    }
    else if(c >= a && c >= b && c >= d && c >= e)
    {
        printf("il numero più grande è:%d\n", c);
    }
    else if(d >= a && d >= b && d >= c && d >= e)
    {
        printf("il numero più grande è:%d\n", d);
    }
    else if(e >= a && e >= b && e >= c && e >= d)
    {
        printf("il numero più grande è:%d\n", e);
    }
}

int media_rad(int a, int b, int c, int d, int e)
{
    int somma = a+b+c+d+e;
    printf("la somma è:%d\n", somma);
    double media = somma/5;
    printf("la media è:%f\n", media);
    double rad = sqrt(somma);
    printf("la radice quadrata della somma é:%f\n", rad);
}