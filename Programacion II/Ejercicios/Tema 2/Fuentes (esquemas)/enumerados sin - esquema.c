#include <stdio.h>
#include <stdlib.h>


int main (void) {

   char c_tecleado;
   int  c_tipo;

   puts("Teclee un caracter y el programa le indicará su tipo");
   printf("Caracter => : ");

   fflush(stdin); /* Limpia el buffer de teclado */
   c_tecleado = getchar();

   if (c_tecleado == '=')
       c_tipo = 1; // SIGNO IGUAL
   else
       if (c_tecleado == '*' || c_tecleado == '/' ||
           c_tecleado == '+' || c_tecleado == '-')
           c_tipo = 2; // OPER. ARITMETICOS
       else
           if (c_tecleado == '>' || c_tecleado == '<')
               c_tipo = 3; // OPER. RELACIONAL
           else
               if ( (c_tecleado >= 'A' && c_tecleado <= 'Z') ||
                    (c_tecleado == 'Ñ') )
                     c_tipo = 4; // LETRA MAYUSCULA
               else
                   if ( (c_tecleado >= 'a' && c_tecleado <= 'z') ||
                        (c_tecleado == 'ñ') )
                         c_tipo = 5; // LETRA MINUSCULA
                   else
                       if (c_tecleado >= '0' && c_tecleado <= '9')
                           c_tipo = 6; // DIGITO
                       else
                           if (c_tecleado >= 0 && c_tecleado <= 31)
                               c_tipo = 7; // CARACTER DE CONTROL
                           else
                               c_tipo = 8; // SIMBOLO


   printf("El caracter tecleado es ");
   switch (c_tipo) {
      case 1 : printf ("un signo de igual.      \n"); break;
      case 2 : printf ("un operador aritmético. \n"); break;
      case 3 : printf ("un operador relacional. \n"); break;
      case 4 : printf ("una letra en mayúscula. \n"); break;
      case 5 : printf ("una letra en minúscula. \n"); break;
      case 6 : printf ("un dígito.              \n"); break;
      case 7 : printf ("un carácter de control. \n"); break;
      case 8 : printf ("un símbolo del teclado. \n");
   }

  printf("\n");
  system("pause");
  return 0;
}
