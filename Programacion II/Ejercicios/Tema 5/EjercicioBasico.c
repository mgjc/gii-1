#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int main (void) {

   ListaEnlazada lst=NULL;;
   tipoNodoRef nuevo;
   tipoNodoRef indice;
   tipoNodoRef aborrar;

   tipoInfo num;

	int nodos,suma;

   lst = NULL;

// Creamos una lista enlazada de numeros enteros
// Terminamos cuando se teclee un numero 0 o negativo
// Los nodos se insertan en la lista siempre como primero

   puts("Introduzce un numero:");
   scanf("%d", &num);
   while (num >0) {

      nuevo = (tipoNodoRef) malloc(sizeof(tipoNodo));
      nuevo->info = num;
      nuevo->sig = NULL;

      nuevo->sig = lst;
      lst = nuevo;

      puts("Introduzce un numero:");
      scanf("%d", &num);
   }


// Recorremos la lista para visualizarla
	puts("");
	puts("Numeros introducidos");
   indice = lst;
   while (indice != NULL) {
      printf("%d\n", indice->info);
      indice = indice-> sig;
   }
/*
  Conjunto de sentencias para contar cuantos nodos tienen la ListaEnlazada
  Sumar el valor de todos los numeros enteros contenidos en los nodos
  Presentandolos en pantalla
*/
	indice=lst;
	nodos++;
	suma+=indice->info;
	while(indice->sig!=NULL){
		indice=indice->sig;
		suma+=indice->info;
		nodos++;
	}

	printf("\nHay %d nodos\n", nodos);
	printf("La suma de todos los numeros es: %d\n",suma);

/*
  Leer numero de teclado e insertarlos como nodos
  Deben de insertarse siempre como el ultimo nodo
  Mostrar luego la lista
*/
   puts("Introduzce un numero:");
   scanf("%d", &num);
   while (num >0) {
      nuevo = (tipoNodoRef) malloc(sizeof(tipoNodo));
      nuevo->info = num;
	//indice->sig=nuevo 	para que el elemento aterior apunte al creado
		indice->sig=nuevo;
	//nuevo->sig=NULL 	para que el elemento creado apunte a NULL
      nuevo->sig = NULL;
	
	//para que el indice se mueva de posición a una más, en este caso al creado para que así se puedan crear más nodos, si no se hace esto se estaría sobreescribiendo el mismo dado que los creados en las anteriores iteraciones quedarían descartados porque el indice no se movería
		indice=indice->sig;

      puts("Introduzce un numero:");
      scanf("%d", &num);
   }

	puts("");
	puts("Numeros introducidos");
   indice = lst;
   while (indice != NULL) {
      printf("%d\n", indice->info);
      indice = indice-> sig;
   }
	indice=lst;
	nodos=1;
	suma+=indice->info;
	while(indice->sig!=NULL){
		indice=indice->sig;
		suma+=indice->info;
		nodos++;
	}

	printf("\nHay %d nodos\n", nodos);
// Eliminamos cada uno de los nodos de la lista enlazada
// Al finalizar este algolitmo lst queda con valor NULL

   aborrar = lst;
   while (lst != NULL) {
      lst = lst-> sig;
      free(aborrar);
      aborrar = lst;
   }

	puts("");
	
   return 0;
}
