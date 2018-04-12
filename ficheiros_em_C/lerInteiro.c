#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	char buffer[256];
	printf("Introduza um número:");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("O valor introduzido é %d .",i);
	return 0;
}
