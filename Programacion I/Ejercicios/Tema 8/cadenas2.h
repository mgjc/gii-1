#include <string.h>
char may=164,min=165;
void cadenaminus (char *cad);
void eliminaespacios (char *cad);
void eliminacaracter(char *cad, char c);
void recortarder(char *cad);
void recortar(char *cad);
void replicaespacios(char *cad);
void romano(char *cad, int annio);
void cadenaminus (char *cad){
	if(*cad>64&&*cad<90||*cad==164){
		if(*cad ==may){
   	 		*cad = min;
		}else{
			*cad=*cad+32;
   	  	}
   	}
}
void eliminaespacios (char *cad){
	int i;
	if(*cad==32){
		for(i=0;*(cad+i)!='\0';i++)
			*(cad+i)=*(cad+i+1);
	}
}
void eliminacaracter(char *cad, char c){
	int i;
	if(*cad==c){
		for(i=0;*(cad+i)!='\0';i++)
			*(cad+i)=*(cad+i+1);
	}
}
void recortarder(char *cad){
	long tam;
	tam=strlen(cad);
	while(*(cad+tam-1)==32){
		*(cad+tam-1)='\0';
		tam=strlen(cad);
	}
}
void recortar(char *cad){
	int k;
	long tam;
	while (*cad==32){
		k=0;
    	while (*(cad+k)!='\0'){
			*(cad+k)=*(cad+k+1);
        	k++;
        }
	}
	tam=strlen(cad);
	while(*(cad+tam-1)==32){
		*(cad+tam-1)='\0';
		tam=strlen(cad);
	}
}
void replicaespacios(char *cad){
	int k;
	long tam;
	tam=strlen(cad);
	for(k=0;k<tam;k++)
		*(cad+k)=32;
}
void romano(char *cad, int annio){
	int temp;
	if(annio<1||annio>3000)strcat(cad,' -');
	else{
		switch()
	}
//	
//	No se implementar esta función de manera correcta
//	Sé como se usa strcat y como usarlo, pero no sé el algoritmo a seguir
//	
}
