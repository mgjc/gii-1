#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main (void){
	char a; int b;
	scanf("%c",&a);
	scanf("%d",&b);
	printf("%c",toupper(a));
	printf("abs: %d",abs(b));
	system("pause");
	return 0;
}
