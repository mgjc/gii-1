//jcmg@usal.es

#include <stdio.h>
#include <stdlib.h>

int main (void){
  int i=1,sum=0,temp=0,j=0;
    while(i<=20){
     printf("%d\t",i);
     i++;
    }
    i=0;
    puts("");
    puts("");
    puts("");
    while(sum<=100){
     printf("%d\t",i);
     i++; 
     sum+=i;           
    }
    puts("");
    puts("");
    puts("");
    while(i!=-1){
     puts("\nEscribe un n\243mero:");
     scanf("%d",&i);
     if(i==-1){
       break;
     }else{
       if(i>=0){    
       printf("%d\n",i);
       }
     }
    }
    i=0;
    puts("");
    puts("");
    puts("");
    while(i>=temp){
     j++;
     puts("Escribe un n\243mero:");
     scanf("%d",&i);
     if(i<temp){
      if(j==1){
        temp=i;
      }else{
            break;
      }
     }else{
      temp=i;
     }
                  
    }
 puts("");
 puts("");
 
    system("pause");
    return 0;
}
