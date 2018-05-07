#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define  MAX 25 
#define  LMINIMO -1000.00F
#define  LMAXIMO  1000.00F

typedef struct {
   float x;
   float y;
} Punto;

typedef struct  {
   float dmedia;
   float dminima;
   float dmaxima;
} CualificadorTr;

void ModuloPrincipal (void);
void Presentacion (void);
void EscribirPunto (Punto);
float DistanciaPuntos (Punto, Punto);
void CrearTrayectoria (Punto *, int, float, float);
void VerTrayectoria (const Punto *, int);
float DistanciaMediaTrayectoria (const Punto *, int);
float DistanciaMaximaTrayectoria(const Punto *, int);
float DistanciaMinimaTrayectoria(const Punto *, int);
void CualificarTrayectoria (const Punto *, int, CualificadorTr *);
void VerCualificadorTrayectoria (const CualificadorTr *);

int main (void) {

     char respuesta;

     Presentacion();
     do{
			puts("");
	   	ModuloPrincipal();
			puts("");
	  		do{
				printf("¿Otra ejecución (S/N)?: ");
	         fflush(stdin);
	         respuesta = toupper(getchar());
	      }while(respuesta!='S'&&respuesta!='N');
    }while(respuesta!='N');

    return 0;
}

void ModuloPrincipal (void) {

     Punto p1, p2;
     float dist;
     Punto trayectoria1[MAX];
     float distmedia;
     float distmaxima;
     float distminima;
     CualificadorTr cualifica_tr1;

     CrearTrayectoria(trayectoria1, MAX, LMINIMO, LMAXIMO);
     VerTrayectoria(trayectoria1, MAX);
     CualificarTrayectoria(trayectoria1, MAX,&cualifica_tr1);
	  VerCualificadorTrayectoria(&cualifica_tr1);
}

void EscribirPunto (Punto p) {

     printf ("(%7g, %7g)", p.x, p.y);
}

float DistanciaPuntos (Punto p1, Punto p2) {

     float distan;
     distan = sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
     return distan;
}

void Presentacion (void) {

     puts("TRATAMIENTO DE TRAYECTORIAS DE PUNTOS");
     puts("=====================================");
     puts("Genera una trayectoria aleatoria y la presenta en pantalla.");
     puts("Posteriormente la cualifica, calculando:");
     puts("     - La distancia mínima");
     puts("     - La distancia máxima");
     puts("     - La distancia media");
     puts("");
}

void CrearTrayectoria (Punto *tr, int dim, float linf, float lsup) {

	int i,j;

	for(i=0;i<dim;i++){
		j=i;
		for(j=0;j<i;j++){
			if(tr[j].x==tr[i].x&&tr[j].y==tr[i].y) {i--; break;}
		}
		do{
			puts("Introduce las coordenadas en el eje X:");
			scanf("%f",&tr[i].x);
		}while(tr[i].x<linf||tr[i].x>lsup);
		do{
			puts("Introduce las coordenadas en el eje Y:");
			scanf("%f",&tr[i].y);
		}while(tr[i].y<linf||tr[i].y>lsup);

	}
}

void VerTrayectoria (const Punto *tr, int dim) {

     int i;

     for (i=0; i<dim; i++) {
          EscribirPunto (tr[i]);
          puts("");
     }
}

float DistanciaMediaTrayectoria (const Punto *tr, int dim) {

	int i;
	float temp=0;

	for(i=0;i<dim-1;i++)
		temp+=DistanciaPuntos(tr[i],tr[i+1]);
	
	return (temp/(dim-1));
}

float DistanciaMaximaTrayectoria (const Punto *tr, int dim) {

	int i=0;
	float temp=DistanciaPuntos(tr[i],tr[i+1]);

	for(i=0;i<dim;i++)
		if(DistanciaPuntos(tr[i],tr[i+1])>temp)temp=DistanciaPuntos(tr[i],tr[i+1]);

	return temp;
}

float DistanciaMinimaTrayectoria (const Punto *tr, int dim) {

	int i=0;
	float temp=DistanciaPuntos(tr[i],tr[i+1]);

	for(i=0;i<dim;i++)
		if(DistanciaPuntos(tr[i],tr[i+1])<temp)temp=DistanciaPuntos(tr[i],tr[i+1]);

	return temp;
}

void CualificarTrayectoria (const Punto *tr, int dim, CualificadorTr *p) {

	p->dmaxima=DistanciaMaximaTrayectoria(tr,dim);
	p->dmedia=DistanciaMediaTrayectoria(tr,dim);
	p->dminima=DistanciaMinimaTrayectoria(tr,dim);

}

void VerCualificadorTrayectoria (const CualificadorTr *ct) {

     printf("Distancia mínima: %.2f\n", ct->dminima);
     printf("Distancia máxima: %.2f\n", ct->dmaxima);
     printf("Distancia media : %.2f\n", ct->dmedia);
}
