#include "iovector.h"
void CreaVector(float *vec1,float *vec2,int *dim){

	int i;

	do{
		printf("Dimensión de los vectores (entre 1 y %d)?: ", DIMMAX);
      scanf("%d", dim);
   }while(*dim<=0||*dim>DIMMAX);

   puts("\nIntroduzca el primer vector:");
   for (i=0; i < *dim; i++){
   	printf("v1[%d]?: ", i+1);
      scanf("%f", &vec1[i]);
   }

   puts("\nIntroduzca el segundo vector:");
   for (i=0; i < *dim; i++){
   	printf("v2[%d]?: ", i+1);
      scanf("%f", &vec2[i]);
   }

}

void LeeVector(float *vec1,float *vec2,int dim){

	int i;

   puts("\nVectores introducidos:");
   printf("V1 = (%g", vec1[0]);
   for (i=1; i < dim; i++)
		printf(", %g", vec1[i]);
   printf(")\n");

   printf("V2 = (%g", vec2[0]);
   for (i=1; i < dim; i++)
		printf(", %g", vec2[i]);
   printf(")\n");

}
