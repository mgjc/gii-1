//jcmg@usal.es


#include <stdio.h>
#include <stdlib.h>

const char barras[]="====================================",titulo []="	CONVERSION DE DIVISAS",Z []="0) Introducir valores cotizaci\242n divisas";
const char A []="A) Convertir euros a d\242lares y libras",B []="B) Convertir d\242lares a euros y libras",C []="C) Convertir libras a d\242lares y euros",S[]="S) Salir";
double libra, euro, dolar, temp1=0, temp2=0;
char a;
int x=1;
int main (void){

  while(x){
  	
	system("cls");
	
    puts(barras);puts(titulo);puts(barras); puts(Z); puts(A); puts(B); puts(C);puts(S); puts("");
    fflush(stdin);
    scanf("%c",&a);
    
	if((a!='0')&&(temp1==0||temp2==0)){
		puts("Tienes que introducir el valor de cotizaci\242n de divisas");
		system("pause");
		continue;
	}
	
	if(a=='0'){
		printf("Introduzca cuantas libras son 1 euro: "); scanf("%lf",&temp1);
    	printf("Introduzca cuantos d\242lares son 1 euro: "); scanf("%lf",&temp2);
      	
		continue;
	}else{
	
	 switch (a){
    	
      case 'a':
	  case 'A':   
	         
		printf("\nIntroduzca importe en euros a convertir:\n");        
    	scanf("%lf",&euro);
        libra=temp1*euro;
        dolar=temp2*euro;
		printf("%.4lf euros\n%.4lf libras (1 Euro = %.4lf)\n%.4lf d\242lares (1 Euro = %.4lf)\n",euro,libra,temp1,dolar,temp2);
        system("pause");
		break;
		
      case 'b':
	  case 'B':
      
        printf("\nIntroduzca importe en d\242lares a convertir:\n");        
		scanf("%lf",&dolar);
		euro=dolar/temp2;
		libra=temp1*euro;
		printf("%.4lf d\242lares\n%.4lf euros (1 D\242lar = %.4lf)\n%.4lf libras (1 D\242lar = %.4lf)\n",dolar,euro,(1.0/temp2),libra,(temp1/temp2));
		system("pause");
		break;
		
	  case 'c':
	  case 'C':
	               
		printf("\nIntroduzca importe en libras a convertir:\n");        
		scanf("%lf",&libra);
		euro=libra/temp1;
		dolar=euro*temp2;
		printf("%.4lf libras\n%.4lf euros (1 Libra = %.4lf)\n%.4lf d\242lares (1 Libra = %.4lf)\n",libra,euro,(1.0/temp1),dolar,(temp2/temp1));
		system("pause");
		break;
		
	  case 's':
	  case 'S':
	  	
		x=0;
		system("pause");
		break;
				
	  default:
	
		puts("Opci\242n incorrecta");
		system("pause");
		break;
	 }
	}
  }
    
    return 0;
}
