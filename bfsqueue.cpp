#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    vector<int> numList;
    numList.push_back(1);
    numList.push_back(2);
    numList.push_back(3);
    numList.push_back(4);
    numList.push_back(5);
    numList.push_back(6);
    numList.push_back(7);
    numList.push_back(8);
    numList.push_back(9);
    numList.push_back(10);
    numList.push_back(11);
    numList.push_back(12);
    numList.push_back(13);
    numList.push_back(14);
    queue<int> bfsqueue;
    bfsqueue.push(0);
    while(!bfsqueue.empty()){
        
        cout << bfsqueue.size()<< " " << bfsqueue.front() <<" " << bfsqueue.back() << endl;
        
        int currentIndex = bfsqueue.front();
        if((currentIndex+1)*2 + 1 <= numList.size()){
            bfsqueue.push((currentIndex+1)* 2 - 1);
            bfsqueue.push((currentIndex+1)* 2);
        }
        else if ((currentIndex + 1) * 2 == numList.size()){
            bfsqueue.push((currentIndex+ 1)* 2 - 1);
        }
        bfsqueue.pop();
    }
}