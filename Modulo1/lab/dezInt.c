#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int a = atoi(argv[1]);
    for (int i = 0; i < a; i++)
    {
        printf("%d\n", i);
    }
}