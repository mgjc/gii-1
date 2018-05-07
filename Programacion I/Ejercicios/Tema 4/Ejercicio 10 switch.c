//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int num, temp;
	scanf("%d",&num);
	temp=num/100;
	switch(temp){
		case 0:
			temp=num;
			break;
		case 1:
			printf("ciento ");
			temp=num-temp*100;
			break;
		case 2:
			printf("doscientos ");
			temp=num-temp*100;
			break;
		case 3:
			printf("trescientos ");
			temp=num-temp*100;
			break;
		case 4:
			printf("cuatrocientos ");
			temp=num-temp*100;
			break;
		case 5:
			printf("quinientos ");
			temp=num-temp*100;
			break;
		case 6:
			printf("seiscientos ");
			temp=num-temp*100;
			break;
		case 7:
			printf("setecientos ");
			temp=num-temp*100;
			break;
		case 8:
			printf("ochocientos ");
			temp=num-temp*100;
			break;
		case 9:
			printf("novecientos ");
			temp=num-temp*100;
			break;
	}
	temp/=10;
	switch(temp){
		case 9:
			printf("noventa ");
			break;
		case 8:
			printf("ochenta ");
			break;
		case 7:
			printf("setenta ");
			break;
		case 6:
			printf("sesenta ");
			break;
		case 5:
			printf("cincuenta ");
			break;
		case 4:
			printf("cuarenta ");
			break;
		case 3:
			printf("treinta ");
			break;
		case 2:
			printf("veint");
			
			switch(num%10){
				case 0:
					printf("e");
					break;
				case 1:
					printf("iuno");
					break;
				case 2:
					printf("idos");
					break;
				case 3:
					printf("itres");
					break;
				case 4:
					printf("icuatro");
					break;
				case 5:
					printf("icinco");
					break;
				case 6:
					printf("is\202is");
					break;
				case 7:
					printf("isiete");
					break;
				case 8:
					printf("iocho");
					break;
				case 9:
					printf("inueve");
					break;
			}
			
			break;
		case 1:
			if((num%10)>5){
			printf("dieci");
			switch(temp%10){
				case 9:
					printf("nueve");
					break;
				case 8:
					printf("ocho");
					break;
				case 7:
					printf("siete");
					break;
				case 6:
					printf("s\202is");
					break;
			}
			}else{
				switch(num%10){
					case 5:
						printf("quince");
						break;
					case 4:
						printf("catorce");
						break;
					case 3:
						printf("trece");
						break;
					case 2:
						printf("doce");
						break;
					case 1:
						printf("once");
						break;
					case 0:
						printf("diez");
						break;
				}
			}
			break;
	}
	
	if((num/10)>2){
		printf("y ");
		
		switch(num%10){
			case 1:
				printf("uno");
				break;
			case 2:
				printf("dos");
				break;
			case 3:
				printf("tres");
				break;
			case 4:
				printf("cuatro");
				break;
			case 5:
				printf("cinco");
				break;
			case 6:
				printf("s\202is");
				break;
			case 7:
				printf("siete");
				break;
			case 8:
				printf("ocho");
				break;
			case 9:
				printf("nueve");
				break;		
		}
	}
	
	printf("\n");
	
	system("pause");
	return 0;
}
