//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

float media=0, num;
int cont=0;

int main (void){
    
    do{
    printf("Introduce un n\243mero: ");
    scanf("%f", &num);
    cont++;
    media+=num;
    }
    while(num>0);
    media/=cont;
    printf("\nLa media es %.3f\n\n", media);
    system("pause");
    return 0;
}
