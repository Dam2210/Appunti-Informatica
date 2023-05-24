#include <stdio.h>
#include <stdlib.h>

int *x_array(int *a, int na, int *b, int nb);
void matrice_print(int *m, int na, int nb);

void main()
{
    int a[] = {1, 2, 3};
    int b[] = {10, 20, 30, 40};

    int na = sizeof(a)/sizeof(int);
    int nb = sizeof(b)/sizeof(int);

    int *x = x_array(a, na, b, nb);
    matrice_print(x, na, nb);

}

int *x_array(int *a, int na, int *b, int nb)
{
    int i, j;
    int *x = malloc(sizeof(int)*(na*nb));
    for(i = 0; i < na; i++)
    {
        for(j = 0; j < nb; j++)
        {
            x[i*nb + j] = a[i]*b[j];
        }   
    }
    return x;
}



void matrice_print(int *m, int na, int nb)
{
    int i, j;
    printf("===================\n");
    for(i = 0; i < na; i++)
    {
        for(j = 0; j < nb; j++)
        {
            printf("%d, ", m[i*nb + j]);
        }
        printf("\n");
    }
}