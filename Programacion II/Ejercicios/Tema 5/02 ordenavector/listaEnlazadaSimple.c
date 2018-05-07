//
//  listaEnlazadaSimple.c
//  Definición de las FUNCIONES GENERICAS o COMUNES para manejo
//  de la lista enlazada objeto de nuestro programa.
//  Son genéricas o comunes porque son válidas para todo tipo de listas,
//  independientemente de los miembros dato definidos para el nodo.
//
//  Este fichero debe de incluir el archivo de cabecera con la
//  definicion del NODO con el que trabajará la lista
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nodo.h"
#include "listaEnlazadaSimple.h"

/* ---------------------------------------------------------- */
   tipoNodoRef creaNodo(tipoInfoRef info) {
/* ---------------------------------------------------------- */
	tipoNodoRef nuevo;

    if (NULL == (nuevo = (tipoNodoRef) malloc(sizeof(tipoNodo)))) // (1)
        return NULL;
	else {
		nuevo->info = *info; // (2)
		nuevo->sig = NULL;   // (3)
	}
	return nuevo;
}

/* ---------------------------------------------------------- */
   int crearVacia (ListaEnlazadaRef pt_raiz) {
/* ---------------------------------------------------------- */
// Iniciamos el puntero de entrada a la lista a NULL
	*pt_raiz = NULL;
	return 0;
}

/* ---------------------------------------------------------- */
   int estaVacia(ListaEnlazada raiz) {
/* ---------------------------------------------------------- */
// Retorna 1 si el puntero de entrada a la lista está a NULL, es decir
// la lista no tienen ningún nodo
	return (raiz == NULL);
}


/* -------------------------------------------------------------------------------------------- */
   int insertarAntesDeNodo (ListaEnlazadaRef pt_raiz, tipoNodoRef pos, tipoInfoRef info) {
/* -------------------------------------------------------------------------------------------- */
// ==> Inserta un nuevo nodo antes del apuntado por el puntero pos
// ==> Deciciones de diseño:
//     Si la lista recibida esta vacia, se inserta el nuevo nodo como primero
//     Si pos se recibe a NULL, se inserta el nuevo nodo como primero
// ==> El algoritmo es robusto porque comprueba que el puntero pos apunta realmente a un nodo de la lista.
//     En caso contrario, no se inserta el nuevo nodo, liberando la memoria reservada previamente para 
//     el nodo y devolviendo -2 por el valor de retorno
// ==> Valores que devuelve la función:
//     -1: Si error al crear el nodo
//     -2: No existe en la lista el nodo apuntado por pos
//      0: Si crea e inserta el nodo con exito
// ==> En la sentencia      while (ant != NULL && ant->sig != pos)    debe de ponerse en ese orden la expresion
//     Debido a la evaluación en cortocircuito, si ant es NULL el resultado del AND es falso, y no se evalua 
//     la segunda expresion ant->sig != pos. De esa forma evitamos que teniendo ant valor NULL, la evaluacion de 
//     ant->sig diera un error. 

	tipoNodoRef nuevo, ant;
	
	if (NULL == (nuevo = creaNodo(info)))
		return -1;
	else {
		if (estaVacia(*pt_raiz) || pos == NULL || pos == *pt_raiz) {
             // Se inserta como primer nodo si la lista esta vacia, o 
             // se recibe el puntero pos a NULL o
             // el puntero pos apunta al primero nodo de la lista
			nuevo->sig = *pt_raiz; // nuevo apunta a primer nodo de la lista
			*pt_raiz = nuevo;      // el puntero de entrada a la lista apunta a nuevo nodo
		}
		else {
			ant = *pt_raiz;         // ant apunta a primer nodo de la lista
			while (ant != NULL && ant->sig != pos) // recorremos la lista hasta encontrar el nodo que esta antes
                 ant = ant->sig;    // del que apunta pos, pues es antes del de pos donde hay que insertar el nuevo
                                    // Si no lo encontramos terminaremos con ant == NULL 
            if (ant != NULL) {      // existe el nodo apuntado por pos     
                nuevo->sig = pos;   // nuevo nodo apunta a pos (se coloca antes que el nodo pos)
                ant->sig = nuevo;   // el nodo que apuntaba a pos apunta ahora a nuevo (nuevo queda antes que pos)
            }
            else { 
                free(nuevo);        // pos no apunta realmente a ningun nodo. Liberamos la memoria reservado
                return -2;          // porque no enlazaremos el nuevo nodo en la lista
            }                         
		}
		return 0;
   }
}


