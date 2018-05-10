#include <stdlib.h>
#include <stdio.h>

void main()
{
    int *p = (int *)malloc(sizeof(int));
    int numero = NULL;
    *p = numero;
    numero = 2;
}