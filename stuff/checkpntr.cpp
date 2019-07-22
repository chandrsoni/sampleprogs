#include <iostream>
using namespace std;
class tuple{
	public:
	int val1,val2,val3,val4,val5,val6,val7,val8;
};
int main(){
	tuple A[50];
	A[0].val1=1;
	A[0].val2=1;
	A[0].val3=1;
	A[0].val4=1;
	A[0].val5=1;
	A[0].val6=1;
	A[0].val7=1;
	A[0].val8=1;
	A[1].val1=12;
	A[1].val2=12;
	A[1].val3=12;
	A[1].val4=12;
	A[1].val5=12;
	A[1].val6=12;
	A[1].val7=12;
	A[1].val8=12;
	A[2].val1=13;
	A[2].val2=13;
	A[2].val3=13;
	A[2].val4=13;
	A[2].val5=13;
	A[2].val6=13;
	A[2].val7=13;
	A[2].val8=13;
	tuple* ptr=&A[0];
	ptr+=1;
	cout<<ptr->val1<<endl;
}
