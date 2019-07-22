#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int t,n,cost;
	long long int sum,S;
	long long int P;
	scanf("%d",&t);
	for (int j = 0; j < t; ++j)
	{
		S = 1;
		sum = 0;
		P = 0;
		std::vector<int> v;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&cost);
			sum += cost;
			v.push_back(cost);
		}
		sort(v.begin(),v.end());
		for (int i = 0; i < n; ++i)
		{
			if(sum*S > P)P = sum*S;
			sum -= v[i];
			S++;
		}
		printf("%lld\n",P );

	}
	// sort
	// sum
    return 0;
}
