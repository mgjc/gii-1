//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define MAX 7000
#define MIN 1000
#define TAM 15

int peticion(int temp); //Prototipo de la función peticion
//Declaraciones
int claves[TAM], *clav[TAM],i,test,temp,*temp2,temp1;

int main (void){
//	Petición de datos hasta que se llene el vector claves comprobando que no se introduce un elemento ya almacenado en el propio vector claves
	for(i=0;i<TAM;i++){
		test=0;
		claves[i]=peticion(temp);
			for(temp1=0;temp1<i;temp1++){
				if(claves[i]==claves[temp1]){
					test=1;
					break;
				}
			}
			if(test==1){
				puts("La clave ya ha sido introducida antes");
				i--;
			}
	}
//	Inicialización de los punteros del vector clav
	for(i=0;i<TAM;i++){
		clav[i]= &claves[i];		
	}
//	Colocación en orden de los elementos del vector claves en el vector clav
	temp1=0;
	do{
		for(i=0;i<TAM-1;i++){
			if(*clav[i]>*clav[i+1]){
				temp2=clav[i+1];
				clav[i+1]=clav[i];
				clav[i]=temp2;
			}
		}
		temp1++;
	}while(temp1<TAM);
//	Muestra el vector clav
	puts("Las claves ordenadas:");
	for(i=0;i<TAM;i++){
		printf("%d  ",*clav[i]);
	}
	puts("");
//	Muestra el vector claves
	puts("Las claves en orden de introducci\242n:");
	for(i=0;i<TAM;i++){
		printf("%d  ",claves[i]);
	}
	puts("");
	system("pause");
	return 0;
}
//	Función que pide un número entre un MIN y un MAX
int peticion(int temp){
	do{
		puts("Introduce una clave:");
		scanf("%d",&temp);
		if(temp<MIN||temp>MAX){
			printf("El n\243mero debe estar dentro del rango %d-%d\n",MIN,MAX);
		}
		
	}while(temp<MIN||temp>MAX);
}
