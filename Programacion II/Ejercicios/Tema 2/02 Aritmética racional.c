#include <stdio.h>
#include <math.h>
#include <ctype.h>

typedef struct {int num, denom;} Racional;

void Modulo_Principal (void);
void Presentacion (void);
void LeerRacional (Racional *);
void MostrarRacional (Racional);
void SumaRacional (Racional, Racional, Racional *);
void RestaRacional (Racional, Racional, Racional *);
Racional MultiplicaRacional (Racional, Racional);
Racional DivideRacional (Racional, Racional);
void SimplificaRacional (Racional *);
int mcd (int, int);

int main (void) {

  char respuesta;
  Presentacion();
  do{
     puts("");
     Modulo_Principal();
     puts("");

     do{
	printf("¿Otra ejecuci\242n (S/N)?: ");
	fflush(stdin);
	respuesta=toupper(getchar());
     }while(respuesta!='S'&&respuesta!='N');

  }while(respuesta!='N');
     
     puts("");
     return 0;
     
}

void Modulo_Principal (void) {

  Racional rac1, rac2, rsum, rres, rprod, rdiv;
  
  printf("Introduzca el primer número racional:\n");
  LeerRacional(&rac1);
  printf("Introduzca el segundo n\243mero racional:\n");
  LeerRacional(&rac2);
          
  puts("");
  SumaRacional (rac1, rac2, &rsum);
  printf("Suma.......: ");
  MostrarRacional(rsum);
  puts("");

  RestaRacional (rac1, rac2, &rres);
  printf("Resta......: ");
  MostrarRacional(rres);
  puts("");
     
  rprod = MultiplicaRacional (rac1, rac2);
  printf("Producto...: ");
  MostrarRacional(rprod);
  puts("");
     
  rdiv = DivideRacional (rac1, rac2);
  printf("Divisi\242n...: ");
  MostrarRacional(rdiv);
  puts("");
}

void Presentacion (void) {

  puts("ARITMETICA BASICA CON NUMEROS RACIONALES");
  puts("========================================");
  puts("");
  printf("Realiza la suma, resta, producto y divisi\242n de n\243meros racionales\n");
  printf("Siempre presenta la expresi%cn irreducible del n\243mero racional\n",162);
  puts("");
}

void LeerRacional (Racional *r) {

  do{
     puts("Escribe el numerador");
     scanf("%d",&r->num);
  }while(r->num==0);
  do{
     puts("Escribe el denominador");
     scanf("%d",&r->denom);
  }while(r->denom==0);
}

void SumaRacional (Racional a, Racional b, Racional *r) {

  r->num=a.num*b.denom+b.num*a.denom;
  r->denom=a.denom*b.denom;
}

void RestaRacional (Racional a, Racional b, Racional *r) {

  r->num=a.num*b.denom-b.num*a.denom;
  r->denom=a.denom*b.denom;
}

Racional MultiplicaRacional (Racional a, Racional b) {

  Racional r;
  r.num=a.num*b.num;
  r.denom=a.denom*b.denom;
  return r;
}

Racional DivideRacional (Racional a, Racional b) {

  Racional r;
  r.num=a.num*b.denom;
  r.denom=a.denom*b.num;
  return r;
}

void MostrarRacional (Racional r) {

  SimplificaRacional(&r);
  if(r.denom<0){
    r.denom*=(-1);
    printf("-%d", r.num);
  }else
    printf(" %d", r.num);

  if (r.denom != 1) printf("/%d", r.denom);
}

void SimplificaRacional (Racional *r) {

  int m;
  m=mcd(r->num,r->denom);
  r->num/=m;
  r->denom/=m;
// Si la fraccion debe llevar segno negativo (num*dem <0)
//    entonces el signo se coloca al numerador 
}

int mcd (int n, int d) {

  int c;

  if(n>d){

    do{
	c=n%d;
	if(c!=0){ n=d; d=c; }
    }while(c!=0);

  return d;
  }else{

    do{
	c=d%n;
	if(c!=0){ d=n; n=c; }
    }while(c!=0);

  return n;
  }
}
