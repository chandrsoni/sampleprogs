#include <iostream>
#include <stdio.h>
using namespace std;


int main(){
	// input
	printf("input as x,degree followed by index firstly for high order\n");
	int x,n;
	scanf("%d",&x);
	scanf("%d",&n);
	int coeff,i=0;
	long long int y=0;
	while(i<=n){
		scanf("%d",&coeff);
		y=y*x+ coeff;
		i++;
	}
	printf("%lld\n",y);
	
	return 0;
}
