int add(int a, int b, int carry){
    if(a == 0 && carry != 0) return add(b,carry,0);
    else if(b == 0 && carry != 0) return add(a,carry,0);
    else if(b == 0 ) return a;
    else if(a == 0) return b;
    
    int abit = a & 1;
    int bbit = b&1;
    
    int carryNew, lowbit;
    int countOne = 0;
    if(abit == 1)countOne++;
    if(bbit == 1)countOne++;
    if(carry == 1)countOne++;
    lowbit = countOne & 1;
    carryNew = (countOne & 2) >> 1;
    
    return (add(a >>1, b >> 1, carryNew) << 1) + lowbit;
    
}

int main() {
    cout<< "1, 0, "<< add(1,0,0) << endl;
    cout<< "1, 1, "<< add(1,1,0) << endl;
    cout<< "2, 0, "<< add(2,0,0) << endl;
    cout<< "2, 1, "<< add(2,1,0) << endl;
    cout<< "2, 2, "<< add(2,2,0) << endl;
    cout<< "3, 1, "<< add(3,1,0) << endl;
    cout<< "3, 2, "<< add(3,2,0) << endl;
    cout<< "1, 4, "<< add(1,4,0) << endl;
    cout<< "1, 3, "<< add(1,3,0) << endl;
    cout<< "2, 5, "<< add(2,5,0) << endl;
    cout<< "7, 9, "<< add(7,9,0) << endl;
    cout<< "4, 5, "<< add(4,5,0) << endl;

    std::cout << "Hello World!\n";
}