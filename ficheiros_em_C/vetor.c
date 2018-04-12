#include <stdio.h>
int main ()
{
	//int num[100]; /* Declara um vetor de inteiros de 100 posicoes */
	char letra[10];
	int count=0;
	int totalnums;
	do
	{
		//printf ("\nEntre com um numero (-999 p/ terminar): ");
		printf("\nEntre com um caracter (x para terminar): ");
		//scanf ("%d",&num[count]);
		scanf("%c", &letra[count]);
		count++;
	} //while (num[count-1]!=-999);
	while(letra[count-1]!='x');
	totalnums=count-1;
	//printf ("\n\n\n\t Os números que você digitou foram:\n\n");
	printf ("\n\n\n\t Os caracteres que você digitou foram:\n\n");
	for (count=0;count<totalnums;count++)
		printf (" %c---",letra[count]);
	printf ("\nJá está!\n");
	printf("Now mining bitcoin >: D\n");
return(0);
}
