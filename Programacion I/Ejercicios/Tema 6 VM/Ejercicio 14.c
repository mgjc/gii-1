//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define MAX 25
#define MIN 3

int main (void){
	
	double mat[MAX][MAX]={0},temp1=0,temp2=0,sumaint=0,sumaext=0;
	int numf,numc,i,j;
	do{
		puts("Escribe el n\243mero de filas que deseas:");
		scanf("%d",&numf);
	}while(numf<MIN||numf>MAX);
	
	do{
		puts("Escribe el n\243mero de columnas que deseas:");
		scanf("%d",&numc);	
	}while(numc<MIN||numc>MAX);
//	lee
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			printf("Escribe el elemento %d-%d\n",i+1,j+1);
			scanf("%lf",&mat[i][j]);
		}
	}
//	temp2 almacena los extemos de arriba, abajo y laterales
	i=0;
	for(j=0;j<numc;j++){
		temp2+=mat[i][j];
	}
	j=0;
	for(i=0;i<numf;i++){
		temp2+=mat[i][j];
	}
	i=numf-1;
	for(j=0;j<numc;j++){
		temp2+=mat[i][j];
	}
	j=numc-1;
	for(i=0;i<numf;i++){
		temp2+=mat[i][j];
	}
//	elementos de las esquinas repetidos una vez, se eliminan y se guarda en sumaext
	sumaext=temp2-(mat[0][0]+mat[numf-1][numc-1]+mat[0][numc-1]+mat[numf-1][0]);

//	sumaint almacena los internos
	for(i=1;i<numf-1;i++){
		for(j=1;j<numc-1;j++){
			sumaint+=mat[i][j];
		}
	}
	
	puts("Matriz:");
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			printf("%lf\t",mat[i][j]);
		}
		puts("");
	}
	puts("");
	printf("Suma de los elementos del \"marco\": %lf\n",sumaext);
	puts("");
	printf("Suma de los elementos internos: %lf\n",sumaint);
	puts("");
	if(sumaext>sumaint){
		puts("La matriz introducida es un marco");
	}else{
		puts("La matriz introducida no es un marco");
	}
	puts("");
	system("pause");
	return 0;
}
