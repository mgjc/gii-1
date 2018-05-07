//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

int main (void){
	const char bl="";
	char cad[MAX]="",temp1,temp;
	int i;
	
	do{
	puts("Escribe una cadena de texto");
	for(i=0;i<MAX;i++){
		cad[i]=bl;	
	}
	fgets(cad,MAX,stdin);
	fflush(stdin);
	i=0;
	while(cad[i]!='\0'){
		temp=cad[MAX-1-i];
		cad[MAX-1-i]=cad[i];
		cad[i]=temp;
		i++;
	}

	for(i=0;i<MAX;i++){
		printf("%c",cad[i]);
	}
	puts("");
	
	puts("Quieres salir? (s/S)");
	scanf("%c",&temp1); fflush(stdin); temp1=toupper(temp1);
	}while(temp1!='S');
	
	system("pause");
	return 0;
}
