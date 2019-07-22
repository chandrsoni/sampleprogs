#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d %d",&a,&b);
	c = a-b;
	if(c%10 == 9)printf("%d",c-1);
	else printf("%d",c+1 );
}