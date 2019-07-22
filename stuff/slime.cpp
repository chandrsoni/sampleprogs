#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

bool start=false;
vector<int> v;

void print_bin(int n,int power){
	if (n<=0)
	{
		return;
	}
	if (n%2 == 1)
	{
		v.push_back(power);
		start = true;
	}
	n=n >> 1;
	power++;
	//printf("%d %d\n",n,power );
	print_bin(n,power);
}

int main(){
	int n;
	scanf("%d",&n);
	print_bin(n,1);
	while(!v.empty())
	{	
		printf("%d ",v.back());
		v.pop_back();
	}
	printf("\n");
}