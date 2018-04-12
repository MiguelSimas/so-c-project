#include <stdio.h>
#include <stdlib.h>
void main()
{
    char a[10];
    char *pc = (char *) malloc(10 * sizeof(char));
    pc = a;
    printf("Insira uma string: ");
    fgets (pc, 10, stdin);
    for (int i = 0; i<10;i++)
        printf("%c",a[i]);
}