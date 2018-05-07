#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *crearV(int,int,int);
void presentar(int*,int);
void liberar(int *);

int main (void){

	int x, y, z, *v;

	puts("Introduce la dimension del vector a crear:");
	do{
		scanf("%d",&z);
		if(z<1)puts("Introduce un numero positivo para la dimension del vector a crear");
	}while(z<1);
	puts("Introduce el elemento minimo que aceptaras en el vector:");
	do{
		scanf("%d",&x);
		if(x<1)puts("Introduce un numero positivo para saber el minimo elemento del vector a crear");
	}while(x<1);
	puts("Introduce el elemento maximo que aceptaras en el vector:");
	do{
		scanf("%d",&y);
		if(y<1)printf("Introduce un numero positivo mayor que %d para saber el maximo elemento del vector a crear\n",x);
	}while(y<x);

	v=crearV(z,x,y);
	presentar(v,z);
	liberar(v);

	return 0;

}

int *crearV(int dim, int min, int max){

	int *x, i;

	if((x=calloc(dim,sizeof(int)))==NULL) exit (-1);

	srand(time(NULL));
	
	for(i=0;i<dim;i++){
		x[i]=rand()%(max-min+1)+min;
	}

	return x;
}

void presentar(int *v,int dim){

	int i;

	for(i=0;i<dim;i++)printf("%d ",v[i]);
	puts("");
}

void liberar(int *x){

	free(x);

}
