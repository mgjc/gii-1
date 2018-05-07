//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100
int comparadora(double*,double*,int);
int main (void){
	int temp,elements,i;
	double vector1[TAM],vector2[TAM];
	do{
		puts("Escribe un n\243mero para la dimensi\242n m\240xima de los vectores:");
		scanf("%d",&elements);
	}while(elements<=0||elements>TAM);
	for(i=0;i<elements;i++){
		printf("Escriba el elemento %d\n",i+1);
		scanf("%lf",(vector1+i));
	}
	for(i=0;i<elements;i++){
		printf("Escriba el elemento %d\n",i+1);
		scanf("%lf",(vector2+i));
	}
	temp=comparadora(vector1,vector2,elements);
	if(temp)
		puts("Los vectores no son iguales en algun elemento");
	else
		puts("Los vectores tienen los mismos elementos en el mismo orden");
	system("pause");
	return 0;
}
int comparadora(double *v1,double *v2,int dim){
	int i,temp=0;
	for(i=0;i<dim;i++){
		if(*(v1+i)!=*(v2+i)){temp=1;break;}
	}
	return temp;
}
