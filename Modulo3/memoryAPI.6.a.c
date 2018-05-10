#include <stdlib.h>
#include <stdio.h>
void main()
{
    int *p;
    p = (int *) malloc(sizeof(int));
    p = NULL;
    printf("%d\n", *p);

}