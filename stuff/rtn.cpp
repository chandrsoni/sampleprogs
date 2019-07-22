#include <iostream>
#include <stdio.h>
using namespace std;

int getCount(int n){
	int count=0;
	while(n!=0){
		if(n%10==4)count++;
		n=n/10;
	}
	return count;
}

int main(){
	int n;
	scanf("%d",&n);
	int in;
	while(n--){
		scanf("%d",&in);
		printf("%d\n",getCount(in));
	}
}
