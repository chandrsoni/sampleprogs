#include<iostream>

using namespace std;

int main() {
    list<int> intlist;
    intlist.push_front(10);
    intlist.push_back(5);
    intlist.push_front(1);
    for(list<int>::iterator it = intlist.begin(); it != intlist.end(); it++){
        cout << *it << endl;
    }
}