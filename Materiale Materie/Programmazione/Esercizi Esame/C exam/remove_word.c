#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remove_word(char*, char*);

int remove_word(char* a, char* b){  //T:O(n*m)+O(m) 
    int i;
    int j;
    int k;
    int c = 1; 
    int lun_a = strlen(a);
    int lun_b = strlen(b);
    for(i = 0; i < lun_a; i++){
        if(a[i] == b[0]){
            for(j = 1; j < lun_b; j++){
                if(a[i+j] == b[j]){
                    c++;
                    k = i+j+1;

                } 
            }
        }
        if(c == lun_b){
            i = strlen(a);
        }
        else{
            c = 1;
        }
    }


    if (c == lun_b){
        for(i = k-c; i+c < lun_a; i++){
            a[i] = a[i+c];
        }

        a[lun_a-lun_b] = '\0';
        for(int i = 0; i < lun_a; i++){
            printf("%c", a[i]);
        }
        printf("\n");
        
        return 1;
    }
    return 0;
    
}

void main(){
    char a[] = "programmazione dei calcolatori";
    char b[] = "azione";

    int risultato = remove_word(a, b);
    printf("%d\n",risultato);
}