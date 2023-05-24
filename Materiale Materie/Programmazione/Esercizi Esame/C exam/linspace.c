#include <stdlib.h>
#include <stdio.h>


float *linspace(float n0, float n1, int n);

void main(){
    int n = 6;
    float *a = linspace(3,7,n);
   //printf("%f\n",*a);
   for(int i = 0; i < n; i++){
       printf("%f, ",a[i]);
   }
   printf("\n");
}
/*Progettare una funzione C, linspace(n0, n1, n), che restituisce un array di n float
equidistanti sull'intervallo da n0 a n1 inclusi gli estremi.
Ad esempio linspace(3, 7, 6) deve restituire l'array
[ 3.00, 3.80, 4.60, 5.40, 6.20, 7.00 ]*/
float *linspace(float n0, float n1, int n){
    float *tmp = malloc(sizeof(float)*n1);
    //formula linspace : (n1-n0)/(n-1)
    float dist = (n1-n0)/(n-1);
    int val = 0;
    for(int i = 0; i < n; i++){
        tmp[i] = n0 + i*dist;
        //printf("%f ",tmp[i]);
        //printf("%f\n",n0+i*dist);
    }
    return tmp;
}