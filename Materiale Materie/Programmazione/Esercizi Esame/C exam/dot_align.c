#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dot_align(char **b, int n);
int left_max(char **b, int  n);
int left(char **b, int i);

void main()
{   
    char *a[] = {"3.14", "0.0001", "52.612", "2.718", "5.0", "123", "1000.0000001"};
    int i = 0;
    while(a[i] != NULL)
    {
        i++;
    }
    i = i-1;
    int n = i;

    char **b = malloc(sizeof(char*)*n);

    for(i = 0; i < n; i++)
    {
        b[i] = *(&a[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s ", b[i]);
    } 
    printf("\n");

    printf("\n");
    dot_align(b, n);
    printf("\n");
}

void dot_align(char **b, int n)
{
    int max = left_max(b, n);
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        int offset = max - left(b, i);
        for (j = 0 ; j < offset ; j++)
        {
            printf(" ");
        }
        printf("%s\n", b[i]);
    }
    
    
}

int left_max(char **b, int  n)
{
    int i;
    int j;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        int c = 0;
        j = 0;
        while (b[i][j] != '.' && b[i][j] != '\0' )
        {
            c++;
            j++;
        }
        if(c > max)
        {
            max = c;
        }
        // printf("MAX: %d\n", max);
    } 
    return max;

}

int left(char **b, int i)
{
    int c = 0;
    int j = 0;
    while (b[i][j] != '.' && b[i][j] != '\0')
        {
            c++;
            j++;
        }
    return c;
}