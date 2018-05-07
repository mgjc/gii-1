//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100
int main (void){
	
	int mat1[TAM][TAM]={0},mat2[TAM][TAM]={0},mat3[TAM][TAM]={0};
	int numf1,numc1,numf2,numc2,i,j,k,l,m,n;
	
//	Comprobación dimensión matriz 1

	do{
		printf("Introduce el n\243mero de filas que deseas, el tama\244o m\240ximo es de %d\n",TAM);
		scanf("%d",&numf1);
	}while(numf1<=0||numf1>TAM);
	
	do{
		printf("Introduce el n\243mero de columnas que deseas, el tama\244o m\240ximo es de %d\n",TAM);
		scanf("%d",&numc1);
	}while(numc1<=0||numc1>TAM);
	
//	Petición de datos matriz 1

	for(i=0;i<numf1;i++){
		for(j=0;j<numc1;j++){
			printf("Introduce el elemento %d-%d de la matriz 1\n",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}
	
//	Comprobación dimensión matriz 2

	do{
		printf("Introduce el n\243mero de filas que deseas, el tama\244o m\240ximo es de %d\n",TAM);
		scanf("%d",&numf2);
	}while(numf2<=0||numf2>TAM);
	
	do{
		printf("Introduce el n\243mero de columnas que deseas, el tama\244o m\240ximo es de %d\n",TAM);
		scanf("%d",&numc2);
	}while(numc2<=0||numc2>TAM);
	
//	Petición de datos matriz 2

	for(i=0;i<numf2;i++){
		for(j=0;j<numc2;j++){
			printf("Introduce el elemento %d-%d de la matriz 2\n",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
	}
	
//	Multiplicación de la matriz 1 por la matriz 2

	for(i=0;i<numf1;i++){
		for(j=0;j<numc1;j++){
			for(k=0;k<numc2;k++){
				for(l=0;l<numf2;l++){
					for(m=0;m<numc2;m++){
						for(n=0;n<numf1;n++){
							mat3[n][m]=mat1[i][j]*mat2[l][k];
						}
					}
				}
			}
			
		}
		
	}
	puts("");
	
//	Muestra matriz 1

	for(i=0;i<numf1;i++){
		for(j=0;j<numc1;j++){
			printf("%d ",mat1[i][j]);
		}
	puts("");
	}
	puts("");
	
//	Muestra matriz 2

	for(i=0;i<numf2;i++){
		for(j=0;j<numc2;j++){
			printf("%d ",mat2[i][j]);
		}
	puts("");
	}
	puts("");
	
//	Muestra matriz 3

	for(i=0;i<numf1;i++){
		for(j=0;j<numc2;j++){
			printf("%d ",mat3[i][j]);
		}
	puts("");
	}
	puts("");
	system("pause");
	return 0;
}
