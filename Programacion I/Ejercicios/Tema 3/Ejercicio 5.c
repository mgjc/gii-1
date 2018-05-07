//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double num;
double cuad;
double cubo;
double ln;
double lg;
double raiz;

int main (void){
    
    printf("Escribe un numero\n");
    scanf("%lf", &num);
    
    cuad=pow(num,2);
    cubo=pow(num,3);
    ln=log(num);
    lg=log10(num);
    raiz=sqrt(num);
    
    printf("Numero introducido...:%lg\n", num);
    printf("Cuadrado.............:%lg\n", cuad);
    printf("Cubo.................:%lg\n", cubo);
    printf("Logaritmo neperiano..:%lg\n", ln);
    printf("Logaritmo decimal....:%lg\n", lg);
    printf("Raiz cuadrada........:%lg\n", raiz);
    system("pause");
    return 0;    
    
}
