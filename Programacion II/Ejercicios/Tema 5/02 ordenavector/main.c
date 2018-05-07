#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vector.h"
#include "nodo.h"

void ModuloPrincipal (void);
void Presentacion (void);


int main (void) {

     char respuesta;
  
     system ("cls");
     Presentacion();
     do
       { printf("\n");
         ModuloPrincipal();
	     printf("\n");
	     do
	       { printf("�Otra ejecuci�n (S/N)?: ");
	         fflush(stdin);
	         respuesta = toupper(getchar());
	       }
	     while (respuesta != 'S' && respuesta != 'N');

       }
     while (respuesta != 'N');
     
     printf("\n");
     return 0;
     
}

void ModuloPrincipal (void) {

   const char *formato = "%d";
   
   tipoDatoVector *vct = NULL;
   int dimv;
   
   ***** COMPLETAR:                       ***** 
   ***** DECLARACION DE LA LISTA ENLAZADA *****
  
   int j;

   do {
     printf("\nIntroduzca la longitud del vector: ");
     scanf("%d", &dimv);
     if (dimv <=0)
        printf("\nLa dimensi�n debe de ser positiva.\n");
   } while (dimv <=0);
   
   vct = CreaVector (dimv);
   
   printf("\nVector original\n");
   PresentaVector (vct, dimv, formato);

   for (j=0; j<dimv; j++)
      ***** COMPLETAR ******
      ***** Llamar a una funcion para InsertarNodoOrdenCreciente
      ***** COMPLETAR ******

            
   ***** COMPLETAR ******
   ***** Recorre la lista almacenando cada nodo en la posicion del vector 
   ***** y eliminando cada nodo
   ***** COMPLETAR ******

 
   printf("\nVector ordenado\n");
   PresentaVector (vct, dimv, formato);
   
   system("pause");

   LiberaVector(vct);
}

void Presentacion (void) {

     puts("")
     puts("====================================================");
     puts("");
     puts("")
     puts("")
     puts("");
}
