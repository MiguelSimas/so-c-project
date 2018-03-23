#include <stdio.h>
void main()
{
    int *p;
    int a;
    printf("Insira um valor: ");
    scanf("%d",&a);
    p = &a;
    (*p)++;
    printf("%d\n",a);
}