//
//  nodo.h
//  Definicion del NODO de la lista enlazada
//

#ifndef __NODO_H
#define __NODO_H

#include "tipoinfo.h"

// ------------------------------------------------------------------
//  Declaraciones GENERICAS o COMUNES para manejo de listas enlazadas
// ------------------------------------------------------------------
typedef tipoInfo * tipoInfoRef;   // Puntero al miembro información de los nodos

typedef struct tipoNodo {         // Definicion del nodo
    tipoInfo info;
    struct tipoNodo *sig;
} tipoNodo;

typedef tipoNodo * tipoNodoRef;            // Puntero a un nodo
typedef tipoNodo * ListaEnlazada;          // Puntero entrada a una Lista Enlazada
typedef ListaEnlazada * ListaEnlazadaRef;  // Puntero al puntero de entrada a una Lista Enlazada

#endif

