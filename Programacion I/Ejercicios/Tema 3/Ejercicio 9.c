//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int h1,h2,m1,m2,s1,s2,h3,m3,s3;
	printf("Introduce las horas, minutos y segundos del primer corredor:\n");
	scanf("%d",&h1);scanf("%d",&m1);scanf("%d",&s1);
	printf("Introduce las horas, minutos y segundos del segundo corredor:\n");
	scanf("%d",&h2);scanf("%d",&m2);scanf("%d",&s2);
	
	if(s1<s2){
		s1+=60;
		s3=s1-s2;
		m2++;
	}else{
		s3=s1-s2;
	}
	
	if(m1<m2){
		m1+=60;
		m3=m1-m2;
		h2++;
	}else{
		m3=m1-m2;
	}
	
	h3=h1-h2;
	
	printf("\nLa distancia entre corredores es de:\n%dhoras, %dminutos, %dsegundos.\n",h3,m3,s3);
		
	system("pause");
	return 0;
}
