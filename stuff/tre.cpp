#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

class ice_cream{
public:
	int index;
	float cost;
	ice_cream(){
		index = -1;
		cost = -1;
	}
	ice_cream(int i, float c){
		index = i;
		cost = c;
	}

};

bool operator<(ice_cream a,ice_cream i){
	return a.cost < i.cost;
}

int main() {
	int t,m,n;
	float cost;
	scanf("%d",&t);
	for (int j = 0; j < t; ++j)
	{
		std::vector<ice_cream> v;
		scanf("%d %d",&m,&n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%f",&cost);
			ice_cream ice(i,cost);
			v.push_back(ice);
		}
		sort(v.begin(),v.end());
		bool found = false;
		for (int i = 0; i < (v.size()+1)/2; ++i)
		{
			for (int j = i+1; j < v.size(); ++j)
			{
				if(v[i].cost + v[j].cost == m){
					if(v[i].index < v[j].index)	printf("%d %d\n",v[i].index +1,v[j].index+1);
					else printf("%d %d\n",v[j].index +1,v[i].index+1);
					found = true;
					break;
				}
				if(found)break;
			}
		}
	}
	// sort
	// binary search
    return 0;
}
