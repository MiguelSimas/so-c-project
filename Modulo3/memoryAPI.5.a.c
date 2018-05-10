#include <stdlib.h>
#include <stdio.h>
void main()
{
    int *p;
    p = (int *) malloc(sizeof(int));
    *p = 2;
    printf("%d\n", *p);

}