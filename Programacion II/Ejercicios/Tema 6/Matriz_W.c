#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 3
#define COLUMNAS 4
#define MAX	10

int main (void){

	FILE *pt;

	const char fich_enco[]="matriz_enco.txt";
	const char fich_deli[]="matriz_deli.txt";
	const char fich_tabu[]="matriz_tabu.txt";

	int f,c,suma=0,numero;

	srand(time(NULL));

	pt=fopen(fich_enco,"w");
	if(pt==NULL) puts("No se ha podido crear el fichero");

	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
			numero=rand()%(MAX+1);
			fprintf(pt,"%3d",numero);
			suma+=numero;
		}
		fprintf(pt,"\n");
	}
	fclose(pt);

	printf("Suma de todos los elementos: %d\n",suma);

	suma=0;
	pt=fopen(fich_deli,"w");
	if(pt==NULL) puts("No se ha podido crear el fichero");

	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
			numero=rand()%(MAX+1);
			fprintf(pt,"%d*",numero);
			suma+=numero;
		}
		fprintf(pt,"\n");
	}
	fclose(pt);

	printf("Suma de todos los elementos: %d\n",suma);

	pt=fopen(fich_tabu,"w");
	if(pt==NULL) puts("No se ha podido crear el fichero");

	suma=0;
	for(f=0;f<FILAS;f++){
		for(c=0;c<COLUMNAS;c++){
			numero=rand()%(MAX+1);
			fprintf(pt,"%d\t",numero);
			suma+=numero;
		}
		fprintf(pt,"\n");
	}
	fclose(pt);

	printf("Suma de todos los elementos: %d\n",suma);

	return 0;
}
