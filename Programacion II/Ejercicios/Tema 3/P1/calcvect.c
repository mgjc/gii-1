#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "vector.h"
#include "iovector.h"

void Presentacion(void);

int main(void) {

  float vector1[DIMMAX], vector2[DIMMAX];
  int diml;
  float modulov1, modulov2;
  float vsuma[DIMMAX];
  float prod_escalar;
  int i;
  char terminar;

  do{

	Presentacion();
	CreaVector(vector1,vector2,&diml);
	LeeVector(vector1,vector2,diml);
	Suma(vsuma,vector1,vector2,diml);
	Modulo(vector1,&modulov1,diml);
	Modulo(vector2,&modulov2,diml);
	prod_escalar=Producto(vector1,vector2,diml);

       puts("");
       printf("Módulo del primer  vector: %g\n", modulov1);
       printf("Módulo del segundo vector: %g\n", modulov2);

       puts("\nVector suma:");
       printf("V1 + V2 = (%g", vsuma[0]);
       for (i=1; i < diml; i++)
           printf(", %g", vsuma[i]);
       printf(")\n");

       puts("\nProducto escalar:");
       printf("V1 x V2 = %g\n", prod_escalar);

       puts("\n");

       do{
			printf("Salir del programa (S/N)?: "); 
          fflush(stdin);
          scanf("%c", &terminar);
          terminar = toupper(terminar);
       }while(terminar!='S'&&terminar!='N');
        
       system ("clear");

  }while(terminar!='S');

  return 0;
}

void Presentacion(void){
  system ("clear");
  puts("Cálculo vectorial");
  puts("=================");
  puts("Se pedirán por pantalla dos vectores y se presentará:");
  puts("   - El módulo de cada uno de ellos.");
  puts("   - Su vector suma.");
  puts("   - Su producto escalar.");
  printf("El programa permite trabajar con vectores de dimensión máxima: %d.\n", DIMMAX);
}
