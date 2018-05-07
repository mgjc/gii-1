//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159

float radio, altura, area, vol;

int main (void){
    
    printf("Introduce el radio y la altura:\n");
    scanf("%f", &radio);
    scanf("%f", &altura);
    
    area=2*PI*radio*altura;
    vol=PI*radio*radio*altura;
    
    printf("El \240rea es %g\nEl volumen es %g\n", area, vol);
    
    system("pause");
    return 0;   
}
