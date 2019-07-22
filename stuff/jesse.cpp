#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long

class profit_desc{
public:
	int value;
	int diff;
	int start_index;
	int end_index;
	profit_desc(){
		value = -1;
		start_index = -1;
		end_index = -1;
		diff = 1000000;
	}
};

int main(){
	int n;
	int d;

	scanf("%d %d",&n,&d);
	int cost[n];

	int profit_input;

	profit_desc profit[10];
	// take input
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&cost[i]);
	}

	for (int i = 0; i < d; ++i)
	{
		scanf("%d",&profit[i].value);
	}

	for (int i = 0; i < n; ++i)
	{
		for(int j=i+1;j<n;j++){
			profit_input = cost[j]-cost[i];
			if(profit_input >0){
				for(int k=0;k<d;k++){
					if(profit_input == profit[k].value){
						if(j-i < profit[k].diff){
							profit[k].start_index=i;
							profit[k].end_index = j;
							profit[k].diff = j-i;
						}
					}
				}
			}
		}
	}

	for(int i=0;i<d;i++){
		if(profit[i].start_index != -1){
			printf("%d %d\n",profit[i].start_index+1,profit[i].end_index+1 );
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}