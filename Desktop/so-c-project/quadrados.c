#include <stdio.h>

float quadrados(float x, float y){
    return ((x*x) + (y*y));
}

void main(){
    float x;
    x = quadrados(5,5);
    printf("%f",x);
}