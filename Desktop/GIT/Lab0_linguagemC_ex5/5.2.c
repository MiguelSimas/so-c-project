#include <stdio.h>
void main()
{
    float *p;
    float a;
    printf("Insira um valor: ");
    scanf("%f",&a);
    p = &a;
    (*p)++;
    printf("%.2f\n",a);
}