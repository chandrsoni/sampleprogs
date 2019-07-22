#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


bool checkPrime(long int n,long int v,long int sq){
	if(sq<v)return true;
	if(n%v==0||n%(v+2)==0)return false;
	return checkPrime(n,v+6,sq);
}

bool isPrime(long int n){
	if(n<2)return false;
	if(n==2||n==3||n==5)return true;
	if(n%2==0)return false;
	long int sq=(long int)(sqrt((long int)(n)));
	return checkPrime(n,5,sq);
}

bool checkFactorCount(long int n){
	long int sq=(long int)(sqrt((long int)(n)));
	long int count=0;
	for(long int i=1;i<sq;i++){
		if(n%i==0)count++;
	}
	return isPrime(2*count+1);
}

bool checkPrimeNFactor(long int value){
	if(value<2)return false;
	long int sq=(long int)(sqrt((long int)(value)));
	if(sq*sq!=value){
		return isPrime(value);
	}
	else{
		checkFactorCount(value);
	}
}

long int getKissCount(long int low,long int hi){
	long int count=0;
	for(long int i=low;i<=hi;i++){
		if(checkPrimeNFactor(i)){count++;}
	}
	return count;
}

int main(){
	long int n;
	long int low,hi;
	scanf("%ld",&n);
	while(n--){
		scanf("%ld %ld",&low,&hi);
		printf("%ld\n",getKissCount(low,hi));
	}
}
