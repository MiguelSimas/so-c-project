#include <stdio.h>

void main(){
int num;
	printf("Digite um número: ");
	scanf("%d",&num);
	if (num>10){
		printf("\n\nO número é maior que 10");
	} else if (num == 10) {
	printf("\n\nVocê acertou!");
	printf("O número é igual a 10");	
} else{
	printf("\n\nO número é menor que 10.");
}

}
