#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaEnlazadaSimple.h"

int crearVacia(ListaEnlazadaRef raiz){
	*raiz=NULL;
	return 0;
}

int estaVacia(ListaEnlazada raiz){
	return (raiz ==NULL);
}

tipoNodoRef creaNodo(tipoInfoRef info){

	tipoNodoRef x;
	if((x=malloc(sizeof(tipoNodo)))==NULL) exit (-1);

	x->info=*info;
	x->sig=NULL;

	return x;
}

int insertarDespuesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info){

	tipoNodoRef x, y;

	if((x=creaNodo(info))==NULL) exit (-1);
	if(estaVacia(*raiz)) *raiz=x;
	else{
		if (pos ==NULL){
			y=*raiz;
			while(y->sig!=NULL)
				y=y->sig;
			y->sig=x;
		}else{
			y->sig=pos->sig;
			pos->sig=x;
		}
	}
	return 0;
}

int insertarAntesDeNodo(ListaEnlazadaRef raiz, tipoNodoRef pos, tipoInfoRef info){

	tipoNodoRef x,anterior;

	if((x=creaNodo(info))==NULL) exit(-1);
	if(estaVacia(*raiz) || pos ==NULL || pos==*raiz){
		x->sig=*raiz;
		*raiz=x;
	}else{
		anterior=*raiz;
		while(anterior->sig!=pos)
			anterior=anterior->sig;
		x->sig=pos;
		anterior->sig=x;
	}
	return 0;
}

int insertarNodoComienzo(ListaEnlazadaRef raiz, tipoInfoRef info){

	return insertarAntesDeNodo(raiz,*raiz,info);
}

int insertarNodoFinal(ListaEnlazadaRef raiz, tipoInfoRef info){

	return insertarDespuesDeNodo(raiz,NULL,info);
}

int insertarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice, tipoInfoRef info){

	int i=0;
	tipoNodoRef x;
	x=*raiz;

	if(indice<0) return -1;
	if(indice==0) return insertarAntesDeNodo(raiz,x,info);
	if(estaVacia(*raiz))	return -1;

	while(x->sig!=NULL && ++i <indice)
		x=x->sig;
	if(i==indice|| i+1 ==indice)
		return insertarDespuesDeNodo(raiz,x,info);

	return -1;
}

int eliminarNodo(ListaEnlazadaRef raiz, tipoNodoRef pos){

	tipoNodoRef x;

	if(estaVacia(*raiz)) return -1;
	if(pos==NULL) return -1;
	if(pos==*raiz){
		*raiz=(*raiz)->sig;
		free(pos);
		return 0;
	}

	x=*raiz;

	while(x!=NULL && x->sig !=pos)
		x=x->sig;

	if(x!=NULL){
		x->sig=pos->sig;
		free(pos);
	}

	return -1;
}

int eliminarNodoComienzo(ListaEnlazadaRef raiz){

	return eliminarNodo(raiz,*raiz);
}

int eliminarNodoFinal(ListaEnlazadaRef raiz){

	tipoNodoRef aborrar;

	if(estaVacia(*raiz)) return -1;
	aborrar=*raiz;
	
	while(aborrar->sig!=NULL)
		aborrar=aborrar->sig;

	return eliminarNodo(raiz,aborrar);
}

int eliminarNodoPosicionIndice(ListaEnlazadaRef raiz, int indice){

	int i=0;
	tipoNodoRef x;
	x=*raiz;
	if(indice<0) return -1;
	if(estaVacia(*raiz)) return -1;

	while(x!=NULL && i++ <indice)
		x=x->sig;

	if(x!=NULL) return eliminarNodo(raiz,x);

	return -1;
}

int liberarListaEnlazada(ListaEnlazadaRef raiz){

	tipoNodoRef aborrar, x;

	if(estaVacia(*raiz)) return -1;

	x=*raiz;
	while(x!=NULL){
		aborrar=x;
		x=x->sig;
		free(aborrar);
	}
	*raiz=NULL;

	return 0;
}

tipoInfo devolverInfoPosicionIndice(ListaEnlazada raiz, int indice){

	int i=0;
	tipoNodoRef x;
	x=raiz;

	if(indice<0) return -1;
	if(estaVacia(raiz)) return -1;

	while(x!=NULL && ++i <=indice)
		x=x->sig;
	if(x!=NULL)
		return x->info;

	return -1;
}

int insertarOrdenada(ListaEnlazadaRef raiz, tipoInfoRef info){

	tipoNodoRef x;

	if(estaVacia(*raiz)|| (*raiz)->info > *info)
		return insertarNodoComienzo(raiz,info);

	x=*raiz;

	while(x->sig!=NULL && x->sig->info < *info)
		x=x->sig;

	return insertarDespuesDeNodo(raiz,x,info);
}

int mostrarListaEnlazada(ListaEnlazada raiz){
	tipoNodoRef aImprimir;
	int res = 0,i = 0;
	
	printf("\n\n");
	printf("%-14s%-10s\n","  Posición", "Valor");
	printf("%-14s%-10s\n","  ==========", "======");


	aImprimir = raiz;
	while (aImprimir != NULL) {
		printf("\t%3d)\t%7d\n",i++, aImprimir->info);
		aImprimir = aImprimir->sig;
	}
	return res;
}

int crearListaValoresAleatorios(ListaEnlazadaRef raiz, int numNodos){
	int i;
	tipoInfo temp;
	
	if (estaVacia(*raiz)) {
		srandom(time(NULL));
		for (i = 0; i < numNodos; i++) {
            temp = random()%10000;
            insertarDespuesDeNodo(raiz, NULL, &temp);
            insertarAntesDeNodo(raiz, NULL, &temp);
            insertarNodoFinal(raiz, &temp);
			insertarNodoComienzo(raiz, &temp);
		}
		return 0;
	}
	return -1;
}
