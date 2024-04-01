#include<stdio.h>
int power(int a,int b,int m){
	if(b==0) return 1;
	return a%m*(power(a,b-1,m))%m;
}

int main(){
int a,b,m;
scanf("%d %d %d",&a,&b,&m);
int c=power(a,b,m);
printf("%d",c);
}