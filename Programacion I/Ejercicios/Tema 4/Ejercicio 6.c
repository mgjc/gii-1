//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    int total, millar, centenas, decenas, temp;
    char cod[5]="";
    puts("Introduzca el precio");
    scanf("%d",&total);          system("cls");
    
    millar=total/1000; temp=total%1000;
    centenas=temp/100; temp%=100;
    decenas=temp/10;   temp%=10;
    if((total/10000)==0){
     switch(millar){
       case 0:
            strcat(cod, "O");
            break;
       case 1:
            strcat(cod, "G");
            break;
       case 2:
            strcat(cod, "A");
            break;
       case 3:
            strcat(cod, "L");
            break;
       case 4:
            strcat(cod, "E");
            break;
       case 5:
            strcat(cod, "I");
            break;
       case 6:
            strcat(cod, "C");
            break;
       case 7:
            strcat(cod, "R");
            break;
       case 8:
            strcat(cod, "U");
            break;
       case 9:
            strcat(cod, "M");
            break;         
     }
      switch(centenas){
       case 0:
            strcat(cod, "O");
            break;
       case 1:
            strcat(cod, "G");
            break;
       case 2:
            strcat(cod, "A");
            break;
       case 3:
            strcat(cod, "L");
            break;
       case 4:
            strcat(cod, "E");
            break;
       case 5:
            strcat(cod, "I");
            break;
       case 6:
            strcat(cod, "C");
            break;
       case 7:
            strcat(cod, "R");
            break;
       case 8:
            strcat(cod, "U");
            break;
       case 9:
            strcat(cod, "M");
            break;
      }
            switch(decenas){
       case 0:
            strcat(cod, "O");
            break;
       case 1:
            strcat(cod, "G");
            break;
       case 2:
            strcat(cod, "A");
            break;
       case 3:
            strcat(cod, "L");
            break;
       case 4:
            strcat(cod, "E");
            break;
       case 5:
            strcat(cod, "I");
            break;
       case 6:
            strcat(cod, "C");
            break;
       case 7:
            strcat(cod, "R");
            break;
       case 8:
            strcat(cod, "U");
            break;
       case 9:
            strcat(cod, "M");
            break;
      }
      switch(temp){
       case 0:
            strcat(cod, "O");
            break;
       case 1:
            strcat(cod, "G");
            break;
       case 2:
            strcat(cod, "A");
            break;
       case 3:
            strcat(cod, "L");
            break;
       case 4:
            strcat(cod, "E");
            break;
       case 5:
            strcat(cod, "I");
            break;
       case 6:
            strcat(cod, "C");
            break;
       case 7:
            strcat(cod, "R");
            break;
       case 8:
            strcat(cod, "U");
            break;
       case 9:
            strcat(cod, "M");
            break;
     }
    }else{
          puts("No es un n\243mero de 4 cifras");
    }
    puts(cod
    );
 system("pause");
 return 0;   
}
