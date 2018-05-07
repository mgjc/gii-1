#include <stdio.h>
#include <stdlib.h>
#define FILAS 3
#define COLUMNAS 4

int main(void){

	FILE *pt;

	const char fich_enco[]="matriz_enco.txt";
   const char fich_deli[]="matriz_deli.txt";
   const char fich_tabu[]="matriz_tabu.txt";

	int f,c,suma=0,numero;
	char x_numero[15];

	pt=fopen(fich_enco,"r");
	if(pt==NULL) puts("No se ha podido abrir el archivo");

	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
		fscanf(pt,"%3d",&numero);
		printf("%3d",numero);
		suma+=numero;
		}
	puts("");
	}

	printf("La suma de los numeros es: %d\n",suma);
	fclose(pt);
	
	suma=0;

	pt=fopen(fich_deli,"r");
	if(pt==NULL) puts("No se ha podido abrir el archivo");

	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
		fscanf(pt,"%[^*]%*c",x_numero);
		numero=atoi(x_numero);
		printf("%3d",numero);
		suma+=numero;
		}
	puts("");
	}

	printf("La suma de los numeros es: %d\n",suma);
	fclose(pt);

	suma=0;

	pt=fopen(fich_tabu,"r");
	if(pt==NULL) puts("No se ha podido abrir el archivo");

	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
		fscanf(pt,"%[^\t]%*c",x_numero);
		numero=atoi(x_numero);
		printf("%3d",numero);
		suma+=numero;
		}
	puts("");
	}

	fclose(pt);
	printf("La suma de los numeros es: %d\n",suma);

	return 0;
}
