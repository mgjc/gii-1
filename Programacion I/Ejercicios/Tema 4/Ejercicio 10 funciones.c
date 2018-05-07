//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int a, temp;

int UnoAQuince (temp){
	
	switch(temp){
	
	case 1: printf("uno\n"); break;
	case 2: printf("dos\n"); break;
	case 3: printf("tres\n"); break;
	case 4: printf("cuatro\n"); break;
	case 5: printf("cinco\n"); break;
	case 6: printf("s\202is\n"); break;
	case 7: printf("siete\n"); break;
	case 8: printf("ocho\n"); break;
	case 9: printf("nueve\n"); break;
	case 10: printf("diez\n"); break;
	case 11: printf("once\n"); break;
	case 12: printf("doce\n"); break;
	case 13: printf("trece\n"); break;
	case 14: printf("catorce\n"); break;
	case 15: printf("quince\n"); break;
	}
	
	return 0;
};

int DieciseisADiecinueve(temp){

	printf("dieci");
	switch(temp){
		
	case 6: printf("s\202is\n"); break;
	case 7: printf("siete\n"); break;
	case 8: printf("ocho\n"); break;
	case 9: printf("nueve\n"); break;
	}
	
	return 0;
};

int VeinteATreinta(temp){
	
	printf("veint");
	switch(temp){
		
	case 0: printf("e\n"); break;
	case 1: printf("iuno\n"); break;
	case 2: printf("id\242s\n"); break;
	case 3: printf("itr\202s\n"); break;
	case 4: printf("icuatro\n"); break;
	case 5: printf("icinco\n"); break;
	case 6: printf("is\202is\n"); break;
	case 7: printf("isiete\n"); break;
	case 8: printf("iocho\n"); break;
	case 9: printf("inueve\n"); break;
	}
	
	return 0;
};

int TreintaACien(temp){
	
	switch(temp){
		
	case 3: printf("treinta"); break;
	case 4: printf("cuarenta"); break;
	case 5: printf("cincuenta"); break;
	case 6: printf("sesenta"); break;
	case 7: printf("setenta"); break;
	case 8: printf("ochenta"); break;
	case 9: printf("noventa"); break;
	}
	
	return 0;	
};

int CienAMil(temp){
	
	switch(temp){
		
	case 1: printf("cien"); break;
	case 2: printf("doscientos "); break;
	case 3: printf("trescientos "); break;
	case 4: printf("cuatrocientos "); break;
	case 5: printf("quinientos "); break;
	case 6: printf("seiscientos "); break;
	case 7: printf("setecientos "); break;
	case 8: printf("ochocientos "); break;
	case 9: printf("novecientos "); break;
				
	}
	
	return 0;
};

int main (void){
	
	scanf("%d",&a);
	
	if(a<=15){
			
	temp=a%20;
	UnoAQuince(temp);
	}
	else{
		if((a<20)){
				
		temp=a%10;
		DieciseisADiecinueve(temp);
		}
		else{
			if(a<30){
				temp=a%10;
				VeinteATreinta(temp);
			}
			else{
				if(a<=99){
					temp=a/10;
					TreintaACien(temp);
					
					if((a%10)!=0){
						printf(" y ");
						temp=a%10;
						UnoAQuince(temp);
					}
				}
				else{
					if(a<=999){
						temp=a/100;
						CienAMil(temp);
						
						if(!(a==100)&&(a<200)){
							printf("to ");
						}
						
						if((a%100)<10){
							temp=a%10;
							UnoAQuince(temp);
						}
						else{
							if((a%100)<=15){
								temp=a%20;
								UnoAQuince(temp);
							}
							else{
								if((a%100)<20){
									temp=a%10;
									DieciseisADiecinueve(temp);
								}
								else{
									if((a%100)<30){
										temp=a%10;
										VeinteATreinta(temp);
									}
									else{
										temp=a%100;
										temp/=10;
										TreintaACien(temp);
										if((a%10)!=0){
												printf(" y ");
												temp=a%10;
												UnoAQuince(temp);
										}
									}
								}
							}
						}
					}
				}
			}
			
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
