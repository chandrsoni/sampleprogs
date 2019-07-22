#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int t,a,b,c;
	scanf("%d",&t);
	for (int j = 0; j < t; ++j)
	{
		std::vector<int> v;
		scanf("%d %d %d",&a,&b,&c);
		v.push_back(a);
		v.push_back(b);
		if(c> a && c> b){printf("NO\n");continue;}
		bool new_val_add = true;
		bool found = false;
		while(new_val_add)
		{
			if(std::find(v.begin(), v.end(), c) != v.end()){
				printf("YES\n");
				found = true;
				break;
			}
			new_val_add = false;
			for (int i = 0; i < v.size(); ++i)
			{
				for (int k = i+1; k < v.size(); ++k)
				{
					if(std::find(v.begin(), v.end(), abs(v[k]-v[i])) == v.end()){
						v.push_back(abs(v[k]-v[i]));
						new_val_add = true;
					}
				}
			}	
		}
		if(!found)printf("NO\n");
	}
	// take diff
	// add diff to possible values

    return 0;
}
