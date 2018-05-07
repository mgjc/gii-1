//jcmg@usal.es

#include<stdio.h>
#include<stdlib.h>

char aminusculas(char caract);
char amayusculas(char caract);
char caract,may=164,min=165;

int main (void){
	
	puts("Escribe una letra:");
	caract=getchar();
	fflush(stdin);
	if(caract==may||(caract>='A'&&caract<='Z')){
	caract=aminusculas(caract);
	printf("%c\n",caract);
	}
	else{
		if(caract==min||(caract>='a'&&caract<='z')){
			caract=amayusculas(caract);
			printf("%c\n",caract);
		}else{
			puts("No es un caracter que se pueda poner a mayusculas o a minusculas");
		}
	}
	
	system("pause");
	return 0;
}
char aminusculas(char caract){
	
	  if(caract==may){
    	caract = min;
      }else{
			caract=(caract + 32);
   	  }
   
    return (caract);
}
char amayusculas(char caract){
	
	if(caract == min){
    	caract = may;
      }else{
			caract=(caract - 32);
   	  }
	return (caract);
}
