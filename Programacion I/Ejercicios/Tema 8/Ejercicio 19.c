//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
int mcd(int,int);
int mcm(int,int,int);

int main(void){
	
	int x,y,result;
	do{
		puts("Escribe el primer n\243mero:");
		scanf("%d",&x);
	}while(x<0);
	do{
		puts("Escribe el segundo n\243mero:");
		scanf("%d",&y);
	}while(y<0);
	
	result=mcd(x,y);
	printf("MCD: %d\n",result);
	result=mcm(x,y,result);
	printf("MCM: %d\n",result);
	system("pause");
	return 0;
}

int mcd(x,y){
	int result,z=1;
	if(x>y){
		while(z!=0){
			z=x%y;
			if(z!=0){
				x=y;
				y=z;
			}
		}
		return y;
	}else{
		while(z!=0){
			z=y%x;
			if(z!=0){
				y=x;
				x=z;
			}
		}
		return x;
	}
}

int mcm(x,y,r){
	int res;
	res=(x*y)/r;
	return res;
}
