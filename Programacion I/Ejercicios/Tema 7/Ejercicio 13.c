//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define FILAS 2
#define COLUMNAS 4

int main (void){
	
	char mat[FILAS][COLUMNAS], *pt, (*pt1)[COLUMNAS],(**pt2)[COLUMNAS], *(*pt3[FILAS]),*(*pt4)[FILAS],*pt5[FILAS];
	int i,j,temp=0;
//	mat[FILAS][COLUMNAS] es una matriz tipo char de 2x4
//	*pt es un puntero que apunta a una variable tipo char
//	(*pt1)[COLUMNAS] es un puntero que apunta a un vector de 4 elementos de tipo char 
//	(**pt2)[COLUMNAS] es un puntero que apunta a otro puntero que apunta a un vector de 4 elementos de tipo char
//	*(*pt3[FILAS]) es un vector de 2 punteros que apuntan a un puntero que apunta a elementos de tipo char
//	*(*pt4)[FILAS] es un puntero que apunta a un vector de punteros que apuntan a 2 elementos de tipo char
//	*pt5[FILAS] es un vector de 2 punteros que apuntan a variables de tipo char
	
	for(i=0;i<FILAS;i++){
		for(j=0;j<COLUMNAS;j++){
			mat[i][j]='a'+temp;
			temp++;
		}
	}
	puts("Matriz normal:");
	for(i=0;i<FILAS;i++){
		for(j=0;j<COLUMNAS;j++){
			printf("%c  ",mat[i][j]);
		}
		puts("");
	}
	puts("");
//	la asignación 	pt=mat	 es correcta
//	pt es un puntero y mat es otro puntero al ser el nombre de la matriz

//	La asignación 	pt=*mat	 es correcta
//	pt es un puntero y *mat un puntero a la primera fila de la matriz mat
	puts("Con pt");
	
//	Como pt es un puntero que apunta a un elemento char hacemos que apunte al puntero de la matriz
//	Para que se recorran todos los elementos de la matriz hacemos el FILAS*COLUMNAS
	pt=*mat;
	for(i=0;i<FILAS*COLUMNAS;i++){
		if(i==COLUMNAS)puts("");
		printf("%c  ",*pt+i);
	}
	puts("");puts("");
	puts("Con pt1:");
	
//	Como pt1 es un puntero que apunta a un vector de 4 elementos
//	Hay que forzarle para que llegue a 2x4 elementos con el FILAS*COLUMNAS

//	(*pt1) es un puntero, literalmente, para que devuelva el valor que contiene
//	Hace falta incluirle otro simbolo de indirección
	pt1=mat;
	for(i=0;i<FILAS*COLUMNAS;i++){
		if(i==COLUMNAS)puts("");
		printf("%c  ",**pt1+i);
	}
	puts("");puts("");
	
	puts("Con pt2:");
//	Como pt2 es un puntero que apunta a otro puntero que apunta a un vector de 4 elementos
//	Hay que forzarle para que llegue a 2x4 elementos con el FILAS*COLUMNAS
	temp=0;
	pt2=*mat;
	for(i=0;i<COLUMNAS;i++){
		printf("%c  ",*(*pt2)+i);
		if(i==COLUMNAS-1&&temp==0){
			puts("");
			pt2=*(mat+1);
			i=-1;
			temp=1;
		}
	}
	puts("");puts("");
	
//	Como pt3 es un vector de 2 punteros que apuntan a un puntero que apunta a elementos de tipo char
//	Hay que asignar a pt3 las filas de la matriz y recorrerlas
	puts("Con pt3:");
	pt3[0]=*mat;
	pt3[1]=*(mat+1);
	for(i=0;i<FILAS;i++){
		for(j=0;j<COLUMNAS;j++){
			printf("%c  ",*(*(pt3+i))+j);
		}
		puts("");
	}
	puts("");
//	Como pt4 es un puntero que apunta a un vector de punteros que apuntan a 2 elementos de tipo char
//	Basta con que pt4 apunte a pt3 que es un vector para sacar sus valores
	puts("Con pt4:");
	temp=0;
	pt4=*pt3;
	for(i=0;i<COLUMNAS;i++){
		printf("%c  ",*(*pt4)+i);
		if(i==COLUMNAS-1&&temp==0){
			puts("");
			pt4=*(pt3+1);
			i=-1;
			temp=1;
		}
	}
	puts("");puts("");
	puts("Con pt5:");
//	Como pt5 es un vector de 2 punteros que apuntan a elementos de tipo char
//	Y al tener mat dos filas, el primer puntero del vector a puntará a la fila 1 y el segundo a la fila 2
	pt5[0]=*mat;
	pt5[1]=&mat[1][0];
	for(j=0;j<FILAS;j++){
		for(i=0;i<COLUMNAS;i++){
			printf("%c  ",*(*(pt5+j)+i));
		}
		puts("");
	}
	puts("");
	system("pause");
	return 0;
}
