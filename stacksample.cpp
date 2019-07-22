#include <iostream>
using namespace std;

int main(){
    stack<int> intstack;
    intstack.push(1);
    intstack.push(2);
    intstack.push(3);
    intstack.push(4);
    while(!intstack.empty()){
        cout<< intstack.front() << endl;
        intstack.pop();
    }
}