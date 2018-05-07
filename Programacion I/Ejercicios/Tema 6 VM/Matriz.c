//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int main (void){
	
	double mat[DIM][DIM]; int i,j,numc,numf;
	
	do{
		printf("Introduce el n\243mero de filas que deseas, el tama\244o m\240ximo es de %d\n",DIM);
		scanf("%d",&numf);
	}while(numf<=0||numf>DIM);
	
	do{
		printf("Introduce el n\243mero de columnas que deseas, el tama\244o m\240ximo es de %d\n",DIM);
		scanf("%d",&numc);
	}while(numc<=0||numc>DIM);
	
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			printf("Introduce el elemento %d-%d\n",i+1,j+1);
			scanf("%lf",&mat[i][j]);
		}
	}
	
	for(i=0;i<numf;i++){
		for(j=0;j<numc;j++){
			printf("%lf ",mat[i][j]);
		}
	puts("");
	}
	
	system("pause");
	return 0;
}
