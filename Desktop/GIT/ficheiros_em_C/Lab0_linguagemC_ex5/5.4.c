#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *par = (int *)malloc(1000 * sizeof(int));
    int impar = (int *)malloc(1000 * sizeof(int));
    int aux;
    int contador = 0;
    while (aux != -999)
    {
        printf("Insira um número inteiro(-999 para terminar): ");
        scanf("%d",aux);
        if (aux % 2 == 0)
        {
            par[contador] = aux;
        }
        else
        {
            impar[contador] = aux;
        }
        contador++;
    }
    for (int i = 0; i < contador; i++)
    {
        printf("O array dos pares contém os números: %d", par[i]);
    }
    for (int i = 0; i < contador; i++)
    {
        printf("O array dos impares contém os números: %d", impar[i]);
    }
}