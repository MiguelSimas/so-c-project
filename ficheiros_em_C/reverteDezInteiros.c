#include "reverteDezInteiros.h"

void inverter_vetor(int v[]){
    for(int i = 9; i >=0; i--){
        printf("O valor da posicao %d é %d . \n",i,v[i]);
    }
}

void main()
{
    int valores[10];
    char aux[10];
    for (int i = 0; i<10; i++)
    {
        printf("Introduza um numero: ");
        fgets(aux,10,stdin);
        valores[i] = atoi(aux);
    }
    inverter_vetor(valores);
}

