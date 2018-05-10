#include <stdio.h>
#include <stdlib.h>

void main()
{
    int vetor[100];
    int *p;
    p =  (int *)malloc(sizeof(int) * 100);
    p = vetor;
    int i = 0;
    while(i <= 10000000000000){
        p =(int *)malloc(sizeof(int) * 100);
        i++;
    }
}