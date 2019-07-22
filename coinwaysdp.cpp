#include <iostream>
using namespace std;

class DpKey {
    public:
    int n;
    int denomCount;
    DpKey(int num, int denom){
        n = num;
        denomCount = denom;
    }
    bool operator== (const DpKey& compKey) const {
        return n == compKey.n && denomCount == compKey.denomCount;
    }
    bool operator< (const DpKey& compKey) const {
        return n < compKey.n || (n == compKey.n && denomCount < compKey.denomCount);
    }
};

map<DpKey, int> splitNum;

int split(int n, int denomCount){
    DpKey key(n, denomCount);
    if(splitNum.find(key) != splitNum.end()){
        cout << "found " << n << ", "<< denomCount << ", "<< splitNum[key] << endl;
        return splitNum[key];
    }
    if(denomCount == 1){
        return 1;
    }
    int denom = 1;
    switch(denomCount){
        case 4:
            denom = 25;
            break;
        case 3:
            denom = 10;
            break;
        case 2:
            denom = 5;
            break;
        default:
            denom = 1;
            break;
    }
    int result = 0;
    for(int i = 0;i <= n/denom; i ++){
        result += split(n-i*denom, denomCount-1);
    }
    splitNum[key] = result;
    return result;
}


int main() {
    std::cout << "Hello World!\n";
    int n = 77;
    int z = split(n,4);
    cout << split(7,4) <<endl;
    cout << split(11,4) <<endl;
    cout << split(26,4) << endl;
    cout << z << endl;
    
    for(map<DpKey, int> :: iterator it = splitNum.begin(); it != splitNum.end(); it++){
        cout << it-> first.n << ", "<< it-> first.denomCount<< ", "<< it-> second << endl;
    }
    
}