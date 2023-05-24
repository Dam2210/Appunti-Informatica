#include <stdio.h>
#include <stdlib.h>

void print_array2d_bad(int a[][3], int nr )
{
    /* Stampa matrici di 3 colonne, troppo specifica! */
    /* il parametro nr indica il numero di righe */
}

void print_array2d(int *a, int nc, int nr)
{
    int i, j;
    for(i = 0; i < nr; i++)
    {
        for(j = 0; j < nc; j++)
        {
            printf("%d, ", a[i*nc + j] );
        }
        printf("\n");
    }
}

void main()
{
    int a[2][3] = {1, 9}; /* struttura dati con 2 righe e 3 colonne quindi array a 2 dimensioni */
    int b[] = {10, 11, 12, 13};
    int c2[][2] = {20, 21, 22, 23, 24, 25}; /* 2 colonne (quindi 3 righe) */
    int c3[][3] = {20, 21, 22, 23, 24, 25}; /* 3 colonne (quindi 2 righe) */
    int d[] = {30, 31, 32, 33, 34, 35};

    int nr = 2, nc = 3; /* nr è il numero delle righe mentre nc è il numero delle colonne */
    int nr_d = 2, nc_d = 3;
    int i, j, k;
    for(i = 0; i < nr; i++)
    {
        for(j = 0; j < nc; j++)
        {
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }
    k = 2;
    printf("%d\n", b[k]);

   print_array2d(d, 2, 3);
   print_array2d(d, 3, 2);

}