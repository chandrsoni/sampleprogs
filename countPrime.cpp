int countPrimes(int n) {
    if(n < 2){return 0;}
    if(n == 2){ return 1;}
    vector<int> primes;
    primes.push(2);
    for(int i = 3; i < n; i++){
        bool foundfactor = false;
        for(int j = 0; j < primes.size(); primes++){
            if(i % primes[j] == 0){
                foundfactor = true;
                break;
            }
        }
        if(!foundfactor){primes.push(i);}
    }
    return primes.size();
}

int main() {
    std::cout << "Hello World!\n";
    
    cout << countPrimes(10) << endl;
}