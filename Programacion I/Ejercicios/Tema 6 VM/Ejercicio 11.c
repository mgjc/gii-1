//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define MAX 25

int main (void){
	
	double mat[MAX][MAX],tempmax,tempmin; int max[MAX][MAX],i,k=0,l=0,j,numf,numc;
	
	do{
		printf("Introduce el n\243mero de filas que deseas, el tama\244o m\240ximo es de %d\n",MAX);
		scanf("%d",&numf);
	}while(numf<=0||numf>MAX);
	
	do{
		printf("Introduce el n\243mero de columnas que deseas, el tama\244o m\240ximo es de %d\n",MAX);
		scanf("%d",&numc);
	}while(numc<=0||numc>MAX);
	
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			printf("Introduce el elemento %d-%d de la matriz\n",i+1,j+1);
			scanf("%lf",&mat[i][j]);
		}
	}
	tempmax=mat[0][0]-1;
	tempmin=mat[0][0]+1;
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			if(mat[i][j]>tempmax){
				tempmax=mat[i][j];
			}
			if(mat[i][j]<tempmin){
				tempmin=mat[i][j];
			}
		}
	}
	printf("M\240ximo: %lf\nM\241nimo: %lf\n",tempmax,tempmin);
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			if(mat[i][j]==tempmax){
				printf("M\240ximo en %d-%d\n",i+1,j+1);
			}
		}
	}
	puts("");
	
	system("pause");
	return 0;
}
