#include "vector.h"
void Modulo(float *vec1, float *mod1,int dim){

	int i;

	*mod1 = 0;
	for(i=0; i < dim; i++)
		*mod1 += vec1[i] * vec1[i];
	*mod1=sqrt(*mod1);

}

void Suma(float *sum,float *vec1,float *vec2,int dim){

	int i;

	for (i=0; i < dim; i++)
		sum[i] = vec1[i] + vec2[i];

}

float Producto(float *vec1,float *vec2,int dim){

	int i;
	float pr=0;

	for (i=0; i < dim; i++)
		pr+=vec1[i]*vec2[i];

return pr;
}
