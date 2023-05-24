#include <stdio.h>

void scambia(int *p, int *q);
int conta_minuscole(char *a);

void main()
{
    int a = 1,  b = 11;
    int *pa = &a;
    *pa = 99;
    char w[] = "pr0graMMaZ1oNe PyThon";
    /* Esercizio 1:
       Scrivere una funzione che scambia 2 variabili intere.*/
    scambia(&a, &b); /* & serve per tirare fuori l'indirizzo dalla variabile */
    printf("il valore di a è: %d\n", a);
    printf("il valore di b è: %d\n", b);

    int num_minuscole = conta_minuscole(w);
    printf("il numero di caratteri minuscoli della stringa... %s .... è: %d\n", w, num_minuscole);
}

void scambia(int *p, int *q) /*devo usare due puntatori per non avere copie e usare effettivamente i valori di a e b */
{
    int t = *p; /* con *p ricavo il valore puntato da p quindi in questo caso a (*(*p)) */
    *p = *q;
    *q = t;
}

int conta_minuscole(char *a)
{   
    int cont = 0;
    int i = 0;
    while(a[i] != '\0')
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            cont++;
        }
        i++;
    }
    return cont;
}