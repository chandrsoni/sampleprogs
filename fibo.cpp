map<int, unsigned long long> fibo;

unsigned long long fib(int n){
    if(n == 0){
        return 0;   
    }
    if(n == 1){
        return 1;
    }
    
    if(fibo.find(n) != fibo.end()){
        return fibo[n];
    }
    
    int result = fib(n-1) + fib(n-2);
    fibo[n] = result;
    return result;
}

int main() {
    cout << fib(2) << endl;
    cout << fib(3) << endl;
    cout << fib(4) << endl;
    cout << fib(5) << endl;
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(9) << endl;
    cout << fib(10) << endl;
    cout << fib(12) << endl;
    cout << fib(13) << endl;
    cout << fib(20) << endl;
    cout << fib(30) << endl;
    cout << fib(40) << endl;
    cout << fib(50) << endl;
    cout << fib(100) << endl;
    std::cout << "Hello World!\n";
}