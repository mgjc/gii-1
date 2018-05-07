//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include "cadenas2.h"
#define TAM 1000

int main(void){
	char cadena[TAM],caract;
	int i,tamano,ano;
	gets(cadena);
	tamano=strlen(cadena);
	printf("tamano: %d\n",tamano);
	for(i=0;i<tamano;i++)
		cadenaminus(cadena+i);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	puts("");
	for(i=0;i<tamano;i++)
		eliminaespacios(cadena+i);
	tamano=strlen(cadena);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	puts("\nEscribe un caracter que quieras eliminar de tu cadena");
	scanf("%c",&caract);
	for(i=0;i<tamano;i++)
		eliminacaracter(cadena+i,caract);
	tamano=strlen(cadena);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	recortarder(cadena);
	tamano=strlen(cadena);
	printf("\ntamano: %d\n",tamano);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	recortar(cadena);
	tamano=strlen(cadena);
	printf("\ntamano: %d\n",tamano);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	puts("Escribe un a\244o para convertirlo a numeros romanos");
	scanf("%d",&ano);
	romano(cadena,ano);
	tamano=strlen(cadena);
	printf("\ntamano: %d\n",tamano);
	for(i=0;i<tamano;i++)
		printf("%c",*(cadena+i));
	puts("");
	system("pause");
	return 0;
}
