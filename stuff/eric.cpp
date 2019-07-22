#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define ll long long

class factor{
public:

};

int main(){
	ll n;
	scanf("%lld",n);
	vector<int> v;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.count; ++i)
	{
		for(int j=i;j< v.count;j++){
			
		}
	}
}