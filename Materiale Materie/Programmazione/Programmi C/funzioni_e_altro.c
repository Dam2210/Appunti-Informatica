#include <stdio.h>

int len(char a[]) /* funzione fuori dal main che restituisce la lunghezza della stringa in input*/
{
    int len = 0;

    while(a[len] != '\0')
    {
        len++; /* len += 1 */
    }

    return len;
}


void main()
{
    int x = 2;
    float y = x + 6.1;
    /* x = (int)(y + 0.5); casting */
    printf("Il valore di x è: %d\n", x);
    printf("il valore di y è: %f\n", y);
    
    if(x < 10)
    {
        printf("x è minore di 10\n");
    }
    else
    {
        printf("x non è minore di 10\n");
    }

    if(x < 10 && y >= 8) /* && = operatore and */
    {
        printf("x < 10 e y >= 8\n");
    }

    if(x<10 || y>=8) /* || = operatore or */
    {
        printf("x < 10 oppure y >= 8\n");
    }

    if(!(x<10)) /* ! = operatore not */
    {
        printf("x non è < 10\n");
    }

    int a = 21, b = 2, c;
    float d;

    c = a/b;
    /* d = (float)a/b; */
    /* d = a/b + 0.0; non va bene, int + float */
    d = 1.0*(a/b); /* d = a/(b + 0.0) questa va bene */

    printf("il valore di c è: %d\n", c);
    printf("il valore di d è: %f\n", d);

    char s[] = "programma in C";
    int i = 4;
    s[i] = 'R';
    s[i+1] = '\n';
    s[i+3] = '\0';

    printf("%s\n", s);
    printf("%c\n%c\n", s[8], s[9]);

    int ln = 0;
    while(s[ln] != '\0')
    {
        ln++; /* len += 1 */
    }

    printf("la lunghezza della stringa s è: %d\n", ln);

    printf("la lunghezza della stringa della funzione prima del main è: %d\n", len(s));
}