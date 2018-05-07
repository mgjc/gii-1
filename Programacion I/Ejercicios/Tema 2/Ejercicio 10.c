//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

float grados, radianes;

int main (void){
    
    printf("Introduce los grados:\n");
    scanf("%f", &grados);
    
    radianes=(PI/180)*grados;
    
    printf("%g grados son %g radianes\n", grados, radianes);    
    
    system("pause");
    return 0;   
}
