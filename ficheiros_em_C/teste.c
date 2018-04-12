#include <stdio.h>
void main(){
int v = 0;
int x = 1;
int y = 2;
int z = 3;
v+=x+y;
printf("\nX = %d, Y = %d, Z = %d, V = %d", x,y,z,v);
x *= y = z+1;
printf("\nX = %d, Y = %d, Z = %d, V = %d", x,y,z,v);
v+= x +=y+=2;
printf("\nX = %d, Y = %d, Z = %d, V = %d", x,y,z,v);
}
