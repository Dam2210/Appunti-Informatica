#include <stdio.h>
#include <stdlib.h>

struct matrice
{
    float *a;
    int nr, nc;
};
typedef struct matrice matrice;
matrice matrice_init(int nr, int nc); 
void matrice_print(matrice m);
void pos_element_m(matrice m, int k, int *i, int *j);

matrice matrice_init(int nr, int nc) /* funzione che crea una matrice vuota, tutti 0 */
{
    matrice m;
    m.a = malloc(sizeof(float)*nr*nc);
    m.nr = nr;
    m.nc = nc;
    for(int i = 0; i < m.nr*m.nc; i++)
    {
        m.a[i] = 0;
    }
    return m;
}

void matrice_print(matrice m) /* funzione che tampa la matrice */
{
    int i, j;
    printf("===================\n");
    for(i = 0; i < m.nr; i++)
    {
        for(j = 0; j < m.nc; j++)
        {
            printf("%f, ", m.a[i*m.nc + j]);
        }
        printf("\n");
    }
}

void pos_element_m(matrice m, int k, int *i, int *j) /* Funzione che restituisce i e j di un elemento k nella matrice */
{
    *i = k / m.nc; /* indice riga in m dell'elemento in posizione k di m.a */
    *j = k % m.nc; /* indice colonna in m dell'elemento in posizione k di m.a */ 
}

void main()
{
    matrice m = matrice_init(3, 2);
    matrice_print(m);

    int k = 5;
    int a, b;
    printf("\n");
    pos_element_m(m, k, &a, &b); /* con la & prendo l'indirizzo di memoria della variabile */
    printf("i = %d, j = %d\n", a, b);

}