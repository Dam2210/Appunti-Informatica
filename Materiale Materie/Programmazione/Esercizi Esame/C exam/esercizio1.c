#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rimuovi_non_ordinati(char *a);
int getDynamicCharArraySize(char* string);
void main(int argc, char *argv[]){
    char* a=malloc(sizeof(argv[1]));
    a=argv[1];
    printf("%s\n",a );
    rimuovi_non_ordinati(a);
    printf("%s\n",a );
    printf("%ld\n",sizeof(a)/sizeof(char));
}

void rimuovi_non_ordinati(char *a){
    int i,k=0;
    int n=strlen(a);
    for(i=1;i<n;i++){
        if(a[i]<a[i-1-k]){
        k++;
        }else{
        a[i-k]=a[i];
        }
    }
    a[n-k] = '\0';
}
