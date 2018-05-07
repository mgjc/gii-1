//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100
void maxmin(int*,int*,int*,int);

int main(void){
	int max,min,num,i,vect[TAM];
	do{
		puts("Escribe cuantos elementos quieres usar:");
		scanf("%d",&num);
	}while(num<0||num>TAM);
	for(i=0;i<num;i++){
		printf("Introduce el elemento %d\n",i+1);
		scanf("%d",&vect[i]);
	}
	maxmin(vect,&min,&max,num);
	printf("\nEl m\240ximo y el m\241nimo del vector son: %d y %d\n",max,min);
	system("pause");
	return 0;
}
void maxmin(int *vc,int *x,int *y,int z){
	int i;
	for(i=0;i<z;i++){
		if(i==0)*x=*vc;
		if(i==0)*y=*vc;
		if(*x>*(vc+i))*x=*(vc+i);
		if(*y<*(vc+i))*y=*(vc+i);
	}
	
}
