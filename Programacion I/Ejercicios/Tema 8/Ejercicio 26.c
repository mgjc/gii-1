//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 3
void iniciar(float(*)[COL],int,float);
int main (void){
	int i,j;
	float x,mat[FIL][COL];
	puts("Que valor inicial quieres que tenga la matriz?");
	scanf("%f",&x);
	printf("La matriz tiene %d filas\n",FIL);
	for(i=0;i<FIL;i++)
		iniciar((*mat+i),FIL,x);
	puts("");
	for(i=0;i<FIL;i++){
		for(j=0;j<COL;j++)
			printf("%f\t",mat[i][j]);
			puts("");
	}
	system("pause");
	return 0;
}

void iniciar(float(*m)[COL],int z,float ini){
	int i;
	for(i=0;i<z;i++)
		**(m+i)=ini;
}
