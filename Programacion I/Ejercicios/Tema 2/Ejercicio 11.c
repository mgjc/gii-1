//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int x, y, temp;

int main (void){
    
    printf("Escribe dos n\243meros:\n");
    scanf("%d", &x);
    scanf("%d", &y);
    
    printf("\nX es igual a %d e Y es igual a %d", x, y);
    
    temp=x;
    x=y;
    y=temp;
    
    printf("\nX es igual a %d e Y es igual a %d\n", x, y);
        
    system("pause");
    return 0;   
}
