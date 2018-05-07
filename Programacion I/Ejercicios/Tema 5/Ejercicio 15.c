//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
	int num1, num2, num3, num4, num5, i; char result [30] = {0}; double nota, media, suma, porc;
	suma=i=media=num1=num2=num3=num4=num5=0;
	do{
		puts("Escribe una nota:"); scanf("%lf",&nota);
		if(nota<0){break;}else{if(nota>10)continue;}
		i++; suma+=nota;
		switch((int)nota){
			case 0:
			case 1:
				num1++;
				break;
			case 2:
			case 3:
			case 4:
				num2++;
				break;
			case 5:
			case 6:
				num3++;
				break;
			case 7:
			case 8:
				num4++;
				break;
			case 9:
			case 10:
				num5++;
				break;
		}
	}while(nota>=0);
	media=(suma/i);
	switch((int)media){
		case 0:
		case 1:
			strcat(result,"Muy deficiente");
			break;
		case 2:
		case 3:
		case 4:
			strcat(result,"Suspenso");
			break;
		case 5:
		case 6:
			strcat(result,"Aprobado");
			break;
		case 7:
		case 8:
			strcat(result,"Notable");
			break;
		case 9:
		case 10:
			strcat(result,"Sobresaliente");
			break;
		}
	printf("Total alumnos presentados a examen..: %d",i);puts("");porc=((double)num5/i)*100;
	printf("Numero de sobresalientes............: %d (%.2lf%%)",num5,porc);puts("");porc=((double)num4/i)*100;
	printf("Numero de notables..................: %d (%.2lf%%)",num4,porc);puts("");porc=((double)num3/i)*100;
	printf("Numero de aprobados.................: %d (%.2lf%%)",num3,porc);puts("");porc=((double)num2/i)*100;
	printf("Numero de suspensos.................: %d (%.2lf%%)",num2,porc);puts("");porc=((double)num1/i)*100;
	printf("Numero de muy deficientes...........: %d (%.2lf%%)",num1,porc);puts("");
	printf("Nota media..........................: %.2lf (%s)",media,result);puts("");
	
	system("pause");
	return 0;
}