/* -------------------------------------------------------------------------------------------- */
   int insertarDespuesDeNodo (ListaEnlazadaRef pt_raiz, tipoNodoRef pos, tipoInfoRef info) {
/* -------------------------------------------------------------------------------------------- */
// ==> Inserta un nuevo nodo despues del apuntado por el puntero pos
// ==> Deciciones de diseño:
//     Si la lista recibida esta vacia, se inserta el nuevo nodo como primero
//     Si pos se recibe a NULL, se inserta el nuevo nodo como ultimo
// ==> El algoritmo es robusto porque comprueba que el puntero pos apunta realmente a un nodo de la lista.
//     En caso contrario, no se inserta el nuevo nodo, liberando la memoria reservada previamente para 
//     el nodo y devolviendo -2 por el valor de retorno
// ==> Valores que devuelve la función:
//     -1: Si error al crear el nodo
//     -2: No existe en la lista el nodo apuntado por pos
//      0: Si crea e inserta el nodo con exito


    tipoNodoRef nuevo, aux, ant;
	
	if (NULL == (nuevo = creaNodo(info)))  // (1)
		return -1;
	else {
		if (estaVacia(*pt_raiz))   // Si vacia, insertamos el nuevo nodo como primero
			*pt_raiz = nuevo;      // el puntero de entrada a la lista apunta a nuevo nodo
        else { 	
                aux = *pt_raiz;      // aux apunta a primer nodo de la lista
                while (aux != NULL && aux != pos) { // recorremos la lista hasta encontrar el nodo pos 
                     ant = aux;                     // siempre ademas apuntamos con ant al nodo anterior a pos
                     aux = aux->sig;     
		        }
                if (aux != NULL && pos != NULL) { // Si he encontrado el nodo buscado y pos no estaba a NULL
                                                  // insertamos el nodo despues de pos
                    nuevo->sig = pos->sig;  // nuevo nodo apunta al siguiente a pos (se coloca despues que el nodo pos)
                    pos->sig = nuevo;       // el nodo posterior a pos apunta ahora a nuevo (nuevo queda despues de pos)  
                }
			    else if (pos == NULL)       // Si pos es NULL insertamos el nuevo nodo al final Da igual que hayamos 
			            ant->sig = nuevo;   // encontrado o no el nodo pos en la lista. el puntero ant segun el  
			                                // bucle anterior, ha quedado apuintando al ultimo nodo
			         else {
                        free(nuevo);        // pos no apunta realmente a ningun nodo. Liberamos la memoria reservado
                        return -2;          // porque no enlazaremos el nuevo nodo en la lista
                     }                         
        }
        return 0;
	}
}


/* -------------------------------------------------------------------- */
   int insertarNodoComienzo(ListaEnlazadaRef pt_raiz, tipoInfoRef info) {
/* -------------------------------------------------------------------- */
// ==> Crea un nuevo nodo y lo inserta como primero de la lista enlazada
// ==> Insertar antes pasando la direccion (pos) del primer nodo de la lista
	return insertarAntesDeNodo(pt_raiz, *pt_raiz, info);
}


/* -------------------------------------------------------------------- */
   int insertarNodoFinal (ListaEnlazadaRef pt_raiz, tipoInfoRef info) {
/* -------------------------------------------------------------------- */
// ==> Crea un nuevo nodo y lo inserta como ultimo de la lista enlazada
// ==> Insertar despues de la direccion (pos) a NULL, por tanto se 
//     inserta como ultimo nodo
	return insertarDespuesDeNodo(pt_raiz, NULL, info);
	
/* Otra forma --------------------------------------------------
	tipoNodoRef fin;
	if (estaVacia(*pt_raiz)) 
		return insertarDespuesDeNodo(pt_raiz, *pt_raiz, info);
		    // Insertar despues, pasando la direccion (pos) a NULL
	else {  // Localizamos el ultimo nodo de la lista 
		fin = *pt_raiz;
		while (fin->sig != NULL)
			fin = fin->sig;
			// Insertamos despues pasando la direccion (pos) del ultimo nodo
		return insertarDespuesDeNodo(pt_raiz, fin, info);
	}
   ------------------------------------------------------------- */
}


