#include "calculadora.h"

float soma(float x, float y){
  return x+y;

}
float subtracao(float x, float y){
  return x-y;
}


float multiplicacao(float x,float y){
 return x*y;
}


float divisao(float x, float y){
  return 0.0;
}



int main(int argc, char *argv[]){
    float a,b;


    if (argc <= 1){
      printf("Deve indicar que operação vai realizar :+,-,/ ou *. ");

    }
    else
    {
    
        //Teste
       printf("O valor de argv: %s\n",argv[0]);
 
       printf("O valor de argv: %s\n",argv[1]);

        if (strcmp("-",argv[1]) == 0){
         printf("Subtração\n");
         printf("Introduza os valores  a subtrair:");
         scanf("%f %f",&a,&b);
         float res1 = subtracao(a,b);
         printf("O resultado da subtracao é:%2.2f\n",res1);

        }
        if (strcmp("+",argv[1]) == 0){
          printf("Soma");
          printf("Introduza os valores  a somar:");
          scanf("%f %f",&a,&b);
          float res = soma(a,b);
          printf("O resultado da soma é:%2.2f\n",res);
        }
    }
}
