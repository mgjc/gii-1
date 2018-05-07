#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct { int g,*p;} Polinomio;

Polinomio *crearP(int);
float evaluarP(const Polinomio *,float);
void liberar(Polinomio *);
void presentar(const Polinomio*);

int main (void){

	Polinomio *x;
	float dato;

	if((x=malloc(sizeof(Polinomio)))==NULL)exit(-1);

	puts("Escribe el grado de tu polinomio:");
	do{
		scanf("%d",&x->g);
		if(x->g<1)puts("Introduce un valor positivo para el grado del polinomio");
	}while(x->g<1);

	x=crearP(x->g);
	puts("Introduce un valor para la 'x' del polinomio:");
	scanf("%f",&dato);
	printf("El resultado de P(%.2f)=%.2f\n",dato,evaluarP(x,dato));
	presentar(x);
	liberar(x);

	return 0;
}

Polinomio *crearP(int dim){

	int i;
	Polinomio *x;
	
	if((x=malloc(sizeof(Polinomio)))==NULL)exit(-1);

	x->g=dim;

	if((x->p=calloc(x->g+1,sizeof(int)))==NULL)exit(-1);

	for(i=0;i<dim;i++){
		printf("Escribe el coeficiente de x^%d: ",dim-i);
		scanf("%d",&x->p[i]);
	}
	printf("Escribe la constante: ");
	scanf("%d",&x->p[dim]);

	x->g=dim;

	return x;
}

float evaluarP (const Polinomio *x, float g){

	float z=0;
	int i,*pot;
	
	if((pot=calloc(x->g,sizeof(int)))==NULL)exit(-1);

	for(i=0;i<x->g;i++){
		if(x->p[i]!=0){
			pot[i]=pow(g,x->g-i);
		}else pot[i]=0;
	}

	for(i=0;i<x->g;i++)
		z+=(pot[i]*x->p[i]);
	
	z+=x->p[x->g];
	
	return z;
}
void liberar(Polinomio *x){
	free(x);
}
void presentar(const Polinomio *x){

	int i,temp;
	temp=x->g;
	
	if(x->p[0]!=0){

		if(x->p[0]<0) printf("-%dx^%d ",x->p[0]*(-1),temp);
		else printf("%dx^%d ",x->p[0],temp);
	}
	temp--;
	for(i=1;i<x->g;i++){
	
		if(x->p[i]!=0){

			if(x->p[i]<0) printf("- %dx^%d ",x->p[i]*(-1),temp);
			else printf("+ %dx^%d ",x->p[i],temp);
		}
		temp--;
	}
	if(x->p[x->g]!=0){
		if(x->p[x->g]<0) printf("- %d\n",x->p[x->g]);
		else printf("+ %d\n",x->p[x->g]);
	}
}
