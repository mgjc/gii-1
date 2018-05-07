#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS_FABRICANTE 16
#define MAX_CHARS_MODELO 32

enum Motor{gasolina,gasoil,hidrogeno,electrico,ninguno};
typedef struct {
  char fabricante[MAX_CHARS_FABRICANTE], modelo[MAX_CHARS_MODELO];
	enum Motor motor;
	int fecha;
	float longitud;
  char codigo;
	float tara;
	double cargaMaxima, pesoMaxRemolcable;
} Vehiculo;

int main (void){

	Vehiculo vehi,veh,ve,v;
	strcpy(vehi.fabricante,"Ford");
	strcpy(vehi.modelo,"Orion");
	vehi.codigo='C';
	vehi.motor=gasoil;
	vehi.fecha=3112;
	vehi.tara=24.953;
	vehi.longitud=3.46;
	vehi.cargaMaxima=1200.91;
	vehi.pesoMaxRemolcable=500.34;
	puts("Con todos los miembros:");
	printf("%ld\n",sizeof(vehi));
	strcpy(veh.fabricante,"Ford");
	strcpy(veh.modelo,"Orion");
	veh.motor=gasoil;
	veh.fecha=3112;
	veh.tara=24.953;
	veh.longitud=3.46;
	veh.cargaMaxima=1200.91;
	veh.pesoMaxRemolcable=500.34;
	puts("Sin el miembro codigo:");
	printf("%ld\n",sizeof(veh));
	strcpy(ve.fabricante,"Ford");
	strcpy(ve.modelo,"Orion");
	ve.codigo='C';
	ve.motor=gasoil;
	ve.fecha=3112;
	ve.longitud=3.46;
	ve.cargaMaxima=1200.91;
	ve.pesoMaxRemolcable=500.34;
	puts("Sin el miembro tara:");
	printf("%ld\n",sizeof(ve));
	strcpy(v.fabricante,"Ford");
	strcpy(v.modelo,"Orion");
	v.motor=gasoil;
	v.fecha=3112;
	v.longitud=3.46;
	v.cargaMaxima=1200.91;
	v.pesoMaxRemolcable=500.34;
	puts("Sin el miembro codigo ni el miembro tara:");
	printf("%ld\n",sizeof(v));
	return 0;
}
