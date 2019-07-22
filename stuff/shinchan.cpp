#include <iostream>
#include <stdio.h>
using namespace std;

subsetSum(int *val,int n,int sum){
	int i;
	for(i=0;i<n;i++){
		if(val[i]>sum)break;
	}
	T[i]
}

void playOneGame(){
	// for a single game
	int n;
	scanf("%d",&n);
	int value[n];
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&value[i]);
		sum+=value[i];
	}
	if(sum%2==1)printf("NO\n");
	else{
		sort(value,value+n);
		if(value[n]>sum)printf("NO\n");
		subsetSum(values,sum-values[n]);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	while(n!=0){
		// For n test cases
		playOneGame();
		n--;
	}
}
