#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Filas 10
#define Columnas 10
#define Minfil 3
#define Mincol 3

void CrearMatrizAleatorios(int (*)[Columnas],int,int);
void VerMatrizAleatorios(int (*)[Columnas],int, int);

int main (void){

	int fil,col,**mat;

	do{
		puts("Introduce las filas a usar para la matriz:");
		scanf("%d",&fil);
	}while(fil<Minfil||fil>Filas);

	do{
		puts("Introduce las columnas a usar para la matriz:");
		scanf("%d",&col);
	}while(col<Mincol||col>Columnas);

	if((mat=malloc(col*sizeof(int)))==NULL)exit(-1);

	CrearMatrizAleatorios(mat[col],fil,col);

	return 0;
}
