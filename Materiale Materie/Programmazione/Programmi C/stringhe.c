#include <stdio.h>
#include <stdlib.h>
 
char *str_cat(char *a, char *b); /* dichiarazione di intenti, prototipo della funzione che andrà svolta in seguito */
int  str_len(char *a);
int conta_minuscole(char *a);

void main()
{
    int n;
    char a[] = "01234567"; /*a non può essere modificato essendo una costante e non posso fare a = b*/
    /* char *b; b può essere modificato in quanto è un puntatore al tipo char e posso fare b = a */
    char b[] = "1abc*d3efg0";

    char str[] = "StrInGa";
    int num_minuscole = conta_minuscole(str);
    printf("il numero di lettere minuscole nella stringa ... %s .... è: %d\n", str, num_minuscole); 

    char *c = str_cat(a, b);
    printf("la stringa c è: %s\nla lunghezza di c è: %d\n", c, str_len(c));
    printf("%d\n%d\n%d\n", b[0], b[1], b[2]); /* stampa il numero di carattere di codifica ascii della tastiera */
    /*a[3] = '\0'; questo mette il carattere di fine stringa nella posizione 3 della stringa a quindi a risulta 012 */
    printf("%c\n", b[0] + 1);

    n = sizeof(a)/sizeof(char); /* restituisce la dimensione occupata dall'array a in byte e bisogna dividerlo per lo spazio occupato dal tipo della variabile */
    printf("%d\n", n);
    printf("%s\n", a); /* %s assume il valore della stringa */

}

int str_len(char *a) /* funzione fuori dal main che restituisce la lunghezza della stringa in input*/
{
    int len = 0;
 
    while(a[len] != '\0')
    {
        len++; /* len += 1 */
    }

    return len;
}

char *str_cat(char *a, char *b) /* scrittura della funzione dichiarata a inizio programma */
{
    /* questa funzione prende in input 2 stringhe e le concatena
    mandando in output la stringa concatenata. */
    
    char *c = NULL;
    int na = str_len(a), nb = str_len(b); /* variabili che prendono in input l'output della funzione che restituisce la lunghezza delle stringhe (a e b) */
    int i = 0, j;

    c = malloc((na+nb+1)*sizeof(char)); /*lo spazio di memoria di c sarà dato dalla lunghezza di a + la lunghezza di b che vengono moltiplicati per la grandezza delle variabili char + 1 (carattere di fine stringa (\0)) */

    for(i = 0; i < na; i++)
    {
        c[i] = a[i];
    }

    j = 0;
    while(b[j] != '\0')
    {
        c[i] = b[j];
        i++;
        j++;
    }

    c[i] = '\0';

    return c;
}

int conta_minuscole(char *a)
{   
    int cont = 0;
    int i = 0;
    for (i = 0; i < str_len(a); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            cont++;
        }
    }
    return cont;
}
