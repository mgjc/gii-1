#include "clase.h"
#include "auxi.h"
#include "alumno.h"
#define NOTAS 5

int main (void){

	Alumno clase[15];

	Presentacion();
	ModuloPrincipal(clase,15);

	return 0;
}

void Presentacion(void){

	system("clear");
	puts("Array de alumnos");
	puts("================");
	puts("Mostrara unos alumnos con sus notas y su fecha de nacimiento:");
	puts("A continuacion mostrara la media de las notas de todos los alumnos");
	puts("Mostrara cual es la menor nota media de todos los alumnos");
	puts("Mostrara cual es el alumno mas mayor");
	puts("Pulse una tecla para continuar");
	getchar();
	fflush(stdin);

}

void ModuloPrincipal(Alumno *al, int n){

	float not_media[n];
	int i,j=0;

	CargarArraysClaseAleatorio(al,n);
	for(i=0;i<n;i++)
		not_media[i]=NotaMediaArrayClase(al,i);

	for(i=0;i<n-1;i++){
		if(not_media[i]>not_media[i+1]) j=i+1;
	}
	puts("");
	printf("El alumno ");
	puts(al[j].nombre);
	printf("con fecha de nacimiento (%d/%d/%d) tiene la nota media mas baja de todas: %.1f\n",al[j].fnacimiento.dia,al[j].fnacimiento.mes,al[j].fnacimiento.anio,not_media[j]);
	puts("");
	MayorEdadArrayClase(al,n);

}
