#include <stdio.h>
#include <stdlib.h>

void inverter_vetor(int v[]){
    for(int i = 9; i >=0; i--){
        printf("O valor da posicao %d é %d . \n",i,v[i]);
    }
}

void multiplicar(float v[]){
    for(int i = 0; i <10; i++){
        v[i] = v[i] * 2.5;
    }

    for(int i = 0; i <10; i++){
        printf("O valor da posicao %d é %f . \n",i,v[i]);
    }
}

void main()
{
    float valores[10];
    char aux[10];
    for (int i = 0; i<10; i++)
    {
        printf("Introduza um numero: ");
        fgets(aux,10,stdin);
        valores[i] = atoi(aux);
    }
    multiplicar(valores);
}

