#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void centering(int *a, int r, int c);
void print_array(int *a, int r, int c);

int a[] = {
1,1,0,0,0,
1,0,0,0,0,
1,1,1,0,0,
1,1,0,0,0,
1,1,1,1,0,
1,1,1,1,1
};

int r = 6, c = 5;

void main()
{
    print_array(a, 6, 5);
    centering(a, 6, 5);
}

void centering(int *a, int r, int c)
{
    int i = 0;
    if(a[i] == 1)
    {
        if(a[c/2] == 0)
        {
            int appo;
            a[c/2] = appo;
            a[i] = a[c/2];
            appo = a[i];
            i++;
        }
        else
        {
            int appo;
            a[(c/2)+1] = appo;
            a[i] = a[(c/2)+1];
            appo = a[i];
            i++;
        }
    }
    printf("-----------------------\n");
    print_array(a, 6, 5);
}

void print_array(int *a, int r, int c)
{
    int i = 0;
    int d = 0;

    while(i < r*c)
    {
        printf("%d,", a[i]);
        i++;
        d++;
        if(d == r-1)
        {
            printf("\n");
            d = 0;
        }
    }
}