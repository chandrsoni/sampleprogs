#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long

class path{
	public:
	int pathNode[32];
	int otherPathNode[32];
	int length1,length2;
	path(){}
};


path getPath(int start,int end){
	if(start>end){
		int temp = start;
		start = end;
		end = temp;
	}
	path interestedNodes;
	interestedNodes.length1 = 0;
	interestedNodes.length2 = 0;
	while(end>=1){
		interestedNodes.pathNode[interestedNodes.length1] = end;
		interestedNodes.length1++;
		end = end/2;
	}
	while(start >=1){
		interestedNodes.otherPathNode[interestedNodes.length2] = start;
		interestedNodes.length2++;
		start = start/2;
	}
	return interestedNodes;
}

void setVal(int start,int end,ll cost){
	path Path = getPath(start,end);
	for (int i = 0; i < Path.length1; ++i)
	{
		printf("%d\n",Path.pathNode[i] );
	}
	for (int i = 0; i < Path.length2; ++i)
	{
		printf("%d\n",Path.otherPathNode[i] );
	}
}

int main(){

	int n;
	int type;
	int start,end;
	ll cost;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&type);
		switch(type){
			case 1:
				scanf("%d %d %lld",&start,&end,&cost);
				setVal(start,end,cost);
				break;
			case 2:
				scanf("%d %d",&start,&end);
				printf("0\n");
				break;
			default:
				printf("wrong Input\n");
		}
	}
}