#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ANIOMIN 1900
#define ANIOMAX 2050

typedef struct { char mes_largo[11], mes_corto[4];
		 int dias_mes, orden_mes;} Mes;

void modulo_principal(void);
void presentacion(void);
int calcular_dias_inicio_annio(int, int, const Mes *);
int bisiesto(int);
int main(void){

  char respuesta;

  presentacion();
  do{
    puts("");
    modulo_principal();
    puts("");
    do{
      printf("¿Otra ejecución (S/N)?: ");
      fflush(stdin);
      respuesta = toupper(getchar());
    }while(respuesta!='S'&&respuesta!='N');
  }while(respuesta!='N');
     
  return 0;
}

void modulo_principal(void){

  int mmes, ddia, aanio,temp,diff_dias,i;
  Mes meses[12];
  for(i=0;i<12;i++){
    switch(i){
	case 0: strcpy(meses[i].mes_largo,"Enero");strcpy(meses[i].mes_corto,"Ene"); break;
	case 1: strcpy(meses[i].mes_largo,"Febrero");strcpy(meses[i].mes_corto,"Feb");break;
	case 2: strcpy(meses[i].mes_largo,"Marzo");strcpy(meses[i].mes_corto,"Mar");break;
	case 3: strcpy(meses[i].mes_largo,"Abril");strcpy(meses[i].mes_corto,"Abr");break;
	case 4: strcpy(meses[i].mes_largo,"Mayo");strcpy(meses[i].mes_corto,"May");break;
	case 5: strcpy(meses[i].mes_largo,"Junio");strcpy(meses[i].mes_corto,"Jun");break;
	case 6: strcpy(meses[i].mes_largo,"Julio");strcpy(meses[i].mes_corto,"Jul");break;
	case 7: strcpy(meses[i].mes_largo,"Agosto");strcpy(meses[i].mes_corto,"Ago");break;
	case 8: strcpy(meses[i].mes_largo,"Septiembre");strcpy(meses[i].mes_corto,"Sep");break;
	case 9: strcpy(meses[i].mes_largo,"Octubre");strcpy(meses[i].mes_corto,"Oct");break;
	case 10: strcpy(meses[i].mes_largo,"Noviembre");strcpy(meses[i].mes_corto,"Nov");break;
	case 11: strcpy(meses[i].mes_largo,"Diciembre");strcpy(meses[i].mes_corto,"Dic");break;
    }
    if(i==0||i==2||i==4||i==6||i==7||i==9||i==11) meses[i].dias_mes=31;
    else if(i!=1) meses[i].dias_mes=30;
    meses[i].orden_mes=i+1;
  }
  do{
    puts("Introduce una fecha con formato: aaaammdd");
    scanf("%d",&temp);
    aanio=temp/10000;
    mmes=(temp%10000)/100;
    ddia=temp%100;
    if(bisiesto(aanio)) meses[1].dias_mes=29;
    else meses[1].dias_mes=28;
  }while(aanio<ANIOMIN||aanio>ANIOMAX||mmes<1||mmes>12||ddia>meses[mmes-1].dias_mes||ddia<1);

  diff_dias=calcular_dias_inicio_annio(mmes-1,ddia,&meses[0]);
  printf("Dias transcurridos desde el 1 de Enero: %d",diff_dias);
}

void presentacion(void){

  puts("CALCULO NUMERO DE DIAS DESDE PRINCIPIO DE AÑO");
  puts("===========================================");
  puts("Se pedirán por pantalla una fecha: año, mes y día.");
  puts("El programa calculará el número total de días transcurridos");
  puts("en el año hasta a ese día.");
}

int calcular_dias_inicio_annio(int mm, int dd, const Mes *nn){

  int x=dd,i;
  for(i=0;i<mm;i++)
    x+=nn[i].dias_mes;
  return x;
}

int bisiesto(int aa){

  if((aa%4)==0)return 1;
  else return 0;
}
