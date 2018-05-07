//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int main (void){
	int vect[TAM];
	int i,temp,temp1, num, diffmax, diff;

	do{
		printf("Escribe el n\243mero m\240ximo de elementos, como m\240ximo ser\240n %d:\n",TAM);
		scanf("%d",&num);
	}while(num<0||num>TAM);
	
	for(i=0;i<num;i++){
		puts("Escribe un elemento");
		scanf("%d",&vect[i]);
		if(i==0) continue;
		if(vect[i]<=vect[i-1]){
			printf("%d es menor que %d\n", vect[i],vect[i-1]);
			return 1;
		}
	}
	diffmax=vect[1]-vect[0];
	for(i=0;i<num;i++){
		printf("%d ",vect[i]);
	}
	for(i=0;i<num-1;i++){
		diff=vect[i+1]-vect[i];
		if(diff>diffmax){
			diffmax=diff;
			temp=vect[i];
			temp1=vect[i+1];
		}
	}
    printf("\nLa m\240xima diferencia es de: %d que est\240 entre %d y %d",diffmax,temp,temp1);
    
	puts("");
	system("pause");
	return 0;     
}
