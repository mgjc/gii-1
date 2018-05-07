#include <stdio.h>
#include <stdlib.h>

int *ConcatenaVectores (int *, int, int *, int);
void PresentaVector (int *, int);
int *LeerVector (int);
void ModuloPrincipal (void);
void Presentacion (void);

int main (void) {

	char respuesta;
  
   system ("clear");
   Presentacion();
	do{
		puts("");
      ModuloPrincipal();
		puts("");
	   do{
			printf("¿Otra ejecución (S/N)?: ");
	      fflush(stdin);
	      respuesta = toupper(getchar());
	   }while (respuesta != 'S' && respuesta != 'N');
	}while(respuesta!='N');
     
	puts("");
   return 0;
}

void ModuloPrincipal (void) {

	int *vector1, *vector2, n1, n2;
   int *vectorc, nc;    

   do{
		printf("\nIntroduzca la longitud del primer vector: ");
   	scanf("%d", &n1);
     	if (n1 <=0)
		puts("La dimension debe de ser positiva");
   }while(n1<=0);
   
	puts("Introduzca los elementos (int) del primer vector");

	vector1=LeerVector(n1);
   
   do{
     printf("\nIntroduzca la longitud del segundo vector: ");
     scanf("%d", &n2);
     if(n2<=0)
		puts("La dimension debe de ser positiva");
   }while(n2<=0);

	puts("Introduzca los elementos (int) del segundo vector");

	vector2=LeerVector(n2);
   
	vectorc=ConcatenaVectores(vector1,n1,vector2,n2);

	puts("Vectores inciales");
	puts("Primer vector:");
   PresentaVector (vector1, n1);
	puts("Segundo vector:");
   PresentaVector (vector2, n2);

	nc=n1+n2;
 
	puts("Vector concatenado:");
   PresentaVector (vectorc, nc);

   free(vector1);
   vector1 = NULL;
   
   free(vector2);
   vector2 = NULL;   
   
   free(vectorc);
   vectorc = NULL; 
}

void Presentacion (void) {

	puts("CONCATENACION DE VECTORES");
   puts("=========================");
   puts("");
   puts("El programa solicita dos vectores por pantalla y presenta el vector ");
   puts("concatenado de ambos.                                               ");
   puts("");
}

int *LeerVector (int dim) {

	int i,*v;

	if((v=calloc(dim,sizeof(int)))==NULL){exit(-1);}

	for(i=0;i<dim;i++){
		printf("Introduce el elemento numero %d: ", i+1);
		scanf("%d",&v[i]);
	}

	return v;
}

int *ConcatenaVectores (int *v1, int dim1, int *v2, int dim2) {

	int *v, i;

	if((v=calloc(dim1+dim2,sizeof(int)))==NULL){exit(-1);}

	for(i=0;i<dim1;i++) v[i]=v1[i];
	for(i=0;i<dim2;i++) v[i+dim1]=v2[i];

	return v;
}

void PresentaVector (int *v, int dim) {

	int i;

	for(i=0;i<dim;i++)printf("%d  ",v[i]);
	puts("");

}
