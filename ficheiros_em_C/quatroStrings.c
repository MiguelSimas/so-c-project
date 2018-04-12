#include <string.h>
#include <stdio.h>

void main(){

char a[10];
char b[10];
char c[10];
char d[10];
char f[40];

scanf("%s",a);
scanf("%s",b);
scanf("%s",c);
scanf("%s",d);

//strcpy(f,"");
strcat(f,a);
strcat(f,b);
strcat(f,c);
strcat(f,d);
printf("%s",f);

}
