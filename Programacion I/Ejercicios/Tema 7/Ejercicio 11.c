//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 120

int main (void){
    
    char mensaje[TAM+1],caract,*vector[TAM+1];
    int lon,veces=0,i;
    puts("Introduce una cadena de texto inferior a 120 caracteres");
    fgets(mensaje,TAM,stdin);
    fflush(stdin);
    puts("Que caracter quieres buscar en tu cadena?");
    scanf("%c",&caract);
    fflush(stdin);
    lon=strlen(mensaje)-1;
    printf("Longitud de tu cadena: %d\n",lon);
    for(i=0;i<=lon;i++){
      if(*(mensaje+i)==caract){
      veces++;
      vector[veces]=(mensaje+i);
      }
    }
    printf("Veces que se encuentra tu caracter en tu cadena: %d\n",veces);
    for(i=0;i<veces;i++){
    	printf("%p\n",vector+i);
	}
	puts("");
    
    
 system("pause");
 return 0;   
}
