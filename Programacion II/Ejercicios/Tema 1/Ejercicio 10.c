#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {float x, y;} Vector;
Vector leerPunto(void);
void presentarPunto(Vector);
float calcularDistancia(Vector, Vector);
Vector puntoMedio(Vector, Vector);

int main (void){
float temp;
Vector p1,p2,t;
p1=leerPunto();
presentarPunto(p1);
puts("Introduce otro punto para calcular la distancia entre ellos y el punto medio");
p2=leerPunto();
temp=calcularDistancia(p1,p2);
t=puntoMedio(p1,p2);
printf("Distancia entre el punto 1 al punto 2: %.2f",temp);
printf("\nPunto medio entre el punto 1 y el punto 2: (%.2f,%.2f)\n",t.x,t.y);
return 0;
}
Vector leerPunto(void){
Vector c;
puts("Introduce las coordenadas en x");
scanf("%f",&c.x);
puts("Introduce las coordenadas en y");
scanf("%f",&c.y);
return c;
}
void presentarPunto(Vector a){
printf("(%.2f,%.2f)\n",a.x,a.y);
}
float calcularDistancia(Vector a, Vector b){
float c;
c=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
return c;
}
Vector puntoMedio(Vector a, Vector b){
Vector c;
c.x=(a.x+b.x)/2;
c.y=(a.y+b.y)/2;
return c;
}
