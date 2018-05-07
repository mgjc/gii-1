#include "clase.h"
void CargarArraysClaseAleatorio(Alumno *al,int m){

	int x,i,j,numA,numN;
	char nombres[][17]={"ALVARO","ARSENIO","CARLOS","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA","RAQUEL",
        "TOMAS", "ZOILO"};
	char apellidos[][17]={" ALONSO"," ALVAREZ"," ARBESU",
        " DOMINGUEZ"," EGIDO"," FERNANDEZ"," FLORIANO"," GARCIA",
        " GONZALEZ"," GOMEZ"," GUTIERREZ",
        " MARTIN", " MORO", " PEREZ"," TURRION",
        " ZAMBRANO"};
	numA=sizeof(apellidos)/17;
	numN=sizeof(nombres)/17;

	srand(time(NULL));
	for(j=0;j<m;j++){
		for(i=0;i<NOTAS;i++){
			al[j].notas[i]=rand()%101;
			al[j].notas[i]/=10;
		}

		al[j].fnacimiento.anio=rand()%13;
		al[j].fnacimiento.anio+=+1983;

		al[j].fnacimiento.mes=rand()%12;
		al[j].fnacimiento.mes++;
		switch(al[j].fnacimiento.mes){
			case 4:
			case 6:
			case 9:
			case 11:
				al[j].fnacimiento.dia=rand()%30;
				al[j].fnacimiento.dia++;
				break;
			case 2:
				x=Bisiesto(al[j].fnacimiento.anio);
				switch(x){
					case 0:
						al[j].fnacimiento.dia=rand()%28;
						al[j].fnacimiento.dia++;
						break;
					case 1:
						al[j].fnacimiento.dia=rand()%29;
						al[j].fnacimiento.dia++;
						break;
				}
				break;
			default:
				al[j].fnacimiento.dia=rand()%31;
				al[j].fnacimiento.dia++;
		}
		/*Cargar nombres y apellidos*/
		sprintf(al[j].nombre,"%s",nombres[rand()%numN]);
		strcat(al[j].nombre,apellidos[rand()%numA]);
		strcat(al[j].nombre,apellidos[rand()%numA]);
		MostrarArrayClase(al, j);
		
	}

}

void MostrarArrayClase(Alumno *al,int i){

	int j;

		puts(al[i].nombre);
		
		printf("%d/%d/%d\n",al[i].fnacimiento.dia,al[i].fnacimiento.mes,al[i].fnacimiento.anio);
		printf("(");
		for(j=0;j<NOTAS;j++) printf(" %.1f ",al[i].notas[j]);
		puts(")");
}

float NotaMediaArrayClase(Alumno *al,int m){

	int i;
	float media=0;

	for(i=0;i<NOTAS;i++){
		media+=al[m].notas[i];
	}
	return media/NOTAS;
}

void MayorEdadArrayClase(Alumno *al, int m){

	int i,tempa=al[0].fnacimiento.anio,tempm=al[0].fnacimiento.mes,tempd=al[0].fnacimiento.dia, temp=0;

	for(i=0;i<m;i++){
		if(al[i].fnacimiento.anio<tempa){
			temp=i;
			tempa=al[i].fnacimiento.anio;
			tempm=al[i].fnacimiento.mes;
			tempd=al[i].fnacimiento.dia;
		}
		if(al[i].fnacimiento.anio==tempa){
			if(al[i].fnacimiento.mes<tempm){
				temp=i;
				tempa=al[i].fnacimiento.anio;
				tempm=al[i].fnacimiento.mes;
				tempd=al[i].fnacimiento.dia;
			}
			if(al[i].fnacimiento.mes==tempm){
				if(al[i].fnacimiento.dia<=tempd){
					temp=i;
					tempa=al[i].fnacimiento.anio;
					tempm=al[i].fnacimiento.mes;
					tempd=al[i].fnacimiento.dia;
				}
			}
		}
	}
	printf("El alumno mas mayor es: ");
	puts(al[temp].nombre);
	printf("(con fecha de nacimiento %d/%d/%d)\n",al[temp].fnacimiento.dia,al[temp].fnacimiento.mes,al[temp].fnacimiento.anio);

}
