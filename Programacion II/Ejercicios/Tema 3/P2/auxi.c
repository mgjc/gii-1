#include "auxi.h"
int Bisiesto(int ann){

	if((ann%4)==0) return 1;

	return 0;
}

int ComprobarFecha(Alumno *al, int m){

	int d,n,bi;

	bi=Bisiesto(al[m].fnacimiento.anio);
	n=al[m].fnacimiento.mes;
	d=al[m].fnacimiento.dia;
	if((n==1)||(n==3)||(n==5)||(n==7)||(n==8)||(n==10)||(n==12)){
		if((d<1)||(d>31))return 1;
	}else{
		if(n==2){
			if(bi){
				if((d<1)||(d>29)) return 1;
			}else{
				if((d<1)||(d>28)) return 1;
			}
		}else{
			if((d<1)||(d>30)) return 1;
		}
	}

	return 0;
}
