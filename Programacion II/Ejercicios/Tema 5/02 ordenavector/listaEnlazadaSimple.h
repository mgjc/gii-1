//
//  listaEnlazadaSimple.h
//  Prototipo de las FUNCIONES GENERICAS o COMUNES para manejo
//  de listas enlazadas.
//  Son genéricas o comunes porque son válidas para todo tipo de listas,
//  independientemente de los miembros dato definidos para el nodo.
//

#ifndef LISTA_ENLAZADA_SIMPLE_H
#define LISTA_ENLAZADA_SIMPLE_H

tipoNodoRef creaNodo(tipoInfoRef info);

int crearVacia     (ListaEnlazadaRef pt_raiz);
int estaVacia      (ListaEnlazada raiz);

int insertarAntesDeNodo   (ListaEnlazadaRef pt_raiz, tipoNodoRef pos, tipoInfoRef info);
int insertarDespuesDeNodo (ListaEnlazadaRef pt_raiz, tipoNodoRef pos, tipoInfoRef info);
int insertarNodoComienzo  (ListaEnlazadaRef pt_raiz, tipoInfoRef info); 
int insertarNodoFinal     (ListaEnlazadaRef pt_raiz, tipoInfoRef info);

int eliminarNodo               (ListaEnlazadaRef pt_raiz, tipoNodoRef pos);
int eliminarNodoComienzo       (ListaEnlazadaRef pt_raiz);
int eliminarNodoFinal          (ListaEnlazadaRef pt_raiz);
int eliminarNodoFinalEficiente (ListaEnlazadaRef pt_raiz);

int liberarListaEnlazada          (ListaEnlazadaRef pt_raiz);

#endif