/* --------------------------------------------------------------------------- */
   int eliminarNodo (ListaEnlazadaRef pt_raiz, tipoNodoRef pos) {
/* --------------------------------------------------------------------------- */
// ==> Elimina el nodo apuntado por el puntero pos
// ==> Valores que devuelve la función:
//     -1: Si la lista recibida esta vacia
//     -2: Si el puntero pos recibido esta a nulo
//     -3: Si no se encuentra el nodo pos
//      0: Si se elimina con exito el nodo pos

	tipoNodoRef ant;
	
	if (estaVacia(*pt_raiz)) 
		return -1;
	else if (pos == NULL)
		return -2;
	else if (pos == *pt_raiz) {      // Si pos apunta al primer nodo, eliminamos el primero
		*pt_raiz = (*pt_raiz)->sig;  // El puntero de entrada a la lista pasa a apuntar al segundo nodo 
		free(pos);                   // Liberamos memoria del nodo pos
		return 0;
	}
	else {
		ant = *pt_raiz;              // Recorremos la lista hasta encontrar el nodo anterior al pos
		while (ant != NULL && ant->sig != pos)
			ant = ant->sig;
		if (ant != NULL) {           // Eliminamos un nodo intermedio. Algoritmo tambien valido si nodo a eliminar es el ultimo
		    ant->sig = pos->sig;     // El nodo anterior a pos apunta a quien apunte pos (al siguiente a pos)
			free(pos);               // Liberamos el nodo pos
			return 0;                
		}
		else
			return -3;   // No hemos encontrado el nodo pos
	}
}


/* --------------------------------------------------------------------------- */
   int eliminarNodoComienzo (ListaEnlazadaRef pt_raiz) {
/* --------------------------------------------------------------------------- */      
// ==> Elimina el primer nodo de la lista enlazada
// ==> Eliminamos nodo pasandole la direccion (pos) del primero 
	return eliminarNodo(pt_raiz, *pt_raiz);
}


/* --------------------------------------------------------------------------- */
   int eliminarNodoFinal (ListaEnlazadaRef pt_raiz) {
/* --------------------------------------------------------------------------- */
// ==> Elimina el ultimo nodo de la lista enlazada
// ==> Eliminar nodo pasandole la direccion (pos) del ultimo 
    
    tipoNodoRef aBorrar;
	
    if (estaVacia(*pt_raiz))
		return -1;
	else {
		aBorrar = *pt_raiz;
		while (aBorrar->sig != NULL)     // Recorremos la lista hasta encontrar el ultimo 
		                                 // nodo (el que apunta a NULL)
			aBorrar = aBorrar->sig;
		return eliminarNodo(pt_raiz, aBorrar);
                   // Eliminamos nodo pasandole la direccion (pos) del ultimo 
	}
}


/* --------------------------------------------------------------------------- */
   int eliminarNodoFinalEficiente (ListaEnlazadaRef pt_raiz) {
/* --------------------------------------------------------------------------- */
// ==> Elimina el ultimo nodo de la lista enlazada
// ==> Es mas eficiente que la implementacion anterior porque el no llamarse 
//     a la funcion eliminarNodo(), se evita el recorrido de la lista que hace 
//     esta funcion siempre

    tipoNodoRef aux, aBorrar;
	
	if (estaVacia(*pt_raiz)) {
		return -1;
	}
	else {
		aBorrar = *pt_raiz;
		while (aBorrar->sig != NULL) {    // Recorremos la lista hasta encontrar el ultimo 
                                          // nodo (el que apunta a NULL)
			aux = aBorrar;                // aBorrar apunta al ultimo nodo. aux apunta al nodo penultimo
			aBorrar = aBorrar->sig;
		}
	
    	if (aBorrar == *pt_raiz)  // La lista solo tiene un nodo. Se inicia el puntero de entrada a NULL
			*pt_raiz = NULL;
		else                      // El anterior al aBorrar se hace apuntar a NULL 
			aux->sig = NULL;
	
    	free(aBorrar);            // Se libera memoria del nodo a eliminar (el ultimo)
		return 0;
    }
}


/* --------------------------------------------------------------------------- */
   int liberarListaEnlazada (ListaEnlazadaRef pt_raiz) {
/* --------------------------------------------------------------------------- */       
// ==> Recorremos toda la lista y vamos liberando cada nodo
// ==> Los nodos se eliminan en el orden en que se van encontrando en la lista
//     desde el primero hasta el ultimo
// ==> Valores que devuelve la función:
//     -1: Si la lista recibida esta vacia
//      0: Si se elimina con exito toda la lista

	tipoNodoRef aBorrar, aux;
	
	if (estaVacia(*pt_raiz)) 
		return -1;
	else {
		aux = *pt_raiz;
		while (aux != NULL) { 
			aBorrar = aux;  // aBorrar sera el nodo a eliminar, pero 
			aux = aux->sig; // antes de eliminar un nodo, apuntamos con aux a su siguiente
			free(aBorrar);
		}
		*pt_raiz = NULL;    // Al final la lista debe quedar vacia, es decir su puntero de entrada a NULL
		return 0;
	}
}

