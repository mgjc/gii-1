//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
    int a,*punt=NULL;
    puts("Escribe un valor para la variable \"a\"");
    scanf("%d",&a);
    printf("El valor de la variable \"a\" es: %d\n",a);
    punt=&a;
    printf("El valor de la variable \"a\" usando el puntero es: %d\n",*punt);
    puts("Escribe un valor para el puntero que apunta a la variable \"a\"");
    scanf("%d",punt);
    printf("El valor de la variable \"a\" es: %d\n",a);
    printf("El valor de la variable \"a\" usando el puntero es: %d\n",*punt);
    printf("La direccion del puntero es: %p\n",punt);
    printf("La direccion de la variable \"a\" es : %p\n", &a);
    printf("La direccion de la variable \"a\" usando el puntero es: %p\n",punt);
    
 system("pause");
 return 0;   
}
