//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int a1, a2, i, suma=0;

int main (void){
    
    printf("Escribe dos n\243meros:\n");
    scanf("%d%d", &a1,&a2);
    
    if(a1>a2){
       
       for(i=a2;i<a1;i++){
             
             if(i%2==0){
                
                suma += i;         
                
             }          
       }  
       
       printf("La suma de los n\243meros pares comprendidos entre %d y %d es: %d\n", a2,a1,suma);
           
    }
 
    system("pause");
    return 0;
}
