#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vector.h"

tipoDatoVector *CreaVector (int dim) {

   int i,*v;
   
   if ( (v = (tipoDatoVector *) calloc(dim, sizeof(tipoDatoVector))) == NULL )
  	  return NULL;
   
   srand(time(NULL));
   for (i=0; i<dim; i++) v[i]=((rand()%ALEATORIOMAX)+1)+((rand()%ALEATORIOMIN)+1)*(-1);
   
   return v;
}

void LiberaVector (tipoDatoVector *v){free (v);} 

void PresentaVector (tipoDatoVector *v, int dim, const char *fmt) {

   int i;
   for (i=0; i<dim; i++) {
     printf("Elemento [%d] = ", i);
     printf(fmt, v[i]);
     puts("");
   }
}
