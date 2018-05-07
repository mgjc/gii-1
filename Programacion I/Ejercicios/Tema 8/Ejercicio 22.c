//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100
float media (int *,int);

int main(void){
	int vect[TAM],result,num,i;
	do{
		puts("Escribe cuantos elementos vas a usar:");
		scanf("%d",&num);
	}while(num<0||num>TAM);
	for(i=0;i<num;i++){
		printf("Escribe el elemento %d:\n",i+1);
		scanf("%d",&vect[i]);
	}
	result=media(vect,num);
	printf("La media aritm\240tica del vector es: %d\n",result);
	system("pause");
	return 0;
}

float media(int *la,int x){
	float result;
	int sum=0,i;
	
	for(i=0;i<x;i++){
		sum+=*(la+i);
	}
	result=(float)sum/x;
	return result;
}
