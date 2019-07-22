#include <iostream>
#include <stdio.h>
#define MAX 10000000
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int segCount;
		int answer=0;
		int count=0;
		int input;
		scanf("%d",&segCount);
		while(segCount--){
			scanf("%d",&input);
			if(input+count>answer){answer=input+count;}
			count++;
		}
		printf("%d\n",answer);
	}
}
