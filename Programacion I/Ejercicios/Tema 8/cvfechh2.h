//jcmg@usal.es
#include <dos.h>
#include <time.h>
long fechasis_ddmmaaaa (void);
int bisiesto (long annio);
int dia (long f);
int annio (long f);
long horasis_hhmmsscc (void);
long horasis_ccssmmhh (void);
int horavalida (long h);
void invertirhora(long *h, int invers);
long centesimas_a_hora (long c);
long hora_a_centesimas (long c);
short horas (long h);
short minutos (long h);
short segundos (long h);
short centesimas (long h);

long fechasis_ddmmaaaa (void){
	long fecha;
	struct tm *d;
	time_t curtime;
	curtime = time(NULL);
	d = localtime(&curtime);
	fecha=((*d).tm_year + 1900) + ((*d).tm_mon + 1) * 10000L + ((*d).tm_mday*1000000L);
	return fecha;
	
}
int bisiesto (long annio){
	if((annio%4)==0) return 1;
	return 0;
}
int dia (long f){
	return f%100;
}
int annio (long f){
	return (f-(f%10000))/10000;
}
long horasis_hhmmsscc (void){
	long hora;
	struct tm *x;
	time_t curtime;
	curtime = time(NULL);
	x = localtime(&curtime);
	hora=x->tm_sec *100 + x->tm_min*10000 + x->tm_hour*1000000;
	return hora;
}
long horasis_ccssmmhh (void){
	long hora;
	struct tm *x;
	time_t curtime;
	curtime = time(NULL);
	x = localtime(&curtime);
	hora=x->tm_sec*10000 + x->tm_min*100 + x->tm_hour;
	return hora;
}
int horavalida (long h){
	if(h>-1&&h<24) return 1;
	return 0;
}
void invertirhora(long *h, int invers){
	int hor,min,seg,cen;
	hor=*h/1000000;
	min=(*h/10000)%100;
	seg=*h%10000-*h%100; seg/=100;
	cen=*h%100;
	if(invers){
		*h=cen*1000000+seg*10000+min*100+hor;
	}else{
		*h=cen*1000000+seg*10000+min*100+hor;
	}
}
long centesimas_a_hora (long c){
	long x,temp;
//	
//	No se implementar esta función de manera correcta
//	
	return x;
}
long hora_a_centesimas (long c){
	long x,temp;
	temp=(c/1000000)*60*60*100;
	x=temp;
	c-=c/1000000;
	temp=(c/10000)*60*100;
	x+=temp;
	c-=c/10000;
	temp=(c/100)*100;
	x+=temp;
	c-=c/100;
	x+=c;
	return x;
}
short horas (long h){
	short x;
	x=h/1000000;
	return x;
}
short minutos (long h){
	short x;
	x=(h/10000)%100;
	return x;
}
short segundos (long h){
	short x;
	x=h%10000-h%100;
	return x/100;
}
short centesimas (long h){
	short x;
	x=h%100;
	return x;
}
