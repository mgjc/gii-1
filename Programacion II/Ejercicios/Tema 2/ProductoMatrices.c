#include <stdio.h>
#define N 3

typedef struct { double elemento[N]; } Vector;
typedef struct { Vector fila[N]; } Matriz;

Vector Producto(Matriz,Vector);

int main (void){

	Vector v,pr;
	Matriz m;
	int i, j;

	puts("Introduce el vector");
	for(i=0;i<N;i++)
		scanf("%lf",&v.elemento[i]);

	for(i=0;i<N;i++){
		printf("Introduce la fila %d de la matriz:\n",i+1);
		for(j=0;j<N;j++)
			scanf("%lf",&m.fila[i].elemento[j]);
	}

	pr=Producto(m,v);
	puts("Productor de la matriz y el vector:");
	for(i=0;i<N;i++)
		printf("%.2lf\n",pr.elemento[i]);

	return 0;
}

Vector Producto(Matriz z,Vector y){

	Vector t;
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			t.elemento[i]+=z.fila[i].elemento[j]*y.elemento[j];
		}
}

	return t;
}
