#include <stdio.h>
#define N 3

typedef struct { double elemento[N];} Vector;
double ProductoEscalar(Vector,Vector);
Vector SumaVectores(Vector,Vector);

int main (void){

	int i;
	Vector v1, v2, vs;
	puts("Introduce el primer vector:");
	for(i=0;i<N;i++)
		scanf("%lf",&v1.elemento[i]);
	puts("Introduce el segundo vector:");
	for(i=0;i<N;i++)
		scanf("%lf",&v2.elemento[i]);

	printf("Producto escalar de los vectores 1 y 2: %lf",ProductoEscalar(v1,v2));
	vs=SumaVectores(v1,v2);
	printf("\nSuma de los vecotres 1 y 2: (%lf,%lf,%lf)",vs.elemento[0],vs.elemento[1],vs.elemento[2]);
	puts("");
	return 0;
}

double ProductoEscalar(Vector v, Vector x){

	double t=0;
	int i;
	
	for(i=0;i<N;i++)
		t+=v.elemento[i]+x.elemento[i];

	return t;
}

Vector SumaVectores(Vector v, Vector x){

	Vector t;
	int i;
	
	for(i=0;i<N;i++)
		t.elemento[i]=v.elemento[i]+x.elemento[i];

	return t;
}
