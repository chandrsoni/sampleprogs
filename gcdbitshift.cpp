int gcd(int a, int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int main() {
    std::cout << "Hello World!\n";
    int x = 29;
    cout << (x & (1<<4)) <<endl;
    cout << (x & (1<<3)) <<endl;
    cout << (x & (1<<2)) <<endl;
    cout << (x & (1<<1)) <<endl;
    cout << (x & 1) <<endl;
    cout << 0b10011 << endl;
    
    cout << gcd(84, 48) << endl;
}