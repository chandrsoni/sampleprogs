#include <iostream>
#include <stdio.h>
using namespace std;

long long int factorial(int n){
	if (n <= 2)return n;
	return n*factorial(n-1);
}

int main(){
	cout<<"get factorial of ";
	int n;
	cin>>n;
	cout<<"factorial is "<<factorial(n)<<endl;
}