//jcmg@usal.es

#include <math.h>
#include <time.h>
#define PI 3.141592
int numeroaleatorio(int,int);
double radianes(double);
int primo(long);
int numeroaleatorio(int num1,int num2){
	int z,ramd,temp;
	temp=abs(num2-num1);
	srand(time(NULL));
	ramd=rand()%temp;
	z=ramd+num1;
	return z;
}
double radianes(double ang){
	double z,temp;
	temp=PI*2; temp/=360;
	z=temp*ang;
	return z;
}
int primo(long num){
	int i,temp=1;
	if (num==1||num==2) return 1;
	if((num%2)==0)return 0;
	for(i=3;i<num;i++){
		if((num%i)==0){
		temp=0;
		break;
		}
	}
	if(temp)return 1;
	else{
		return 0;
	}
}
