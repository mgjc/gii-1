#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *crearP(int);
float evaluarP(const int *,int,float);
void liberar(int *);
void presentar(const int*,int);

int main (void){

	int *x,g;
	float d,dato;

	puts("Escribe el grado de tu polinomio:");
	do{
		scanf("%d",&g);
		if(g<1)puts("Introduce un valor positivo para el grado del polinomio");
	}while(g<1);

	x=crearP(g);
	puts("Introduce un valor para la 'x' del polinomio:");
	scanf("%f",&dato);
	d=evaluarP(x,g,dato);
	printf("El resultado de P(%.2f)=%.2f\n",dato,d);
	presentar(x,g);
	liberar(x);

	return 0;
}

int *crearP(int dim){

	int *p,i;

	if((p=calloc(dim+1,sizeof(int)))==NULL)exit(-1);

	for(i=0;i<dim;i++){
		printf("Escribe el coeficiente de x^%d: ",dim-i);
		scanf("%d",&p[i]);
	}
	printf("Escribe la constante: ");
	scanf("%d",&p[dim]);

	return p;
}

float evaluarP (const int *x, int dim, float g){

	float z=0;
	int i,*pot,j;
	
	if((pot=calloc(dim,sizeof(int)))==NULL)exit(-1);

	for(i=0;i<dim;i++){
		if(x[i]!=0){
			pot[i]=pow(g,dim-i);
		}else pot[i]=0;
	}

	for(i=0;i<dim;i++)
		z+=(pot[i]*x[i]);
	
	z+=x[dim];
	
	return z;
}
void liberar(int *x){
	free(x);
}
void presentar(const int *x, int dim){

	int i,temp;
	temp=dim;
	
	if(x[0]!=0){

		if(x[0]<0) printf("-%dx^%d ",x[0]*(-1),temp);
		else printf("%dx^%d ",x[0],temp);
	}
	temp--;
	for(i=1;i<dim;i++){
	
		if(x[i]!=0){

			if(x[i]<0) printf("- %dx^%d ",x[i]*(-1),temp);
			else printf("+ %dx^%d ",x[i],temp);
		}
		temp--;
	}
	if(x[dim]!=0){
		if(x[dim]<0) printf("- %d\n",x[dim]);
		else printf("+ %d\n",x[dim]);
	}
}
