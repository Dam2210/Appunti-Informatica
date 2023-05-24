#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(char*);

void main()
{
    char a[] = "programmazione in C";
    printf("la stringa è: %s\n", a);
    printf("la stringa al contrario è: %s\n", reverse_string(a));
}

char *reverse_string(char *str)
{
    int len = strlen(str)-1;
    int k = len;
    char temp;
    for (int i = 0; i <= len/2 ; i++)
    {
        temp = str[i];
        str[i] = str[k];
        str[k] = temp; 
        k--;
    }
    return str;   
}