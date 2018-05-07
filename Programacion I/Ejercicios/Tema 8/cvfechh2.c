//jcmg@usal.es
//jcmg@usal.es
#include <stdio.h>
#include <stdlib.h>
#include "cvfechh2.h"


int main(void){
	long fecha,ano,temp,hora,hora1,cent,cent1;
	int di, ann,temp1;
	short h,m,s,c;
	fecha=fechasis_ddmmaaaa();
	printf("fecha: %ld\n",fecha);
	ano=fecha%10000;
	temp=bisiesto(ano);
	if(temp) puts("Es bisiesto");
	else puts("No es bisiesto");
	fecha=(fecha/1000000)+(fecha%10000)*10000+(fecha%1000000-fecha%10000)/100;
	printf("fecha: %ld\n",fecha);
	di=dia(fecha);
	ann=annio(fecha);
	printf("Dia: %d\n",di);
	printf("A\244o: %d\n",ann);
	hora=horasis_hhmmsscc();
	printf("Hora: %ld\n",hora);
	hora1=horasis_ccssmmhh();
	printf("Hora: %ld\n",hora1);
	temp1=horavalida(hora%100);
	if(temp1) puts("La hora es valida");
	else puts ("La hora no es valida");
	printf("Hora: %ld\n",hora);
	invertirhora(&hora,0);
	printf("Hora: %ld\n",hora);
	invertirhora(&hora,1);
	printf("Hora: %ld\n",hora);
	cent=hora_a_centesimas(hora);
	printf("El formato %ld en centesimas es: %ld\n",hora,cent);
	cent1=centesimas_a_hora(cent);
	printf("El formato %ld en horas es: %ld\n",cent,cent1);
	h=horas(hora);
	m=minutos(hora);
	s=segundos(hora);
	c=centesimas(hora);
	printf("Horas: %u\nMinutos: %u\nSegundos: %u\nCentesimas: %u\n",h,m,s,c);
	puts("");
	system("pause");
	return 0;
}
